---
title: "Compilador aviso (nível 1) C4020 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
ms.openlocfilehash: 15cb40b592452081cac5de3cfe887f60d2b24c1e
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4020"></a>Compilador C4020 de aviso (nível 1)
'function': excesso de parâmetros real  
  
 O número de parâmetros reais em uma chamada de função excede o número de parâmetros formais na definição ou protótipo de função. O compilador passa parâmetros extras reais de acordo com a convenção de chamada da função.  
  
 O exemplo a seguir gera C4020:  
  
```  
// C4020.c  
// compile with: /W1 /c  
void f(int);  
int main() {  
   f(1,2);   // C4020  
}  
```  
  
 Resolução possível:  
  
```  
// C4020b.c  
// compile with: /c  
void f(int);  
int main() {  
   f(1);  
}  
```
