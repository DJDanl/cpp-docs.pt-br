---
title: noalias
ms.date: 07/07/2020
f1_keywords:
- noalias_cpp
helpviewer_keywords:
- noalias __declspec keyword
- __declspec keyword [C++], noalias
ms.assetid: efafa8b0-7f39-4edc-a81e-d287ae882c9b
ms.openlocfilehash: 70c1f4e8bfa426e858014a78febc424b473a89ae
ms.sourcegitcommit: e17cc8a478b51739d67304d7d82422967b35f716
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/08/2020
ms.locfileid: "86127876"
---
# `noalias`

**Específico da Microsoft**

**`noalias`** significa que uma chamada de função não modifica ou referencia o estado global visível e modifica apenas a memória apontada *diretamente* por parâmetros de ponteiro (indireçãos de primeiro nível).

Se uma função for anotada como **`noalias`** , o otimizador poderá pressupor que apenas os próprios parâmetros e apenas os indireções de primeiro nível dos parâmetros de ponteiro serão referenciados ou modificados dentro da função.

A **`noalias`** anotação só se aplica dentro do corpo da função anotada. Marcar uma função como **`__declspec(noalias)`** não afeta o alias de ponteiros retornados pela função.

Para outra anotação que pode afetar o alias, consulte [`__declspec(restrict)`](../cpp/restrict.md) .

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de **`__declspec(noalias)`** .

Quando a função `multiply` que acessa a memória é anotada **`__declspec(noalias)`** , ela informa ao compilador que essa função não modifica o estado global, exceto pelos ponteiros em sua lista de parâmetros.

```C
// declspec_noalias.c
#include <stdio.h>
#include <stdlib.h>

#define M 800
#define N 600
#define P 700

float * mempool, * memptr;

float * ma(int size)
{
    float * retval;
    retval = memptr;
    memptr += size;
    return retval;
}

float * init(int m, int n)
{
    float * a;
    int i, j;
    int k=1;

    a = ma(m * n);
    if (!a) exit(1);
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            a[i*n+j] = 0.1/k++;
    return a;
}

__declspec(noalias) void multiply(float * a, float * b, float * c)
{
    int i, j, k;

    for (j=0; j<P; j++)
        for (i=0; i<M; i++)
            for (k=0; k<N; k++)
                c[i * P + j] =
                          a[i * N + k] *
                          b[k * P + j];
}

int main()
{
    float * a, * b, * c;

    mempool = (float *) malloc(sizeof(float) * (M*N + N*P + M*P));

    if (!mempool)
    {
        puts("ERROR: Malloc returned null");
        exit(1);
    }

    memptr = mempool;
    a = init(M, N);
    b = init(N, P);
    c = init(M, P);

    multiply(a, b, c);
}
```

## <a name="see-also"></a>Confira também

[`__declspec`](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[`__declspec(restrict)`](../cpp/restrict.md)
