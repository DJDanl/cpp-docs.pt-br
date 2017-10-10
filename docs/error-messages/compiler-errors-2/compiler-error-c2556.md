---
title: C2556 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2556
dev_langs:
- C++
helpviewer_keywords:
- C2556
ms.assetid: fc4399ad-45b3-49fd-be1f-0b13956a595a
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 6678c34022c28dccfa5920809e7b8d6db0d39546
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2556"></a>C2556 de erro do compilador
'Identificador': funções sobrecarregadas diferem apenas por tipo de retorno  
  
 As funções sobrecarregadas têm tipos de retorno diferentes, mas a mesma lista de parâmetros. Cada função sobrecarregada deve ter uma lista de parâmetros formais distintos.  
  
 O exemplo a seguir gera C2556:  
  
```  
// C2556.cpp  
// compile with: /c  
class C {  
   int func();  
   double func();   // C2556  
   int func(int i);   // ok parameter lists differ  
};  
```
