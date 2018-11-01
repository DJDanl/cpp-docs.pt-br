---
title: Precedência em regras de inferência
ms.date: 11/04/2016
helpviewer_keywords:
- inference rules in NMAKE
- rules, inference
- precedence, inference rule
ms.assetid: 69e3dc02-0815-4c3a-b02b-1cb85fceaf24
ms.openlocfilehash: 30dee54c99115c076f7662bafb8aa22d97f234fa
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50548727"
---
# <a name="precedence-in-inference-rules"></a>Precedência em regras de inferência

Se uma regra de inferência de tipos está definida várias vezes, NMAKE usa a definição de precedência mais alta. A lista a seguir mostra a ordem de precedência da mais alta para a mais baixa:

1. Uma regra de inferência de tipos definida em um makefile; definições de posteriores têm precedência.

1. Uma regra de inferência de tipos definida em Tools. ini; definições de posteriores têm precedência.

1. Uma regra de inferência de tipos predefinidos.

## <a name="see-also"></a>Consulte também

[Regras de inferência](../build/inference-rules.md)