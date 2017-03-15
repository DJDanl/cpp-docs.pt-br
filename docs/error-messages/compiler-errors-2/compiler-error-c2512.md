---
title: C2512 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2512
dev_langs:
- C++
helpviewer_keywords:
- C2512
ms.assetid: 15206da9-1164-451a-b869-280e00711aad
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: a3db6acd6fcfafc6488fff357ff87a30d74f2de0
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2512"></a>C2512 de erro do compilador
'identifier': nenhum construtor padrão apropriado disponível  
  
 Nenhum construtor padrão está disponível para a classe especificada, estrutura ou união. O compilador fornece um construtor padrão apenas se construtores definidos pelo usuário não forem fornecidos.  
  
 Se você fornecer um construtor que aceita um parâmetro não nulo, e para permitir que sua classe a ser criada sem parâmetros — por exemplo, como os elementos de uma matriz, você também deve fornecer um construtor padrão. O construtor padrão pode ser um construtor com valores padrão para todos os parâmetros.  
  
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
  
 O exemplo a seguir mostra um C2512 mais sutil. Para corrigir esse erro, reorganize o código para definir a classe antes que o construtor é referenciado:  
  
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
  
 C2512 também pode ser causado por uma chamada para criar uma classe que contém uma constante ou membro de dados de referência padrão. Esses membros devem ser inicializados em uma lista de inicializador de construtor, que impede que o compilador gera um construtor padrão.  
  
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
