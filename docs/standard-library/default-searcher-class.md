---
title: default_searcher turma
ms.date: 08/03/2019
f1_keywords:
- functional/std::default_searcher
helpviewer_keywords:
- std::default_searcher [C++]
ms.openlocfilehash: 2c8b93b83b271f787c993f789e1a68f84a60f016
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368919"
---
# <a name="default_searcher-class"></a>classe default_searcher

A `default_searcher` é um tipo de objeto de função para operações que buscam uma seqüência especificada no construtor do objeto. A pesquisa é feita dentro de outra seqüência fornecida ao operador de chamada de função do objeto. O `default_searcher` invokes [std::search](algorithm-functions.md#search) para realizar a pesquisa.

## <a name="syntax"></a>Sintaxe

```cpp
template <class ForwardIterator, class BinaryPredicate = equal_to<>>
class default_searcher
{
    default_searcher(
        ForwardIterator pat_first,
        ForwardIterator pat_last,
        BinaryPredicate pred = BinaryPredicate());

    template <class ForwardIterator2>
    pair<ForwardIterator2, ForwardIterator2> operator()(
        ForwardIterator2 first,
        ForwardIterator2 last) const;
};
```

## <a name="members"></a>Membros

| | |
| - | - |
| **Construtor** | |
| [default_searcher](#default-searcher-constructor) | |
| **Operadores** | |
| [operador()](#operator-call) | |

## <a name="default_searcher-constructor"></a><a name="default-searcher-constructor"></a>construtor default_searcher

Constrói um `default_searcher` objeto de função usando a seqüência para procurar e um predicado de igualdade.

```cpp
default_searcher(                   // C++17
    ForwardIterator pat_first,
    ForwardIterator pat_last,
    BinaryPredicate pred = BinaryPredicate());

constexpr default_searcher(         // C++20
    ForwardIterator pat_first,
    ForwardIterator pat_last,
    BinaryPredicate pred = BinaryPredicate());
```

### <a name="parameters"></a>Parâmetros

*pat_first*\
O elemento inicial da seqüência para procurar.

*pat_last*\
O fim da sequência para procurar.

*Pred*\
O predicado opcional de comparação de igualdade para elementos de seqüência. Se um tipo de comparação de igualdade não `std::equal_to`for especificado, o padrão será .

### <a name="remarks"></a>Comentários

Lança qualquer exceção lançada pelo construtor de cópias dos tipos *BinaryPredicate* ou *ForwardIterator.*

Esta classe é nova em C++17. C++20 fez o `constexpr`construtor .

## <a name="operator"></a><a name="operator-call"></a>operador()

O operador de chamada do operador de função. Pesquisa dentro da `[first, last)` seqüência de argumentos para a seqüência especificada para o construtor.

```cpp
template <class ForwardIterator2>   // C++17
pair<ForwardIterator2, ForwardIterator2> operator()(
    ForwardIterator2 first,
    ForwardIterator2 last) const;

template <class ForwardIterator2>   // C++20
constexpr pair<ForwardIterator2, ForwardIterator2> operator()(
    ForwardIterator2 first,
    ForwardIterator2 last) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
O elemento inicial da seqüência para procurar dentro.

*Última*\
O fim da seqüência para procurar dentro.

### <a name="remarks"></a>Comentários

Retorna um par de iteradores. O iterator inicial *i* é o resultado efetivo de:

`std::search( first, last, pat_first, pat_last, pred )`.

O segundo tempo do par é o *último* se *eu** for *o último*. Caso contrário, é o resultado efetivo de:

`std::next( i, std::distance( pat_first, pat_last ))`.

Esta classe é nova em C++17. C++20 fez o `constexpr`operador de chamada .

## <a name="see-also"></a>Confira também

[\<>funcionais](functional.md)\
[funções de algoritmo](algorithm-functions.md)\
[dst::pesquisa](algorithm-functions.md#search)
