---
title: "default (OpenMP) | Microsoft Docs"
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
  - "default"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "default OpenMP clause"
  - "defaults, OpenMP clause"
ms.assetid: 96055106-a8f0-40b3-8319-e412b6e07bf8
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# default (OpenMP)
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Especifica o comportamento de variáveis unscoped em uma região paralela.  
  
## Sintaxe  
  
```  
default(shared | none)  
```  
  
## Comentários  
 `shared`, que está em vigor se a `default` cláusula não for especificada, significa que qualquer variável em uma região paralela será tratado como se ele tiver sido especificado com o [shared](../../../parallel/openmp/reference/shared-openmp.md) cláusula.  `none`significa que todas as variáveis usadas em uma região paralela que não têm o escopo com o [private](../../../parallel/openmp/reference/private-openmp.md), [shared](../../../parallel/openmp/reference/shared-openmp.md), [reduction](../../../parallel/openmp/reference/reduction.md), [firstprivate](../Topic/firstprivate.md), ou [lastprivate](../../../parallel/openmp/reference/lastprivate.md) cláusula causará um erro do compilador.  
  
 `default`aplica as diretivas a seguir:  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [for](../Topic/for%20\(OpenMP\).md)  
  
-   [sections](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.5 default](../../../parallel/openmp/2-7-2-5-default.md).  
  
## Exemplo  
 Consulte [private](../../../parallel/openmp/reference/private-openmp.md) para obter um exemplo do uso de `default`.  
  
## Consulte também  
 [Clauses](../../../parallel/openmp/reference/openmp-clauses.md)