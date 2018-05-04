---
title: restringir | Microsoft Docs
ms.custom: ''
ms.date: 02/09/2018
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- restrict_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], restrict
- restrict __declspec keyword
ms.assetid: f39cf632-68d8-4362-a497-2d4c15693689
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ed5f91288671eaa3dcf4700ec35dae63ffaef172
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="restrict"></a>restrict

**Seção específica da Microsoft**

Quando aplicado a uma declaração de função ou a definição que retorna um tipo de ponteiro, `restrict` informa ao compilador que a função retorna um objeto que não seja *alias*, ou seja, referenciada por quaisquer outros ponteiros. Isso permite que o compilador executar otimizações adicionais.

## <a name="syntax"></a>Sintaxe

> **__declspec(restrict)** *pointer_return_type* *function*();  
  
## <a name="remarks"></a>Comentários

Propaga o compilador `__declspec(restrict)`. Por exemplo, CRT `malloc` função tem um `__declspec(restrict)` decoração e, portanto, o compilador pressupõe que os ponteiros inicializada para locais de memória por `malloc` também não são um alias por previamente existente ponteiros.

O compilador não verifica se o ponteiro retornado não é realmente um alias. É responsabilidade do desenvolvedor assegurar que o programa não coloque alias em um ponteiro com o modificador `restrict __declspec`.  
  
Para uma semântica semelhante em variáveis, consulte [Restrict](../cpp/extension-restrict.md).
 
Para outra anotação que se aplica ao alias dentro de uma função, consulte [__declspec(noalias)](../cpp/noalias.md).
  
Para obter informações sobre o **restringir** palavra-chave que faz parte do C++ AMP, consulte [restrita (C++ AMP)](../cpp/restrict-cpp-amp.md).  
 
## <a name="example"></a>Exemplo  

O exemplo a seguir demonstra o uso de `__declspec(restrict)`.

Quando `__declspec(restrict)` é aplicado a uma função que retorna um ponteiro, isso informa ao compilador que a memória que aponta para o valor de retorno não é um alias. Neste exemplo, os ponteiros `mempool` e `memptr` são globais, portanto, o compilador não pode ter certeza de que a memória que se refiram a não é um alias. No entanto, elas são usadas no `ma` e seu chamador `init` de forma que retorna a memória caso contrário não é referenciada pelo programa, portanto `__decslpec(restrict)` é usado para ajudar o otimizador. Isso é semelhante a como os cabeçalhos do CRT decoram funções de alocação como `malloc` usando `__declspec(restrict)` para indicar que elas sempre retornarem a memória que não pode ser um alias por ponteiros existentes.

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

[Palavras-chave](../cpp/keywords-cpp.md)  
[__declspec](../cpp/declspec.md)  
[__declspec(noalias)](../cpp/noalias.md)  
