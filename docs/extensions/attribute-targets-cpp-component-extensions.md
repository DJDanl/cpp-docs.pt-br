---
title: Destinos de atributo (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- custom attributes, targets
ms.assetid: b4e6e224-da77-4520-b6e6-b96846e0ebc1
ms.openlocfilehash: 502f5ba2e5bbb5bd5a5fcceca16acaa3987db4bc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65516141"
---
# <a name="attribute-targets-ccli-and-ccx"></a>Destinos de atributo (C++/CLI e C++/CX)

Os especificadores de uso de atributos possibilitam especificar destinos de atributo.  Cada atributo é definido para ser aplicado a determinados elementos de linguagem. Por exemplo, é possível definir um atributo para aplicá-lo apenas a classes e structs.  A lista a seguir mostra os possíveis elementos sintáticos nos quais um atributo personalizado pode ser usado. É possível usar combinações desses valores (usando o “ou” lógico).

Para especificar o destino de um atributo, passe um ou mais enumeradores <xref:System.AttributeTargets> para <xref:System.AttributeUsageAttribute> ao definir o atributo.

A seguir apresentamos uma lista dos destinos de atributos válidos:

- `All` (aplica-se a todos os constructos)

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::All)]
    ref class Attr : public Attribute {};

    [assembly:Attr];
    ```

- `Assembly` (aplica-se a um assembly como um todo)

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Assembly)]
    ref class Attr : public Attribute {};

    [assembly:Attr];
    ```

- `Module` (aplica-se a um módulo como um todo)

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Module)]
    ref class Attr : public Attribute {};

    [module:Attr];
    ```

- `Class`

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Class)]
    ref class Attr : public System::Attribute {};

    [Attr]   // same as [class:Attr]
    ref class MyClass {};
    ```

- `Struct`

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Struct)]
    ref class Attr : public Attribute {};

    [Attr]   // same as [struct:Attr]
    value struct MyStruct{};
    ```

- `enum`

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Enum)]
    ref class Attr : public Attribute {};

    [Attr]   // same as [enum:Attr]
    enum struct MyEnum{e, d};
    ```

- `Constructor`

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Constructor)]
    ref class Attr : public Attribute {};

    ref struct MyStruct{
    [Attr] MyStruct(){}   // same as [constructor:Attr]
    };
    ```

- `Method`

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Method)]
    ref class Attr : public Attribute {};

    ref struct MyStruct{
    [Attr] void Test(){}   // same as [method:Attr]
    };
    ```

- `Property`

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Property)]
    ref class Attr : public Attribute {};

    ref struct MyStruct{
    [Attr] property int Test;   // same as [property:Attr]
    };
    ```

- `Field`

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Field)]
    ref class Attr : public Attribute {};

    ref struct MyStruct{
    [Attr] int Test;   // same as [field:Attr]
    };
    ```

- `Event`

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Event)]
    ref class Attr : public Attribute {};

    delegate void ClickEventHandler(int, double);

    ref struct MyStruct{
    [Attr] event ClickEventHandler^ OnClick;   // same as [event:Attr]
    };
    ```

- `Interface`

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Interface)]
    ref class Attr : public Attribute {};

    [Attr]   // same as [event:Attr]
    interface struct MyStruct{};
    ```

- `Parameter`

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Parameter)]
    ref class Attr : public Attribute {};

    ref struct MyStruct{
    void Test([Attr] int i);
    void Test2([parameter:Attr] int i);
    };
    ```

- `Delegate`

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::Delegate)]
    ref class Attr : public Attribute {};

    [Attr] delegate void Test();
    [delegate:Attr] delegate void Test2();
    ```

- `ReturnValue`

    ```cpp
    using namespace System;
    [AttributeUsage(AttributeTargets::ReturnValue)]
    ref class Attr : public Attribute {};

    ref struct MyStruct {
    // Note required specifier
    [returnvalue:Attr] int Test() { return 0; }
    };
    ```

Normalmente, um atributo precede diretamente o elemento de linguagem ao qual se aplica. Em alguns casos, no entanto, a posição de um atributo não é suficiente para determinar o destino pretendido do atributo. Considere este exemplo:

```cpp
[Attr] int MyFn(double x)...
```

Sintaticamente, não há como saber se o atributo se destina a ser aplicado ao método ou ao valor de retorno do método (nesse caso, o método é padronizado). Nesses casos, use um especificador de uso de atributo. Por exemplo, para tornar o atributo aplicável ao valor de retorno, use o especificador `returnvalue`, da seguinte maneira:

```cpp
[returnvalue:Attr] int MyFn(double x)... // applies to return value
```

Especificadores de uso de atributo são necessários nas seguintes situações:

- Para especificar um atributo de nível de assembly ou de módulo.

- Para especificar que um atributo se aplica ao valor de retorno de um método, não ao método:

    ```cpp
    [method:Attr] int MyFn(double x)...     // Attr applies to method
    [returnvalue:Attr] int MyFn(double x)...// Attr applies to return value
    [Attr] int MyFn(double x)...            // default: method
    ```

- Para especificar que um atributo se aplica ao acessador de uma propriedade, não à propriedade:

    ```cpp
    [method:MyAttr(123)] property int Property()
    [property:MyAttr(123)] property int Property()
    [MyAttr(123)] property int get_MyPropy() // default: property
    ```

- Para especificar que um atributo se aplica ao acessador de um evento, não ao evento:

    ```cpp
    delegate void MyDel();
    ref struct X {
       [field:MyAttr(123)] event MyDel* MyEvent;   //field
       [event:MyAttr(123)] event MyDel* MyEvent;   //event
       [MyAttr(123)] event MyDel* MyEvent;   // default: event
    }
    ```

Um especificador de uso de atributo aplica-se somente ao atributo que o segue imediatamente; ou seja,

```cpp
[returnvalue:Attr1, Attr2]
```

é diferente de

```cpp
[returnvalue:Attr1, returnvalue:Attr2]
```

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

Este exemplo mostra como especificar vários destinos.

### <a name="code"></a>Código

```cpp
using namespace System;
[AttributeUsage(AttributeTargets::Class | AttributeTargets::Struct, AllowMultiple = true )]
ref struct Attr : public Attribute {
   Attr(bool i){}
   Attr(){}
};

[Attr]
ref class MyClass {};

[Attr]
[Attr(true)]
value struct MyStruct {};
```

## <a name="see-also"></a>Consulte também

[Atributos definidos pelo usuário](user-defined-attributes-cpp-component-extensions.md)