---
title: Algoritmos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- libraries [C++], C++ algorithm conventions
- algorithms [C++], C++
- C++ Standard Library, algorithms
- algorithm template function C++ library conventions
- conventions [C++], C++ algorithm
ms.assetid: dec9b373-7d5c-46cc-b7d2-21a938ecd0a6
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5bc9d57f93b5d3ee537330ab16c2c9a02b6beead
ms.sourcegitcommit: 185e11ab93af56ffc650fe42fb5ccdf1683e3847
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2018
---
# <a name="algorithms"></a>Algoritmos
Os algoritmos são uma parte fundamental da Biblioteca Padrão do C++. Os algoritmos não funcionam com contêineres em si, mas sim com iteradores. Portanto, o mesmo algoritmo pode ser usado pela maioria ou até por todos os contêineres da Biblioteca Padrão do C++. Esta seção discute as convenções e a terminologia dos algoritmos da Biblioteca Padrão do C++.  
  
## <a name="remarks"></a>Comentários  
 As descrições das funções do modelo de algoritmo empregam várias frases abreviadas:  
  
-   A frase "no intervalo [*A*, *B*)" representa a sequência de zero ou mais valores discretos, começando com *A* até *B*, mas não o incluindo. Um intervalo apenas é válido quando *B* pode ser acessado em *A*, quando você pode armazenar *A* em um objeto *N* (*N* = *A*), incrementar o objeto zero ou mais vezes (++*N*) e ter o objeto comparado como igual a *B* após um número finito de incrementos (N == B*).*  
  
-   A frase "cada *N* no intervalo [*A*, *B*)" significa que *N* começa com o valor *A* e é incrementado zero ou mais vezes até se igualar ao valor *B*. O caso *N* == *B* não está no intervalo.  
  
-   A frase "o valor mais baixo de *N* no intervalo [*A*, *B*), de modo que *X*" significa que a condição *X* é determinada para cada *N* no intervalo [*A*, *B*) até que a condição *X* seja atendida.  
  
-   A frase "o maior valor de *N* no intervalo [*A*, *B*), de modo que *X*” significa que *X* é determinado para cada *N* no intervalo [*A*, *B*). A função armazena em `K` uma cópia de *N* sempre que a condição *X* é atendida. Se esse tipo de repositório ocorrer, a função substituirá o valor final de *N*, que é igual a *B*, pelo valor de `K`. No entanto, para um iterador de acesso aleatório ou bidirecional, isso também pode significar que *N* começa com o valor mais alto no intervalo e é decrementado ao longo do intervalo até que a condição *X* seja atendida.  
  
-   Expressões como *X* - *Y*, em que *X* e *Y* podem ser iteradores diferentes dos iteradores de acesso aleatório, são usadas no sentido matemático. A função não avaliará necessariamente o operador **-** se precisar determinar esse valor. O mesmo também vale para expressões como *X* + *N* e *X* - *N*, em que *N* é do tipo inteiro.  
  
 Vários algoritmos usam um predicado que executa uma comparação de pares, como com `operator==`, para produzir um resultado `bool`. A função de predicado `operator==` ou qualquer substituição dela, não deve alterar nenhum de seus operandos. Ela deverá produzir o mesmo resultado `bool` sempre que for avaliada e deverá produzir o mesmo resultado se uma cópia de um dos operandos for substituída pelo operando.  
  
 Vários algoritmos usam um predicado que deve impor uma ordenação fraca estrita aos pares de elementos de uma sequência. Para o predicado `pr`(*X*, *Y*):  
  
-   Estrito significa que `pr`(*X*, *X*) é false.  
  
-   Fraco significa que *X* e *Y* têm uma ordenação equivalente se !`pr`(*X*, *Y*) && !`pr`(*Y*, *X*) (*X* == *Y* não precisa ser definido).  
  
-   Ordenação significa que `pr`(*X*, *Y*) && `pr`(*Y*, Z) implica `pr`(*X*, Z).  
  
 Alguns desses algoritmos usam implicitamente o predicado *X* \< *Y*. Outros predicados que normalmente atendem ao requisito de ordenação fraca estrita são *X* > *Y*, **less**(*X*, *Y*) e `greater`(*X*, *Y*). No entanto, observe que predicados como *X* \<= *Y* e *X* >= *Y* não atendem a esse requisito.  
  
 Uma sequência de elementos designados por iteradores no intervalo [`First`, `Last`) será uma sequência ordenada pelo operador**<** se, para cada *N* no intervalo [0, `Last` - `First`) e para cada *M* no intervalo (N, `Last` - `First`) o predicado !(\*(`First` + *M*) < \*(*First* + *N*)) for true. (Observe que os elementos são classificados em ordem crescente). A função de predicado **operator<** ou qualquer substituição dela, não deve alterar nenhum de seus operandos. Ela deverá produzir o mesmo resultado `bool` sempre que for avaliada e deverá produzir o mesmo resultado se uma cópia de um dos operandos for substituída pelo operando. Além disso, ela deve impor uma ordenação fraca estrita aos operandos que compara.  
  
 Uma sequência de elementos designados por iteradores no intervalo [`First`, `Last`) será um heap ordenado por **operator<** se, para cada *N* no intervalo [1, `Last` - `First`) o predicado !(\*`First` < \*(`First` + *N*)) for true. (O primeiro elemento é o maior). Sua estrutura interna é conhecida apenas para as funções de modelo [make_heap](../standard-library/algorithm-functions.md#make_heap), [pop_heap](../standard-library/algorithm-functions.md#pop_heap), e [push_heap](../standard-library/algorithm-functions.md#push_heap). Assim como acontece com uma sequência ordenada, a função de predicado **operator<** ou qualquer substituição dela, não deve alterar nenhum de seus operandos e deve impor uma ordenação fraca estrita aos operandos que compara. Ela deverá produzir o mesmo resultado `bool` sempre que for avaliada e deverá produzir o mesmo resultado se uma cópia de um dos operandos for substituída pelo operando.  
  
 Os algoritmos da Biblioteca Padrão do C++ estão localizados nos arquivos de cabeçalho [\<algorithm>](../standard-library/algorithm.md) e [\<numeric>](../standard-library/numeric.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

