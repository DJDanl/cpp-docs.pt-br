---
title: C2090 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2090
dev_langs:
- C++
helpviewer_keywords:
- C2090
ms.assetid: e8176e55-382b-453d-aa27-6597f0274afd
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 9a60a4e2d1a5db0a698e210ca5ed1360a96ffdc6
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2090"></a>C2090 de erro do compilador
função retorna a matriz  
  
 Uma função não pode retornar uma matriz. Em vez disso, retorne um ponteiro para uma matriz.  
  
 O exemplo a seguir gera C2090:  
  
```  
// C2090.cpp  
int func1(void)[] {}   // C2090  
```  
  
 Possível solução:  
  
```  
// C2090b.cpp  
// compile with: /c  
int* func2(int * i) {  
   return i;  
}  
```
