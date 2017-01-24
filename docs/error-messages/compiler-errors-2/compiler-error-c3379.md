---
title: "Erro do Compilador C3379 | Microsoft Docs"
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
  - "C3379"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3379"
ms.assetid: a66c2c4e-091c-4426-9cde-7c4cfb2ffce1
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3379
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“classes: uma classe aninhadas não pode ter um especificador do assembly como parte de sua declaração  
  
 Quando aplicado a um tipo gerenciado, como a classe ou a estrutura, [público](../../cpp/public-cpp.md) e as palavras\-chave de [privado](../Topic/private%20\(C++\).md) indica se será exposto a classe com os metadados de assembly.  `public` ou `private` não podem ser aplicados a uma classe que herde aninhada, o acesso do assembly incluindo da classe.  
  
 Quando usado com [\/clr](../../build/reference/clr-common-language-runtime-compilation.md), `ref` e as palavras\-chave de `value` indicam que uma classe é gerenciada \(consulte [Classes and Structs](../../windows/classes-and-structs-cpp-component-extensions.md)\).  
  
 O seguinte exemplo gera C3379:  
  
```  
// C3379a.cpp  
// compile with: /clr  
using namespace System;  
  
public ref class A {  
public:  
   static int i = 9;  
  
   public ref class BA {   // C3379  
   // try the following line instead  
   // ref class BA {  
   public:  
      static int ii = 8;  
   };  
};  
  
int main() {  
  
   A^ myA = gcnew A;  
   Console::WriteLine(myA->i);  
  
   A::BA^ myBA = gcnew A::BA;  
   Console::WriteLine(myBA->ii);  
}  
```  
  
 O seguinte exemplo gera C3379:  
  
```  
// C3379b.cpp  
// compile with: /clr:oldSyntax  
#using <mscorlib.dll>  
  
public __gc class A {  
public:  
   static int i = 9;  
  
   public __gc class BA {   // C3379  
   // try the following line instead  
   // __gc class BA {  
   public:  
      static int ii = 8;  
   };  
};  
  
int main() {  
  
   A *myA = new A;  
   Console::WriteLine(myA->i);  
  
   A::BA *myBA = new A::BA;  
   Console::WriteLine(myBA->ii);  
}  
```