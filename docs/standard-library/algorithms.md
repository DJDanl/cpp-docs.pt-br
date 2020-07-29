---
title: Algoritmos
ms.date: 10/18/2018
helpviewer_keywords:
- libraries [C++], C++ algorithm conventions
- algorithms [C++], C++
- C++ Standard Library, algorithms
- algorithm template function C++ library conventions
- conventions [C++], C++ algorithm
ms.assetid: dec9b373-7d5c-46cc-b7d2-21a938ecd0a6
ms.openlocfilehash: 6532cb56bb70c82525a13ba53efdd6203ebafb12
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87205217"
---
# <a name="algorithms"></a>Algoritmos

Os algoritmos são uma parte fundamental da Biblioteca Padrão do C++. Os algoritmos não funcionam com contêineres em si, mas sim com iteradores. Portanto, o mesmo algoritmo pode ser usado pela maioria ou até por todos os contêineres da Biblioteca Padrão do C++. Esta seção discute as convenções e a terminologia dos algoritmos da Biblioteca Padrão do C++.

## <a name="remarks"></a>Comentários

As descrições das funções do modelo de algoritmo empregam várias frases abreviadas:

- A frase "no intervalo \[ *a*, *B*)" significa a sequência de zero ou mais valores discretos que começam com *um* até, mas não incluindo *B*. Um intervalo é válido somente se *B* estiver acessível a partir de *A;* você pode armazenar *um* em um objeto *N* (*n*  =  *A*), incrementar o objeto zero ou mais vezes (+ +*N*) e fazer com que o objeto seja comparado igual a *B* após um número finito de incrementos (*N*  ==  *B*).

- A frase "cada *N* no intervalo a \[ *A*, *B*)" significa que *N* começa com o valor *a* e é incrementado zero ou mais vezes até que seja igual ao valor *B*. O caso *N*  ==  *B* não está no intervalo.

- A frase "o menor valor de *N* no intervalo \[ *a*, *b*) de modo que *x*" significa que a condição *x* é determinada para cada *N* no intervalo \[ *a*, *b*) até que a condição *x* seja atendida.

- A frase "o valor mais alto de *N* no intervalo \[ *a*, *b*) de modo que *x* significa que *x* é determinado para cada *N* no intervalo a \[ *A*, *b*). A função armazena em *K* uma cópia de *N* toda vez que a condição *X* é atendida. Se qualquer repositório desse tipo ocorrer, a função substituirá o valor final de *N*, que é igual a *B*, com o valor de *K*. No entanto, para um iterador bidirecional ou de acesso aleatório, também pode significar que *N* começa com o valor mais alto no intervalo e é decrementado sobre o intervalo até que a condição *X* seja atendida.

- Expressões como *x*  -  *Y*, em que *x* e *Y* podem ser iteradores diferentes de iteradores de acesso aleatório, destinam-se ao sentido matemático. A função não necessariamente avalia o operador **-** se ele precisar determinar esse valor. O mesmo também é verdadeiro para expressões como *x*  +  *n* e *x*  -  *n*, em que *N* é um tipo inteiro.

Vários algoritmos usam um predicado que executa uma comparação emparelhada, como com `operator==` , para gerar um **`bool`** resultado. A função de predicado `operator==` ou qualquer substituição dela, não deve alterar nenhum de seus operandos. Ele deve produzir o mesmo **`bool`** resultado toda vez que for avaliado e deverá produzir o mesmo resultado se uma cópia de um dos operandos for substituída pelo operando.

Vários algoritmos usam um predicado que deve impor uma ordenação fraca estrita aos pares de elementos de uma sequência. Para o predicado *Pred*(*X*, *Y*):

- Estrito significa que *Pred*(*x*, *x*) é false.

- Fraco significa que *X* e *y* têm uma ordenação equivalente se \! *Pred*(*x*, *Y*)  && \! *Pred*(*y* *x*) (*x*  ==  *y* não precisa ser definido).

- A ordenação significa que *Pred*(*x*, *Y*)  && *Pred*(*Y*, *z*) implica *Pred*(*x*, *z*).

Alguns desses algoritmos usam implicitamente o predicado *X* \< *Y*. Other predicates that typically satisfy the strict weak ordering requirement are *X* > *Y*, `less` (*x*, *Y*) e `greater` (*x*, *y*). No entanto, observe que predicados como *X* \<= *Y* and *X* > =  *Y* não atendem a esse requisito.

Uma sequência de elementos designados por iteradores no intervalo \[ *primeiro*, *último*) é uma sequência ordenada por operador **<** se, para cada *N* no intervalo \[ 0, o *último*  -  *primeiro*) e para cada *M* no intervalo (*N*, o *último*  -  *primeiro*), o predicado \! ( \* (*primeiro*  +  *M*) < \* (*primeiras*  +  *N*)) é true. (Observe que os elementos são classificados em ordem crescente.) A função de predicado `operator<` , ou qualquer substituição para ela, não deve alterar qualquer um de seus operandos. Ele deve produzir o mesmo **`bool`** resultado toda vez que for avaliado e deverá produzir o mesmo resultado se uma cópia de um dos operandos for substituída pelo operando. Além disso, ela deve impor uma ordenação fraca estrita aos operandos que compara.

Uma sequência de elementos designados por iteradores no intervalo \[ `First` , `Last` ) é um heap ordenado por `operator<` If, para cada *N* no intervalo \[ 1, *último*  -  *primeiro*) o predicado \! ( \* _primeiro_  <  \* (*primeiro*  +  *N*)) é true. (O primeiro elemento é o maior.) Sua estrutura interna, de outra forma, é conhecida apenas pelas funções de modelo [make_heap](algorithm-functions.md#make_heap), [pop_heap](algorithm-functions.md#pop_heap)e [push_heap](algorithm-functions.md#push_heap). Assim como com uma sequência ordenada, a função de predicado `operator<` ou qualquer substituição para ela, não deve alterar qualquer um de seus operandos e deve impor uma ordenação fraca estrita nos operandos que ele compara. Ele deve produzir o mesmo **`bool`** resultado toda vez que for avaliado e deverá produzir o mesmo resultado se uma cópia de um dos operandos for substituída pelo operando.

Os algoritmos de biblioteca padrão do C++ estão localizados nos [\<algorithm>](algorithm.md) [\<numeric>](numeric.md) arquivos de cabeçalho e.

## <a name="see-also"></a>Confira também

[Referência da biblioteca padrão do C++](cpp-standard-library-reference.md)\
[Segurança de thread na biblioteca padrão C++](thread-safety-in-the-cpp-standard-library.md)
