---
title: '&lt;string_view&gt; operadores'
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
ms.openlocfilehash: 1fbb7faf7d6fc92a053c0f4d47575c5c53c7968e
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64346914"
---
# <a name="ltstringviewgt-operators"></a>&lt;string_view&gt; operadores

Use esses operadores para comparar dois objetos string_view, ou um string_view e algum outro objeto de cadeia de caracteres (por exemplo [std:: string](basic-string-class.md), ou **char\*** ) para que uma conversão implícita é fornecida. 

||||
|-|-|-|
|[operator!=](#op_neq)|[operator&gt;](#op_gt)|[operator&gt;=](#op_gt_eq)|
|[operator&lt;](#op_lt)|[operator&lt;&lt;](#op_lt_lt)|[operator&lt;=](#op_lt_eq)|
|[operator==](#op_eq_eq)|[operator""sv](#op_sv)|

## <a name="op_neq"></a> operador! =

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

*left*<br/>
Um objeto do tipo ou qualquer tipo de cadeia de caracteres conversíveis `basic_string_view` a ser comparado.

*right*<br/>
Um objeto do tipo ou qualquer tipo de cadeia de caracteres conversíveis `basic_string_view` a ser comparado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o objeto no lado esquerdo do operador não é lexicograficamente igual ao objeto no lado direito; caso contrário **falso**.

### <a name="remarks"></a>Comentários

Uma conversão implícita deve existir na *convertible_string_type* para a string_view no outro lado. 

A comparação é baseada em um par comparação lexicográfica de sequências de caracteres. Se eles tiverem o mesmo número de elementos e os elementos são todas iguais, os dois objetos são iguais. Caso contrário, são diferentes.

## <a name="op_eq_eq"></a> operator==

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

*left*<br/>
Um objeto do tipo ou qualquer tipo de cadeia de caracteres conversíveis `basic_string_view` a ser comparado.

*right*<br/>
Um objeto do tipo ou qualquer tipo de cadeia de caracteres conversíveis `basic_string_view` a ser comparado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o objeto no lado esquerdo do operador é lexicograficamente igual ao objeto no lado direito; caso contrário **falso**.

### <a name="remarks"></a>Comentários

Uma conversão implícita deve existir na *convertible_string_type* para a string_view no outro lado. 

A comparação é baseada em um par comparação lexicográfica de sequências de caracteres. Se eles tiverem o mesmo número de elementos e os elementos são todas iguais, os dois objetos são iguais.


## <a name="op_lt"> Operador</a>&lt;

Testa se o objeto no lado esquerdo do operador é menor que o objeto a sidestring_view à direita
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

*left*<br/>
Um objeto do tipo ou qualquer tipo de cadeia de caracteres conversíveis `basic_string_view` a ser comparado.

*right*<br/>
Um objeto do tipo ou qualquer tipo de cadeia de caracteres conversíveis `basic_string_view` a ser comparado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o objeto no lado esquerdo do operador é lexicograficamente menor que o objeto no lado direito; caso contrário **falso**.

### <a name="remarks"></a>Comentários

Uma conversão implícita deve existir na *convertible_string_type* para a string_view no outro lado. 

A comparação é baseada em um par comparação lexicográfica de sequências de caracteres. Quando o primeiro par desigual de caracteres for encontrado, o resultado da comparação é retornado. Se nenhum caractere diferente é encontrado, mas uma sequência for menor, a sequência mais curta for menor que a mais longa. Em outras palavras, "gato" é menor que "gatos".

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

*left*<br/>
Um objeto do tipo ou qualquer tipo de cadeia de caracteres conversíveis `basic_string_view` a ser comparado.

*right*<br/>
Um objeto do tipo ou qualquer tipo de cadeia de caracteres conversíveis `basic_string_view` a ser comparado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o objeto no lado esquerdo do operador é lexicograficamente menor ou igual ao objeto no lado direito; caso contrário **falso**.

### <a name="remarks"></a>Comentários

Ver [operador&lt;](#op_lt).

## <a name="op_lt_lt"></a> operador&lt;&lt;

Grava um string_view em um fluxo de saída.

```cpp
template <class CharType, class Traits>
inline basic_ostream<CharType, Traits>& operator<<(
    basic_ostream<CharType, Traits>& Ostr, const basic_string_view<CharType, Traits> Str);
```

### <a name="parameters"></a>Parâmetros

*Ostr*<br/>
um fluxo de saída que estão sendo gravado.

*Str*<br/>
String_view serem inseridos em um fluxo de saída.

### <a name="return-value"></a>Valor de retorno

um fluxo de saída que estão sendo gravado.

### <a name="remarks"></a>Comentários

Use este operador para inserir o conteúdo de um string_view em um fluxo de saída, por exemplo, usando [std:: cout](iostream.md#cout).

## <a name="op_gt"> Operador</a>&gt;

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

*left*<br/>
Um objeto do tipo ou qualquer tipo de cadeia de caracteres conversíveis `basic_string_view` a ser comparado.

*right*<br/>
Um objeto do tipo ou qualquer tipo de cadeia de caracteres conversíveis `basic_string_view` a ser comparado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o objeto no lado esquerdo do operador é lexicograficamente maior que o objeto string_view no lado direito; caso contrário **falso**.

### <a name="remarks"></a>Comentários

Ver [operador&lt;](#op_lt).

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

*left*<br/>
Um objeto do tipo ou qualquer tipo de cadeia de caracteres conversíveis `basic_string_view` a ser comparado.

*right*<br/>
Um objeto do tipo ou qualquer tipo de cadeia de caracteres conversíveis `basic_string_view` a ser comparado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o objeto no lado esquerdo do operador é lexicograficamente maior que ou igual ao objeto no lado direito; caso contrário **falso**.

### <a name="remarks"></a>Comentários

Ver [operador&lt;](#op_lt).

## <a name="op_sv"></a> operador"" sv (string_view literal)

Constrói um string_view de um literal de cadeia de caracteres. Requer o namespace `std::literals::string_view_literals`. 

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

[\<string_view>](../standard-library/string-view.md)<br/>
