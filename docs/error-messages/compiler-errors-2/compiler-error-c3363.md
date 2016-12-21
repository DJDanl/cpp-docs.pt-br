---
title: "C3363 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C3363"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3363"
ms.assetid: 41aa922f-608e-4f7a-ba66-451fc1161935
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3363 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': 'typeid' só pode ser aplicada a um tipo  
  
 O [typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md) operador foi usado incorretamente.  
  
## Exemplo  
 O exemplo a seguir gera C3363.  
  
```  
// C3363.cpp // compile with: /clr int main() { System::typeid;   // C3363 }  
```