---
title: "Resolução de nomes para tipos dependentes | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
ms.assetid: 34066bb4-0c79-4fd8-bda7-539a60a277ab
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5d8978e38745f088884bbf28ffb0ab98cfb87895
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="name-resolution-for-dependent-types"></a>Resolução de nome para tipos dependentes
Use **typename** para nomes qualificados em definições de modelo para informar ao compilador que o nome qualificado determinado identifica um tipo. Para obter mais informações, consulte [typename](../cpp/typename.md).  
  
```cpp  
// template_name_resolution1.cpp  
#include <stdio.h>  
template <class T> class X  
{  
public:  
   void f(typename T::myType* mt) {}  
};  
  
class Yarg  
{  
public:  
   struct myType { };  
};  
  
int main()  
{  
   X<Yarg> x;  
   x.f(new Yarg::myType());  
   printf("Name resolved by using typename keyword.");  
}  
```  
  
```Output  
Name resolved by using typename keyword.  
```  
  
 Pesquisa de nome para nomes de dependente examina os nomes do contexto da definição de modelo — no exemplo a seguir, neste contexto encontraria `myFunction(char)`— e o contexto de instanciação de modelo. No exemplo a seguir, o modelo é instanciado no principal; Portanto, o `MyNamespace::myFunction` é visível a partir do ponto de instanciação e é escolhida como a melhor correspondência. Se `MyNamespace::myFunction` fosse renomeado, `myFunction(char)` seria chamado.  
  
 Todos os nomes são resolvidos como se fossem nomes dependentes. Entretanto, recomendamos que você use nomes totalmente qualificados se houver qualquer conflito possível.  
  
```cpp  
// template_name_resolution2.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
void myFunction(char)  
{  
   cout << "Char myFunction" << endl;  
}  
  
template <class T> class Class1  
{  
public:  
   Class1(T i)  
   {  
      // If replaced with myFunction(1), myFunction(char)  
      // will be called  
      myFunction(i);  
}  
};  
  
namespace MyNamespace  
{  
   void myFunction(int)  
   {  
      cout << "Int MyNamespace::myFunction" << endl;  
   }  
};  
  
using namespace MyNamespace;  
  
int main()  
{  
   Class1<int>* c1 = new Class1<int>(100);  
}  
```  
  
### <a name="output"></a>Saída  
  
```  
Int MyNamespace::myFunction  
```  
  
### <a name="template-disambiguation"></a>Desambiguação de modelo  
 O [!INCLUDE[cpp_dev11_long](../build/includes/cpp_dev11_long_md.md)] impõem as regras do padrão C++98/03/11 para a desambiguação com a palavra-chave “template”. No exemplo a seguir, o Visual C++ 2010 aceite as linhas não está em conformidade e as linhas estão em conformidade.  [!INCLUDE[cpp_dev11_long](../build/includes/cpp_dev11_long_md.md)]aceita apenas as linhas estão em conformidade.  
  
```cpp  
#include <iostream>  
#include <ostream>  
#include <typeinfo>  
using namespace std;  
  
template <typename T> struct Allocator {  
    template <typename U> struct Rebind {  
        typedef Allocator<U> Other;  
    };  
};  
  
template <typename X, typename AY> struct Container {  
    #if defined(NONCONFORMANT)  
        typedef typename AY::Rebind<X>::Other AX; // nonconformant  
    #elif defined(CONFORMANT)  
        typedef typename AY::template Rebind<X>::Other AX; // conformant  
    #else  
        #error Define NONCONFORMANT or CONFORMANT.  
    #endif  
};  
  
int main() {  
    cout << typeid(Container<int, Allocator<float>>::AX).name() << endl;  
}  
```  
  
 A conformidade com as regras de desambiguação é necessária porque, por padrão, o C++ presume que `AY::Rebind` não seja um modelo e, assim, o compilador interpreta o seguinte “`<`” como menor que. Ele precisa saber que `Rebind` é um modelo para poder analisar corretamente “`<`” como um colchete angular.  
  
## <a name="see-also"></a>Consulte também  
 [Resolução de nome](../cpp/templates-and-name-resolution.md)