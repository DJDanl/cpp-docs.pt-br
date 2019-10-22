---
title: Classe basic_regex
ms.date: 03/27/2019
f1_keywords:
- regex/std::basic_regex
helpviewer_keywords:
- basic_regex class
ms.assetid: 8a18c6b4-f22a-4cfd-bc16-b4267867ebc3
ms.openlocfilehash: 45776754bd0854aeb85382eda95891a6832ca09e
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689961"
---
# <a name="basic_regex-class"></a>Classe basic_regex

Encapsula uma expressão regular.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class RXtraits>
class basic_regex
```

## <a name="parameters"></a>Parâmetros

@No__t_1 *elem*
O tipo de elemento a ser correspondido.

@No__t_1 *RXtraits*
Classe de características para elementos.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que contém uma expressão regular. Objetos desse modelo de classe podem ser passados para as funções de modelo [regex_match](../standard-library/regex-functions.md#regex_match), [regex_search](../standard-library/regex-functions.md#regex_search)e [regex_replace](../standard-library/regex-functions.md#regex_replace), juntamente com argumentos de cadeia de caracteres de texto adequados, para Pesquisar texto que corresponda à expressão regular. Há duas especializações desse modelo de classe, com o [Regex](../standard-library/regex-typedefs.md#regex) de definições de tipo para elementos do tipo **Char**e [wregex](../standard-library/regex-typedefs.md#wregex) para elementos do tipo **wchar_t**.

O argumento de modelo *RXtraits* descreve várias propriedades importantes da sintaxe das expressões regulares às quais o modelo de classe dá suporte. Uma classe que especifica essas características de expressão regular deve ter a mesma interface externa que um objeto do tipo [Classe regex_traits](../standard-library/regex-traits-class.md).

Algumas funções usam uma sequência de operando que define uma expressão regular. Você pode especificar uma sequência de operando de várias maneiras:

`ptr`--uma sequência terminada em nulo (como uma cadeia de caracteres C, para *elem* do tipo **Char**) começando em `ptr` (que não deve ser um ponteiro nulo), em que o elemento de terminação é o valor `value_type()` e não faz parte da sequência do operando

`ptr`, `count` – uma sequência de elementos `count` começando em `ptr` (que não deve ser um ponteiro nulo)

`str` – a sequência especificada pelo objeto `basic_string``str`

`first`, `last` – uma sequência de elementos delimitados pelos iteradores `first` e `last`, no intervalo `[first, last)`

`right` – o objeto `basic_regex``right`

Essas funções de membro também usam um argumento `flags` que especifica várias opções para a interpretação da expressão regular, além das descritas pelo tipo *RXtraits* .

### <a name="members"></a>Membros

|Membro|Valor padrão|
|-|-|
|public static const flag_type ICase|regex_constants::icase|
|Public estática const flag_type NoSubs|regex_constants:: NoSubs|
|público estático const flag_type otimizar|regex_constants:: Optimize|
|Agrupamento Public estático const flag_type|regex_constants:: COLLATE|
|public static const flag_type ECMAScript|regex_constants:: ECMAScript|
|pública estática const flag_type básica|regex_constants:: básico|
|pública estática const flag_type estendida|regex_constants:: estendido|
|public static const flag_type awk|regex_constants:: awk|
|public static const flag_type grep|regex_constants:: grep|
|public static const flag_type egrep|regex_constants::egrep|
|características RXtraits privadas||

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_regex](#basic_regex)|Construa o objeto de expressão regular.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[flag_type](#flag_type)|O tipo de sinalizadores de opção de sintaxe.|
|[locale_type](#locale_type)|O tipo do objeto de localidade armazenado.|
|[value_type](#value_type)|O tipo de elemento.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[assign](#assign)|Atribui um valor ao objeto da expressão regular.|
|[flags](#flags)|Retorna os sinalizadores de opção de sintaxe.|
|[getloc](#getloc)|Retorna o objeto de localidade armazenado.|
|[imbue](#imbue)|Altera o objeto de localidade armazenado.|
|[mark_count](#mark_count)|Retorna o número de subexpressões correspondente.|
|[swap](#swap)|Troca dois objetos de expressão regular.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_eq)|Atribui um valor ao objeto da expressão regular.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<regex>

**Namespace:** std

## <a name="example"></a>Exemplo

```cpp
// std__regex__basic_regex.cpp
// compile with: /EHsc
#include <regex>
#include <iostream>

using namespace std;

int main()
{
    regex::value_type elem = 'x';
    regex::flag_type flag = regex::grep;

    elem = elem;  // to quiet "unused" warnings
    flag = flag;

    // constructors
    regex rx0;
    cout << "match(\"abc\", \"\") == " << boolalpha
        << regex_match("abc", rx0) << endl;

    regex rx1("abcd", regex::ECMAScript);
    cout << "match(\"abc\", \"abcd\") == " << boolalpha
        << regex_match("abc", rx1) << endl;

    regex rx2("abcd", 3);
    cout << "match(\"abc\", \"abc\") == " << boolalpha
        << regex_match("abc", rx2) << endl;

    regex rx3(rx2);
    cout << "match(\"abc\", \"abc\") == " << boolalpha
        << regex_match("abc", rx3) << endl;

    string str("abcd");
    regex rx4(str);
    cout << "match(string(\"abcd\"), \"abc\") == " << boolalpha
        << regex_match("abc", rx4) << endl;

    regex rx5(str.begin(), str.end() - 1);
    cout << "match(string(\"abc\"), \"abc\") == " << boolalpha
        << regex_match("abc", rx5) << endl;
    cout << endl;

    // assignments
    rx0 = "abc";
    rx0 = rx1;
    rx0 = str;

    rx0.assign("abcd", regex::ECMAScript);
    rx0.assign("abcd", 3);
    rx0.assign(rx1);
    rx0.assign(str);
    rx0.assign(str.begin(), str.end() - 1);

    rx0.swap(rx1);

    // mark_count
    cout << "\"abc\" mark_count == "
        << regex("abc").mark_count() << endl;
    cout << "\"(abc)\" mark_count == "
        << regex("(abc)").mark_count() << endl;

    // locales
    regex::locale_type loc = rx0.imbue(locale());
    cout << "getloc == imbued == " << boolalpha
        << (loc == rx0.getloc()) << endl;

    // initializer_list
    regex rx6({ 'a', 'b', 'c' }, regex::ECMAScript);
    cout << "match(\"abc\") == " << boolalpha
        << regex_match("abc", rx6);
    cout << endl;
}
```

```Output
match("abc", "") == false
match("abc", "abcd") == false
match("abc", "abc") == true
match("abc", "abc") == true
match(string("abcd"), "abc") == false
match(string("abc"), "abc") == true

"abc" mark_count == 0
"(abc)" mark_count == 1
getloc == imbued == true
match("abc") == true
```

## <a name="assign"></a>  basic_regex::assign

Atribui um valor ao objeto da expressão regular.

```cpp
basic_regex& assign(
    const basic_regex& right);

basic_regex& assign(
    const Elem* ptr,
    flag_type flags = ECMAScript);

basic_regex& assign(
    const Elem* ptr,
    size_type len,
    flag_type flags = ECMAScript);

basic_regex& assign(
    initializer_list<_Elem> IList,
    flag_type flags = regex_constants::ECMAScript);

template <class STtraits, class STalloc>
basic_regex& assign(
    const basic_string<Elem, STtraits, STalloc>& str,
    flag_type flags = ECMAScript);

template <class InIt>
basic_regex& assign(
    InIt first, InIt last,
    flag_type flags = ECMAScript);
```

### <a name="parameters"></a>Parâmetros

@No__t_1 de *características*
Classe de características para uma fonte de cadeia de caracteres.

@No__t_1 de *desalocação*
Classe de alocador de uma fonte de cadeia de caracteres.

@No__t_1 de *inicialização*
Tipo de iterador de entrada para uma fonte de intervalo.

\ *à direita*
Fonte de regex a copiar.

\ *PTR*
Ponteiro para o início da sequência a copiar.

*sinalizadores* \
Sinalizadores de opção de sintaxe a adicionar ao copiar.

*> Len/TD* \
Comprimento da sequência a copiar.

\ de *Str*
Cadeia de caracteres a copiar.

*primeiro* \
Início da sequência a copiar.

*última* \
Fim da sequência a copiar.

*IList* \
A initializer_list a ser copiada.

### <a name="remarks"></a>Comentários

As funções membro substituem, cada uma, a expressão regular mantida por `*this` pela expressão regular descrita pela sequência de operando, então retornam `*this`.

## <a name="basic_regex"></a>  basic_regex::basic_regex

Construa o objeto de expressão regular.

```cpp
basic_regex();

explicit basic_regex(
    const Elem* ptr,
    flag_type flags);

explicit basic_regex(
    const Elem* ptr,
    size_type len,
    flag_type flags);

basic_regex(
    const basic_regex& right);

basic_regex(
    initializer_list<Type> IList,
    flag_type flags);

template <class STtraits, class STalloc>
explicit basic_regex(
    const basic_string<Elem, STtraits, STalloc>& str,
    flag_type flags);

template <class InIt>
explicit basic_regex(
    InIt first,
    InIt last,
    flag_type flags);
```

### <a name="parameters"></a>Parâmetros

@No__t_1 de *características*
Classe de características para uma fonte de cadeia de caracteres.

@No__t_1 de *desalocação*
Classe de alocador de uma fonte de cadeia de caracteres.

@No__t_1 de *inicialização*
Tipo de iterador de entrada para uma fonte de intervalo.

\ *à direita*
Fonte de regex a copiar.

\ *PTR*
Ponteiro para o início da sequência a copiar.

*sinalizadores* \
Sinalizadores de opção de sintaxe a adicionar ao copiar.

*> Len/TD* \
Comprimento da sequência a copiar.

\ de *Str*
Cadeia de caracteres a copiar.

*primeiro* \
Início da sequência a copiar.

*última* \
Fim da sequência a copiar.

*IList* \
A initializer_list a ser copiada.

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um objeto construído por padrão do tipo `RXtraits`.

O primeiro construtor constrói um objeto `basic_regex` vazio. Os outros construtores constroem um objeto `basic_regex` que contém a expressão regular descrita pela sequência de operando.

Um objeto `basic_regex` vazio não corresponde a nenhuma sequência de caracteres quando passado para [regex_match](../standard-library/regex-functions.md#regex_match), [regex_search](../standard-library/regex-functions.md#regex_search)ou [regex_replace](../standard-library/regex-functions.md#regex_replace).

## <a name="flag_type"></a>  basic_regex::flag_type

O tipo de sinalizadores de opção de sintaxe.

```cpp
typedef regex_constants::syntax_option_type flag_type;
```

### <a name="remarks"></a>Comentários

O tipo é sinônimo de [regex_constants::syntax_option_type](../standard-library/regex-constants-class.md#syntax_option_type).

## <a name="flags"></a>  basic_regex::flags

Retorna os sinalizadores de opção de sintaxe.

```cpp
flag_type flags() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o valor do argumento `flag_type` passado para a chamada mais recente para uma das funções membro [basic_regex::assign](#assign) ou, se nenhuma chamada assim tiver sido feita, o valor passado para o construtor.

## <a name="getloc"></a>  basic_regex::getloc

Retorna o objeto de localidade armazenado.

```cpp
locale_type getloc() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna `traits.`[regex_traits::getloc](../standard-library/regex-traits-class.md#getloc)`()`.

## <a name="imbue"></a>  basic_regex::imbue

Altera o objeto de localidade armazenado.

```cpp
locale_type imbue(locale_type loc);
```

### <a name="parameters"></a>Parâmetros

\ de *Loc*
O objeto de localidade a ser armazenado.

### <a name="remarks"></a>Comentários

A função de membro esvazia `*this` e retorna `traits.`[regex_traits::imbue](../standard-library/regex-traits-class.md#imbue)`(loc)`.

## <a name="locale_type"></a>  basic_regex::locale_type

O tipo do objeto de localidade armazenado.

```cpp
typedef typename RXtraits::locale_type locale_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de [regex_traits::locale_type](../standard-library/regex-traits-class.md#locale_type).

## <a name="mark_count"></a>  basic_regex::mark_count

Retorna o número de subexpressões correspondente.

```cpp
unsigned mark_count() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o número de grupos de captura na expressão regular.

## <a name="op_eq"></a>  basic_regex::operator=

Atribui um valor ao objeto da expressão regular.

```cpp
basic_regex& operator=(const basic_regex& right);

basic_regex& operator=(const Elem *str);

template <class STtraits, class STalloc>
basic_regex& operator=(const basic_string<Elem, STtraits, STalloc>& str);
```

### <a name="parameters"></a>Parâmetros

@No__t_1 de *características*
Classe de características para uma fonte de cadeia de caracteres.

@No__t_1 de *desalocação*
Classe de alocador de uma fonte de cadeia de caracteres.

\ *à direita*
Fonte de regex a copiar.

\ de *Str*
Cadeia de caracteres a copiar.

### <a name="remarks"></a>Comentários

Os operadores substituem, cada um, a expressão regular mantida por `*this` pela expressão regular descrita pela sequência de operando, então retornam `*this`.

## <a name="swap"></a>  basic_regex::swap

Troca dois objetos de expressão regular.

```cpp
void swap(basic_regex& right) throw();
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
O objeto de expressão regular com o qual trocar.

### <a name="remarks"></a>Comentários

A função membro troca as expressões regulares entre `*this` e *direita*. Ela faz isso em um horário constante e não gera exceções.

## <a name="value_type"></a>  basic_regex::value_type

O tipo de elemento.

```cpp
typedef Elem value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo *elem*.

## <a name="see-also"></a>Consulte também

[\<regex>](../standard-library/regex.md)\
\ [regex_match](../standard-library/regex-functions.md#regex_match)
\ [regex_search](../standard-library/regex-functions.md#regex_search)
\ [regex_replace](../standard-library/regex-functions.md#regex_replace)
[regex](../standard-library/regex-typedefs.md#regex)\
[wregex](../standard-library/regex-typedefs.md#wregex)\
[Classe regex_traits](../standard-library/regex-traits-class.md)
