---
title: Erro do compilador C2052
ms.date: 11/04/2016
f1_keywords:
- C2052
helpviewer_keywords:
- C2052
ms.assetid: 922ca43b-b64b-4ef7-9611-c7313be3fd79
ms.openlocfilehash: a9e891ad60d5eea31a2554320a8c2c584234c435
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74739109"
---
# <a name="compiler-error-c2052"></a>Erro do compilador C2052

' type ': tipo inválido para expressão Case

As expressões Case devem ser constantes Integer.

O exemplo a seguir gera C2052:

```cpp
// C2052.cpp
int main() {
   int index = 0;
   switch (index) {
      case 1:
         return 24;
      case 1.0:   // C2052
      // try the following line instead
      // case 2:
         return 23;
   }
}
```
