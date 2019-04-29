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
ms.openlocfilehash: 937c217cdef6895aaa3adb1499f1fde8f67fd513
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62369482"
---
# <a name="regexiterator-class"></a>Classe regex_iterator

Classe de iterador para correspondências.

## <a name="syntax"></a>Sintaxe

```cpp
template<class BidIt,
   class Elem = typename std::iterator_traits<BidIt>::value_type,
   class RxTraits = regex_traits<Elem> >
class regex_iterator
```

## <a name="parameters"></a>Parâmetros

*BidIt*<br/>
O tipo de iterador para subcorrespondências.

*Elem*<br/>
O tipo de elemento a ser correspondido.

*RXtraits*<br/>
Classe de características para elementos.

## <a name="remarks"></a>Comentários

A classe de modelo descreve um objeto de iterador de avanço constante. Ele extrai objetos do tipo `match_results<BidIt>` aplicando repetidamente seu objeto de expressão regular `*pregex` à sequência de caracteres definida pelo intervalo do iterador `[begin, end)`.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[regex_iterator](#regex_iterator)|Constrói o iterador.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[difference_type](#difference_type)|O tipo de uma diferença de iterador.|
|[iterator_category](#iterator_category)|O tipo da categoria do iterador.|
|[pointer](#pointer)|O tipo de um ponteiro para uma correspondência.|
|[reference](#reference)|O tipo de uma referência de uma correspondência.|
|[regex_type](#regex_type)|O tipo da expressão regular de correspondência.|
|[value_type](#value_type)|O tipo de uma correspondência.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator!=](#op_neq)|Compara a desigualdade dos iteradores.|
|[operator*](#op_star)|Acessa a correspondência designada.|
|[operator++](#op_add_add)|Incrementa o iterador.|
|[operator=](#op_eq)|Compara a igualdade dos iteradores.|
|[operator->](#op_arrow)|Acessa a correspondência designada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<regex>

**Namespace:** std

## <a name="examples"></a>Exemplos

Consulte os tópicos a seguir para ver exemplos de expressões regulares:

- [regex_match](../standard-library/regex-functions.md#regex_match)

- [regex_replace](../standard-library/regex-functions.md#regex_replace)

- [regex_search](../standard-library/regex-functions.md#regex_search)

- [swap](../standard-library/regex-functions.md#swap)

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

## <a name="difference_type"></a>  regex_iterator::difference_type

O tipo de uma diferença de iterador.

```cpp
typedef std::ptrdiff_t difference_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `std::ptrdiff_t`.

## <a name="iterator_category"></a>  regex_iterator::iterator_category

O tipo da categoria do iterador.

```cpp
typedef std::forward_iterator_tag iterator_category;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `std::forward_iterator_tag`.

## <a name="op_neq"></a>  regex_iterator::operator!=

Compara a desigualdade dos iteradores.

```cpp
bool operator!=(const regex_iterator& right);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
O iterador a ser comparado.

### <a name="remarks"></a>Comentários

A função membro retorna `!(*this == right)`.

## <a name="op_star"></a>  regex_iterator::operator*

Acessa a correspondência designada.

```cpp
const match_results<BidIt>& operator*();
```

### <a name="remarks"></a>Comentários

A função do membro retorna o valor armazenado `match`.

## <a name="op_add_add"></a>  regex_iterator::operator++

Incrementa o iterador.

```cpp
regex_iterator& operator++();
regex_iterator& operator++(int);
```

### <a name="remarks"></a>Comentários

Se a correspondência atual não tiver nenhum caractere, o primeiro operador chama `regex_search(begin, end, match, *pregex, flags | regex_constants::match_prev_avail | regex_constants::match_not_null)`; caso contrário, ele avança o valor armazenado `begin` para apontar para o primeiro caractere após a correspondência atual e chama `regex_search(begin, end, match, *pregex, flags | regex_constants::match_prev_avail)`. Em ambos os casos, se a pesquisa falhar, o operador define o objeto como um iterador de fim de sequência. O operador retorna o objeto.

O segundo operador faz uma cópia do objeto, incrementa o objeto e retorna a cópia.

## <a name="op_eq"></a>  regex_iterator::operator=

Compara a igualdade dos iteradores.

```cpp
bool operator==(const regex_iterator& right);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
O iterador a ser comparado.

### <a name="remarks"></a>Comentários

A função membro retornará true se `*this` e *direito* são os iteradores de fim de sequência ou se nenhum deles for um iterador de fim de sequência e `begin == right.begin`, `end == right.end`, `pregex == right.pregex`, e `flags == right.flags`. Caso contrário, retorna false.

## <a name="op_arrow"></a>  regex_iterator::operator-&gt;

Acessa a correspondência designada.

```cpp
const match_results<BidIt> * operator->();
```

### <a name="remarks"></a>Comentários

A função membro retorna o endereço do valor armazenado `match`.

## <a name="pointer"></a>  regex_iterator::pointer

O tipo de um ponteiro para uma correspondência.

```cpp
typedef match_results<BidIt> *pointer;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `match_results<BidIt>*`, em que `BidIt` é o parâmetro de modelo.

## <a name="reference"></a>  regex_iterator::reference

O tipo de uma referência de uma correspondência.

```cpp
typedef match_results<BidIt>& reference;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `match_results<BidIt>&`, em que `BidIt` é o parâmetro de modelo.

## <a name="regex_iterator"></a>  regex_iterator::regex_iterator

Constrói o iterador.

```cpp
regex_iterator();

regex_iterator(BidIt first,
    BidIt last,
    const regex_type& re,
    regex_constants::match_flag_type f = regex_constants::match_default);
```

### <a name="parameters"></a>Parâmetros

*first*<br/>
Início da sequência de correspondência.

*last*<br/>
Fim da sequência de correspondência.

*re*<br/>
Expressão regular para correspondências.

*f*<br/>
Sinalizadores de correspondências.

### <a name="remarks"></a>Comentários

O primeiro construtor cria um iterador de fim de sequência. O segundo construtor inicializa o valor armazenado `begin` com *primeiro*, o valor armazenado `end` com *último*, o valor armazenado `pregex` com `&re`e o valor armazenado `flags` com *f*. Depois, chama `regex_search(begin, end, match, *pregex, flags)`. Se a pesquisa falhar, o construtor define o objeto como um iterador de fim de sequência.

## <a name="regex_type"></a>  regex_iterator::regex_type

O tipo da expressão regular de correspondência.

```cpp
typedef basic_regex<Elem, RXtraits> regex_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo de `basic_regex<Elem, RXtraits>`.

## <a name="value_type"></a>  regex_iterator::value_type

O tipo de uma correspondência.

```cpp
typedef match_results<BidIt> value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `match_results<BidIt>`, em que `BidIt` é o parâmetro de modelo.

## <a name="see-also"></a>Consulte também

[\<regex>](../standard-library/regex.md)<br/>
[Classe regex_constants](../standard-library/regex-constants-class.md)<br/>
[Classe regex_error](../standard-library/regex-error-class.md)<br/>
[\<Funções regex>](../standard-library/regex-functions.md)<br/>
[Classe regex_iterator](../standard-library/regex-iterator-class.md)<br/>
[\<Operadores regex>](../standard-library/regex-operators.md)<br/>
[Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)<br/>
[Classe regex_traits](../standard-library/regex-traits-class.md)<br/>
[\<Typedef regex>](../standard-library/regex-typedefs.md)<br/>
