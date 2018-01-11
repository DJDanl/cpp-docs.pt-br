---
title: "5 usando a diretiva crítica | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 14423018-25b9-4f98-92f2-34c9b0ac0ce0
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7cf4170fae6792906db29c90f61f067886b00f1d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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