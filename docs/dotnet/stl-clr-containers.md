---
title: "Contêineres STL/CLR | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- STL/CLR, containers
- containers, STL/CLR
ms.assetid: 34ca8031-2041-46b9-aed9-29082d1972ea
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 1b8aa8ef5b1425d4aa41b1811dca5ec5d56acd1c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="stlclr-containers"></a>Contêineres STL/CLR
A biblioteca STL/CLR tem os mesmos contêineres que são encontrados na biblioteca C++ padrão, mas ele é executado dentro do ambiente gerenciado do .NET Framework. Se você já estiver familiarizado com a biblioteca padrão C++ STL/CLR é a melhor maneira para continuar a usar as habilidades que você já criou durante a atualização do seu código para o common language runtime (CLR) de destino.  
  
 Este documento fornece uma visão geral dos contêineres STL/CLR, como os requisitos dos elementos de contêiner, os tipos de elementos que você pode inserir os contêineres e propriedade problemas com os elementos nos contêineres. Quando apropriado, as diferenças entre a biblioteca padrão C++ nativo e a STL/CLR são mencionadas.  
  
## <a name="requirements-for-container-elements"></a>Requisitos dos elementos de contêiner  
 Todos os elementos inseridos em contêineres de biblioteca padrão C++ devem obedecer a determinadas diretrizes. Para obter mais informações, consulte [requisitos para elementos de contêiner STL/CLR](../dotnet/requirements-for-stl-clr-container-elements.md).  
  
## <a name="valid-container-elements"></a>Elementos de contêiner válido  
 Contêineres STL/CLR podem conter um dos dois tipos de elementos:  
  
-   Trata-se para tipos de referência.  
  
-   Tipos de referência.  
  
-   Tipos de valor não Demarcado.  
  
 Você não é possível inserir tipos de valor demarcado em qualquer um dos contêineres STL/CLR.  
  
### <a name="handles-to-reference-types"></a>Identificadores de tipos de referência  
 Você pode inserir um identificador para um tipo de referência em um contêiner STL/CLR. Um identificador em C++ que tem como alvo o CLR é análogo a um ponteiro em C++ nativo. Para obter mais informações, consulte [operador Handle to Object (^)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md).  
  
#### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como inserir um identificador para um objeto de funcionário em um [cliext::set](../dotnet/set-stl-clr.md).  
  
```  
// cliext_container_valid_reference_handle.cpp  
// compile with: /clr  
  
#include <cliext/set>  
  
using namespace cliext;  
using namespace System;  
  
ref class Employee  
{  
public:  
    // C++ Standard Library containers might require a public constructor, so it  
    // is a good idea to define one.  
    Employee() :  
        name(nullptr),  
        employeeNumber(0) { }  
  
    // All C++ Standard Library containers require a public copy constructor.  
    Employee(const Employee% orig) :  
        name(orig.name),  
        employeeNumber(orig.employeeNumber) { }  
  
    // All C++ Standard Library containers require a public assignment operator.  
    Employee% operator=(const Employee% orig)  
    {  
        if (this != %orig)  
        {  
            name = orig.name;  
            employeeNumber = orig.employeeNumber;  
        }  
  
        return *this;  
    }  
  
    // All C++ Standard Library containers require a public destructor.  
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
 Também é possível inserir um tipo de referência (em vez de um identificador para um tipo de referência) em um contêiner STL/CLR. A principal diferença é que, quando um contêiner de tipos de referência é excluído, o destruidor é chamado para todos os elementos desse contêiner. Em um contêiner de identificadores para tipos de referência, não serão chamados destruidores para esses elementos.  
  
#### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como inserir um objeto de funcionário em um `cliext::set`.  
  
```  
// cliext_container_valid_reference.cpp  
// compile with: /clr  
  
#include <cliext/set>  
  
using namespace cliext;  
using namespace System;  
  
ref class Employee  
{  
public:  
    // C++ Standard Library containers might require a public constructor, so it  
    // is a good idea to define one.  
    Employee() :  
        name(nullptr),  
        employeeNumber(0) { }  
  
    // All C++ Standard Library containers require a public copy constructor.  
    Employee(const Employee% orig) :  
        name(orig.name),  
        employeeNumber(orig.employeeNumber) { }  
  
    // All C++ Standard Library containers require a public assignment operator.  
    Employee% operator=(const Employee% orig)  
    {  
        if (this != %orig)  
        {  
            name = orig.name;  
            employeeNumber = orig.employeeNumber;  
        }  
  
        return *this;  
    }  
  
    // All C++ Standard Library containers require a public destructor.  
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
  
### <a name="unboxed-value-types"></a>Tipos de valor não demarcado  
 Você também pode inserir um tipo de valor não demarcado em um contêiner STL/CLR. Um valor não demarcado é um tipo de valor que não tenha sido *box* em um tipo de referência.  
  
 Um elemento de tipo de valor pode ser um dos tipos de valor padrão, como um `int`, ou pode ser um tipo de valor definido pelo usuário, como um `value class`. Para obter mais informações, consulte [Classes e estruturas](../windows/classes-and-structs-cpp-component-extensions.md)  
  
#### <a name="example"></a>Exemplo  
 O exemplo a seguir modifica o primeiro exemplo, fazendo com que o funcionário um tipo de valor de classe. Este tipo de valor é inserido em um `cliext::set` assim como no primeiro exemplo.  
  
```  
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
  
 Se você tentar inserir um identificador para um tipo de valor em um contêiner, [C3225 de erro do compilador](../error-messages/compiler-errors-2/compiler-error-c3225.md) é gerado.  
  
### <a name="performance-and-memory-implications"></a>Desempenho e as implicações de memória  
 Você deve considerar vários fatores ao determinar se irá usar identificadores para referenciar tipos ou tipos de valor como elementos de contêiner. Se você decidir usar tipos de valor, lembre-se de que é feita uma cópia do elemento toda vez que um elemento é inserido no contêiner. Para objetos pequenos, ele não deve ser um problema, mas se os objetos que estão sendo inseridos forem grandes, o desempenho poderá ser prejudicado. Além disso, se você estiver usando tipos de valor, é impossível armazenar um elemento em vários contêineres ao mesmo tempo, porque cada contêiner deve ter sua própria cópia do elemento.  
  
 Se você decidir usar identificadores para tipos de referência em vez disso, o desempenho pode aumentar porque não é necessário fazer uma cópia do elemento quando ele é inserido no contêiner. Além disso, ao contrário de com tipos de valor, o mesmo elemento pode existir em vários contêineres. No entanto, se você decidir usar identificadores, você deve ter cuidado para garantir que o identificador é válido e que o objeto se refere a não foi excluído em outro lugar no programa.  
  
## <a name="ownership-issues-with-containers"></a>Problemas de propriedade com contêineres  
 Contêineres STL/CLR funcionam na semântica de valor. Sempre que você insere um elemento em um contêiner, uma cópia desse elemento é inserida. Se você deseja obter a semântica de referência, você pode inserir um identificador para um objeto, em vez do próprio objeto.  
  
 Quando você chamar a limpar ou apaga o método de um contêiner de objetos de identificador, os objetos que fazem referência os identificadores não são liberados da memória. Você deve explicitamente excluir o objeto, ou, porque esses objetos residem no heap gerenciado, permitir que o coletor de lixo liberar a memória depois que ele determina que o objeto não está sendo usado.  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)