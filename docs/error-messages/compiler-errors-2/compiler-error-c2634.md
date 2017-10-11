---
title: C2634 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2634
dev_langs:
- C++
helpviewer_keywords:
- C2634
ms.assetid: 58c8f2db-ac95-4a81-9355-ef3cfb0ba7b3
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 2aa4d35dedc49ad4fbb226cb47790b9bedcfa6fa
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2634"></a>C2634 de erro do compilador
' & class::member': ponteiro para membro de referência é inválido  
  
 Um ponteiro para um membro de referência é declarado.  
  
 O exemplo a seguir gera C2634:  
  
```  
// C2634.cpp  
int mem;  
struct S {  
   S() : rf(mem) { }  
   int &rf;  
};  
int (S::*pdm) = &S::rf;   // C2634  
```
