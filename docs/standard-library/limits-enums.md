---
title: Enumerações &lt;limits&gt;
ms.date: 11/04/2016
f1_keywords:
- limits/std::float_denorm_style
- limits/std::float_round_style
ms.assetid: c86680a2-ba97-4ed9-8c20-a448857d7dc5
ms.openlocfilehash: 567e0538f59c40d57f85d652a8919be6e034cf0b
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420067"
---
# <a name="ltlimitsgt-enums"></a>Enumerações &lt;limits&gt;

## <a name="float_denorm_style"></a>float_denorm_style

A enumeração descreve os vários métodos que uma implementação pode escolher para representar um valor de ponto flutuante desnormalizado — um pequeno demais para ser representado como um valor normalizado:

```cpp
enum float_denorm_style {
    denorm_indeterminate = -1,
    denorm_absent = 0,
    denorm_present = 1    };
```

### <a name="return-value"></a>Valor retornado

A enumeração retornará:

- `denorm_indeterminate` se a presença ou a ausência de formulários desnormalizados não puder ser determinada no momento da tradução.

- `denorm_absent` se formulários desnormalizados estiverem ausentes.

- `denorm_present` se estiverem presentes formulários desnormalizados.

### <a name="example"></a>Exemplo

Consulte [numeric_limits::has_denorm](../standard-library/numeric-limits-class.md#has_denorm) para ver um exemplo em que os valores da enumeração podem ser acessados.

## <a name="float_round_style"></a>float_round_style

A enumeração descreve os vários métodos que uma implementação pode escolher para fazer o arredondamento de um valor de ponto flutuante para um valor inteiro.

```cpp
enum float_round_style {
    round_indeterminate = -1,
    round_toward_zero = 0,
    round_to_nearest = 1,
    round_toward_infinity = 2,
    round_toward_neg_infinity = 3    };
```

### <a name="return-value"></a>Valor retornado

A enumeração retornará:

- `round_indeterminate` se o método de arredondamento não puder ser determinado.

- `round_toward_zero` se o arredondar para zero.

- `round_to_nearest` se o número de arredondar para o inteiro mais próximo.

- `round_toward_infinity` se o arredondamento para longe de zero.

- `round_toward_neg_infinity` se o número arredondado para um inteiro negativo.

### <a name="example"></a>Exemplo

Consulte [numeric_limits::round_style](../standard-library/numeric-limits-class.md#round_style) para ver um exemplo em que os valores da enumeração podem ser acessados.
