---
title: Erro do compilador C2381
ms.date: 11/04/2016
f1_keywords:
- C2381
helpviewer_keywords:
- C2381
ms.assetid: cc765f67-64ac-406f-93ef-ae7d548d58d7
ms.openlocfilehash: 834b9939a99c694c702bb268b928575b4beb8856
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74745389"
---
# <a name="compiler-error-c2381"></a>Erro do compilador C2381

' função ': redefinição; __declspec (noreturn) difere

Uma função foi declarada e, em seguida, definida, mas a definição usou o modificador de `__declspec` [noreturn](../../cpp/noreturn.md) . O uso de `noreturn` constitui uma redefinição da função; a declaração e a definição precisam concordar com o uso de `noreturn`.

O exemplo a seguir gera C2381:

```cpp
// C2381.cpp
// compile with: /c
void f1();
void __declspec(noreturn) f1() {}   // C2381
void __declspec(noreturn) f2() {}   // OK
```
