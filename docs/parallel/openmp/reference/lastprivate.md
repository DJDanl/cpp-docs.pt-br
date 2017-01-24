---
title: "lastprivate | Microsoft Docs"
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
  - "lastprivate"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "lastprivate OpenMP clause"
ms.assetid: 6ef87b31-375a-47e8-8d0d-281be45fb56a
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# lastprivate
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Especifica a versão do contexto delimitador da variável é definida igual à versão particular de qualquer segmento executa a iteração final \(construção for loop\) ou a última seção \(\# pragma seções\).  
  
## Sintaxe  
  
```  
lastprivate(var)  
```  
  
## Comentários  
 onde,  
  
 `var`  
 A variável definida igual à versão particular do segmento que for executa a iteração final \(construção for loop\) ou a última seção \(\# pragma seções\).  
  
## Comentários  
 `lastprivate`aplica as diretivas a seguir:  
  
-   [for](../Topic/for%20\(OpenMP\).md)  
  
-   [sections](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.3 lastprivate](../Topic/2.7.2.3%20lastprivate.md).  
  
## Exemplo  
 Consulte [schedule](../../../parallel/openmp/reference/schedule.md) para obter um exemplo do uso de `lastprivate` cláusula.  
  
## Consulte também  
 [Clauses](../../../parallel/openmp/reference/openmp-clauses.md)