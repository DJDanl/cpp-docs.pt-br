---
title: Aviso do compilador (nível 3) C4645
ms.date: 11/04/2016
f1_keywords:
- C4645
helpviewer_keywords:
- C4645
ms.assetid: fd7c1ddf-f0d0-4e10-bab9-ccb4c3476298
ms.openlocfilehash: 246eed6592b892c3bd233d9217e26e7bf7a49ff8
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502303"
---
# <a name="compiler-warning-level-3-c4645"></a>Aviso do compilador (nível 3) C4645

função declarada com __declspec (noreturn) tem uma instrução return

Uma instrução de [retorno](../../cpp/program-termination.md) foi encontrada em uma função que está marcada com o modificador [noreturn](../../cpp/noreturn.md) **`__declspec`** . A **`return`** instrução foi ignorada.

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
