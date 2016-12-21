---
title: "_CRT_DISABLE_PERFCRIT_LOCKS | Microsoft Docs"
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
  - "_CRT_DISABLE_PERFCRIT_LOCKS"
  - "CRT_DISABLE_PERFCRIT_LOCKS"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _CRT_DISABLE_PERFCRIT_LOCKS"
  - "Constante CRT_DISABLE_PERFCRIT_LOCKS"
ms.assetid: 36cc2d86-cdb1-4b2b-a03c-c0d3818e7c6f
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CRT_DISABLE_PERFCRIT_LOCKS
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Desabilita o bloqueio desempenho crítico em operações de E\/S.  
  
## Sintaxe  
  
```  
#define _CRT_DISABLE_PERFCRIT_LOCKS  
```  
  
## Comentários  
 Definir esse símbolo pode melhorar o desempenho em programas de thread único de E\/S\- limite todas as operações forçando de E\/S para assumir um modelo de thread único de E\/S.  Para obter mais informações, consulte [Desempenho de bibliotecas multithread](../c-runtime-library/multithreaded-libraries-performance.md).  
  
## Consulte também  
 [Constantes globais](../c-runtime-library/global-constants.md)