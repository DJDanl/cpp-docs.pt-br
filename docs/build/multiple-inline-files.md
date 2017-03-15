---
title: "V&#225;rios arquivos embutidos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos embutidos, NMAKE múltiplo"
  - "vários arquivos embutidos"
  - "programa NMAKE, arquivos embutidos"
ms.assetid: 6d381dcf-0ed8-45d1-8df3-b4598d860b99
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# V&#225;rios arquivos embutidos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um comando pode criar mais de um arquivo embutido.  
  
## Sintaxe  
  
```  
  
      command << <<  
inlinetext  
<<[KEEP | NOKEEP]  
inlinetext  
<<[KEEP | NOKEEP]  
```  
  
## Comentários  
 Para cada arquivo, especifique uma ou mais linhas de texto embutido seguidas por uma linha que contém o delimitador de fechamento.  Inicie o segundo arquivo de texto na linha após a linha de restrição para o primeiro arquivo.  
  
## Consulte também  
 [Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)