---
title: "3.3.1 omp_get_wtime Function | Microsoft Docs"
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
ms.assetid: 90188bd2-c53e-4398-8946-d3ecc92fa0f6
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 3.3.1 omp_get_wtime Function
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O `omp_get_wtime` função retorna um valor de ponto flutuante de precisão dupla igual a do tempo decorrido em segundos desde alguns "no passado tempo".  O "tempo no passado" real é arbitrário, mas é garantido para não alterar durante a execução do programa aplicativo.  O formato é o seguinte:  
  
```  
#include <omp.h>  
double omp_get_wtime(void);  
```  
  
 É definido de antemão que a função será usada para medir os tempos decorridos conforme mostrado no exemplo a seguir:  
  
```  
double start;  
double end;  
start = omp_get_wtime();  
... work to be timed ...  
end = omp_get_wtime();  
printf_s("Work took %f sec. time.\n", end-start);  
```  
  
 Os tempos de retornados são "vezes por thread" por que é destinado a que eles não precisam ser globalmente consistente em todos os threads que estejam participando de um aplicativo.