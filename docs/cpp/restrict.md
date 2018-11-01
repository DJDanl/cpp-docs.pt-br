---
title: restrict
ms.date: 02/09/2018
f1_keywords:
- restrict_cpp
helpviewer_keywords:
- __declspec keyword [C++], restrict
- restrict __declspec keyword
ms.assetid: f39cf632-68d8-4362-a497-2d4c15693689
ms.openlocfilehash: 40c1c05ca72f639829f2d3658497b0e9f3199640
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50431740"
---
# <a name="restrict"></a>restrict

**Seção específica da Microsoft**

Quando aplicado a uma declaração de função ou a definição que retorna um tipo de ponteiro **restringir** informa ao compilador que a função retorna um objeto que não seja *um alias*, ou seja, referenciada por nenhum outro ponteiros. Isso permite que o compilador execute otimizações adicionais.

## <a name="syntax"></a>Sintaxe

> **__declspec(restrict)** *pointer_return_type* *function*();

## <a name="remarks"></a>Comentários

O compilador propaga **__declspec(restrict)**. Por exemplo, o CRT `malloc` função tem um **__declspec(restrict)** decoração e, portanto, o compilador pressupõe que os ponteiros inicializados para locais de memória por `malloc` também não são um alias por anteriormente ponteiros existentes.

O compilador não verifica que o ponteiro retornado não é realmente um alias. É responsabilidade do desenvolvedor para garantir que o programa não coloque alias em um ponteiro com o **restringir declspec** modificador.

Para a semântica semelhante em variáveis, consulte [Restrict](../cpp/extension-restrict.md).

Para outra anotação se aplica ao alias dentro de uma função, consulte [__declspec(noalias)](../cpp/noalias.md).

Para obter informações sobre o **restringir** palavra-chave que faz parte do C++ AMP, consulte [restrita (C++ AMP)](../cpp/restrict-cpp-amp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de **__declspec(restrict)**.

Quando **__declspec(restrict)** é aplicado a uma função que retorna um ponteiro, isso informa ao compilador que a memória apontada pelo valor retornado não é um alias. Neste exemplo, os ponteiros `mempool` e `memptr` são globais, para que o compilador não pode ter certeza de que a memória que referem-se não é um alias. No entanto, elas são usadas no `ma` e seu chamador `init` de forma que retorna a memória que, caso contrário, não é referenciada pelo programa, portanto **__decslpec(restrict)** é usado para ajudar o otimizador. Isso é semelhante a como os cabeçalhos de CRT decoram funções de alocação, como `malloc` por meio **__declspec(restrict)** para indicar que eles sempre retornam uma memória que não pode ser um alias existente ponteiros.

```C
// declspec_restrict.c
// Compile with: cl /W4 declspec_restrict.c
#include <stdio.h>
#include <stdlib.h>

#define M 800
#define N 600
#define P 700

float * mempool, * memptr;

__declspec(restrict) float * ma(int size)
{
    float * retval;
    retval = memptr;
    memptr += size;
    return retval;
}

__declspec(restrict) float * init(int m, int n)
{
    float * a;
    int i, j;
    int k=1;

    a = ma(m * n);
    if (!a) exit(1);
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            a[i*n+j] = 0.1f/k++;
    return a;
}

void multiply(float * a, float * b, float * c)
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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[__declspec](../cpp/declspec.md)<br/>
[__declspec(noalias)](../cpp/noalias.md)
