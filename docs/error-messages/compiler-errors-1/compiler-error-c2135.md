---
title: Erro do compilador C2135
ms.date: 11/04/2016
f1_keywords:
- C2135
helpviewer_keywords:
- C2135
ms.assetid: aa360d22-4f79-4de1-b384-93cadd10975f
ms.openlocfilehash: 0b6cc8fb8ec1c6a7b054eb48d914335460811310
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50450096"
---
# <a name="compiler-error-c2135"></a>Erro do compilador C2135

'bit operator': operação de campo de bits inválida

O operador address-of (`&`) não pode ser aplicado a um campo de bits.

O exemplo a seguir gera C2135:

```
// C2135.cpp
struct S {
   int i : 1;
};

struct T {
   int j;
};
int main() {
   &S::i;   // C2135 address of a bit field
   &T::j;   // OK
}
```