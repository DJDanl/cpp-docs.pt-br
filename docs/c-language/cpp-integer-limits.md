---
title: Limites de inteiro C++
ms.date: 01/29/2018
helpviewer_keywords:
- limits, integer
- limits, integer constants
- integer limits
ms.assetid: 0c23cbd6-29fb-4d9c-b689-5984e19748de
ms.openlocfilehash: 057da1ac8e4549a05d10a01cc3aead678045d9c5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50548285"
---
# <a name="c-integer-limits"></a>Limites de inteiro C++

**Seção específica da Microsoft**

Os limites para tipos de inteiros estão listadas na tabela a seguir. Esses limites são definidos no arquivo de cabeçalho padrão LIMITS.H. O Microsoft C também permite a declaração de variáveis de inteiro dimensionadas, que são tipos integrais de 8, 16 ou 32 bits de tamanho. Para obter mais informações sobre inteiros dimensionados, consulte [Tipos de inteiros dimensionados](../c-language/c-sized-integer-types.md).

## <a name="limits-on-integer-constants"></a>Limites em constantes de inteiro

|**Constante**|Significado|Valor|
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

Se um valor exceder a representação do maior inteiro, o compilador da Microsoft gera um erro.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Constantes de inteiro C](../c-language/c-integer-constants.md)
