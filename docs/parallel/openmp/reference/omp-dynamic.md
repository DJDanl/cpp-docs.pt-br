---
title: "OMP_DYNAMIC | Microsoft Docs"
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
  - "OMP_DYNAMIC"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "OMP_DYNAMIC OpenMP environment variable"
ms.assetid: e306049d-b644-4b73-8b63-46c835bff98b
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# OMP_DYNAMIC
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Especifica se o tempo de execução de OpenMP pode ajustar o número de segmentos em uma região paralela.  
  
## Sintaxe  
  
```  
set OMP_DYNAMIC[=TRUE | =FALSE]  
```  
  
## Comentários  
 O `OMP_DYNAMIC` variável de ambiente pode ser substituída pela [omp\_set\_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) função.  
  
 O valor padrão na implementação do Visual C\+\+ do OpenMP padrão é `OMP_DYNAMIC=FALSE`.  
  
 Para obter mais informações, consulte [4.3 OMP\_DYNAMIC](../../../parallel/openmp/4-3-omp-dynamic.md).  
  
## Exemplo  
 O comando a seguir define o `OMP_DYNAMIC` a variável de ambiente como TRUE:  
  
```  
set OMP_DYNAMIC=TRUE  
```  
  
 O comando a seguir exibe a configuração atual da `OMP_DYNAMIC` variável de ambiente:  
  
```  
set OMP_DYNAMIC  
```  
  
## Consulte também  
 [Environment Variables](../../../parallel/openmp/reference/openmp-environment-variables.md)