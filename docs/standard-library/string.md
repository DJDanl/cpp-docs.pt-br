---
title: '&lt;cadeia de caracteres&gt;'
ms.date: 11/04/2016
f1_keywords:
- string/std::<string>
- <string>
helpviewer_keywords:
- string header
ms.assetid: a2fb9d00-d7ae-4170-bfea-2dc337aa37cf
ms.openlocfilehash: cb7d869d36bea6854e3eacbacb6dfad0c32a816f
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833174"
---
# <a name="ltstringgt"></a>&lt;cadeia de caracteres&gt;

Define o modelo de classe de contêiner `basic_string` e vários modelos de suporte.

Para obter mais informações sobre `basic_string`, consulte [basic_string Class](../standard-library/basic-string-class.md)

## <a name="syntax"></a>Sintaxe

```cpp
#include <string>
```

## <a name="remarks"></a>Comentários

A linguagem C++ e a biblioteca C++ padrão dão suporte a dois tipos de cadeias de caracteres:

- Matrizes de caracteres com terminação nula geralmente conhecidas como cadeias de caracteres C.

- objetos de modelo de classe, do tipo `basic_string` , que manipulam **`char`** argumentos de modelo semelhantes.

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[cadeia de caracteres](../standard-library/string-typedefs.md#string)|Um tipo que descreve uma especialização do modelo de classe `basic_string` com elementos do tipo **`char`** como um `string` .|
|[wstring](../standard-library/string-typedefs.md#wstring)|Um tipo que descreve uma especialização do modelo de classe `basic_string` com elementos do tipo **`wchar_t`** como um `wstring` .|
|[u16string](../standard-library/string-typedefs.md#u16string)|Um tipo que descreve uma especialização do modelo de classe `basic_string` com base em elementos do tipo **`char16_t`** .|
|[u32string](../standard-library/string-typedefs.md#u32string)|Um tipo que descreve uma especialização do modelo de classe `basic_string` com base em elementos do tipo **`char32_t`** .|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador +](../standard-library/string-operators.md#op_add)|Concatena dois objetos de cadeia de caracteres.|
|[operador! =](../standard-library/string-operators.md#op_neq)|Testa se o objeto da cadeia de caracteres à esquerda do operador é diferente do objeto da cadeia de caracteres à direita.|
|[operador = =](../standard-library/string-operators.md#op_eq_eq)|Testa se o objeto da cadeia de caracteres à esquerda do operador é igual ao objeto da cadeia de caracteres à direita.|
|[<do operador ](../standard-library/string-operators.md#op_lt)|Testa se o objeto da cadeia de caracteres à esquerda do operador é menor que o objeto da cadeia de caracteres à direita.|
|[<do operador =](../standard-library/string-operators.md#op_lt_eq)|Testa se o objeto da cadeia de caracteres à esquerda do operador é menor que ou igual ao objeto da cadeia de caracteres à direita.|
|[<do operador \<](../standard-library/string-operators.md#op_lt_lt)|Uma função de modelo que insere uma cadeia de caracteres no fluxo de saída.|
|[>do operador ](../standard-library/string-operators.md#op_gt)|Testa se o objeto da cadeia de caracteres à esquerda do operador é maior que o objeto da cadeia de caracteres à direita.|
|[>do operador =](../standard-library/string-operators.md#op_gt_eq)|Testa se o objeto da cadeia de caracteres à esquerda do operador é maior que ou igual ao objeto da cadeia de caracteres à direita.|
|[>>do operador ](../standard-library/string-operators.md#op_gt_gt)|Uma função de modelo que extrai uma cadeia de caracteres do fluxo de entrada.|

### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas

|Nome|Descrição|
|-|-|
|`hash`|Produz um hash de uma cadeia de caracteres.|
|[permuta](../standard-library/string-functions.md#swap)|Troca as matrizes de caracteres de duas cadeias de caracteres.|
|[stod](../standard-library/string-functions.md#stod)|Converte uma sequência de caracteres em um **`double`** .|
|[stof](../standard-library/string-functions.md#stof)|Converte uma sequência de caracteres em um **`float`** .|
|[stoi](../standard-library/string-functions.md#stoi)|Converte uma sequência de caracteres em um número inteiro.|
|[stold](../standard-library/string-functions.md#stold)|Converte uma sequência de caracteres em um **`long double`** .|
|[stoll](../standard-library/string-functions.md#stoll)|Converte uma sequência de caracteres em um **`long long`** .|
|[stoul](../standard-library/string-functions.md#stoul)|Converte uma sequência de caracteres em um **`unsigned long`** .|
|[stoull](../standard-library/string-functions.md#stoull)|Converte uma sequência de caracteres em um **`unsigned long long`** .|
|[to_string](../standard-library/string-functions.md#to_string)|Converte um valor em uma `string`.|
|[to_wstring](../standard-library/string-functions.md#to_wstring)|Converte um valor em uma `string` larga.|

### <a name="functions"></a>Funções

|Função|Descrição|
|-|-|
|[Modelo getline](../standard-library/string-functions.md#getline)|Extrai cadeias de caracteres do fluxo de entrada linha por linha.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[Classe basic_string](../standard-library/basic-string-class.md)|Um modelo de classe que descreve objetos que podem armazenar uma sequência de objetos arbitrários do tipo caractere.|
|[char_traits struct](../standard-library/char-traits-struct.md)|Um modelo de classe que descreve os atributos associados a um caractere do tipo CharType|

### <a name="specializations"></a>Especializações

|Nome|Descrição|
|-|-|
|[char_traits \<char> struct](../standard-library/char-traits-char-struct.md)|Uma struct que é uma especialização do struct do modelo `char_traits` \<CharType> para um elemento do tipo **`char`** .|
|[char_traits<wchar_t struct>](../standard-library/char-traits-wchar-t-struct.md)|Uma struct que é uma especialização do struct do modelo `char_traits` \<CharType> para um elemento do tipo **`wchar_t`** .|
|[char_traits<char16_t struct>](../standard-library/char-traits-char16-t-struct.md)|Uma struct que é uma especialização do struct do modelo `char_traits` \<CharType> para um elemento do tipo **`char16_t`** .|
|[char_traits<char32_t struct>](../standard-library/char-traits-char32-t-struct.md)|Uma struct que é uma especialização do struct do modelo `char_traits` \<CharType> para um elemento do tipo **`char32_t`** .|

## <a name="requirements"></a>Requisitos

- **Cabeçalho:**\<string>

- **Namespace:** std

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
