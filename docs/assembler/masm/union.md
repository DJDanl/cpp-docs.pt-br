---
title: "UNION | Microsoft Docs"
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
  - "union"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "UNION directive"
ms.assetid: 52504abf-7dc1-47c5-944c-b886803a0c6a
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# UNION
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Declara uma união de um ou mais tipos de dados.  O  *fielddeclarations* deve ser definições de dados válidos.  Omitir o  [termina](../../assembler/masm/ends-masm.md)*nome* aninhados de rótulo em  **união** definições.  
  
## Sintaxe  
  
```  
  
      name   
      UNION [[alignment]] [[, NONUNIQUE]]  
   fielddeclarations  
[[name]] ENDS  
```  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)