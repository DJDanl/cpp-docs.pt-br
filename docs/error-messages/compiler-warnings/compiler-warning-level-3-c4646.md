---
title: Compilador aviso (nível 3) C4646
ms.date: 11/04/2016
f1_keywords:
- C4646
helpviewer_keywords:
- C4646
ms.assetid: 23677e8e-603e-40e0-b99a-2e4894a1278e
ms.openlocfilehash: 03ea8328351a594e04988e3544686d8c5dc1144a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401625"
---
# <a name="compiler-warning-level-3-c4646"></a>Compilador aviso (nível 3) C4646

função declarada com __declspec(noreturn) tem o tipo de retorno não nulo

Uma função marcada com o [noreturn](../../cpp/noreturn.md) `__declspec` modificador deve ter uma [void](../../cpp/void-cpp.md) tipo de retorno.

O exemplo a seguir gera C4646:

```
// C4646.cpp
// compile with: /W3 /WX
int __declspec(noreturn) TestFunction()
{   // C4646  make return type void
}
```