---
title: "Instruções de iteração (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- iteration statements
- loop structures, iteration statements
ms.assetid: bf6d75f7-ead2-426a-9c47-33847f59b8c7
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: f81ffa2e6b8f1dc07e409b737f76cb8e6aca5258
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="iteration-statements-c"></a>Instruções de iteração (C++)
As instruções de iteração fazem com que as instruções (ou instruções compostas) sejam executadas nenhuma ou mais vezes, de acordo com os critérios de término de loop. Quando essas instruções são declarações compostas, eles são executados em ordem, exceto quando ambos o [quebra](../cpp/break-statement-cpp.md) instrução ou o [continuar](../cpp/continue-statement-cpp.md) instrução for encontrada.  
  
 C++ fornece quatro instruções de iteração — [enquanto](../cpp/while-statement-cpp.md), [fazer](../cpp/do-while-statement-cpp.md), [para](../cpp/for-statement-cpp.md), e [com base em intervalo para](../cpp/range-based-for-statement-cpp.md). Cada uma dessas itera até que sua expressão de encerramento é avaliada como zero (false) ou encerramento do loop for forçado com um **quebra** instrução. A tabela a seguir resume essas instruções e suas ações; cada uma delas é discutida em detalhes nas seções seguintes.  
  
### <a name="iteration-statements"></a>Instruções de iteração  
  
|Instrução|Avaliada como|Inicialização|Incremento|  
|---------------|------------------|--------------------|---------------|  
|`while`|Topo do loop|Não|Não|  
|**do**|Final do loop|Não|Não|  
|**for**|Topo do loop|Sim|Sim|  
|**com base em intervalo para**|Topo do loop|Sim|Sim|  
  
 A parte da instrução de uma instrução de iteração não pode ser uma declaração. No entanto, pode ser uma instrução composta que contenha uma declaração.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral das instruções C++](../cpp/overview-of-cpp-statements.md)