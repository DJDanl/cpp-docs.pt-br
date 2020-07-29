---
title: Tipos internos (C++)
ms.date: 07/22/2020
f1_keywords:
- __int128_cpp
- __wchar_t_cpp
- char_cpp
- char8_t_cpp
- char16_t_cpp
- char32_t_cpp
- double_cpp
- float_cpp
- int_cpp
- long_cpp
- long_double_cpp
- short_cpp
- signed_cpp
- unsigned_cpp
- unsigned_int_cpp
- wchar_t_cpp
helpviewer_keywords:
- specifiers [C++], type
- float keyword [C++]
- char keyword [C++]
- __wchar_t keyword [C++]
- signed types [C++], summary of data types
- Integer data type [C++], C++ data types
- arithmetic operations [C++], types
- int data type
- unsigned types [C++], summary of data types
- short data type [C++]
- double data type [C++], summary of types
- long long keyword [C++]
- long double keyword [C++]
- unsigned types [C++]
- signed types [C++]
- void keyword [C++]
- storage [C++], basic type
- integral types, C++
- wchar_t keyword [C++]
- floating-point numbers [C++], C++ data types
- long keyword [C++]
- type specifiers [C++]
- integral types
- long keyword [C++]
- storing types [C++]
- data types [C++], void
ms.assetid: 58b0106a-0406-4b74-a430-7cbd315c0f89
ms.openlocfilehash: 73486dd4d81fc91007f078ec5c509bcb963d2706
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232268"
---
# <a name="built-in-types-c"></a>Tipos internos (C++)

Os tipos internos (também chamados de *tipos fundamentais*) são especificados pelo padrão de linguagem C++ e são criados no compilador. Os tipos internos não são definidos em nenhum arquivo de cabeçalho. Os tipos internos são divididos em três categorias principais: *integral*, *ponto flutuante*e *void*. Tipos integrais representam números inteiros. Tipos de ponto flutuante podem especificar valores que podem ter partes fracionárias. A maioria dos tipos internos são tratados como tipos distintos pelo compilador. No entanto, alguns tipos são *sinônimos*ou tratados como tipos equivalentes pelo compilador.

## <a name="void-type"></a>Tipo void

O [`void`](void-cpp.md) tipo descreve um conjunto vazio de valores. Nenhuma variável do tipo **`void`** pode ser especificada. O **`void`** tipo é usado principalmente para declarar funções que não retornam valores ou para declarar ponteiros genéricos para dados digitados de forma arbitrária ou sem tipo. Qualquer expressão pode ser convertida explicitamente ou converter em tipo **`void`** . No entanto, tais expressões estão restritas aos seguintes usos:

- Uma instrução de expressão. (Para obter mais informações, consulte [Expressions](expressions-cpp.md).)

- O operando esquerdo do operador vírgula. (Para obter mais informações, consulte [operador de vírgula](comma-operator.md).)

- O segundo ou terceiro operando do operador condicional ( `? :` ). (Para obter mais informações, consulte [expressões com o operador condicional](conditional-operator-q.md).)

## <a name="stdnullptr_t"></a>std:: nullptr_t

A palavra-chave **`nullptr`** é uma constante de ponteiro nulo do tipo `std::nullptr_t` , que é conversível para qualquer tipo de ponteiro bruto. Para obter mais informações, consulte [`nullptr`](nullptr.md).

## <a name="boolean-type"></a>Tipo booliano

O [`bool`](bool-cpp.md) tipo pode ter valores [`true`](../cpp/true-cpp.md) e [`false`](../cpp/false-cpp.md) . O tamanho do **`bool`** tipo é específico da implementação. Consulte [tamanhos de tipos internos](#sizes-of-built-in-types) para obter detalhes de implementação específicos da Microsoft.

## <a name="character-types"></a>Tipos de caractere

O **`char`** tipo é um tipo de representação de caractere que codifica com eficiência os membros do conjunto de caracteres de execução básico. O compilador C++ trata variáveis do tipo **`char`** , **`signed char`** e **`unsigned char`** como tendo tipos diferentes.

**Específico da Microsoft**: variáveis do tipo **`char`** são promovidas para **`int`** como If do tipo **`signed char`** por padrão, a menos que a [`/J`](../build/reference/j-default-char-type-is-unsigned.md) opção de compilação seja usada. Nesse caso, eles são tratados como tipo **`unsigned char`** e são promovidos para **`int`** sem extensão de assinatura.

Uma variável do tipo **`wchar_t`** é um tipo de caractere largo ou multibyte. Use o **`L`** prefixo antes de um literal de caractere ou de cadeia de caracteres para especificar o tipo de caractere largo.

**Específico da Microsoft**: por padrão, **`wchar_t`** é um tipo nativo, mas você pode usar [`/Zc:wchar_t-`](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para criar **`wchar_t`** um typedef para **`unsigned short`** . O **`__wchar_t`** tipo é um sinônimo específico da Microsoft para o **`wchar_t`** tipo nativo.

O **`char8_t`** tipo é usado para a representação de caracteres UTF-8. Ele tem a mesma representação que **`unsigned char`** , mas é tratado como um tipo distinto pelo compilador. O **`char8_t`** tipo é novo no c++ 20. **Específico da Microsoft**: o uso de **`char8_t`** requer a [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md) opção de compilador.

O **`char16_t`** tipo é usado para a representação de caracteres UTF-16. Ele deve ser grande o suficiente para representar qualquer unidade de código UTF-16. Ele é tratado como um tipo distinto pelo compilador.

O **`char32_t`** tipo é usado para a representação de caractere UTF-32. Ele deve ser grande o suficiente para representar qualquer unidade de código UTF-32. Ele é tratado como um tipo distinto pelo compilador.

## <a name="floating-point-types"></a>Tipos de ponto flutuante

Os tipos de ponto flutuante usam uma representação IEEE-754 para fornecer uma aproximação de valores fracionários em uma ampla gama de magnitudes. A tabela a seguir lista os tipos de ponto flutuante em C++ e as restrições comparativa em tamanhos de tipo de ponto flutuante. Essas restrições são obrigatórias pelo padrão C++ e são independentes da implementação da Microsoft. O tamanho absoluto dos tipos de ponto flutuante internos não é especificado no padrão.

| Type | Sumário |
|--|--|
| **`float`** | Type **`float`** é o menor tipo de ponto flutuante em C++. |
| **`double`** | Type **`double`** é um tipo de ponto flutuante que é maior ou igual ao tipo **`float`** , mas menor que ou igual ao tamanho do tipo **`long double`** . |
| **`long double`** | Type **`long double`** é um tipo de ponto flutuante que é maior ou igual ao tipo **`double`** . |

**Específico da Microsoft**: a representação de **`long double`** e **`double`** é idêntica. No entanto, **`long double`** e **`double`** são tratados como tipos distintos pelo compilador. O compilador do Microsoft C++ usa as representações de ponto flutuante de 4 e 8 bytes IEEE-754. Para obter mais informações, consulte [representação de ponto flutuante IEEE](../build/ieee-floating-point-representation.md).

## <a name="integer-types"></a>Tipos de inteiro

O **`int`** tipo é o tipo de inteiro básico padrão. Ele pode representar todos os números inteiros em um intervalo específico de implementação.

Uma representação de inteiro *assinada* é aquela que pode conter valores positivos e negativos. Ele é usado por padrão ou quando a **`signed`** palavra-chave do modificador está presente. A **`unsigned`** palavra-chave modificador especifica uma representação não *assinada* que só pode conter valores não negativos.

Um modificador de tamanho especifica a largura em bits da representação de inteiro usada. O idioma dá suporte a **`short`** **`long`** **`long long`** modificadores, e. Um **`short`** tipo deve ter pelo menos 16 bits de largura. Um **`long`** tipo deve ter pelo menos 32 bits de largura. Um **`long long`** tipo deve ter pelo menos 64 bits de largura. O padrão especifica uma relação de tamanho entre os tipos integrais:

`1 == sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)`

Uma implementação deve manter os requisitos de tamanho mínimo e a relação de tamanho para cada tipo. No entanto, os tamanhos reais podem e variam entre as implementações. Consulte [tamanhos de tipos internos](#sizes-of-built-in-types) para obter detalhes de implementação específicos da Microsoft.

A **`int`** palavra-chave pode ser omitida quando os **`signed`** **`unsigned`** modificadores de tamanho, ou são especificados. Os modificadores e o **`int`** tipo, se presentes, podem aparecer em qualquer ordem. Por exemplo, **`short unsigned`** e **`unsigned int short`** se referem ao mesmo tipo.

### <a name="integer-type-synonyms"></a>Sinônimos de tipo Integer

Os seguintes grupos de tipos são considerados sinônimos pelo compilador:

- **`short`**, **`short int`**, **`signed short`**, **`signed short int`**

- **`unsigned short`**, **`unsigned short int`**

- **`int`**, **`signed`**, **`signed int`**

- **`unsigned`**, **`unsigned int`**

- **`long`**, **`long int`**, **`signed long`**, **`signed long int`**

- **`unsigned long`**, **`unsigned long int`**

- **`long long`**, **`long long int`**, **`signed long long`**, **`signed long long int`**

- **`unsigned long long`**, **`unsigned long long int`**

Os tipos inteiros **específicos da Microsoft** incluem os tipos de largura específica **`__int8`** ,, **`__int16`** **`__int32`** e **`__int64`** . Esses tipos podem usar os **`signed`** **`unsigned`** modificadores e. O **`__int8`** tipo de dados é sinônimo de tipo **`char`** , **`__int16`** é sinônimo de tipo **`short`** , **`__int32`** é sinônimo de tipo **`int`** e **`__int64`** é sinônimo de tipo **`long long`** .

## <a name="sizes-of-built-in-types"></a>Tamanhos de tipos internos

A maioria dos tipos internos tem tamanhos definidos pela implementação. A tabela a seguir lista a quantidade de armazenamento necessária para tipos internos no Microsoft C++. Em particular, o **`long`** é de 4 bytes até mesmo em sistemas operacionais de 64 bits.

| Type | Tamanho |
|--|--|
| **`bool`**, **`char`**, **`char8_t`**, **`unsigned char`**, **`signed char`**, **`__int8`** | 1 byte |
| **`char16_t`**, **`__int16`**, **`short`**, **`unsigned short`**, **`wchar_t`**, **`__wchar_t`** | 2 bytes |
| **`char32_t`**, **`float`**, **`__int32`**, **`int`**, **`unsigned int`**, **`long`**, **`unsigned long`** | 4 bytes |
| **`double`**, **`__int64`**, **`long double`**, **`long long`**, **`unsigned long long`** | 8 bytes |

Consulte [intervalos de tipos de dados](data-type-ranges.md) para obter um resumo do intervalo de valores de cada tipo.

Para obter mais informações sobre conversão de tipo, consulte [conversões padrão](standard-conversions.md).

## <a name="see-also"></a>Confira também

[Intervalos de tipos de dados](data-type-ranges.md)
