---
title: C2683 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2683
dev_langs:
- C++
helpviewer_keywords:
- C2683
ms.assetid: db605e4f-601b-4d05-92a1-c43ca24de08d
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b3e79c1a05ac0d1fab713e2dfa97c9da740088bb
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2683"></a>C2683 de erro do compilador
'cast': 'type' não é um tipo polimórfico  
  
 Não é possível usar [dynamic_cast](../../cpp/dynamic-cast-operator.md) para converter de uma classe não é polimórfico (uma classe com nenhuma função virtual).  
  
 Você pode usar [static_cast](../../cpp/static-cast-operator.md) para realizar conversões de tipos não polimórficas. No entanto, `static_cast` não executa uma verificação de tempo de execução.  
  
 O exemplo a seguir gera C2683:  
  
```  
// C2683.cpp  
// compile with: /c  
class B { };  
class D : public B { };  
  
void f(B* pb) {  
   D* pd1 = dynamic_cast<D*>(pb);  // C2683  
   D* pd1 = static_cast<D*>(pb);   // OK  
}  
```
