---
title: "3.2.1 omp_init_lock and omp_init_nest_lock Functions | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 098a2721-b16a-484f-bc83-4b8e281e382c
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 3.2.1 omp_init_lock and omp_init_nest_lock Functions
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essas funções fornecem o único meio de inicializar um bloqueio.  Cada função inicializa o bloqueio associado ao parâmetro  *lock* para uso em chamadas subseqüentes.  O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_init_lock(omp_lock_t *lock);  
void omp_init_nest_lock(omp_nest_lock_t *lock);  
```  
  
 O estado inicial está desbloqueado \(ou seja, nenhum segmento possui o bloqueio\).  Para um bloqueio de nestable, a contagem de aninhamento inicial é zero.  Ele é não compatível para chamar qualquer uma dessas rotinas com uma variável de bloqueio que já foi inicializado.