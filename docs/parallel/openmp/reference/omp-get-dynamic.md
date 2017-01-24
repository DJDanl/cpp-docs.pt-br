---
title: "omp_get_dynamic | Microsoft Docs"
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
  - "omp_get_dynamic"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "omp_get_dynamic OpenMP function"
ms.assetid: efa843c5-7266-4a75-8db3-22992663d9db
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# omp_get_dynamic
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Retorna um valor que indica se o número de threads disponíveis na região paralela subseqüente pode ser ajustado pelo tempo de execução.  
  
## Sintaxe  
  
```  
int omp_get_dynamic();  
```  
  
## Valor de retorno  
 Se for diferente de zero, o ajuste dinâmico de threads está habilitado.  
  
## Comentários  
 Ajuste dinâmico de segmentos é especificado com [omp\_set\_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) e [OMP\_DYNAMIC](../../../parallel/openmp/reference/omp-dynamic.md).  
  
 Para obter mais informações, consulte [3.1.7 omp\_set\_dynamic Function](../../../parallel/openmp/3-1-7-omp-set-dynamic-function.md).  
  
## Exemplo  
 Consulte [omp\_set\_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) para obter um exemplo do uso de `omp_get_dynamic`.  
  
## Consulte também  
 [Functions](../../../parallel/openmp/reference/openmp-functions.md)