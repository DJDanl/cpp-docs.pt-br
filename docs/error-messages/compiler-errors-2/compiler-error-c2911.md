---
title: C2911 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2911
dev_langs:
- C++
helpviewer_keywords:
- C2911
ms.assetid: 83c7c01a-ab6a-4179-9fb0-289a9ec8d44e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 182d9ec130df7c5b8776d4dce0f185cb6b05ed59
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2911"></a>C2911 de erro do compilador
'member': não pode ser declarado ou definido no escopo atual  
  
 Dentro de um namespace, classe ou função, você pode definir somente um membro do mesmo namespace, classe ou função ou um membro que é colocado entre o mesmo namespace, classe ou função.  
  
 O exemplo a seguir gera C2911:  
  
```  
// C2911.cpp  
struct A;  
  
namespace M {  
   struct D;  
}  
  
namespace N {  
   struct C;  
  
   namespace O {  
      struct B;  
   }  
  
   // in N  
   struct ::A {};   // C2911  A is member of global NS  
   struct O::B{};   // OK B is in O, O is inside of N  
   struct C {};     // OK C is member of N  
   struct M::D {};  // C2911 D is member of M, M not enclosed by N  
}  
```