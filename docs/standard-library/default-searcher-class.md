---
title: classe default_searcher
ms.date: 08/03/2019
f1_keywords:
- functional/std::default_searcher
helpviewer_keywords:
- std::default_searcher [C++]
ms.openlocfilehash: f2b1fe83b5223bbb60e9e32149c101e6379f93c3
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2019
ms.locfileid: "68268818"
---
# <a name="default_searcher-class"></a>Classe default_searcher

Um `default_searcher` é um tipo de objeto de função para operações que pesquisam uma sequência especificada no construtor do objeto. A pesquisa é feita dentro de outra sequência fornecida para o operador de chamada de função do objeto. O `default_searcher` invoca o [std:: Search](algorithm-functions.md#search) para executar a pesquisa.

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
| [operator()](#operator-call) | |

## <a name="default-searcher-constructor"></a>Construtor default_searcher

Constrói um `default_searcher` objeto de função usando a sequência para pesquisar e um predicado de igualdade.

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
O elemento inicial da sequência a ser pesquisada.

*pat_last*\
O fim da sequência a ser pesquisada.

*Pred*\
O predicado de comparação de igualdade opcional para elementos de sequência. Se um tipo de comparação de igualdade não for especificado, `std::equal_to`o padrão será.

### <a name="remarks"></a>Comentários

Gera qualquer exceção gerada pelo construtor de cópia dos tipos *BinaryPredicate* ou *ForwardIterator* .

Essa classe é nova no C++ 17. O c++ 20 fez o `constexpr`Construtor.

## <a name="operator-call"></a>operador ()

O operador de chamada do operador de função. Pesquisa dentro da sequência `[first, last)` de argumento para a sequência especificada para o construtor.

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

*primeiro*\
O elemento inicial da sequência na qual Pesquisar.

*última*\
O fim da sequência na qual Pesquisar.

### <a name="remarks"></a>Comentários

Retorna um par de iteradores. O iterador inicial é o resultado efetivo de:

`std::search( first, last, pat_first, pat_last, pred )`.

O segundo iterador do par será o *último* se *i** for o *último*. Caso contrário, é o resultado efetivo de:

`std::next( i, std::distance( pat_first, pat_last ))`.

Essa classe é nova no C++ 17. O c++ 20 fez o operador `constexpr`Call.

## <a name="see-also"></a>Consulte também

[\<functional>](functional.md)\
[funções de algoritmo](algorithm-functions.md)\
[std:: Search](algorithm-functions.md#search)
