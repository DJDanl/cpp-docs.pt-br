---
title: C2178 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 05/08/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2178
dev_langs:
- C++
helpviewer_keywords:
- C2178
ms.assetid: 79a14158-17f3-4221-bd06-9d675c49cef4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3727a66554b2e128061820df160c02a1370ebb74
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33171289"
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
