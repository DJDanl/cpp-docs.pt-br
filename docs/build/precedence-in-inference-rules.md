---
title: Precedência em regras de inferência
ms.date: 11/04/2016
helpviewer_keywords:
- inference rules in NMAKE
- rules, inference
- precedence, inference rule
ms.assetid: 69e3dc02-0815-4c3a-b02b-1cb85fceaf24
ms.openlocfilehash: 99d92985b00f7c05f409b43009eb61cec6d6f1b1
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57413271"
---
# <a name="precedence-in-inference-rules"></a>Precedência em regras de inferência

Se uma regra de inferência de tipos está definida várias vezes, NMAKE usa a definição de precedência mais alta. A lista a seguir mostra a ordem de precedência da mais alta para a mais baixa:

1. Uma regra de inferência de tipos definida em um makefile; definições de posteriores têm precedência.

1. Uma regra de inferência de tipos definida em Tools. ini; definições de posteriores têm precedência.

1. Uma regra de inferência de tipos predefinidos.

## <a name="see-also"></a>Consulte também

[Regras de inferência](../build/inference-rules.md)
