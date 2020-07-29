---
title: Erro do compilador C2581
ms.date: 11/04/2016
f1_keywords:
- C2581
helpviewer_keywords:
- C2581
ms.assetid: 24a4e4c1-24d3-4e42-b760-7dcaf9740b16
ms.openlocfilehash: a632d6a47afb29b8bb46761c3188391905eda842
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87206868"
---
# <a name="compiler-error-c2581"></a>Erro do compilador C2581

' type ': função static ' operator = ' é inválida

O operador de atribuição ( `=` ) está declarado incorretamente como **`static`** . Os operadores de atribuição não podem ser **`static`** . Para obter mais informações, consulte [operadores definidos pelo usuário (C++/CLI)](../../dotnet/user-defined-operators-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2581.

```cpp
// C2581.cpp
// compile with: /clr /c
ref struct Y {
   static Y ^ operator = (Y^ me, int i);   // C2581
   Y^ operator =(int i);   // OK
};
```
