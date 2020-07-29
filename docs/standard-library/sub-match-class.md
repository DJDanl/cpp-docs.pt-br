---
title: Classe sub_match
ms.date: 09/10/2018
f1_keywords:
- regex/std::sub_match
- regex/std::sub_match::matched
- regex/std::sub_match::compare
- regex/std::sub_match::length
- regex/std::sub_match::str
- regex/std::sub_match::difference_type
- regex/std::sub_match::iterator
- regex/std::sub_match::value_type
helpviewer_keywords:
- std::sub_match [C++]
- std::sub_match [C++], matched
- std::sub_match [C++], compare
- std::sub_match [C++], length
- std::sub_match [C++], str
- std::sub_match [C++], difference_type
- std::sub_match [C++], iterator
- std::sub_match [C++], value_type
ms.assetid: 804e2b9e-d16a-4c4c-ac60-024e0b2dd0e8
ms.openlocfilehash: 57aa4ec366588f71f41a747a2dc5127f87ea2e2e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222193"
---
# <a name="sub_match-class"></a>Classe sub_match

Descreve uma subcorrespondência.

## <a name="syntax"></a>Sintaxe

```cpp
template <class BidIt>
class sub_match
    : public std::pair<BidIt, BidIt>
```

## <a name="parameters"></a>parâmetros

*Bidirecional*\
O tipo de iterador para subcorrespondências.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que designa uma sequência de caracteres que correspondeu a um grupo de captura em uma chamada para [regex_match](../standard-library/regex-functions.md#regex_match) ou para [regex_search](../standard-library/regex-functions.md#regex_search). Objetos do tipo [Classe match_results](../standard-library/match-results-class.md) contêm uma matriz desses objetos, uma para cada grupo de captura na expressão regular que foi usada na pesquisa.

Se o grupo de captura não tiver sido correspondido ao membro de dados do objeto, `matched` será falso e os dois iteradores `first` e `second` (herdados de `std::pair` base) serão iguais. Se o grupo de captura for correspondido, `matched` será verdadeiro, o iterador `first` apontará para o primeiro caractere na sequência de destino que corresponde ao grupo de captura e o iterador `second` apontará para uma posição após o último caractere na sequência de destino que corresponde ao grupo de captura. Observe que para uma correspondência de comprimento zero, o membro `matched` será verdadeiro, os dois iteradores serão iguais e ambos apontarão para a posição da correspondência.

Uma correspondência de comprimento zero pode ocorrer quando um grupo de captura consiste exclusivamente em uma declaração ou em uma repetição que permite repetições de zero. Por exemplo:

“^” corresponde à sequência de destino “a”; o objeto `sub_match` correspondente ao grupo de captura 0 contém iteradores que apontam para o primeiro caractere na sequência.

“b(a*)b” corresponde à sequência de destino “bb”; o objeto `sub_match` correspondente ao grupo de captura 1 contém iteradores que apontam para o segundo caractere na sequência.

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[difference_type](#difference_type)|O tipo de uma diferença de iterador.|
|[repeti](#iterator)|O tipo de um iterador.|
|[value_type](#value_type)|O tipo de um elemento.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[comparar](#compare)|Compare a subcorrespondência com uma sequência.|
|[length](#length)|Retorna o tamanho de uma subcorrespondência.|
|[combinados](#matched)|Indica se a correspondência teve êxito.|
|[str](#str)|Converte a subcorrespondência em uma cadeia de caracteres.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[<de basic_string do operador value_type>](#op_basic_string_lt_value_type_gt)|Molda a subcorrespondência em uma cadeia de caracteres.|

## <a name="example"></a>Exemplo

```cpp
// std__regex__sub_match.cpp
// compile with: /EHsc
#include <regex>
#include <iostream>

int main()
    {
    std::regex rx("c(a*)|(b)");
    std::cmatch mr;

    std::regex_search("xcaaay", mr, rx);

    std::csub_match sub = mr[1];
    std::cout << "matched == " << std::boolalpha
        << sub.matched << std::endl;
    std::cout << "length == " << sub.length() << std::endl;

    std::csub_match::difference_type dif = std::distance(sub.first, sub.second);
    std::cout << "difference == " << dif << std::endl;

    std::csub_match::iterator first = sub.first;
    std::csub_match::iterator last = sub.second;
    std::cout << "range == " << std::string(first, last)
        << std::endl;
    std::cout << "string == " << sub << std::endl;

    std::csub_match::value_type const *ptr = "aab";
    std::cout << "compare(\"aab\") == "
        << sub.compare(ptr) << std::endl;
    std::cout << "compare(string) == "
        << sub.compare(std::string("AAA")) << std::endl;
    std::cout << "compare(sub) == "
        << sub.compare(sub) << std::endl;

    return (0);
    }
```

```Output
matched == true
length == 3
difference == 3
range == aaa
string == aaa
compare("aab") == -1
compare(string) == 1
compare(sub) == 0
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<regex>

**Namespace:** std

## <a name="sub_matchcompare"></a><a name="compare"></a>sub_match:: Compare

Compare a subcorrespondência com uma sequência.

```cpp
int compare(const sub_match& right) const;
int compare(const basic_string<value_type>& str) const;
int compare(const value_type *ptr) const;
```

### <a name="parameters"></a>parâmetros

*Certo*\
A subcorrespondência com a qual comparar.

*Str*\
A cadeia de caracteres com a qual comparar.

*PTR*\
A sequência com terminação nula com a qual comparar.

### <a name="remarks"></a>Comentários

A primeira função membro compara a sequência correspondente `[first, second)` à sequência correspondente `[right.first, right.second)`. A segunda função membro compara a sequência correspondente `[first, second)` à sequência de caracteres `[right.begin(), right.end())`. A terceira função membro compara a sequência correspondente `[first, second)` à sequência de caracteres `[right, right + std::char_traits<value_type>::length(right))`.

Cada função retorna:

um valor negativo se o primeiro valor diferente na sequência correspondente for comparado como menor que o elemento correspondente na sequência de operando (conforme determinado por `std::char_traits<value_type>::compare`) ou se os dois tiverem um prefixo comum, mas a sequência de destino for mais longa

zero se os dois forem comparados como iguais elemento por elemento e tiverem o mesmo tamanho

caso contrário, um valor positivo

## <a name="sub_matchdifference_type"></a><a name="difference_type"></a>sub_match::d ifference_type

O tipo de uma diferença de iterador.

```cpp
typedef typename iterator_traits<BidIt>::difference_type difference_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo de `iterator_traits<BidIt>::difference_type`.

## <a name="sub_matchiterator"></a><a name="iterator"></a>sub_match:: iterador

O tipo de um iterador.

```cpp
typedef BidIt iterator;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo do argumento de tipo de modelo `Bidit`.

## <a name="sub_matchlength"></a><a name="length"></a>sub_match:: comprimento

Retorna o tamanho de uma subcorrespondência.

```cpp
difference_type length() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o tamanho da sequência correspondente ou zero se não houve nenhuma sequência correspondente.

## <a name="sub_matchmatched"></a><a name="matched"></a>sub_match:: matchado

Indica se a correspondência teve êxito.

```cpp
bool matched;
```

### <a name="remarks"></a>Comentários

O membro **`true`** só terá se o grupo de captura associado à **`*this`** parte da expressão regular corresponder.

## <a name="sub_matchoperator-basic_stringltvalue_typegt"></a><a name="op_basic_string_lt_value_type_gt"></a>basic_string de sub_match:: Operator &lt; value_type&gt;

Molda a subcorrespondência em uma cadeia de caracteres.

```cpp
operator basic_string<value_type>() const;
```

### <a name="remarks"></a>Comentários

O operador de membro retorna `str()`.

## <a name="sub_matchstr"></a><a name="str"></a>sub_match:: Str

Converte a subcorrespondência em uma cadeia de caracteres.

```cpp
basic_string<value_type> str() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna `basic_string<value_type>(first, second)`.

## <a name="sub_matchvalue_type"></a><a name="value_type"></a>sub_match:: value_type

O tipo de um elemento.

```cpp
typedef typename iterator_traits<BidIt>::value_type value_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo de `iterator_traits<BidIt>::value_type`.

## <a name="see-also"></a>Confira também

[\<regex>](../standard-library/regex.md)\
[sub_match](../standard-library/sub-match-class.md)
