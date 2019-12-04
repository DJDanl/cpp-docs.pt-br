---
title: Erro do compilador C2227
ms.date: 11/04/2016
f1_keywords:
- C2227
helpviewer_keywords:
- C2227
ms.assetid: d470e8b8-7e15-468b-84fa-37d1a0132271
ms.openlocfilehash: affc500208644cebbef1da93a0eafabd4aeaa094
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759289"
---
# <a name="compiler-error-c2227"></a>Erro do compilador C2227

esquerda de '-> membro ' deve apontar para tipo de classe/struct/Union/Generic

O operando à esquerda de `->` não é um ponteiro para uma classe, estrutura ou União.

O exemplo a seguir gera C2227:

```cpp
// C2227.cpp
int *pInt;
struct S {
public:
    int member;
} s, *pS = &s;

int main() {
   pInt->member = 0;   // C2227 pInt points to an int
   pS->member = 0;   // OK
}
```
