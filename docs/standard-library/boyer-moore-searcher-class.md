---
title: classe boyer_moore_searcher
ms.date: 08/03/2019
f1_keywords:
- functional/std::boyer_moore_searcher
helpviewer_keywords:
- std::boyer_moore_searcher [C++]
ms.openlocfilehash: d6fa4dd203336107614ca3431f38846f0c3c89af
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90039802"
---
# <a name="boyer_moore_searcher-class"></a>classe boyer_moore_searcher

A `boyer_moore_searcher` classe é um tipo de objeto de função que usa o algoritmo Boyer-Moore para pesquisar uma sequência especificada no construtor do objeto. A pesquisa é feita dentro de outra sequência fornecida para o operador de chamada de função do objeto. Essa classe é passada como um parâmetro para uma das sobrecargas de [std:: Search](algorithm-functions.md#search).

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

| Membro | DESCRIÇÃO |
| - | - |
| **Qu** | |
| [boyer_moore_searcher](#boyer-moore-searcher-constructor) | Constrói uma instância de pesquisador. |
| **Operadores** | |
| [operador ()](#operator-call) | Invoca a operação na sequência. |

## <a name="boyer_moore_searcher-constructor"></a><a name="boyer-moore-searcher-constructor"></a> Construtor de boyer_moore_searcher

Constrói um `boyer_moore_searcher` objeto de função usando a sequência para pesquisar, um objeto de função de hash e um predicado de igualdade.

```cpp
boyer_moore_searcher(
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
O predicado de comparação de igualdade opcional para elementos de sequência. Se um tipo de comparação de igualdade não for especificado, o padrão será `std::equal_to` .

### <a name="remarks"></a>Comentários

Gera qualquer exceção gerada pelo construtor de cópia dos tipos *BinaryPredicate*, *hash*ou *RandomAccessIterator* ou o operador de chamada de *BinaryPredicate* ou *hash*.

Essa classe é nova no C++ 17.

## <a name="operator"></a><a name="operator-call"></a> operador ()

O operador de chamada do objeto de função. Pesquisa dentro da sequência `[first, last)` de argumento para a sequência especificada para o construtor.

```cpp
template <class ForwardIterator2>
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

Se o padrão de pesquisa `[pat_first, pat_last)` estiver vazio, o retornará `make_pair(first, first)` . Se o padrão de pesquisa não for encontrado, o retornará `make_pair(last, last)` . Caso contrário, retorna um par de iteradores para o início e o final de uma sequência em `[first, last)` que é igual a de `[pat_first, pat_last)` acordo com o predicado *Pred*.

Essa classe é nova no C++ 17.

## <a name="see-also"></a>Confira também

[\<functional>](functional.md)\
[funções de algoritmo](algorithm-functions.md)\
[classe boyer_moore_horspool_searcher](boyer-moore-horspool-searcher-class.md)\
[std:: Search](algorithm-functions.md#search)
