---
title: "Erro do Compilador C2885 | Microsoft Docs"
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
  - "C2885"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2885"
ms.assetid: 7743e5f3-a034-44b4-9ee8-5a6254c27f8c
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2885
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“mais class::identifier”: não usados uma declaração válido no escopo de não classe  
  
 Você usou uma declaração de [usando](../../cpp/using-declaration.md) incorretamente.  
  
## Exemplo  
 Esse erro pode ser gerado no resultado do trabalho de conformidade do compilador que foi feito para Visual C\+\+ 2005: não é mais válida ter uma declaração de `using` a um tipo aninhado; você deve qualificar explicitamente cada referência feitas ao tipo aninhado, coloca o tipo em um namespace, ou cria um typedef.  
  
 O exemplo a seguir produz C2885.  
  
```  
// C2885.cpp  
namespace MyNamespace {  
   class X1 {};  
}  
  
struct MyStruct {  
   struct X1 {  
      int i;  
   };  
};  
  
int main () {  
   using MyStruct::X1;   // C2885  
  
   // OK  
   using MyNamespace::X1;  
   X1 myX1;  
  
   MyStruct::X1 X12;  
  
   typedef MyStruct::X1 abc;  
   abc X13;  
   X13.i = 9;  
}  
```  
  
## Exemplo  
 Se você usar a palavra\-chave de `using` a um membro da classe, C\+\+ exige que você definir esse membro dentro de outra classe \(uma classe derivada\).  
  
 O exemplo a seguir produz C2885.  
  
```  
// C2885_b.cpp  
// compile with: /c  
class A {  
public:  
   int i;  
};  
  
void z() {  
   using A::i;   // C2885 not in a class  
}  
  
class B : public A {  
public:  
   using A::i;  
};  
```