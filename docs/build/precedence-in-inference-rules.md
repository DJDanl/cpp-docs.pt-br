---
title: "Precedência em regras de inferência | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- inference rules in NMAKE
- rules, inference
- precedence, inference rule
ms.assetid: 69e3dc02-0815-4c3a-b02b-1cb85fceaf24
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f7374da0541fc66464947af5a7b2ea7ea7b5c1d3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="precedence-in-inference-rules"></a>Precedência em regras de inferência
Se uma regra de inferência é definida várias vezes, NMAKE usa a definição de precedência mais alta. A lista a seguir mostra a ordem de prioridade do mais alto ao mais baixo:  
  
1.  Uma regra de inferência de tipos definida em um makefile; as definições mais recente tem precedência.  
  
2.  Uma regra de inferência de tipos definida em Tools.ini; as definições mais recente tem precedência.  
  
3.  Uma regra de inferência de tipos predefinidos.  
  
## <a name="see-also"></a>Consulte também  
 [Regras de inferência](../build/inference-rules.md)