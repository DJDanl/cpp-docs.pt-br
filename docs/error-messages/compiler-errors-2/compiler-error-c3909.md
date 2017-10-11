---
title: C3909 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3909
dev_langs:
- C++
helpviewer_keywords:
- C3909
ms.assetid: 0a443132-e53f-42dc-a58b-f086da3e7bfd
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 5cb5929fe1619ce75a7bde15ac08955247f1af7a
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3909"></a>C3909 de erro do compilador
aWinRT ou declaração de evento gerenciado deve ocorrer em um WinRT ou tipo gerenciado  
  
 Um evento de tempo de execução do Windows ou gerenciado foi declarado em um tipo nativo. Para corrigir esse erro, declare eventos em tipos de tempo de execução do Windows ou tipos gerenciados.  
  
 Para obter mais informações, consulte [evento](../../windows/event-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C3909 e mostra como corrigi-lo:  
  
```  
// C3909.cpp  
// compile with: /clr /c  
delegate void H();  
class X {  
   event H^ E;   // C3909 - use ref class X instead  
};  
  
ref class Y {  
   static event H^ E {  
      void add(H^) {}  
      void remove( H^ h ) {}  
      void raise( ) {}  
   }  
};  
```
