---
title: "C3421 de erro do compilador | Microsoft Docs"
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
  - "C3421"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3421"
ms.assetid: b52050c6-17a4-424a-8894-337b0cec7010
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3421 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': não é possível chamar o finalizador para essa classe como ela está inacessível ou não existe  
  
 Um finalizador é implicitamente particular, ele não pode ser chamado de fora de seu tipo delimitador.  
  
 Para obter mais informações, consulte [Destruidores e finalizadores em Visual C\+\+](../../misc/destructors-and-finalizers-in-visual-cpp.md).  
  
## Exemplo  
 O exemplo a seguir gera C3421.  
  
```  
// C3421.cpp // compile with: /clr ref class A {}; ref class B { !B() {} public: ~B() {} }; int main() { A a; a.!A();   // C3421 B b; b.!B();   // C3421 }  
```