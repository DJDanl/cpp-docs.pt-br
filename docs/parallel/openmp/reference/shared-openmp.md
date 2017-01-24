---
title: "shared (OpenMP) | Microsoft Docs"
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
  - "Shared"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "shared OpenMP clause"
ms.assetid: 7887dc95-67a2-462f-a3a2-8e0632bf5d04
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# shared (OpenMP)
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Especifica que uma ou mais variáveis devem ser compartilhadas entre todos os threads.  
  
## Sintaxe  
  
```  
shared(var)  
```  
  
## Comentários  
 onde,  
  
 `var`  
 Variáveis de mais um para compartilhar.  Se mais de uma variável for especificada, separe os nomes de variáveis com uma vírgula.  
  
## Comentários  
 Outra maneira de compartilhar variáveis entre threads é com o [copyprivate](../Topic/copyprivate.md) cláusula.  
  
 `shared`aplica as diretivas a seguir:  
  
-   [for](../Topic/for%20\(OpenMP\).md)  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [sections](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.4 shared](../../../parallel/openmp/2-7-2-4-shared.md).  
  
## Exemplo  
 Consulte [private](../../../parallel/openmp/reference/private-openmp.md) para obter um exemplo do uso de `shared`.  
  
## Consulte também  
 [Clauses](../../../parallel/openmp/reference/openmp-clauses.md)