---
title: operadores de&gt; de string_view &lt;
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
ms.openlocfilehash: 1bf4fa82e10d236828059a37c639e3a3b64bc5f9
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80076400"
---
# <a name="ltstring_viewgt-operators"></a>operadores de&gt; de string_view &lt;

Use esses operadores para comparar dois objetos string_view, ou um string_view e algum outro objeto de cadeia de caracteres (por exemplo, [std:: String](basic-string-class.md)ou **Char\*** ) para o qual uma conversão implícita é fornecida.

||||
|-|-|-|
|[operator!=](#op_neq)|[operator&gt;](#op_gt)|[operator&gt;=](#op_gt_eq)|
|[operator&lt;](#op_lt)|[operator&lt;&lt;](#op_lt_lt)|[operator&lt;=](#op_lt_eq)|
|[operator==](#op_eq_eq)|[operador "" VA](#op_sv)|

## <a name="operator"></a><a name="op_neq"></a>operador! =

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

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Qualquer tipo de cadeia de caracteres conversível ou um objeto do tipo `basic_string_view` a ser comparado.

\ *à direita*
Qualquer tipo de cadeia de caracteres conversível ou um objeto do tipo `basic_string_view` a ser comparado.

### <a name="return-value"></a>Valor retornado

**true** se o objeto no lado esquerdo do operador não for modo lexicográfico igual ao objeto no lado direito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Uma conversão implícita deve existir de *convertible_string_type* para a string_view do outro lado.

A comparação é baseada em uma comparação de lexicográfica emparelhada das sequências de caracteres. Se eles tiverem o mesmo número de elementos e os elementos forem iguais, os dois objetos serão iguais. Caso contrário, são diferentes.

## <a name="operator"></a><a name="op_eq_eq"></a>operador = =

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

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Qualquer tipo de cadeia de caracteres conversível ou um objeto do tipo `basic_string_view` a ser comparado.

\ *à direita*
Qualquer tipo de cadeia de caracteres conversível ou um objeto do tipo `basic_string_view` a ser comparado.

### <a name="return-value"></a>Valor retornado

**true** se o objeto no lado esquerdo do operador for modo lexicográfico igual ao objeto no lado direito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Uma conversão implícita deve existir de *convertible_string_type* para a string_view do outro lado.

A comparação é baseada em uma comparação de lexicográfica emparelhada das sequências de caracteres. Se eles tiverem o mesmo número de elementos e os elementos forem iguais, os dois objetos serão iguais.

## <a name="operatorlt"></a><a name="op_lt">Operador </a>&lt;

Testa se o objeto no lado esquerdo do operador é menor que o objeto à direita sidestring_view

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

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Qualquer tipo de cadeia de caracteres conversível ou um objeto do tipo `basic_string_view` a ser comparado.

\ *à direita*
Qualquer tipo de cadeia de caracteres conversível ou um objeto do tipo `basic_string_view` a ser comparado.

### <a name="return-value"></a>Valor retornado

**true** se o objeto no lado esquerdo do operador for modo lexicográfico menor que o objeto no lado direito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Uma conversão implícita deve existir de *convertible_string_type* para a string_view do outro lado.

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

## <a name="operatorlt"></a><a name="op_lt_eq"></a>= de&lt;do operador

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

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Qualquer tipo de cadeia de caracteres conversível ou um objeto do tipo `basic_string_view` a ser comparado.

\ *à direita*
Qualquer tipo de cadeia de caracteres conversível ou um objeto do tipo `basic_string_view` a ser comparado.

### <a name="return-value"></a>Valor retornado

**true** se o objeto no lado esquerdo do operador for modo lexicográfico menor ou igual ao objeto no lado direito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Consulte [&lt;do operador ](#op_lt).

## <a name="operatorltlt"></a><a name="op_lt_lt"></a>&lt; de&lt;do operador

Grava um string_view em um fluxo de saída.

```cpp
template <class CharType, class Traits>
inline basic_ostream<CharType, Traits>& operator<<(
    basic_ostream<CharType, Traits>& Ostr, const basic_string_view<CharType, Traits> Str);
```

### <a name="parameters"></a>parâmetros

\ *OSTR*
um fluxo de saída no qual está sendo gravado.

\ de *Str*
O string_view a ser inserido em um fluxo de saída.

### <a name="return-value"></a>Valor retornado

um fluxo de saída no qual está sendo gravado.

### <a name="remarks"></a>Comentários

Use esse operador para inserir o conteúdo de um string_view em um fluxo de saída, por exemplo, usando [std:: cout](iostream.md#cout).

## <a name="operatorgt"></a><a name="op_gt">Operador </a>&gt;

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

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Qualquer tipo de cadeia de caracteres conversível ou um objeto do tipo `basic_string_view` a ser comparado.

\ *à direita*
Qualquer tipo de cadeia de caracteres conversível ou um objeto do tipo `basic_string_view` a ser comparado.

### <a name="return-value"></a>Valor retornado

**true** se o objeto no lado esquerdo do operador for modo lexicográfico maior que o objeto string_view no lado direito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Consulte [&lt;do operador ](#op_lt).

## <a name="operatorgt"></a><a name="op_gt_eq"></a>= de&gt;do operador

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

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Qualquer tipo de cadeia de caracteres conversível ou um objeto do tipo `basic_string_view` a ser comparado.

\ *à direita*
Qualquer tipo de cadeia de caracteres conversível ou um objeto do tipo `basic_string_view` a ser comparado.

### <a name="return-value"></a>Valor retornado

**true** se o objeto no lado esquerdo do operador for modo lexicográfico maior ou igual ao objeto no lado direito; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Consulte [&lt;do operador ](#op_lt).

## <a name="operator-sv-string_view-literal"></a><a name="op_sv"></a>operador "" VA (string_view literal)

Constrói um string_view a partir de um literal de cadeia de caracteres. Requer `std::literals::string_view_literals`de namespace.

### <a name="example"></a>Exemplo

```cpp

using namespace std;
using namespace literals::string_view_literals;

    string_view sv{ "Hello"sv };
    wstring_view wsv{ L"Hello"sv };
    u16string_view sv16{ u"Hello"sv };
    u32string_view sv32{ U"Hello"sv };
```

## <a name="see-also"></a>Confira também

[\<string_view >](../standard-library/string-view.md)
