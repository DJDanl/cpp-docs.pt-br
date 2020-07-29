---
title: Aviso do compilador (nível 3) C4645
ms.date: 11/04/2016
f1_keywords:
- C4645
helpviewer_keywords:
- C4645
ms.assetid: fd7c1ddf-f0d0-4e10-bab9-ccb4c3476298
ms.openlocfilehash: 607122b5592c9db4fc2ad4cabf369b4605b2673b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228759"
---
# <a name="compiler-warning-level-3-c4645"></a>Aviso do compilador (nível 3) C4645

função declarada com __declspec (noreturn) tem uma instrução return

Uma instrução de [retorno](../../cpp/return-statement-in-program-termination-cpp.md) foi encontrada em uma função que está marcada com o modificador [noreturn](../../cpp/noreturn.md) **`__declspec`** . A **`return`** instrução foi ignorada.

O exemplo a seguir gera C4645:

```cpp
// C4645.cpp
// compile with:  /W3
void __declspec(noreturn) func() {
   return;   // C4645, delete this line to resolve
}

int main() {
}
```
