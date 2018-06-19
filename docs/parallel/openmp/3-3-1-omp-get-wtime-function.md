---
title: 3.3.1 função omp_get_wtime | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 90188bd2-c53e-4398-8946-d3ecc92fa0f6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d71296d23df72464ed730713566c95e2403760a1
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33689487"
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