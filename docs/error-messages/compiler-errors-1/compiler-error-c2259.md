---
title: "C2259 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2259"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2259"
ms.assetid: e458236f-bdea-4786-9aa6-a98d8bffa5f4
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2259 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“classes: não é possível criar uma instância da classe abstrata  
  
 O código a seguir declara uma instância de uma classe abstrata ou estrutura.  
  
 Você não pode criar uma instância de uma classe ou estrutura com uma ou mais funções virtuais puras.  Para criar uma instância dos objetos de uma classe derivada, a classe derivada deve substituir cada função virtual pura.  
  
 Para obter mais informações, consulte [Implicitamente classes abstratas](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Implicitly_abstract_classes).  
  
 O seguinte exemplo gera C2259:  
  
```  
// C2259.cpp  
// compile with: /c  
class V {  
public:  
   void virtual func() = 0;  
};  
class A : public V {};  
class B : public V {  
public:  
   void func();  
};  
V v;  // C2259, V is an abstract class  
A a;  // C2259, A inherits func() as pure virtual  
B b;  // OK, B defines func()  
```  
  
 Sempre que você se deriva de e se uma interface implementa os métodos da interface na classe derivada com permissões de acesso diferentes do utilitário, você pode receber C2259.  Isso ocorre porque o compilador espera os métodos da interface implementados na classe derivada para ter acesso público.  Quando você implementa as funções de membro para uma interface com as permissões de acesso mais restritivas, o compilador não irá considerá\-las ser implementações dos métodos da interface definidos na interface, que faz por sua vez da classe derivada uma classe abstrata.  
  
 Há duas soluções alternativas possíveis para o problema:  
  
-   Faça o utilitário permissões de acesso para os métodos implementados.  
  
-   Use o operador de resolução de escopo dos métodos da interface implementados na classe derivada para qualificar o nome do método implementado com o nome da interface.  
  
 C2259 também pode ocorrer no resultado do trabalho que foi feito no Visual C\+\+ 2005, **\/Zc:wchar\_t** de conformidade agora é ativado por padrão.  Nessa situação, C2599 pode ser resolvido ou compilando com **\/Zc:wchar\_t\-**, para obter o comportamento de versões anteriores, ou preferivelmente, atualizando seus tipos de modo que sejam compatíveis.  Para obter mais informações, consulte [\/Zc:wchar\_t \(wchar\_t é do tipo nativo\)](../../build/reference/zc-wchar-t-wchar-t-is-native-type.md).  
  
 O seguinte exemplo gera C2259:  
  
```  
// C2259b.cpp  
// compile with: /c  
#include <windows.h>   
  
class MyClass {  
public:  
   // WCHAR now typedef'ed to wchar_t  
   virtual void func(WCHAR*) = 0;  
};  
  
class MyClass2 : MyClass {  
public:  
   void func(unsigned short*);  
};  
  
MyClass2 x;   // C2259  
  
// OK  
class MyClass3 {  
public:  
   virtual void func(WCHAR*) = 0;  
   virtual void func2(wchar_t*) = 0;  
   virtual void func3(unsigned short*) = 0;  
};  
  
class MyClass4 : MyClass3 {  
public:  
   void func(WCHAR*) {}  
   void func2(wchar_t*) {}  
   void func3(unsigned short*) {}  
};  
  
MyClass4 y;  
```  
  
 O seguinte exemplo gera C2259:  
  
```  
// C2259c.cpp  
// compile with: /clr  
interface class MyInterface {  
   void MyMethod();  
};  
  
ref class MyDerivedClass: public MyInterface {  
private:  
   // Uncomment the following line to resolve.  
   // public:  
   void MyMethod(){}  
   // or the following line  
   // void MyInterface::MyMethod() {};  
};  
  
int main() {  
   MyDerivedClass^ instance = gcnew MyDerivedClass; // C2259  
}  
```  
  
 O seguinte exemplo gera C2259:  
  
```  
// C2259d.cpp  
// compile with: /clr:oldSyntax  
public __gc __interface MyInterface {  
   void MyMethod();  
};  
  
__gc class MyDerivedClass : public MyInterface {  
// Uncomment the following line to resolve.  
// public:  
   void MyMethod() {};  
   // or the following line  
   // void MyInterface::MyMethod() {};  
};  
  
int main() {  
   MyDerivedClass *instance = new MyDerivedClass();   // C2259  
}  
```