---
title: C2678 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2678
dev_langs: C++
helpviewer_keywords: C2678
ms.assetid: 1f0a4e26-b429-44f5-9f94-cb66441220c8
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5b28f29f1f0f509200cabe8dad46a9ad7f0b2da1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2678"></a>C2678 de erro do compilador
binário 'operator': Nenhum operador definido que receba um operando esquerdo do tipo 'type' (ou não há nenhuma conversão aceitável)  
  
 Para usar o operador, você deve sobrecarregá-lo para o tipo especificado ou definir uma conversão para um tipo para o qual o operador está definido.  
  
## <a name="example"></a>Exemplo  
 C2678 pode ocorrer quando o operando esquerdo é qualificado como const, mas o operador está definido para levar um argumento não const.  
  
 O exemplo a seguir gera C2678 e mostra como corrigi-lo:  
  
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
  
## <a name="example"></a>Exemplo  
 C2678 também pode ocorrer se você não fixar um membro nativo antes de chamar uma função de membro.  
  
 O exemplo a seguir gera C2678 e mostra como corrigi-lo.  
  
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
