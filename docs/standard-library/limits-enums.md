---
title: Enumerações &lt;limits&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- limits/std::float_denorm_style
- limits/std::float_round_style
ms.assetid: c86680a2-ba97-4ed9-8c20-a448857d7dc5
ms.openlocfilehash: 356c98ce5c93d1e05a583fc30c4758c5d15d7529
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="ltlimitsgt-enums"></a>Enumerações &lt;limits&gt;

|||
|-|-|
|[float_denorm_style](#float_denorm_style)|[float_round_style](#float_round_style)|

## <a name="float_denorm_style"></a> Enumeração float_denorm_style

A enumeração descreve os vários métodos que uma implementação pode escolher para representar um valor de ponto flutuante desnormalizado — um pequeno demais para ser representado como um valor normalizado:

```cpp
enum float_denorm_style {
    denorm_indeterminate = -1,
    denorm_absent = 0,
    denorm_present = 1    };
```

### <a name="return-value"></a>Valor de retorno

A enumeração retornará:

- **denorm_indeterminate** se a presença ou ausência de formas desnormalizadas não puder ser determinada no momento da conversão.

- **denorm_absent** se formas desnormalizadas estiverem ausentes.

- **denorm_present** se formas desnormalizadas estiverem presentes.

### <a name="example"></a>Exemplo

Consulte [numeric_limits::has_denorm](../standard-library/numeric-limits-class.md#has_denorm) para ver um exemplo em que os valores da enumeração podem ser acessados.

## <a name="float_round_style"></a> Enumeração float_round_style

A enumeração descreve os vários métodos que uma implementação pode escolher para fazer o arredondamento de um valor de ponto flutuante para um valor inteiro.

```cpp
enum float_round_style {
    round_indeterminate = -1,
    round_toward_zero = 0,
    round_to_nearest = 1,
    round_toward_infinity = 2,
    round_toward_neg_infinity = 3    };
```

### <a name="return-value"></a>Valor de retorno

A enumeração retornará:

- **round_indeterminate** se o método de arredondamento não puder ser determinado.

- **round_toward_zero** se o arredondamento for feito em direção a zero.

- **round_to_nearest** se o arredondamento for feito para o inteiro mais próximo.

- **round_toward_infinity** se o arredondamento for feito se distanciando de zero.

- **round_toward_neg_infinity** se o arredondamento for feito para o inteiro mais negativo.

### <a name="example"></a>Exemplo

Consulte [numeric_limits::round_style](../standard-library/numeric-limits-class.md#round_style) para ver um exemplo em que os valores da enumeração podem ser acessados.

## <a name="see-also"></a>Consulte também

[\<limits>](../standard-library/limits.md)<br/>
