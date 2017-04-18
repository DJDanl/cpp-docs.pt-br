---
title: "Compilador aviso (nível 3) C4645 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4645
dev_langs:
- C++
helpviewer_keywords:
- C4645
ms.assetid: fd7c1ddf-f0d0-4e10-bab9-ccb4c3476298
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 077793fdc0b226cf10d4f51850da121095ed4fc7
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4645"></a>Compilador C4645 de aviso (nível 3)
função declarada com __declspec(noreturn) possui uma instrução return  
  
 A [retornar](../../cpp/return-statement-in-program-termination-cpp.md) instrução foi encontrada em uma função que é marcada com o [noreturn](../../cpp/noreturn.md) `__declspec` modificador. O `return` instrução foi ignorada.  
  
 O exemplo a seguir gera C4645:  
  
```  
// C4645.cpp  
// compile with:  /W3  
void __declspec(noreturn) func() {  
   return;   // C4645, delete this line to resolve  
}  
  
int main() {  
}  
```
