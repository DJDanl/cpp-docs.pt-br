---
title: 'Como: Inserir um manifesto em um aplicativo C/C++'
ms.date: 11/04/2016
helpviewer_keywords:
- manifests [C++]
- embedding manifests
- makefiles, updating to embed manifest
ms.assetid: ec0bac69-2fdc-466c-ab0d-710a22974e5d
ms.openlocfilehash: b1bff23c91b465d697cc52a2b893ece5be3764b1
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57412894"
---
# <a name="how-to-embed-a-manifest-inside-a-cc-application"></a>Como: Inserir um manifesto em um aplicativo C/C++

É recomendável que um aplicativo C/C++ (ou biblioteca) tem seu manifesto inserido no final binário, porque isso garante que o comportamento de tempo de execução correto na maioria dos cenários. Por padrão, o Visual Studio tenta inserir o manifesto quando ele cria um projeto de arquivos de origem; ver [geração de manifesto no Visual Studio](../build/manifest-generation-in-visual-studio.md) para obter mais informações. No entanto se um aplicativo é criado, usando nmake, algumas alterações para o makefile existente são necessárias. Esta seção demonstra como alterar makefiles existentes para inserir automaticamente o manifesto em final binário.

## <a name="two-approaches"></a>Duas abordagens

Há duas maneiras de inserir o manifesto dentro de um aplicativo ou uma biblioteca.

- Se você não estiver fazendo uma compilação incremental, você pode inserir diretamente o manifesto usando uma linha de comando semelhante ao seguinte como uma etapa de pós-compilação:

   **mt.exe -manifest MyApp.exe.manifest -outputresource:MyApp.exe;1**

   ou

   **mt.exe -manifest MyLibrary.dll.manifest -outputresource:MyLibrary.dll;2**

   (1 para que um EXE, 2 para uma DLL).

- Se você estiver fazendo uma compilação incremental, editando diretamente o recurso, como mostrado aqui será desabilitar a compilação incremental e causar uma recompilação completa; cuidado, portanto, uma abordagem diferente:

   - Vincule o binário para gerar o arquivo MyApp.exe.manifest.

   - Converta o manifesto em um arquivo de recurso.

   - Vincule novamente (de maneira incremental) para incorporar o recurso de manifesto em binário.

Os exemplos a seguir mostram como alterar makefiles para incorporar as duas técnicas.

## <a name="makefiles-before"></a>Makefiles (antes)

Considere o script de nmake para MyApp.exe, um aplicativo simples criado a partir de um arquivo:

```
# build MyApp.exe
!if "$(DEBUG)" == "1"
CPPFLAGS=$(CPPFLAGS) /MDd
LFLAGS=$(LFLAGS) /INCREMENTAL
!else
CPPFLAGS=$(CPPFLAGS) /MD
!endif

MyApp.exe : MyApp.obj
    link $** /out:$@ $(LFLAGS)

MyApp.obj : MyApp.cpp

clean :
    del MyApp.obj MyApp.exe
```

Se esse script é executado inalterado com o Visual C++, ele cria MyApp.exe com êxito. Ele também cria o arquivo de manifesto externo MyApp.exe.manifest, para uso pelo sistema operacional para carregar assemblies de dependentes em tempo de execução.

O script de nmake MyLibrary parece muito semelhante:

```
# build MyLibrary.dll
!if "$(DEBUG)" == "1"
CPPFLAGS=$(CPPFLAGS) /MDd
LFLAGS=$(LFLAGS) /DLL /INCREMENTAL

!else
CPPFLAGS=$(CPPFLAGS) /MD
LFLAGS=$(LFLAGS) /DLL

!endif

MyLibrary.dll : MyLibrary.obj
    link $** /out:$@ $(LFLAGS)

MyLibrary.obj : MyLibrary.cpp

clean :
    del MyLibrary.obj MyLibrary.dll
```

## <a name="makefiles-after"></a>Makefiles (depois)

Para compilar com o embedded manifestos, que é preciso fazer quatro pequenas alterações em makefiles originais. Para o makefile MyApp.exe:

```
# build MyApp.exe
!include makefile.inc
#^^^^^^^^^^^^^^^^^^^^ Change #1. (Add full path if necessary.)

!if "$(DEBUG)" == "1"
CPPFLAGS=$(CPPFLAGS) /MDd
LFLAGS=$(LFLAGS) /INCREMENTAL
!else
CPPFLAGS=$(CPPFLAGS) /MD
!endif

MyApp.exe : MyApp.obj
    link $** /out:$@ $(LFLAGS)
    $(_VC_MANIFEST_EMBED_EXE)
#^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Change #2

MyApp.obj : MyApp.cpp

clean :
    del MyApp.obj MyApp.exe
    $(_VC_MANIFEST_CLEAN)
#^^^^^^^^^^^^^^^^^^^^^^^^ Change #3

!include makefile.targ.inc
#^^^^^^^^^^^^^^^^^^^^^^^^^ Change #4. (Add full path if necessary.)
```

Para o makefile MyLibrary:

```
# build MyLibrary.dll
!include makefile.inc
#^^^^^^^^^^^^^^^^^^^^ Change #1. (Add full path if necessary.)

!if "$(DEBUG)" == "1"
CPPFLAGS=$(CPPFLAGS) /MDd
LFLAGS=$(LFLAGS) /DLL /INCREMENTAL

!else
CPPFLAGS=$(CPPFLAGS) /MD
LFLAGS=$(LFLAGS) /DLL

!endif

MyLibrary.dll : MyLibrary.obj
    link $** /out:$@ $(LFLAGS)
    $(_VC_MANIFEST_EMBED_DLL)
#^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Change #2.

MyLibrary.obj : MyLibrary.cpp

clean :
    del MyLibrary.obj MyLibrary.dll
    $(_VC_MANIFEST_CLEAN)
#^^^^^^^^^^^^^^^^^^^^^^^^ Change #3.

!include makefile.targ.inc
#^^^^^^^^^^^^^^^^^^^^^^^^^ Change #4. (Add full path if necessary.)
```

Os makefiles agora incluem dois arquivos que fazem o trabalho real, makefile.inc e makefile.targ.inc.

Criar makefile.inc e copie o seguinte para ele:

```
# makefile.inc -- Include this file into existing makefile at the very top.

# _VC_MANIFEST_INC specifies whether build is incremental (1 - incremental).
# _VC_MANIFEST_BASENAME specifies name of a temporary resource file.

!if "$(DEBUG)" == "1"
CPPFLAGS=$(CPPFLAGS) /MDd
LFLAGS=$(LFLAGS) /INCREMENTAL
_VC_MANIFEST_INC=1
_VC_MANIFEST_BASENAME=__VC90.Debug

!else
CPPFLAGS=$(CPPFLAGS) /MD
_VC_MANIFEST_INC=0
_VC_MANIFEST_BASENAME=__VC90

!endif

####################################################
# Specifying name of temporary resource file used only in incremental builds:

!if "$(_VC_MANIFEST_INC)" == "1"
_VC_MANIFEST_AUTO_RES=$(_VC_MANIFEST_BASENAME).auto.res
!else
_VC_MANIFEST_AUTO_RES=
!endif

####################################################
# _VC_MANIFEST_EMBED_EXE - command to embed manifest in EXE:

!if "$(_VC_MANIFEST_INC)" == "1"

#MT_SPECIAL_RETURN=1090650113
#MT_SPECIAL_SWITCH=-notify_resource_update
MT_SPECIAL_RETURN=0
MT_SPECIAL_SWITCH=
_VC_MANIFEST_EMBED_EXE= \
if exist $@.manifest mt.exe -manifest $@.manifest -out:$(_VC_MANIFEST_BASENAME).auto.manifest $(MT_SPECIAL_SWITCH) & \
if "%ERRORLEVEL%" == "$(MT_SPECIAL_RETURN)" \
rc /r $(_VC_MANIFEST_BASENAME).auto.rc & \
link $** /out:$@ $(LFLAGS)

!else

_VC_MANIFEST_EMBED_EXE= \
if exist $@.manifest mt.exe -manifest $@.manifest -outputresource:$@;1

!endif

####################################################
# _VC_MANIFEST_CLEAN - command to clean resources files generated temporarily:

!if "$(_VC_MANIFEST_INC)" == "1"

_VC_MANIFEST_CLEAN=-del $(_VC_MANIFEST_BASENAME).auto.res \
    $(_VC_MANIFEST_BASENAME).auto.rc \
    $(_VC_MANIFEST_BASENAME).auto.manifest

!else

_VC_MANIFEST_CLEAN=

!endif

# End of makefile.inc
####################################################
```

Agora crie makefile.targ.inc e copie o seguinte para ele:

```
# makefile.targ.inc - include this at the very bottom of the existing makefile

####################################################
# Commands to generate initial empty manifest file and the RC file
# that references it, and for generating the .res file:

$(_VC_MANIFEST_BASENAME).auto.res : $(_VC_MANIFEST_BASENAME).auto.rc

$(_VC_MANIFEST_BASENAME).auto.rc : $(_VC_MANIFEST_BASENAME).auto.manifest
    type <<$@
#include <winuser.h>
1RT_MANIFEST"$(_VC_MANIFEST_BASENAME).auto.manifest"
<< KEEP

$(_VC_MANIFEST_BASENAME).auto.manifest :
    type <<$@
<?xml version='1.0' encoding='UTF-8' standalone='yes'?>
<assembly xmlns='urn:schemas-microsoft-com:asm.v1' manifestVersion='1.0'>
</assembly>
<< KEEP

# end of makefile.targ.inc
```

## <a name="see-also"></a>Consulte também

[Noções básicas sobre o Manifest Generation para programas do C/C++](../build/understanding-manifest-generation-for-c-cpp-programs.md)
