---
title: Classe regex_token_iterator
ms.date: 09/10/2018
f1_keywords:
- regex/std::regex_token_iterator
- regex/std::regex_token_iterator::regex_type
- regex/std::regex_token_iterator::value_type
- regex/std::regex_token_iterator::iterator_category
- regex/std::regex_token_iterator::difference_type
- regex/std::regex_token_iterator::pointer
- regex/std::regex_token_iterator::reference
- regex/std::regex_token_iterator::operator==
- regex/std::regex_token_iterator::operator!=
- regex/std::regex_token_iterator::operator*
- regex/std::regex_token_iterator::operator->
- regex/std::regex_token_iterator::operator++
helpviewer_keywords:
- std::regex_token_iterator [C++]
- std::regex_token_iterator [C++], regex_type
- std::regex_token_iterator [C++], value_type
- std::regex_token_iterator [C++], iterator_category
- std::regex_token_iterator [C++], difference_type
- std::regex_token_iterator [C++], pointer
- std::regex_token_iterator [C++], reference
ms.assetid: a213ba48-8e4e-4b6b-871a-2637acf05f15
ms.openlocfilehash: 57fac1d9d5c73c2644a679402809933290dd3fc3
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689066"
---
# <a name="regex_token_iterator-class"></a>Classe regex_token_iterator

Classe de iterador para subcorrespondências.

## <a name="syntax"></a>Sintaxe

```cpp
template<class BidIt,
   class Elem = typename std::iterator_traits<BidIt>::value_type,
   class RxTraits = regex_traits<Elem> >
class regex_token_iterator
```

## <a name="parameters"></a>Parâmetros

@No__t_1 *bidirecional*
O tipo de iterador para subcorrespondências.

@No__t_1 *elem*
O tipo de elemento a ser correspondido.

@No__t_1 *RXtraits*
Classe de características para elementos.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto iterador de encaminhamento constante. Conceitualmente, ela mantém um objeto `regex_iterator` que utiliza para pesquisar correspondências de expressão regular em uma sequência de caracteres. Ela extrai objetos do tipo `sub_match<BidIt>` representando as subcorrespondências identificadas pelos valores de índice no vetor armazenado `subs` para cada correspondência de expressão regular.

Um valor de -1 designa a sequência de caracteres que começa imediatamente após o fim da correspondência de expressão regular anterior ou que começa no início da sequência de caracteres, se não houver nenhuma correspondência de expressão regular anterior e estendendo-se a, sem incluir, o primeiro caractere da correspondência da expressão regular ou até o fim da sequência de caracteres se não houver nenhuma correspondência atual. Qualquer outro valor de índice `idx` designa o conteúdo do grupo de captura mantido em `it.match[idx]`.

### <a name="members"></a>Membros

|Membro|Valor padrão|
|-|-|
|`private regex_iterator<BidIt, Elem, RXtraits> it`||
|`private vector<int> subs`||
|`private int pos`||

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[regex_token_iterator](#regex_token_iterator)|Constrói o iterador.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[difference_type](#difference_type)|O tipo de uma diferença de iterador.|
|[iterator_category](#iterator_category)|O tipo da categoria do iterador.|
|[pointer](#pointer)|O tipo de um ponteiro para uma correspondência.|
|[reference](#reference)|O tipo de uma referência de uma subcorrespondência.|
|[regex_type](#regex_type)|O tipo da expressão regular de correspondência.|
|[value_type](#value_type)|O tipo de uma subcorrespondência.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator!=](#op_neq)|Compara a desigualdade dos iteradores.|
|[operator*](#op_star)|Acessa a subcorrespondência designada.|
|[operator++](#op_add_add)|Incrementa o iterador.|
|[operator==](#op_eq_eq)|Compara a igualdade dos iteradores.|
|[operator->](#op_arrow)|Acessa a subcorrespondência designada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<regex>

**Namespace:** std

## <a name="example"></a>Exemplo

```cpp
#include <regex>
#include <iostream>

typedef std::regex_token_iterator<const char *> Myiter;
int main()
    {
    const char *pat = "aaxaayaaz";
    Myiter::regex_type rx("(a)a");
    Myiter next(pat, pat + strlen(pat), rx);
    Myiter end;

// show whole match
    for (; next != end; ++next)
        std::cout << "match == " << next->str() << std::endl;
    std::cout << std::endl;

// show prefix before match
    next = Myiter(pat, pat + strlen(pat), rx, -1);
    for (; next != end; ++next)
        std::cout << "match == " << next->str() << std::endl;
    std::cout << std::endl;

// show (a) submatch only
    next = Myiter(pat, pat + strlen(pat), rx, 1);
    for (; next != end; ++next)
        std::cout << "match == " << next->str() << std::endl;
    std::cout << std::endl;

// show prefixes and submatches
    std::vector<int> vec;
    vec.push_back(-1);
    vec.push_back(1);
    next = Myiter(pat, pat + strlen(pat), rx, vec);
    for (; next != end; ++next)
        std::cout << "match == " << next->str() << std::endl;
    std::cout << std::endl;

// show prefixes and whole matches
    int arr[] = {-1, 0};
    next = Myiter(pat, pat + strlen(pat), rx, arr);
    for (; next != end; ++next)
        std::cout << "match == " << next->str() << std::endl;
    std::cout << std::endl;

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
match == aa
match == aa
match == aa

match ==
match == x
match == y
match == z

match == a
match == a
match == a

match ==
match == a
match == x
match == a
match == y
match == a
match == z

match ==
match == aa
match == x
match == aa
match == y
match == aa
match == z
```

## <a name="difference_type"></a>  regex_token_iterator::difference_type

O tipo de uma diferença de iterador.

```cpp
typedef std::ptrdiff_t difference_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `std::ptrdiff_t`.

## <a name="iterator_category"></a>  regex_token_iterator::iterator_category

O tipo da categoria do iterador.

```cpp
typedef std::forward_iterator_tag iterator_category;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `std::forward_iterator_tag`.

## <a name="op_neq"></a>  regex_token_iterator::operator!=

Compara a desigualdade dos iteradores.

```cpp
bool operator!=(const regex_token_iterator& right);
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
O iterador a ser comparado.

### <a name="remarks"></a>Comentários

A função membro retorna `!(*this == right)`.

## <a name="op_star"></a>  regex_token_iterator::operator*

Acessa a subcorrespondência designada.

```cpp
const sub_match<BidIt>& operator*();
```

### <a name="remarks"></a>Comentários

A função de membro retorna um objeto `sub_match<BidIt>` que representa o grupo de captura identificado pelo valor de índice `subs[pos]`.

## <a name="op_add_add"></a>  regex_token_iterator::operator++

Incrementa o iterador.

```cpp
regex_token_iterator& operator++();

regex_token_iterator& operator++(int);
```

### <a name="remarks"></a>Comentários

Se o iterador armazenado `it` for um iterador de fim-de-sequência, o primeiro operador define o valor armazenado `pos` para o valor de `subs.size()` (criando dessa forma um iterador de fim de sequência). Caso contrário, o operador incrementa o valor armazenado `pos`; se o resultado for igual ao valor `subs.size()`, ela define o valor armazenado `pos` como zero e incrementa o iterador armazenado `it`. Ao incrementar, o iterador armazenado deixa-os diferentes de um iterador de fim de sequência e o operador não fará nada mais. Caso contrário, se o final da correspondência anterior estava no fim da sequência de caracteres, o operador define o valor armazenado de `pos` para `subs.size()`. Caso contrário, o operador repetidamente incrementa o valor armazenado `pos` até `pos == subs.size()` ou `subs[pos] == -1` (garantindo, assim, que a próxima desreferência do iterador retornará o final da sequência de caracteres se um dos valores de índice for -1). Em todo caso, o operador retorna o objeto.

O segundo operador faz uma cópia do objeto, incrementa o objeto e retorna a cópia.

## <a name="op_eq_eq"></a>  regex_token_iterator::operator==

Compara a igualdade dos iteradores.

```cpp
bool operator==(const regex_token_iterator& right);
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
O iterador a ser comparado.

### <a name="remarks"></a>Comentários

A função membro retorna `it == right.it && subs == right.subs && pos == right.pos`.

## <a name="op_arrow"></a>  regex_token_iterator::operator-&gt;

Acessa a subcorrespondência designada.

```cpp
const sub_match<BidIt> * operator->();
```

### <a name="remarks"></a>Comentários

A função membro retorna um ponteiro para um objeto `sub_match<BidIt>` que representa o grupo de captura identificado pelo valor do índice `subs[pos]`.

## <a name="pointer"></a>  regex_token_iterator::pointer

O tipo de um ponteiro para uma correspondência.

```cpp
typedef sub_match<BidIt> *pointer;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `sub_match<BidIt>*`, em que `BidIt` é o parâmetro de modelo.

## <a name="reference"></a>  regex_token_iterator::reference

O tipo de uma referência de uma subcorrespondência.

```cpp
typedef sub_match<BidIt>& reference;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `sub_match<BidIt>&`, em que `BidIt` é o parâmetro de modelo.

## <a name="regex_token_iterator"></a>  regex_token_iterator::regex_token_iterator

Constrói o iterador.

```cpp
regex_token_iterator();

regex_token_iterator(BidIt first, BidIt last,
    const regex_type& re, int submatch = 0,
    regex_constants::match_flag_type f = regex_constants::match_default);

regex_token_iterator(BidIt first, BidIt last,
    const regex_type& re, const vector<int> submatches,
    regex_constants::match_flag_type f = regex_constants::match_default);

template <std::size_t N>
regex_token_iterator(BidIt first, BidIt last,
    const regex_type& re, const int (&submatches)[N],
    regex_constants::match_flag_type f = regex_constants::match_default);
```

### <a name="parameters"></a>Parâmetros

*primeiro* \
Início da sequência de correspondência.

*última* \
Fim da sequência de correspondência.

\ *novamente*
Expressão regular para correspondências.

\ de *f*
Sinalizadores de correspondências.

### <a name="remarks"></a>Comentários

O primeiro construtor cria um iterador de fim de sequência.

O segundo construtor cria um objeto cujo iterador armazenado `it` é inicializado com `regex_iterator<BidIt, Elem, RXtraits>(first, last, re, f)`, cujo vetor armazenado `subs` contém exatamente um inteiro, com valor `submatch` e cujo valor armazenado `pos` é zero. Observação: o objeto resultante extrai a subcorrespondência identificada pelo valor de índice `submatch` para cada correspondência de expressão regular bem-sucedida.

O terceiro construtor cria um objeto cujo iterador armazenado `it` é inicializado para `regex_iterator<BidIt, Elem, RXtraits>(first, last, re, f)`, cujo vetor armazenado `subs` mantém uma cópia do argumento do construtor `submatches` e cujo valor armazenado `pos` é zero.

O quarto construtor cria um objeto cujo iterador armazenado `it` é inicializado para `regex_iterator<BidIt, Elem, RXtraits>(first, last, re, f)`, cujo vetor armazenado `subs` mantém os valores `N` apontados pelo argumento do construtor `submatches` e cujo valor armazenado `pos` é zero.

## <a name="regex_type"></a>  regex_token_iterator::regex_type

O tipo da expressão regular de correspondência.

```cpp
typedef basic_regex<Elem, RXtraits> regex_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo de `basic_regex<Elem, RXtraits>`.

## <a name="value_type"></a>  regex_token_iterator::value_type

O tipo de uma subcorrespondência.

```cpp
typedef sub_match<BidIt> value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `sub_match<BidIt>`, em que `BidIt` é o parâmetro de modelo.

## <a name="see-also"></a>Consulte também

[\<regex>](../standard-library/regex.md)\
\ [classe regex_constants](../standard-library/regex-constants-class.md)
\ [classe regex_error](../standard-library/regex-error-class.md)
[\<regex > funções](../standard-library/regex-functions.md) \
\ [Classe regex_iterator](../standard-library/regex-iterator-class.md)
[operadores de > de \<regex](../standard-library/regex-operators.md) \
\ [Classe regex_traits](../standard-library/regex-traits-class.md)
[\<Typedef regex>](../standard-library/regex-typedefs.md)
