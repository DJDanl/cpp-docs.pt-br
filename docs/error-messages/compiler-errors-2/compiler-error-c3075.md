---
title: C3075 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
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
ms.workload:
- cplusplus
ms.openlocfilehash: b424aa4a3804d1bfe20497dfb65185e0688352d4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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