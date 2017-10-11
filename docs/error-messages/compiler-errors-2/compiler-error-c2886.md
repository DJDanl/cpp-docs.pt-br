---
title: C2886 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2886
dev_langs:
- C++
helpviewer_keywords:
- C2886
ms.assetid: c01588a1-484c-4dc9-a3f1-f900c6e44543
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: cbb4ab1d50a4a6c5bb9ea3c392febf786197e0fa
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2886"></a>C2886 de erro do compilador
'class::identifier': símbolo não pode ser usado em uma declaração de using membro  
  
 Um `using` declaração usa um símbolo, como um nome de namespace. Um `using` declaração é para declarar membros de classe base.  
  
 O exemplo a seguir gera C2886:  
  
```  
// C2886.cpp  
// compile with: /c  
namespace Z {  
    int i;  
}  
  
class B {  
protected:  
    int i;  
};  
  
class D : public B {  
    // Error: Z is a namespace  
    using Z::i;   // C2886  
  
    // OK: B is a base class  
    using B::i;  
};  
```
