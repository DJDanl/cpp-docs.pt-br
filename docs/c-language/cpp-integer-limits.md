---
title: Limites de inteiro C e C++
ms.date: 10/21/2019
helpviewer_keywords:
- limits, integer
- limits, integer constants
- integer limits
ms.assetid: 0c23cbd6-29fb-4d9c-b689-5984e19748de
ms.openlocfilehash: 1484b43719696578be437909351e24a550ec9869
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217110"
---
# <a name="c-and-c-integer-limits"></a>Limites de inteiro C e C++

**Específico da Microsoft**

Os limites para tipos de inteiros em C e C++ são listados na tabela a seguir. Esses limites são definidos no arquivo de cabeçalho padrão C `<limits.h>` . O cabeçalho da biblioteca padrão C++ `<limits>` inclui o `<climits>` , que inclui o `<limits.h>` .

O Microsoft C também permite a declaração de variáveis inteiras de tamanho, que são tipos integrais de tamanho de 8, 16-, 32-ou 64 bits. Para obter mais informações sobre os inteiros de tamanho em C, consulte [tipos de inteiro de tamanho](../c-language/c-sized-integer-types.md).

## <a name="limits-on-integer-constants"></a>Limites em constantes de inteiro

|**Amortiza**|Significado|Valor|
|------------------|-------------|-----------|
|**CHAR_BIT**|Número de bits na menor variável que não é um campo de bit.|8|
|**SCHAR_MIN**|Valor mínimo para uma variável do tipo **`signed char`** .|-128|
|**SCHAR_MAX**|Valor máximo para uma variável do tipo **`signed char`** .|127|
|**UCHAR_MAX**|Valor máximo para uma variável do tipo **`unsigned char`** .|255 (0xff)|
|**CHAR_MIN**|Valor mínimo para uma variável do tipo **`char`** .|-128; 0 se a opção /J for usada|
|**CHAR_MAX**|Valor máximo para uma variável do tipo **`char`** .|127; 255 se a opção /J for usada|
|**MB_LEN_MAX**|Número máximo de bytes em uma constante de vários caracteres.|5|
|**SHRT_MIN**|Valor mínimo para uma variável do tipo **`short`** .|-32768|
|**SHRT_MAX**|Valor máximo para uma variável do tipo **`short`** .|32767|
|**USHRT_MAX**|Valor máximo para uma variável do tipo **`unsigned short`** .|65535 (0xffff)|
|**INT_MIN**|Valor mínimo para uma variável do tipo **`int`** .|-2147483647 - 1|
|**INT_MAX**|Valor máximo para uma variável do tipo **`int`** .|2147483647|
|**UINT_MAX**|Valor máximo para uma variável do tipo **`unsigned int`** .|4294967295 (0xffffffff)|
|**LONG_MIN**|Valor mínimo para uma variável do tipo **`long`** .|-2147483647 - 1|
|**LONG_MAX**|Valor máximo para uma variável do tipo **`long`** .|2147483647|
|**ULONG_MAX**|Valor máximo para uma variável do tipo **`unsigned long`** .|4294967295 (0xffffffff)|
|**LLONG_MIN**|Valor mínimo para uma variável do tipo **`long long`** .|-9.223.372.036.854.775.807-1|
|**LLONG_MAX**|Valor máximo para uma variável do tipo **`long long`** .|9,223,372,036,854,775,807|
|**ULLONG_MAX**|Valor máximo para uma variável do tipo **`unsigned long long`** .|18446744073709551615 (0xFFFFFFFFFFFFFFFF)|

Se um valor exceder a representação do maior inteiro, o compilador da Microsoft gera um erro.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Constantes de inteiro C](../c-language/c-integer-constants.md)
