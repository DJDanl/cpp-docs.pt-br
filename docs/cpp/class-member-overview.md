---
title: Visão geral de membros de classe
ms.date: 11/04/2016
helpviewer_keywords:
- members [C++], types of class members
- members [C++]
- class members [C++], types of
- class members
ms.assetid: 8802cfa9-705d-4f37-acde-245d6838010c
ms.openlocfilehash: 7847de072b2c0d5b95597e88f9ebf7e2ad63e180
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180947"
---
# <a name="class-member-overview"></a>Visão geral de membros de classe

Uma classe ou estrutura consiste em seus membros. O trabalho que uma classe faz é executado por suas funções de membro. O estado que ele mantém é armazenado em seus membros de dados. A inicialização de membros é feita por construtores e o trabalho de limpeza, como a liberação de memória e a liberação de recursos, é feito por destruidores. No C++ 11 e posterior, os membros de dados podem (e geralmente devem) ser inicializados no ponto de declaração.

## <a name="kinds-of-class-members"></a>Tipos de membros de classe

A lista completa de categorias de membros é a seguinte:

- [Funções de membro especiais](special-member-functions.md).

- [Visão geral das funções de membro](overview-of-member-functions.md).

- [Membros de dados](static-members-cpp.md) , incluindo tipos internos e outros tipos definidos pelo usuário.

- Operadores

- [Declarações de classe aninhadas](nested-class-declarations.md) e.)

- [Uniões](unions.md)

- [Enumerações](../cpp/enumerations-cpp.md).

- [Campos de bits](../cpp/cpp-bit-fields.md).

- [Amigos](../cpp/friend-cpp.md).

- [Aliases e TYPEDEFs](../cpp/aliases-and-typedefs-cpp.md).

    > [!NOTE]
    >  Os friends são incluídos na lista anterior porque estão contidos na declaração da classe. Porém, eles não são membros da classe true, pois não estão no escopo da classe.

## <a name="example-class-declaration"></a>Declaração de classe de exemplo

O exemplo a seguir mostra uma declaração de classe simples:

```cpp
// TestRun.h

class TestRun
{
    // Start member list.

    //The class interface accessible to all callers.
public:
    // Use compiler-generated default constructor:
    TestRun() = default;
    // Don't generate a copy constructor:
    TestRun(const TestRun&) = delete;
    TestRun(std::string name);
    void DoSomething();
    int Calculate(int a, double d);
    virtual ~TestRun();
    enum class State { Active, Suspended };

    // Accessible to this class and derived classes only.
protected:
    virtual void Initialize();
    virtual void Suspend();
    State GetState();

    // Accessible to this class only.
private:
    // Default brace-initialization of instance members:
    State _state{ State::Suspended };
    std::string _testName{ "" };
    int _index{ 0 };

    // Non-const static member:
    static int _instances;
    // End member list.
};

// Define and initialize static member.
int TestRun::_instances{ 0 };
```

## <a name="member-accessibility"></a>Acessibilidade de membro

Os membros de uma classe são declarados na lista de membros. A lista de membros de uma classe pode ser dividida em qualquer número de seções **privadas**, **protegidas** e **públicas** usando palavras-chave conhecidas como especificadores de acesso.  Dois-pontos **:** deve seguir o especificador de acesso.  Essas seções não precisam ser contíguas, ou seja, qualquer uma dessas palavras-chave pode aparecer várias vezes na lista de membros.  A palavra-chave designa o acesso de todos os membros acima até o próximo especificador de acesso ou a próxima chave de fechamento. Para obter mais informações, consulte [controle de acessoC++de membro ()](../cpp/member-access-control-cpp.md).

## <a name="static-members"></a>Membros estáticos

Um membro de dados pode ser declarado como estático, o que significa que todos os objetos da classe têm acesso à mesma cópia dele. Uma função de membro pode ser declarada como estática; nesse caso, ela só pode acessar membros de dados estáticos da classe (e não tem *esse* ponteiro). Para obter mais informações, consulte [membros de dados estáticos](../cpp/static-members-cpp.md).

## <a name="special-member-functions"></a>Funções de membro especiais

Funções de membro especiais são funções que são fornecidas automaticamente pelo compilador se você não especificá-las em seu código-fonte.

1. Construtor padrão

1. O construtor de cópia.

1. **(C++ 11)** Mover Construtor

1. Operador de atribuição de cópia

1. **(C++ 11)** Mover operador de atribuição

1. Destruidor

Para obter mais informações, consulte [funções de membro especiais](../cpp/special-member-functions.md).

## <a name="memberwise-initialization"></a>Inicialização do memberwise

No C++ 11 e posterior, os declaradores de membro não estáticos podem conter inicializadores.

```cpp
class CanInit
{
public:
    long num {7};       // OK in C++11
    int k = 9;          // OK in C++11
    static int i = 9; // Error: must be defined and initialized
                      // outside of class declaration.

    // initializes num to 7 and k to 9
    CanInit(){}

    // overwrites original initialized value of num:
    CanInit(int val) : num(val) {}
};
int main()
{
}
```

Se um membro for atribuído a um valor em um construtor, esse valor substituirá o valor com o qual o membro foi inicializado no ponto de declaração.

Há apenas uma cópia compartilhada membros de dados estáticos para todos os objetos de um determinado tipo de classe. Os membros de dados estáticos devem ser definidos e podem ser inicializados no escopo do arquivo. (Para obter mais informações sobre membros de dados estáticos, consulte [membros de dados estáticos](../cpp/static-members-cpp.md).) O exemplo a seguir mostra como executar essas inicializações:

```cpp
// class_members2.cpp
class CanInit2
{
public:
    CanInit2() {} // Initializes num to 7 when new objects of type
                 //  CanInit are created.
    long     num {7};
    static int i;
    static int j;
};

// At file scope:

// i is defined at file scope and initialized to 15.
// The initializer is evaluated in the scope of CanInit.
int CanInit2::i = 15;

// The right side of the initializer is in the scope
// of the object being initialized
int CanInit2::j = i;
```

> [!NOTE]
>  O nome da classe, `CanInit2`, deve preceder `i` para especificar que `i` que está sendo definida é um membro da classe `CanInit2`.

## <a name="see-also"></a>Confira também

[Classes e Structs](../cpp/classes-and-structs-cpp.md)
