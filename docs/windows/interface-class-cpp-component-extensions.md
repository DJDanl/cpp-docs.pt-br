---
title: "interface class  (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "interface_CPP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "interface class keyword"
  - "interface struct keyword"
ms.assetid: 3ccea701-f50b-4da7-ad6b-f0ee1203e2b9
caps.latest.revision: 30
caps.handback.revision: 28
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# interface class  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Declara uma interface.  Para obter informações sobre as interfaces nativos, consulte [\_\_interface](../Topic/__interface.md).  
  
## Todos os Tempos de Execução  
 **Sintaxe**  
  
```  
  
        interface_access interface class  name :  inherit_access base_interface {};  
interface_access interface struct name :  inherit_access base_interface {};  
```  
  
 **Parâmetros**  
  
 *interface\_access*  
 Acessibilidade de uma interface fora do assembly.  Os valores possíveis são **public** e `private`.  `private` é o padrão.  As interfaces aninhadas não podem ter um especificador de *interface\_access* .  
  
 *name*  
 O nome da interface.  
  
 *inherit\_access*  
 A acessibilidade de *base\_interface*.  A única acessibilidade permitida para uma interface base é `public` \(o padrão\).  
  
 *base\_interface* \(opcional\)  
 Uma interface base para a interface *name*.  
  
 **Comentários**  
  
 **interface struct** é equivalente a **interface class**.  
  
 Uma interface pode conter instruções para funções, eventos, e.  Todos os membros de têm acessibilidade a interface pública.  Uma interface também pode conter membros de dados estáticos, funções, eventos, as propriedades e, e esses membros estáticos devem ser definidos na interface.  
  
 Uma interface define como uma classe pode ser implementada.  Uma interface não é uma classe e as classes só podem implementar interfaces.  Quando uma classe define uma função declarada em uma interface, a função é implementada, não substituída.  Consequentemente, a pesquisa do nome não inclui membros da interface.  
  
 Uma classe ou uma estrutura que se derivem da interface devem implementar todos os membros da interface.  Ao implementar *o nome* da interface você também deve implementar as interfaces em `base_interface` lista.  
  
 Para obter mais informações, consulte:  
  
-   [Construtor estáticos de interface](../dotnet/how-to-define-an-interface-static-constructor-cpp-cli.md)  
  
-   [Generic Interfaces \(Visual C\+\+\)](../Topic/Generic%20Interfaces%20\(Visual%20C++\).md)  
  
 Para obter informações sobre outros tipos de CLR, consulte [Classes e Estruturas](../windows/classes-and-structs-cpp-component-extensions.md).  
  
 Você pode detectar em tempo de compilação se um tipo é uma interface com `__is_interface_class(``type``)`.  Para obter mais informações, consulte [Compiler Support for Type Traits](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
 No ambiente de desenvolvimento, você pode obter F1 ajuda para essas palavras\-chave realçando a palavra\-chave, \(`interface class`, por exemplo\) e pressionando F1.  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 **Comentários**  
  
 \(Não há nenhum comentário sobre este recurso de linguagem que se aplica somente Tempo de Execução do Windows\).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Comentários**  
  
 \(Não há nenhum comentário sobre este recurso de linguagem que se aplica somente ao common language runtime\).  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir demonstra como uma interface pode definir o comportamento de uma função do relógio.  
  
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
  
  **em Function\_3**  
 **em Function\_2**  
 **em Function\_1**  
 **8**  
 **OnClick: 7, 3,14159**  
 **em Function\_1** **Exemplo**  
  
 O exemplo a seguir mostra do exemplo de código duas formas de implementar funções com a mesma assinatura declarada em interfaces de vários e onde as interfaces são usadas por uma classe.  
  
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
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)