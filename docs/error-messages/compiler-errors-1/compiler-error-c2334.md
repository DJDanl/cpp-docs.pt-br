---
title: C2334 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2334
dev_langs:
- C++
helpviewer_keywords:
- C2334
ms.assetid: 36142855-e00b-4bbf-80f5-a301edeff46e
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b31ba4a8a5711fcdfbfca725938beb9afdf4301c
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2334"></a>C2334 de erro do compilador
tokens inesperados anterior ': ou {'; ignorando corpo aparente de função  
  
 O exemplo a seguir gera C2334. Esse erro ocorre após erro C2059:  
  
```  
// C2334.cpp  
// compile with: /c  
// C2059 expected  
struct s1 {  
   s1   {}   // C2334  
   s1() {}   // OK  
};  
```
