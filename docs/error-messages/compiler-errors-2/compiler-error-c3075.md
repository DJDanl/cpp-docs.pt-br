---
title: C3075 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3075
dev_langs:
- C++
helpviewer_keywords:
- C3075
ms.assetid: f431daa9-e0fa-48f0-a5c3-f99be96b55e3
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 8197297ffd2f75afede3876577f249d3e07c6abb
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3075"></a>C3075 de erro do compilador
'instance': não é possível inserir uma instância de um tipo de referência, 'type' em um tipo de valor  
  
 Um tipo de valor não pode conter uma instância de um tipo de referência.  
  
 Para obter mais informações, consulte [semântica de pilha C++ para tipos de referência](../../dotnet/cpp-stack-semantics-for-reference-types.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3075.  
  
```  
// C3075.cpp  
// compile with: /clr /c  
ref struct U {};  
value struct X {  
   U y;   // C3075  
};  
  
ref struct Y {  
   U y;   // OK  
};  
```
