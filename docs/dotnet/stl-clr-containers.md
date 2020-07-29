---
title: Contêineres STL/CLR
ms.date: 09/18/2018
ms.topic: reference
helpviewer_keywords:
- STL/CLR, containers
- containers, STL/CLR
ms.assetid: 34ca8031-2041-46b9-aed9-29082d1972ea
ms.openlocfilehash: 04ba56bf4f134ac5e9b906f7f84563c00ffe1b96
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214861"
---
# <a name="stlclr-containers"></a>Contêineres STL/CLR

A biblioteca STL/CLR consiste em contêineres semelhantes aos encontrados na biblioteca padrão C++, mas é executado dentro do ambiente gerenciado do .NET Framework. Ela não é mantida atualizada com a biblioteca padrão C++ real e é mantida para suporte herdado.

Este documento fornece uma visão geral dos contêineres na STL/CLR, como os requisitos para elementos de contêiner, os tipos de elementos que você pode inserir nos contêineres e problemas de propriedade com os elementos nos contêineres. Quando apropriado, as diferenças entre a biblioteca padrão do C++ Standard e STL/CLR são mencionadas.

## <a name="requirements-for-container-elements"></a>Requisitos dos elementos de contêiner

Todos os elementos inseridos em contêineres STL/CLR devem obedecer a certas diretrizes. Para obter mais informações, consulte [Requirements for STL/CLR container Elements](../dotnet/requirements-for-stl-clr-container-elements.md).

## <a name="valid-container-elements"></a>Elementos de contêiner válidos

Os contêineres STL/CLR podem conter um dos dois tipos de elementos:

- Identificadores para tipos de referência.

- Tipos de referência.

- Tipos de valor desemoldurados.

Não é possível inserir tipos de valor boxed em nenhum dos contêineres STL/CLR.

### <a name="handles-to-reference-types"></a>Identificadores para tipos de referência

Você pode inserir um identificador para um tipo de referência em um contêiner STL/CLR. Um identificador em C++ que tem como alvo o CLR é análogo a um ponteiro no C++ nativo. Para obter mais informações, consulte [operador de identificador para objeto (^)](../extensions/handle-to-object-operator-hat-cpp-component-extensions.md).

#### <a name="example"></a>Exemplo

O exemplo a seguir mostra como inserir um identificador para um objeto Employee em um [cliext:: Set](../dotnet/set-stl-clr.md).

```cpp
// cliext_container_valid_reference_handle.cpp
// compile with: /clr

#include <cliext/set>

using namespace cliext;
using namespace System;

ref class Employee
{
public:
    // STL/CLR containers might require a public constructor, so it
    // is a good idea to define one.
    Employee() :
        name(nullptr),
        employeeNumber(0) { }

    // All STL/CLR containers require a public copy constructor.
    Employee(const Employee% orig) :
        name(orig.name),
        employeeNumber(orig.employeeNumber) { }

    // All STL/CLR containers require a public assignment operator.
    Employee% operator=(const Employee% orig)
    {
        if (this != %orig)
        {
            name = orig.name;
            employeeNumber = orig.employeeNumber;
        }

        return *this;
    }

    // All STL/CLR containers require a public destructor.
    ~Employee() { }

    // Associative containers such as maps and sets
    // require a comparison operator to be defined
    // to determine proper ordering.
    bool operator<(const Employee^ rhs)
    {
        return (employeeNumber < rhs->employeeNumber);
    }

    // The employee's name.
    property String^ Name
    {
        String^ get() { return name; }
        void set(String^ value) { name = value; }
    }

    // The employee's employee number.
    property int EmployeeNumber
    {
        int get() { return employeeNumber; }
        void set(int value) { employeeNumber = value; }
    }

private:
    String^ name;
    int employeeNumber;
};

int main()
{
    // Create a new employee object.
    Employee^ empl1419 = gcnew Employee();
    empl1419->Name = L"Darin Lockert";
    empl1419->EmployeeNumber = 1419;

    // Add the employee to the set of all employees.
    set<Employee^>^ emplSet = gcnew set<Employee^>();
    emplSet->insert(empl1419);

    // List all employees of the company.
    for each (Employee^ empl in emplSet)
    {
        Console::WriteLine("Employee Number {0}: {1}",
            empl->EmployeeNumber, empl->Name);
    }

    return 0;
}
```

### <a name="reference-types"></a>Tipos de referência

Também é possível inserir um tipo de referência (em vez de um identificador para um tipo de referência) em um contêiner STL/CLR. A principal diferença aqui é que, quando um contêiner de tipos de referência é excluído, o destruidor é chamado para todos os elementos dentro desse contêiner. Em um contêiner de identificadores para tipos de referência, os destruidores desses elementos não seriam chamados.

#### <a name="example"></a>Exemplo

O exemplo a seguir mostra como inserir um objeto Employee em um `cliext::set` .

```cpp
// cliext_container_valid_reference.cpp
// compile with: /clr

#include <cliext/set>

using namespace cliext;
using namespace System;

ref class Employee
{
public:
    // STL/CLR containers might require a public constructor, so it
    // is a good idea to define one.
    Employee() :
        name(nullptr),
        employeeNumber(0) { }

    // All STL/CLR containers require a public copy constructor.
    Employee(const Employee% orig) :
        name(orig.name),
        employeeNumber(orig.employeeNumber) { }

    // All STL/CLR containers require a public assignment operator.
    Employee% operator=(const Employee% orig)
    {
        if (this != %orig)
        {
            name = orig.name;
            employeeNumber = orig.employeeNumber;
        }

        return *this;
    }

    // All STL/CLR containers require a public destructor.
    ~Employee() { }

    // Associative containers such as maps and sets
    // require a comparison operator to be defined
    // to determine proper ordering.
    bool operator<(const Employee^ rhs)
    {
        return (employeeNumber < rhs->employeeNumber);
    }

    // The employee's name.
    property String^ Name
    {
        String^ get() { return name; }
        void set(String^ value) { name = value; }
    }

    // The employee's employee number.
    property int EmployeeNumber
    {
        int get() { return employeeNumber; }
        void set(int value) { employeeNumber = value; }
    }

private:
    String^ name;
    int employeeNumber;
};

int main()
{
    // Create a new employee object.
    Employee empl1419;
    empl1419.Name = L"Darin Lockert";
    empl1419.EmployeeNumber = 1419;

    // Add the employee to the set of all employees.
    set<Employee>^ emplSet = gcnew set<Employee>();
    emplSet->insert(empl1419);

    // List all employees of the company.
    for each (Employee^ empl in emplSet)
    {
        Console::WriteLine("Employee Number {0}: {1}",
            empl->EmployeeNumber, empl->Name);
    }

    return 0;
}
```

### <a name="unboxed-value-types"></a>Tipos de valor unboxed

Você também pode inserir um tipo de valor unboxed em um contêiner STL/CLR. Um tipo de valor unboxed é um tipo de valor que não foi *encaixado* em um tipo de referência.

Um elemento de tipo de valor pode ser um dos tipos de valor padrão, como um **`int`** , ou pode ser um tipo de valor definido pelo usuário, como um **`value class`** . Para obter mais informações, consulte [classes e structs](../extensions/classes-and-structs-cpp-component-extensions.md)

#### <a name="example"></a>Exemplo

O exemplo a seguir modifica o primeiro exemplo fazendo com que a classe Employee seja um tipo Value. Esse tipo de valor é inserido em um, assim `cliext::set` como no primeiro exemplo.

```cpp
// cliext_container_valid_valuetype.cpp
// compile with: /clr

#include <cliext/set>

using namespace cliext;
using namespace System;

value class Employee
{
public:
    // Associative containers such as maps and sets
    // require a comparison operator to be defined
    // to determine proper ordering.
    bool operator<(const Employee^ rhs)
    {
        return (employeeNumber < rhs->employeeNumber);
    }

    // The employee's name.
    property String^ Name
    {
        String^ get() { return name; }
        void set(String^ value) { name = value; }
    }

    // The employee's employee number.
    property int EmployeeNumber
    {
        int get() { return employeeNumber; }
        void set(int value) { employeeNumber = value; }
    }

private:
    String^ name;
    int employeeNumber;
};

int main()
{
    // Create a new employee object.
    Employee empl1419;
    empl1419.Name = L"Darin Lockert";
    empl1419.EmployeeNumber = 1419;

    // Add the employee to the set of all employees.
    set<Employee>^ emplSet = gcnew set<Employee>();
    emplSet->insert(empl1419);

    // List all employees of the company.
    for each (Employee empl in emplSet)
    {
        Console::WriteLine("Employee Number {0}: {1}",
            empl.EmployeeNumber, empl.Name);
    }

    return 0;
}
```

Se você tentar inserir um identificador para um tipo de valor em um contêiner, o [erro do compilador C3225](../error-messages/compiler-errors-2/compiler-error-c3225.md) será gerado.

### <a name="performance-and-memory-implications"></a>Implicações de desempenho e memória

Você deve considerar vários fatores ao determinar se deve usar identificadores para referenciar tipos ou tipos de valor como elementos de contêiner. Se você decidir usar tipos de valor, lembre-se de que uma cópia do elemento é feita toda vez que um elemento é inserido no contêiner. Para objetos pequenos, isso não deve ser um problema, mas se os objetos que estão sendo inseridos forem grandes, o desempenho poderá ser prejudicado. Além disso, se você estiver usando tipos de valor, é impossível armazenar um elemento em vários contêineres ao mesmo tempo porque cada contêiner teria sua própria cópia do elemento.

Se você decidir usar identificadores para referenciar tipos, o desempenho poderá aumentar porque não é necessário fazer uma cópia do elemento quando ele for inserido no contêiner. Além disso, ao contrário dos tipos de valor, o mesmo elemento pode existir em vários contêineres. No entanto, se você decidir usar identificadores, deverá ter cuidado para garantir que o identificador seja válido e que o objeto ao qual ele se refere não tenha sido excluído em outro lugar do programa.

## <a name="ownership-issues-with-containers"></a>Problemas de propriedade com contêineres

Os contêineres na STL/CLR funcionam na semântica de valor. Toda vez que você insere um elemento em um contêiner, uma cópia desse elemento é inserida. Se você quiser obter semântica semelhante à referência, poderá inserir um identificador para um objeto em vez do próprio objeto.

Quando você chama o método Clear ou Erase de um contêiner de objetos Handle, os objetos aos quais os identificadores se referem não são liberados da memória. Você deve excluir explicitamente o objeto ou, como esses objetos residem no heap gerenciado, permita que o coletor de lixo libere a memória depois de determinar que o objeto não está mais sendo usado.

## <a name="see-also"></a>Confira também

[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
