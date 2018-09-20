---
title: A.24 exemplo da cláusula private | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: f90a5b49-81ff-4746-ae03-37bbd33f6c08
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: df2efc9fe111fa6e8d0b0507eceb20f07f48b02d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46416234"
---
# <a name="a24---example-of-the-private-clause"></a>A.24   Exemplo da cláusula private

O `private` cláusula ([seção 2.7.2.1](../../parallel/openmp/2-7-2-1-private.md) na página 25) de uma região paralela tem efeito somente para a extensão de léxica da região, e não para a extensão dinâmica da região.  Portanto, no exemplo a seguir, quaisquer usos da variável *uma* dentro a `for` loop na rotina *f* refere-se a uma cópia privada do *um*, enquanto um uso em rotina *g* refere-se ao global *um*.

```
int a;

void f(int n)
{
    a = 0;

    #pragma omp parallel for private(a)
    for (int i=1; i<n; i++)
    {
        a = i;
        g(i, n);
        d(a);     // Private copy of "a"
        ...
    }
    ...

void g(int k, int n)
{
    h(k,a); // The global "a", not the private "a" in f
}
```