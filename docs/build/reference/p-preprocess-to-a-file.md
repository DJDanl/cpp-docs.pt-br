---
title: -P (pré-processar em um arquivo) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.GeneratePreprocessedFile
- /p
- VC.Project.VCCLWCECompilerTool.GeneratePreprocessedFile
dev_langs:
- C++
helpviewer_keywords:
- /P compiler option [C++]
- -P compiler option [C++]
- P compiler option [C++]
- output files, preprocessor
- preprocessing output files
ms.assetid: 123ee54f-8219-4a6f-9876-4227023d83fc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4cbec53526fe90d1b4644b5b9fdd667d0fffcbe8
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45714500"
---
# <a name="p-preprocess-to-a-file"></a>/P (pré-processar em um arquivo)

Pré-processa arquivos de código-fonte C e C++ e grava a saída pré-processada em um arquivo.

## <a name="syntax"></a>Sintaxe

```
/P
```

## <a name="remarks"></a>Comentários

O arquivo tem o mesmo nome base que o arquivo de origem e uma extensão. i. No processo, todas as diretivas de pré-processamento são executadas, expansões de macro são executadas e comentários são removidos. Para preservar os comentários na saída pré-processada, use o [/C (preservar comentários durante o pré-processamento)](../../build/reference/c-preserve-comments-during-preprocessing.md) junto com a opção **p**.

**/P** adiciona `#line` diretivas para a saída, no início e no final de cada arquivo incluído e em torno de linhas removidas por diretivas de pré-processador para compilação condicional. Essas diretivas renumerar as linhas do arquivo pré-processado. Como resultado, os erros gerados durante os estágios posteriores do processamento de consultem os números de linha do arquivo de origem original em vez de linhas no arquivo pré-processado. Para suprimir a geração de `#line` diretivas, use [/EP (pré-processar para stdout sem diretivas de #line)](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) , bem como **p**.

O **/p** opção inibe compilação. Ele não produzir um arquivo. obj, mesmo se você usar [/Fo (nome de arquivo de objeto)](../../build/reference/fo-object-file-name.md). Você deve reenviar o arquivo pré-processado para compilação. **/P** também suprime os arquivos de saída do **/FA**, **/Fa**, e **/Fm** opções. Para obter mais informações, consulte [/FA, /Fa (listando arquivo)](../../build/reference/fa-fa-listing-file.md) e [/Fm (Mapfile de nome)](../../build/reference/fm-name-mapfile.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **pré-processador** página de propriedades.

1. Modificar a **gerar o arquivo pré-processado** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.GeneratePreprocessedFile%2A>.

## <a name="example"></a>Exemplo

A seguinte linha de comando pré-processa `ADD.C`, preservará comentários, adiciona `#line` diretivas e grava o resultado em um arquivo, `ADD.I`:

```
CL /P /C ADD.C
```

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[/Fi (pré-processar nome do arquivo de saída)](../../build/reference/fi-preprocess-output-file-name.md)