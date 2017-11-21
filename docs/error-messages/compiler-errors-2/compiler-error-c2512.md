---
title: C2512 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2512
dev_langs: C++
helpviewer_keywords: C2512
ms.assetid: 15206da9-1164-451a-b869-280e00711aad
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 63090bc7dac08aa87bcd68e77c076185176a7285
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c2512"></a>C2512 de erro do compilador
'Identificador': nenhum construtor padrão apropriado disponível  
  
 Nenhum construtor padrão está disponível para a classe especificada, estrutura ou união. O compilador fornece um construtor padrão somente se não forem fornecidos construtores definidos pelo usuário.  
  
 Se você fornecer um construtor que aceita um parâmetro não nulo, e para permitir que sua classe a ser criado sem parâmetros — por exemplo, como os elementos de uma matriz, você também deve fornecer um construtor padrão. O construtor padrão pode ser um construtor com valores padrão para todos os parâmetros.  
  
 O exemplo a seguir gera C2512 e mostra como corrigi-lo:  
  
```  
// C2512.cpp  
// C2512 expected  
struct B {  
   B (char *);  
   // Uncomment the following line to fix.  
   // B() {};  
};  
  
int main() {  
   B b;   
}  
```  
  
 O exemplo a seguir mostra um C2512 mais sutil. Para corrigir esse erro, reorganizar o código para definir a classe antes de seu construtor é referenciado:  
  
```  
// C2512b.cpp  
// compile with: /c  
struct S {  
   struct X;  
  
   void f() {  
      X *x = new X();   // C2512 X not defined yet  
   }  
  
};  
  
struct S::X {};  
  
struct T {  
   struct X;  
   void f();  
};  
  
struct T::X {};  
  
void T::f() {  
   X *x = new X();  
}  
```  
  
 C2512 também pode ser causado por uma chamada para uma classe que contém uma constante ou membro de dados de referência de construção de padrão. Esses membros devem ser inicializados em uma lista de inicializador de construtor, que impede que o compilador gere um construtor padrão.  
  
 O exemplo a seguir gera C2512 e mostra como corrigi-lo:  
  
```  
// C2512c.cpp  
// Compile by using: cl /c /W3 C2512c.cpp  
struct S {  
   const int i_;  
   int &r_;   
};   
  
int SumS() {  
   const int ci = 7;  
   int ir = 42;  
  
   S s1; // C2512 - no default constructor available  
   S s2{ci, ir};  // Fix - initialize const and reference members   
   return s2.i_ + s2.r_;  
}  
```