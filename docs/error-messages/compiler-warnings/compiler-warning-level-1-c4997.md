---
title: Aviso do compilador (nível 1) C4997
ms.date: 11/04/2016
f1_keywords:
- C4997
helpviewer_keywords:
- C4997
ms.assetid: d39678fd-0c1a-4104-8a45-9e3f20de0407
ms.openlocfilehash: 15f96c6ab65eb5d9728e31e1cc9b31d0bc8aa9b2
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91499667"
---
# <a name="compiler-warning-level-1-c4997"></a>Aviso do compilador (nível 1) C4997

"Class": coclass não implementa uma interface COM ou pseudo-interface

Uma classe marcada com o atributo [coclass](../../windows/attributes/coclass.md) não implementou uma interface.

O exemplo a seguir gera C4997:

```cpp
// C4997.cpp
// compile with: /WX
// to resolve this C4997, uncomment all code
#include <objbase.h>

[ object ]
__interface I {
   HRESULT func();
};

[ coclass ]
struct C /*: I*/ {
   /*
   HRESULT func() {
      return S_OK;
   }
   */
};   // C4997
```
