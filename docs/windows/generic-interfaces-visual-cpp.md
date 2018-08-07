---
title: Interfaces genéricas (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- generic interfaces
- interfaces, generic [C++}
ms.assetid: f3da788a-ba83-4db7-9dcf-9b95a8fb9d1a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 428004d3390b95c700c53fd157b62a1b3fbe3d0b
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39571169"
---
# <a name="generic-interfaces-visual-c"></a>Interfaces genéricas (Visual C++)
As restrições que se aplicam aos parâmetros de tipo em classes são iguais aos que se aplicam aos parâmetros de tipo em interfaces (consulte [Classes genéricas (C + + / CLI)](../windows/generic-classes-cpp-cli.md)).  
  
 As regras que controlam o sobrecarregamento de função são as mesmas para funções dentro de classes genéricas ou interfaces genéricas.  
  
 Implementações de membros de interface explícita trabalham com tipos de interface construído da mesma forma que com tipos de interface simples (consulte os exemplos a seguir).  
  
 Para obter mais informações sobre interfaces, consulte [classe de interface](../windows/interface-class-cpp-component-extensions.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[attributes] generic <class-key type-parameter-identifier[, ...]>  
[type-parameter-constraints-clauses][accesibility-modifiers] interface class identifier [: base-list] {   interface-body} [declarators] ;  
```  
  
## <a name="remarks"></a>Comentários  
 *atributos* (opcional)  
 Informações declarativas adicionais. Para obter mais informações sobre atributos e classes de atributos, consulte atributos.  
  
 *chave de classe*  
 **classe** ou **typename**  
  
 *tipo-parâmetro-identificador (es)*  
 Lista de identificadores separados por vírgulas.  
  
 *tipo de parâmetro-restrições cláusulas*  
 Assume o formato especificado no [restrições em parâmetros de tipo genéricos (C + + c++ CLI)](../windows/constraints-on-generic-type-parameters-cpp-cli.md)  
  
 *modificadores de acessibilidade* (opcional)  
 Modificadores de acessibilidade (por exemplo, **público, privado**).  
  
 *identifier*  
 O nome da interface.  
  
 *Base de dados de lista* (opcional)  
 Uma lista que contém um ou mais interfaces base explícitas separadas por vírgulas.  
  
 *corpo de interface*  
 Declarações de membros de interface.  
  
 *declaradores* (opcional)  
 Declarações de variáveis com base nesse tipo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como declarar e criar uma interface genérica. No exemplo, a interface genérica `IList<ItemType>` é declarada. Em seguida, é implementado por duas classes genéricas, `List1<ItemType>` e `List2<ItemType>`, com implementações diferentes.  
  
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
  
## <a name="example"></a>Exemplo  
 Este exemplo declara uma interface genérica, `IMyGenIface`e duas interfaces não genéricas, `IMySpecializedInt` e `ImySpecializedString`, que são especializados `IMyGenIface`. As duas interfaces especializadas, em seguida, são implementadas por duas classes, `MyIntClass` e `MyStringClass`. O exemplo mostra como especializar interfaces genéricas, instanciar interfaces genéricas e não genéricas e chamar os membros explicitamente implementados nas interfaces.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Genéricos](../windows/generics-cpp-component-extensions.md)