---
title: "Compilador aviso (nível 1) C4353 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4353
dev_langs:
- C++
helpviewer_keywords:
- C4353
ms.assetid: 6e79f186-ed82-4c95-9923-0ad5bb9c4db1
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
ms.openlocfilehash: 485338864e8c0434b436f25209fb495de0347929
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4353"></a>Compilador C4353 de aviso (nível 1)
extensão não padrão usada: constante 0 como expressão de função. Use '__noop' função intrínseca  
  
 Você não pode usar o constante zero (0) como uma expressão de função. Para obter mais informações, consulte [__noop](../../intrinsics/noop.md).  
  
 O exemplo a seguir gera C4353:  
  
```  
// C4353.cpp  
// compile with: /W1  
void MyPrintf(void){};  
#define X 0  
#if X  
   #define DBPRINT MyPrint  
#else  
   #define DBPRINT 0   // C4353 expected  
#endif  
int main(){  
DBPRINT();  
}  
```
