---
title: C2256 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2256
dev_langs:
- C++
helpviewer_keywords:
- C2256
ms.assetid: 171fa2bc-8c72-49cd-afe5-d723b7acd3c5
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 54802178136f02d0b334203ebcedf020942f0ed9
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2256"></a>C2256 de erro do compilador
Uso inválido de especificador friend em 'function'  
  
 Um construtor ou destruidor não pode ser especificado como um [friend](../../cpp/friend-cpp.md).  
  
 O exemplo a seguir gera C2256:  
  
```  
// C2256.cpp  
// compile with: /c  
class C {  
public:  
   friend ~C();   // C2256  
   ~C();   // OK  
};  
```
