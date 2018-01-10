---
title: "interface de classe (extensões de componentes C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: interface_CPP
dev_langs: C++
helpviewer_keywords:
- interface class keyword
- interface struct keyword
ms.assetid: 3ccea701-f50b-4da7-ad6b-f0ee1203e2b9
caps.latest.revision: "30"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: abe4173dabd20442b96c8e5536b040483df4f150
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="interface-class--c-component-extensions"></a>classe de interface (Extensões de Componentes C++)
Declara uma interface.  Para obter informações sobre interfaces nativo, consulte [interface](../cpp/interface.md).  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 **Sintaxe**  
  
```  
  
interface_access  
interface class  
 name :  inherit_accessbase_interface{};interface_accessinterface structname :  inherit_accessbase_interface{};  
```  
  
 **Parâmetros**  
  
 *interface_access*  
 A acessibilidade de uma interface fora do assembly.  Os valores possíveis são **pública** e `private`.  `private` é o padrão.  Interfaces aninhados não podem ter um *interface_access* especificador.  
  
 *name*  
 O nome da interface.  
  
 *inherit_access*  
 A acessibilidade de *base_interface*.  A única permissão acessibilidade é uma interface base `public` (o padrão).  
  
 *base_interface* (opcional)  
 Uma interface base para a interface *nome*.  
  
 **Comentários**  
  
 **interface struct** é equivalente a **classe de interface**.  
  
 Uma interface pode conter declarações de funções, propriedades e eventos.  Todos os membros de interface terem acessibilidade pública. Uma interface também pode conter funções, propriedades, eventos e membros de dados estáticos, e esses membros estáticos devem ser definidos na interface.  
  
 Uma interface define como uma classe pode ser implementada. Uma interface não é uma classe e classes só podem implementar interfaces. Quando uma classe define uma função declarada em uma interface, a função é implementada, não foi substituído. Portanto, a pesquisa de nome não inclui membros de interface.  
  
 Uma classe ou estrutura que deriva de uma interface deve implementar todos os membros da interface. Ao implementar a interface *nome* você também deve implementar as interfaces de `base_interface` lista.  
  
 Para obter mais informações, consulte:  
  
-   [Construtor estático de interface](../dotnet/how-to-define-an-interface-static-constructor-cpp-cli.md)  
  
-   [Interfaces genéricas (Visual C++)](../windows/generic-interfaces-visual-cpp.md)  
  
 Para obter informações sobre outros tipos CLR, consulte [Classes e estruturas](../windows/classes-and-structs-cpp-component-extensions.md).  
  
 Você pode detectar no tempo de compilação se um tipo é uma interface com `__is_interface_class(type)`. Para obter mais informações, consulte [suporte para características do tipo de compilador](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
 No ambiente de desenvolvimento, você pode obter ajuda de F1 sobre essas palavras-chave, destacando a palavra-chave (`interface class`, por exemplo) e pressionando F1.  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 **Comentários**  
  
 (Não há nenhum comentários para esse recurso de idioma que se aplicam somente no tempo de execução do Windows).  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
 **Comentários**  
  
 (Não há nenhum comentários para esse recurso de idioma que se aplicam a apenas o common language runtime).  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir demonstra como uma interface pode definir o comportamento de uma função de relógio.  
  
```  
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
  
 **Saída**  
  
```Output  
in Function_3  
  
in Function_2  
  
in Function_1  
  
8  
  
OnClick: 7, 3.14159  
  
in Function_1  
```  
  
 **Exemplo**  
  
 O exemplo de código a seguir mostra duas maneiras de implementar funções com a mesma assinatura declarada em várias interfaces e em que essas interfaces são usadas por uma classe.  
  
```  
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
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)