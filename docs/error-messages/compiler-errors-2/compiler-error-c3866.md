---
title: C3866 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3866
dev_langs:
- C++
helpviewer_keywords:
- C3866
ms.assetid: 685870af-2440-4cdf-a6cb-284a5b96ef9d
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b1bcba6226a05379248a68f2047653333d98cdf8
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3866"></a>C3866 de erro do compilador
função chamada faltando lista de argumentos  
  
 Dentro de uma função de membro não estático, uma chamada de destruidor ou finalizador não tinha uma lista de argumentos.  
  
 O exemplo a seguir gera C3866:  
  
```  
// C3866.cpp  
// compile with: /c  
class C {  
   ~C();  
   void f() {  
      this->~C;   // C3866  
      this->~C();   // OK  
   }  
};  
```
