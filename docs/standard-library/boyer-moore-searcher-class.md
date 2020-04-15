---
title: boyer_moore_searcher turma
ms.date: 08/03/2019
f1_keywords:
- functional/std::boyer_moore_searcher
helpviewer_keywords:
- std::boyer_moore_searcher [C++]
ms.openlocfilehash: 54e5c4b7c9fe27d6df32f56d57eb1207fa09332c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366764"
---
# <a name="boyer_moore_searcher-class"></a>boyer_moore_searcher turma

A `boyer_moore_searcher` classe é um tipo de objeto de função que usa o algoritmo Boyer-Moore para procurar uma seqüência especificada no construtor do objeto. A pesquisa é feita dentro de outra seqüência fornecida ao operador de chamada de função do objeto. Esta classe é passada como um parâmetro para uma das sobrecargas de [std::search](algorithm-functions.md#search).

## <a name="syntax"></a>Sintaxe

```cpp
template <
    class RandomAccessIterator1,
    class Hash = hash<typename iterator_traits<RandomAccessIterator1>::value_type>,
    class BinaryPredicate = equal_to<>>
class boyer_moore_searcher
{
    boyer_moore_searcher(
        RandomAccessIterator1 pat_first,
        RandomAccessIterator1 pat_last,
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
|[boyer_moore_searcher](#boyer-moore-searcher-constructor)||
| **Operadores** | |
| [operador()](#operator-call) | |

## <a name="boyer_moore_searcher-constructor"></a><a name="boyer-moore-searcher-constructor"></a>construtor boyer_moore_searcher

Constrói um `boyer_moore_searcher` objeto de função usando a seqüência para procurar, um objeto de função hash e um predicado de igualdade.

```cpp
boyer_moore_searcher(
    RandomAccessIterator pat_first,
    RandomAccessIterator pat_last,
    Hash hf = Hash(),
    BinaryPredicate pred = BinaryPredicate());
```

### <a name="parameters"></a>Parâmetros

*pat_first*\
O elemento inicial da seqüência para procurar.

*pat_last*\
O fim da sequência para procurar.

*Hf*\
Um objeto caliável, usado para hash os elementos de seqüência.

*Pred*\
O predicado opcional de comparação de igualdade para elementos de seqüência. Se um tipo de comparação de igualdade não `std::equal_to`for especificado, o padrão será .

### <a name="remarks"></a>Comentários

Lança qualquer exceção lançada pelo construtor de cópias dos tipos *BinaryPredicate,* *Hash*ou *RandomAccessIterator,* ou o operador de chamada do *BinaryPredicate* ou *Hash*.

Esta classe é nova em C++17.

## <a name="operator"></a><a name="operator-call"></a>operador()

O operador de chamada do objeto de função. Pesquisa dentro da `[first, last)` seqüência de argumentos para a seqüência especificada para o construtor.

```cpp
template <class ForwardIterator2>
pair<RandomAccessIterator2, RandomAccessIterator2> operator()(
    RandomAccessIterator2 first,
    RandomAccessIterator2 last) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
O elemento inicial da seqüência para procurar dentro.

*Última*\
O fim da seqüência para procurar dentro.

### <a name="remarks"></a>Comentários

Se o `[pat_first, pat_last)` padrão de `make_pair(first, first)`pesquisa estiver vazio, retorna. Se o padrão de pesquisa `make_pair(last, last)`não for encontrado, retorna. Caso contrário, retorna um par de iteradores para o `[first, last)` início e `[pat_first, pat_last)` o fim de uma seqüência em que é igual a de acordo com o predicado *pred*.

Esta classe é nova em C++17.

## <a name="see-also"></a>Confira também

[\<>funcionais](functional.md)\
[funções de algoritmo](algorithm-functions.md)\
[boyer_moore_horspool_searcher turma](boyer-moore-horspool-searcher-class.md)\
[dst::pesquisa](algorithm-functions.md#search)
