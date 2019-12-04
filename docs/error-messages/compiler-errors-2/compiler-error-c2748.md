---
title: Erro do compilador C2748
ms.date: 11/04/2016
f1_keywords:
- C2748
helpviewer_keywords:
- C2748
ms.assetid: b63ac78b-a200-499c-afea-15af1a1e819e
ms.openlocfilehash: e43defbf28c76dadcc7921ca76778413c41490a6
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759627"
---
# <a name="compiler-error-c2748"></a>Erro do compilador C2748

a criação da matriz gerenciada ou do WinRT deve ter o tamanho da matriz ou inicializador de matriz

Uma matriz gerenciada ou WinRT estava mal formada. Para obter mais informações, consulte [matriz](../../extensions/arrays-cpp-component-extensions.md).

O exemplo a seguir gera C2748 e mostra como corrigi-lo:

```cpp
// C2748.cpp
// compile with: /clr
int main() {
   array<int> ^p1 = new array<int>();   // C2748
   // try the following line instead
   array<int> ^p2 = new array<int>(2);
}
```
