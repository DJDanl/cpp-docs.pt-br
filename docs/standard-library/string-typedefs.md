---
title: '&lt;string&gt; typedefs'
ms.date: 11/04/2016
f1_keywords:
- string/std::string
- string/std::u16string
- string/std::u32string
- string/std::wstring
ms.assetid: fdca01e9-f2f1-4b59-abda-0093d760b3cc
ms.openlocfilehash: 1ee36d67d137c74e17fff845f9d412b2673f311e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376632"
---
# <a name="ltstringgt-typedefs"></a>&lt;string&gt; typedefs

||||
|-|-|-|
|[cadeia de caracteres](#string)|[u16string](#u16string)|[u32string](#u32string)|
|[wstring](#wstring)|

## <a name="string"></a>Cadeia de caracteres <a name="string"></a>

Um tipo que descreve uma especialização do modelo de classe [basic_string](../standard-library/basic-string-class.md) com elementos de **tipo char**.

Outros typedefs que especializam `basic_string` incluem [wstring](../standard-library/string-typedefs.md#wstring), [u16string](../standard-library/string-typedefs.md#u16string) e [u32string](../standard-library/string-typedefs.md#u32string).

```cpp
typedef basic_string<char, char_traits<char>, allocator<char>> string;
```

### <a name="remarks"></a>Comentários

As declarações a seguir são equivalentes:

```cpp
string str("");

basic_string<char> str("");
```

Para obter uma lista de construtores de cadeia de caracteres, consulte [basic_string::basic_string](../standard-library/basic-string-class.md#basic_string).

## <a name="u16string"></a><a name="u16string"></a>u16string

Um tipo que descreve uma especialização [basic_string](../standard-library/basic-string-class.md) do modelo `char16_t`de classe basic_string com elementos do tipo .

Outros typedefs que especializam `basic_string` incluem [wstring](../standard-library/string-typedefs.md#wstring), [string](../standard-library/string-typedefs.md#string) e [u32string](../standard-library/string-typedefs.md#u32string).

```cpp
typedef basic_string<char16_t, char_traits<char16_t>, allocator<char16_t>> u16string;
```

### <a name="remarks"></a>Comentários

Para obter uma lista de construtores de cadeia de caracteres, consulte [basic_string::basic_string](../standard-library/basic-string-class.md#basic_string).

## <a name="u32string"></a><a name="u32string"></a>u32string

Um tipo que descreve uma especialização [basic_string](../standard-library/basic-string-class.md) do modelo `char32_t`de classe basic_string com elementos do tipo .

Outros typedefs que especializam `basic_string` incluem [string](../standard-library/string-typedefs.md#string), [u16string](../standard-library/string-typedefs.md#u16string) e [wstring](../standard-library/string-typedefs.md#wstring).

```cpp
typedef basic_string<char32_t, char_traits<char32_t>, allocator<char32_t>> u32string;
```

### <a name="remarks"></a>Comentários

Para obter uma lista de construtores de cadeia de caracteres, consulte [basic_string::basic_string](../standard-library/basic-string-class.md#basic_string).

## <a name="wstring"></a><a name="wstring"></a>Wstring

Um tipo que descreve uma especialização do modelo de classe [basic_string](../standard-library/basic-string-class.md) com elementos de **tipo wchar_t**.

Outros typedefs que especializam `basic_string` incluem [string](../standard-library/string-typedefs.md#string), [u16string](../standard-library/string-typedefs.md#u16string) e [u32string](../standard-library/string-typedefs.md#u32string).

```cpp
typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t>> wstring;
```

### <a name="remarks"></a>Comentários

As declarações a seguir são equivalentes:

```cpp
wstring wstr(L"");

basic_string<wchar_t> wstr(L"");
```

Para obter uma lista de construtores de cadeia de caracteres, consulte [basic_string::basic_string](../standard-library/basic-string-class.md#basic_string).

> [!NOTE]
> O tamanho do **wchar_t** é definido pela implementação. Se o seu código depender **wchar_t** ser de um determinado tamanho, verifique `sizeof(wchar_t)`a implementação da sua plataforma (por exemplo, com ). Se você precisar de um tipo de caractere de cadeia com uma largura que garantidamente continuará a mesma em todas as plataformas, use [string](../standard-library/string-typedefs.md#string), [u16string](../standard-library/string-typedefs.md#u16string) ou [u32string](../standard-library/string-typedefs.md#u32string).

## <a name="see-also"></a>Confira também

[\<>de corda](../standard-library/string.md)
