---
title: /doc (Processar comentários de documentação) (C/C++)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.GenerateXMLDocumentationFiles
- /doc
- VC.Project.VCCLCompilerTool.XMLDocumentationFileName
helpviewer_keywords:
- /doc compiler option [C++]
- comments, C++ code
- XML documentation, comments in source files
- -doc compiler option [C++]
ms.assetid: b54f7e2c-f28f-4f46-9ed6-0db09be2cc63
ms.openlocfilehash: 39b614b1ab21a654a35e30b0d3acffa15d244fb0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50530033"
---
# <a name="doc-process-documentation-comments-cc"></a>/doc (Processar comentários de documentação) (C/C++)

Faz com que o compilador processar comentários de documentação em arquivos de código-fonte e criar um arquivo. XDC para cada arquivo de código de origem que tenha comentários de documentação.

## <a name="syntax"></a>Sintaxe

> **/doc**[*nome*]

## <a name="arguments"></a>Arguments

*name*<br/>
O nome do arquivo. XDC que o compilador criará. Válido somente quando um arquivo. cpp é passado na compilação.

## <a name="remarks"></a>Comentários

Os arquivos. XDC são processados em um arquivo. XML com xdcmake.exe. Para obter mais informações, consulte [referência XDCMake](../../ide/xdcmake-reference.md).

Você pode adicionar comentários de documentação para seus arquivos de código-fonte. Para obter mais informações, consulte [marcas recomendadas para comentários da documentação](../../ide/recommended-tags-for-documentation-comments-visual-cpp.md).

Para usar o arquivo. XML gerado com o IntelliSense, verifique o nome do arquivo do arquivo. XML, o mesmo que o assembly que você deseja dar suporte e colocar o arquivo. XML está no mesmo diretório que o assembly. Quando o assembly for referenciado no projeto do Visual Studio, também é encontrar o arquivo. XML. Para obter mais informações, consulte [usando o IntelliSense](/visualstudio/ide/using-intellisense) e [fornecendo comentários de código XML](/visualstudio/ide/supplying-xml-code-comments).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **arquivos de saída** página de propriedades.

1. Modificar a **gerar arquivos de documentação XML** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.GenerateXMLDocumentationFiles%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)