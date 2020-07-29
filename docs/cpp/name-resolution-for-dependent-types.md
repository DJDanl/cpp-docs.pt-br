---
title: Resolução de nome para tipos dependentes
ms.date: 11/04/2016
ms.assetid: 34066bb4-0c79-4fd8-bda7-539a60a277ab
ms.openlocfilehash: de40bd056fe351e679ff32d9908c068ea4c6752a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227303"
---
# <a name="name-resolution-for-dependent-types"></a>Resolução de nome para tipos dependentes

Use **`typename`** para nomes qualificados em definições de modelo para informar ao compilador que o nome qualificado fornecido identifica um tipo. Para obter mais informações, consulte [TypeName](../cpp/typename.md).

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

A pesquisa de nome para nomes dependentes examina nomes do contexto da definição do modelo — no exemplo a seguir, esse contexto encontraria `myFunction(char)` — e o contexto da instanciação do modelo. No exemplo a seguir, o modelo é instanciado em Main; Portanto, o `MyNamespace::myFunction` é visível a partir do ponto de instanciação e é escolhido como a melhor correspondência. Se `MyNamespace::myFunction` fosse renomeado, `myFunction(char)` seria chamado.

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

```Output
Int MyNamespace::myFunction
```

### <a name="template-disambiguation"></a>Desambiguação de modelo

O Visual Studio 2012 impõe as regras padrão do C++ 98/03/11 para a desambiguidade com a palavra-chave "template". No exemplo a seguir, o Visual Studio 2010 aceitaria as linhas não conformes e as linhas em conformidade.  O Visual Studio 2012 aceita apenas as linhas em conformidade.

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

## <a name="see-also"></a>Confira também

[Resolução de nomes](../cpp/templates-and-name-resolution.md)
