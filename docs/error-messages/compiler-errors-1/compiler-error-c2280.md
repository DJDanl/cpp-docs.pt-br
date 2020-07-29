---
title: Erro do compilador C2280
ms.date: 04/25/2017
f1_keywords:
- C2280
helpviewer_keywords:
- C2280
ms.assetid: e6c5b1fb-2b9b-4554-8ff9-775eeb37161b
ms.openlocfilehash: 9ee5b8105241ee347812a0dcc083a4f1cc7dca49
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87208402"
---
# <a name="compiler-error-c2280"></a>Erro do compilador C2280

'*declaração*': tentando referenciar uma função excluída

O compilador detectou uma tentativa de fazer referência a uma `deleted` função. Esse erro pode ser causado por uma chamada a uma função de membro que foi explicitamente marcada como `= deleted` no código-fonte. Esse erro também pode ser causado por uma chamada para uma função de membro especial implícita de uma struct ou classe que é declarada automaticamente e marcada como `deleted` pelo compilador. Para obter mais informações sobre quando o compilador gera automaticamente **`default`** ou `deleted` funções de membro especiais, consulte [funções de membro especiais](../../cpp/special-member-functions.md).

## <a name="example-explicitly-deleted-functions"></a>Exemplo: funções explicitamente excluídas

Uma chamada para uma `deleted` função explícita causa esse erro. Uma `deleted` função membro explicitamente implica que a classe ou struct foi intencionalmente projetada para impedir seu uso, portanto, para corrigir esse problema, você deve alterar seu código para evitá-lo.

```cpp
// C2280_explicit.cpp
// compile with: cl /c /W4 C2280_explicit.cpp
struct A {
    A();
    A(int) = delete;
};

struct B {
    A a1;
    A a2 = A(3); // C2280, calls deleted A::A(int)
    // To fix, remove the call to A(int)
};

void f() {
    B b;    // calls implicit B::B(void)
}
```

## <a name="example-uninitialized-data-members"></a>Exemplo: membros de dados não inicializados

Um membro de dados de tipo de referência não inicializado ou **`const`** membro de dados faz com que o compilador declare implicitamente um `deleted` construtor padrão. Para corrigir esse problema, inicialize o membro de dados quando ele for declarado.

```cpp
// C2280_uninit.cpp
// compile with: cl /c C2280_uninit.cpp
struct A {
    const int i; // uninitialized const-qualified data
    // members or reference type data members cause
    // the implicit default constructor to be deleted.
    // To fix, initialize the value in the declaration:
    // const int i = 42;
} a;    // C2280
```

## <a name="example-reference-and-const-data-members"></a>Exemplo: membros de dados Reference e const

Um **`const`** membro de dados do tipo de referência a ou faz com que o compilador declare um `deleted` operador de atribuição de cópia. Depois de inicializados, esses membros não podem ser atribuídos a, portanto, uma cópia ou movimentação simples não funciona. Para corrigir esse problema, recomendamos que você altere sua lógica para remover as operações de atribuição que causam o erro.

```cpp
// C2280_ref.cpp
// compile with: cl /c C2280_ref.cpp
extern int k;
struct A {
    A();
    int& ri = k; // a const or reference data member causes
    // implicit copy assignment operator to be deleted.
};

void f() {
    A a1, a2;
    // To fix, consider removing this assignment.
    a2 = a1;    // C2280
}
```

## <a name="example-movable-deletes-implicit-copy"></a>Exemplo: móvel exclui a cópia implícita

Se uma classe declarar um Construtor mover ou mover o operador de atribuição, mas não declarar explicitamente um construtor de cópia, o compilador declarará implicitamente um construtor de cópia e o definirá como `deleted` . Da mesma forma, se uma classe declarar um construtor de movimentação ou um operador de atribuição de movimento, mas não declarar explicitamente um operador de atribuição de cópia, o compilador declarará implicitamente um operador de atribuição de cópia e o definirá como `deleted` . Para corrigir esse problema, você deve declarar explicitamente esses membros.

Quando você vir o erro C2280 em conexão com um `unique_ptr` , é quase certamente porque você está tentando invocar seu construtor de cópia, que é uma `deleted` função. Por design, um `unique_ptr` não pode ser copiado. Use um Construtor move para transferir a propriedade.

```cpp
// C2280_move.cpp
// compile with: cl /c C2280_move.cpp
class base
{
public:
    base();
    ~base();
    base(base&&);
    // Move constructor causes copy constructor to be
    // implicitly declared as deleted. To fix this
    // issue, you can explicitly declare a copy constructor:
    // base(base&);
    // If you want the compiler default version, do this:
    // base(base&) = default;
};

void copy(base *p)
{
    base b{*p};  // C2280
}
```

## <a name="example-variant-and-volatile-members"></a>Exemplo: variante e membros voláteis

As versões do compilador antes do Visual Studio 2015 atualização 2 eram não compatíveis e geraram construtores e destruidores padrão para uniões anônimas. Agora, eles estão implicitamente declarados como `deleted` . Essas versões também permitiam a definição implícita não compatível de **`default`** construtores de copiar e mover e **`default`** operadores de atribuição de copiar e mover em classes e estruturas que têm **`volatile`** variáveis de membro. O compilador agora considera que eles têm construtores não triviais e operadores de atribuição, e não gera **`default`** implementações. Quando essa classe é membro de uma União ou de uma União anônima dentro de uma classe, os construtores copiar e mover e os operadores de atribuição copiar e mover da União ou da classe são definidos implicitamente como `deleted` . Para corrigir esse problema, você deve declarar explicitamente as funções de membro especiais necessárias.

```cpp
// C2280_variant.cpp
// compile with: cl /c C2280_variant.cpp
struct A {
    A() = default;
    A(const A&);
};

struct B {
    union {
        A a;
        int i;
    };
    // To fix this issue, declare the required
    // special member functions:
    // B();
    // B(const B& b);
};

int main() {
    B b1;
    B b2(b1);  // C2280
}
```

## <a name="example-indirect-base-members-deleted"></a>Exemplo: membros de base indiretos excluídos

As versões do compilador antes do Visual Studio 2015 atualização 2 eram não em conformidade e permitia que uma classe derivada chamasse funções de membro especiais de classes base indiretamente derivadas `private virtual` . O compilador agora emite C2280 de erro do compilador quando tal chamada é feita.

Neste exemplo, a classe `top` deriva indiretamente de virtual privada `base` . No código de conformidade, isso torna os membros de `base` inacessíveis para `top` ; um objeto do tipo `top` não pode ser construído ou destruído padrão. Para corrigir esse problema no código que dependia do comportamento do compilador antigo, altere a classe intermediária para usar a `protected virtual` derivação ou altere a `top` classe para usar a derivação direta:

```cpp
// C2280_indirect.cpp
// compile with: cl /c C2280_indirect.cpp
class base
{
protected:
    base();
    ~base();
};

class middle : private virtual base {};
// Possible fix: Replace line above with:
// class middle : protected virtual base {};
class top : public virtual middle {};    // C4594, C4624
// Another possible fix: use direct derivation:
// class top : public virtual middle, private virtual base {};

void destroy(top *p)
{
    delete p;  // C2280
}
```
