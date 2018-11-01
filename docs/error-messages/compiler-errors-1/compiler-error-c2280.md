---
title: Erro do compilador C2280
ms.date: 04/25/2017
f1_keywords:
- C2280
helpviewer_keywords:
- C2280
ms.assetid: e6c5b1fb-2b9b-4554-8ff9-775eeb37161b
ms.openlocfilehash: e1ec032878fefdc1992605df5ee1aa13c673d4cf
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50572803"
---
# <a name="compiler-error-c2280"></a>Erro do compilador C2280

'*declaração*': tentativa de fazer referência a uma função excluída

O compilador detectou uma tentativa de fazer referência a um `deleted` função. Esse erro pode ser causado por uma chamada para uma função de membro que foi marcada explicitamente como `= deleted` no código-fonte. Esse erro também pode ser causado por uma chamada para uma função de membro especial implícito de um struct ou classe que é automaticamente declarado e marcado como `deleted` pelo compilador. Para obter mais informações sobre quando o compilador gera automaticamente `default` ou `deleted` funções de membro especial, consulte [funções de membro especial](../../cpp/special-member-functions.md).

## <a name="example-explicitly-deleted-functions"></a>Exemplo: Excluídos explicitamente funções

Uma chamada para um explicitamente `deleted` função faz com que esse erro. Um explicitamente `deleted` função de membro implica que a classe ou struct intencionalmente foi projetado para evitar seu uso, portanto, para corrigir esse problema, você deve alterar seu código para evitá-la.

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

## <a name="example-uninitialized-data-members"></a>Exemplo: Membros de dados não inicializados

Um membro de dados do tipo de referência não inicializado ou `const` membro de dados faz com que o compilador declarar implicitamente um `deleted` construtor padrão. Para corrigir esse problema, inicialize o membro de dados quando ele é declarado.

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

## <a name="example-reference-and-const-data-members"></a>Exemplo: Referência e constantes membros de dados

Um `const` ou membro de dados de tipo de referência faz com que o compilador declarar um `deleted` operador de atribuição de cópia. Depois de inicializado, esses membros não podem ser atribuídos, portanto, uma simple cópia ou movimentação não pode funcionar. Para corrigir esse problema, é recomendável que você altere sua lógica para remover as operações de atribuição que causam o erro.

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

## <a name="example-movable-deletes-implicit-copy"></a>Exemplo: Movidos exclui cópia implícita

Se uma classe declara um construtor de movimentação ou um operador de atribuição de movimentação, mas não declara explicitamente um construtor de cópia, o compilador implicitamente declara um construtor de cópia e define-o como `deleted`. Da mesma forma, se uma classe declara um construtor de movimentação ou um operador de atribuição de movimentação, mas não declara explicitamente um operador de atribuição de cópia, o compilador implicitamente declara um operador de atribuição de cópia e define-o como `deleted`. Para corrigir esse problema, você deve declarar explicitamente esses membros.

Quando você vir o erro C2280 em conexão com um `unique_ptr`, provavelmente é porque você está tentando invocar o construtor de cópia, que é um `deleted` função. Por design, um `unique_ptr` não pode ser copiado. Use um construtor de movimentação para transferir a propriedade em vez disso.

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

## <a name="example-variant-and-volatile-members"></a>Exemplo: Membros de Variant e volátil

Versões do compilador antes do Visual Studio 2015 atualização 2 foram construtores e destruidores para uniões anônimas padrão gerado e não conformes. Eles agora são implicitamente declarados como `deleted`. Essas versões também permitiam não conformes definição implícita da `default` copiar e mover os construtores e `default` copiar e mover os operadores de atribuição em classes e structs que têm `volatile` variáveis de membro. Agora o compilador considera ter construtores não-triviais e operadores de atribuição e não gera `default` implementações. Quando essa classe é um membro de uma união ou uma união anônima dentro de uma classe, os construtores de cópia e movimentação e operadores de atribuição de cópia e movimentação da união ou classe são definidos implicitamente como `deleted`. Para corrigir esse problema, você deve declarar explicitamente as funções de membro especial necessária.

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

## <a name="example-indirect-base-members-deleted"></a>Exemplo: Membros base indiretos excluídos

Versões do compilador antes do Visual Studio 2015 atualização 2 foram não conformes e permissão de uma classe derivada chamasse funções membro especial de derivadas indiretamente `private virtual` classes base. Agora, o compilador emite o erro do compilador C2280 quando essa chamada é feita.

Neste exemplo, a classe `top` deriva indiretamente de privada virtual `base`. No código de conformidade, isso faz com que os membros da `base` inacessível para `top`; um objeto do tipo `top` não pode ser padrão construído ou destruído. Para corrigir esse problema no código que usava o antigo comportamento do compilador, altere a classe intermediária para usar `protected virtual` derivação ou alterar o `top` classe usar derivação direta:

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
