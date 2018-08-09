---
title: Delegados genéricos (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- generic delegates
- delegates, generic [C++]
ms.assetid: 09d430b2-1aef-4fbc-87f9-9d7b8185d798
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5aa0bc804b3308a9b77c93cf40a2ba9cab7558a8
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39652895"
---
# <a name="generic-delegates-visual-c"></a>Delegados genéricos (Visual C++)
Você pode usar parâmetros de tipo genérico com delegados. Para obter mais informações sobre delegados, consulte [delegado (extensões de componentes C++)](../windows/delegate-cpp-component-extensions.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[attributes]   
generic < [class | typename] type-parameter-identifiers>  
[type-parameter-constraints-clauses]  
[accessibility-modifiers] delegate result-type identifier   
([formal-parameters]);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *atributos* (opcional)  
 Informações declarativas adicionais. Para obter mais informações sobre atributos e classes de atributos, consulte atributos.  
  
 *tipo-parâmetro-identificador (es)*  
 Lista separada por vírgulas de identificadores para os parâmetros de tipo.  
  
 *tipo de parâmetro-restrições cláusulas*  
 Assume o formato especificado no [restrições em parâmetros de tipo genéricos (C + + c++ CLI)](../windows/constraints-on-generic-type-parameters-cpp-cli.md)  
  
 *modificadores de acessibilidade* (opcional)  
 Modificadores de acessibilidade (por exemplo, **pública**, **privada**).  
  
 *result-type*  
 O tipo de retorno do delegado.  
  
 *identifier*  
 O nome do delegado.  
  
 *parâmetros formais de* (opcional)  
 A lista de parâmetros do delegado.  
  
## <a name="example"></a>Exemplo  
 Os parâmetros de tipo de delegado são especificados no ponto em que um objeto delegado é criado. O delegado e o método associado a ele devem ter a mesma assinatura. O exemplo a seguir é um exemplo de uma declaração de delegado genérico.  
  
```cpp  
// generics_generic_delegate1.cpp  
// compile with: /clr /c  
generic <class ItemType>  
delegate ItemType GenDelegate(ItemType p1, ItemType% p2);  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra que  
  
-   Você não pode usar o mesmo objeto de delegado com diferentes tipos construídos. Crie objetos para diferentes tipos de delegado diferente.  
  
-   Um delegado genérico pode ser associado um método genérico.  
  
-   Quando um método genérico é chamado sem especificar argumentos de tipo, o compilador tentará deduzir os argumentos de tipo para a chamada.  
  
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
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir declara um delegado genérico `GenDelegate<ItemType>`e, em seguida, cria uma instância-lo por meio de associação para o método `MyMethod` que usa o parâmetro de tipo `ItemType`. Duas instâncias do delegado (um número inteiro e um valor double) são criadas e invocadas.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Genéricos](../windows/generics-cpp-component-extensions.md)