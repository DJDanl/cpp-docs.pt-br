---
title: A.5 usando a diretiva critical | Microsoft Docs
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
ms.openlocfilehash: 99f9ab513ae1df5a7e1e62cfefcefe404637c063
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46444561"
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