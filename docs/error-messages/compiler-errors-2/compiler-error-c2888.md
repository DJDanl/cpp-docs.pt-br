---
title: Erro do compilador C2888
ms.date: 11/04/2016
f1_keywords:
- C2888
helpviewer_keywords:
- C2888
ms.assetid: 244f593e-ff25-4dad-b31f-84dafa3bc84a
ms.openlocfilehash: 93fe37c72a04e8c942f910ed3a631e5ba2a542bc
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760909"
---
# <a name="compiler-error-c2888"></a>Erro do compilador C2888

' identifier ': símbolo não pode ser definido no namespace ' namespace '

Um símbolo que pertence ao namespace A deve ser definido em um namespace que inclui um.

O exemplo a seguir gera C2888:

```cpp
// C2888.cpp
// compile with: /c
namespace M {
   namespace N {
      void f1();
      void f2();
   }

   void N::f1() {}   // OK: namspace M encloses N
}

namespace O {
   void M::N::f2() {}   // C2888 namespace O does not enclose M
}
```
