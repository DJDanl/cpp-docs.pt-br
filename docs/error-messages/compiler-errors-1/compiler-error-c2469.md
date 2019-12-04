---
title: Erro do compilador C2469
ms.date: 11/04/2016
f1_keywords:
- C2469
helpviewer_keywords:
- C2469
ms.assetid: 3814bdff-581a-4d3e-8b47-8de6887cea69
ms.openlocfilehash: eafb3ed3a26fe127b39558542b6d415be65cefb7
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74743751"
---
# <a name="compiler-error-c2469"></a>Erro do compilador C2469

' operator ': não é possível alocar objeto ' type '

Um operador recebeu um tipo inválido.

O exemplo a seguir gera C2469:

```cpp
// C2469.cpp
int main() {
   int *i = new void;   // C2469
   int *i = new int;   // OK
}
```
