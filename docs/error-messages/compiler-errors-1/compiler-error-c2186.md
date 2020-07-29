---
title: Erro do compilador C2186
ms.date: 11/04/2016
f1_keywords:
- C2186
helpviewer_keywords:
- C2186
ms.assetid: 284bfb7e-ab85-4fcb-9864-1ddf7f6c94ae
ms.openlocfilehash: a11b6b7aad4469c7151648a5f092265a4cb9d504
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87209793"
---
# <a name="compiler-error-c2186"></a>Erro do compilador C2186

' operator ': operando inválido do tipo ' void '

O operador tem um **`void`** operando.

O exemplo a seguir gera C2186:

```cpp
// C2186.cpp
// compile with: /c
void func1( void );
int  func2( void );
int i = 2 + func1();   // C2186 func1() is type void
int j = 2 + func2();   // OK both operands are type int
```
