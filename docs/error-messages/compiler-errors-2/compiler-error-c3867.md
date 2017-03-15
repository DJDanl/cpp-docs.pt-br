---
title: C3867 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3867
dev_langs:
- C++
helpviewer_keywords:
- C3867
ms.assetid: bc5de03f-e01a-4407-88c3-2c63f0016a1e
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b56a07d98e7d6644e8b3f7ec356012265c8200f5
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3867"></a>C3867 de erro do compilador
'função': a chamada de função ausente da lista de argumentos; Use '< / func' para criar um ponteiro para membro  
  
 Você tentou obter o endereço de uma função de membro sem qualificação da função de membro com o nome da classe e o operador address-of.  
  
 Esse erro também pode ser gerado como resultado de trabalho de conformidade do compilador que foi feito no Visual C++ 2005: conformidade aprimorada do ponteiro para membro. Código compilado antes do Visual C++ 2005 agora irá gerar C3867.  
  
## <a name="example"></a>Exemplo  
 C3867 pode ser emitido do compilador com uma resolução sugerida enganoso. Sempre que possível, use a classe mais derivada.  
  
 O exemplo a seguir gera C3867 e mostra como corrigi-lo.  
  
```  
// C3867_1.cpp  
// compile with: /c  
struct Base {   
protected:   
   void Test() {}  
};  
  
class Derived : public Base {   
   virtual void Bar();  
};  
  
void Derived::Bar() {  
   void (Base::*p1)() = Test;   // C3867  
   &Derived::Test;   // OK  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3867 e mostra como corrigi-lo.  
  
```  
// C3867_2.cpp  
#include<stdio.h>  
  
struct S {  
   char *func() {  
      return "message";  
   }  
};  
  
class X {  
public:  
   void f() {}  
};  
  
int main() {  
   X::f;   // C3867  
  
   // OK  
   X * myX = new X;  
   myX->f();  
  
   S s;  
   printf_s("test %s", s.func);   // C3867  
   printf_s("test %s", s.func());   // OK  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3867 e mostra como corrigi-lo.  
  
```  
// C3867_3.cpp  
class X {  
public:  
   void mf(){}  
};  
  
int main() {  
   void (X::*pmf)() = X::mf;   // C3867  
  
   // try the following line instead  
   void (X::*pmf2)() = &X::mf;  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3867.  
  
```  
// C3867_4.cpp  
// compile with: /c  
class A {  
public:  
   void f(int) {}  
  
   typedef void (A::*TAmtd)(int);  
  
   struct B {  
      TAmtd p;  
   };  
  
   void g() {  
      B b1;  
      b1.p = f;   // C3867  
   }  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3867.  
  
```  
// C3867_5.cpp  
// compile with: /EHsc  
#include <iostream>  
  
class Testpm {  
public:  
   void m_func1() {  
      std::cout << m_num << "\tm_func1\n";   
    }  
  
   int m_num;  
   typedef void (Testpm::*pmfn1)();  
   void func(Testpm* p);  
};  
  
void Testpm::func(Testpm* p) {  
   pmfn1 s = m_func1;   // C3867  
   pmfn1 s2 = &Testpm::m_func1;   // OK  
   (p->*s2)();  
}  
  
int main() {  
   Testpm *pTestpm = new Testpm;  
   pTestpm->m_num = 10;  
  
   pTestpm->func(pTestpm);  
}  
```
