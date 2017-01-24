---
title: "Erro do Compilador C3185 | Microsoft Docs"
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
  - "C3185"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3185"
ms.assetid: 5bf96279-043c-4981-9d02-b4550071b192
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3185
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'typeid' usado em gerenciado ou tipo WinRT 'type', use 'operator' em vez disso  
  
 Você não pode aplicar o [typeid](../../cpp/typeid-operator.md) operador a ser gerenciada ou WinRT digite; use [typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md) em vez disso.  
  
 O exemplo a seguir gera C3185 e mostra como corrigi\-lo:  
  
```  
// C3185a.cpp  
// compile with: /clr  
ref class Base {};  
ref class Derived : public Base {};  
  
int main() {  
   Derived ^ pd = gcnew Derived;  
   Base ^pb = pd;  
   const type_info & t1 = typeid(pb);   // C3185  
   System::Type ^ MyType = Base::typeid;   // OK  
};  
```  
  
 **Extensões gerenciadas do C\+\+**  
  
 Não é possível aplicar [typeid](../../cpp/typeid-operator.md) para um tipo gerenciado; use [TypeOf](../../misc/typeof.md) em vez disso.  
  
 O exemplo a seguir gera C3185:  
  
```  
// C3185b.cpp  
// compile with: /clr:oldSyntax  
#using <mscorlib.dll>  
__gc class Base {};  
__gc class Derived : public Base {};  
  
int main() {  
   Derived *pd = new Derived;  
   Base *pb = pd;  
   const type_info & t1 = typeid(*pb);   // C3185  
  
   // OK  
   Type * t = __typeof(Base);  
   Type * t1 = __typeof(Derived);  
};  
```