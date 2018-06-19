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
ms.openlocfilehash: 36d462d4222cbfc143dd7487d4cb6b1b8bb3ba3b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32368480"
---
# <a name="precedence-in-inference-rules"></a>Precedência em regras de inferência
Se uma regra de inferência é definida várias vezes, NMAKE usa a definição de precedência mais alta. A lista a seguir mostra a ordem de prioridade do mais alto ao mais baixo:  
  
1.  Uma regra de inferência de tipos definida em um makefile; as definições mais recente tem precedência.  
  
2.  Uma regra de inferência de tipos definida em Tools.ini; as definições mais recente tem precedência.  
  
3.  Uma regra de inferência de tipos predefinidos.  
  
## <a name="see-also"></a>Consulte também  
 [Regras de inferência](../build/inference-rules.md)