---
title: Classes e estruturas de valor (C + + c++ /CX) | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: language-reference
helpviewer_keywords:
- value struct
- value class
ms.assetid: 262a0992-9721-4c02-8297-efc07d90e5a4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 226198c35dc0b7e7e1c7fab4ce81fc4782b5ca38
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43764196"
---
# <a name="value-classes-and-structs-ccx"></a>Classes e estruturas de valor (C++/CX)
Um *valor&lt;1* ou *classe de valor* é um Windows compatível com o tempo de execução POD ("estrutura plain old data"). Ela tem um tamanho fixo e consiste somente em campos; diferentemente de uma classe ref, ela não tem propriedades.  
  
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
  
 Quando uma variável de um tipo de valor é atribuída a outra variável, o valor é copiado para que cada uma das duas variáveis tenha sua própria cópia dos dados. Uma *estrutura de valor* é uma estrutura de tamanho fixo que contém apenas campos de dados públicos e é declarada com o uso da palavra-chave `value struct` .  
  
 Uma *classe de valor* é como uma `value struct` , exceto pelo fato de que seus campos devem receber acessibilidade pública explicitamente. É declarada com o uso da palavra-chave `value class` .  
  
 Uma estrutura de valor ou classe de valor pode conter como campos somente tipos numéricos fundamentais, classes enum, `Platform::String^`, ou [Platform:: ibox \<T > ^](../cppcx/platform-ibox-interface.md) onde T é uma classe de tipo ou de enumeração numérico ou a classe ou struct. Um campo `IBox<T>^` pode ter o valor `nullptr`; é assim que o C++ implementa o conceito de *tipos que permitem valor nulo*.  
  
 Uma classe ou uma estrutura de valor que contém um tipo `Platform::String^` ou `IBox<T>^` como membro não aceita `memcpy`.  
  
 Como todos os membros de uma `value class` ou `value struct` são públicos e emitidos nos metadados, os tipos C++ padrão não são permitidos como membros. Isso é diferente das classes ref, que podem conter tipos C++ padrão `private` ou `internal` .  
  
 O fragmento de código a seguir declara os tipos `Coordinates` e `City` como estruturas de valor. Observe que um dos membros de dados `City` é um tipo `GeoCoordinates` . Uma `value struct` pode conter outras estruturas de valor como membros.  
  
 [!code-cpp[cx_classes#07](../cppcx/codesnippet/CPP/classesstructs/class1.h#07)]  
  
## <a name="parameter-passing-for-value-types"></a>Passagem de parâmetro para tipos de valor  
 Se você tiver um valor de tipo como um parâmetro de função ou método, ele será normalmente transmitido por valor. Para objetos maiores, isso pode causar um problema de desempenho. No Visual Studio 2013 e anteriores, os tipos de valor em C++/CX sempre são passados por valor. No Visual Studio de 2015 e posteriores, você pode passar tipos de valor por referência ou por valor.  
  
 Para declarar um parâmetro que transmita um tipo de valor por valor, use um código como o seguinte:  
  
```  
void Method1(MyValueType obj);  
```  
  
 Para declarar um parâmetro que passe um tipo de valor por referência, use o símbolo de referência (&) como no exemplo a seguir:  
  
```  
void Method2(MyValueType& obj);  
```  
  
 O tipo dentro de Method2 é uma referência a MyValueType e funciona da mesma maneira que um tipo de referência no C++ padrão.  
  
 Quando você chama Method1 de outra linguagem, como o C#, não é necessário usar a palavra-chave `ref` ou `out` . Quando você chamar Method2, use a palavra-chave `ref` .  
  
```  
Method2(ref obj);  
```  
  
 Você também pode usar um símbolo de ponteiro (*) para transmitir um tipo de valor por referência. O comportamento com relação a autores da chamada em outras linguagens é o mesmo (os autores da chamada em C# usam a palavra-chave `ref` ), mas no método, o tipo é um ponteiro para o tipo de valor.  
  
## <a name="nullable-value-types"></a>Tipos de valor anuláveis  
 Como mencionado anteriormente, uma classe ou estrutura de valor pode ter um campo do tipo [Platform:: ibox\<T > ^](../cppcx/platform-ibox-interface.md)— por exemplo, `IBox<int>^`. Esse campo pode ter qualquer valor numérico que seja válido para o tipo `int` ou pode ter o valor `nullptr`. Você pode transmitir um campo anulável como argumento para um método cujo parâmetro seja declarado como opcional ou para qualquer lugar em que um tipo de valor não precise ter um valor.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipos (C++/CX)](../cppcx/type-system-c-cx.md)   
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)   
 [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)   
 [Classes e structs de referência (C++/CX)](../cppcx/ref-classes-and-structs-c-cx.md)