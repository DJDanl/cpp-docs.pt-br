---
title: C2881 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2881
dev_langs:
- C++
helpviewer_keywords:
- C2881
ms.assetid: b49c63c2-b064-4d4b-a75e-ddd2af947522
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 96e406dea9a320ec42b0f49a41ef5e531767e82e
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2881"></a>C2881 de erro do compilador
'namespace1': já é usado como um alias para 'namespace2'  
  
 Você não pode usar o mesmo nome como um alias de dois namespaces.  
  
 O exemplo a seguir gera C2881:  
  
```  
// C2881.cpp  
// compile with: /c  
namespace A {  
   int k;  
}  
  
namespace B {  
   int i;  
}  
  
namespace C = A;  
namespace C = B;   // C2881 C is already an alias for A  
```
