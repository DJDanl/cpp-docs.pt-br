---
title: "Erro do Compilador C2248 | Microsoft Docs"
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
  - "C2248"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2248"
ms.assetid: 7a3ba0e8-d3b9-4bb9-95db-81ef17e31d23
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2248
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“membro”: não pode acessar o membro de “acesso” declarado em classes das classes  
  
 Os membros de uma classe derivada não podem acessar membros de `private` de uma classe base.  Você não pode acessar `private` ou membros de `protected` das instâncias da classe.  
  
 Consulte o artigo da Base de Dados de Conhecimento KB243351 para obter mais informações sobre como C2248.  
  
 O seguinte exemplo gera C2248:  
  
```  
// C2248.cpp  
#include <stdio.h>  
class X {  
public:  
   int  m_pubMemb;  
   void setPrivMemb( int i ) {  
      m_privMemb = i;  
      printf_s("\n%d", m_privMemb);  
   }  
protected:  
   int  m_protMemb;  
  
private:  
   int  m_privMemb;  
} x;  
  
int main() {  
   x.m_pubMemb = 4;  
   printf_s("\n%d", x.m_pubMemb);  
   x.m_protMemb = 2;   // C2248 m_protMemb is protected  
   x.m_privMemb = 3;   // C2248  m_privMemb is private  
   x.setPrivMemb(0);   // OK uses public access function  
}  
```  
  
 Outro problema de conformidade que expõe C2248 é o uso de amigos e de conhecimento do modelo.  Para obter mais informações, consulte [O vinculador de ferramentas do erro LNK2019](../Topic/Linker%20Tools%20Error%20LNK2019.md).  
  
```  
// C2248_b.cpp  
template<class T>  
void f(T t) {  
   t.i;   // C2248  
}  
  
struct S {  
private:  
   int i;  
  
public:  
   S() {}  
   // Delete the following line to resolve.  
   friend void f(S);   // refer to the non-template function void f(S)  
  
   // Uncomment the following line to resolve.  
   // friend void f<S>(S);  
};  
  
int main() {  
   S s;  
   f<S>(s);  
}  
```  
  
 Outro problema de conformidade que expõe C2248 é quando você tentar declarar um amigo de uma classe e quando a classe não é visível à declaração de amigo no escopo da classe.  Nesse caso, amizade de concessão a classe inclusive para resolver o erro.  
  
```  
// C2248_c.cpp  
// compile with: /c  
class T {  
   class S {  
      class E {};  
   };  
   friend class S::E;   // C2248  
};  
  
class A {  
   class S {  
      class E {};  
      friend class A;   // grant friendship to enclosing class  
   };  
   friend class S::E;   // OK  
};  
```