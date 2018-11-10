---
title: Efeitos colaterais
ms.date: 11/04/2016
helpviewer_keywords:
- expression evaluation, side effects
- side effects in expression evaluation
ms.assetid: d9b3004a-830e-43a0-bea5-8989d501d670
ms.openlocfilehash: 97fbb2bc382216e27139a01d1e803a15bd16160b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50582553"
---
# <a name="side-effects"></a>Efeitos colaterais

A ordem de avaliação das expressões é definida pela implementação específica, exceto quando a linguagem garante uma determinada ordem de avaliação (conforme descrito em [Precedência e ordem de avaliação](../c-language/precedence-and-order-of-evaluation.md)). Por exemplo, os efeitos colaterais ocorrem nas seguintes chamadas de função:

```
add( i + 1, i = j + 2 );
myproc( getc(), getc() );
```

Os argumentos de uma chamada de função podem ser avaliados em qualquer ordem. A expressão `i + 1` pode ser avaliada antes de `i = j + 2`, ou `i = j + 2` pode ser avaliada antes de `i + 1`. O resultado é diferente em cada caso. De maneira similar, não é possível garantir quais caracteres serão passados para `myproc`. Como os incrementos unários e operações de redução envolvem atribuições, essas operações podem causar efeitos colaterais, conforme mostrado no seguinte exemplo:

```
x[i] = i++;
```

Neste exemplo, o valor de `x` alterado é imprevisível. O valor do subscrito pode ser o valor novo ou antigo de `i`. O resultado pode variar em compiladores diferentes ou níveis de otimização diferentes.

Como C não define a ordem de avaliação de efeitos colaterais, ambos os métodos de avaliação discutidos anteriormente estão corretos e qualquer um pode ser implementado. Para garantir que o seu código seja portátil e claro, evite as instruções que dependem de um pedido específico de avaliação quanto aos efeitos colaterais.

## <a name="see-also"></a>Consulte também

[Avaliação de expressão](../c-language/expression-evaluation-c.md)