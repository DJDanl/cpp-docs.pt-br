---
title: A resolução de nome para nomes declarados localmente | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 743b88f3-de11-48f4-ae83-931449ea3886
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6347f3b0b71dc35544f22101479de23bb4efd686
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="name-resolution-for-locally-declared-names"></a>Resolução de nome para nomes declarados localmente

O nome de modelo propriamente dito pode ser referenciado com ou sem os argumentos de modelo. No escopo de um modelo de classe, o nome propriamente dito se refere ao modelo. No escopo de uma especialização ou de uma especialização parcial de modelo, o nome sozinho se refere à especialização ou à especialização parcial. Outras especializações ou especializações parciais do modelo também podem ser referenciadas, com os argumentos de modelo apropriados.  
  
## <a name="example"></a>Exemplo

 O código a seguir mostra que o nome do modelo de classe A é interpretado de maneira diferente no escopo de uma especialização ou especialização parcial.  
  
```cpp
// template_name_resolution3.cpp  
// compile with: /c  
template <class T> class A {  
   A* a1;   // A refers to A<T>  
   A<int>* a2;  // A<int> refers to a specialization of A.  
   A<T*>* a3;   // A<T*> refers to the partial specialization A<T*>.  
};  
  
template <class T> class A<T*> {  
   A* a4; // A refers to A<T*>.  
};  
  
template<> class A<int> {  
   A* a5; // A refers to A<int>.  
};  
```  
  
## <a name="example"></a>Exemplo

 Em caso de conflito de nome entre um parâmetro de modelo e outro objeto, o parâmetro de modelo pode ou não ser oculto. As regras a seguir ajudam a determinar a precedência.  
  
 O parâmetro de modelo está no escopo desde o ponto onde aparece primeiro até o final do modelo de classe ou de função. Se o nome aparece novamente na lista de argumentos do modelo ou na lista de classes base, ele faz referência ao mesmo tipo. No C++ padrão, nenhum outro nome idêntico ao parâmetro de modelo pode ser declarado no mesmo escopo. Uma extensão da Microsoft permite que o parâmetro de modelo seja redefinido no escopo do modelo. O exemplo a seguir mostra o uso do parâmetro de modelo na especificação da base de um modelo de classe.  
  
```cpp
// template_name_resolution4.cpp  
// compile with: /EHsc  
template <class T>  
class Base1 {};  
  
template <class T>  
class Derived1 : Base1<T> {};  
  
int main() {  
   // Derived1<int> d;  
}  
```  
  
## <a name="example"></a>Exemplo

 Ao definir as funções de membro de um modelo fora do modelo de classe, é possível usar um nome de parâmetro de modelo diferente. Se a definição de função de membro de modelo usar, para o parâmetro de modelo, um nome diferente do usado pela declaração e o nome usado na definição entrar em conflito com outro membro da declaração, o membro na declaração de modelo terá precedência.  
  
```cpp
// template_name_resolution5.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
template <class T> class C {  
public:  
   struct Z {  
      Z() { cout << "Z::Z()" << endl; }  
   };  
   void f();  
};  
  
template <class Z>  
void C<Z>::f() {  
   // Z refers to the struct Z, not to the template arg;  
   // Therefore, the constructor for struct Z will be called.  
   Z z;  
}  
  
int main() {  
   C<int> c;  
   c.f();  
}  
```  
  
```Output  
Z::Z()  
```  
  
## <a name="example"></a>Exemplo

 Ao definir uma função de modelo ou uma função de membro fora do namespace no qual o modelo foi declarado, o argumento de modelo tem precedência sobre os nomes de outros membros do namespace.  
  
```cpp
// template_name_resolution6.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
namespace NS {  
   void g() { cout << "NS::g" << endl; }  
  
   template <class T> struct C {  
      void f();  
      void g() { cout << "C<T>::g" << endl; }  
   };  
};  
  
template <class T>  
void NS::C<T>::f() {  
   g(); // C<T>::g, not NS::g  
};  
  
int main() {  
   NS::C<int> c;  
   c.f();  
}  
```  
  
```Output  
C<T>::g  
```  
  
## <a name="example"></a>Exemplo

 Nas definições que estão fora da declaração de classe de modelo, se uma classe de modelo tiver uma classe base que não dependa de um argumento de modelo e se a classe base ou um de seus membros tiver o mesmo nome que um argumento de modelo, a classe base ou o nome de membro ocultarão o argumento de modelo.  
  
```cpp
// template_name_resolution7.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
struct B {  
   int i;  
   void print() { cout << "Base" << endl; }  
};  
  
template <class T, int i> struct C : public B {  
   void f();  
};  
  
template <class B, int i>  
void C<B, i>::f() {  
   B b;   // Base class b, not template argument.  
   b.print();  
   i = 1; // Set base class's i to 1.  
}  
  
int main() {  
   C<int, 1> c;  
   c.f();  
   cout << c.i << endl;  
}  
```  
  
```Output  
Base  
1  
```  
  
## <a name="see-also"></a>Consulte também

 [Resolução de nome](../cpp/templates-and-name-resolution.md)
