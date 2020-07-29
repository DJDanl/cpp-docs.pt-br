---
title: Limites de inteiro
ms.date: 01/29/2018
helpviewer_keywords:
- integral limits
- limits, integer
- limits.h header file
- integer limits
ms.assetid: 6922bdbf-0f49-443b-bc03-ee182e4cbd57
ms.openlocfilehash: a113dd687e6f135af950f461e024b9fd9feaf1b5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213379"
---
# <a name="integer-limits"></a>Limites de inteiro

**Específico da Microsoft**

Os limites para tipos de inteiros estão listadas na tabela a seguir. As macros de pré-processador para esses limites também são definidas quando você inclui o arquivo de cabeçalho padrão \<climits> .

## <a name="limits-on-integer-constants"></a>Limites em constantes de inteiro

| Constante | Significado | Valor |
|--|--|--|
| `CHAR_BIT` | Número de bits na menor variável que não é um campo de bit. | 8 |
| `SCHAR_MIN` | Valor mínimo para uma variável do tipo **`signed char`** . | -128 |
| `SCHAR_MAX` | Valor máximo para uma variável do tipo **`signed char`** . | 127 |
| `UCHAR_MAX` | Valor máximo para uma variável do tipo **`unsigned char`** . | 255 (0xff) |
| `CHAR_MIN` | Valor mínimo para uma variável do tipo **`char`** . | -128; 0 se a **`/J`** opção for usada |
| `CHAR_MAX` | Valor máximo para uma variável do tipo **`char`** . | 127; 255 se a **`/J`** opção for usada |
| `MB_LEN_MAX` | Número máximo de bytes em uma constante de vários caracteres. | 5 |
| `SHRT_MIN` | Valor mínimo para uma variável do tipo **`short`** . | -32768 |
| `SHRT_MAX` | Valor máximo para uma variável do tipo **`short`** . | 32767 |
| `USHRT_MAX` | Valor máximo para uma variável do tipo **`unsigned short`** . | 65535 (0xffff) |
| `INT_MIN` | Valor mínimo para uma variável do tipo **`int`** . | -2147483648 |
| `INT_MAX` | Valor máximo para uma variável do tipo **`int`** . | 2147483647 |
| `UINT_MAX` | Valor máximo para uma variável do tipo **`unsigned int`** . | 4294967295 (0xffffffff) |
| `LONG_MIN` | Valor mínimo para uma variável do tipo **`long`** . | -2147483648 |
| `LONG_MAX` | Valor máximo para uma variável do tipo **`long`** . | 2147483647 |
| `ULONG_MAX` | Valor máximo para uma variável do tipo **`unsigned long`** . | 4294967295 (0xffffffff) |
| `LLONG_MIN` | Valor mínimo para uma variável do tipo**`long long`** | -9223372036854775808 |
| `LLONG_MAX` | Valor máximo para uma variável do tipo**`long long`** | 9223372036854775807 |
| `ULLONG_MAX` | Valor máximo para uma variável do tipo**`unsigned long long`** | 18446744073709551615 (0xffffffffffffffff) |

Se um valor exceder a representação do maior inteiro, o compilador da Microsoft gera um erro.

## <a name="see-also"></a>Confira também

[Limites flutuantes](../cpp/floating-limits.md)
