---
title: C2272 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2272
dev_langs:
- C++
helpviewer_keywords:
- C2272
ms.assetid: 1517706a-9c27-452e-9b10-3424b3d232bc
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 305b0cd510c088f4731a8430959f76bb57ee33a6
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2272"></a>C2272 de erro do compilador
'function': modificadores não permitidos em funções membro static  
  
 Um `static` função de membro é declarada com um especificador de modelo de memória, como [const](../../cpp/const-cpp.md) ou [volátil](../../cpp/volatile-cpp.md), e esses modificadores não são permitidos em `static` funções de membro.  
  
 O exemplo a seguir gera C2272:  
  
```  
// C2272.cpp  
// compile with: /c  
class CMyClass {  
public:  
   static void func1() const volatile;   // C2272  func1 is static  
   void func2() const volatile;   // OK  
};  
```
