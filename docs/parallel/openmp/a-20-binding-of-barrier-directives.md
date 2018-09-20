---
title: A.20 vinculação de diretivas barrier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a3fdcc26-6873-429b-998e-de451401483b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 628920caa6a122230f42394cc757e3abdb1874cd
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46381303"
---
# <a name="a20---binding-of-barrier-directives"></a>A.20  Vinculação de diretivas barrier

A associação de diretiva de regras de chamada para um **barreira** diretiva para associar a mais próxima circunscrição `parallel` diretiva. Para obter mais informações sobre associação de diretiva, consulte [2.8 seção](../../parallel/openmp/2-8-directive-binding.md) na página 32.

No exemplo a seguir, a chamada de *principal* para *sub2* está em conformidade porque a **barreira** (na *sub3*) é associado à região paralela na *sub2*. A chamada de *principal* para *sub1* está em conformidade porque as **barreira** liga para a região paralela na sub-rotina *sub2*.  A chamada de *principal* para *sub3* está em conformidade porque as **barreira** não associar a qualquer região paralela e será ignorado. Observe também que o **barreira** sincroniza somente a equipe de threads na região paralela delimitador e nem todos os threads criados no *sub1*.

```
int main()
{
    sub1(2);
    sub2(2);
    sub3(2);
}

void sub1(int n)
{
    int i;
    #pragma omp parallel private(i) shared(n)
    {
        #pragma omp for
        for (i=0; i<n; i++)
            sub2(i);
    }
}

void sub2(int k)
{
     #pragma omp parallel shared(k)
     sub3(k);
}

void sub3(int n)
{
    work(n);
    #pragma omp barrier
    work(n);
}
```