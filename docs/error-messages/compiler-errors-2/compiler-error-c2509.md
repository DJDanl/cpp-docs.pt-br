---
title: Erro do compilador C2509
ms.date: 11/04/2016
f1_keywords:
- C2509
helpviewer_keywords:
- C2509
ms.assetid: 339c1fcd-ec4a-456c-9f18-a9b24d9921af
ms.openlocfilehash: f0322c1d6f80f26b81ac0e93b944a2f3277026ce
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74746806"
---
# <a name="compiler-error-c2509"></a>Erro do compilador C2509

' identifier ': função membro não declarada em ' class '

A função não está declarada na classe especificada.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2509.

```cpp
// C2509.cpp
// compile with: /c
struct A {
   virtual int vfunc() = 0;
   virtual int vfunc2() = 0;
};

struct B : private A {
   using A::vfunc;
   virtual int vfunc2();
};

int B::vfunc() { return 1; }   // C2509
int B::vfunc2() { return 1; }   // OK
```
