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
ms.openlocfilehash: 35b8bfb30a49efa35a3af3d3b76e75f8dede9fd7
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57418965"
---
# <a name="yc-create-precompiled-header-file"></a>/Yc (criar arquivo de cabeçalho pré-compilado)

Instrui o compilador crie um arquivo de cabeçalho pré-compilado (. pch) que representa o estado da compilação em um determinado ponto.

## <a name="syntax"></a>Sintaxe

> __/Yc__<br/>
> __/Yc__*filename*

## <a name="arguments"></a>Arguments

*filename*<br/>
Especifica um arquivo de cabeçalho (. h). Quando esse argumento é usado, o compilador compila todo o código até e incluindo o arquivo. h.

## <a name="remarks"></a>Comentários

Quando **/Yc** for especificado sem um argumento, o compilador compila todo o código até o fim do arquivo de origem de base, ou para o ponto no arquivo de base onde uma [hdrstop](../../preprocessor/hdrstop.md) diretiva ocorre. O arquivo. pch resultante tem o mesmo nome base como seu arquivo de origem de base, a menos que você especifique um nome de arquivo diferente usando o **hdrstop** pragma ou o **/Fp** opção.

O código pré-compilado é salvo em um arquivo com um nome criado do nome de base do arquivo especificado com o **/Yc** opção e a extensão. pch. Você também pode usar o [/Fp (nome. Arquivo pch)](../../build/reference/fp-name-dot-pch-file.md) opção para especificar um nome para o arquivo de cabeçalho pré-compilado.

Se você usar __/Yc__*filename*, o compilador compila todo o código até e incluindo o arquivo especificado para uso subsequente com o [/Yu (usar a arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md) opção.

Se as opções __/Yc__*filename* e __/Yu__*filename* ocorrem na mesma linha de comando e ambos referenciar ou sugerem, o mesmo nome de arquivo, __/Yc__*filename* terá precedência. Esse recurso simplifica a gravação de makefiles.

Para obter mais informações sobre cabeçalhos pré-compilados, consulte:

- [/Y (cabeçalhos pré-compilados)](../../build/reference/y-precompiled-headers.md)

- [Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Selecione um arquivo. cpp. O arquivo. cpp deve #include do arquivo. h que contém informações de cabeçalho pré-compilado. O projeto **/Yc** configuração pode ser substituída no nível de arquivo.

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Abra o **propriedades de configuração**, **C/C++**, **cabeçalhos pré-compilados** página de propriedades.

1. Modificar a **cabeçalho pré-compilado** propriedade.

1. Para definir o nome do arquivo, modifique a **arquivo de cabeçalho pré-compilado** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.PrecompiledHeaderThrough%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UsePrecompiledHeader%2A>.

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

Quando esse código for compilado com o comando `CL /YcMYAPP.H PROG.CPP`, o compilador salva todo o pré-processamento para afxwin. h, Resource. h, e MYAPP.h em um arquivo de cabeçalho pré-compilado chamado MYAPP.pch.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)
