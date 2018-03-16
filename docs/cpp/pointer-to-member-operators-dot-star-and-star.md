---
title: Operadores de ponteiro para membro:. * e -&gt;* | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- .*
- ->*
dev_langs:
- C++
helpviewer_keywords:
- expressions [C++], pointer
- pointer-to-member operators [C++]
- .* operator
- expressions [C++], operators
- ->* operator
ms.assetid: 2632be3f-1c81-4523-b56c-982a92a68688
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6db7b7190a1374564071775ce2ea6c0777bdf567
ms.sourcegitcommit: 9239c52c05e5cd19b6a72005372179587a47a8e4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2018
---
# <a name="pointer-to-member-operators--and--gt"></a>Operadores de ponteiro para membro:. * e -&gt;*
## <a name="syntax"></a>Sintaxe  
  
```  
expression .* expression  
expression ->* expression  
```  
  
## <a name="remarks"></a>Comentários  
 Os operadores de ponteiro para membro,. * e ->\*, retornar o valor de um membro de classe específica para o objeto especificado no lado esquerdo da expressão.  O lado direito deve especificar um membro da classe.  O exemplo a seguir mostra como usar estes operadores:  
  
```  
// expre_Expressions_with_Pointer_Member_Operators.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
  
class Testpm {  
public:  
   void m_func1() { cout << "m_func1\n"; }  
   int m_num;  
};  
  
// Define derived types pmfn and pmd.  
// These types are pointers to members m_func1() and  
// m_num, respectively.  
void (Testpm::*pmfn)() = &Testpm::m_func1;  
int Testpm::*pmd = &Testpm::m_num;  
  
int main() {  
   Testpm ATestpm;  
   Testpm *pTestpm = new Testpm;  
  
// Access the member function  
   (ATestpm.*pmfn)();  
   (pTestpm->*pmfn)();   // Parentheses required since * binds  
                        // less tightly than the function call.  
  
// Access the member data  
   ATestpm.*pmd = 1;  
   pTestpm->*pmd = 2;  
  
   cout  << ATestpm.*pmd << endl  
         << pTestpm->*pmd << endl;  
   delete pTestpm;  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
m_func1  
m_func1  
1  
2  
```  
  
 No exemplo anterior, um ponteiro para um membro, `pmfn`, é usado para invocar a função de membro `m_func1`. Outro ponteiro para um membro, `pmd`, é usado para acessar o membro `m_num`.  
  
 O operador binário .* combina seu primeiro operando, que deve ser um objeto de tipo de classe, com o segundo operando, que deve ser um tipo de ponteiro para membro.  
  
 O operador binário -> * combina seu primeiro operando, que deve ser um ponteiro para um objeto do tipo de classe, com seu segundo operando deve ser um tipo de ponteiro-para-membro.  
  
 Em uma expressão que contém o operador .*, o primeiro operando deve ser do tipo de classe, e é acessível para, do ponteiro para o membro especificado no segundo operando ou de um tipo acessível derivado de maneira não ambígua de e acessíveis a essa classe.  
  
 Em uma expressão que contém o-> * operador, o primeiro operando deve ser do tipo "ponteiro para o tipo de classe" do tipo especificado no segundo operando, ou ele deve ser de um tipo de maneira não ambígua derivado de classe.  
  
## <a name="example"></a>Exemplo  
 Considere as seguintes classes e fragmento de programa:  
  
```  
// expre_Expressions_with_Pointer_Member_Operators2.cpp  
// C2440 expected  
class BaseClass {  
public:  
   BaseClass(); // Base class constructor.  
   void Func1();  
};  
  
// Declare a pointer to member function Func1.  
void (BaseClass::*pmfnFunc1)() = &BaseClass::Func1;  
  
class Derived : public BaseClass {  
public:  
   Derived();  // Derived class constructor.  
   void Func2();  
};  
  
// Declare a pointer to member function Func2.  
void (Derived::*pmfnFunc2)() = &Derived::Func2;  
  
int main() {  
   BaseClass ABase;  
   Derived ADerived;  
  
   (ABase.*pmfnFunc1)();   // OK: defined for BaseClass.  
   (ABase.*pmfnFunc2)();   // Error: cannot use base class to  
                           // access pointers to members of  
                           // derived classes.   
  
   (ADerived.*pmfnFunc1)();   // OK: Derived is unambiguously  
                              // derived from BaseClass.   
   (ADerived.*pmfnFunc2)();   // OK: defined for Derived.  
}  
```  
  
 O resultado da. * ou ->\* operadores de ponteiro para membro é um objeto ou função do tipo especificado na declaração de ponteiro para membro. Assim, no exemplo anterior, o resultado da expressão `ADerived.*pmfnFunc1()` é um ponteiro para uma função que retorna void. Esse resultado será um valor l se o segundo operando for um valor l.  
  
> [!NOTE]
>  Se o resultado de um dos operadores de ponteiro para membro for uma função, o resultado poderá ser usado apenas como um operando para o operador da chamada de função.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)

