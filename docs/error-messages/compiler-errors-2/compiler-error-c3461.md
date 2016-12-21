---
title: "C3461 de erro do compilador | Microsoft Docs"
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
  - "C3461"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3461"
ms.assetid: bd66833a-545d-445a-bdfe-dee771a450a4
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3461 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': somente um tipo gerenciado pode ser encaminhado  
  
 Encaminhamento de tipo só pode ocorrer em tipos CLR.  Consulte [Classes and Structs](../../windows/classes-and-structs-cpp-component-extensions.md) para obter mais informações.  
  
 Para obter mais informações, consulte [Type Forwarding \(C\+\+\/CLI\)](../../windows/type-forwarding-cpp-cli.md).  
  
## Exemplo  
 O exemplo a seguir cria um componente.  
  
```  
// C3461.cpp // compile with: /clr /LD public ref class R {};  
```  
  
## Exemplo  
 O exemplo a seguir gera C3461.  
  
```  
// C3461b.cpp // compile with: /clr /c #using "C3461.dll" class N {}; [assembly:TypeForwardedTo(N::typeid)];   // C3461 [assembly:TypeForwardedTo(R::typeid)];   // OK  
```