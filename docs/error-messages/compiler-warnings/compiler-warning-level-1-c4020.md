---
title: Aviso do compilador (nível 1) C4020
ms.date: 11/04/2016
f1_keywords:
- C4020
helpviewer_keywords:
- C4020
ms.assetid: 8c4cd6be-9371-4c8c-b0ff-a5ad367bbab0
ms.openlocfilehash: 2136e94a261b2f767165e43acfd66583e8d15e9f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164580"
---
# <a name="compiler-warning-level-1-c4020"></a>Aviso do compilador (nível 1) C4020

' function ': muitos parâmetros reais

O número de parâmetros reais em uma chamada de função excede o número de parâmetros formais no protótipo de função ou definição. O compilador passa os parâmetros reais extras de acordo com a Convenção de chamada da função.

O exemplo a seguir gera C4020:

```c
// C4020.c
// compile with: /W1 /c
void f(int);
int main() {
   f(1,2);   // C4020
}
```

Resolução possível:

```c
// C4020b.c
// compile with: /c
void f(int);
int main() {
   f(1);
}
```
