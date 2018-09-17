---
title: Precedência em regras de inferência | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- inference rules in NMAKE
- rules, inference
- precedence, inference rule
ms.assetid: 69e3dc02-0815-4c3a-b02b-1cb85fceaf24
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b4f2e7ff55e935b7e425b552ba85f47f134c6b80
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45725225"
---
# <a name="precedence-in-inference-rules"></a>Precedência em regras de inferência

Se uma regra de inferência de tipos está definida várias vezes, NMAKE usa a definição de precedência mais alta. A lista a seguir mostra a ordem de precedência da mais alta para a mais baixa:

1. Uma regra de inferência de tipos definida em um makefile; definições de posteriores têm precedência.

1. Uma regra de inferência de tipos definida em Tools. ini; definições de posteriores têm precedência.

1. Uma regra de inferência de tipos predefinidos.

## <a name="see-also"></a>Consulte também

[Regras de inferência](../build/inference-rules.md)