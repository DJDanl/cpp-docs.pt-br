---
title: C2298 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2298
dev_langs:
- C++
helpviewer_keywords:
- C2298
ms.assetid: eb0120ad-c850-4bdd-911d-0361229cc859
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 3bd426fb1351577a1cfc42c78daa77826705341f
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2298"></a>C2298 de erro do compilador
'operação de ': operação ilegal no ponteiro para a expressão de função de membro  
  
 Um ponteiro para a expressão de função de membro deve chamar a função de membro.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2298.  
  
```  
// C2298.cpp  
#include <stdio.h>  
  
struct X {  
   void mf() {  
      puts("in X::mf");  
   }  
  
   void mf2() {  
      puts("in X::mf2");  
   }  
};  
  
X x;  
// pointer to member functions with no params and void return in X  
typedef void (X::*pmf_t)();   
  
// a pointer to member function X::mf  
void (X::*pmf)() = &X::mf;  
  
int main() {  
   int (*pf)();  
   pf = x.*pmf;   // C2298  
   +(x.*pmf);     // C2298  
  
   pmf_t pf2 = &X::mf2;  
   (x.*pf2)();   // uses X::mf2  
   (x.*pmf)();   // uses X::mf  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2298.  
  
```  
// C2298_b.cpp  
// compile with: /c  
void F() {}  
  
class Measure {  
public:  
   void SetTrackingFunction(void (Measure::*fnc)()) {  
      TrackingFunction = this->*fnc;   // C2298  
      TrackingFunction = fnc;   // OK  
      GlobalTracker = F;   // OK  
   }  
private:  
   void (Measure::*TrackingFunction)(void);  
   void (*GlobalTracker)(void);  
};  
```
