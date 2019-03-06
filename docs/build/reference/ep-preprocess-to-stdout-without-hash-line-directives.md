---
title: '/EP (pré-processar para stdout sem diretivas #line)'
ms.date: 11/04/2016
f1_keywords:
- /ep
- VC.Project.VCCLCompilerTool.GeneratePreprocessedFileNoLines
helpviewer_keywords:
- copy preprocessor output to stdout
- preprocessor output, copy to stdout
- -EP compiler option [C++]
- EP compiler option [C++]
- /EP compiler option [C++]
ms.assetid: 6ec411ae-e33d-4ef5-956e-0054635eabea
ms.openlocfilehash: ad64d39ee6e617556b9210086139c75a246cb63f
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57422735"
---
# <a name="ep-preprocess-to-stdout-without-line-directives"></a>/EP (pré-processar para stdout sem diretivas #line)

Pré-processa arquivos de código-fonte C e C++ e copiará os arquivos pré-processados para o dispositivo de saída padrão.

## <a name="syntax"></a>Sintaxe

```
/EP
```

## <a name="remarks"></a>Comentários

No processo, todas as diretivas de pré-processamento são executadas, expansões de macro são executadas e comentários são removidos. Para preservar os comentários na saída pré-processada, use o [/C (preservar comentários durante o pré-processamento)](../../build/reference/c-preserve-comments-during-preprocessing.md) com a opção **/EP**.

O **/EP** opção inibe compilação. Você deve reenviar o arquivo pré-processado para compilação. **/EP** também suprime os arquivos de saída a partir de **/FA**, **/Fa**, e **/Fm** opções. Para obter mais informações, consulte [/FA, /Fa (listando arquivo)](../../build/reference/fa-fa-listing-file.md) e [/Fm (Mapfile de nome)](../../build/reference/fm-name-mapfile.md).

Erros gerados durante os estágios posteriores de processamento se referem aos números de linha do arquivo pré-processado em vez de um arquivo de origem original. Se você quiser que os números de linha para se referir ao arquivo de origem original, use [/E (pré-processar em stdout)](../../build/reference/e-preprocess-to-stdout.md) em vez disso. O **/E** opção adiciona `#line` diretivas para a saída para essa finalidade.

Para enviar a saída pré-processada, com `#line` diretivas, em um arquivo, usam o [/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md) opção em vez disso.

Para enviar a saída pré-processada em stdout, com `#line` diretivas, use **p** e **/EP** juntos.

Não é possível usar cabeçalhos pré-compilados com o **/EP** opção.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **pré-processador** página de propriedades.

1. Modificar a **gerar o arquivo pré-processado** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.GeneratePreprocessedFile%2A>.

## <a name="example"></a>Exemplo

A seguinte linha de comando pré-processa arquivo `ADD.C`, preservará comentários e exibe o resultado no dispositivo de saída padrão:

```
CL /EP /C ADD.C
```

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
