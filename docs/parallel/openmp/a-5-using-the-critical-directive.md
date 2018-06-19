---
title: 5 usando a diretiva crítica | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 14423018-25b9-4f98-92f2-34c9b0ac0ce0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c1a41e9664faaca24b6708c737a044828eb460bd
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33686250"
---
# <a name="a5---using-the-critical-directive"></a>A.5   Usando a diretiva critical
O exemplo a seguir inclui vários `critical` diretivas ([seção 2.6.2](../../parallel/openmp/2-6-2-critical-construct.md) na página 18). O exemplo ilustra um modelo de enfileiramento de mensagens em que uma tarefa é removida da fila e trabalhada. Para se proteger contra vários threads removê-la fila a mesma tarefa, a operação dequeuing deve estar em um `critical` seção. Como as duas filas neste exemplo são independentes, eles são protegidos por `critical` diretivas com nomes diferentes, *xaxis* e *yaxis*.  
  
```  
#pragma omp parallel shared(x, y) private(x_next, y_next)  
{  
    #pragma omp critical ( xaxis )  
        x_next = dequeue(x);  
    work(x_next);  
    #pragma omp critical ( yaxis )  
        y_next = dequeue(y);  
    work(y_next);  
}  
```