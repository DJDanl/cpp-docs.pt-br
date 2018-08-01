---
title: Instruções de iteração (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- iteration statements
- loop structures, iteration statements
ms.assetid: bf6d75f7-ead2-426a-9c47-33847f59b8c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 988d46b3f4b2e20ff14227fda70a6f39ac95756c
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39402891"
---
# <a name="iteration-statements-c"></a>Instruções de iteração (C++)
As instruções de iteração fazem com que as instruções (ou instruções compostas) sejam executadas nenhuma ou mais vezes, de acordo com os critérios de término de loop. Quando essas instruções são instruções compostas, são executadas em ordem, exceto quando ambos os [quebra](../cpp/break-statement-cpp.md) instrução ou o [continuar](../cpp/continue-statement-cpp.md) instrução for encontrada.  
  
 C++ fornece quatro instruções de iteração — [enquanto](../cpp/while-statement-cpp.md), [fazer](../cpp/do-while-statement-cpp.md), [para](../cpp/for-statement-cpp.md), e [baseado em intervalo para](../cpp/range-based-for-statement-cpp.md). Cada uma delas itera até que a expressão de término seja avaliada como zero (false) ou até o término de loop seja imposto com uma **quebra** instrução. A tabela a seguir resume essas instruções e suas ações; cada uma delas é discutida em detalhes nas seções seguintes.  
  
### <a name="iteration-statements"></a>Instruções de iteração  
  
|Instrução|Avaliada como|Inicialização|Incremento|  
|---------------|------------------|--------------------|---------------|  
|**while**|Topo do loop|Não|Não|  
|**do**|Final do loop|Não|Não|  
|**for**|Topo do loop|Sim|Sim|  
|**baseado em intervalo para**|Topo do loop|Sim|Sim|  
  
 A parte da instrução de uma instrução de iteração não pode ser uma declaração. No entanto, pode ser uma instrução composta que contenha uma declaração.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral das instruções C++](../cpp/overview-of-cpp-statements.md)