---
title: Erro do compilador C2879
ms.date: 11/04/2016
f1_keywords:
- C2879
helpviewer_keywords:
- C2879
ms.assetid: ac92b645-2394-49de-8632-43d44e0553ed
ms.openlocfilehash: 9ac8f5e5edb1a6ed7314c5b5d125fcc9bfbe67de
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50677949"
---
# <a name="compiler-error-c2879"></a>Erro do compilador C2879

'symbol': apenas um namespace existente pode ser dado um nome alternativo por uma definição de alias de namespace

Não é possível criar uma [alias de namespace](../../cpp/namespaces-cpp.md#namespace_aliases) a um símbolo que não seja um namespace.

O exemplo a seguir gera C2879:

```
// C2879.cpp
int main() {
   int i;
   namespace A = i;   // C2879 i is not a namespace
}
```