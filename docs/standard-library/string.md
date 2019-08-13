---
title: '&lt;string&gt;'
ms.date: 11/04/2016
f1_keywords:
- string/std::<string>
- <string>
helpviewer_keywords:
- string header
ms.assetid: a2fb9d00-d7ae-4170-bfea-2dc337aa37cf
ms.openlocfilehash: 80d5d297cc28cfb019dae99e9e9736e4b2eb654f
ms.sourcegitcommit: 16c0392fc8d96e814c3a40b0c5346d7389aeb525
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/12/2019
ms.locfileid: "68957122"
---
# <a name="ltstringgt"></a>&lt;string&gt;

Define a classe de modelo do contêiner `basic_string` e diversos modelos de suporte.

Para obter mais informações sobre `basic_string`, consulte [basic_string Class](../standard-library/basic-string-class.md)

## <a name="syntax"></a>Sintaxe

```cpp
#include <string>
```

## <a name="remarks"></a>Comentários

A linguagem C++ e a biblioteca C++ padrão dão suporte a dois tipos de cadeias de caracteres:

- Matrizes de caracteres com terminação nula geralmente conhecidas como cadeias de caracteres C.

- Objetos de classe de modelo, `basic_string`do tipo, que lidam com todos os argumentos de modelo semelhantes a **caracteres**.

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[string](../standard-library/string-typedefs.md#string)|Um tipo que descreve uma especialização da classe `basic_string` de modelo com elementos do tipo **Char** como `string`um.|
|[wstring](../standard-library/string-typedefs.md#wstring)|Um tipo que descreve uma especialização da classe `basic_string` de modelo com elementos do tipo **wchar_t** como `wstring`um.|
|[u16string](../standard-library/string-typedefs.md#u16string)|Um tipo que descreve uma especialização da classe modelo `basic_string` com base em elementos do tipo `char16_t`.|
|[u32string](../standard-library/string-typedefs.md#u32string)|Um tipo que descreve uma especialização da classe modelo `basic_string` com base em elementos do tipo `char32_t`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator+](../standard-library/string-operators.md#op_add)|Concatena dois objetos de cadeia de caracteres.|
|[operator!=](../standard-library/string-operators.md#op_neq)|Testa se o objeto da cadeia de caracteres à esquerda do operador é diferente do objeto da cadeia de caracteres à direita.|
|[operator==](../standard-library/string-operators.md#op_eq_eq)|Testa se o objeto da cadeia de caracteres à esquerda do operador é igual ao objeto da cadeia de caracteres à direita.|
|[operator<](../standard-library/string-operators.md#op_lt)|Testa se o objeto da cadeia de caracteres à esquerda do operador é menor que o objeto da cadeia de caracteres à direita.|
|[operator<=](../standard-library/string-operators.md#op_lt_eq)|Testa se o objeto da cadeia de caracteres à esquerda do operador é menor que ou igual ao objeto da cadeia de caracteres à direita.|
|[operator<\<](../standard-library/string-operators.md#op_lt_lt)|Uma função de modelo que insere uma cadeia de caracteres no fluxo de saída.|
|[operator>](../standard-library/string-operators.md#op_gt)|Testa se o objeto da cadeia de caracteres à esquerda do operador é maior que o objeto da cadeia de caracteres à direita.|
|[operator>=](../standard-library/string-operators.md#op_gt_eq)|Testa se o objeto da cadeia de caracteres à esquerda do operador é maior que ou igual ao objeto da cadeia de caracteres à direita.|
|[operator>>](../standard-library/string-operators.md#op_gt_gt)|Uma função de modelo que extrai uma cadeia de caracteres do fluxo de entrada.|

### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas

|||
|-|-|
|hash|Produz um hash de uma cadeia de caracteres.|
|[swap](../standard-library/string-functions.md#swap)|Troca as matrizes de caracteres de duas cadeias de caracteres.|
|[stod](../standard-library/string-functions.md#stod)|Converte uma sequência de caracteres em um **duplo**.|
|[stof](../standard-library/string-functions.md#stof)|Converte uma sequência de caracteres em um **float**.|
|[stoi](../standard-library/string-functions.md#stoi)|Converte uma sequência de caracteres em um número inteiro.|
|[stold](../standard-library/string-functions.md#stold)|Converte uma sequência de caracteres em um **longo Duplo**.|
|[stoll](../standard-library/string-functions.md#stoll)|Converte uma sequência de caracteres em um **longo**tempo.|
|[stoul](../standard-library/string-functions.md#stoul)|Converte uma sequência de caracteres em um **longo não assinado**.|
|[stoull](../standard-library/string-functions.md#stoull)|Converte uma sequência de caracteres em um **longo tempo não assinado**.|
|[to_string](../standard-library/string-functions.md#to_string)|Converte um valor em uma `string`.|
|[to_wstring](../standard-library/string-functions.md#to_wstring)|Converte um valor em uma `string` larga.|

### <a name="functions"></a>Funções

|Função|Descrição|
|-|-|
|[Modelo getline](../standard-library/string-functions.md#getline)|Extrai cadeias de caracteres do fluxo de entrada linha por linha.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[Classe basic_string](../standard-library/basic-string-class.md)|Uma classe de modelo que descreve os objetos que pode armazenar uma sequência de objetos arbitrários do tipo caractere.|
|[Struct char_traits](../standard-library/char-traits-struct.md)|Uma classe de modelo que descreve os atributos associados a um caractere do tipo CharType|

### <a name="specializations"></a>Especializações

|||
|-|-|
|[char_traits\<char> Struct](../standard-library/char-traits-char-struct.md)|Um struct é uma especialização de struct modelo `char_traits`\<CharType> para um elemento do tipo `char`.|
|[Struct char_traits<wchar_t>](../standard-library/char-traits-wchar-t-struct.md)|Um struct é uma especialização de struct modelo `char_traits`\<CharType> para um elemento do tipo `wchar_t`.|
|[Struct char_traits<char16_t>](../standard-library/char-traits-char16-t-struct.md)|Um struct é uma especialização de struct modelo `char_traits`\<CharType> para um elemento do tipo `char16_t`.|
|[Struct char_traits<char32_t>](../standard-library/char-traits-char32-t-struct.md)|Um struct é uma especialização de struct modelo `char_traits`\<CharType> para um elemento do tipo `char32_t`.|

## <a name="requirements"></a>Requisitos

- **Cabeçalho:** \<string>

- **Namespace:** std

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
