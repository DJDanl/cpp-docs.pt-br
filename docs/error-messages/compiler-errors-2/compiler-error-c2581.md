---
title: Erro do compilador C2581
ms.date: 11/04/2016
f1_keywords:
- C2581
helpviewer_keywords:
- C2581
ms.assetid: 24a4e4c1-24d3-4e42-b760-7dcaf9740b16
ms.openlocfilehash: 03fc7e9da8a9b3a2e2c445f5b06395c2616f0d98
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755428"
---
# <a name="compiler-error-c2581"></a>Erro do compilador C2581

' type ': função static ' operator = ' é inválida

O operador de atribuição (`=`) está declarado incorretamente como `static`. Os operadores de atribuição não podem ser `static`. Para obter mais informações, consulte [operadores definidos pelo usuárioC++(/CLI)](../../dotnet/user-defined-operators-cpp-cli.md).

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
