---
title: Descarregando de maneira explícita uma DLL carregada com atraso
ms.date: 11/04/2016
helpviewer_keywords:
- /DELAY:UNLOAD linker option
- DELAY:UNLOAD linker option
- __FUnloadDelayLoadedDLL2
- delayed loading of DLLs, unloading
ms.assetid: 1c4c5172-fd06-45d3-9e4f-f12343176b3c
ms.openlocfilehash: 9909a3e179aa6c0af3a622c7bf1b545326f90bbd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62293453"
---
# <a name="explicitly-unloading-a-delay-loaded-dll"></a>Descarregando de maneira explícita uma DLL carregada com atraso

O [/Delay](delay-delay-load-import-settings.md): opção de vinculador unload permite que você descarregar uma DLL que foi carregado de atraso. Por padrão, quando seu código descarrega a DLL (usando /Delay: Unload e **__FUnloadDelayLoadedDLL2**), as importações carregadas com atraso permanecerão na tabela de endereços de importação (IAT). No entanto, se você usar /Delay: Unload na linha de comando do vinculador, a função auxiliar dará suporte a descarregamento explícito da DLL, redefinindo o IAT para sua forma original; os ponteiros inválido agora serão substituídos. O IAT é um campo de [ImgDelayDescr](calling-conventions-parameters-and-return-type.md) que contém o endereço de uma cópia da IAT original (se houver).

## <a name="example"></a>Exemplo

### <a name="code"></a>Código

```
// link with /link /DELAYLOAD:MyDLL.dll /DELAY:UNLOAD
#include <windows.h>
#include <delayimp.h>
#include "MyDll.h"
#include <stdio.h>

#pragma comment(lib, "delayimp")
#pragma comment(lib, "MyDll")
int main()
{
    BOOL TestReturn;
    // MyDLL.DLL will load at this point
    fnMyDll();

    //MyDLL.dll will unload at this point
    TestReturn = __FUnloadDelayLoadedDLL2("MyDll.dll");

    if (TestReturn)
        printf_s("\nDLL was unloaded");
    else
        printf_s("\nDLL was not unloaded");
}
```

### <a name="comments"></a>Comentários

Observações importantes sobre descarregar a DLL carregadas com atraso:

- Você pode encontrar a implementação de **__FUnloadDelayLoadedDLL2** função no arquivo \VC7\INCLUDE\DELAYHLP. CPP.

- O parâmetro name do **__FUnloadDelayLoadedDLL2** função deve corresponder exatamente (incluindo caso) o que a biblioteca de importação contém (ou seja, cadeia de caracteres também na tabela de importação na imagem). Você pode exibir o conteúdo da biblioteca de importação com [DUMPBIN /Dependents](dependents.md). Se uma correspondência não diferencia maiusculas de cadeia de caracteres for desejada, você pode atualizar **__FUnloadDelayLoadedDLL2** usar uma das funções de cadeia de caracteres de CRT ou uma chamada à API do Windows.

Ver [descarregando uma DLL Delay-Loaded](unloading-a-delay-loaded-dll.md) para obter mais informações.

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](linker-support-for-delay-loaded-dlls.md)
