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
ms.openlocfilehash: 894bbffcc73693e5d0976831d65df54b09c853d2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216018"
---
# <a name="generic-classes-ccli"></a>Classes genéricas (C++/CLI)

Uma classe genérica é declarada da seguinte forma:

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

*attributes*<br/>
(Opcional) Informações declarativas adicionais. Saiba mais sobre atributos e classes de atributos em Atributos.

*class-key*<br/>
Um **`class`** ou**`typename`**

*type-parameter-identifier(s)*, lista de identificadores separados por vírgula que especificam os nomes dos parâmetros de tipo.

*constraint-clauses*<br/>
Uma lista (não separada por vírgulas) de cláusulas **where** que especificam as restrições para os parâmetros de tipo. Assume o formato:

> **em que** *tipo de parâmetro-identificador* **:** *restrição-List***..** .  

*constraint-list*<br/>
*Class-ou-interface*[ `,` *...*]

*accessibility-modifiers*<br/>
Modificadores de acessibilidade para a classe genérica. Para o Windows Runtime, o único modificador permitido é **`private`** . Para o Common Language Runtime, os modificadores permitidos são **`private`** e **`public`** .

*ID*<br/>
O nome da classe genérica, qualquer identificador C++ válido.

*modificadores*<br/>
(Opcional) Os modificadores permitidos incluem **sealed** e **abstract**.

*base-list*<br/>
Uma lista que contém uma classe base e quaisquer interfaces implementadas, todas separadas por vírgulas.

*class-body*<br/>
O corpo da classe, que contém campos, funções de membros, etc.

*declarators*<br/>
Declarações de todas as variáveis desse tipo. Por exemplo: `^` *identificador*[ `,` ...]

Você pode declarar classes genéricas como essas (Observe que a palavra-chave **`class`** pode ser usada em vez de **`typename`** ). Neste exemplo, `ItemType`, `KeyType` e `ValueType` são tipos desconhecidos especificados no ponto where do tipo. `HashTable<int, int>` é um tipo construído do tipo genérico `HashTable<KeyType, ValueType>`. É possível construir vários tipos construídos diferentes a partir de um único tipo genérico. Tipos construídos criados a partir de classes genéricas são tratados como qualquer outro tipo de classe ref.

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

Ambos os tipos de valor (tipos internos, como **`int`** ou **`double`** , ou tipos de valor definidos pelo usuário) e tipos de referência podem ser usados como um argumento de tipo genérico. Independentemente disso, a sintaxe dentro da definição genérica é a mesma. Sintaticamente, o tipo desconhecido é tratado como se fosse um tipo de referência. No entanto, o runtime é capaz de determinar se o tipo usado é, na verdade, um tipo de valor e substituir o código gerado apropriado para acesso direto aos membros. Tipos de valor usados como argumentos de tipo genérico não passam por conversão boxing e, portanto, não sofrem a penalidade de desempenho associada à conversão boxing. A sintaxe usada dentro do corpo do genérico deve ser `T^` e `->`, em vez de `.`. Todo uso de [ref new, gcnew](ref-new-gcnew-cpp-component-extensions.md) para o parâmetro de tipo é adequadamente interpretado pelo runtime como a criação simples de um tipo de valor se o argumento de tipo for de valor.

Também é possível declarar uma classe genérica com [Restrições em parâmetros de tipo genérico (C++/CLI)](constraints-on-generic-type-parameters-cpp-cli.md) nos tipos que podem ser usados para o parâmetro de tipo. No exemplo a seguir, qualquer tipo usado para `ItemType` deve implementar a interface `IItem`. A tentativa de usar **`int`** , por exemplo, que não implementa `IItem` , produziria um erro de tempo de compilação porque o argumento de tipo não atende à restrição.

```cpp
// generic_classes_2.cpp
// compile with: /clr /c
interface class IItem {};
generic <class ItemType>
where ItemType : IItem
ref class Stack {};
```

Classes genéricas no mesmo namespace não podem ser sobrecarregadas com a alteração apenas do número ou dos tipos de parâmetros de tipo. No entanto, se cada classe reside em um namespace diferente, elas podem ser sobrecarregadas. Por exemplo, considere as seguintes classes, `MyClass` e `MyClass<ItemType>`, nos namespaces `A` e `B`. As duas classes podem ser sobrecarregadas em um terceiro namespace C:

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

A classe base e as interfaces base não podem ser parâmetros de tipo. No entanto, a classe base pode envolver o parâmetro de tipo como um argumento, como no caso a seguir:

```cpp
// generic_classes_4.cpp
// compile with: /clr /c
generic <typename ItemType>
interface class IInterface {};

generic <typename ItemType>
ref class MyClass : IInterface<ItemType> {};
```

Construtores e destruidores são executados uma vez para cada instância de objeto (como de costume); construtores estáticos são executados uma vez para cada tipo construído.

## <a name="fields-in-generic-classes"></a>Campos em classes genéricas

Esta seção demonstra o uso de instância e campos estáticos em classes genéricas.

### <a name="instance-variables"></a>Variáveis de instância

As variáveis de instância de uma classe genérica podem ter tipos e inicializadores de variável que incluam quaisquer parâmetros de tipo da classe delimitadora.

## <a name="example"></a>Exemplo

No exemplo a seguir, três instâncias diferentes da classe genérica, MyClass \<ItemType> , são criadas usando os argumentos de tipo apropriados ( **`int`** , e a cadeia de **`double`** **caracteres**).

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

Na criação de um novo tipo genérico, são criadas novas instâncias de todas as variáveis estáticas e são executados os construtores estáticos para esse tipo.

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

## <a name="methods-in-generic-classes"></a>Métodos em classes genéricas

Os métodos em classes genéricas podem ser genéricos; métodos não genéricos são parametrizados implicitamente pelo parâmetro de tipo de classe.

As seguintes regras especiais aplicam-se a métodos em classes genéricas:

- Métodos em classes genéricas podem usar parâmetros de tipo como parâmetros, tipos de retorno ou variáveis locais.

- Métodos em classes genéricas podem usar tipos construídos abertos ou fechados como parâmetros, tipos de retorno ou variáveis locais.

### <a name="non-generic-methods-in-generic-classes"></a>Métodos não genéricos em classes genéricas

Métodos em classes genéricas que não têm parâmetros de tipo adicionais geralmente são chamados de não genéricos, embora sejam implicitamente parametrizados pela classe genérica delimitadora.

A assinatura de um método não genérico não pode incluir um ou mais parâmetros de tipo da classe delimitadora, diretamente ou em um tipo construído aberto. Por exemplo:

`void MyMethod(MyClass<ItemType> x) {}`

O corpo desses métodos também pode usar esses parâmetros de tipo.

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

## <a name="generic-methods-in-generic-classes"></a>Métodos genéricos em classes genéricas

É possível declarar métodos genéricos em classes genéricas e não genéricas. Por exemplo:

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

O método não genérico ainda é genérico no sentido de que é parametrizado por um parâmetro de tipo da classe, mas não tem nenhum parâmetro de tipo adicional.

Todos os tipos de métodos em classes genéricas podem ser genéricos, incluindo os métodos static, instance e virtual.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como declarar e usar os métodos genéricos em classes genéricas:

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

## <a name="using-nested-types-in-generic-classes"></a>Usar tipos aninhados em classes genéricas

Assim como em classes comuns, é possível declarar outros tipos dentro de uma classe genérica. A declaração de classe aninhada é parametrizada implicitamente pelos parâmetros de tipo da declaração de classe externa. Dessa forma, uma classe aninhada distinta é definida para cada tipo externo construído. Por exemplo, na declaração,

```cpp
// generic_classes_5.cpp
// compile with: /clr /c
generic <typename ItemType>
ref struct Outer {
   ref class Inner {};
};
```

O tipo `Outer<int>::Inner` não é igual ao tipo `Outer<double>::Inner`.

Assim como acontece com métodos genéricos em classes genéricas, parâmetros de tipo adicionais podem ser definidos para o tipo aninhado. Se você usar os mesmos nomes de parâmetro de tipo na classe interna e externa, o parâmetro de tipo interno ocultará o parâmetro de tipo externo.

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

Quando tipos genéricos construídos e aninhados são nomeados, o parâmetro para o tipo externo não é incluído na lista de parâmetros para o tipo interno, mesmo que o tipo interno seja parametrizado implicitamente pelo parâmetro do tipo externo. No caso acima, um nome de tipo construído seria `Outer<int>::Inner<string>`.

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

## <a name="properties-events-indexers-and-operators-in-generic-classes"></a>Propriedades, eventos, indexadores e operadores em classes genéricas

- Propriedades, eventos, indexadores e operadores podem usar os parâmetros de tipo da classe delimitadora genérica como valores de retorno, parâmetros ou variáveis locais, como quando `ItemType` é um parâmetro de tipo de uma classe:

    ```cpp
    public ItemType MyProperty {}
    ```

- Propriedades, eventos, indexadores e operadores não podem ser parametrizados.

## <a name="example"></a>Exemplo

Este exemplo mostra declarações de uma propriedade de instância em uma classe genérica.

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

As regras para declarar e usar structs genéricos são as mesmas das classes genéricas, exceto pelas diferenças observadas na referência da linguagem do Visual C++.

## <a name="example"></a>Exemplo

O exemplo a seguir declara um struct genérico, `MyGenStruct` , com um campo, `myField` e atribui valores de tipos diferentes ( **`int`** , **`double`** , `String^` ) a esse campo.

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

## <a name="see-also"></a>Confira também

[Genéricos](generics-cpp-component-extensions.md)
