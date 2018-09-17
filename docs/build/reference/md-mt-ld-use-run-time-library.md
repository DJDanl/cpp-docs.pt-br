---
title: -MD, -MT, -LD (usar biblioteca de tempo de execução) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /ld
- /mt
- VC.Project.VCCLWCECompilerTool.RuntimeLibrary
- VC.Project.VCCLCompilerTool.RuntimeLibrary
- /md
- /ml
dev_langs:
- C++
helpviewer_keywords:
- /MT compiler option [C++]
- -MD compiler option [C++]
- threading [C++], multithread compiler option
- MSVCRTD.lib
- MSVCRT.lib
- LIBCMT.lib
- MD compiler option [C++]
- /MD compiler option [C++]
- MT compiler option [C++]
- LD compiler option [C++]
- MDd compiler option [C++]
- -MDd compiler option [C++]
- LIBCD.lib
- -MTd compiler option [C++]
- MTd compiler option [C++]
- /MTd compiler option [C++]
- -LD compiler option [C++]
- /MDd compiler option [C++]
- multithread compiler option
- _STATIC_CPPLIB symbol
- LIBC.lib
- /LD compiler option [C++]
- DLLs [C++], compiler options
- LIBCMTD.lib
- -MT compiler option [C++]
ms.assetid: cf7ed652-dc3a-49b3-aab9-ad60e5395579
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ee8e59fbc88e63343d4da75a4cbf95d4f83bf815
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45701357"
---
# <a name="md-mt-ld-use-run-time-library"></a>/MD, /MT, /LD (Usar biblioteca de tempo de execução)

Indica se um módulo com multithread é uma DLL e especifica versões comerciais ou de depuração da biblioteca em tempo de execução.

## <a name="syntax"></a>Sintaxe

```
/MD[d]
/MT[d]
/LD[d]
```

## <a name="remarks"></a>Comentários

|Opção|Descrição|
|------------|-----------------|
|**/MD**|Faz com que o aplicativo use a versão específica de multithread e a versão específica de DLL da biblioteca em tempo de execução. Define `_MT` e `_DLL` e faz com que o compilador coloque o nome da biblioteca MSVCRT.lib no arquivo .obj.<br /><br /> Os aplicativos criados com esta opção são vinculados a MSVCRT.lib estaticamente. Essa biblioteca fornece uma camada de código que permite que o vinculador resolva referências externas. O código de trabalho real está contido em MSVCR*versionnumber*. DLL, que deve estar disponível em tempo de execução para aplicativos vinculados a Msvcrt. lib.|
|**/MDd**|Define `_DEBUG`, `_MT` e `_DLL`, e faz com que o aplicativo use a versão específica de multithread de depuração e a versão específica de DLL da biblioteca em tempo de execução. Também faz com que o compilador coloque o nome da biblioteca MSVCRTD.lib no arquivo .obj.|
|**/MT**|Faz com que o aplicativo use a versão estática de multithread da biblioteca em tempo de execução. Define `_MT` e faz com que o compilador coloque o nome da biblioteca LIBCMT.lib no arquivo .obj para que o vinculador use LIBCMT.lib para resolver símbolos externos.|
|**/MTd**|Define `_DEBUG` e `_MT`. Essa opção também faz com que o compilador coloque o nome da biblioteca LIBCMTD.lib no arquivo .obj para que o vinculador use LIBCMTD.lib para resolver símbolos externos.|
|**/LD**|Cria uma DLL.<br /><br /> Passa o **/DLL** opção de vinculador. O vinculador procura, mas não requer, uma função `DllMain`. Se você não grava uma função `DllMain`, o vinculador insere uma função `DllMain` que retorna TRUE.<br /><br /> Vincula o código de inicialização da DLL.<br /><br /> Cria uma biblioteca da importação (.lib), se um arquivo de exportação (.exp) não é especificado na linha de comando. Você vinculará a biblioteca de importação aos aplicativos que chamam a DLL.<br /><br /> Interpreta [/Fe (nomear o arquivo EXE)](../../build/reference/fe-name-exe-file.md) como uma DLL em vez de um arquivo de .exe de nomenclatura. Por padrão, o nome do programa se torna *basename*. dll em vez de *basename*.exe.<br /><br /> Implica **/MT** , a menos que você especifique explicitamente **/MD**.|
|**/LDd**|Cria uma DLL de depuração. Define `_MT` e `_DEBUG`.|

Para obter mais informações sobre bibliotecas de tempo de execução do C e quais bibliotecas são usadas quando você compila com [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md), consulte [recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

Todos os módulos passados para determinada invocação do vinculador devem ter sido compilados com a mesma opção de compilador da biblioteca de tempo de execução (**/MD**, **/MT**, **/LD**).

Para obter mais informações sobre como usar as versões de depuração das bibliotecas de tempo de execução, consulte [referência de biblioteca de tempo de execução C](../../c-runtime-library/c-run-time-library-reference.md).

O artigo Q140584 da Base de Dados de Conhecimento também discute como escolher a biblioteca CRT adequada.

Para obter mais informações sobre DLLs, consulte [DLLs no Visual C++](../../build/dlls-in-visual-cpp.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o **C/C++** pasta.

1. Selecione o **geração de código** página de propriedades.

1. Modificar a **biblioteca de tempo de execução** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.RuntimeLibrary%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)