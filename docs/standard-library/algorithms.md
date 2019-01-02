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
ms.openlocfilehash: a0a1165d731e44568d530e3ed919d73e2a3e8e5e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50648014"
---
# <a name="algorithms"></a>Algoritmos

Os algoritmos são uma parte fundamental da Biblioteca Padrão do C++. Os algoritmos não funcionam com contêineres em si, mas sim com iteradores. Portanto, o mesmo algoritmo pode ser usado pela maioria ou até por todos os contêineres da Biblioteca Padrão do C++. Esta seção discute as convenções e a terminologia dos algoritmos da Biblioteca Padrão do C++.

## <a name="remarks"></a>Comentários

As descrições das funções do modelo de algoritmo empregam várias frases abreviadas:

- A frase "no intervalo \[ *um*, *B*)" significa que a sequência de zero ou mais valores discretos, começando com o *um* até, mas não incluir *B* . Um intervalo é válido somente se *B* possa ser acessado pela *A;* você pode armazenar *um* em um objeto *N* (*N*  =  *Um*), incrementar o objeto zero ou mais vezes (+ +*N*), e ter o objeto comparados como iguais *B* após um número finito de incrementos (*N*   ==  *B*).

- A frase "cada *N* no intervalo \[ *um*, *B*)" significa que *N* começa com o valor *um*e é incrementado zero ou mais vezes até que ele é igual ao valor *B*. O caso *N* == *B* não está no intervalo.

- A frase "o menor valor de *N* no intervalo \[ *um*, *B*), de modo que *X*" significa que a condição *X* é determinada para cada *N* no intervalo \[ *um*, *B*) até que a condição *X*for atendida.

- A frase "o maior valor de *N* no intervalo \[ *um*, *B*), de modo que *X* significa que *X* é determinado para cada *N* no intervalo \[ *um*, *B*). A função armazena em *K* uma cópia do *N* sempre que a condição *X* for atendida. Se esse tipo de repositório ocorrer, a função substituirá o valor final da *N*, que é igual a *B*, com o valor de *K*. No entanto, para um iterador de acesso aleatório ou bidirecional, isso também pode significar que *N* começa com o valor mais alto no intervalo e é decrementado ao longo do intervalo até que a condição *X* seja atendida.

- Expressões como *X* - *Y*, em que *X* e *Y* podem ser iteradores diferentes dos iteradores de acesso aleatório, são usadas no sentido matemático. A função não avaliará necessariamente o operador **-** se precisar determinar esse valor. O mesmo também vale para expressões como *X* + *N* e *X* - *N*, em que *N* é do tipo inteiro.

Vários algoritmos usam um predicado que executa uma comparação de paridade, como com `operator==`, para produzir uma **bool** resultado. A função de predicado `operator==` ou qualquer substituição dela, não deve alterar nenhum de seus operandos. Ele deverá produzir o mesmo **bool** resultam sempre que ela é avaliada e deverá produzir o mesmo resultado se uma cópia de qualquer um dos operandos for substituída pelo operando.

Vários algoritmos usam um predicado que deve impor uma ordenação fraca estrita aos pares de elementos de uma sequência. Para o predicado *pred*(*X*, *Y*):

- Estrito significa que *pred*(*X*, *X*) é false.

- Fraco significa que *X* e *Y* têm uma ordenação equivalente se \! *pred*(*X*, *Y*) & & \! *pred*(*Y*, *X*) (*X* == *Y*não precisa ser definido).

- Ordenação significa que *pred*(*X*, *Y*) & & *pred*(*Y*, *Z*) implica *pred*(*X*, *Z*).

Alguns desses algoritmos usam implicitamente o predicado *X* \< *Y*. Outros predicados que normalmente satisfazem a requisito de ordenação fraca estrita são *X* > *Y*, `less`(*X*, *Y*), e `greater`(*X*, *Y*). No entanto, observe que predicados como *X* \<= *Y* e *X* >= *Y* não atendem a esse requisito.

Uma sequência de elementos designados por iteradores no intervalo \[ *primeiro*, *último*) é uma sequência ordenada pelo operador **<** se, para cada  *N* no intervalo \[0, *última* - *primeiro*) e para cada *M* no intervalo (*N*, *Última* - *primeiro*) o predicado \!(\*(*primeiro*  +  *M*) < \*(*primeiro* + *N*)) é true. (Observe que os elementos são classificados em ordem crescente). A função de predicado `operator<` ou qualquer substituição dela, não deve alterar nenhum de seus operandos. Ele deverá produzir o mesmo **bool** resultam sempre que ela é avaliada e deverá produzir o mesmo resultado se uma cópia de qualquer um dos operandos for substituída pelo operando. Além disso, ela deve impor uma ordenação fraca estrita aos operandos que compara.

Uma sequência de elementos designados por iteradores no intervalo \[ `First`, `Last`) é um heap ordenado por `operator<` se, para cada *N* no intervalo \[1, *daúltima*  -  *Primeiro*) o predicado \!(\*_primeiro_ < \*(*primeiro*  +  *N*)) é true. (O primeiro elemento é o maior). Sua estrutura interna é conhecida apenas para as funções de modelo [make_heap](../standard-library/algorithm-functions.md#make_heap), [pop_heap](../standard-library/algorithm-functions.md#pop_heap), e [push_heap](../standard-library/algorithm-functions.md#push_heap). Assim como acontece com uma sequência ordenada, a função de predicado `operator<`, ou qualquer substituição dela, não deve alterar nenhum de seus operandos e deve impor uma ordenação fraca estrita aos operandos que compara. Ele deverá produzir o mesmo **bool** resultam sempre que ela é avaliada e deverá produzir o mesmo resultado se uma cópia de qualquer um dos operandos for substituída pelo operando.

Os algoritmos da Biblioteca Padrão do C++ estão localizados nos arquivos de cabeçalho [\<algorithm>](../standard-library/algorithm.md) e [\<numeric>](../standard-library/numeric.md).

## <a name="see-also"></a>Consulte também

[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
