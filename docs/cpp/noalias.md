---
title: noalias | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- noalias
- noalias_cpp
dev_langs:
- C++
helpviewer_keywords:
- noalias __declspec keyword
- __declspec keyword [C++], noalias
ms.assetid: efafa8b0-7f39-4edc-a81e-d287ae882c9b
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: cb8d3425b08984f31954df3a7cf7771e85301a5b
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="noalias"></a>noalias

**Seção específica da Microsoft**

`noalias`significa que uma chamada de função não modificar ou referência de estado global visível e modifica somente a memória apontada *diretamente* por parâmetros de ponteiro (primeiro nível referências indiretas).

Se uma função é anotada como `noalias`, o otimizador pode assumir que, além dos parâmetros em si, somente as indireções de primeiro nível dos parâmetros do ponteiro são referenciadas ou modificadas na função. O estado global visível é o conjunto de todos os dados que não estão definidos ou referenciados fora do escopo da compilação, e o endereço não é pego. O escopo de compilação é todos os arquivos de origem ([/LTCG (geração de código Link-time)](../build/reference/ltcg-link-time-code-generation.md) compilações) ou um único arquivo de origem (não -**/LTCG** criar).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso `__declspec(restrict)` e `__declspec(noalias)`. Normalmente, a memória retornado de `malloc` é `restrict` porque os cabeçalhos de CRT são decorados adequadamente.

No entanto, no exemplo, os ponteiros `mempool` e `memptr` são globais para o compilador não tem nenhuma garantia de que a memória não está sujeita às alias. Decorando as funções que retornam ponteiros com `__declspec(restrict)` dizem ao compilador que a memória apontada pelo valor de retorno não possui alias.

Decorando a função no exemplo que acessa a memória com `__declspec(noalias)` informa o compilador que essa função não interfere no estado global exceto por ponteiros na lista de parâmetros.

```C
// declspec_noalias.c
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

[__declspec](../cpp/declspec.md)  
[Palavras-chave](../cpp/keywords-cpp.md)
