---
title: Erro do compilador C3737
ms.date: 11/04/2016
f1_keywords:
- C3737
helpviewer_keywords:
- C3737
ms.assetid: ca2aeb23-2491-4ccb-8838-884abf7065c8
ms.openlocfilehash: b6c2a85556e96ff6176e158b7d75a844bb5710d6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50458624"
---
# <a name="compiler-error-c3737"></a>Erro do compilador C3737

'delegate': um delegate não deve possuir uma convenção de chamada explícita

Não é possível especificar o [convenção de chamada](../../cpp/calling-conventions.md) para um `delegate`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3737:

```
// C3737a.cpp
// compile with: /clr
delegate void __stdcall MyFunc();   // C3737
// Try the following line instead.
// delegate void MyFunc();

int main() {
}
```
