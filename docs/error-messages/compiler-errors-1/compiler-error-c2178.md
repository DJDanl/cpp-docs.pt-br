---
title: C2178 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 05/08/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2178
dev_langs:
- C++
helpviewer_keywords:
- C2178
ms.assetid: 79a14158-17f3-4221-bd06-9d675c49cef4
caps.latest.revision: 0
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: facb255b0c53a3de0e1d5c9f90de5835b25e3c32
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2178"></a>C2178 de erro do compilador  
  
'*identificador*'não pode ser declarado com'*especificador*' especificador  
  
Um `mutable` especificador foi usado em uma declaração, mas o especificador não é permitido neste contexto.  
  
O `mutable` especificador pode ser aplicado somente aos nomes de membros de dados de classe e não pode ser aplicado para nomes declarados `const` ou `static`e não pode ser aplicado para fazer referência a membros.  
  
## <a name="example"></a>Exemplo  
  
O exemplo a seguir mostra como C2178 podem ocorrer e como corrigi-lo.  
  
```  
// C2178.cpp
// compile with: cl /c /W4 C2178.cpp

class S {
    mutable const int i; // C2178
    // To fix, declare either const or mutable, not both.
};

mutable int x = 4; // C2178
// To fix, remove mutable keyword
```  

