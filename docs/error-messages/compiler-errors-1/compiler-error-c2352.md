---
title: C2352 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2352
dev_langs:
- C++
helpviewer_keywords:
- C2352
ms.assetid: 0efad8cb-659f-4b3e-8f6f-9f8ec44d345c
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 2f41907647f11a5f7ca47c272b735f2eeca0f452
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2352"></a>C2352 de erro do compilador
'class::function': chamada inválida a função de membro não estático  
  
 Um `static` chamado de função de membro de uma função de membro não estático. Ou então, uma função de membro não estático foi chamada de fora da classe como uma função estática.  
  
 O exemplo a seguir gera C2352 e mostra como corrigi-lo:  
  
```  
// C2352.cpp  
// compile with: /c  
class CMyClass {  
public:  
   static void func1();  
   void func2();  
   static void func3() {  
      func2();   // C2352 calls nonstatic func2  
      func1();   // OK calls static func1  
   }  
};  
```  
  
 O exemplo a seguir gera C2352 e mostra como corrigi-lo:  
  
```  
// C2352b.cpp  
class MyClass {  
public:  
   void MyFunc() {}  
   static void MyFunc2() {}  
};  
  
int main() {  
   MyClass::MyFunc();   // C2352  
   MyClass::MyFunc2();   // OK  
}  
```
