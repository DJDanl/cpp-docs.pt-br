---
title: Erro do compilador C2381
ms.date: 11/04/2016
f1_keywords:
- C2381
helpviewer_keywords:
- C2381
ms.assetid: cc765f67-64ac-406f-93ef-ae7d548d58d7
ms.openlocfilehash: a36655b0b3a28536538998656d7ce354c409d07c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225521"
---
# <a name="compiler-error-c2381"></a>Erro do compilador C2381

' função ': redefinição; __declspec (noreturn) difere

Uma função foi declarada e, em seguida, definida, mas a definição usou o modificador [noreturn](../../cpp/noreturn.md) **`__declspec`** . O uso de `noreturn` constitui uma redefinição da função; a declaração e a definição precisam concordar com o uso de `noreturn` .

O exemplo a seguir gera C2381:

```cpp
// C2381.cpp
// compile with: /c
void f1();
void __declspec(noreturn) f1() {}   // C2381
void __declspec(noreturn) f2() {}   // OK
```
