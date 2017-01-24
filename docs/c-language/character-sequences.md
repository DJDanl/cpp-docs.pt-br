---
title: "Sequ&#234;ncias de caracteres | Microsoft Docs"
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
  - "C"
ms.assetid: 1e6961a9-150e-4c13-b427-9af4b6a1fb7a
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sequ&#234;ncias de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 3.8.2** O mapeamento de sequências de caracteres do arquivo de origem  
  
 As instruções do pré\-processador usam o mesmo conjunto de caracteres das instruções de arquivo de origem, com exceção das sequências de escape, que não têm suporte.  
  
 Assim, para especificar um caminho para um arquivo de inclusão, use somente uma barra invertida:  
  
```  
#include "path1\path2\myfile"  
```  
  
 No código\-fonte, duas barras invertidas são necessárias:  
  
```  
fil = fopen( "path1\\path2\\myfile", "rt" );  
```  
  
## Consulte também  
 [Pré\-processando diretivas](../Topic/Preprocessing%20Directives.md)