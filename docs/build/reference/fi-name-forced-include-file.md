---
title: /FI (Arquivo de inclusão forçado do nome)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCNMakeTool.ForcedIncludes
- VC.Project.VCCLCompilerTool.ForcedIncludeFiles
- VC.Project.VCCLWCECompilerTool.ForcedIncludeFiles
helpviewer_keywords:
- FI compiler option [C++]
- -FI compiler option [C++]
- /FI compiler option [C++]
- preprocess header file compiler option [C++]
ms.assetid: 07e79577-8152-4df9-a64c-aae08c603397
ms.openlocfilehash: 6460f75e2cad81bc1dcc540e3c687de5d0dc0d32
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439793"
---
# <a name="fi-name-forced-include-file"></a>/FI (Arquivo de inclusão forçado do nome)

Faz com que o pré-processador processe o arquivo de cabeçalho especificado.

## <a name="syntax"></a>Sintaxe

```
/FI[ ]pathname
```

## <a name="remarks"></a>Comentários

Essa opção tem o mesmo efeito que especificar o arquivo com aspas duplas em uma diretiva `#include` na primeira linha de cada arquivo de origem especificado na linha de comando, na variável de ambiente CL ou em um arquivo de comando. Se você usar várias opções **/Fi** , os arquivos serão incluídos na ordem em que são processados pelo CL.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **CC++ /** .

1. Clique na página de propriedades **avançado** .

1. Modifique a propriedade de **inclusão forçada de arquivo** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ForcedIncludeFiles%2A>.

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Especificando o nome de caminho](specifying-the-pathname.md)
