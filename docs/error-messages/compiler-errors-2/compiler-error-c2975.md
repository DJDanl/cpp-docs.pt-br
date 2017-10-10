---
title: C2975 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2975
dev_langs:
- C++
helpviewer_keywords:
- C2975
ms.assetid: 526f6b9d-6c76-4c12-9252-1b1d7c1e06c7
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 07b2b96cd79364215c9a859a9fd0282768ff45e4
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2975"></a>C2975 de erro do compilador
'arg': argumento de template inválido para 'type', esperada expressão de constante de tempo de compilação  
  
 O argumento de modelo não coincide com a declaração de modelo; uma expressão constante deve aparecer dentro de colchetes angulares. Não são permitidas variáveis como argumentos de modelo real. Verifique a definição de modelo para localizar os tipos corretos.  
  
 O exemplo a seguir gera C2975:  
  
```  
// C2975.cpp  
template<int I>  
class X {};  
  
int main() {  
   int i = 4, j = 2;  
   X<i + j> x1;   // C2975  
   X<6> x2;   // OK  
}  
```  
  
 C2975 também ocorrerá quando você usar __LINE\_ \_ como uma constante de tempo de compilação com [/ZI](../../build/reference/z7-zi-zi-debug-information-format.md). Uma solução seria compilar com [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) em vez de **/ZI**.  
  
```  
// C2975b.cpp  
// compile with: /ZI  
// processor: x86  
template<long line>   
void test(void) {}  
  
int main() {  
   test<__LINE__>();   // C2975  
}  
```
