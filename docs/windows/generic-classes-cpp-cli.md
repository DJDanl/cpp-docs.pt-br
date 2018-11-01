---
title: Classes genéricas (C++/CLI)
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- classes [C++], generic
- generic classes [C++], about generic classes
- data types [C++], generic
- generic classes
- generics [C++], declaring generic classes
ms.assetid: 0beb99e1-1ec4-4fee-9836-ce9657d67a3a
ms.openlocfilehash: 74a16feb38f79b7e588324eb8d3fa72f88440a4c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50591753"
---
# <a name="generic-classes-ccli"></a>Classes genéricas (C++/CLI)

Uma classe genérica é declarada usando o seguinte formato:

## <a name="syntax"></a>Sintaxe

```cpp
[attributes]
generic <class-key type-parameter-identifier(s)>
[constraint-clauses]
[accessibility-modifiers] ref class identifier  [modifiers]
[: base-list]
{
class-body
} [declarators] [;]
```

## <a name="remarks"></a>Comentários

Na sintaxe acima, os seguintes termos são usados:

*Atributos*<br/>
(Opcional) Informações declarativas adicionais. Para obter mais informações sobre atributos e classes de atributos, consulte atributos.

*chave de classe*<br/>
Qualquer um dos **classe** ou **typename**

*tipo-parâmetro-identificador (es)*, lista separada por vírgulas de identificadores para especificar os nomes dos parâmetros de tipo.

*cláusulas de restrição*<br/>
Uma lista (não separada por vírgulas) de **onde** cláusulas especificando as restrições para os parâmetros de tipo. Assume a forma:

> **em que** *identificador de parâmetro de tipo* **:** *lista de restrições***...**

*lista de restrições*<br/>
*interface ou classe*[`,` *...* ]

*modificadores de acessibilidade*<br/>
Modificadores de acessibilidade para a classe genérica. Para o tempo de execução do Windows, é o modificador permitido apenas **privada**. Para o common language runtime, os modificadores permitidos são **privados** e **público**.

*identifier*<br/>
O nome da classe genérica, qualquer identificador válido do C++.

*Modificadores*<br/>
(Opcional) Permitido incluem modificadores **lacrado** e **abstrata**.

*Base de dados de lista*<br/>
Uma lista que contém uma classe base e qualquer implementado interfaces, todos separados por vírgulas.

*corpo da classe*<br/>
O corpo da classe, que contém campos, funções de membro, etc.

*declaradores*<br/>
Declarações de todas as variáveis desse tipo. Por exemplo: `^` *identificador*[`,` ...]

Você pode declarar classes genéricas como essas (Observe que a palavra-chave **classe** pode ser usado em vez de **typename**). Neste exemplo, `ItemType`, `KeyType` e `ValueType` são tipos desconhecidos que são especificados no ponto em que o tipo. `HashTable<int, int>` é um tipo construído do tipo genérico `HashTable<KeyType, ValueType>`. Um número de diferentes tipos construídos pode ser construído a partir de um único tipo genérico. Tipos construídos construídos a partir de classes genéricas são tratados como qualquer outro tipo de classe ref.

```cpp
// generic_classes_1.cpp
// compile with: /clr
using namespace System;
generic <typename ItemType>
ref struct Stack {
   // ItemType may be used as a type here
   void Add(ItemType item) {}
};

generic <typename KeyType, typename ValueType>
ref class HashTable {};

// The keyword class may be used instead of typename:
generic <class ListItem>
ref class List {};

int main() {
   HashTable<int, Decimal>^ g1 = gcnew HashTable<int, Decimal>();
}
```

Ambos os tipos de valor (tipos de qualquer um dos internos, como **int** ou **duplo**, ou tipos de valor definidos pelo usuário) e tipos de referência podem ser usados como um argumento de tipo genérico. A sintaxe dentro da definição genérica é o mesmo independentemente. Sintaticamente, o tipo desconhecido é tratado como se fosse um tipo de referência. No entanto, o tempo de execução é capaz de determinar que, se o tipo usado na verdade, é um tipo de valor e substitua o código gerado apropriado para acesso direto aos membros. Tipos de valor usados como argumentos de tipo genérico não são boxed e portanto não sofrem a penalidade de desempenho associada a conversão boxing. A sintaxe usada dentro do corpo de genérica deve ser `T^` e `->` em vez de `.`. Uso de qualquer [gcnew de novo, ref](../windows/ref-new-gcnew-cpp-component-extensions.md) para o tipo de parâmetro será adequadamente interpretado pelo tempo de execução como a criação simple de um tipo de valor se o argumento de tipo é um tipo de valor.

Você também pode declarar uma classe genérica com [restrições em parâmetros de tipo genéricos (C + + c++ CLI)](../windows/constraints-on-generic-type-parameters-cpp-cli.md) sobre os tipos que podem ser usados para o parâmetro de tipo. No exemplo a seguir, qualquer tipo usado para `ItemType` deve implementar o `IItem` interface. Tentativa de usar **int**, por exemplo, que não implementa `IItem`, geraria um erro de tempo de compilação porque o argumento de tipo não satisfaz a restrição.

```cpp
// generic_classes_2.cpp
// compile with: /clr /c
interface class IItem {};
generic <class ItemType>
where ItemType : IItem
ref class Stack {};
```

Classes genéricas no mesmo namespace não podem ser sobrecarregadas, alterando apenas o número ou os tipos de parâmetros de tipo. No entanto, se cada classe reside em um namespace diferente, eles podem ser sobrecarregados. Por exemplo, considere as seguintes classes, `MyClass` e `MyClass<ItemType>`, nos namespaces `A` e `B`. As duas classes, em seguida, podem ser sobrecarregadas em um namespace de terceiro c:

```cpp
// generic_classes_3.cpp
// compile with: /clr /c
namespace A {
   ref class MyClass {};
}

namespace B {
   generic <typename ItemType>
   ref class MyClass2 { };
}

namespace C {
   using namespace A;
   using namespace B;

   ref class Test {
      static void F() {
         MyClass^ m1 = gcnew MyClass();   // OK
         MyClass2<int>^ m2 = gcnew MyClass2<int>();   // OK
      }
   };
}
```

A classe base e interfaces base não podem ser parâmetros de tipo. No entanto, a classe base pode envolver o parâmetro de tipo como um argumento, como no caso a seguir:

```cpp
// generic_classes_4.cpp
// compile with: /clr /c
generic <typename ItemType>
interface class IInterface {};

generic <typename ItemType>
ref class MyClass : IInterface<ItemType> {};
```

Construtores e destruidores são executados uma vez para cada instância do objeto (como de costume); construtores estáticos são executados uma vez para cada tipo construído.

## <a name="fields-in-generic-classes"></a>Campos em Classes genéricas

Esta seção demonstra o uso de instância e campos estáticos em classes genéricas.

### <a name="instance-variables"></a>Variáveis de instância

Variáveis de instância de uma classe genérica podem ter tipos e inicializadores de variável que incluam quaisquer parâmetros de tipo da classe delimitadora.

## <a name="example"></a>Exemplo

No exemplo a seguir, três instâncias diferentes da classe genérica, MyClass\<ItemType >, são criados usando os argumentos de tipo apropriada (**int**, **double**e **cadeia de caracteres**).

```cpp
// generics_instance_fields1.cpp
// compile with: /clr
// Instance fields on generic classes
using namespace System;

generic <typename ItemType>
ref class MyClass {
// Field of the type ItemType:
public :
   ItemType field1;
   // Constructor using a parameter of the type ItemType:
   MyClass(ItemType p) {
   field1 = p;
   }
};

int main() {
   // Instantiate an instance with an integer field:
   MyClass<int>^ myObj1 = gcnew MyClass<int>(123);
   Console::WriteLine("Integer field = {0}", myObj1->field1);

   // Instantiate an instance with a double field:
   MyClass<double>^ myObj2 = gcnew MyClass<double>(1.23);
   Console::WriteLine("Double field = {0}", myObj2->field1);

   // Instantiate an instance with a String field:
   MyClass<String^>^ myObj3 = gcnew MyClass<String^>("ABC");
   Console::WriteLine("String field = {0}", myObj3->field1);
   }
```

```Output
Integer field = 123
Double field = 1.23
String field = ABC
```

## <a name="static-variables"></a>Variáveis estáticas

A criação de um novo tipo genérico, novas instâncias de todas as variáveis estáticas são criadas e qualquer construtor estático para esse tipo é executado.

Variáveis estáticas podem usar quaisquer parâmetros de tipo da classe delimitadora.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar campos estáticos e um construtor estático em uma classe genérica.

```cpp
// generics_static2.cpp
// compile with: /clr
using namespace System;

interface class ILog {
   void Write(String^ s);
};

ref class DateTimeLog : ILog {
public:
   virtual void Write(String^ s) {
      Console::WriteLine( "{0}\t{1}", DateTime::Now, s);
   }
};

ref class PlainLog : ILog {
public:
   virtual void Write(String^ s) { Console::WriteLine(s); }
};

generic <typename LogType>
where LogType : ILog
ref class G {
   static LogType s_log;

public:
   G(){}
   void SetLog(LogType log) { s_log = log; }
   void F() { s_log->Write("Test1"); }
   static G() { Console::WriteLine("Static constructor called."); }
};

int main() {
   G<PlainLog^>^ g1 = gcnew G<PlainLog^>();
   g1->SetLog(gcnew PlainLog());
   g1->F();

   G<DateTimeLog^>^ g2 = gcnew G<DateTimeLog^>();
   g2->SetLog(gcnew DateTimeLog());

   // prints date
   // g2->F();
}
```

```Output
Static constructor called.
Static constructor called.
Static constructor called.
Test1
```

## <a name="methods-in-generic-classes"></a>Métodos em Classes genéricas

Métodos em classes genéricas podem ser genéricos em si; métodos genéricos não serão parametrizados implicitamente pelo parâmetro de tipo de classe.

As seguintes regras especiais se aplicam a métodos em classes genéricas:

- Métodos em classes genéricas podem usar parâmetros de tipo como parâmetros, tipos de retorno ou variáveis locais.

- Métodos em classes genéricas podem usar tipos construídos abertos ou fechados como parâmetros, tipos de retorno ou variáveis locais.

### <a name="non-generic-methods-in-generic-classes"></a>Métodos não genéricos em Classes genéricas

Métodos em classes genéricas que não têm nenhum parâmetro de tipo adicionais geralmente são chamados de não-genérica embora eles implicitamente são parametrizados pela classe genérica delimitador.

A assinatura de um método genérico não pode incluir um ou mais parâmetros de tipo da classe delimitadora, diretamente ou em um tipo construído aberto. Por exemplo:

`void MyMethod(MyClass<ItemType> x) {}`

O corpo de tais métodos também pode usar esses parâmetros de tipo.

## <a name="example"></a>Exemplo

O exemplo a seguir declara um método não genérico, `ProtectData`, dentro de uma classe genérica, `MyClass<ItemType>`. O método usa o parâmetro de tipo de classe `ItemType` na sua assinatura em um tipo construído aberto.

```cpp
// generics_non_generic_methods1.cpp
// compile with: /clr
// Non-generic methods within a generic class.
using namespace System;

generic <typename ItemType>
ref class MyClass {
public:
   String^ name;
   ItemType data;

   MyClass(ItemType x) {
      data = x;
   }

   // Non-generic method using the type parameter:
   virtual void ProtectData(MyClass<ItemType>^ x) {
      data = x->data;
   }
};

// ItemType defined as String^
ref class MyMainClass: MyClass<String^> {
public:
   // Passing "123.00" to the constructor:
   MyMainClass(): MyClass<String^>("123.00") {
      name = "Jeff Smith";
   }

   virtual void ProtectData(MyClass<String^>^ x) override {
      x->data = String::Format("${0}**", x->data);
   }

   static void Main() {
      MyMainClass^ x1 = gcnew MyMainClass();

      x1->ProtectData(x1);
      Console::WriteLine("Name: {0}", x1->name);
      Console::WriteLine("Amount: {0}", x1->data);
   }
};

int main() {
   MyMainClass::Main();
}
```

```Output
Name: Jeff Smith
Amount: $123.00**
```

## <a name="generic-methods-in-generic-classes"></a>Métodos genéricos em Classes genéricas

Você pode declarar métodos genéricos em classes genéricas e não genéricas. Por exemplo:

## <a name="example"></a>Exemplo

```cpp
// generics_method2.cpp
// compile with: /clr /c
generic <typename Type1>
ref class G {
public:
   // Generic method having a type parameter
   // from the class, Type1, and its own type
   // parameter, Type2
   generic <typename Type2>
   void Method1(Type1 t1, Type2 t2) { F(t1, t2); }

   // Non-generic method:
   // Can use the class type param, Type1, but not Type2.
   void Method2(Type1 t1) { F(t1, t1); }

   void F(Object^ o1, Object^ o2) {}
};
```

O método não genérico ainda é genérico no sentido de que ele é parametrizado por um parâmetro de tipo da classe, mas ele não tem nenhum parâmetro de tipo adicionais.

Todos os tipos de métodos em classes genéricas podem ser genérico, incluindo estático, a instância e métodos virtuais.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra declarando e usando os métodos genéricos em classes genéricas:

```cpp
// generics_generic_method2.cpp
// compile with: /clr
using namespace System;
generic <class ItemType>
ref class MyClass {
public:
   // Declare a generic method member.
   generic <class Type1>
   String^ MyMethod(ItemType item, Type1 t) {
      return String::Concat(item->ToString(), t->ToString());
   }
};

int main() {
   // Create instances using different types.
   MyClass<int>^ myObj1 = gcnew MyClass<int>();
   MyClass<String^>^ myObj2 = gcnew MyClass<String^>();
   MyClass<String^>^ myObj3 = gcnew MyClass<String^>();

   // Calling MyMethod using two integers.
   Console::WriteLine("MyMethod returned: {0}",
            myObj1->MyMethod<int>(1, 2));

   // Calling MyMethod using an integer and a string.
   Console::WriteLine("MyMethod returned: {0}",
            myObj2->MyMethod<int>("Hello #", 1));

   // Calling MyMethod using two strings.
   Console::WriteLine("MyMethod returned: {0}",
       myObj3->MyMethod<String^>("Hello ", "World!"));

   // generic methods can be called without specifying type arguments
   myObj1->MyMethod<int>(1, 2);
   myObj2->MyMethod<int>("Hello #", 1);
   myObj3->MyMethod<String^>("Hello ", "World!");
}
```

```Output
MyMethod returned: 12
MyMethod returned: Hello #1
MyMethod returned: Hello World!
```

## <a name="using-nested-types-in-generic-classes"></a>Usando tipos aninhados em Classes genéricas

Assim como com classes comuns, você pode declarar outros tipos de dentro de uma classe genérica. Implicitamente, a declaração de classe aninhada é parametrizada por parâmetros de tipo de declaração da classe externa. Dessa forma, uma classe aninhada distinta é definida para cada tipo externo construído. Por exemplo, na declaração,

```cpp
// generic_classes_5.cpp
// compile with: /clr /c
generic <typename ItemType>
ref struct Outer {
   ref class Inner {};
};
```

O tipo `Outer<int>::Inner` não é igual ao tipo `Outer<double>::Inner`.

Assim como acontece com métodos genéricos em classes genéricas, parâmetros de tipo adicionais podem ser definidos para o tipo aninhado. Se você usar os mesmos nomes de parâmetro de tipo na classe interna e externa, o parâmetro de tipo interna ocultará o parâmetro de tipo externo.

```cpp
// generic_classes_6.cpp
// compile with: /clr /c
generic <typename ItemType>
ref class Outer {
   ItemType outer_item;   // refers to outer ItemType

   generic <typename ItemType>
   ref class Inner {
      ItemType inner_item;   // refers to Inner ItemType
   };
};
```

Como não há nenhuma maneira de se referir ao parâmetro de tipo externo, o compilador gerará um aviso nessa situação.

Quando são nomeados construídos de tipos genéricos aninhados, o parâmetro de tipo para o tipo externo não está incluído na lista de parâmetros de tipo para o tipo interno, mesmo que o tipo interno implicitamente é parametrizado pelo parâmetro de tipo do tipo externo. No caso acima, um nome de um tipo construído seria `Outer<int>::Inner<string>`.

O exemplo a seguir demonstra a criação e a leitura de uma lista vinculada usando tipos aninhados em classes genéricas.

## <a name="example"></a>Exemplo

```cpp
// generics_linked_list.cpp
// compile with: /clr
using namespace System;
generic <class ItemType>
ref class LinkedList {
// The node class:
public:
   ref class Node {
   // The link field:
   public:
      Node^ next;
      // The data field:
      ItemType item;
   } ^first, ^current;
};

ref class ListBuilder {
public:
   void BuildIt(LinkedList<double>^ list) {
      /* Build the list */
      double m[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
      Console::WriteLine("Building the list:");

      for (int n=0; n<=4; n++) {
         // Create a new node:
         list->current = gcnew LinkedList<double>::Node();

         // Assign a value to the data field:
         list->current->item = m[n];

         // Set the link field "next" to be the same as
         // the "first" field:
         list->current->next = list->first;

         // Redirect "first" to the new node:
         list->first = list->current;

         // Display node's data as it builds:
         Console::WriteLine(list->current->item);
      }
   }

   void ReadIt(LinkedList<double>^ list) {
      // Read the list
      // Make "first" the "current" link field:
      list->current = list->first;
      Console::WriteLine("Reading nodes:");

      // Read nodes until current == null:
      while (list->current != nullptr) {
         // Display the node's data field:
         Console::WriteLine(list->current->item);

         // Move to the next node:
         list->current = list->current->next;
      }
   }
};

int main() {
   // Create a list:
   LinkedList<double>^ aList = gcnew LinkedList<double>();

   // Initialize first node:
   aList->first = nullptr;

   // Instantiate the class, build, and read the list:
   ListBuilder^ myListBuilder = gcnew ListBuilder();
   myListBuilder->BuildIt(aList);
   myListBuilder->ReadIt(aList);
}
```

```Output
Building the list:
0.1
0.2
0.3
0.4
0.5
Reading nodes:
0.5
0.4
0.3
0.2
0.1
```

## <a name="properties-events-indexers-and-operators-in-generic-classes"></a>Propriedades, eventos, indexadores e operadores em Classes genéricas

- Propriedades, eventos, indexadores e operadores podem usar os parâmetros de tipo da classe delimitadora genérico como valores de retorno, parâmetros ou variáveis locais, por exemplo, quando `ItemType` é um parâmetro de tipo de uma classe:

    ```cpp
    public ItemType MyProperty {}
    ```

- Propriedades, eventos, indexadores e operadores não podem se ser parametrizados.

## <a name="example"></a>Exemplo

Este exemplo mostra as declarações de uma propriedade de instância em uma classe genérica.

```cpp
// generics_generic_properties1.cpp
// compile with: /clr
using namespace System;

generic <typename ItemType>
ref class MyClass {
private:
   property ItemType myField;

public:
   property ItemType MyProperty {
      ItemType get() {
         return myField;
      }
      void set(ItemType value) {
         myField = value;
      }
   }
};

int main() {
   MyClass<String^>^ c = gcnew MyClass<String^>();
   MyClass<int>^ c1 = gcnew MyClass<int>();

   c->MyProperty = "John";
   c1->MyProperty = 234;

   Console::Write("{0}, {1}", c->MyProperty, c1->MyProperty);
}
```

```Output
John, 234
```

## <a name="example"></a>Exemplo

O exemplo a seguir mostra uma classe genérica com um evento.

```cpp
// generics_generic_with_event.cpp
// compile with: /clr
// Declare a generic class with an event and
// invoke events.
using namespace System;

// declare delegates
generic <typename ItemType>
delegate void ClickEventHandler(ItemType);

// generic class that defines events
generic <typename ItemType>
ref class EventSource {
public:
   // declare the event OnClick
   event ClickEventHandler<ItemType>^ OnClick;
   void FireEvents(ItemType item) {
      // raises events
      OnClick(item);
   }
};

// generic class that defines methods that will called when
// event occurs
generic <typename ItemType>
ref class EventReceiver {
public:
   void OnMyClick(ItemType item) {
   Console::WriteLine("OnClick: {0}", item);
   }
};

int main() {
   EventSource<String^>^ MyEventSourceString =
                   gcnew EventSource<String^>();
   EventSource<int>^ MyEventSourceInt = gcnew EventSource<int>();
   EventReceiver<String^>^ MyEventReceiverString =
                   gcnew EventReceiver<String^>();
   EventReceiver<int>^ MyEventReceiverInt = gcnew EventReceiver<int>();

   // hook handler to event
   MyEventSourceString->OnClick += gcnew ClickEventHandler<String^>(
       MyEventReceiverString, &EventReceiver<String^>::OnMyClick);
   MyEventSourceInt->OnClick += gcnew ClickEventHandler<int>(
             MyEventReceiverInt, &EventReceiver<int>::OnMyClick);

   // invoke events
   MyEventSourceString->FireEvents("Hello");
   MyEventSourceInt->FireEvents(112);

   // unhook handler to event
   MyEventSourceString->OnClick -= gcnew ClickEventHandler<String^>(
        MyEventReceiverString, &EventReceiver<String^>::OnMyClick);
   MyEventSourceInt->OnClick -= gcnew ClickEventHandler<int>(
        MyEventReceiverInt, &EventReceiver<int>::OnMyClick);
}
```

## <a name="generic-structs"></a>Structs genéricos

As regras para declarar e usar structs genéricos são as mesmas para classes genéricas, exceto pelas diferenças observadas na referência da linguagem Visual C++.

## <a name="example"></a>Exemplo

O exemplo a seguir declara uma estrutura genérica, `MyGenStruct`, com um campo, `myField`e atribui valores de tipos diferentes (**int**, **double**, `String^`) para esse campo.

```cpp
// generics_generic_struct1.cpp
// compile with: /clr
using namespace System;

generic <typename ItemType>
ref struct MyGenStruct {
public:
   ItemType myField;

   ItemType AssignValue(ItemType item) {
      myField = item;
      return myField;
   }
};

int main() {
   int myInt = 123;
   MyGenStruct<int>^ myIntObj = gcnew MyGenStruct<int>();
   myIntObj->AssignValue(myInt);
   Console::WriteLine("The field is assigned the integer value: {0}",
            myIntObj->myField);

   double myDouble = 0.123;
   MyGenStruct<double>^ myDoubleObj = gcnew MyGenStruct<double>();
   myDoubleObj->AssignValue(myDouble);
   Console::WriteLine("The field is assigned the double value: {0}",
            myDoubleObj->myField);

   String^ myString = "Hello Generics!";
   MyGenStruct<String^>^ myStringObj = gcnew MyGenStruct<String^>();
   myStringObj->AssignValue(myString);
   Console::WriteLine("The field is assigned the string: {0}",
            myStringObj->myField);
}
```

```Output
The field is assigned the integer value: 123
The field is assigned the double value: 0.123
The field is assigned the string: Hello Generics!
```

## <a name="see-also"></a>Consulte também

[Genéricos](../windows/generics-cpp-component-extensions.md)