---
title: C3919 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3919
dev_langs:
- C++
helpviewer_keywords:
- C3919
ms.assetid: 5f8eddda-d751-478b-930d-e18f7191ddfb
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 26e3b3fed712c1d738d214ab5f12c9572bab7206
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3919"></a>C3919 de erro do compilador
'event_method': função deve ter o tipo 'type'  
  
 Um método de acessador de evento não foi declarado corretamente.  
  
 Para obter mais informações sobre eventos, consulte [evento](../../windows/event-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C3919:  
  
```  
// C3919.cpp  
// compile with: /clr /c  
using namespace System;  
delegate void D(String^);  
ref class R {  
   event D^ e {  
      int add(int);   // C3919  
      int remove(int);   // C3919  
  
      void add(D^);   // OK  
      void remove(D^);   // OK  
   }  
};  
```
