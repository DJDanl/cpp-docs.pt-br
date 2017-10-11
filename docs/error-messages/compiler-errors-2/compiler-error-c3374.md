---
title: C3374 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3374
dev_langs:
- C++
helpviewer_keywords:
- C3374
ms.assetid: 41431299-bd20-47d4-a0c8-1334dd79018b
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 16c857cf431462abd2acc21cf7444ec0aad2d075
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3374"></a>C3374 de erro do compilador
não é possível obter o endereço de 'função', a menos que a criação represente a instância  
  
 O endereço de uma função foi executado em um contexto diferente do de criação de uma instância representada.  
  
 O seguinte exemplo gera C3374:  
  
```  
// C3374.cpp  
// compile with: /clr  
public delegate void MyDel(int i);  
  
ref class A {  
public:  
   void func1(int i) {  
      System::Console::WriteLine("in func1 {0}", i);  
   }  
};  
  
int main() {  
   &A::func1;   // C3374  
  
   // OK  
   A ^ a = gcnew A;  
   MyDel ^ StaticDelInst = gcnew MyDel(a, &A::func1);  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Como definir e usar delegados (C++/CLI)](../../dotnet/how-to-define-and-use-delegates-cpp-cli.md)
