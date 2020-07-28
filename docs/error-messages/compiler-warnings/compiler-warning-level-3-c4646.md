---
title: Aviso do compilador (nível 3) C4646
ms.date: 11/04/2016
f1_keywords:
- C4646
helpviewer_keywords:
- C4646
ms.assetid: 23677e8e-603e-40e0-b99a-2e4894a1278e
ms.openlocfilehash: 3bbb9214a67284876c55e04485cea796cf9dbc29
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214419"
---
# <a name="compiler-warning-level-3-c4646"></a>Aviso do compilador (nível 3) C4646

função declarada com __declspec (noreturn) tem tipo de retorno não void

Uma função marcada com o modificador [noreturn](../../cpp/noreturn.md) **`__declspec`** deve ter um tipo de retorno [void](../../cpp/void-cpp.md) .

O exemplo a seguir gera C4646:

```cpp
// C4646.cpp
// compile with: /W3 /WX
int __declspec(noreturn) TestFunction()
{   // C4646  make return type void
}
```
