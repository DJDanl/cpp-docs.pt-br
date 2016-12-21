---
title: "Erro do Compilador C3764 | Microsoft Docs"
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
  - "C3764"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3764"
ms.assetid: af5d254c-8d4a-4dda-aad9-3c5c1257c868
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3764
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“override\_function”: não é possível substituir o método “base\_class\_function” da classe base  
  
 O compilador detectou uma substituição doente\- bem formada.  Por exemplo, a função da classe base não foi `virtual`.  Para obter mais informações, consulte [override](../../windows/override-cpp-component-extensions.md).  
  
## Exemplo  
 O exemplo a seguir produz C3764.  
  
```  
// C3764.cpp  
// compile with: /clr /c  
public ref struct A {  
   void g(int);  
   virtual void h(int);  
};  
  
public ref struct B : A {  
   virtual void g(int) override {}   // C3764  
   virtual void h(int) override {}   // OK  
};  
```  
  
## Exemplo  
 C3764 também pode ocorrer quando um método da classe base é ambos e nomeadas explicitamente substituído.  O exemplo a seguir produz C3764.  
  
```  
// C3764_b.cpp  
// compile with: /clr /c  
ref struct A {  
   virtual void Test() {}  
};  
  
ref struct B : public A {  
   virtual void Test() override {}  
   virtual void Test2() = A::Test {}   // C3764  
};  
```