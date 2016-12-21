---
title: "C3075 de erro do compilador | Microsoft Docs"
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
  - "C3075"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3075"
ms.assetid: f431daa9-e0fa-48f0-a5c3-f99be96b55e3
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3075 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'instance': não é possível inserir uma instância de um tipo de referência, 'type' em um tipo de valor  
  
 Um tipo de valor não pode conter uma instância de um tipo de referência.  
  
 Para obter mais informações, consulte [Semântica da pilha do C\+\+ para tipos de referência](../../dotnet/cpp-stack-semantics-for-reference-types.md).  
  
## Exemplo  
 O exemplo a seguir gera C3075.  
  
```  
// C3075.cpp // compile with: /clr /c ref struct U {}; value struct X { U y;   // C3075 }; ref struct Y { U y;   // OK };  
```