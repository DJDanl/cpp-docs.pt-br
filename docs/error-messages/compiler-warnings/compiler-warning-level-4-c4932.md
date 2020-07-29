---
title: Aviso do compilador (nível 4) C4932
ms.date: 11/04/2016
f1_keywords:
- C4932
helpviewer_keywords:
- C4932
ms.assetid: 0b8d88cc-21f6-45cb-a9f5-1795b7db0dfa
ms.openlocfilehash: 992e047f31e4a30edd29ba6110bf119d2bc8928b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230591"
---
# <a name="compiler-warning-level-4-c4932"></a>Aviso do compilador (nível 4) C4932

__identifier (identificador) e \_ _identifier (identificador) são indistinguíveis

O compilador não pode distinguir entre **_finally** e **`__finally`** ou `__try` e **_try** como um parâmetro passado para [__identifier](../../extensions/identifier-cpp-cli.md). Você não deve tentar usá-los como identificadores no mesmo programa, pois isso resultará em um erro de [C2374](../../error-messages/compiler-errors-1/compiler-error-c2374.md) .

O exemplo a seguir gera C4932:

```cpp
// C4932.cpp
// compile with: /clr /W4 /WX
int main() {
   int __identifier(_finally) = 245;   // C4932
   int __identifier(__finally) = 25;   // C4932
}
```
