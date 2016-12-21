---
title: "Cont&#234;ineres STL/CLR | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "contêineres, STL/CLR"
  - "STL/CLR, contêineres"
ms.assetid: 34ca8031-2041-46b9-aed9-29082d1972ea
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres STL/CLR
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca de STL\/CLR tem os mesmos contêiner que são encontradas na biblioteca padrão C\+\+, mas é executado dentro do ambiente gerenciado do.NET Framework.  Se você já estiver familiarizado com a biblioteca padrão \(STL\) do modelo, STL\/CLR é a melhor maneira de continuar a usar as habilidades que você já tem desenvolvido para atualizar o seu código para atingir Common Language Runtime \(CLR\).  
  
 Este documento fornece uma visão geral dos contêineres em STL\/CLR, como os requisitos para elementos de contêiner, os tipos de elementos que podem ser inseridos nos contêineres, e a propriedade emite aos elementos dos contêineres.  Quando apropriado, diferenças entre a biblioteca padrão nativo do modelo e STL\/CLR são citados.  
  
## Os requisitos para os elementos do recipiente  
 Todos os elementos inseridos em contêineres STL devem obedecer determinadas diretrizes.  Para obter mais informações, consulte [Requisitos dos elementos de contêiner STL\/CLR](../Topic/Requirements%20for%20STL-CLR%20Container%20Elements.md).  
  
## Elementos válidos do contêiner  
 Os contêineres de STL\/CLR pode conter um dos dois tipos de elementos:  
  
-   Identificadores para referenciar tipos.  
  
-   Tipos de referência.  
  
-   Tipos de valor Unboxed.  
  
 Você não pode inserir tipos de valor boxed em alguns dos contêineres de STL\/CLR.  
  
### Identificadores para referenciar tipos  
 Você pode inserir um identificador em um tipo de referência em um contêiner de STL\/CLR.  Um identificador em C\+\+ que se destinam CLR equivale a um ponteiro em C\+\+ nativo.  Para obter mais informações, consulte [Operador Handle to Object \(^\)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md).  
  
#### Exemplo  
 O exemplo a seguir mostra como inserir um identificador para um objeto de funcionário em [cliext::set](../dotnet/set-stl-clr.md).  
  
```  
// cliext_container_valid_reference_handle.cpp  
// compile with: /clr  
  
#include <cliext/set>  
  
using namespace cliext;  
using namespace System;  
  
ref class Employee  
{  
public:  
    // STL containers might require a public constructor, so it  
    // is a good idea to define one.  
    Employee() :  
        name(nullptr),  
        employeeNumber(0) { }  
  
    // All STL containers require a public copy constructor.  
    Employee(const Employee% orig) :  
        name(orig.name),  
        employeeNumber(orig.employeeNumber) { }  
  
    // All STL containers require a public assignment operator.  
    Employee% operator=(const Employee% orig)  
    {  
        if (this != %orig)  
        {  
            name = orig.name;  
            employeeNumber = orig.employeeNumber;  
        }  
  
        return *this;  
    }  
  
    // All STL containers require a public destructor.  
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
  
### Tipos de referência  
 Também é possível inserir um tipo de referência \(em vez de um identificador em um tipo de referência\) em um contêiner de STL\/CLR.  A principal diferença é que aqui quando um contêiner de tipos de referência é excluído, o destruidor é chamado para todo o interior de elementos que contêiner.  Em um contêiner das alças para referenciar tipos, os destruidores para esses elementos não serão chamados.  
  
#### Exemplo  
 O exemplo a seguir mostra como inserir um objeto de funcionário em `cliext::set`.  
  
```  
// cliext_container_valid_reference.cpp  
// compile with: /clr  
  
#include <cliext/set>  
  
using namespace cliext;  
using namespace System;  
  
ref class Employee  
{  
public:  
    // STL containers might require a public constructor, so it  
    // is a good idea to define one.  
    Employee() :  
        name(nullptr),  
        employeeNumber(0) { }  
  
    // All STL containers require a public copy constructor.  
    Employee(const Employee% orig) :  
        name(orig.name),  
        employeeNumber(orig.employeeNumber) { }  
  
    // All STL containers require a public assignment operator.  
    Employee% operator=(const Employee% orig)  
    {  
        if (this != %orig)  
        {  
            name = orig.name;  
            employeeNumber = orig.employeeNumber;  
        }  
  
        return *this;  
    }  
  
    // All STL containers require a public destructor.  
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
  
### Tipos de valor Unboxed  
 Você também pode inserir um tipo de valor unboxed em um contêiner de STL\/CLR.  Um tipo de valor unboxed é um tipo de valor que *não é encaixotado* em um tipo de referência.  
  
 Um elemento do tipo de valor pode ser um dos tipos de valores padrão, como `int`, ou pode ser um tipo de valor definido pelo usuário, como `value class`.  Para obter mais informações, consulte [Classes and Structs](../windows/classes-and-structs-cpp-component-extensions.md)  
  
#### Exemplo  
 O exemplo a seguir altera o primeiro exemplo fazendo à classe do funcionário um tipo de valor.  Esse tipo de valor é inserido em `cliext::set` assim como no primeiro exemplo.  
  
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
  
 Se você tentar inserir um identificador em um tipo de valor em um contêiner, [Erro do Compilador C3225](../error-messages/compiler-errors-2/compiler-error-c3225.md) será gerado.  
  
### Implicações de desempenho e de memória  
 Você deve considerar vários fatores ao determinar se use as alças para referenciar tipos ou tipos de valores como elementos do contêiner.  Se você decidir usar tipos de valor, lembre\-se de que uma cópia do elemento é feita sempre que a um elemento será inserida no contêiner.  Para objetos pequenos, isso não deve ser um problema, mas se os objetos que estão sendo inseridos forem grandes, o desempenho pode ser afetado.  Além disso, se você estiver usando tipos de valor, é impossível armazenar ao mesmo tempo um elemento em vários contêineres como cada contêiner teria sua própria cópia do elemento.  
  
 Se você decidir usar as alças para referenciar tipos em vez disso, o desempenho pode aumentar pois não é necessário fazer uma cópia do elemento quando é inserido no contêiner.  Além disso, ao contrário do com os tipos de valor, o mesmo elemento pode existir em vários contêineres.  No entanto, se você decidir usar identificadores, você deve tomar cuidado para assegurar que o identificador é válido e que o objeto que faz referência não esteve excluída em outro lugar no programa.  
  
## Problemas de propriedade com contêineres  
 Contêineres do trabalho de STL\/CLR na semântica do valor.  Cada vez que você insere um elemento em um contêiner, uma cópia desse elemento é inserida.  Se você desejar obter referência\- como a semântica, é possível inserir um identificador para um objeto em vez do próprio objeto.  
  
 Quando você chama o espaço livre ou apaga o método de um contêiner de objetos de identificador, os objetos que fazem referência aos identificadores não são liberados de memória.  Você deve excluir ou explicitamente o objeto, ou, porque esses objetos residem no heap gerenciado, permite que o coletor de lixo liberar a memória depois que determina se o objeto está sendo usado.  
  
## Consulte também  
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)