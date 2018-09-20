---
title: A.15 determinando o número de Threads usados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 026bb59a-f668-40db-a7cb-69a1bae83d2d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1042b4871f53bddb5cff894330f3afe7d8a088ef
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46428729"
---
# <a name="a15---determining-the-number-of-threads-used"></a>A.15  Determinando o número de threads usados

Considere o seguinte exemplo incorreto (para [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37):

```
np = omp_get_num_threads(); // misplaced
#pragma omp parallel for schedule(static)
    for (i=0; i<np; i++)
        work(i);
```

O `omp_get_num_threads()` chamar retorna 1 na seção serial do código, então *np* sempre será igual a 1 no exemplo anterior. Para determinar o número de threads que serão implantados para a região paralela, a chamada deve ser dentro da região paralela.

O exemplo a seguir mostra como reescrever esse programa sem a inclusão de uma consulta para o número de threads:

```
#pragma omp parallel private(i)
{
    i = omp_get_thread_num();
    work(i);
}
```