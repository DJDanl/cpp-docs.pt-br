---
title: Visão geral de membros de classe
ms.date: 11/04/2016
helpviewer_keywords:
- members [C++], types of class members
- members [C++]
- class members [C++], types of
- class members
ms.assetid: 8802cfa9-705d-4f37-acde-245d6838010c
ms.openlocfilehash: 8edfadefdacf94685952d31f2eaf83e8593eaef8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386103"
---
# <a name="class-member-overview"></a>Visão geral de membros de classe

Uma classe ou struct consiste em seus membros. O trabalho que faz uma classe é executado por suas funções de membro. O estado que ele mantém é armazenado em seus membros de dados. Inicialização de membros é feita por construtores e trabalho de limpeza, como a liberação de memória e liberação de recursos é feita pelo destruidores. No C++ 11 e posterior, os membros de dados pode (e geralmente deve) ser inicializados no ponto de declaração.

## <a name="kinds-of-class-members"></a>Tipos de membros de classe

A lista completa das categorias de membro é da seguinte maneira:

- [Funções de membro especial](special-member-functions.md).

- [Visão geral das funções de membro](overview-of-member-functions.md).

- [Membros de dados](static-members-cpp.md) tipos definidos pelo incluindo tipos internos e outro usuário.

- Operadores

- [Declarações de classes aninhadas](nested-class-declarations.md) e.)

- [Uniões](unions.md)

- [Enumerações](../cpp/enumerations-cpp.md).

- [Campos de bit](../cpp/cpp-bit-fields.md).

- [Amigos](../cpp/friend-cpp.md).

- [Aliases e typedefs](../cpp/aliases-and-typedefs-cpp.md).

    > [!NOTE]
    >  Os friends são incluídos na lista anterior porque estão contidos na declaração da classe. Porém, eles não são membros da classe true, pois não estão no escopo da classe.

## <a name="example-class-declaration"></a>Exemplo de declaração de classe

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

Os membros de uma classe são declarados na lista de membros. A lista de membros de uma classe pode ser dividida em qualquer número de **privados**, **protegido** e **público** seções usando palavras-chave conhecidas como especificadores de acesso.  Dois-pontos **:** deve seguir o especificador de acesso.  Essas seções não precisam ser contíguas, ou seja, qualquer uma dessas palavras-chave pode aparecer várias vezes na lista de membros.  A palavra-chave designa o acesso de todos os membros acima até o próximo especificador de acesso ou a próxima chave de fechamento. Para obter mais informações, consulte [controle de acesso de membro (C++)](../cpp/member-access-control-cpp.md).

## <a name="static-members"></a>Membros estáticos

Um membro de dados pode ser declarado como estática, o que significa que todos os objetos da classe têm acesso à mesma cópia dele. Uma função de membro pode ser declarada como estática, nesse caso, ele pode acessar somente os membros de dados estáticos da classe (e não tem nenhum *isso* ponteiro). Para obter mais informações, consulte [membros de dados estáticos](../cpp/static-members-cpp.md).

## <a name="special-member-functions"></a>Funções de membro especiais

Funções de membro especiais são funções que são fornecidas automaticamente pelo compilador se você não especificá-los no seu código-fonte.

1. Construtor padrão

1. Construtor de cópia

1. **(C++11)**  Construtor de movimentação

1. Operador de atribuição de cópia

1. **(C++11)**  Operador de atribuição de movimentação

1. Destruidor

Para obter mais informações, consulte [funções de membro especial](../cpp/special-member-functions.md).

## <a name="memberwise-initialization"></a>A inicialização

No C++ 11 e posterior, os declaradores de membro não estático podem conter inicializadores.

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

Se um membro é atribuído um valor em um construtor, esse valor substituirá o valor com o qual o membro foi inicializado no ponto de declaração.

Há apenas uma cópia compartilhada membros de dados estáticos para todos os objetos de um determinado tipo de classe. Os membros de dados estáticos devem ser definidos e podem ser inicializados no escopo do arquivo. (Para obter mais informações sobre membros de dados estáticos, consulte [membros de dados estáticos](../cpp/static-members-cpp.md).) O exemplo a seguir mostra como realizar essas inicializações:

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

## <a name="see-also"></a>Consulte também

[Classes e Structs](../cpp/classes-and-structs-cpp.md)