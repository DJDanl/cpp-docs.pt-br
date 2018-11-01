---
title: noalias
ms.date: 02/09/2018
f1_keywords:
- noalias_cpp
helpviewer_keywords:
- noalias __declspec keyword
- __declspec keyword [C++], noalias
ms.assetid: efafa8b0-7f39-4edc-a81e-d287ae882c9b
ms.openlocfilehash: 2eceffd10f97615859918991320ceebf577d094c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50447119"
---
# <a name="noalias"></a>noalias

**Seção específica da Microsoft**

**noalias** significa que uma chamada de função não modifica nem referenciar o estado global visível e modifica somente a memória apontada *diretamente* pelos parâmetros de ponteiro (indireções de primeiro nível).

Se uma função é anotada como **noalias**, o otimizador pode assumir que, além dos parâmetros em si, indireções de primeiro nível apenas dos parâmetros do ponteiro são referenciadas ou modificadas na função. O estado global visível é o conjunto de todos os dados que não estão definidos ou referenciados fora do escopo da compilação, e o endereço não é pego. O escopo da compilação é todos os arquivos de origem ([/LTCG (geração de código Link-time)](../build/reference/ltcg-link-time-code-generation.md) compilações) ou um único arquivo de origem (não -**/LTCG** compilar).

O **noalias** anotação se aplica somente dentro do corpo da função anotado. Marcar uma função como **__declspec(noalias)** não afeta a suavização de ponteiros retornados pela função.

Para outra anotação que pode afetar o alias, consulte [__declspec(restrict)](../cpp/restrict.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de **__declspec(noalias)**.

Quando a função `multiply` que os acessos de memória é anotada **__declspec(noalias)**, ele informa ao compilador que essa função não modifica o estado global exceto por ponteiros na sua lista de parâmetros.

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

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[__declspec(restrict)](../cpp/restrict.md)
