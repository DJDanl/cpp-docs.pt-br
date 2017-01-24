---
title: "OMP_NESTED | Microsoft Docs"
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
  - "OMP_NESTED"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "OMP_NESTED OpenMP environment variable"
ms.assetid: c43f5287-a548-40d0-bd54-0c6b2b9f9a53
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# OMP_NESTED
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Especifica se o paralelismo aninhado está ativado, a menos que o paralelismo aninhado está habilitado ou desabilitado com `omp_set_nested`.  
  
## Sintaxe  
  
```  
set OMP_NESTED[=TRUE | =FALSE]  
```  
  
## Comentários  
 O `OMP_NESTED` variável de ambiente pode ser substituída pela [omp\_set\_nested](../../../parallel/openmp/reference/omp-set-nested.md) função.  
  
 O valor padrão na implementação do Visual C\+\+ do OpenMP padrão é `OMP_DYNAMIC=FALSE`.  
  
 Para obter mais informações, consulte [4.4 OMP\_NESTED](../Topic/4.4%20OMP_NESTED.md).  
  
## Exemplo  
 O comando a seguir define o `OMP_NESTED` a variável de ambiente como TRUE:  
  
```  
set OMP_NESTED=TRUE  
```  
  
 O comando a seguir exibe a configuração atual da `OMP_NESTED` variável de ambiente:  
  
```  
set OMP_NESTED  
```  
  
## Consulte também  
 [Environment Variables](../../../parallel/openmp/reference/openmp-environment-variables.md)