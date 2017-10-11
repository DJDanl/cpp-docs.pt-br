---
title: C2327 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2327
dev_langs:
- C++
helpviewer_keywords:
- C2327
ms.assetid: 95278c95-d1f9-4487-ad27-53311f5e8112
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 2eefd1e3fb4f23087b0f08bf6a9ff55593d9a961
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2327"></a>C2327 de erro do compilador
'symbol': não é um nome de tipo, static ou enumerador  
  
 O código dentro de uma classe aninhada tenta acessar um membro da classe delimitador que não é um nome de tipo, um membro estático ou um enumerador.  
  
 Ao compilar com **/clr**, uma causa comum para C2327 é uma propriedade com o mesmo nome que o tipo de propriedade.  
  
 O exemplo a seguir gera C2327:  
  
```  
// C2327.cpp  
int x;  
class enclose {  
public:  
   int x;  
   static int s;  
   class inner {  
      void f() {  
         x = 1;   // C2327; enclose::x is not static  
         s = 1;   // ok; enclose::s is static  
         ::x = 1;   // ok; ::x refers to global  
      }  
   };  
};  
```  
  
 C2327 também poderá ocorrer se o nome de um tipo é ocultado por nome de um membro:  
  
```  
// C2327b.cpp  
class X {};  
  
class S {  
   X X;  
   // try the following line instead  
   // X MyX;  
   X other;   // C2327, rename member X  
};  
```  
  
 C2327 também podem acionar nessa situação, onde você precisa especificar totalmente o tipo de dados do parâmetro:  
  
```  
// C2327c.cpp  
// compile with: /c  
struct A {};  
  
struct B {  
   int A;  
   void f(A a) {   // C2327  
   void f2(struct A a) {}   // OK  
   }  
};  
```  
  
 O exemplo a seguir gera C2327:  
  
```  
// C2327d.cpp  
// compile with: /clr /c  
using namespace System;  
  
namespace NA {  
   public enum class E : Int32 {  
      one = 1,  
      two = 2,  
      three = 3  
   };  
  
   public ref class A {  
   private:  
      E m_e;  
   public:  
      property E E {  
         NA::E get() {  
            return m_e;  
         }  
         // At set, compiler doesn't know whether E is get_E or   
         // Enum E, therefore fully qualifying Enum E is necessary  
         void set( E e ) {   // C2327  
            // try the following line instead  
            // void set(NA::E e) {  
            m_e = e;  
         }  
      }  
   };  
}  
```  
  
O exemplo a seguir mostra C2327 quando uma propriedade tem o mesmo nome que o tipo de propriedade:  
  
```  
// C2327f.cpp  
// compile with: /clr /c  
public value class Address {};  
  
public ref class Person {  
public:  
   property Address Address {  
      ::Address get() {     
         return address;  
      }  
      void set(Address addr) {   // C2327  
      // try the following line instead  
      // set(::Address addr) {  
         address = addr;   
      }  
   }  
private:  
   Address address;   // C2327  
   // try the following line instead  
   // ::Address address;  
};  
```  

