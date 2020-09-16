---
title: Delegados Genéricos (C++/CLI)
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- generic delegates
- delegates, generic [C++]
ms.assetid: 09d430b2-1aef-4fbc-87f9-9d7b8185d798
ms.openlocfilehash: 980beb21325e78baa9c6f3691f7b814c5266b79a
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686607"
---
# <a name="generic-delegates-ccli"></a>Delegados Genéricos (C++/CLI)

É possível usar parâmetros de tipo genérico com delegados. Confira mais informações sobre delegados em [Delegado (C++/CLI e C++/CX)](delegate-cpp-component-extensions.md).

## <a name="syntax"></a>Sintaxe

```cpp
[attributes]
generic < [class | typename] type-parameter-identifiers>
[type-parameter-constraints-clauses]
[accessibility-modifiers] delegate result-type identifier
([formal-parameters]);
```

### <a name="parameters"></a>Parâmetros

*attributes*<br/>
(Opcional) Informações declarativas adicionais. Saiba mais sobre atributos e classes de atributos em Atributos.

*type-parameter-identifier(s)*<br/>
Lista separada por vírgula de identificadores para os parâmetros de tipo.

*type-parameter-constraints-clauses*<br/>
Assume o formato especificado em [Restrições em parâmetros de tipo genérico (C++/CLI)](constraints-on-generic-type-parameters-cpp-cli.md)

*accessibility-modifiers*<br/>
Adicional Modificadores de acessibilidade (por exemplo **`public`** , **`private`** ).

*tipo de resultado*<br/>
O tipo de retorno do delegado.

*ID*<br/>
O nome do delegado.

*formal-parameters*<br/>
(Opcional) A lista de parâmetros do delegado.

## <a name="examples"></a>Exemplos

Os parâmetros de tipo delegado são especificados no ponto em que um objeto delegado é criado. Tanto o delegado quanto o método associado a ele devem ter a mesma assinatura. Veja a seguir um exemplo de uma declaração de delegado genérico.

```cpp
// generics_generic_delegate1.cpp
// compile with: /clr /c
generic <class ItemType>
delegate ItemType GenDelegate(ItemType p1, ItemType% p2);
```

O exemplo a seguir mostra que

- Você não pode usar o mesmo objeto delegado com diferentes tipos construídos. Crie diferentes objetos delegados para diferentes tipos.

- Um delegado genérico pode ser associado a um método genérico.

- Quando um método genérico é chamado sem especificar argumentos de tipo, o compilador tenta inferir os argumentos de tipo da chamada.

```cpp
// generics_generic_delegate2.cpp
// compile with: /clr
generic <class ItemType>
delegate ItemType GenDelegate(ItemType p1, ItemType% p2);

generic <class ItemType>
ref struct MyGenClass {
   ItemType MyMethod(ItemType i, ItemType % j) {
      return ItemType();
   }
};

ref struct MyClass {
   generic <class ItemType>
   static ItemType MyStaticMethod(ItemType i, ItemType % j) {
      return ItemType();
   }
};

int main() {
   MyGenClass<int> ^ myObj1 = gcnew MyGenClass<int>();
   MyGenClass<double> ^ myObj2 = gcnew MyGenClass<double>();
   GenDelegate<int>^ myDelegate1 =
      gcnew GenDelegate<int>(myObj1, &MyGenClass<int>::MyMethod);

   GenDelegate<double>^ myDelegate2 =
      gcnew GenDelegate<double>(myObj2, &MyGenClass<double>::MyMethod);

   GenDelegate<int>^ myDelegate =
      gcnew GenDelegate<int>(&MyClass::MyStaticMethod<int>);
}
```

O exemplo a seguir declara um delegado genérico `GenDelegate<ItemType>` e, em seguida, instancia-o associando-o ao método `MyMethod` que usa o parâmetro de tipo `ItemType`. Duas instâncias do delegado (um inteiro e um duplo) são criadas e invocadas.

```cpp
// generics_generic_delegate.cpp
// compile with: /clr
using namespace System;

// declare generic delegate
generic <typename ItemType>
delegate ItemType GenDelegate (ItemType p1, ItemType% p2);

// Declare a generic class:
generic <typename ItemType>
ref class MyGenClass {
public:
   ItemType MyMethod(ItemType p1, ItemType% p2) {
      p2 = p1;
      return p1;
    }
};

int main() {
   int i = 0, j = 0;
   double m = 0.0, n = 0.0;

   MyGenClass<int>^ myObj1 = gcnew MyGenClass<int>();
   MyGenClass<double>^ myObj2 = gcnew MyGenClass<double>();

   // Instantiate a delegate using int.
   GenDelegate<int>^ MyDelegate1 =
      gcnew GenDelegate<int>(myObj1, &MyGenClass<int>::MyMethod);

   // Invoke the integer delegate using MyMethod.
   i = MyDelegate1(123, j);

   Console::WriteLine(
      "Invoking the integer delegate: i = {0}, j = {1}", i, j);

   // Instantiate a delegate using double.
   GenDelegate<double>^ MyDelegate2 =
      gcnew GenDelegate<double>(myObj2, &MyGenClass<double>::MyMethod);

   // Invoke the integer delegate using MyMethod.
   m = MyDelegate2(0.123, n);

   Console::WriteLine(
      "Invoking the double delegate: m = {0}, n = {1}", m, n);
}
```

```Output
Invoking the integer delegate: i = 123, j = 123
Invoking the double delegate: m = 0.123, n = 0.123
```

## <a name="see-also"></a>Confira também

[Genéricos](generics-cpp-component-extensions.md)
