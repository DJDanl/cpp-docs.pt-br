---
title: Constantes de tipo de dados
ms.date: 06/25/2018
f1_keywords:
- FLT_MIN
- SHRT_MAX
- CHAR_MIN
- MB_LEN_MAX
- DBL_EPSILON
- SHRT_MIN
- _FLT_RADIX
- FLT_DIG
- FLT_MAX_10_EXP
- FLT_MANT_DIG
- DBL_MAX_EXP
- SCHAR_MIN
- SCHAR_MAX
- DBL_MIN
- FLT_MIN_10_EXP
- _DBL_ROUNDS
- USHRT_MAX
- FLT_MAX_EXP
- LONG_MAX
- DBL_MAX
- DBL_DIG
- FLT_MIN_EXP
- INT_MIN
- DBL_MIN_10_EXP
- CHAR_BIT
- INT_MAX
- ULONG_MAX
- DBL_MIN_EXP
- LONG_MIN
- _FLT_ROUNDS
- DBL_MANT_DIG
- _DBL_RADIX
- CHAR_MAX
- FLT_MAX
- DBL_MAX_10_EXP
- UCHAR_MAX
- FLT_EPSILON
- UINT_MAX
- LLONG_MIN
- LLONG_MAX
- ULLONG_MAX
- _I8_MIN
- _I8_MAX
- _UI8_MAX
- _I16_MIN
- _I16_MAX
- _UI16_MAX
- _I32_MIN
- _I32_MAX
- _UI32_MAX
- _I64_MIN
- _I64_MAX
- _UI64_MAX
- _I128_MIN
- _I128_MAX
- _UI128_MAX
- SIZE_MAX
- RSIZE_MAX
- LDBL_DIG
- LDBL_EPSILON
- LDBL_HAS_SUBNORM
- LDBL_MANT_DIG
- LDBL_MAX
- LDBL_MAX_10_EXP
- LDBL_MAX_EXP
- LDBL_MIN
- LDBL_MIN_10_EXP
- LDBL_MIN_EXP
- _LDBL_RADIX
- LDBL_TRUE_MIN
- DECIMAL_DIG
helpviewer_keywords:
- DBL_MAX_EXP constant
- _DBL_RADIX constant
- FLT_MIN_EXP constant
- DBL_EPSILON constant
- INT_MIN constant
- FLT_EPSILON constant
- DBL_MANT_DIG constant
- _FLT_RADIX constant
- DBL_MIN constant
- USHRT_MAX constant
- FLT_MAX_10_EXP constant
- _FLT_ROUNDS constant
- data type constants [C++]
- _DBL_ROUNDS constant
- CHAR_MAX constant
- FLT_MAX_EXP constant
- FLT_MIN constant
- CHAR_MIN constant
- FLT_MIN_10_EXP constant
- DBL_MIN_EXP constant
- SCHAR_MAX constant
- FLT_RADIX constant
- CHAR_BIT constant
- UCHAR_MAX constant
- DBL_RADIX constant
- FLT_ROUNDS constant
- LONG_MIN constant
- SHRT_MAX constant
- LONG_MAX constant
- DBL_MAX_10_EXP constant
- DBL_MIN_10_EXP constant
- INT_MAX constant
- constants [C++], data type
- ULONG_MAX constant
- FLT_DIG constant
- MB_LEN_MAX constant
- DBL_DIG constant
- SHRT_MIN constant
- DBL_MAX constant
- DBL_ROUNDS constant
- FLT_MAX constant
- UINT_MAX constant
- FLT_MANT_DIG constant
- SCHAR_MIN constant
- LLONG_MIN constant
- LLONG_MAX constant
- ULLONG_MAX constant
- _I8_MIN constant
- _I8_MAX constant
- _UI8_MAX constant
- _I16_MIN constant
- _I16_MAX constant
- _UI16_MAX constant
- _I32_MIN constant
- _I32_MAX constant
- _UI32_MAX constant
- _I64_MIN constant
- _I64_MAX constant
- _UI64_MAX constant
- _I128_MIN constant
- _I128_MAX constant
- _UI128_MAX constant
- SIZE_MAX constant
- RSIZE_MAX constant
ms.assetid: c0f1c405-0465-41d5-b5ff-e81cdb6f1622
ms.openlocfilehash: c4ffbf294083131f29ffe957fd0434182fbb8f99
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50636924"
---
# <a name="data-type-constants"></a>Constantes de tipo de dados

Constantes de tipo de dados são intervalos de valores dependentes de implementação permitidos para tipos de dados integrais e de ponto flutuante.

## <a name="integral-type-constants"></a>Constantes de tipo integral

Essas constantes oferecem os intervalos para os tipos de dados integrais. Para usar essas constantes, inclua o cabeçalho limits.h em seu arquivo de origem:

```C
#include <limits.h>
```

> [!NOTE]
> A opção do compilador [/J](../build/reference/j-default-char-type-is-unsigned.md) altera o tipo padrão **char** para **sem sinal**.

|Constante|Valor|Descrição|
|--------------|-----------|-------------|
|**CHAR_BIT**|8|O número de bits em um **char**|
|**SCHAR_MIN**|(-128)|Valor mínimo de **char** com sinal|
|**SCHAR_MAX**|127|Valor máximo de **char** com sinal|
|**UCHAR_MAX**|255 (0xff)|Valor máximo de **char** **sem sinal**|
|**CHAR_MIN**|(-128) (0 se a opção **/J** for usada)|Valor mínimo de **char**|
|**CHAR_MAX**|127 (255 se a opção **/J** for usada)|Valor máximo de **char**|
|**MB_LEN_MAX**|5|O número máximo de bytes em um multibyte **char**|
|**SHRT_MIN**|-32768|Valor **short** mínimo com sinal|
|**SHRT_MAX**|32767|Valor **short** máximo com sinal|
|**USHRT_MAX**|65535 (0xffff)|Valor **short** máximo **sem sinal**|
|**INT_MIN**|(-2147483647 - 1)|Valor **int** mínimo com sinal|
|**INT_MAX**|2147483647|Valor **int** máximo com sinal|
|**UINT_MAX**|4294967295 (0xffffffff)|Valor **int** máximo **sem sinal**|
|**LONG_MIN**|(-2147483647L - 1)|Valor **long** mínimo com sinal|
|**LONG_MAX**|2147483647L|Valor **long** máximo com sinal|
|**ULONG_MAX**|4294967295UL (0xfffffffful)|Valor **long** máximo **sem sinal**|
|**LLONG_MIN**|(-9223372036854775807LL - 1)|Valor mínimo **long** **long** ou **__int64** com sinal|
|**LLONG_MAX**|9223372036854775807LL|Valor máximo **long** **long** ou **__int64** com sinal|
|**ULLONG_MAX**|0xffffffffffffffffull|Valor **long** **long** máximo **sem sinal**|
|**_I8_MIN**|(-127i8 - 1)|Valor mínimo de 8 bits com sinal|
|**_I8_MAX**|127i8|Valor máximo de 8 bits com sinal|
|**_UI8_MAX**|0xffui8|Valor máximo de 8 bits sem sinal|
|**_I16_MIN**|(-32767i16 - 1)|Valor mínimo de 16 bits com sinal|
|**_I16_MAX**|32767i16|Valor máximo de 16 bits com sinal|
|**_UI16_MAX**|0xffffui16|Valor máximo de 16 bits sem sinal|
|**_I32_MIN**|(-2147483647i32 - 1)|Valor mínimo de 32 bits com sinal|
|**_I32_MAX**|2147483647i32|Valor máximo de 32 bits com sinal|
|**_UI32_MAX**|0xffffffffui32|Valor máximo de 32 bits sem sinal|
|**_I64_MIN**|(-9223372036854775807 - 1)|Valor mínimo de 64 bits com sinal|
|**_I64_MAX**|9223372036854775807|Valor máximo de 64 bits com sinal|
|**_UI64_MAX**|0xffffffffffffffffui64|Valor máximo de 64 bits sem sinal|
|**_I128_MIN**|(-170141183460469231731687303715884105727i128 - 1)|Valor mínimo de 128 bits com sinal|
|**_I128_MAX**|170141183460469231731687303715884105727i128|Valor máximo de 128 bits com sinal|
|**_UI128_MAX**|0xffffffffffffffffffffffffffffffffui128|Valor máximo de 128 bits sem sinal|
|**SIZE_MAX**|igual a **_UI64_MAX** se **_WIN64** for definido ou **UINT_MAX**|Tamanho máximo de inteiro nativo|
|**RSIZE_MAX**|igual a (**SIZE_MAX** >> 1)|Tamanho de inteiro máximo de biblioteca segura|

## <a name="floating-point-type-constants"></a>Constantes de tipo de ponto flutuante

As constantes a seguir fornecem o intervalo e outras características dos tipos de dados **long** **double**, **double** e **float**. Para usar essas constantes, inclua o cabeçalho float.h em seu arquivo de origem:

```C
#include <float.h>
```

|Constante|Valor|Descrição|
|--------------|-----------|-----------------|
|**DBL_DECIMAL_DIG**|17|Nº de dígitos decimais de precisão de arredondamento|
|**DBL_DIG**|15|Nº de casas decimais de precisão|
|**DBL_EPSILON**|2.2204460492503131e-016|O menor valor, de forma que 1,0 + **DBL_EPSILON** != 1,0|
|**DBL_HAS_SUBNORM**|1|Tipo é compatível com números subnormais (desnormalizados)|
|**DBL_MANT_DIG**|53|n º de bits no significando (mantissa)|
|**DBL_MAX**|1.7976931348623158e+308|Valor máximo|
|**DBL_MAX_10_EXP**|308|Expoente decimal máximo|
|**DBL_MAX_EXP**|1024|Expoente binário máximo|
|**DBL_MIN**|2.2250738585072014e-308|Valor mínimo normalizado positivo|
|**DBL_MIN_10_EXP**|(-307)|Expoente decimal mínimo|
|**DBL_MIN_EXP**|(-1021)|Expoente binário mínimo|
|**_DBL_RADIX**|2|Expoente base|
|**DBL_TRUE_MIN**|4,9406564584124654e-324|Valor mínimo subnormal positivo|
|**FLT_DECIMAL_DIG**|9|Número de dígitos decimais de precisão do arredondamento|
|**FLT_DIG**|6|Número de dígitos decimais de precisão|
|**FLT_EPSILON**|1.192092896e-07F|O menor valor, de forma que 1,0 + **FLT_EPSILON** != 1,0|
|**FLT_HAS_SUBNORM**|1|Tipo é compatível com números subnormais (desnormalizados)|
|**FLT_MANT_DIG**|24|Número de bits no significando (mantissa)|
|**FLT_MAX**|3.402823466e+38F|Valor máximo|
|**FLT_MAX_10_EXP**|38|Expoente decimal máximo|
|**FLT_MAX_EXP**|128|Expoente binário máximo|
|**FLT_MIN**|1.175494351e-38F|Valor mínimo normalizado positivo|
|**FLT_MIN_10_EXP**|(-37)|Expoente decimal mínimo|
|**FLT_MIN_EXP**|(-125)|Expoente binário mínimo|
|**FLT_RADIX**|2|Expoente base|
|**FLT_TRUE_MIN**|1,401298464e-45F|Valor mínimo subnormal positivo|
|**LDBL_DIG**|15|Nº de casas decimais de precisão|
|**LDBL_EPSILON**|2.2204460492503131e-016|O menor valor, de forma que 1,0 + **LDBL_EPSILON** != 1,0|
|**LDBL_HAS_SUBNORM**|1|Tipo é compatível com números subnormais (desnormalizados)|
|**LDBL_MANT_DIG**|53|n º de bits no significando (mantissa)|
|**LDBL_MAX**|1.7976931348623158e+308|Valor máximo|
|**LDBL_MAX_10_EXP**|308|Expoente decimal máximo|
|**LDBL_MAX_EXP**|1024|Expoente binário máximo|
|**LDBL_MIN**|2.2250738585072014e-308|Valor mínimo normalizado positivo|
|**LDBL_MIN_10_EXP**|(-307)|Expoente decimal mínimo|
|**LDBL_MIN_EXP**|(-1021)|Expoente binário mínimo|
|**_LDBL_RADIX**|2|Expoente base|
|**LDBL_TRUE_MIN**|4,9406564584124654e-324|Valor mínimo subnormal positivo|
|**DECIMAL_DIG**|igual a **DBL_DECIMAL_DIG**|Padrão (duplo) de casas decimais de precisão de arredondamento|

## <a name="see-also"></a>Consulte também

[Constantes globais](../c-runtime-library/global-constants.md)
