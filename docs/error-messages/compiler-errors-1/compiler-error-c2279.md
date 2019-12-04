---
title: Erro do compilador C2279
ms.date: 11/04/2016
f1_keywords:
- C2279
helpviewer_keywords:
- C2279
ms.assetid: 1b5c88ef-2336-49b8-9ddb-d61f97c73e14
ms.openlocfilehash: b3b37788d6e4727761ab993f0502746edace18e9
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759172"
---
# <a name="compiler-error-c2279"></a>Erro do compilador C2279

especificação de exceção não pode aparecer em uma declaração de typedef

Em **/za**, as [especificações de exceção](../../cpp/exception-specifications-throw-cpp.md) não são permitidas em uma declaração de typedef.

O exemplo a seguir gera C2279:

```cpp
// C2279.cpp
// compile with: /Za /c
typedef int (*xy)() throw(...);   // C2279
typedef int (*xyz)();   // OK
```
