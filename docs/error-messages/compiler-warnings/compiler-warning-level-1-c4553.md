---
title: "Compilador aviso (nível 1) C4553 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4553
dev_langs:
- C++
helpviewer_keywords:
- C4553
ms.assetid: d8aacbe0-3cb5-4367-a6e5-fd7e28f0ff9d
caps.latest.revision: 6
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
ms.openlocfilehash: f29ea4173cdbd0fbf5abaebcf27997e1a90c696f
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4553"></a>Compilador C4553 de aviso (nível 1)
'operator': operador não tem efeito; Você pretendia 'operator'?  
  
 Se uma instrução de expressão tiver um operador com nenhum efeito colateral de parte superior da expressão, provavelmente é um erro.  
  
 O exemplo a seguir gera C4553:  
  
```  
// C4553.cpp  
// compile with: /W1  
int func()  
{  
   return 0;  
}  
  
int main()  
{  
   int i;  
   i == func();   // C4553  
   // try the following line instead  
   // i = func();  
}  
```
