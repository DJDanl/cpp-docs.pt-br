---
title: Classe basic_regex
ms.date: 03/27/2019
f1_keywords:
- regex/std::basic_regex
helpviewer_keywords:
- basic_regex class
ms.assetid: 8a18c6b4-f22a-4cfd-bc16-b4267867ebc3
ms.openlocfilehash: 74a8684c619e2cfbd5417950aa6108ad93511bf7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376755"
---
# <a name="basic_regex-class"></a>Classe basic_regex

Encapsula uma expressão regular.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class RXtraits>
class basic_regex
```

## <a name="parameters"></a>Parâmetros

*Elem*\
O tipo de elemento a ser correspondido.

*RXtraits*\
Classe de características para elementos.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que contém uma expressão regular. Os objetos deste modelo de classe podem ser passados para as funções do modelo [regex_match](../standard-library/regex-functions.md#regex_match), [regex_search](../standard-library/regex-functions.md#regex_search)e [regex_replace,](../standard-library/regex-functions.md#regex_replace)juntamente com argumentos de seqüência de texto adequados, para procurar um texto que corresponda à expressão regular. Existem duas especializações deste modelo de classe, com as definições de tipo [regex](../standard-library/regex-typedefs.md#regex) para elementos do tipo **char**, e [wregex](../standard-library/regex-typedefs.md#wregex) para elementos do tipo **wchar_t**.

O argumento do modelo *RXtraits* descreve várias propriedades importantes da sintaxe das expressões regulares que o modelo de classe suporta. Uma classe que especifique esses traços de expressão regulares deve ter a mesma interface externa que um objeto de tipo [regex_traits Classe](../standard-library/regex-traits-class.md).

Algumas funções usam uma sequência de operando que define uma expressão regular. Você pode especificar uma sequência de operando de várias maneiras:

`ptr`-- uma seqüência nula (como uma seqüência **char**C, `ptr` para *Elem* do tipo char ) começando em `value_type()` (que não deve ser um ponteiro nulo), onde o elemento de terminação é o valor e não faz parte da seqüência de operand

`ptr`, `count` – uma sequência de elementos `count` começando em `ptr` (que não deve ser um ponteiro nulo)

`str` – a sequência especificada pelo objeto `basic_string``str`

`first`, `last` – uma sequência de elementos delimitados pelos iteradores `first` e `last`, no intervalo `[first, last)`

`right` – o objeto `basic_regex``right`

Essas funções de membro `flags` também tomam um argumento que especifica várias opções para a interpretação da expressão regular, além daquelas descritas pelo tipo *RXtraits.*

### <a name="members"></a>Membros

|Membro|Valor Padrão|
|-|-|
|const estática pública flag_type icase|regex_constants:icase|
|const estática pública flag_type subs|regex_constants::nosubs|
|const estática pública flag_type otimizar|regex_constants::otimizar|
|const estática pública flag_type colisão|regex_constants::collate|
|const estática pública flag_type ECMAScript|regex_constants:ECMAScript|
|const estática pública flag_type básico|regex_constants::básico|
|const estática pública flag_type estendido|regex_constants::estendido|
|const estática pública flag_type awk|regex_constants::awk|
|const estática pública flag_type grep|regex_constants::grep|
|const estática pública flag_type egrep|regex_constants::egrep|
|características privadas de RXtraits||

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_regex](#basic_regex)|Construa o objeto de expressão regular.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[flag_type](#flag_type)|O tipo de sinalizadores de opção de sintaxe.|
|[locale_type](#locale_type)|O tipo do objeto de localidade armazenado.|
|[Value_type](#value_type)|O tipo de elemento.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Atribuir](#assign)|Atribui um valor ao objeto da expressão regular.|
|[Sinalizadores](#flags)|Retorna os sinalizadores de opção de sintaxe.|
|[getloc](#getloc)|Retorna o objeto de localidade armazenado.|
|[imbue](#imbue)|Altera o objeto de localidade armazenado.|
|[mark_count](#mark_count)|Retorna o número de subexpressões correspondente.|
|[Trocar](#swap)|Troca dois objetos de expressão regular.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador=](#op_eq)|Atribui um valor ao objeto da expressão regular.|

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

## <a name="basic_regexassign"></a><a name="assign"></a>basic_regex::atribuir

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

*Estreito de TT*\
Classe de características para uma fonte de cadeia de caracteres.

*STalloc*\
Classe de alocador de uma fonte de cadeia de caracteres.

*Init*\
Tipo de iterador de entrada para uma fonte de intervalo.

*Certo*\
Fonte de regex a copiar.

*Ptr*\
Ponteiro para o início da sequência a copiar.

*Sinalizadores*\
Sinalizadores de opção de sintaxe a adicionar ao copiar.

*>len/TD*\
Comprimento da sequência a copiar.

*Str*\
Cadeia de caracteres a copiar.

*Primeiro*\
Início da sequência a copiar.

*Última*\
Fim da sequência a copiar.

*Ilist*\
A initializer_list a ser copiada.

### <a name="remarks"></a>Comentários

As funções membro substituem, cada uma, a expressão regular mantida por `*this` pela expressão regular descrita pela sequência de operando, então retornam `*this`.

## <a name="basic_regexbasic_regex"></a><a name="basic_regex"></a>basic_regex::basic_regex

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

*Estreito de TT*\
Classe de características para uma fonte de cadeia de caracteres.

*STalloc*\
Classe de alocador de uma fonte de cadeia de caracteres.

*Init*\
Tipo de iterador de entrada para uma fonte de intervalo.

*Certo*\
Fonte de regex a copiar.

*Ptr*\
Ponteiro para o início da sequência a copiar.

*Sinalizadores*\
Sinalizadores de opção de sintaxe a adicionar ao copiar.

*>len/TD*\
Comprimento da sequência a copiar.

*Str*\
Cadeia de caracteres a copiar.

*Primeiro*\
Início da sequência a copiar.

*Última*\
Fim da sequência a copiar.

*Ilist*\
A initializer_list a ser copiada.

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um objeto construído por padrão do tipo `RXtraits`.

O primeiro construtor constrói um objeto `basic_regex` vazio. Os outros construtores constroem um objeto `basic_regex` que contém a expressão regular descrita pela sequência de operando.

Um `basic_regex` objeto vazio não corresponde a nenhuma seqüência de caracteres quando passado para [regex_match,](../standard-library/regex-functions.md#regex_match) [regex_search](../standard-library/regex-functions.md#regex_search)ou [regex_replace](../standard-library/regex-functions.md#regex_replace).

## <a name="basic_regexflag_type"></a><a name="flag_type"></a>basic_regex:flag_type

O tipo de sinalizadores de opção de sintaxe.

```cpp
typedef regex_constants::syntax_option_type flag_type;
```

### <a name="remarks"></a>Comentários

O tipo é sinônimo de [regex_constants::syntax_option_type](../standard-library/regex-constants-class.md#syntax_option_type).

## <a name="basic_regexflags"></a><a name="flags"></a>basic_regex::bandeiras

Retorna os sinalizadores de opção de sintaxe.

```cpp
flag_type flags() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o valor do argumento `flag_type` passado para a chamada mais recente para uma das funções membro [basic_regex::assign](#assign) ou, se nenhuma chamada assim tiver sido feita, o valor passado para o construtor.

## <a name="basic_regexgetloc"></a><a name="getloc"></a>basic_regex:getloc

Retorna o objeto de localidade armazenado.

```cpp
locale_type getloc() const;
```

### <a name="remarks"></a>Comentários

A função `traits.`membro retorna [regex_traits:getloc](../standard-library/regex-traits-class.md#getloc)`()`.

## <a name="basic_regeximbue"></a><a name="imbue"></a>basic_regex:imbue

Altera o objeto de localidade armazenado.

```cpp
locale_type imbue(locale_type loc);
```

### <a name="parameters"></a>Parâmetros

*Loc*\
O objeto de localidade a ser armazenado.

### <a name="remarks"></a>Comentários

A função do `*this` membro `traits.`esvazia e retorna [regex_traits:imbue](../standard-library/regex-traits-class.md#imbue)`(loc)`.

## <a name="basic_regexlocale_type"></a><a name="locale_type"></a>basic_regex:locale_type

O tipo do objeto de localidade armazenado.

```cpp
typedef typename RXtraits::locale_type locale_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de [regex_traits::locale_type](../standard-library/regex-traits-class.md#locale_type).

## <a name="basic_regexmark_count"></a><a name="mark_count"></a>basic_regex:mark_count

Retorna o número de subexpressões correspondente.

```cpp
unsigned mark_count() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o número de grupos de captura na expressão regular.

## <a name="basic_regexoperator"></a><a name="op_eq"></a>basic_regex:operador=

Atribui um valor ao objeto da expressão regular.

```cpp
basic_regex& operator=(const basic_regex& right);

basic_regex& operator=(const Elem *str);

template <class STtraits, class STalloc>
basic_regex& operator=(const basic_string<Elem, STtraits, STalloc>& str);
```

### <a name="parameters"></a>Parâmetros

*Estreito de TT*\
Classe de características para uma fonte de cadeia de caracteres.

*STalloc*\
Classe de alocador de uma fonte de cadeia de caracteres.

*Certo*\
Fonte de regex a copiar.

*Str*\
Cadeia de caracteres a copiar.

### <a name="remarks"></a>Comentários

Os operadores substituem, cada um, a expressão regular mantida por `*this` pela expressão regular descrita pela sequência de operando, então retornam `*this`.

## <a name="basic_regexswap"></a><a name="swap"></a>basic_regex::swap

Troca dois objetos de expressão regular.

```cpp
void swap(basic_regex& right) throw();
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto de expressão regular com o qual trocar.

### <a name="remarks"></a>Comentários

A função do membro troca `*this` as expressões regulares entre e *à direita*. Ela faz isso em um horário constante e não gera exceções.

## <a name="basic_regexvalue_type"></a><a name="value_type"></a>basic_regex:value_type

O tipo de elemento.

```cpp
typedef Elem value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro modelo *Elem*.

## <a name="see-also"></a>Confira também

[\<regex>](../standard-library/regex.md)\
[regex_match](../standard-library/regex-functions.md#regex_match)\
[regex_search](../standard-library/regex-functions.md#regex_search)\
[regex_replace](../standard-library/regex-functions.md#regex_replace)\
[Regex](../standard-library/regex-typedefs.md#regex)\
[wregex](../standard-library/regex-typedefs.md#wregex)\
[Classe regex_traits](../standard-library/regex-traits-class.md)
