---
title: "C3238 de erro do compilador | Microsoft Docs"
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
  - "C3238"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3238"
ms.assetid: 19942497-b3c5-4df0-9144-142ced92468b
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3238 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': um tipo com esse nome já foi encaminhado para o assembly 'assembly'  
  
 Um tipo foi definido em um aplicativo cliente que também é definido, por meio do tipo de encaminhamento de sintaxe, em um assembly referenciado. Ambos os tipos não podem ser definidos no escopo do aplicativo.  
  
 Consulte [Type Forwarding \(C\+\+\/CLI\)](../../windows/type-forwarding-cpp-cli.md) para obter mais informações.  
  
## Exemplo  
 O exemplo a seguir cria um assembly que contém um tipo que foi encaminhado de outro assembly.  
  
```  
// C3238.cpp // compile with: /clr /LD public ref class R {};  
```  
  
## Exemplo  
 O exemplo a seguir cria um assembly usado para conter a definição de tipo, mas não apenas contém o tipo de sintaxe de encaminhamento.  
  
```  
// C3238_b.cpp // compile with: /clr /LD #using "C3238.dll" [ assembly:TypeForwardedTo(R::typeid) ];  
```  
  
## Exemplo  
 O exemplo a seguir gera C3238.  
  
```  
// C3238_c.cpp // compile with: /clr /c // C3238 expected // Delete the following line to resolve. #using "C3238_b.dll" public ref class R {};  
```