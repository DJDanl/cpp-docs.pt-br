---
title: classe de interface (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- interface_CPP
helpviewer_keywords:
- interface class keyword
- interface struct keyword
ms.assetid: 3ccea701-f50b-4da7-ad6b-f0ee1203e2b9
ms.openlocfilehash: e7847f71502354189e874d505414b4a45b74ab45
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228694"
---
# <a name="interface-class--ccli-and-ccx"></a>classe de interface (C++/CLI e C++/CX)

Declara uma interface.  Confira mais informações sobre interfaces nativas em [__interface](../cpp/interface.md).

## <a name="all-runtimes"></a>Todos os Runtimes

### <a name="syntax"></a>Sintaxe

```cpp
interface_access
interface class
name :  inherit_accessbase_interface{};interface_accessinterface structname :  inherit_accessbase_interface{};
```

### <a name="parameters"></a>parâmetros

*interface_access*<br/>
A acessibilidade de uma interface fora do assembly.  Os valores possíveis são **`public`** e **`private`** .  **`private`** é o padrão. Interfaces aninhadas não pode ter um especificador *interface_access*.

*name*<br/>
O nome da interface.

*inherit_access*<br/>
A acessibilidade de *base_interface*.  A única acessibilidade permitida para uma interface base é **`public`** (o padrão).

*base_interface*<br/>
(Opcional) Uma interface base para a interface *name*.

### <a name="remarks"></a>Comentários

Um **struct de interface** é equivalente a uma **classe de interface**.

Uma interface pode conter declarações para funções, eventos e propriedades.  Todos os membros da interface têm acessibilidade pública. Uma interface também pode conter membros de dados estáticos, funções, eventos e propriedades, e esses membros estáticos devem ser definidos na interface.

Uma interface define como uma classe pode ser implementada. Uma interface não é uma classe, e classes só podem implementar interfaces. Quando uma classe define uma função declarada em uma interface, essa função é implementada, e não substituída. Portanto, a pesquisa de nomes não inclui membros de interface.

Uma classe ou um struct derivado de uma interface deve implementar todos os membros dessa interface. Ao implementar a interface *name*, você também deve implementar as interfaces na lista `base_interface`.

Para obter mais informações, consulte:

- [Construtor estático de interface](../dotnet/how-to-define-an-interface-static-constructor-cpp-cli.md)

- [Interfaces genéricas (C++/CLI)](generic-interfaces-visual-cpp.md)

Confira mais informações sobre outros tipos de CLR em [Classes e structs](classes-and-structs-cpp-component-extensions.md).

Em tempo de compilação, você pode detectar se um tipo é uma interface com `__is_interface_class(type)`. Saiba mais em [Suporte para compilador de traços de tipo](compiler-support-for-type-traits-cpp-component-extensions.md).

No ambiente de desenvolvimento, você pode obter ajuda F1 sobre essas palavras-chave, destacando a palavra-chave ( **`interface class`** , por exemplo) e pressionando F1.

## <a name="windows-runtime"></a>Windows Runtime

### <a name="remarks"></a>Comentários

(Não há comentários para esse recurso de linguagem que se apliquem somente ao Windows Runtime.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

(Não há comentários para esse recurso de linguagem que se apliquem apenas ao Common Language Runtime.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir demonstra como uma interface pode definir o comportamento de uma função de relógio.

```cpp
// mcppv2_interface_class.cpp
// compile with: /clr
using namespace System;

public delegate void ClickEventHandler(int, double);

// define interface with nested interface
public interface class Interface_A {
   void Function_1();

   interface class Interface_Nested_A {
      void Function_2();
   };
};

// interface with a base interface
public interface class Interface_B : Interface_A {
   property int Property_Block;
   event ClickEventHandler^ OnClick;
   static void Function_3() { Console::WriteLine("in Function_3"); }
};

// implement nested interface
public ref class MyClass : public Interface_A::Interface_Nested_A {
public:
   virtual void Function_2() { Console::WriteLine("in Function_2"); }
};

// implement interface and base interface
public ref class MyClass2 : public Interface_B {
private:
   int MyInt;

public:
   // implement non-static function
   virtual void Function_1() { Console::WriteLine("in Function_1"); }

   // implement property
   property int Property_Block {
      virtual int get() { return MyInt; }
      virtual void set(int value) { MyInt = value; }
   }
   // implement event
   virtual event ClickEventHandler^ OnClick;

   void FireEvents() {
      OnClick(7, 3.14159);
   }
};

// class that defines method called when event occurs
ref class EventReceiver {
public:
   void OnMyClick(int i, double d) {
      Console::WriteLine("OnClick: {0}, {1}", i, d);
   }
};

int main() {
   // call static function in an interface
   Interface_B::Function_3();

   // instantiate class that implements nested interface
   MyClass ^ x = gcnew MyClass;
   x->Function_2();

   // instantiate class that implements interface with base interface
   MyClass2 ^ y = gcnew MyClass2;
   y->Function_1();
   y->Property_Block = 8;
   Console::WriteLine(y->Property_Block);

   EventReceiver^ MyEventReceiver = gcnew EventReceiver();

   // hook handler to event
   y->OnClick += gcnew ClickEventHandler(MyEventReceiver, &EventReceiver::OnMyClick);

   // invoke events
   y->FireEvents();

   // unhook handler to event
   y->OnClick -= gcnew ClickEventHandler(MyEventReceiver, &EventReceiver::OnMyClick);

   // call implemented function via interface handle
   Interface_A^ hi = gcnew MyClass2();
   hi->Function_1();
}
```

```Output
in Function_3

in Function_2

in Function_1

8

OnClick: 7, 3.14159

in Function_1
```

O exemplo de código a seguir mostra duas maneiras de implementar funções com a mesma assinatura declarada em várias interfaces e em que locais essas interfaces são usadas por uma classe.

```cpp
// mcppv2_interface_class_2.cpp
// compile with: /clr /c
interface class I {
   void Test();
   void Test2();
};

interface class J : I {
   void Test();
   void Test2();
};

ref struct R : I, J {
   // satisfies the requirement to implement Test in both interfaces
   virtual void Test() {}

   // implement both interface functions with explicit overrides
   virtual void A() = I::Test2 {}
   virtual void B() = J::Test2 {}
};
```

## <a name="see-also"></a>Confira também

[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)
