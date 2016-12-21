---
title: "C3375 de erro do compilador | Microsoft Docs"
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
  - "C3375"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3375"
ms.assetid: f1df78c6-e6ca-48f3-8b29-4e1710002bf3
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3375 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'function': função de delegação ambíguo  
  
 Uma instanciação de delegado poderia ser uma função de membro estático, ou como um delegado não associado a uma função de instância, então o compilador emitiu esse erro.  
  
 Para obter mais informações, consulte [delegado](../../windows/delegate-cpp-component-extensions.md).  
  
## Exemplo  
 O exemplo a seguir gera C3375.  
  
```  
// C3375.cpp // compile with: /clr ref struct R { static void f(R^) {} void f() {} }; delegate void Del(R^); int main() { Del ^ a = gcnew Del(&R::f);   // C3375 }  
```