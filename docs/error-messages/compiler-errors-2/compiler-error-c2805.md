---
title: C2805 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2805
dev_langs:
- C++
helpviewer_keywords:
- C2805
ms.assetid: c997dc56-e199-442f-b94e-ac551ec9b015
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 6c314f93f9933fa20051aad91442a2d1ac00b9da
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2805"></a>C2805 de erro do compilador
binário 'operator operador' possui poucos parâmetros  
  
 O operador binário não tem parâmetros.  
  
 O exemplo a seguir gera C2805:  
  
```  
// C2805.cpp  
// compile with: /c  
class X {  
public:  
   X operator< ( void );   // C2805 must take one parameter  
   X operator< ( X );   // OK  
};  
```
