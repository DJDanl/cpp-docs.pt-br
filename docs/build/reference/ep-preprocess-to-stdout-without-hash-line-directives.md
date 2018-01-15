---
title: "-EP (pré-processar para stdout sem diretivas de #line) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /ep
- VC.Project.VCCLCompilerTool.GeneratePreprocessedFileNoLines
dev_langs: C++
helpviewer_keywords:
- copy preprocessor output to stdout
- preprocessor output, copy to stdout
- -EP compiler option [C++]
- EP compiler option [C++]
- /EP compiler option [C++]
ms.assetid: 6ec411ae-e33d-4ef5-956e-0054635eabea
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9d7b2a64ec8fa7565d17ab04683fec07c48aea3f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ep-preprocess-to-stdout-without-line-directives"></a>/EP (pré-processar para stdout sem diretivas #line)
Pré-processa arquivos de origem C e C++ e copia os arquivos pré-processado para o dispositivo de saída padrão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/EP  
```  
  
## <a name="remarks"></a>Comentários  
 No processo, todas as diretivas de pré-processador são executadas, expansões de macro são executadas e comentários são removidos. Para preservar comentários na saída pré-processada, use o [/C (preservar comentários durante o pré-processamento)](../../build/reference/c-preserve-comments-during-preprocessing.md) com a opção **/EP**.  
  
 O **/EP** opção inibe compilação. Você deverá reenviar o arquivo pré-processados para compilação. **/EP** também suprime os arquivos de saída de **/FA**, **/Fa**, e **/Fm** opções. Para obter mais informações, consulte [/FA, /Fa (listando arquivo)](../../build/reference/fa-fa-listing-file.md) e [/Fm (Mapfile de nome)](../../build/reference/fm-name-mapfile.md).  
  
 Erros gerados durante as fases posteriores de processamento se referir aos números de linha de arquivo pré-processados em vez do arquivo de origem. Se desejar que os números de linha, consulte o arquivo de origem, use [/E (pré-processar em stdout)](../../build/reference/e-preprocess-to-stdout.md) em vez disso. O **/E** opção adiciona `#line` diretivas para a saída para essa finalidade.  
  
 Para enviar a saída pré-processada, com `#line` diretivas, para um arquivo, usam o [/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md) opção.  
  
 Para enviar a saída pré-processada em stdout, com `#line` diretivas, use **/p** e **/EP** juntos.  
  
 Não é possível usar cabeçalhos pré-compilados com o **/EP** opção.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **pré-processador** página de propriedades.  
  
4.  Modificar o **gerar arquivo pré-processados** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.GeneratePreprocessedFile%2A>.  
  
## <a name="example"></a>Exemplo  
 A seguinte linha de comando pré-processa arquivo `ADD.C`, preserva comentários e exibe o resultado no dispositivo de saída padrão:  
  
```  
CL /EP /C ADD.C  
```  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)