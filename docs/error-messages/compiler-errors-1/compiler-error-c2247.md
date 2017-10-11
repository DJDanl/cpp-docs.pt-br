---
title: C2247 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2247
dev_langs:
- C++
helpviewer_keywords:
- C2247
ms.assetid: 72efa03e-615e-4ef9-aede-0a98654b20fd
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 64eafb23ca83cb61ac9b45cf9c84ba69365f8198
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2247"></a>C2247 de erro do compilador
'Identificador' não está acessível porque 'class' usa 'especificador' para herdar de 'class'  
  
 `identifier`é herdada de uma classe declarada com acesso particular ou protegido.  
  
 O exemplo a seguir gera C2247:  
  
```  
// C2247.cpp  
class A {  
public:  
   int i;  
};  
class B : private A {};    // B inherits a private A  
class C : public B {} c;   // so even though C's B is public  
int j = c.i;               // C2247, i not accessible  
```  
  
 Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: controle com membros protegidos de acesso. Um membro protegido (n) só pode ser acessado através de uma função de membro de uma classe (B) que herda da classe (A) do qual ele (n) é um membro.  
  
 Para o código que é válido no Visual Studio .NET 2003 e versões do Visual Studio .NET do Visual C++, declare o membro seja um amigo do tipo. Herança pública também pode ser usada.  
  
```  
// C2247b.cpp  
// compile with: /c  
// C2247 expected  
class A {  
public:  
   void f();  
   int n;  
};  
  
class B: protected A {  
   // Uncomment the following line to resolve.  
   // friend void A::f();  
};  
  
void A::f() {  
   B b;  
   b.n;  
}  
```  
  
 C2247 também podem ser gerados como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: privada as classes base agora inacessível. Uma classe (A) que é uma classe base privada para um tipo não (B) deve estar acessível para um tipo (C) que usa B como uma classe base.  
  
 Para o código que é válido no Visual Studio .NET 2003 e versões do Visual Studio .NET do Visual C++, use o operador de escopo.  
  
```  
// C2247c.cpp  
// compile with: /c  
struct A {};  
  
struct B: private A {};  
  
struct C : B {  
   void f() {  
      A *p1 = (A*) this;   // C2247  
      // try the following line instead  
      // ::A *p2 = (::A*) this;  
   }  
};  
```
