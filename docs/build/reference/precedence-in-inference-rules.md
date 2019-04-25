---
title: Precedência em regras de inferência
ms.date: 11/04/2016
helpviewer_keywords:
- inference rules in NMAKE
- rules, inference
- precedence, inference rule
ms.assetid: 69e3dc02-0815-4c3a-b02b-1cb85fceaf24
ms.openlocfilehash: ca24134fd1829ad3d97ca67b8c30aae3af4109ee
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62319675"
---
# <a name="precedence-in-inference-rules"></a>Precedência em regras de inferência

Se uma regra de inferência de tipos está definida várias vezes, NMAKE usa a definição de precedência mais alta. A lista a seguir mostra a ordem de precedência da mais alta para a mais baixa:

1. Uma regra de inferência de tipos definida em um makefile; definições de posteriores têm precedência.

1. Uma regra de inferência de tipos definida em Tools. ini; definições de posteriores têm precedência.

1. Uma regra de inferência de tipos predefinidos.

## <a name="see-also"></a>Consulte também

[Regras de inferência](inference-rules.md)
