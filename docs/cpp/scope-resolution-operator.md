---
title: 'Operador de resolução do escopo: ::'
ms.date: 11/04/2016
f1_keywords:
- '::'
helpviewer_keywords:
- scope, scope resolution operator
- operators [C++], scope resolution
- scope resolution operator
- ':: operator'
ms.assetid: fd5de9d3-c716-4e12-bae9-03a16fd79a50
ms.openlocfilehash: e601bed976009a72a43545d8d38a38d75e93a137
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50452267"
---
# <a name="scope-resolution-operator-"></a>Operador de resolução do escopo: ::

O operador de resolução de escopo **::** é usado para identificar e resolver a ambiguidade de identificadores usados em escopos diferentes. Para obter mais informações sobre escopo, consulte [escopo](../cpp/scope-visual-cpp.md).

## <a name="syntax"></a>Sintaxe

```
:: identifier
class-name :: identifier
namespace :: identifier
enum class :: identifier
enum struct :: identifier
```

## <a name="remarks"></a>Comentários

O `identifier` pode ser uma variável, uma função ou um valor de enumeração.

## <a name="with-classes-and-namespaces"></a>Com classes e namespaces

O exemplo a seguir mostra como o operador de resolução do escopo é usado com namespaces e classes:

```cpp
namespace NamespaceA{
    int x;
    class ClassA {
    public:
        int x;
    };
}

int main() {

    // A namespace name used to disambiguate
    NamespaceA::x = 1;

    // A class name used to disambiguate
    NamespaceA::ClassA a1;
    a1.x = 2;
}
```

Um operador de resolução do escopo sem um qualificador de escopo refere-se ao namespace global.

```cpp
namespace NamespaceA{
    int x;
}

int x;

int main() {
    int x;

    // the x in main()
    x = 0;
    // The x in the global namespace
    ::x = 1;

    // The x in the A namespace
    NamespaceA::x = 2;
}
```

Você pode usar o operador de resolução do escopo para identificar um membro de um namespace ou para identificar um namespace que nomeia namespace de membros em uma diretiva de uso. No exemplo abaixo, você pode usar `NamespaceC` para qualificar `ClassB`, embora `ClassB` tenha sido declarada em namespace `NamespaceB` porque `NamespaceB` foi nomeado em `NamespaceC` por uma diretiva de uso.

```cpp
namespace NamespaceB {
    class ClassB {
    public:
        int x;
    };
}

namespace NamespaceC{
    using namespace B;
}
int main() {
    NamespaceB::ClassB c_b;
    NamespaceC::ClassB c_c;

    c_b.x = 3;
    c_c.x = 4;
}
```

Você pode usar cadeias de operadores de resolução do escopo. No exemplo a seguir, `NamespaceD::NamespaceD1` identifica o namespace aninhado `NamespaceD1` e `NamespaceE::ClassE::ClassE1` identifica a classe aninhada `ClassE1`.

```cpp
namespace NamespaceD{
    namespace NamespaceD1{
        int x;
    }
}

namespace NamespaceE{
    class ClassE{
    public:
        class ClassE1{
        public:
            int x;
        };
    };
}

int main() {
    NamespaceD:: NamespaceD1::x = 6;
    NamespaceE::ClassE::ClassE1 e1;
    e1.x = 7  ;
}
```

## <a name="with-static-members"></a>Com membros estáticos

Você deve usar o operador de resolução do escopo para chamar membros estáticos de classes.

```cpp
class ClassG {
public:
    static int get_x() { return x;}
    static int x;
};

int ClassG::x = 6;

int main() {

    int gx1 = ClassG::x;
    int gx2 = ClassG::get_x();
}
```

## <a name="with-scoped-enumerations"></a>Com enumerações de escopo

O operador de resolução do escopo também é usado com os valores de uma enumeração com escopo [declarações de enumeração](../cpp/enumerations-cpp.md), conforme mostrado no exemplo a seguir:

```cpp
enum class EnumA{
    First,
    Second,
    Third
};

int main() {
    EnumA enum_value = EnumA::First;
}
```

## <a name="see-also"></a>Consulte também

[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Namespaces](../cpp/namespaces-cpp.md)