---
title: C3764 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3764
dev_langs:
- C++
helpviewer_keywords:
- C3764
ms.assetid: af5d254c-8d4a-4dda-aad9-3c5c1257c868
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 60317bb31b5021d4b9b1b6568d77ae92e06880ce
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3764"></a>C3764 de erro do compilador
'override_function': não é possível substituir o método da classe base 'base_class_function'  
  
 O compilador detectou uma substituição mal formados. Por exemplo, a função de classe base não era `virtual`. Para obter mais informações, consulte [substituir](../../windows/override-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3764.  
  
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
  
## <a name="example"></a>Exemplo  
 C3764 também pode ocorrer quando um método de classe base é explicitamente e nomeado substituído. O exemplo a seguir gera C3764.  
  
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
