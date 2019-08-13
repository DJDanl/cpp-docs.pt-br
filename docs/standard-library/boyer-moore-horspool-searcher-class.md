---
title: classe boyer_moore_horspool_searcher
ms.date: 08/03/2019
f1_keywords:
- functional/std::boyer_moore_horspool_searcher
helpviewer_keywords:
- std::boyer_moore_horspool_searcher [C++]
ms.openlocfilehash: c7d24fee4a47fc588b00e527594682f1c4aadf76
ms.sourcegitcommit: 16c0392fc8d96e814c3a40b0c5346d7389aeb525
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/12/2019
ms.locfileid: "68957169"
---
# <a name="boyer_moore_horspool_searcher-class"></a>classe boyer_moore_horspool_searcher

A `boyer_moore_horspool_searcher` classe é um tipo de objeto de função que usa o algoritmo Boyer-Moore-Horspool para pesquisar uma sequência especificada no construtor do objeto. A pesquisa é feita dentro de outra sequência fornecida para o operador de chamada de função do objeto. Essa classe é passada como um parâmetro para uma das sobrecargas de [std:: Search](algorithm-functions.md#search).

## <a name="syntax"></a>Sintaxe

```cpp
template <
    class RandomAccessIterator,
    class Hash = hash<typename iterator_traits<RandomAccessIterator>::value_type>,
    class BinaryPredicate = equal_to<>>
class boyer_moore_horspool_searcher
{
    boyer_moore_horspool_searcher(
        RandomAccessIterator pat_first,
        RandomAccessIterator pat_last,
        Hash hf = Hash(),
        BinaryPredicate pred = BinaryPredicate());

    template <class RandomAccessIterator2>
    pair<RandomAccessIterator2, RandomAccessIterator2> operator()(
        RandomAccessIterator2 first,
        RandomAccessIterator2 last) const;
};
```

## <a name="members"></a>Membros

| | |
| - | - |
| **Construtor** | |
| [boyer_moore_horspool_searcher](#boyer-moore-horspool-searcher-constructor) | |
| **Operadores** | |
| [operator()](#operator-call) | |

## <a name="boyer-moore-horspool-searcher-constructor"></a>Construtor boyer_moore_horspool_searcher

Constrói um `boyer_moore_horspool_searcher` objeto de função usando a sequência para pesquisar, um objeto de função de hash e um predicado de igualdade.

```cpp
boyer_moore_horspool_searcher(
    RandomAccessIterator pat_first,
    RandomAccessIterator pat_last,
    Hash hf = Hash(),
    BinaryPredicate pred = BinaryPredicate());
```

### <a name="parameters"></a>Parâmetros

*pat_first*\
O elemento inicial da sequência a ser pesquisada.

*pat_last*\
O fim da sequência a ser pesquisada.

*HF*\
Um objeto que possa ser chamado, usado para aplicar o hash aos elementos de sequência.

*Pred*\
O predicado de comparação de igualdade opcional para elementos de sequência. Se um tipo de comparação de igualdade não for especificado, `std::equal_to`o padrão será.

### <a name="remarks"></a>Comentários

Gera qualquer exceção gerada pelo construtor de cópia dos tipos *BinaryPredicate*, *hash*ou *RandomAccessIterator* ou o operador de chamada de *BinaryPredicate* ou *hash*.

Essa classe é nova no C++ 17.

## <a name="operator-call"></a>operador ()

O operador de chamada do objeto de função. Pesquisa dentro da sequência `[first, last)` de argumento para a sequência especificada para o construtor.

```cpp
template <class ForwardIterator2>   // C++17
pair<RandomAccessIterator2, RandomAccessIterator2> operator()(
    RandomAccessIterator2 first,
    RandomAccessIterator2 last) const;
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
O elemento inicial da sequência na qual Pesquisar.

*última*\
O fim da sequência na qual Pesquisar.

### <a name="remarks"></a>Comentários

Se o padrão `[pat_first, pat_last)` de pesquisa estiver vazio, `make_pair(first, first)`o retornará. Se o padrão de pesquisa não for encontrado `make_pair(last, last)`, o retornará. Caso contrário, retorna um par de iteradores para o início e o final de uma `[first, last)` sequência em que é `[pat_first, pat_last)` igual a de acordo com o predicado *Pred*.

Essa classe é nova no C++ 17.

## <a name="see-also"></a>Consulte também

[\<functional>](functional.md)\
[funções de algoritmo](algorithm-functions.md)\
[classe boyer_moore_searcher](boyer-moore-searcher-class.md)\
[std:: Search](algorithm-functions.md#search)
