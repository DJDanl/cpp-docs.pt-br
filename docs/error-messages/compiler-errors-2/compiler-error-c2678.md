---
title: "Erro do Compilador C2678 | Microsoft Docs"
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
  - "C2678"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2678"
ms.assetid: 1f0a4e26-b429-44f5-9f94-cb66441220c8
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2678
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

binário 'operator': Nenhum operador definido que leva um operando esquerdo do tipo 'type' \(ou não há nenhuma conversão aceitável\)  
  
 Para usar o operador, você deve sobrecarregá\-lo para o tipo especificado ou definir uma conversão para um tipo para o qual o operador está definido.  
  
## Exemplo  
 C2678 pode ocorrer quando o operando esquerdo for qualificado const, mas o operador está definido para levar um argumento não const.  
  
 O exemplo a seguir gera C2678 e mostra como corrigi\-lo:  
  
```  
// C2678a.cpp  
// Compile by using: cl /EHsc /W4 C2678a.cpp  
struct Combo {  
   int number;  
   char letter;  
};  
  
inline Combo& operator+=(Combo& lhs, int rhs) {  
   lhs.number += rhs;  
   return lhs;  
}  
  
int main() {  
   Combo const combo1{ 42, 'X' };  
   Combo combo2{ 13, 'Z' };  
  
   combo1 += 6; // C2678  
   combo2 += 9; // OK - operator+= matches non-const Combo  
}  
```  
  
## Exemplo  
 C2678 também pode ocorrer se você não coloque um membro nativo antes de chamar uma função de membro.  
  
 O exemplo a seguir gera C2678 e mostra como corrigi\-lo.  
  
```  
// C2678.cpp  
// compile with: /clr /c  
struct S { int _a; };  
  
ref class C {  
public:  
   void M( S param ) {  
      test = param;   // C2678  
  
      // OK  
      pin_ptr<S> ptest = &test;  
      *ptest = param;  
   }  
   S test;  
};  
```  
  
## Exemplo  
 O exemplo a seguir gera C2678 e mostra como corrigi\-lo.  
  
```  
// C2678_2.cpp  
// compile with: /clr:oldSyntax /c  
struct S { int _a; };  
  
__gc class C {  
public:  
   void M(S param) {  
      test = param;   // C2678  
  
      // OK  
      S __pin* ptest = &test;  
      *ptest = param;  
   }  
  
   S test;  
};  
```