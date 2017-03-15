---
title: C2705 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2705
dev_langs:
- C++
helpviewer_keywords:
- C2705
ms.assetid: 29249ea3-4ea7-4105-944b-bdb83e8d6852
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
ms.openlocfilehash: 17617aa6121e6ac05c1119bc4d5025fb2588faac
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2705"></a>C2705 de erro do compilador
'Rótulo': ilegal salto no escopo de 'block do manipulador de exceção'  
  
 Execution jumps to a label within a `try`/`catch`, `__try`/`__except`, `__try`/`__finally` block. Para obter mais informações, consulte [Exception Handling](../../cpp/exception-handling-in-visual-cpp.md).  
  
 O exemplo a seguir gera C2705:  
  
```  
// C2705.cpp  
int main() {  
goto trouble;  
   __try {  
      trouble: ;   // C2705  
   }  
   __finally {}  
  
   // try the following line instead  
   // trouble: ;  
}  
```
