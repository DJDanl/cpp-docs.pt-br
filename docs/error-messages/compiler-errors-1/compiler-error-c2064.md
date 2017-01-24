---
title: "Erro do Compilador C2064 | Microsoft Docs"
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
  - "C2064"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2064"
ms.assetid: 6cda05da-f437-4f50-9813-ae69538713a3
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2064
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

termo não avalia para uma função usando argumentos de N  
  
 É feita uma chamada para uma função por meio de uma expressão.  A expressão não é avaliada como um ponteiro para uma função que usa o número especificado de argumentos.  
  
 Neste exemplo, o código tenta chamar funções não como funções.  O exemplo a seguir gera C2064:  
  
```  
// C2064.cpp  
int i, j;  
char* p;  
void func() {  
   j = i();    // C2064, i is not a function  
   p();        // C2064, p doesn't point to a function  
}  
```  
  
 Você deve chamar ponteiros para funções de membro não estático no contexto de uma instância do objeto.  O exemplo a seguir gera C2064 e mostra como corrigi\-lo:  
  
```  
// C2064b.cpp  
struct C {  
   void func1(){}  
   void func2(){}  
};  
  
typedef void (C::*pFunc)();  
  
int main() {  
   C c;  
   pFunc funcArray[2] = {&C::func1, &C::func2};  
   (funcArray[0])();    // C2064   
   (c.*funcArray[0])(); // OK - function called in instance context  
}  
  
```  
  
 Dentro de uma classe, os ponteiros de função de membro também devem indicar o contexto de objeto de chamada.  O exemplo a seguir gera C2064 e mostra como corrigi\-lo:  
  
```  
// C2064d.cpp  
// Compile by using: cl /c /W4 C2064d.cpp  
struct C {  
   typedef void (C::*pFunc)();  
   pFunc funcArray[2];  
   void func1(){}  
   void func2(){}  
   C() {  
      funcArray[0] = &C::func1;  
      funcArray[1] = &C::func2;  
   }  
   void func3() {  
      (funcArray[0])();   // C2064  
      (this->*funcArray[0])(); // OK - called in this instance context  
   }  
};  
```