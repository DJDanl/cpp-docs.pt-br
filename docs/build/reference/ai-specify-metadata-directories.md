---
title: /AI (especificar diretórios de metadados)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.AdditionalUsingDirectories
- VC.Project.VCNMakeTool.AssemblySearchPath
- /AI
- VC.Project.VCCLWCECompilerTool.AdditionalUsingDirectories
helpviewer_keywords:
- /AI compiler option [C++]
- AI compiler option [C++]
- -AI compiler option [C++]
ms.assetid: fb9c1846-504c-4a3b-bb39-c8696de32f6f
ms.openlocfilehash: 3633cfe34a4f9c627f84cf401cb559f02f8c8229
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57810205"
---
# <a name="ai-specify-metadata-directories"></a>/AI (especificar diretórios de metadados)

Especifica um diretório em que o compilador pesquisará para resolver referências de arquivo passadas para diretiva `#using`.

## <a name="syntax"></a>Sintaxe

> **/AI**_directory_

## <a name="arguments"></a>Arguments

*directory*<br/>
O diretório ou o caminho para o compilador pesquisar.

## <a name="remarks"></a>Comentários

Apenas um diretório pode ser passado para um **/AI** invocação. Especifique um **/AI** opção para cada caminho que você deseja que o compilador pesquise. Por exemplo, para adicionar C:\Project\Meta e C:\Common\Meta ao caminho de pesquisa do compilador para `#using` diretivas, adicione `/AI"C:\Project\Meta" /AI"C:\Common\Meta"` à linha de comando do compilador ou adicione cada diretório para o **adicionais #using diretórios** propriedade no Visual Studio.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **geral** página de propriedades.

1. Modificar a **adicionais #using diretórios** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalUsingDirectories%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Diretiva #using](../../preprocessor/hash-using-directive-cpp.md)
