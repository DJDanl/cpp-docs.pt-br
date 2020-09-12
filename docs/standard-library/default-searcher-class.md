---
title: classe default_searcher
ms.date: 08/03/2019
f1_keywords:
- functional/std::default_searcher
helpviewer_keywords:
- std::default_searcher [C++]
ms.openlocfilehash: 307fc6da3b383690e0b65bff2a72f386a37d6711
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90039684"
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

| Membro | DESCRIÇÃO |
| - | - |
| **Qu** | |
| [default_searcher](#default-searcher-constructor) | Constrói uma instância de pesquisador. |
| **Operadores** | |
| [operador ()](#operator-call) | Invoca a operação na sequência. |

## <a name="default_searcher-constructor"></a><a name="default-searcher-constructor"></a> Construtor de default_searcher

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
O predicado de comparação de igualdade opcional para elementos de sequência. Se um tipo de comparação de igualdade não for especificado, o padrão será `std::equal_to` .

### <a name="remarks"></a>Comentários

Gera qualquer exceção gerada pelo construtor de cópia dos tipos *BinaryPredicate* ou *ForwardIterator* .

Essa classe é nova no C++ 17. O c++ 20 fez o construtor **`constexpr`** .

## <a name="operator"></a><a name="operator-call"></a> operador ()

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

Retorna um par de iteradores. O *iterador* inicial é o resultado efetivo de:

`std::search( first, last, pat_first, pat_last, pred )`.

O segundo iterador do par será o *último* se *i** for o *último*. Caso contrário, é o resultado efetivo de:

`std::next( i, std::distance( pat_first, pat_last ))`.

Essa classe é nova no C++ 17. O c++ 20 fez o operador Call **`constexpr`** .

## <a name="see-also"></a>Confira também

[\<functional>](functional.md)\
[funções de algoritmo](algorithm-functions.md)\
[std:: Search](algorithm-functions.md#search)
