---
title: "OMP_SCHEDULE | Microsoft Docs"
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
  - "OMP_SCHEDULE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "OMP_SCHEDULE OpenMP environment variable"
ms.assetid: 2295a801-e584-4d2f-826f-7ca4c88846a6
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# OMP_SCHEDULE
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Modifica o comportamento da [schedule](../../../parallel/openmp/reference/schedule.md) cláusula quando `schedule(runtime)` é especificado em um `for` ou `parallel for` diretiva.  
  
## Sintaxe  
  
```  
set OMP_SCHEDULE[=type[,size]]  
```  
  
## Comentários  
 onde,  
  
 `size`\(opcional\)  
 Especifica o tamanho de iterações.  `size`deve ser um inteiro positivo.  O padrão é 1, exceto quando `type` é estático.  Not valid when `type` is `runtime`.  
  
 `type`  
 O tipo de agendamento:  
  
-   `dynamic`  
  
-   `guided`  
  
-   `runtime`  
  
-   `static`  
  
## Comentários  
 O valor padrão na implementação do Visual C\+\+ do OpenMP padrão é `OMP_SCHEDULE=static,0`.  
  
 Para obter mais informações, consulte [4.1 OMP\_SCHEDULE](../../../parallel/openmp/4-1-omp-schedule.md).  
  
## Exemplo  
 O comando a seguir define o  **OMP\_SCHEDULE** variável de ambiente:  
  
```  
set OMP_SCHEDULE="guided,2"  
```  
  
 O comando a seguir exibe a configuração atual da  **OMP\_SCHEDULE** variável de ambiente:  
  
```  
set OMP_SCHEDULE  
```  
  
## Consulte também  
 [Environment Variables](../../../parallel/openmp/reference/openmp-environment-variables.md)