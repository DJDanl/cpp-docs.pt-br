---
title: /Yc (criar arquivo de cabeçalho pré-compilado)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.UsePrecompiledHeader
- /yc
- VC.Project.VCCLWCECompilerTool.PrecompiledHeaderThrough
- VC.Project.VCCLWCECompilerTool.UsePrecompiledHeader
- VC.Project.VCCLCompilerTool.PrecompiledHeaderThrough
helpviewer_keywords:
- precompiled header files, creating
- PCH files, creating
- .pch files, creating
- -Yc compiler option [C++]
- /Yc compiler option [C++]
- Yc compiler option [C++]
ms.assetid: 47c2e555-b4f5-46e6-906e-ab5cf21f0678
ms.openlocfilehash: 71a05df3adc74edfd814bb6dc15121e4a343dc4d
ms.sourcegitcommit: 6b749db14b4cf3a2b8d581fda6fdd8cb98bc3207
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/05/2020
ms.locfileid: "82825750"
---
# <a name="yc-create-precompiled-header-file"></a>/Yc (criar arquivo de cabeçalho pré-compilado)

Instrui o compilador a criar um arquivo de cabeçalho pré-compilado (. pch) que representa o estado de compilação em um determinado ponto.

## <a name="syntax"></a>Sintaxe

> __/Yc__\
> __/Yc__*Nome de arquivo* /YC

## <a name="arguments"></a>Argumentos

*nome do arquivo*<br/>
Especifica um arquivo de cabeçalho (. h). Quando esse argumento é usado, o compilador compila todo o código até e incluindo o arquivo. h.

## <a name="remarks"></a>Comentários

Quando **/YC** é especificado sem um argumento, o compilador compila todo o código até o final do arquivo de origem base ou até o ponto no arquivo base em que ocorre uma diretiva [hdrstop](../../preprocessor/hdrstop.md) . O arquivo. pch resultante tem o mesmo nome base do arquivo de origem base, a menos que você especifique um nome de arquivo diferente usando o pragma **hdrstop** ou a opção **/FP** .

O código pré-compilado é salvo em um arquivo com um nome criado a partir do nome base do arquivo especificado com a opção **/YC** e uma extensão. pch. Você também pode usar o [/FP (Name. Arquivo PCH)](fp-name-dot-pch-file.md) para especificar um nome para o arquivo de cabeçalho pré-compilado.

Se você usar o*nome de arquivo* __/YC__, o compilador compilará todo o código até e incluindo o arquivo especificado para uso posterior com a opção [/Yu (usar arquivo de cabeçalho pré-compilado)](yu-use-precompiled-header-file.md) .

Se as opções __/YC__*filename* e __/Yu__*filename* ocorrerem na mesma linha de comando e na referência, ou sugerem, o mesmo nome de arquivo, __/YC__*filename* terá precedência. Esse recurso simplifica a gravação de makefiles.

Para obter mais informações sobre cabeçalhos pré-compilados, consulte:

- [/Y (cabeçalhos pré-compilados)](y-precompiled-headers.md)

- [Arquivos de cabeçalho pré-compilados](../creating-precompiled-header-files.md)

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Selecione um arquivo. cpp. O arquivo. cpp deve #include arquivo. h que contém informações de cabeçalho pré-compilado. A configuração **/YC** do projeto pode ser substituída no nível do arquivo.

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Abra a página de **Propriedades configuração**, **C/C++**, **cabeçalhos pré-compilados** .

1. Modifique a propriedade de **cabeçalho pré-compilado** .

1. Para definir o nome de arquivo, modifique a propriedade de **arquivo de cabeçalho pré-compilado** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Veja <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.PrecompiledHeaderThrough%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UsePrecompiledHeader%2A>.

## <a name="example"></a>Exemplo

Considere o código a seguir:

```cpp
// prog.cpp
// compile with: cl /c /Ycmyapp.h prog.cpp
#include <afxwin.h>   // Include header for class library
#include "resource.h" // Include resource definitions
#include "myapp.h"    // Include information specific to this app
// ...
```

Quando esse código é compilado com o comando `CL /YcMYAPP.H PROG.CPP`, o compilador salva todo o pré-processamento de Afxwin. h, Resource. h e MyApp. h em um arquivo de cabeçalho pré-compilado chamado MyApp. pch.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Arquivos de cabeçalho pré-compilados](../creating-precompiled-header-files.md)
