---
title: "Compilador (nível 1) de aviso C4020 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4020
dev_langs:
- C++
helpviewer_keywords:
- C4020
ms.assetid: 8c4cd6be-9371-4c8c-b0ff-a5ad367bbab0
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: f4980961746f2711fcf0655dd37b5f37d8d8124e
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-warning-level-1-c4020"></a>Compilador C4020 de aviso (nível 1)
'function': muitos parâmetros reais  
  
 O número de parâmetros reais em uma chamada de função excede o número de parâmetros formais no protótipo de função ou definição. O compilador passa os parâmetros extra reais de acordo com a convenção de chamada da função.  
  
 O exemplo a seguir gera C4020:  
  
```  
// C4020.c  
// compile with: /W1 /c  
void f(int);  
int main() {  
   f(1,2);   // C4020  
}  
```  
  
 Possível solução:  
  
```  
// C4020b.c  
// compile with: /c  
void f(int);  
int main() {  
   f(1);  
}  
```
