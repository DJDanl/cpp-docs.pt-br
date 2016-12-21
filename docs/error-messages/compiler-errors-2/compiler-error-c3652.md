---
title: "Erro do Compilador C3652 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C3652"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3652"
ms.assetid: 15d68737-177e-41f1-80e0-7c3e2afdf0fc
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3652
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“substituição”: uma função que substitui deve ser explicitamente virtual  
  
 Uma função que faça uma substituição explícita deve ser virtual.  Para obter mais informações, consulte [Substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md).  
  
 O seguinte exemplo gera C3652:  
  
```  
// C3652.cpp  
// compile with: /clr /c  
public interface class I {  
   void f();  
};  
  
public ref struct R : I {  
   void f() = I::f {}   // C3652  
   // try the following line instead  
   // virtual void f() = I::f {}  
};  
```