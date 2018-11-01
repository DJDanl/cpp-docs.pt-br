---
title: A.5   Usando a diretiva critical
ms.date: 11/04/2016
ms.assetid: 14423018-25b9-4f98-92f2-34c9b0ac0ce0
ms.openlocfilehash: 82497d63acc057fbbcf26f585e42fc8611c08ec4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50545079"
---
# <a name="a5---using-the-critical-directive"></a>A.5   Usando a diretiva critical

O exemplo a seguir inclui vários `critical` diretivas ([seção 2.6.2](../../parallel/openmp/2-6-2-critical-construct.md) na página 18). O exemplo ilustra um modelo de enfileiramento de mensagens em que uma tarefa é removida da fila e trabalhou em. Para se proteger contra vários threads remover da fila a mesma tarefa, a operação remover deve estar em um `critical` seção. Como as duas filas neste exemplo são independentes, eles são protegidos pelo `critical` com nomes diferentes, as diretivas *numérica de xaxis* e *yaxis*.

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