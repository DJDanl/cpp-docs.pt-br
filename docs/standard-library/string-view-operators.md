---
title: '&lt;operadores&gt; string_view'
ms.date: 04/19/2019
f1_keywords:
- xstring/basic_string_view::operator!=
- xstring/basic_string_view::operator&gt;
- xstring/basic_string_view::operator&gt;=
- xstring/basic_string_view::operator&lt;
- xstring/basic_string_view::operator&lt;&lt;
- xstring/basic_string_view::operator&lt;=
- xstring/basic_string_view::operator+
- xstring/basic_string_view::operator==
helpviewer_keywords:
- std::basic_string_view::operator!=
- std::basic_string_view::operator&gt;
- std::basic_string_view::operator&gt;=
- std::basic_string_view::operator&lt;
- std::basic_string_view::operator&lt;&lt;
- std::basic_string_view::operator&lt;=, std::basic_string_view::operator==
ms.openlocfilehash: caa6e515428cc0ea767eef20e819753c8f7ff8f9
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459213"
---
# <a name="ltstringviewgt-operators"></a>&lt;operadores&gt; string_view

Use esses operadores para comparar dois objetos string_view ou um string_view e algum outro objeto de cadeia de caracteres (por exemplo [std:: String](basic-string-class.md)ou **Char\*** ) para o qual uma conversão implícita é fornecida. 

||||
|-|-|-|
|[operator!=](#op_neq)|[operator&gt;](#op_gt)|[operator&gt;=](#op_gt_eq)|
|[operator&lt;](#op_lt)|[operator&lt;&lt;](#op_lt_lt)|[operator&lt;=](#op_lt_eq)|
|[operator==](#op_eq_eq)|[operator""sv](#op_sv)|

## <a name="op_neq"></a>operador! =

Testa se o objeto à esquerda do operador é diferente do objeto à direita.

```cpp
template <class CharType, class Traits>
bool operator!=(
    const basic_string_view<CharType, Traits>& left,
    const basic_string_view<CharType, Traits>& right);

template <class CharType, class Traits>
bool operator!=(
    const basic_string_view<CharType, Traits>& left,
    convertible_string_type right);

template <class CharType, class Traits>
bool operator!=(
    convertible_string_type left,
    const basic_string_view<CharType, Traits>& right);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
Qualquer tipo de cadeia de caracteres conversível ou `basic_string_view` um objeto do tipo a ser comparado.

*Certo*\
Qualquer tipo de cadeia de caracteres conversível ou `basic_string_view` um objeto do tipo a ser comparado.

### <a name="return-value"></a>Valor de retorno

**true** se o objeto no lado esquerdo do operador não for modo lexicográfico igual ao objeto no lado direito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Uma conversão implícita deve existir de *convertible_string_type* para string_view no outro lado. 

A comparação é baseada em uma comparação de lexicográfica emparelhada das sequências de caracteres. Se eles tiverem o mesmo número de elementos e os elementos forem iguais, os dois objetos serão iguais. Caso contrário, são diferentes.

## <a name="op_eq_eq"></a>operador = =

Testa se o objeto à esquerda do operador é igual ao objeto à direita.

```cpp
template <class CharType, class Traits>
bool operator==(
    const basic_string_view<CharType, Traits>& left,
    const basic_string_view<CharType, Traits>& right);

template <class CharType, class Traits>
bool operator==(
    const basic_string_view<CharType, Traits>& left,
    convertible_string_type right);

template <class CharType, class Traits>
bool operator==(
    convertible_string_type left,
    const basic_string_view<CharType, Traits>& right);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
Qualquer tipo de cadeia de caracteres conversível ou `basic_string_view` um objeto do tipo a ser comparado.

*Certo*\
Qualquer tipo de cadeia de caracteres conversível ou `basic_string_view` um objeto do tipo a ser comparado.

### <a name="return-value"></a>Valor de retorno

**true** se o objeto no lado esquerdo do operador for modo lexicográfico igual ao objeto no lado direito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Uma conversão implícita deve existir de *convertible_string_type* para string_view no outro lado. 

A comparação é baseada em uma comparação de lexicográfica emparelhada das sequências de caracteres. Se eles tiverem o mesmo número de elementos e os elementos forem iguais, os dois objetos serão iguais.


## <a name="op_lt"></a> Operador&lt;

Testa se o objeto no lado esquerdo do operador é menor que o objeto no sidestring_view direito
```cpp
template <class CharType, class Traits>
bool operator<(
    const basic_string_view<CharType, Traits>& left,
    const basic_string_view<CharType, Traits>& right);

template <class CharType, class Traits>
bool operator<(
    const basic_string_view<CharType, Traits>& left,
    convertible_string_type right);

template <class CharType, class Traits>
bool operator<(
    convertible_string_type left,
    const basic_string_view<CharType, Traits>& right);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
Qualquer tipo de cadeia de caracteres conversível ou `basic_string_view` um objeto do tipo a ser comparado.

*Certo*\
Qualquer tipo de cadeia de caracteres conversível ou `basic_string_view` um objeto do tipo a ser comparado.

### <a name="return-value"></a>Valor de retorno

**true** se o objeto no lado esquerdo do operador for modo lexicográfico menor que o objeto no lado direito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Uma conversão implícita deve existir de *convertible_string_type* para string_view no outro lado. 

A comparação é baseada em uma comparação de lexicográfica emparelhada das sequências de caracteres. Quando o primeiro par de caracteres desiguals é encontrado, o resultado dessa comparação é retornado. Se nenhum caractere diferente for encontrado, mas uma sequência for menor, a sequência mais curta será menor do que a mais longa. Em outras palavras, "Cat" é menor que "gatos".

### <a name="example"></a>Exemplo

```cpp
#include <string>
#include <string_view>

using namespace std;

int main()
{
    string_view sv1 { "ABA" };
    string_view sv2{ "ABAC" };
    string_view sv3{ "ABAD" };
    string_view sv4{ "ABACE" };

    bool result = sv2 > sv1; // true
    result = sv3 > sv2; // true
    result = sv3 != sv1; // true
    result = sv4 < sv3; // true because `C` < `D`
}
```

## <a name="op_lt_eq"></a> operador&lt;=

Testa se o objeto à esquerda do operador é menor que ou igual ao objeto à direita.

```cpp
template <class CharType, class Traits>
bool operator<=(
    const basic_string_view<CharType, Traits>& left,
    const basic_string_view<CharType, Traits>& right);

template <class CharType, class Traits>
bool operator<=(
    const basic_string_view<CharType, Traits>& left,
    convertible_string_type right);

template <class CharType, class Traits>
bool operator<=(
    convertible_string_type left,
    const basic_string_view<CharType, Traits>& right);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
Qualquer tipo de cadeia de caracteres conversível ou `basic_string_view` um objeto do tipo a ser comparado.

*Certo*\
Qualquer tipo de cadeia de caracteres conversível ou `basic_string_view` um objeto do tipo a ser comparado.

### <a name="return-value"></a>Valor de retorno

**true** se o objeto no lado esquerdo do operador for modo lexicográfico menor ou igual ao objeto no lado direito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Consulte [operador&lt;](#op_lt).

## <a name="op_lt_lt"></a> operador&lt;&lt;

Grava um string_view em um fluxo de saída.

```cpp
template <class CharType, class Traits>
inline basic_ostream<CharType, Traits>& operator<<(
    basic_ostream<CharType, Traits>& Ostr, const basic_string_view<CharType, Traits> Str);
```

### <a name="parameters"></a>Parâmetros

*Ostr*\
um fluxo de saída no qual está sendo gravado.

*Str*\
O string_view a ser inserido em um fluxo de saída.

### <a name="return-value"></a>Valor de retorno

um fluxo de saída no qual está sendo gravado.

### <a name="remarks"></a>Comentários

Use este operador para inserir o conteúdo de um string_view em um fluxo de saída, por exemplo, usando [std:: cout](iostream.md#cout).

## <a name="op_gt"></a> Operador&gt;

Testa se o objeto à esquerda do operador é maior do que o objeto à direita.

```cpp
template <class CharType, class Traits>
bool operator>(
    const basic_string_view<CharType, Traits>& left,
    const basic_string_view<CharType, Traits>& right);

template <class CharType, class Traits>
bool operator>(
    const basic_string_view<CharType, Traits>& left,
    convertible_string_type right);

template <class CharType, class Traits>
bool operator>(
    convertible_string_type left,
    const basic_string_view<CharType, Traits>& right);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
Qualquer tipo de cadeia de caracteres conversível ou `basic_string_view` um objeto do tipo a ser comparado.

*Certo*\
Qualquer tipo de cadeia de caracteres conversível ou `basic_string_view` um objeto do tipo a ser comparado.

### <a name="return-value"></a>Valor de retorno

**true** se o objeto no lado esquerdo do operador for modo lexicográfico maior que o objeto string_view no lado direito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Consulte [operador&lt;](#op_lt).

## <a name="op_gt_eq"></a> operador&gt;=

Testa se o objeto à esquerda do operador é maior que ou igual ao objeto à direita.

```cpp
template <class CharType, class Traits>
bool operator>=(
    const basic_string_view<CharType, Traits>& left,
    const basic_string_view<CharType, Traits>& right);

template <class CharType, class Traits>
bool operator>=(
    const basic_string_view<CharType, Traits>& left,
    convertible_string_type right);

template <class CharType, class Traits>
bool operator>=(
    convertible_string_type left,
    const basic_string_view<CharType, Traits>& right);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
Qualquer tipo de cadeia de caracteres conversível ou `basic_string_view` um objeto do tipo a ser comparado.

*Certo*\
Qualquer tipo de cadeia de caracteres conversível ou `basic_string_view` um objeto do tipo a ser comparado.

### <a name="return-value"></a>Valor de retorno

**true** se o objeto no lado esquerdo do operador for modo lexicográfico maior ou igual ao objeto no lado direito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Consulte [operador&lt;](#op_lt).

## <a name="op_sv"></a>Operator "" VA (string_view literal)

Constrói um string_view de um literal de cadeia de caracteres. Requer namespace `std::literals::string_view_literals`. 

### <a name="example"></a>Exemplo

```cpp

using namespace std;
using namespace literals::string_view_literals;

    string_view sv{ "Hello"sv };
    wstring_view wsv{ L"Hello"sv };
    u16string_view sv16{ u"Hello"sv };
    u32string_view sv32{ U"Hello"sv };
```

## <a name="see-also"></a>Consulte também

[\<string_view>](../standard-library/string-view.md)
