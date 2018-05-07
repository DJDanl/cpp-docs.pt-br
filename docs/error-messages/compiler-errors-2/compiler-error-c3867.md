---
title: C3867 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3867
dev_langs:
- C++
helpviewer_keywords:
- C3867
ms.assetid: bc5de03f-e01a-4407-88c3-2c63f0016a1e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f39abadc4b8947c4b3c4ce24b847c8c3fc20bf6d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3867"></a>C3867 de erro do compilador
'func': chamada de função faltando lista de argumentos; Use ' & func' para criar um ponteiro para membro  
  
 Você tentou obter o endereço de uma função membro sem a qualificação da função de membro com seu nome de classe e o endereço do operador.  
  
 Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2005: conformidade aprimorada de ponteiro-para-membro. Código compilado antes do Visual C++ 2005 agora irá gerar C3867.  
  
## <a name="example"></a>Exemplo  
 C3867 podem ser emitidos do compilador com uma resolução sugerida enganoso. Sempre que possível, use a classe mais derivada.  
  
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