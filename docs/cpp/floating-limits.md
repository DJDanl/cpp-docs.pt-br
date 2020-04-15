---
title: Limites flutuantes
ms.date: 08/03/2018
helpviewer_keywords:
- ranges, floating-point constants
- floating-point constants, limits
- float.h header file
- limits, floating-point constants
- floating-point numbers [C++]
- floating limits
ms.assetid: fc718652-1f4c-4ed8-af60-0e769637459c
ms.openlocfilehash: ccd395eef319e57cecffad8a5278b6df1397f4cb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373373"
---
# <a name="floating-limits"></a>Limites flutuantes

**Específico da Microsoft**

A tabela a seguir lista os limites nos valores de constantes de ponto flutuante. Esses limites também são definidos \<no arquivo de cabeçalho padrão float.h>.

## <a name="limits-on-floating-point-constants"></a>Limites em constantes de ponto flutuante

|Constante|Significado|Valor|
|--------------|-------------|-----------|
|`FLT_DIG`<br/>`DBL_DIG`<br/>`LDBL_DIG`|Número de dígitos, q, de modo que um número de ponto flutuante com dígitos decimais de q possam ser arredondados em uma representação de ponto flutuante e de volta sem perda de precisão.|6<br/>15<br/>15|
|`FLT_EPSILON`<br/>`DBL_EPSILON`<br/>`LDBL_EPSILON`|O menor número positivo x, de modo que x + 1,0 não é igual a 1,0.|1.192092896e-07F<br/>2.2204460492503131e-016<br/>2.2204460492503131e-016|
|`FLT_GUARD`||0|
|`FLT_MANT_DIG`<br/>`DBL_MANT_DIG`<br/>`LDBL_MANT_DIG`|Número de dígitos no radix `FLT_RADIX` especificado pelo ponto flutuante. O rádio é 2; portanto, esses valores especificam bits.|24<br/>53<br/>53|
|`FLT_MAX`<br/>`DBL_MAX`<br/>`LDBL_MAX`|Número máximo de ponto flutuante representando.|3.402823466e+38F<br/>1,7976931348623158e+308<br/>1,7976931348623158e+308|
|`FLT_MAX_10_EXP`<br/>`DBL_MAX_10_EXP`<br/>`LDBL_MAX_10_EXP`|O inteiro máximo de tal forma que 10 elevados a esse número é um número de ponto flutuante representando.|38<br/>308<br/>308|
|`FLT_MAX_EXP`<br/>`DBL_MAX_EXP`<br/>`LDBL_MAX_EXP`|O inteiro máximo `FLT_RADIX` que elevou para esse número é um número de ponto flutuante representando.|128<br/>1024<br/>1024|
|`FLT_MIN`<br/>`DBL_MIN`<br/>`LDBL_MIN`|Valor positivo mínimo.|1.175494351e-38F<br/>2,2250738585072014e-308<br/>2,2250738585072014e-308|
|`FLT_MIN_10_EXP`<br/>`DBL_MIN_10_EXP`<br/>`LDBL_MIN_10_EXP`|O inteiro negativo mínimo de tal forma que 10 elevados a esse número é um número de ponto flutuante representando.|-37<br/>-307<br/>-307|
|`FLT_MIN_EXP`<br/>`DBL_MIN_EXP`<br/>`LDBL_MIN_EXP`|O inteiro negativo mínimo `FLT_RADIX` que elevou para esse número é um número de ponto flutuante representando.|-125<br/>-1021<br/>-1021|
|`FLT_NORMALIZE`||0|
|`FLT_RADIX`<br/>`_DBL_RADIX`<br/>`_LDBL_RADIX`|Raiz de representação do expoente.|2<br/>2<br/>2|
|`FLT_ROUNDS`<br/>`_DBL_ROUNDS`<br/>`_LDBL_ROUNDS`|Modo de arredondamento para adição de ponto flutuante.|1 (próximo)<br/>1 (próximo)<br/>1 (próximo)|

> [!NOTE]
> As informações da tabela podem ser diferente em versões futuras do produto.

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[Limites inteiros](../cpp/integer-limits.md)
