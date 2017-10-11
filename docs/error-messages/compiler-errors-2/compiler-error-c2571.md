---
title: C2571 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2571
dev_langs:
- C++
helpviewer_keywords:
- C2571
ms.assetid: c6522616-dee9-4d7d-9bf8-30a7e1deaadf
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 8bfb4f9af849efea2fa3aa8a84a57f1cfb4cd502
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2571"></a>C2571 de erro do compilador
'function': função virtual não pode estar em union 'union'  
  
 Uma união é declarada com uma função virtual. Você pode declarar uma função virtual somente em uma classe ou estrutura.  Possíveis resoluções:  
  
1.  Altere a união de uma classe ou estrutura.  
  
2.  Torna a função não virtual.  
  
 O exemplo a seguir gera C2571:  
  
```  
// C2571.cpp  
// compile with: /c  
union A {  
   virtual void func1();   // C2571  
   void func2();   // OK  
};  
```
