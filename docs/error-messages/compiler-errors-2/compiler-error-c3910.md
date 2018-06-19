---
title: C3910 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3910
dev_langs:
- C++
helpviewer_keywords:
- C3910
ms.assetid: cfcbe620-b463-463b-95ea-2d60ad33ebb5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 72b18f5c22e957c18b28de3a130f09427e623829
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33269238"
---
# <a name="compiler-error-c3910"></a>C3910 de erro do compilador
'event': deve definir o método' member'  
  
 Um evento foi definido, mas não continha o método de acessador especificado, é necessário.  
  
 Para obter mais informações, consulte [evento](../../windows/event-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C3910:  
  
```  
// C3910.cpp  
// compile with: /clr /c  
delegate void H();  
ref class X {  
   event H^ E {  
      // uncomment the following lines  
      // void add(H^) {}  
      // void remove( H^ h ) {}  
      // void raise( ) {}  
   };   // C3910  
  
   event H^ E2; // OK data member  
};  
```