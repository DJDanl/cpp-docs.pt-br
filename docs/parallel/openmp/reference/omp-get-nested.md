---
title: "omp_get_nested | Microsoft Docs"
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
  - "omp_get_nested"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "omp_get_nested OpenMP function"
ms.assetid: e9784847-516e-40d3-89f7-b8b6898d8667
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# omp_get_nested
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Retorna um valor que indica se o paralelismo aninhado está ativado.  
  
## Sintaxe  
  
```  
int omp_get_nested( );  
```  
  
## Valor de retorno  
 Se for diferente de zero, o paralelismo aninhado está habilitado.  
  
## Comentários  
 Paralelismo aninhado é especificado com [omp\_set\_nested](../../../parallel/openmp/reference/omp-set-nested.md) e [OMP\_NESTED](../../../parallel/openmp/reference/omp-nested.md).  
  
 Para obter mais informações, consulte [3.1.10 omp\_get\_nested Function](../../../parallel/openmp/3-1-10-omp-get-nested-function.md).  
  
## Exemplo  
 Consulte [omp\_set\_nested](../../../parallel/openmp/reference/omp-set-nested.md) para obter um exemplo do uso de `omp_get_nested`.  
  
## Consulte também  
 [Functions](../../../parallel/openmp/reference/openmp-functions.md)