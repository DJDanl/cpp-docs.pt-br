---
title: Erro do compilador C2495
ms.date: 11/04/2016
f1_keywords:
- C2495
helpviewer_keywords:
- C2495
ms.assetid: bb7066fe-3549-4901-97e4-157f3c04dd57
ms.openlocfilehash: 5e16404e8c23a902a2cdbfc436cecdff21e68b6a
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757014"
---
# <a name="compiler-error-c2495"></a>Erro do compilador C2495

"Identifier": "nothrow" só pode ser aplicado a declarações ou definições de função

O atributo estendido [nothrow](../../cpp/nothrow-cpp.md) pode ser aplicado somente a declarações de função ou definições.

O exemplo a seguir gera C2495:

```cpp
// C2495.cpp
// compile with: /c
__declspec(nothrow) class X {   // C2495
   int m_data;
} x;

__declspec(nothrow) void test();   // OK
```
