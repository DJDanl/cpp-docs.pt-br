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
ms.openlocfilehash: cead21c9a66dbc54b46b1c9f8083022a59e80295
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50469962"
---
# <a name="floating-limits"></a>Limites flutuantes

**Seção específica da Microsoft**

A tabela a seguir lista os limites nos valores de constantes de ponto flutuante. Esses limites também são definidos no arquivo de cabeçalho padrão \<float. h >.

## <a name="limits-on-floating-point-constants"></a>Limites em constantes de ponto flutuante

|Constante|Significado|Valor|
|--------------|-------------|-----------|
|`FLT_DIG`<br/>`DBL_DIG`<br/>`LDBL_DIG`|Número de dígitos, q, de modo que um número de ponto flutuante com dígitos decimais de q possam ser arredondados em uma representação de ponto flutuante e de volta sem perda de precisão.|6<br/>15<br/>15|
|`FLT_EPSILON`<br/>`DBL_EPSILON`<br/>`LDBL_EPSILON`|O menor número positivo x, de modo que x + 1,0 não é igual a 1,0.|1.192092896e-07F<br/>2.2204460492503131e-016<br/>2.2204460492503131e-016|
|`FLT_GUARD`||0|
|`FLT_MANT_DIG`<br/>`DBL_MANT_DIG`<br/>`LDBL_MANT_DIG`|Número de dígitos na raiz especificada por `FLT_RADIX` em significando de ponto flutuante. A raiz é 2; Portanto, esses valores especificam bits.|24<br/>53<br/>53|
|`FLT_MAX`<br/>`DBL_MAX`<br/>`LDBL_MAX`|Número de ponto flutuante representável máximo.|3.402823466e+38F<br/>1.7976931348623158e+308<br/>1.7976931348623158e+308|
|`FLT_MAX_10_EXP`<br/>`DBL_MAX_10_EXP`<br/>`LDBL_MAX_10_EXP`|Inteiro máximo, de modo que 10 gerados para esse número é um número de ponto flutuante representável.|38<br/>308<br/>308|
|`FLT_MAX_EXP`<br/>`DBL_MAX_EXP`<br/>`LDBL_MAX_EXP`|Inteiro máximo, de modo que `FLT_RADIX` gerado para esse número seja um número de ponto flutuante representável.|128<br/>1024<br/>1024|
|`FLT_MIN`<br/>`DBL_MIN`<br/>`LDBL_MIN`|Valor positivo mínimo.|1.175494351e-38F<br/>2.2250738585072014e-308<br/>2.2250738585072014e-308|
|`FLT_MIN_10_EXP`<br/>`DBL_MIN_10_EXP`<br/>`LDBL_MIN_10_EXP`|Inteiro negativo mínimo, de modo que 10 gerados para esse número é um número de ponto flutuante representável.|-37<br/>-307<br/>-307|
|`FLT_MIN_EXP`<br/>`DBL_MIN_EXP`<br/>`LDBL_MIN_EXP`|Inteiro negativo mínimo, de modo que `FLT_RADIX` gerado para esse número seja um número de ponto flutuante representável.|-125<br/>-1021<br/>-1021|
|`FLT_NORMALIZE`||0|
|`FLT_RADIX`<br/>`_DBL_RADIX`<br/>`_LDBL_RADIX`|Raiz de representação do expoente.|2<br/>2<br/>2|
|`FLT_ROUNDS`<br/>`_DBL_ROUNDS`<br/>`_LDBL_ROUNDS`|Modo de arredondamento para adição de ponto flutuante.|1 (próximo)<br/>1 (próximo)<br/>1 (próximo)|

> [!NOTE]
>  As informações da tabela podem ser diferente em versões futuras do produto.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Limites de inteiros](../cpp/integer-limits.md)
