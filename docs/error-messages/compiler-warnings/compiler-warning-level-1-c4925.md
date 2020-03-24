---
title: Aviso do compilador (nível 1) C4925
ms.date: 11/04/2016
f1_keywords:
- C4925
helpviewer_keywords:
- C4925
ms.assetid: a4b206c0-016a-4f28-873a-bb8bb41bad50
ms.openlocfilehash: defd60d02a8725b114b3901f8d70af87e27445c4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174629"
---
# <a name="compiler-warning-level-1-c4925"></a>Aviso do compilador (nível 1) C4925

' method ': método de dispinterface não pode ser chamado a partir de script

As linguagens de script não podem criar um VT_BYREF parâmetro ' in ', ele só pode criar VT_BYREF parâmetros ' out '.

Outra maneira de resolver esse aviso não torna o parâmetro (na definição e implementação) um tipo de ponteiro.

O exemplo a seguir gera C4925:

```cpp
// C4925.cpp
// compile with: /LD /W1
#define _ATL_ATTRIBUTES 1
#include <atlbase.h>
#include <atlcom.h>
[ module(name="Test")];

[ dispinterface, uuid("00000000-0000-0000-0000-000000000001") ]
__interface IDisp {
   [id(9)] void f([in] int*);
};

[ coclass, uuid("00000000-0000-0000-0000-000000000002")  ]
struct CDisp : IDisp {   // C4925
   void f(int*) {}
};
```
