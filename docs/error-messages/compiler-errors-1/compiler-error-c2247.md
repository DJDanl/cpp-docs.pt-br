---
title: "Erro do Compilador C2247 | Microsoft Docs"
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
  - "C2247"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2247"
ms.assetid: 72efa03e-615e-4ef9-aede-0a98654b20fd
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2247
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador” não acessível como” de “especificador do classes “a “herdar das classes  
  
 `identifier` é herdado de uma classe declarada com acesso particular ou protegido.  
  
 O seguinte exemplo gera C2247:  
  
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
  
 Esse erro também pode ser gerado no resultado do trabalho de conformidade do compilador que foi feito para Visual Studio .NET 2003:. controle de acesso com membros protegidos.  Um membro protegido \(n\) só pode ser acessado com uma função de membro de uma classe \(b\) que herde da classe \(a\) que ele \(n\) é um membro.  
  
 Para o código que é válido em versões do Visual Studio .NET. 2003 e do Visual Studio .NET do Visual C\+\+, declarar o membro para ser um amigo do tipo.  A herança pública também poderia ser usada.  
  
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
  
 C2247 também pode ser gerado no resultado do trabalho de conformidade do compilador que foi feito para Visual Studio .NET 2003:. classes base privadas agora inacessíveis.  Uma classe \(a\) que é uma classe base privada em um tipo \(b\) não deve ser acessível a um tipo \(c\) que usa B como uma classe base.  
  
 Para o código que é válido em versões do Visual Studio .NET. 2003 e do Visual Studio .NET do Visual C\+\+, use o operador do escopo.  
  
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