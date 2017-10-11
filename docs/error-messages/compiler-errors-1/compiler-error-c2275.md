---
title: C2275 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2275
dev_langs:
- C++
helpviewer_keywords:
- C2275
ms.assetid: c1eafa71-48de-46e0-82f3-b575538ef205
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 584eb7b3099c52cb8f2a9bded570b4b76ca683d9
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2275"></a>C2275 de erro do compilador
'Identificador': uso inválido deste tipo como uma expressão  
  
 Uma expressão usa o `->` operador com um `typedef` identificador.  
  
 O exemplo a seguir gera C2275:  
  
```  
// C2275.cpp  
typedef struct S {  
    int mem;  
} *S_t;  
void func1( int *parm );  
void func2() {  
    func1( &S_t->mem );   // C2275, S_t is a typedef  
}  
```
