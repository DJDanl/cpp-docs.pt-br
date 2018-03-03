---
title: "-P (pré-processar em um arquivo) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0f4de2f19820a846197806e0a24ddc213dd636c4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="p-preprocess-to-a-file"></a>/P (pré-processar em um arquivo)
Pré-processa arquivos de origem C e C++ e grava a saída pré-processada em um arquivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/P  
```  
  
## <a name="remarks"></a>Comentários  
 O arquivo tem o mesmo nome base do arquivo de origem e uma extensão de .i. No processo, todas as diretivas de pré-processador são executadas, expansões de macro são executadas e comentários são removidos. Para preservar comentários na saída pré-processada, use o [/C (preservar comentários durante o pré-processamento)](../../build/reference/c-preserve-comments-during-preprocessing.md) juntamente com **/p**.  
  
 **/ P** adiciona `#line` diretivas para a saída, no início e no final de cada arquivo incluído e em torno de linhas removidas por diretivas de pré-processador para compilação condicional. Essas diretivas renumerar as linhas do arquivo pré-processados. Como resultado, os erros gerados durante posteriores estágios do processamento de consultem os números de linha do arquivo original em vez de linhas no arquivo pré-processados. Para suprimir a geração de `#line` diretivas, use [/EP (pré-processar para stdout sem diretivas de #line)](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) , bem como **/p**.  
  
 O **/p** opção inibe compilação. Não produz um arquivo. obj, mesmo se você usar [/Fo (nome de arquivo de objeto)](../../build/reference/fo-object-file-name.md). Você deverá reenviar o arquivo pré-processados para compilação. **/ P** também suprime os arquivos de saída de **/FA**, **/Fa**, e **/Fm** opções. Para obter mais informações, consulte [/FA, /Fa (listando arquivo)](../../build/reference/fa-fa-listing-file.md) e [/Fm (Mapfile de nome)](../../build/reference/fm-name-mapfile.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **pré-processador** página de propriedades.  
  
4.  Modificar o **gerar arquivo pré-processados** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.GeneratePreprocessedFile%2A>.  
  
## <a name="example"></a>Exemplo  
 A seguinte linha de comando pré-processa `ADD.C`, preserva comentários, adiciona `#line` diretivas e grava o resultado em um arquivo, `ADD.I`:  
  
```  
CL /P /C ADD.C  
```  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [/Fi (pré-processar nome do arquivo de saída)](../../build/reference/fi-preprocess-output-file-name.md)