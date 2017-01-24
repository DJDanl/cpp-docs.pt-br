---
title: "Aviso do compilador (n&#237;vel 2) C4250 | Microsoft Docs"
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
  - "C4250"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4250"
ms.assetid: d47f7249-6b5a-414b-b2d4-56e5d246a782
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 2) C4250
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“class1”: herda “class2::member” por meio de domínio  
  
 Dois ou mais membros têm o mesmo nome.  Nesse `class2` é herdado como é uma classe base para as outras classes que contêm esse membro.  
  
 Para suprimir C4250, use o pragma de [warning](../../preprocessor/warning.md) .  
  
 Porque uma classe base virtual é compartilhada entre várias classes derivadas, um nome em uma classe derivada corresponde ao mestre um nome em uma classe base.  Por exemplo, na hierarquia a seguir da classe, há duas definições de funcional herdado no losango: a instância de vbc::func\(\) pela classe e, e o dominant::func\(\) pela classe dominante.  Uma chamada não qualificado de func\(\) por meio de um objeto da classe de losangos, chama sempre a instância de dominate::func\(\) .  Se a classe for fraca introduzir uma instância de func\(\), nenhuma definição dominaria, e a chamada será sinalizada como ambígua.  
  
```  
// C4250.cpp  
// compile with: /c /W2  
#include <stdio.h>  
struct vbc {  
   virtual void func() { printf("vbc::func\n"); }  
};  
  
struct weak : public virtual vbc {};  
  
struct dominant : public virtual vbc {  
   void func() { printf("dominant::func\n"); }  
};  
  
struct diamond : public weak, public dominant {};  
  
int main() {  
   diamond d;  
   d.func();   // C4250  
}  
```  
  
## Exemplo  
 O exemplo a seguir produz C4250.  
  
```  
// C4250_b.cpp  
// compile with: /W2 /EHsc  
#include <iostream>  
using namespace std;  
class A {  
public:  
   virtual operator int () {  
      return 2;  
   }  
};  
  
class B : virtual public A {  
public:  
   virtual operator int () {  
      return 3;  
   }  
};  
  
class C : virtual public A {};  
  
class E : public B, public C {};   // C4250  
  
int main() {  
   E eObject;  
   cout << eObject.operator int() << endl;  
}  
```  
  
## Exemplo  
 Este exemplo mostra uma situação mais complexa.  O exemplo a seguir produz C4250.  
  
```  
// C4250_c.cpp  
// compile with: /W2 /EHsc  
#include <iostream>  
using namespace std;  
  
class V {  
public:  
   virtual int f() {  
      return 1024;  
   }  
};  
  
class B : virtual public V {  
public:  
   int b() {  
      return f(); // B::b() calls V::f()  
   }  
};  
  
class M : virtual public V {  
public:  
   int f() {  
      return 7;  
   }  
};  
  
// because of dominance, f() is M::f() inside D,  
// changing the meaning of B::b's f() call inside a D  
class D : public B, public M {};   // C4250  
  
int main() {  
   D d;  
   cout << "value is: " << d.b();   // invokes M::f()  
}  
```