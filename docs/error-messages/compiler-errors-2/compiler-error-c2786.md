---
title: Erro do compilador C2786
ms.date: 11/04/2016
f1_keywords:
- C2786
helpviewer_keywords:
- C2786
ms.assetid: 6676d8c0-86dd-4a39-bdda-b75a35f4d137
ms.openlocfilehash: ba5d05e9c7cc702509144fb876a1301bfc8bf3d4
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74739604"
---
# <a name="compiler-error-c2786"></a>Erro do compilador C2786

' type ': operando inválido para __uuidof

O operador [__uuidof](../../cpp/uuidof-operator.md) usa um tipo definido pelo usuário com um GUID anexado ou um objeto desse tipo definido pelo usuário.  Possíveis causas:

1. O argumento não é um tipo definido pelo usuário.

1. `__uuidof` não pode extrair o GUID do argumento.

O exemplo a seguir gera C2786:

```cpp
// C2786.cpp
struct __declspec(uuid("00000000-0000-0000-0000-000000000000")) A {};

int main() {
   __uuidof(int);   // C2786
   __uuidof(int *);   // C2786
   __uuidof(A **);   // C2786

   // no error
   __uuidof(A);
   __uuidof(A *);
   __uuidof(A &);
   __uuidof(A[]);

   int i;
   int *pi;
   A **ppa;

   __uuidof(i);      // C2786
   __uuidof(pi);     // C2786
   __uuidof(ppa);    // C2786
}
```
