---
title: "Instru&#231;&#245;es de itera&#231;&#227;o (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instruções iteration"
  - "Estruturas de loop, instruções iteration"
ms.assetid: bf6d75f7-ead2-426a-9c47-33847f59b8c7
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es de itera&#231;&#227;o (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As instruções de iteração fazem com que as instruções \(ou instruções compostas\) sejam executadas nenhuma ou mais vezes, de acordo com os critérios de término de loop.  Quando essas instruções são compostas, são executadas em sequência, exceto quando a instrução [break](../cpp/break-statement-cpp.md) ou a instrução [continue](../cpp/continue-statement-cpp.md) são encontradas.  
  
 O C\+\+ fornece quatro instruções de iteração — [while](../cpp/while-statement-cpp.md), [do](../cpp/do-while-statement-cpp.md), [for](../cpp/for-statement-cpp.md)e [range\-based for](../Topic/Range-based%20for%20Statement%20\(C++\).md).  Cada uma delas itera até que a expressão de término seja avaliada como zero \(false\), ou até que o término de loop seja imposto com uma instrução **break**.  A tabela a seguir resume essas instruções e suas ações; cada uma delas é discutida em detalhes nas seções seguintes.  
  
### Instruções de iteração  
  
|Instrução|Avaliada como|Inicialização|Incremento|  
|---------------|-------------------|-------------------|----------------|  
|`while`|Topo do loop|Não|Não|  
|**do**|Final do loop|Não|Não|  
|**for**|Topo do loop|Sim|Sim|  
|**range\-based for**|Topo do loop|Sim|Sim|  
  
 A parte da instrução de uma instrução de iteração não pode ser uma declaração.  No entanto, pode ser uma instrução composta que contenha uma declaração.  
  
## Consulte também  
 [Visão geral de instruções C\+\+](../cpp/overview-of-cpp-statements.md)