---
title: Erro do compilador C2101
ms.date: 11/04/2016
f1_keywords:
- C2101
helpviewer_keywords:
- C2101
ms.assetid: 42f0136f-8cc1-4f2b-be1c-721ec9278e66
ms.openlocfilehash: 8bea258bd3e20cba1dbfabdd3a669a44414b89f8
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74752334"
---
# <a name="compiler-error-c2101"></a>Erro do compilador C2101

' & ' na constante

O operador address-of (`&`) deve ter um l-Value como operando.

O exemplo a seguir gera C2101:

```cpp
// C2101.cpp
int main() {
   char test;
   test = &'a';   // C2101
   test = 'a';   // OK
}
```
