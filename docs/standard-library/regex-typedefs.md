---
title: Typedefs &lt;regex&gt;
ms.date: 11/04/2016
f1_keywords:
- regex/std::cmatch
- regex/std::cregex_iterator
- regex/std::cregex_token_iterator
- regex/std::csub_match
- regex/std::regex
- regex/std::smatch
- regex/std::sregex_iterator
- regex/std::sregex_token_iterator
- regex/std::ssub_match
- regex/std::wcmatch
- regex/std::wcregex_iterator
- regex/std::wcregex_token_iterator
- regex/std::wcsub_match
- regex/std::wregex
- regex/std::wsmatch
- regex/std::wsregex_iterator
- regex/std::wsregex_token_iterator
- regex/std::wssub_match
ms.assetid: e6a69067-106c-4a24-9e08-7c867a3a2260
ms.openlocfilehash: 5dbda2df4877da7594dd633e9f203a3780b4adb1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368552"
---
# <a name="ltregexgt-typedefs"></a>Typedefs &lt;regex&gt;

||||
|-|-|-|
|[cmatch](#cmatch)|[cregex_iterator](#cregex_iterator)|[cregex_token_iterator](#cregex_token_iterator)|
|[csub_match](#csub_match)|[Regex](#regex)|[smatch](#smatch)|
|[sregex_iterator](#sregex_iterator)|[sregex_token_iterator](#sregex_token_iterator)|[ssub_match](#ssub_match)|
|[wcmatch](#wcmatch)|[wcregex_iterator](#wcregex_iterator)|[wcregex_token_iterator](#wcregex_token_iterator)|
|[wcsub_match](#wcsub_match)|[wregex](#wregex)|[wsmatch](#wsmatch)|
|[wsregex_iterator](#wsregex_iterator)|[wsregex_token_iterator](#wsregex_token_iterator)|[wssub_match](#wssub_match)|

## <a name="cmatch-typedef"></a><a name="cmatch"></a>cmatch Typedef

Definição de tipo para char match_results.

```cpp
typedef match_results<const char*> cmatch;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `const char*`match_results [Classe](../standard-library/match-results-class.md) para iteradores do tipo .

## <a name="cregex_iterator-typedef"></a><a name="cregex_iterator"></a>cregex_iterator Typedef

Definição de tipo para char regex_iterator.

```cpp
typedef regex_iterator<const char*> cregex_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `const char*`regex_iterator [Classe](../standard-library/regex-iterator-class.md) para iteradores do tipo .

## <a name="cregex_token_iterator-typedef"></a><a name="cregex_token_iterator"></a>cregex_token_iterator Typedef

Definição de tipo para char regex_token_iterator

```cpp
typedef regex_token_iterator<const char*> cregex_token_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `const char*`regex_token_iterator [Classe](../standard-library/regex-token-iterator-class.md) para iteradores do tipo .

## <a name="csub_match-typedef"></a><a name="csub_match"></a>csub_match Typedef

Definição de tipo para char sub_match.

```cpp
typedef sub_match<const char*> csub_match;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `const char*`sub_match [Classe](../standard-library/sub-match-class.md) para iteradores do tipo .

## <a name="regex-typedef"></a><a name="regex"></a>Regex Typedef

Definição de tipo para char basic_regex.

```cpp
typedef basic_regex<char> regex;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe [basic_regex Classe](../standard-library/basic-regex-class.md) para elementos de **tipo char**.

> [!NOTE]
> Caracteres de bit alto terão resultados imprevisíveis com `regex`. Valores fora do intervalo de 0 a 127 podem resultar em um comportamento indefinido.

## <a name="smatch-typedef"></a><a name="smatch"></a>smatch Typedef

Definição de tipo para string match_results.

```cpp
typedef match_results<string::const_iterator> smatch;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `string::const_iterator`match_results [Classe](../standard-library/match-results-class.md) para iteradores do tipo .

## <a name="sregex_iterator-typedef"></a><a name="sregex_iterator"></a>sregex_iterator Typedef

Definição de tipo para string regex_iterator.

```cpp
typedef regex_iterator<string::const_iterator> sregex_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `string::const_iterator`regex_iterator [Classe](../standard-library/regex-iterator-class.md) para iteradores do tipo .

## <a name="sregex_token_iterator-typedef"></a><a name="sregex_token_iterator"></a>sregex_token_iterator Typedef

Definição de tipo para string regex_token_iterator.

```cpp
typedef regex_token_iterator<string::const_iterator> sregex_token_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `string::const_iterator`regex_token_iterator [Classe](../standard-library/regex-token-iterator-class.md) para iteradores do tipo .

## <a name="ssub_match-typedef"></a><a name="ssub_match"></a>ssub_match Typedef

Definição de tipo para sub_match de cadeia de caractere.

```cpp
typedef sub_match<string::const_iterator> ssub_match;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `string::const_iterator`sub_match [Classe](../standard-library/sub-match-class.md) para iteradores do tipo .

## <a name="wcmatch-typedef"></a><a name="wcmatch"></a>wcmatch Typedef

Definição de tipo para wchar_t match_results.

```cpp
typedef match_results<const wchar_t *> wcmatch;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `const wchar_t*`match_results [Classe](../standard-library/match-results-class.md) para iteradores do tipo .

## <a name="wcregex_iterator-typedef"></a><a name="wcregex_iterator"></a>wcregex_iterator Typedef

Definição de tipo para wchar_t regex_iterator.

```cpp
typedef regex_iterator<const wchar_t*> wcregex_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `const wchar_t*`regex_iterator [Classe](../standard-library/regex-iterator-class.md) para iteradores do tipo .

## <a name="wcregex_token_iterator-typedef"></a><a name="wcregex_token_iterator"></a>wcregex_token_iterator Typedef

Definição de tipo para wchar_t regex_token_iterator.

```cpp
typedef regex_token_iterator<const wchar_t*> wcregex_token_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `const wchar_t*`regex_token_iterator [Classe](../standard-library/regex-token-iterator-class.md) para iteradores do tipo .

## <a name="wcsub_match-typedef"></a><a name="wcsub_match"></a>wcsub_match Typedef

Definição de tipo para wchar_t sub_match.

```cpp
typedef sub_match<const wchar_t*> wcsub_match;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `const wchar_t*`sub_match [Classe](../standard-library/sub-match-class.md) para iteradores do tipo .

## <a name="wregex-typedef"></a><a name="wregex"></a>wregex Typedef

Definição de tipo para wchar_t basic_regex.

```cpp
typedef basic_regex<wchar_t> wregex;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe [basic_regex Classe](../standard-library/basic-regex-class.md) para elementos do tipo **wchar_t**.

## <a name="wsmatch-typedef"></a><a name="wsmatch"></a>wsmatch Typedef

Definição de tipo para wstring match_results.

```cpp
typedef match_results<wstring::const_iterator> wsmatch;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `wstring::const_iterator`match_results [Classe](../standard-library/match-results-class.md) para iteradores do tipo .

## <a name="wsregex_iterator-typedef"></a><a name="wsregex_iterator"></a>wsregex_iterator Typedef

Definição de tipo para wstring regex_iterator.

```cpp
typedef regex_iterator<wstring::const_iterator> wsregex_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `wstring::const_iterator`regex_iterator [Classe](../standard-library/regex-iterator-class.md) para iteradores do tipo .

## <a name="wsregex_token_iterator-typedef"></a><a name="wsregex_token_iterator"></a>wsregex_token_iterator Typedef

Definição de tipo para wstring regex_token_iterator.

```cpp
typedef regex_token_iterator<wstring::const_iterator> wsregex_token_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `wstring::const_iterator`regex_token_iterator [Classe](../standard-library/regex-token-iterator-class.md) para iteradores do tipo .

## <a name="wssub_match-typedef"></a><a name="wssub_match"></a>wssub_match Typedef

Definição de tipo para wstring sub_match.

```cpp
typedef sub_match<wstring::const_iterator> wssub_match;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe `wstring::const_iterator`sub_match [Classe](../standard-library/sub-match-class.md) para iteradores do tipo .

## <a name="see-also"></a>Confira também

[\<regex>](../standard-library/regex.md)\
[regex_constants](../standard-library/regex-constants-class.md)\
[Classe regex_error](../standard-library/regex-error-class.md)\
[\<funções de> regex](../standard-library/regex-functions.md)\
[regex_iterator](../standard-library/regex-iterator-class.md)\
[\<operadores de> regex](../standard-library/regex-operators.md)\
[classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)\
[Classe regex_traits](../standard-library/regex-traits-class.md)
