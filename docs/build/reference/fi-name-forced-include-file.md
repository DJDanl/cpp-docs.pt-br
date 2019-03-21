---
title: /FI (Arquivo de inclusão forçado do nome)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCNMakeTool.ForcedIncludes
- VC.Project.VCCLCompilerTool.ForcedIncludeFiles
- VC.Project.VCCLWCECompilerTool.ForcedIncludeFiles
- /fi
helpviewer_keywords:
- FI compiler option [C++]
- -FI compiler option [C++]
- /FI compiler option [C++]
- preprocess header file compiler option [C++]
ms.assetid: 07e79577-8152-4df9-a64c-aae08c603397
ms.openlocfilehash: e047ecc5266a898f2c6dc24be3c204f8ddf94386
ms.sourcegitcommit: 90817d9d78fbaed8ffacde63f3add334842e596f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/20/2019
ms.locfileid: "58278362"
---
# <a name="fi-name-forced-include-file"></a>/FI (Arquivo de inclusão forçado do nome)

Faz com que o pré-processador processar o arquivo de cabeçalho especificado.

## <a name="syntax"></a>Sintaxe

```
/FI[ ]pathname
```

## <a name="remarks"></a>Comentários

Essa opção tem o mesmo efeito que especificar o arquivo com aspas duplas em um `#include` diretiva na primeira linha de cada arquivo de origem especificado na linha de comando, na variável de ambiente CL, ou em um arquivo de comando. Se você usar várias **/FI** opções, os arquivos são incluídas na ordem em que eles são processados pelo CL.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **avançado** página de propriedades.

1. Modificar a **arquivo de Include forçado** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ForcedIncludeFiles%2A>.

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Especificando o nome de caminho](specifying-the-pathname.md)
