---
title: Erro do compilador C2739
ms.date: 11/04/2016
f1_keywords:
- C2739
helpviewer_keywords:
- C2739
ms.assetid: 5b63e435-7631-43d7-805e-f2adefb7e517
ms.openlocfilehash: 18cece8d9630aa93e867329acc7cefea30da3286
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759653"
---
# <a name="compiler-error-c2739"></a>Erro do compilador C2739

' Number ': dimensões de matriz gerenciadas explícitas ou de WinRT devem estar entre 1 e 32

Uma dimensão de matriz não estava entre 1 e 32.

O exemplo a seguir gera C2739 e mostra como corrigi-lo:

```cpp
// C2739.cpp
// compile with: /clr
int main() {
   array<int, -1>^a;   // C2739
   // try the following line instead
   // array<int, 2>^a;
}
```
