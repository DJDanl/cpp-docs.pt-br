---
title: Erro do compilador C2332
ms.date: 11/04/2016
f1_keywords:
- C2332
helpviewer_keywords:
- C2332
ms.assetid: fb05cd68-e271-4bea-9fb7-ef4edb0a26ac
ms.openlocfilehash: 74b0045b70a68e182025976f84f8a709c3a30064
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74747755"
---
# <a name="compiler-error-c2332"></a>Erro do compilador C2332

' typedef ': nome de marca ausente

O compilador encontrou uma definição de tipo incompleta.

O exemplo a seguir gera C2332:

```cpp
// C2332.cpp
// compile with: /c
struct S {
   int i;
};

typedef struct * pS;   // C2332
typedef struct S* pS;   // OK

int get_S_i(pS p) {
   return p->i;
}
```
