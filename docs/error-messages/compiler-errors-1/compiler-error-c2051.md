---
title: Erro do compilador C2051
ms.date: 11/04/2016
f1_keywords:
- C2051
helpviewer_keywords:
- C2051
ms.assetid: 81c0469a-78e2-49fa-bd76-97cdb135e3ea
ms.openlocfilehash: 51bf9b9bcde7f02210dd0e381f1239507ac56bdb
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74739097"
---
# <a name="compiler-error-c2051"></a>Erro do compilador C2051

expressão Case não constante

As expressões Case devem ser constantes Integer.

O exemplo a seguir gera C2051:

```cpp
// C2051.cpp
class X {};

int main() {
   static X x;
   int i = 0;

   switch (i) {
      case x:   // C2051 use constant expression to resolve error
         break;
      default:
         break;
   }
}
```

Resolução possível:

```cpp
// C2051b.cpp
class X {};

int main() {
   static X x;
   int i = 0;

   switch (i) {
      case 1:
         break;
      default:
         break;
   }
}
```
