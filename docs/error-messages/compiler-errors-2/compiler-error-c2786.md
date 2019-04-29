---
title: Erro do compilador C2786
ms.date: 11/04/2016
f1_keywords:
- C2786
helpviewer_keywords:
- C2786
ms.assetid: 6676d8c0-86dd-4a39-bdda-b75a35f4d137
ms.openlocfilehash: b03155ad1a209ae59327dd31d432f5623f380ac9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62265991"
---
# <a name="compiler-error-c2786"></a>Erro do compilador C2786

'type': operando inválido para uuidof

O [uuidof](../../cpp/uuidof-operator.md) operador usa um tipo definido pelo usuário com um GUID anexado ou um objeto desse tipo definido pelo usuário.  Possíveis causas:

1. O argumento não é um tipo definido pelo usuário.

1. `__uuidof` não é possível extrair o GUID do argumento.

O exemplo a seguir gera C2786:

```
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