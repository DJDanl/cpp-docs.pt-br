---
title: Erro do compilador C3737
ms.date: 11/04/2016
f1_keywords:
- C3737
helpviewer_keywords:
- C3737
ms.assetid: ca2aeb23-2491-4ccb-8838-884abf7065c8
ms.openlocfilehash: 6b61904fac09145ba749138a730603fcfdbb862d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223376"
---
# <a name="compiler-error-c3737"></a>Erro do compilador C3737

' delegate ': um delegado não pode ter uma Convenção de chamada explícita

Você não pode especificar a [Convenção de chamada](../../cpp/calling-conventions.md) para um **`delegate`** .

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3737:

```cpp
// C3737a.cpp
// compile with: /clr
delegate void __stdcall MyFunc();   // C3737
// Try the following line instead.
// delegate void MyFunc();

int main() {
}
```
