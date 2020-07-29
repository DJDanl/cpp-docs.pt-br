---
title: restrict
ms.date: 02/09/2018
f1_keywords:
- restrict_cpp
helpviewer_keywords:
- __declspec keyword [C++], restrict
- restrict __declspec keyword
ms.assetid: f39cf632-68d8-4362-a497-2d4c15693689
ms.openlocfilehash: a0108cff3d6b98fd929b7888d2ad718e7b6b3a64
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213249"
---
# <a name="restrict"></a>restrict

**Específico da Microsoft**

Quando aplicado a uma declaração ou definição de função que retorna um tipo de ponteiro, **`restrict`** diz ao compilador que a função retorna um objeto que não tem um *alias*, ou seja, referenciado por quaisquer outros ponteiros. Isso permite que o compilador execute otimizações adicionais.

## <a name="syntax"></a>Sintaxe

> **`__declspec(restrict)`***pointer_return_type* *função*pointer_return_type ();

## <a name="remarks"></a>Comentários

O compilador é propagado **`__declspec(restrict)`** . Por exemplo, a `malloc` função CRT tem uma **`__declspec(restrict)`** decoração e, portanto, o compilador supõe que os ponteiros inicializados para locais de memória `malloc` também não têm o alias de ponteiros existentes anteriormente.

O compilador não verifica se o ponteiro retornado não é, na verdade, alias. É responsabilidade do desenvolvedor garantir que o programa não faça o alias de um ponteiro marcado com o modificador **restrict __declspec** .

Para obter semântica semelhante em variáveis, consulte [__restrict](../cpp/extension-restrict.md).

Para outra anotação que se aplica a alias em uma função, consulte [__declspec (noalias)](../cpp/noalias.md).

Para obter informações sobre a **`restrict`** palavra-chave que faz parte de C++ amp, consulte [restringir (C++ amp)](../cpp/restrict-cpp-amp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de **`__declspec(restrict)`** .

Quando **`__declspec(restrict)`** é aplicado a uma função que retorna um ponteiro, isso informa ao compilador que a memória apontada pelo valor de retorno não tem um alias. Neste exemplo, os ponteiros `mempool` e `memptr` são globais, portanto, o compilador não pode ter certeza de que a memória à qual se refere não tem um alias. No entanto, eles são usados em `ma` e `init` em seu chamador de uma forma que retorna a memória que não é referenciada pelo programa, de modo que **__decslpec (restrito)** é usado para ajudar o otimizador. Isso é semelhante a como os cabeçalhos CRT decoram funções de alocação, como `malloc` usando o **`__declspec(restrict)`** para indicar que sempre retornam memória que não pode ser alias por ponteiros existentes.

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

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[__declspec](../cpp/declspec.md)<br/>
[__declspec (noalias)](../cpp/noalias.md)
