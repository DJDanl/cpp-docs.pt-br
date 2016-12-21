---
title: "C3490 de erro do compilador | Microsoft Docs"
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
  - "C3490"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3490"
ms.assetid: 7638559a-fd06-4527-a9c1-0c8ae68b3123
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3490 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'var' não pode ser modificada porque ela está sendo acessada por meio de um objeto const  
  
 Uma expressão lambda que é declarada em um `const` método não pode modificar dados de membro não mutável.  
  
### Para corrigir este erro  
  
-   Remover o `const` modificador de sua declaração de método.  
  
## Exemplo  
 O exemplo a seguir gera C3490 porque ele modifica a variável de membro`_i` em um `const` método:  
  
```  
// C3490a.cpp // compile with: /c class C { void f() const  { auto x = [=]() { _i = 20; }; // C3490 } int _i; };  
```  
  
## Exemplo  
 O exemplo a seguir resolve C3490 removendo o `const` modificador da declaração de método:  
  
```  
// C3490b.cpp // compile with: /c class C { void f() { auto x = [=]() { _i = 20; }; } int _i; };  
```  
  
## Consulte também  
 [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)