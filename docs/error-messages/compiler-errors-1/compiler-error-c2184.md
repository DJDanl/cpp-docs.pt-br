---
title: Erro do compilador C2184
ms.date: 11/04/2016
f1_keywords:
- C2184
helpviewer_keywords:
- C2184
ms.assetid: 80fc8bff-7d76-4bde-94d2-01d84bb6824a
ms.openlocfilehash: 146035134cc159b9e4271ce10c94f196098581b8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385830"
---
# <a name="compiler-error-c2184"></a>Erro do compilador C2184

'type': tipo inválido para EXCEPT expressão, deve ser integral

Um tipo que foi usado em uma [EXCEPT](../../c-language/try-except-statement-c.md) instrução, mas o tipo não é permitido.

O exemplo a seguir gera C2184:

```
// C2184.cpp
void f() {
   int * p;
   __try{}
   __except(p){};   // C2184
}
```

Solução possível:

```
// C2184b.cpp
// compile with: /c
void f() {
   int i = 0;
   __try{}
   __except(i){};
}
```