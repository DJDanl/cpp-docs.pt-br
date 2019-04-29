---
title: Erro do compilador C2381
ms.date: 11/04/2016
f1_keywords:
- C2381
helpviewer_keywords:
- C2381
ms.assetid: cc765f67-64ac-406f-93ef-ae7d548d58d7
ms.openlocfilehash: b29f7dac6c6d71e12eb0f003cdfc151dd2c349a7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62347893"
---
# <a name="compiler-error-c2381"></a>Erro do compilador C2381

'function': redefinição; difere de __declspec(noreturn)

Uma função foi declarada e, em seguida, definida, mas a definição usada a [noreturn](../../cpp/noreturn.md) `__declspec` modificador. O uso de `noreturn` constitui uma redefinição da função; a declaração e a definição precisam concordar sobre o uso de `noreturn`.

O exemplo a seguir gera C2381:

```
// C2381.cpp
// compile with: /c
void f1();
void __declspec(noreturn) f1() {}   // C2381
void __declspec(noreturn) f2() {}   // OK
```