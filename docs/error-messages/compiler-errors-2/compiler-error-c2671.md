---
title: C2671 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2671
dev_langs:
- C++
helpviewer_keywords:
- C2671
ms.assetid: fc0ee40f-c8f3-408f-b89d-745d149c4169
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 4cfea4daeb6bb4adce028cfee19bb33b8e1a008d
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2671"></a>C2671 de erro do compilador
'function': funções membro static não possuem ponteiros 'this'  
  
 Um `static` função membro tentou acessar `this`.  
  
 O exemplo a seguir gera C2671:  
  
```  
// C2671.cpp  
struct S {  
   static S* const func() { return this; }  // C2671  
};  
```
