---
title: Classe regex_iterator
ms.date: 09/10/2018
f1_keywords:
- regex/std::regex_iterator
- regex/std::regex_iterator::operator==
- regex/std::regex_iterator::operator!=
- regex/std::regex_iterator::operator*
- regex/std::regex_iterator::operator->
- regex/std::regex_iterator::operator++
helpviewer_keywords:
- std::regex_iterator
- std::regex_iterator::operator==
- std::regex_iterator::operator!=
- std::regex_iterator::operator*
- std::regex_iterator::operator->
- std::regex_iterator::operator++
ms.assetid: 0cfd8fd0-5a95-4f3c-bf8e-6ef028c423d3
ms.openlocfilehash: d9d2baf99b1e2334132f54aeace3d8197b1e73da
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217578"
---
# <a name="regex_iterator-class"></a>Classe regex_iterator

Classe de iterador para correspondências.

## <a name="syntax"></a>Sintaxe

```cpp
template<class BidIt,
   class Elem = typename std::iterator_traits<BidIt>::value_type,
   class RxTraits = regex_traits<Elem> >
class regex_iterator
```

## <a name="parameters"></a>parâmetros

*Bidirecional*\
O tipo de iterador para subcorrespondências.

*Elem*\
O tipo de elemento a ser correspondido.

*RXtraits*\
Classe de características para elementos.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto iterador de encaminhamento constante. Ele extrai objetos do tipo `match_results<BidIt>` aplicando repetidamente seu objeto de expressão regular `*pregex` à sequência de caracteres definida pelo intervalo do iterador `[begin, end)`.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[regex_iterator](#regex_iterator)|Constrói o iterador.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[difference_type](#difference_type)|O tipo de uma diferença de iterador.|
|[iterator_category](#iterator_category)|O tipo da categoria do iterador.|
|[refere](#pointer)|O tipo de um ponteiro para uma correspondência.|
|[reference](#reference)|O tipo de uma referência de uma correspondência.|
|[regex_type](#regex_type)|O tipo da expressão regular de correspondência.|
|[value_type](#value_type)|O tipo de uma correspondência.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador! =](#op_neq)|Compara a desigualdade dos iteradores.|
|[operador](#op_star)|Acessa a correspondência designada.|
|[operador + +](#op_add_add)|Incrementa o iterador.|
|[operador =](#op_eq)|Compara a igualdade dos iteradores.|
|[operador->](#op_arrow)|Acessa a correspondência designada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<regex>

**Namespace:** std

## <a name="examples"></a>Exemplos

Consulte os tópicos a seguir para ver exemplos de expressões regulares:

- [regex_match](../standard-library/regex-functions.md#regex_match)

- [regex_replace](../standard-library/regex-functions.md#regex_replace)

- [regex_search](../standard-library/regex-functions.md#regex_search)

- [permuta](../standard-library/regex-functions.md#swap)

```cpp
// std__regex__regex_iterator.cpp
// compile with: /EHsc
#include <regex>
#include <iostream>

typedef std::regex_iterator<const char *> Myiter;
int main()
    {
    const char *pat = "axayaz";
    Myiter::regex_type rx("a");
    Myiter next(pat, pat + strlen(pat), rx);
    Myiter end;

    for (; next != end; ++next)
        std::cout << "match == " << next->str() << std::endl;

// other members
    Myiter it1(pat, pat + strlen(pat), rx);
    Myiter it2(it1);
    next = it1;

    Myiter::iterator_category cat = std::forward_iterator_tag();
    Myiter::difference_type dif = -3;
    Myiter::value_type mr = *it1;
    Myiter::reference ref = mr;
    Myiter::pointer ptr = &ref;

    dif = dif; // to quiet "unused" warnings
    ptr = ptr;

    return (0);
    }
```

```Output
match == a
match == a
match == a
```

## <a name="regex_iteratordifference_type"></a><a name="difference_type"></a>regex_iterator::d ifference_type

O tipo de uma diferença de iterador.

```cpp
typedef std::ptrdiff_t difference_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `std::ptrdiff_t`.

## <a name="regex_iteratoriterator_category"></a><a name="iterator_category"></a>regex_iterator:: iterator_category

O tipo da categoria do iterador.

```cpp
typedef std::forward_iterator_tag iterator_category;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `std::forward_iterator_tag`.

## <a name="regex_iteratoroperator"></a><a name="op_neq"></a>regex_iterator:: Operator! =

Compara a desigualdade dos iteradores.

```cpp
bool operator!=(const regex_iterator& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O iterador a ser comparado.

### <a name="remarks"></a>Comentários

A função membro retorna `!(*this == right)`.

## <a name="regex_iteratoroperator"></a><a name="op_star"></a>regex_iterator:: Operator *

Acessa a correspondência designada.

```cpp
const match_results<BidIt>& operator*();
```

### <a name="remarks"></a>Comentários

A função do membro retorna o valor armazenado `match`.

## <a name="regex_iteratoroperator"></a><a name="op_add_add"></a>regex_iterator:: operador + +

Incrementa o iterador.

```cpp
regex_iterator& operator++();
regex_iterator& operator++(int);
```

### <a name="remarks"></a>Comentários

Se a correspondência atual não tiver nenhum caractere, o primeiro operador chama `regex_search(begin, end, match, *pregex, flags | regex_constants::match_prev_avail | regex_constants::match_not_null)`; caso contrário, ele avança o valor armazenado `begin` para apontar para o primeiro caractere após a correspondência atual e chama `regex_search(begin, end, match, *pregex, flags | regex_constants::match_prev_avail)`. Em ambos os casos, se a pesquisa falhar, o operador define o objeto como um iterador de fim de sequência. O operador retorna o objeto.

O segundo operador faz uma cópia do objeto, incrementa o objeto e retorna a cópia.

## <a name="regex_iteratoroperator"></a><a name="op_eq"></a>regex_iterator:: Operator =

Compara a igualdade dos iteradores.

```cpp
bool operator==(const regex_iterator& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O iterador a ser comparado.

### <a name="remarks"></a>Comentários

A função membro retornará verdadeiro se **`*this`** e *direita* forem iteradores de fim de sequência ou se nenhum for um iterador de fim de sequência e,, `begin == right.begin` `end == right.end` `pregex == right.pregex` e `flags == right.flags` . Caso contrário, retorna false.

## <a name="regex_iteratoroperator-gt"></a><a name="op_arrow"></a>operador regex_iterator::&gt;

Acessa a correspondência designada.

```cpp
const match_results<BidIt> * operator->();
```

### <a name="remarks"></a>Comentários

A função membro retorna o endereço do valor armazenado `match`.

## <a name="regex_iteratorpointer"></a><a name="pointer"></a>regex_iterator::p ointer

O tipo de um ponteiro para uma correspondência.

```cpp
typedef match_results<BidIt> *pointer;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `match_results<BidIt>*`, em que `BidIt` é o parâmetro de modelo.

## <a name="regex_iteratorreference"></a><a name="reference"></a>regex_iterator:: referência

O tipo de uma referência de uma correspondência.

```cpp
typedef match_results<BidIt>& reference;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `match_results<BidIt>&`, em que `BidIt` é o parâmetro de modelo.

## <a name="regex_iteratorregex_iterator"></a><a name="regex_iterator"></a>regex_iterator:: regex_iterator

Constrói o iterador.

```cpp
regex_iterator();

regex_iterator(BidIt first,
    BidIt last,
    const regex_type& re,
    regex_constants::match_flag_type f = regex_constants::match_default);
```

### <a name="parameters"></a>parâmetros

*primeiro*\
Início da sequência de correspondência.

*última*\
Fim da sequência de correspondência.

*outra*\
Expressão regular para correspondências.

*fixo*\
Sinalizadores de correspondências.

### <a name="remarks"></a>Comentários

O primeiro construtor cria um iterador de fim de sequência. O segundo construtor inicializa o valor armazenado `begin` com *primeiro*, o valor armazenado `end` com *Last*, o valor armazenado `pregex` com `&re` e o valor armazenado `flags` com *f*. Depois, chama `regex_search(begin, end, match, *pregex, flags)`. Se a pesquisa falhar, o construtor define o objeto como um iterador de fim de sequência.

## <a name="regex_iteratorregex_type"></a><a name="regex_type"></a>regex_iterator:: regex_type

O tipo da expressão regular de correspondência.

```cpp
typedef basic_regex<Elem, RXtraits> regex_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo de `basic_regex<Elem, RXtraits>`.

## <a name="regex_iteratorvalue_type"></a><a name="value_type"></a>regex_iterator:: value_type

O tipo de uma correspondência.

```cpp
typedef match_results<BidIt> value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `match_results<BidIt>`, em que `BidIt` é o parâmetro de modelo.

## <a name="see-also"></a>Confira também

[\<regex>](../standard-library/regex.md)\
[Classe regex_constants](../standard-library/regex-constants-class.md)\
[Classe regex_error](../standard-library/regex-error-class.md)\
[\<regex>funções](../standard-library/regex-functions.md)\
[Classe regex_iterator](../standard-library/regex-iterator-class.md)\
[\<regex>operações](../standard-library/regex-operators.md)\
[Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)\
[Classe regex_traits](../standard-library/regex-traits-class.md)\
[\<regex>TYPEDEFs](../standard-library/regex-typedefs.md)
