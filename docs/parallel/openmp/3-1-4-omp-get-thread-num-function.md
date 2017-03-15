---
title: "3.1.4 omp_get_thread_num Function | Microsoft Docs"
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
ms.assetid: 5220402b-c109-4b1f-ba79-002e93d08617
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 3.1.4 omp_get_thread_num Function
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O `omp_get_thread_num` função retorna o número de segmento, dentro de sua equipe, do thread executando a função.  O consiste de thread número entre 0 e  **omp\_get\_num\_threads\(\)**– 1, inclusive.  O segmento principal da equipe é 0.  
  
 O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_get_thread_num(void);  
```  
  
 Se for chamado de uma região serial, `omp_get_thread_num` retorna 0.  Se for chamado de dentro de uma região paralela aninhada que for serializada, esta função retorna 0.  
  
## Entre as referências:  
  
-   `omp_get_num_threads`função, consulte  [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37.