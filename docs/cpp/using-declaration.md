---
title: "Declara&#231;&#227;o de uso | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "usando declaração"
  - "declarando namespaces, nomes não qualificados em namespaces"
  - "declarações [C++], declaração using"
  - "namespaces [C++], nomes não qualificados em"
  - "palavra-chave using [C++]"
  - "declarações [C++], namespaces"
ms.assetid: 4184e2b1-3adc-408e-b5f3-0b3f8b554723
caps.latest.revision: 12
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Declara&#231;&#227;o de uso
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A declaração `using` introduz um nome na região declarativa em que a declaração `using` aparece.  
  
## Sintaxe  
  
```  
  
      using [typename][::] nested-name-specifier unqualified-id  
using :: unqualified-id  
```  
  
## Comentários  
 O nome se torna um sinônimo para uma entidade declarada em outro lugar.  Permite que um nome *individual* de um namespace específico seja usado sem [qualificação explícita](../misc/explicit-qualification.md).  Isso contrasta com a política `using`, que permite que *todos* os nomes em um namespace sejam usados sem qualificação.  Consulte [Diretiva using](../misc/using-directive-cpp.md) para obter mais informações.  Essa palavra\-chave é usada também para [aliases de tipo](../cpp/aliases-and-typedefs-cpp.md).  
  
## Exemplo  
 Uma declaração using pode ser usada em uma definição de classe.  
  
```cpp  
// using_declaration1.cpp  
#include <stdio.h>  
class B {  
public:  
   void f(char) {  
      printf_s("In B::f()\n");  
   }  
  
   void g(char) {  
      printf_s("In B::g()\n");  
   }  
};  
  
class D : B {  
public:  
   using B::f;  
   using B::g;  
   void f(int) {  
      printf_s("In D::f()\n");  
      f('c');  
   }  
  
   void g(int) {  
      printf_s("In D::g()\n");  
      g('c');  
   }  
};  
  
int main() {  
   D myD;  
   myD.f(1);  
   myD.g('a');  
}  
```  
  
  **In D::f\(\)**  
**In B::f\(\)**  
**In B::g\(\)**   
## Exemplo  
 Quando usada para declarar um membro, uma declaração using deve se referir a um membro de uma classe base.  
  
```cpp  
// using_declaration2.cpp  
#include <stdio.h>  
  
class B {  
public:  
   void f(char) {  
      printf_s("In B::f()\n");  
   }  
  
   void g(char) {  
      printf_s("In B::g()\n");  
   }  
};  
  
class C {  
public:  
   int g();  
};  
  
class D2 : public B {  
public:  
   using B::f;   // ok: B is a base of D2  
   // using C::g;   // error: C isn't a base of D2  
};  
  
int main() {  
   D2 MyD2;  
   MyD2.f('a');  
}  
```  
  
  **In B::f\(\)**   
## Exemplo  
 Os membros declarados com uma declaração using podem ser referenciados usando a qualificação explícita.  O prefixo `::` refere\-se ao namespace global.  
  
```cpp  
// using_declaration3.cpp  
#include <stdio.h>  
  
void f() {  
   printf_s("In f\n");  
}  
  
namespace A {  
   void g() {  
      printf_s("In A::g\n");  
   }  
}  
  
namespace X {  
   using ::f;   // global f  
   using A::g;   // A's g  
}  
  
void h() {  
   printf_s("In h\n");  
   X::f();   // calls ::f  
   X::g();   // calls A::g  
}  
  
int main() {  
   h();  
}  
```  
  
  **In h**  
**In f**  
**In A::g**   
## Exemplo  
 Quando uma declaração using é feita, o sinônimo criado pela declaração se refere apenas às definições que são válidas no ponto da declaração using.  As definições adicionadas a um namespace depois da declaração using são sinônimos inválidos.  
  
 Um nome definido por uma declaração using é um alias para o nome original.  Não afeta o tipo, a vinculação ou outros atributos da declaração original.  
  
```cpp  
// post_declaration_namespace_additions.cpp  
// compile with: /c  
namespace A {  
   void f(int) {}  
}  
  
using A::f;   // f is a synonym for A::f(int) only  
  
namespace A {  
   void f(char) {}  
}  
  
void f() {  
   f('a');   // refers to A::f(int), even though A::f(char) exists  
}  
  
void b() {  
   using A::f;   // refers to A::f(int) AND A::f(char)  
   f('a');   // calls A::f(char);  
}  
```  
  
## Exemplo  
 Com relação às funções nos namespaces, se um conjunto de declarações locais e declarações using para um único nome for fornecido em uma região declarativa, todas as declarações deverão referenciar a mesma entidade, ou referenciar funções.  
  
```cpp  
// functions_in_namespaces1.cpp  
// C2874 expected  
namespace B {  
    int i;  
    void f(int);  
    void f(double);  
}  
  
void g() {  
    int i;  
    using B::i;   // error: i declared twice  
    void f(char);  
    using B::f;   // ok: each f is a function  
}  
```  
  
 No exemplo anterior, a instrução `using B::i` faz com que um segundo `int i` seja declarado na função `g()`.  A instrução `using B::f` não entra em conflito com a função `f(char)` porque os nomes de função introduzidos por `B::f` têm tipos de parâmetro diferentes.  
  
## Exemplo  
 Uma declaração de função local não pode ter o mesmo nome e tipo que uma função introduzida usando a declaração.  Por exemplo:  
  
```cpp  
// functions_in_namespaces2.cpp  
// C2668 expected  
namespace B {  
    void f(int);  
    void f(double);  
}  
  
namespace C {  
    void f(int);  
    void f(double);  
    void f(char);  
}  
  
void h() {  
    using B::f;          // introduces B::f(int) and B::f(double)  
    using C::f;          // C::f(int), C::f(double), and C::f(char)  
    f('h');              // calls C::f(char)  
    f(1);                // C2668 ambiguous: B::f(int) or C::f(int)?  
    void f(int);         // C2883 conflicts with B::f(int) and C::f(int)  
}  
```  
  
## Exemplo  
 No que diz respeito à herança, quando uma declaração using introduz um nome de uma classe base em um escopo de classe derivada, as funções de membro na classe derivada substituem funções de membro virtuais com o mesmo nome e tipo de argumento na classe base.  
  
```cpp  
// using_declaration_inheritance1.cpp  
#include <stdio.h>  
struct B {  
   virtual void f(int) {  
      printf_s("In B::f(int)\n");  
   }  
  
   virtual void f(char) {  
      printf_s("In B::f(char)\n");  
   }  
  
   void g(int) {  
      printf_s("In B::g\n");  
   }  
  
   void h(int);  
};  
  
struct D : B {  
   using B::f;  
   void f(int) {   // ok: D::f(int) overrides B::f(int)  
      printf_s("In D::f(int)\n");  
   }  
  
   using B::g;  
   void g(char) {   // ok: there is no B::g(char)  
      printf_s("In D::g(char)\n");  
   }  
  
   using B::h;  
   void h(int) {}   // Note: D::h(int) hides non-virtual B::h(int)  
};  
  
void f(D* pd) {  
   pd->f(1);   // calls D::f(int)  
   pd->f('a');   // calls B::f(char)  
   pd->g(1);   // calls B::g(int)  
   pd->g('a');   // calls D::g(char)  
}  
  
int main() {  
   D * myd = new D();  
   f(myd);  
}  
```  
  
  **In D::f\(int\)**  
**In B::f\(char\)**  
**In B::g**  
**In D::g\(char\)**   
## Exemplo  
 Todas as instâncias de um nome mencionado em uma declaração using devem estar acessíveis.  Em particular, se uma classe derivada usar uma declaração using para acessar um membro de uma classe base, o nome do membro deverá ser acessível.  Se o nome for o de uma função de membro sobrecarregada, todas as funções nomeadas deverão estar acessíveis.  
  
 Consulte [Controle de acesso de membros](../cpp/member-access-control-cpp.md) para obter mais informações sobre a acessibilidade de membros.  
  
```cpp  
// using_declaration_inheritance2.cpp  
// C2876 expected  
class A {  
private:  
   void f(char);  
public:  
   void f(int);  
protected:  
   void g();  
};  
  
class B : public A {  
   using A::f;   // C2876: A::f(char) is inaccessible  
public:  
   using A::g;   // B::g is a public synonym for A::g  
};  
```  
  
## Consulte também  
 [Namespaces](../cpp/namespaces-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)