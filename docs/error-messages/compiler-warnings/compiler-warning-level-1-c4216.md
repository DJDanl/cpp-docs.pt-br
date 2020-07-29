---
title: Aviso do compilador (nível 1) C4216
ms.date: 11/04/2016
f1_keywords:
- C4216
helpviewer_keywords:
- C4216
ms.assetid: 211079dc-59d0-42a7-801c-2ddab21d7232
ms.openlocfilehash: b7fc44fd15f761c19ed28402a41b3bd3619b21a0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223259"
---
# <a name="compiler-warning-level-1-c4216"></a>Aviso do compilador (nível 1) C4216

extensão não padrão usada: float Long

As extensões padrão da Microsoft (/Ze) tratam **float Long** as **`double`** . A compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)) não. Use **`double`** para manter a compatibilidade. O exemplo a seguir gera C4216:

```cpp
// C4216.cpp
// compile with: /W1
float long a;   // C4216

// use the line below to resolve the warning
// double a;

int main() {
}
```
