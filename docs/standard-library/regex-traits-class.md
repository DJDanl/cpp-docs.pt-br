---
title: Classe regex_traits
ms.date: 09/10/2018
f1_keywords:
- regex/std::regex_traits
- regex/std::regex_traits::char_type
- regex/std::regex_traits::size_type
- regex/std::regex_traits::string_type
- regex/std::regex_traits::locale_type
- regex/std::regex_traits::char_class_type
- regex/std::regex_traits::length
- regex/std::regex_traits::translate
- regex/std::regex_traits::translate_nocase
- regex/std::regex_traits::transform
- regex/std::regex_traits::transform_primary
- regex/std::regex_traits::lookup_classname
- regex/std::regex_traits::lookup_collatename
- regex/std::regex_traits::isctype
- regex/std::regex_traits::value
- regex/std::regex_traits::imbue
- regex/std::regex_traits::getloc
helpviewer_keywords:
- std::regex_traits [C++]
- std::regex_traits [C++], char_type
- std::regex_traits [C++], size_type
- std::regex_traits [C++], string_type
- std::regex_traits [C++], locale_type
- std::regex_traits [C++], char_class_type
- std::regex_traits [C++], length
- std::regex_traits [C++], translate
- std::regex_traits [C++], translate_nocase
- std::regex_traits [C++], transform
- std::regex_traits [C++], transform_primary
- std::regex_traits [C++], lookup_classname
- std::regex_traits [C++], lookup_collatename
- std::regex_traits [C++], isctype
- std::regex_traits [C++], value
- std::regex_traits [C++], imbue
- std::regex_traits [C++], getloc
ms.assetid: bc5a5eed-32fc-4eb7-913d-71c42e729e81
ms.openlocfilehash: 8879336c48d0fec8a20411abf1c07d570a1575e7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366386"
---
# <a name="regex_traits-class"></a>Classe regex_traits

Descreve as características dos elementos de correspondência.

## <a name="syntax"></a>Sintaxe

```cpp
template<class Elem>
class regex_traits
```

## <a name="parameters"></a>Parâmetros

*Elem*\
O tipo de elemento de caractere a ser descrito.

## <a name="remarks"></a>Comentários

O modelo de classe descreve vários traços de expressão regulares para o tipo *Elem*. O modelo de classe [basic_regex Classe](../standard-library/basic-regex-class.md) usa essas informações para manipular elementos do tipo *Elem*.

Cada objeto `regex_traits` contém um objeto do tipo `regex_traits::locale` que é usado por algumas de suas funções membro. A localidade padrão é uma cópia de `regex_traits::locale()`. A função membro `imbue` substitui o objeto de localidade e a função de membro `getloc` retorna uma cópia do objeto de localidade.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[regex_traits](#regex_traits)|Constrói o objeto.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[char_class_type](#char_class_type)|O tipo dos designadores da classe de caractere.|
|[char_type](#char_type)|O tipo de um elemento.|
|[locale_type](#locale_type)|O tipo do objeto de localidade armazenado.|
|[size_type](#size_type)|O tipo de um tamanho de sequência.|
|[string_type](#string_type)|O tipo de uma cadeia de caracteres de elementos.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[getloc](#getloc)|Retorna o objeto de localidade armazenado.|
|[imbue](#imbue)|Altera o objeto de localidade armazenado.|
|[isctype](#isctype)|Testa a associação da classe.|
|[length](#length)|Retorna o comprimento de uma seqüência terminada nula.|
|[lookup_classname](#lookup_classname)|Mapeia a sequência para uma classe de caractere.|
|[lookup_collatename](#lookup_collatename)|Mapeia uma sequência para um elemento de agrupamento.|
|[Transformar](#transform)|É convertido na sequência ordenada equivalente.|
|[transform_primary](#transform_primary)|É convertido na sequência ordenada sem distinção de maiúsculas e minúsculas.|
|[Traduzir](#translate)|É convertido no elemento correspondente equivalente.|
|[Translate_nocase](#translate_nocase)|É convertido no elemento correspondente equivalente sem distinção de maiúsculas e minúsculas.|
|[value](#value)|Converte um elemento em um valor de dígito.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<regex>

**Namespace:** std

## <a name="example"></a>Exemplo

```cpp
// std__regex__regex_traits.cpp
// compile with: /EHsc
#include <regex>
#include <iostream>

typedef std::regex_traits<char> Mytr;
int main()
    {
    Mytr tr;

    Mytr::char_type ch = tr.translate('a');
    std::cout << "translate('a') == 'a' == " << std::boolalpha
        << (ch == 'a') << std::endl;

    std::cout << "nocase 'a' == 'A' == " << std::boolalpha
        << (tr.translate_nocase('a') == tr.translate_nocase('A'))
        << std::endl;

    const char *lbegin = "abc";
    const char *lend = lbegin + strlen(lbegin);
    Mytr::size_type size = tr.length(lbegin);
    std::cout << "length(\"abc\") == " << size <<std::endl;

    Mytr::string_type str = tr.transform(lbegin, lend);
    std::cout << "transform(\"abc\") < \"abc\" == " << std::boolalpha
        << (str < "abc") << std::endl;

    const char *ubegin = "ABC";
    const char *uend = ubegin + strlen(ubegin);
    std::cout << "primary \"ABC\" < \"abc\" == " << std::boolalpha
        << (tr.transform_primary(ubegin, uend) <
            tr.transform_primary(lbegin, lend))
        << std::endl;

    const char *dig = "digit";
    Mytr::char_class_type cl = tr.lookup_classname(dig, dig + 5);
    std::cout << "class digit == d == " << std::boolalpha
        << (cl == tr.lookup_classname(dig, dig + 1))
        << std::endl;

    std::cout << "'3' is digit == " <<std::boolalpha
        << tr.isctype('3', tr.lookup_classname(dig, dig + 5))
        << std::endl;

    std::cout << "hex C == " << tr.value('C', 16) << std::endl;

// other members
    str = tr.lookup_collatename(dig, dig + 5);

    Mytr::locale_type loc = tr.getloc();
    tr.imbue(loc);

    return (0);
    }
```

```Output
translate('a') == 'a' == true
nocase 'a' == 'A' == true
length("abc") == 3
transform("abc") < "abc" == false
primary "ABC" < "abc" == false
class digit == d == true
'3' is digit == true
hex C == 12
```

## <a name="regex_traitschar_class_type"></a><a name="char_class_type"></a>regex_traits:char_class_type

O tipo dos designadores da classe de caractere.

```cpp
typedef T8 char_class_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de um tipo não especificado que designa a classes de caracteres. Valores desse tipo podem ser combinados usando o operador `|` para designar classes de caracteres que serão a união das classes designado pelo operandos.

## <a name="regex_traitschar_type"></a><a name="char_type"></a>regex_traits:char_type

O tipo de um elemento.

```cpp
typedef Elem char_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo do argumento de modelo `Elem`.

## <a name="regex_traitsgetloc"></a><a name="getloc"></a>regex_traits:getloc

Retorna o objeto de localidade armazenado.

```cpp
locale_type getloc() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o objeto `locale` armazenado.

## <a name="regex_traitsimbue"></a><a name="imbue"></a>regex_traits:imbue

Altera o objeto de localidade armazenado.

```cpp
locale_type imbue(locale_type loc);
```

### <a name="parameters"></a>Parâmetros

*Loc*\
O objeto de localidade a ser armazenado.

### <a name="remarks"></a>Comentários

A função membro copia *loc* para o objeto armazenado `locale` e `locale` retorna uma cópia do valor anterior do objeto armazenado.

## <a name="regex_traitsisctype"></a><a name="isctype"></a>regex_traits::isctype

Testa a associação da classe.

```cpp
bool isctype(char_type ch, char_class_type cls) const;
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento para teste.

*Cls*\
As classes de teste.

### <a name="remarks"></a>Comentários

A função do membro retorna verdadeira somente se o *caractere ch* estiver na classe de caractere designada por *cls*.

## <a name="regex_traitslength"></a><a name="length"></a>regex_traits::comprimento

Retorna o comprimento de uma seqüência terminada nula.

```cpp
static size_type length(const char_type *str);
```

### <a name="parameters"></a>Parâmetros

*Str*\
A sequência nula terminada.

### <a name="remarks"></a>Comentários

A função membro estática retorna `std::char_traits<char_type>::length(str)`.

## <a name="regex_traitslocale_type"></a><a name="locale_type"></a>regex_traits:locale_type

O tipo do objeto de localidade armazenado.

```cpp
typedef T7 locale_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo de um tipo que encapsula as localidades. Nas especializações `regex_traits<char>` e `regex_traits<wchar_t>`, é um sinônimo de `std::locale`.

## <a name="regex_traitslookup_classname"></a><a name="lookup_classname"></a>regex_traits:lookup_classname

Mapeia a sequência para uma classe de caractere.

```cpp
template <class FwdIt>
char_class_type lookup_classname(FwdIt first, FwdIt last) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Início da sequência a ser pesquisada.

*Última*\
Fim da sequência a ser pesquisada.

### <a name="remarks"></a>Comentários

A função membro retorna um valor que designa a classe de caractere nomeada pela sequência de caracteres apontada por seus argumentos. O valor não depende da diferença entre maiúsculas e minúsculas dos caracteres na sequência.

A especialização `regex_traits<char>` reconhece os nomes `"d"`, `"s"`, `"w"`, `"alnum"`, `"alpha"`, `"blank"`, `"cntrl"`, `"digit"`, `"graph"`, `"lower"`, `"print"`, `"punct"`, `"space"`, `"upper"` e `"xdigit"`, sem considerar a diferença entre maiúsculas e minúsculas.

A especialização `regex_traits<wchar_t>` reconhece os nomes `L"d"`, `L"s"`, `L"w"`, `L"alnum"`, `L"alpha"`, `L"blank"`, `L"cntrl"`, `L"digit"`, `L"graph"`, `L"lower"`, `L"print"`, `L"punct"`, `L"space"`, `L"upper"` e `L"xdigit"`, sem considerar a diferença entre maiúsculas e minúsculas.

## <a name="regex_traitslookup_collatename"></a><a name="lookup_collatename"></a>regex_traits:lookup_collatename

Mapeia uma sequência para um elemento de agrupamento.

```cpp
template <class FwdIt>
string_type lookup_collatename(FwdIt first, FwdIt last) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Início da sequência a ser pesquisada.

*Última*\
Fim da sequência a ser pesquisada.

### <a name="remarks"></a>Comentários

A função membro retorna um objeto de cadeia de caracteres que contém o elemento de agrupamento corresponde à sequência `[first, last)` ou uma cadeia de caracteres vazia se a sequência não for um elemento de agrupamento válido.

## <a name="regex_traitsregex_traits"></a><a name="regex_traits"></a>regex_traits:regex_traits

Constrói o objeto.

```cpp
regex_traits();
```

### <a name="remarks"></a>Comentários

O construtor cria um objeto cujo armazenado objeto `locale` armazenado é inicializado para a localidade padrão.

## <a name="regex_traitssize_type"></a><a name="size_type"></a>regex_traits:size_type

O tipo de um tamanho de sequência.

```cpp
typedef T6 size_type;
```

### <a name="remarks"></a>Comentários

O typedef é sinônimo de um tipo integral sem sinal. Nas especializações `regex_traits<char>` e `regex_traits<wchar_t>`, é um sinônimo de `std::size_t`.

O typedef é um sinônimo de `std::size_t`.

## <a name="regex_traitsstring_type"></a><a name="string_type"></a>regex_traits:string_type

O tipo de uma cadeia de caracteres de elementos.

```cpp
typedef basic_string<Elem> string_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo de `basic_string<Elem>`.

## <a name="regex_traitstransform"></a><a name="transform"></a>regex_traits::transformar

É convertido na sequência ordenada equivalente.

```cpp
template <class FwdIt>
string_type transform(FwdIt first, FwdIt last) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Início da sequência a ser transformada.

*Última*\
Fim da sequência a ser transformada.

### <a name="remarks"></a>Comentários

A função de membro retorna uma cadeia de caracteres que é gerada usando uma regra de transformação que depende do objeto `locale` armazenado. Para duas sequências de caracteres designadas pelos intervalos de iterador `[first1, last1)` e `[first2, last2)`, `transform(first1, last1) < transform(first2, last2)` se a sequência de caracteres designada pelo intervalo de iterador `[first1, last1)` for classificada antes da sequência de caracteres designada pelo intervalo do iterador `[first2, last2)`.

## <a name="regex_traitstransform_primary"></a><a name="transform_primary"></a>regex_traits:transform_primary

É convertido na sequência ordenada sem distinção de maiúsculas e minúsculas.

```cpp
template <class FwdIt>
string_type transform_primary(FwdIt first, FwdIt last) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Início da sequência a ser transformada.

*Última*\
Fim da sequência a ser transformada.

### <a name="remarks"></a>Comentários

A função de membro retorna uma cadeia de caracteres que é gerada usando uma regra de transformação que depende do objeto `locale` armazenado. Para duas sequências de caracteres designadas pelos intervalos de iterador `[first1, last1)` e `[first2, last2)`, `transform_primary(first1, last1) < transform_primary(first2, last2)` se a sequência de caracteres designada pelo intervalo de iterador `[first1, last1)` for classificada antes da sequência de caracteres designada pelo intervalo do iterador `[first2, last2)` sem considerar a distinção de maiúsculas e minúsculas nem acentos.

## <a name="regex_traitstranslate"></a><a name="translate"></a>regex_traits::traduzir

É convertido no elemento correspondente equivalente.

```cpp
char_type translate(char_type ch) const;
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser convertido.

### <a name="remarks"></a>Comentários

A função membro retorna um caracteres que é gerado usando uma regra de transformação que depende do objeto `locale` armazenado. Para dois objetos `char_type`, `ch1` e `ch2`, `translate(ch1) == translate(ch2)` somente se `ch1` e `ch2` devem corresponder quando um ocorre na definição de expressão regular e o outro em uma posição correspondente na sequência de destino para uma correspondência com distinção de localidade.

## <a name="regex_traitstranslate_nocase"></a><a name="translate_nocase"></a>regex_traits:translate_nocase

É convertido no elemento correspondente equivalente sem distinção de maiúsculas e minúsculas.

```cpp
char_type translate_nocase(char_type ch) const;
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser convertido.

### <a name="remarks"></a>Comentários

A função membro retorna um caracteres que é gerado usando uma regra de transformação que depende do objeto `locale` armazenado. Para dois objetos `char_type`, `ch1` e `ch2`, `translate_nocase(ch1) == translate_nocase(ch2)` somente se `ch1` e `ch2` devem corresponder quando um ocorre na definição de expressão regular e o outro em uma posição correspondente na sequência de destino para uma correspondência sem distinção entre maiúsculas e minúsculas.

## <a name="regex_traitsvalue"></a><a name="value"></a>regex_traits::valor

Converte um elemento em um valor de dígito.

```cpp
int value(Elem ch, int radix) const;
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser convertido.

*Base*\
A base aritmética a ser usada.

### <a name="remarks"></a>Comentários

A função do membro retorna o valor representado pelo caractere *ch* no *radix*base , ou -1 se *ch* não for um dígito válido no *radix*base . A função só será chamada com um argumento *radix* de 8, 10 ou 16.

## <a name="see-also"></a>Confira também

[\<regex>](../standard-library/regex.md)\
[regex_constants](../standard-library/regex-constants-class.md)\
[Classe regex_error](../standard-library/regex-error-class.md)\
[\<funções de> regex](../standard-library/regex-functions.md)\
[regex_iterator](../standard-library/regex-iterator-class.md)\
[\<operadores de> regex](../standard-library/regex-operators.md)\
[classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)\
[\<> de reex](../standard-library/regex-typedefs.md)\
[regex_traits\<char classe>](../standard-library/regex-traits-char-class.md)\
[Classe regex_traits\<wchar_t>](../standard-library/regex-traits-wchar-t-class.md)
