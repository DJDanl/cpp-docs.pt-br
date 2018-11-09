---
title: Avaliação de expressão (C)
ms.date: 11/04/2016
helpviewer_keywords:
- expression evaluation
- expressions [C++], evaluating
ms.assetid: 9493f8cc-64a2-4284-9aaf-26eec11c4f40
ms.openlocfilehash: 58478830d901836fc82ee02412c86a776a2c1998
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50522350"
---
# <a name="expression-evaluation-c"></a>Avaliação de expressão (C)

Expressões que envolvem atribuição, incremento unário, diminuição unária ou chamando de uma função podem ter consequências incidentais à sua avaliação (efeitos colaterais). Quando um "ponto de sequência" é alcançado, tudo que precede o ponto de sequência, inclusive todos os efeitos colaterais, obrigatoriamente foram avaliados antes que a avaliação seja iniciada em qualquer coisa posterior ao ponto de sequência.

Os "efeitos colaterais" são alterações causadas pela avaliação de uma expressão. Os efeitos colaterais ocorrem sempre que o valor de uma variável é alterado por uma avaliação da expressão. Todas as operações de atribuição têm efeitos colaterais. As chamadas de função também poderão ter efeitos colaterais se alterarem o valor de um item externamente visível, seja pela atribuição direta ou indireta por meio de um ponteiro.

## <a name="see-also"></a>Consulte também

[Operandos e expressões](../c-language/operands-and-expressions.md)