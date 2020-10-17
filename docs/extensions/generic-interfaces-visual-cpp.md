---
title: Interfaces genéricas (C++/CLI)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- generic interfaces
- interfaces, generic [C++}
ms.assetid: f3da788a-ba83-4db7-9dcf-9b95a8fb9d1a
ms.openlocfilehash: 61ab514d244c8b41d467d382fa97e30556ccbb32
ms.sourcegitcommit: ced5ff1431ffbd25b20d106901955532723bd188
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/16/2020
ms.locfileid: "92135522"
---
# <a name="generic-interfaces-ccli"></a>Interfaces genéricas (C++/CLI)

As restrições que se aplicam aos parâmetros de tipo nas classes são as mesmas que se aplicam aos parâmetros de tipo nas interfaces. Confira [Classes genéricas (C++/CLI)](generic-classes-cpp-cli.md).

As regras que controlam a sobrecarga de funções são as mesmas para funções dentro de classes genéricas ou interfaces genéricas.

As implementações de membros da interface explícita funcionam com tipos de interface construídos da mesma maneira que com tipos de interface simples (consulte os exemplos a seguir).

Saiba mais sobre interfaces em [classe interface](interface-class-cpp-component-extensions.md).

## <a name="syntax"></a>Sintaxe

```cpp
[attributes] generic <class-key type-parameter-identifier[, ...]>
[type-parameter-constraints-clauses][accesibility-modifiers] interface class identifier [: base-list] {   interface-body} [declarators] ;
```

## <a name="remarks"></a>Comentários

*attributes*<br/>
(Opcional) Informações declarativas adicionais. Saiba mais sobre atributos e classes de atributos em **Atributos**.

*class-key*<br/>
**`class`** or **`typename`**

*type-parameter-identifier(s)*<br/>
Lista de identificadores separados por vírgulas.

*type-parameter-constraints-clauses*<br/>
Assume o formato especificado em [Restrições em parâmetros de tipo genérico (C++/CLI)](constraints-on-generic-type-parameters-cpp-cli.md)

*accessibility-modifiers*<br/>
Adicional Modificadores de acessibilidade (por exemplo **, público, privado**).

*ID*<br/>
O nome da interface.

*base-list*<br/>
(Opcional) Uma lista que contém uma ou mais interfaces base explícitas separadas por vírgulas.

*interface-body*<br/>
Declarações de membros da interface.

*declarators*<br/>
(Opcional) Declarações de variáveis ​​baseadas neste tipo.

## <a name="example-how-to-declare-and-instantiate-a-generic-interface"></a>Exemplo: como declarar e criar uma instância de uma interface genérica

O exemplo a seguir demonstra como declarar e criar a instância de uma interface genérica. No exemplo, declaramos a interface genérica `IList<ItemType>`. Em seguida, implementamos por duas classes genéricas, `List1<ItemType>` e `List2<ItemType>`, com diferentes implementações.

```cpp
// generic_interface.cpp
// compile with: /clr
using namespace System;

// An exception to be thrown by the List when
// attempting to access elements beyond the
// end of the list.
ref class ElementNotFoundException : Exception {};

// A generic List interface
generic <typename ItemType>
public interface class IList {
   ItemType MoveFirst();
   bool Add(ItemType item);
   bool AtEnd();
   ItemType Current();
   void MoveNext();
};

// A linked list implementation of IList
generic <typename ItemType>
public ref class List1 : public IList<ItemType> {
   ref class Node {
      ItemType m_item;

   public:
      ItemType get_Item() { return m_item; };
      void set_Item(ItemType value) { m_item = value; };

      Node^ next;

      Node(ItemType item) {
         m_item = item;
         next = nullptr;
      }
   };

   Node^ first;
   Node^ last;
   Node^ current;

   public:
   List1() {
      first = nullptr;
      last = first;
      current = first;
   }

   virtual ItemType MoveFirst() {
      current = first;
      if (first != nullptr)
        return first->get_Item();
      else
         return ItemType();
   }

   virtual bool Add(ItemType item) {
      if (last != nullptr) {
         last->next = gcnew Node(item);
         last = last->next;
      }
      else {
         first = gcnew Node(item);
         last = first;
         current = first;
      }
      return true;
   }

   virtual bool AtEnd() {
      if (current == nullptr )
        return true;
      else
        return false;
   }

   virtual ItemType Current() {
       if (current != nullptr)
         return current->get_Item();
       else
         throw gcnew ElementNotFoundException();
   }

   virtual void MoveNext() {
      if (current != nullptr)
       current = current->next;
      else
        throw gcnew ElementNotFoundException();
   }
};

// An array implementation of IList
generic <typename ItemType>
ref class List2 : public IList<ItemType> {
   array<ItemType>^ item_array;
   int count;
   int current;

   public:

   List2() {
      // not yet possible to declare an
      // array of a generic type parameter
      item_array = gcnew array<ItemType>(256);
      count = current = 0;
   }

   virtual ItemType MoveFirst() {
      current = 0;
      return item_array[0];
   }

   virtual bool Add(ItemType item) {
      if (count < 256)
         item_array[count++] = item;
      else
        return false;
      return true;
   }

   virtual bool AtEnd() {
      if (current >= count)
        return true;
      else
        return false;
   }

   virtual ItemType Current() {
      if (current < count)
        return item_array[current];
      else
        throw gcnew ElementNotFoundException();
   }

   virtual void MoveNext() {
      if (current < count)
         ++current;
      else
         throw gcnew ElementNotFoundException();
   }
};

// Add elements to the list and display them.
generic <typename ItemType>
void AddStringsAndDisplay(IList<ItemType>^ list, ItemType item1, ItemType item2) {
   list->Add(item1);
   list->Add(item2);
   for (list->MoveFirst(); ! list->AtEnd(); list->MoveNext())
   Console::WriteLine(list->Current());
}

int main() {
   // Instantiate both types of list.

   List1<String^>^ list1 = gcnew List1<String^>();
   List2<String^>^ list2 = gcnew List2<String^>();

   // Use the linked list implementation of IList.
   AddStringsAndDisplay<String^>(list1, "Linked List", "List1");

   // Use the array implementation of the IList.
   AddStringsAndDisplay<String^>(list2, "Array List", "List2");
}
```

```Output
Linked List
List1
Array List
List2
```

## <a name="example-declare-a-generic-interface"></a>Exemplo: declarar uma interface genérica

Este exemplo declara uma interface genérica, `IMyGenIface`, e duas interfaces não genéricas, `IMySpecializedInt` e `ImySpecializedString`, que especializam `IMyGenIface`. As duas interfaces especializadas são então implementadas por duas classes, `MyIntClass` e `MyStringClass`. O exemplo mostra como especializar interfaces genéricas, instanciar interfaces genéricas e não genéricas e chamar os membros explicitamente implementados nas interfaces.

```cpp
// generic_interface2.cpp
// compile with: /clr
// Specializing and implementing generic interfaces.
using namespace System;

generic <class ItemType>
public interface class IMyGenIface {
   void Initialize(ItemType f);
};

public interface class IMySpecializedInt: public IMyGenIface<int> {
   void Display();
};

public interface class IMySpecializedString: public IMyGenIface<String^> {
   void Display();
};

public ref class MyIntClass: public IMySpecializedInt {
   int myField;

public:
   virtual void Initialize(int f) {
      myField = f;
   }

   virtual void Display() {
      Console::WriteLine("The integer field contains: {0}", myField);
   }
};

public ref struct MyStringClass: IMySpecializedString {
   String^ myField;

public:
   virtual void Initialize(String^ f) {
      myField = f;
    }

   virtual void Display() {
      Console::WriteLine("The String field contains: {0}", myField);
   }
};

int main() {
   // Instantiate the generic interface.
   IMyGenIface<int>^ myIntObj = gcnew MyIntClass();

   // Instantiate the specialized interface "IMySpecializedInt."
   IMySpecializedInt^ mySpIntObj = (IMySpecializedInt^) myIntObj;

   // Instantiate the generic interface.
   IMyGenIface<String^>^ myStringObj = gcnew MyStringClass();

   // Instantiate the specialized interface "IMySpecializedString."
   IMySpecializedString^ mySpStringObj =
            (IMySpecializedString^) myStringObj;

   // Call the explicitly implemented interface members.
   myIntObj->Initialize(1234);
   mySpIntObj->Display();

   myStringObj->Initialize("My string");
   mySpStringObj->Display();
}
```

```Output
The integer field contains: 1234
The String field contains: My string
```

## <a name="see-also"></a>Confira também

[Genéricos](generics-cpp-component-extensions.md)
