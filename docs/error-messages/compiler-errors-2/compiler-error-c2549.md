---
title: C2549 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2549
dev_langs:
- C++
helpviewer_keywords:
- C2549
ms.assetid: 29310094-54a3-4605-bc6d-a312a68daf5d
caps.latest.revision: 8
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
ms.openlocfilehash: a2609b657546739c3574f8d856c75c8b7cc0e2ab
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2549"></a>C2549 de erro do compilador
conversão definida pelo usuário não pode especificar um tipo de retorno  
  
 O exemplo a seguir gera C2549:  
  
```  
// C2549.cpp  
// compile with: /c  
class X {  
public:  
   int operator int() { return value; }   // C2549  
  
   // try the following line instead  
   // operator int() { return value; }  
private:  
   int value;  
};  
```
