---
title: "/EP (pr&#233;-processar para stdout sem diretivas #line) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/ep"
  - "VC.Project.VCCLCompilerTool.GeneratePreprocessedFileNoLines"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /EP (C++)"
  - "copiar saída de pré-processador em stdout"
  - "Opção de compilador EP [C++]"
  - "Opção de compilador -EP [C++]"
  - "saída de pré-processador, copiar em stdout"
ms.assetid: 6ec411ae-e33d-4ef5-956e-0054635eabea
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /EP (pr&#233;-processar para stdout sem diretivas #line)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Preprocesses arquivos de origem de 2.0 C e C\+\+ e copia os arquivos pré\-processados para o dispositivo de saída padrão.  
  
## Sintaxe  
  
```  
/EP  
```  
  
## Comentários  
 No processo, todas as políticas de pré\-processador são realizadas, as expansões macro são executadas, e os comentários são removidos.  Para preservar comentários na saída pré\-processados, use a opção de [\/C \(preservar comentários durante o pré\-processamento\)](../../build/reference/c-preserve-comments-during-preprocessing.md) com **\/EP**.  
  
 A opção de **\/EP** suprime a compilação.  Você deve enviar novamente o arquivo pré\-processados para a compilação.  **\/EP** também elimina os arquivos de saída de **\/FA**, de **\/Fa**, e as opções de **\/Fm** .  Para obter mais informações, consulte [\/FA, \/Fa \(listando arquivo\)](../../build/reference/fa-fa-listing-file.md) e [\/Fm \(mapfile de nome\)](../Topic/-Fm%20\(Name%20Mapfile\).md).  
  
 Os erros gerados durante estados avançadas de processamento se referem aos números de linhas do arquivo pré\-processados em vez do arquivo de origem original.  Se você quiser números de linha para fazer referência ao arquivo de origem, use [\/E \(pré\-processar em stdout\)](../../build/reference/e-preprocess-to-stdout.md) em vez disso.  A opção de **\/E** adiciona políticas de `#line` à saída para essa finalidade.  
  
 Para enviar a saída pré\-processados, com políticas de `#line` , em um arquivo, use a opção de [\/P \(pré\-processar em um arquivo\)](../../build/reference/p-preprocess-to-a-file.md) em vez disso.  
  
 Para enviar junto a saída pré\-processados para stdout, com políticas de `#line` , use **\/P** e **\/EP** .  
  
 Você não pode usar cabeçalhos pré\-compilados com a opção de **\/EP** .  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Pré\-Processador** .  
  
4.  Modifique a propriedade de **Gerar Arquivo Pré\-Processado** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.GeneratePreprocessedFile%2A>.  
  
## Exemplo  
 A linha de comando a seguir preprocesses o arquivo `ADD.C`, preserva comentários, e exibe o resultado no dispositivo de saída padrão:  
  
```  
CL /EP /C ADD.C  
```  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)