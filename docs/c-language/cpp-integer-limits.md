---
title: Limites de inteiro C e C++
ms.date: 10/21/2019
helpviewer_keywords:
- limits, integer
- limits, integer constants
- integer limits
ms.assetid: 0c23cbd6-29fb-4d9c-b689-5984e19748de
ms.openlocfilehash: 6940f36e37ec58ca8fe23c9062928cbf90b125bd
ms.sourcegitcommit: ea9d78dbb93bf3f8841dde93dbc12bd66f6f32ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/22/2019
ms.locfileid: "72778370"
---
# <a name="c-and-c-integer-limits"></a>Limites de inteiro C e C++

**Específico da Microsoft**

Os limites para tipos de inteiros em C e C++ são listados na tabela a seguir. Esses limites são definidos no arquivo `<limits.h>`de cabeçalho padrão C. O cabeçalho `<limits>` da biblioteca padrão C++ `<climits>`inclui o, `<limits.h>`que inclui o.

O Microsoft C também permite a declaração de variáveis inteiras de tamanho, que são tipos integrais de tamanho de 8, 16-, 32-ou 64 bits. Para obter mais informações sobre os inteiros de tamanho em C, consulte [tipos de inteiro de tamanho](../c-language/c-sized-integer-types.md).

## <a name="limits-on-integer-constants"></a>Limites em constantes de inteiro

|**Amortiza**|Significado|Valor|
|------------------|-------------|-----------|
|**CHAR_BIT**|Número de bits na menor variável que não é um campo de bit.|8|
|**SCHAR_MIN**|Valor mínimo para uma variável do tipo **signed char**.|-128|
|**SCHAR_MAX**|Valor máximo para uma variável do tipo **signed char**.|127|
|**UCHAR_MAX**|Valor máximo para uma variável do tipo **unsigned char**.|255 (0xff)|
|**CHAR_MIN**|Valor mínimo para uma variável do tipo **char**.|-128; 0 se a opção /J for usada|
|**CHAR_MAX**|Valor máximo para uma variável do tipo **char**.|127; 255 se a opção /J for usada|
|**MB_LEN_MAX**|Número máximo de bytes em uma constante de vários caracteres.|5|
|**SHRT_MIN**|Valor mínimo para uma variável do tipo **short**.|-32768|
|**SHRT_MAX**|Valor máximo para uma variável do tipo **short**.|32767|
|**USHRT_MAX**|Valor máximo para uma variável do tipo **unsigned short**.|65535 (0xffff)|
|**INT_MIN**|Valor mínimo para uma variável do tipo **int**.|-2147483647 - 1|
|**INT_MAX**|Valor máximo para uma variável do tipo **int**.|2147483647|
|**UINT_MAX**|Valor máximo para uma variável do tipo **unsigned int**.|4294967295 (0xffffffff)|
|**LONG_MIN**|Valor mínimo para uma variável do tipo **long**.|-2147483647 - 1|
|**LONG_MAX**|Valor máximo para uma variável do tipo **long**.|2147483647|
|**ULONG_MAX**|Valor máximo para uma variável do tipo **unsigned long**.|4294967295 (0xffffffff)|
|**LLONG_MIN**|Valor mínimo para uma variável do tipo **longo**longo.|-9.223.372.036.854.775.807-1|
|**LLONG_MAX**|Valor máximo para uma variável do tipo **longo**longo.|9,223,372,036,854,775,807|
|**ULLONG_MAX**|Valor máximo para uma variável do tipo **sem sinal longo**.|18446744073709551615 (0xFFFFFFFFFFFFFFFF)|

Se um valor exceder a representação do maior inteiro, o compilador da Microsoft gera um erro.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Constantes de inteiro C](../c-language/c-integer-constants.md)
