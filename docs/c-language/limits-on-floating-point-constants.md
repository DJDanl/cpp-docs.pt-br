---
title: Limites em constantes de ponto flutuantes | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- ranges, floating-point constants
- floating-point constants, limits
- FLOAT.H header file
- constants, floating-point
- limits, floating-point constants
- floating-point numbers, floating limits
ms.assetid: 2d975868-2af6-45d7-a8af-db79f2c6b67b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b42fb03aca7334414a43b46be1134941389e4277
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46095307"
---
# <a name="limits-on-floating-point-constants"></a>Limites em constantes de ponto flutuante

**Seção específica da Microsoft**

Os limites dos valores de constantes de ponto flutuante são fornecidos na seguinte tabela. O arquivo de cabeçalho FLOAT.H contém essas informações.

### <a name="limits-on-floating-point-constants"></a>Limites em constantes de ponto flutuante

|Constante|Significado|Valor|
|--------------|-------------|-----------|
|**FLT_DIG**<br />**DBL_DIG**<br />**LDBL_DIG**|Número de dígitos, *q*, de modo que um número de ponto flutuante com dígitos decimais de *q* possam ser arredondados em uma representação de ponto flutuante e de volta sem perda de precisão.|6<br />15<br />15|
|**FLT_EPSILON**<br />**DBL_EPSILON**<br />**LDBL_EPSILON**|O menor número positivo *x*, de modo que *x* + 1,0 não é igual a 1,0|1.192092896e-07F<br />2.2204460492503131e-016<br />2.2204460492503131e-016|
|**FLT_GUARD**||0|
|**FLT_MANT_DIG**<br />**DBL_MANT_DIG**<br />**LDBL_MANT_DIG**|Número de dígitos na raiz especificada por **FLT_RADIX** em significando de ponto flutuante. A raiz é 2; portanto, esses valores especificam bits.|24<br />53<br />53|
|**FLT_MAX**<br />**DBL_MAX**<br />**LDBL_MAX**|Número de ponto flutuante representável máximo.|3.402823466e+38F<br />1.7976931348623158e+308<br />1.7976931348623158e+308|
|**FLT_MAX_10_EXP**<br />**DBL_MAX_10_EXP**<br />**LDBL_MAX_10_EXP**|Inteiro máximo de modo que 10 gerados para esse número sejam um número de ponto flutuante representável.|38<br />308<br />308|
|**FLT_MAX_EXP**<br />**DBL_MAX_EXP**<br />**LDBL_MAX_EXP**|Inteiro máximo de modo que **FLT_RADIX** gerado para esse número seja um número de ponto flutuante representável.|128<br />1024<br />1024|
|**FLT_MIN**<br />**DBL_MIN**<br />**LDBL_MIN**|Valor positivo mínimo.|1.175494351e-38F<br />2.2250738585072014e-308<br />2.2250738585072014e-308|
|**FLT_MIN_10_EXP**<br />**DBL_MIN_10_EXP**<br />**LDBL_MIN_10_EXP**|Inteiro negativo mínimo de modo que 10 gerados para esse número sejam um número de ponto flutuante representável.|-37<br />-307<br />-307|
|**FLT_MIN_EXP**<br />**DBL_MIN_EXP**<br />**LDBL_MIN_EXP**|Inteiro negativo mínimo de modo que **FLT_RADIX** gerado para esse número seja um número de ponto flutuante representável.|-125<br />-1021<br />-1021|
|**FLT_NORMALIZE**||0|
|**FLT_RADIX**<br />**_DBL_RADIX**<br />**_LDBL_RADIX**|Raiz de representação do expoente.|2<br />2<br />2|
|**FLT_ROUNDS**<br />**_DBL_ROUNDS**<br />**_LDBL_ROUNDS**|Arredondamento do modo para a adição de ponto flutuante.|1 (próximo)<br />1 (próximo)<br />1 (próximo)|

Observe que as informações da tabela acima podem ser diferentes em implementações futuras.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Constantes de ponto flutuante C](../c-language/c-floating-point-constants.md)