---
title: "3.3.1 função omp_get_wtime | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 90188bd2-c53e-4398-8946-d3ecc92fa0f6
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0f89a71d1b91a27dfdd0abf13be4a5f0e30b3fd9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="331-ompgetwtime-function"></a>3.3.1 função omp_get_wtime
O `omp_get_wtime` função retorna um valor de ponto flutuante de precisão dupla igual para o tempo decorrido em segundos desde alguma "hora no passado".  O "tempo no passado" real é arbitrário, mas é garantido para não alterar durante a execução do programa aplicativo. O formato é o seguinte:  
  
```  
#include <omp.h>  
double omp_get_wtime(void);  
```  
  
 Espera-se que a função será usada para medir o tempo conforme mostrado no exemplo a seguir:  
  
```  
double start;  
double end;  
start = omp_get_wtime();  
... work to be timed ...  
end = omp_get_wtime();  
printf_s("Work took %f sec. time.\n", end-start);  
```  
  
 Os tempos de retornados são "tempo por segmento" por que é destinado a que eles não precisam ser globalmente consistente em todos os threads participando de um aplicativo.