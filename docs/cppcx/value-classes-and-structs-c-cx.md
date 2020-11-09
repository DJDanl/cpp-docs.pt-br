---
title: Classes e estruturas de valor (C++/CX)
ms.date: 12/30/2016
helpviewer_keywords:
- value struct
- value class
ms.assetid: 262a0992-9721-4c02-8297-efc07d90e5a4
ms.openlocfilehash: 15d54d139f086ce5bb025aaeab145c71d33903c0
ms.sourcegitcommit: 3f0c1dcdcce25865d1a1022bcc5b9eec79f69025
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2020
ms.locfileid: "94381591"
---
# <a name="value-classes-and-structs-ccx"></a>Classes e estruturas de valor (C++/CX)

Uma *classe* de *valor ou struct* é um pod compatível com Windows Runtime ("estrutura de dados simples antiga"). Ela tem um tamanho fixo e consiste somente em campos; diferentemente de uma classe ref, ela não tem propriedades.

Os exemplos a seguir mostram como declarar e inicializar estruturas de valor.

```

// in mainpage.xaml.h:
    value struct TestStruct
    {
        Platform::String^ str;
        int i;
    };

    value struct TestStruct2
    {
        TestStruct ts;
        Platform::String^ str;
        int i;
    };

// in mainpage.cpp:
    // Initialize a value struct with an int and String
    TestStruct ts = {"I am a TestStruct", 1};

    // Initialize a value struct that contains
    // another value struct, an int and a String
    TestStruct2 ts2 = {{"I am a TestStruct", 1}, "I am a TestStruct2", 2};

    // Initialize value struct members individually.
    TestStruct ts3;
    ts3.i = 108;
    ts3.str = "Another way to init a value struct.";
```

Quando uma variável de um tipo de valor é atribuída a outra variável, o valor é copiado para que cada uma das duas variáveis tenha sua própria cópia dos dados. Um *struct de valor* é uma estrutura de tamanho fixo que contém somente campos de dados públicos e é declarada usando a **`value struct`** palavra-chave.

Uma *classe de valor* é exatamente como uma **`value struct`** , exceto que seus campos devem receber explicitamente a acessibilidade pública. Ele é declarado usando a **`value class`** palavra-chave.

Uma classe de valor ou struct pode conter como campos apenas tipos numéricos fundamentais, classes enum, `Platform::String^` ou [Platform:: iBox \<T> ^ ](../cppcx/platform-ibox-interface.md) , em que T é um tipo numérico ou classe enum ou classe de valor ou struct. Um `IBox<T>^` campo pode ter um valor de **`nullptr`** – é assim que o C++ implementa o conceito de *tipos de valores anuláveis*.

Uma classe ou uma estrutura de valor que contém um tipo `Platform::String^` ou `IBox<T>^` como membro não aceita `memcpy`.

Como todos os membros de um **`value class`** ou **`value struct`** são públicos e são emitidos em metadados, os tipos C++ padrão não são permitidos como membros. Isso é diferente das classes ref, que podem conter **`private`** ou **`internal`** tipos C++ padrão.

O fragmento de código a seguir declara os tipos `Coordinates` e `City` como estruturas de valor. Observe que um dos membros de dados `City` é um tipo `GeoCoordinates` . Um **`value struct`** pode conter outras structs de valor como membros.

[!code-cpp[cx_classes#07](../cppcx/codesnippet/CPP/classesstructs/class1.h#07)]

## <a name="parameter-passing-for-value-types"></a>Passagem de parâmetro para tipos de valor

Se você tiver um valor de tipo como um parâmetro de função ou método, ele será normalmente transmitido por valor. Para objetos maiores, isso pode causar um problema de desempenho. Em Visual Studio 2013 e anteriores, os tipos de valor em C++/CX eram sempre passados por valor. No Visual Studio de 2015 e posteriores, você pode passar tipos de valor por referência ou por valor.

Para declarar um parâmetro que transmita um tipo de valor por valor, use um código como o seguinte:

```cpp
void Method1(MyValueType obj);
```

Para declarar um parâmetro que passe um tipo de valor por referência, use o símbolo de referência (&) como no exemplo a seguir:

```cpp
void Method2(MyValueType& obj);
```

O tipo dentro de Method2 é uma referência a MyValueType e funciona da mesma maneira que um tipo de referência no C++ padrão.

Quando você chama Method1 de outra linguagem, como o C#, não é necessário usar a palavra-chave `ref` ou `out` . Quando você chamar Method2, use a palavra-chave `ref` .

```
Method2(ref obj);
```

Você também pode usar um símbolo de ponteiro (*) para transmitir um tipo de valor por referência. O comportamento com relação a autores da chamada em outras linguagens é o mesmo (os autores da chamada em C# usam a palavra-chave `ref` ), mas no método, o tipo é um ponteiro para o tipo de valor.

## <a name="nullable-value-types"></a>Tipos de valor anuláveis

Como mencionado anteriormente, uma classe Value ou um struct de valor pode ter um campo do tipo [Platform: \<T> ^ : iBox](../cppcx/platform-ibox-interface.md)— por exemplo, `IBox<int>^` . Esse campo pode ter qualquer valor numérico válido para o **`int`** tipo ou pode ter um valor de **`nullptr`** . Você pode transmitir um campo anulável como argumento para um método cujo parâmetro seja declarado como opcional ou para qualquer lugar em que um tipo de valor não precise ter um valor.

O exemplo a seguir mostra como inicializar uma estrutura que tem um campo que permite valor nulo.

```
public value struct Student
{
    Platform::String^ Name;
    int EnrollmentYear;
    Platform::IBox<int>^ GraduationYear; // Null if not yet graduated.
};
//To create a Student struct, one must populate the nullable type.
MainPage::MainPage()
{
    InitializeComponent();

    Student A;
    A.Name = "Alice";
    A.EnrollmentYear = 2008;
    A.GraduationYear = ref new Platform::Box<int>(2012);

    Student B;
    B.Name = "Bob";
    B.EnrollmentYear = 2011;
    B.GraduationYear = nullptr;

    IsCurrentlyEnrolled(A);
    IsCurrentlyEnrolled(B);
}
bool MainPage::IsCurrentlyEnrolled(Student s)
{
    if (s.GraduationYear == nullptr)
    {
        return true;
    }
    return false;
}
```

A própria estrutura de valor pode permitir valor nulo da mesma forma, como é mostrado aqui:

```

public value struct MyStruct
{
public:
    int i;
    Platform::String^ s;
};

public ref class MyClass sealed
{
public:
    property Platform::IBox<MyStruct>^ myNullableStruct;
};
```

## <a name="see-also"></a>Confira também

[Type System (C++/CX)](../cppcx/type-system-c-cx.md)<br/>
[Referência de linguagem do C++/CX](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)<br/>
[Classes e estruturas ref (C++/CX)](../cppcx/ref-classes-and-structs-c-cx.md)
