---
title: Aviso do compilador (nível 4) C4932
description: Descreve o C4932 de aviso do compilador C/C++ da Microsoft.
ms.date: 08/25/2020
f1_keywords:
- C4932
helpviewer_keywords:
- C4932
ms.assetid: 0b8d88cc-21f6-45cb-a9f5-1795b7db0dfa
ms.openlocfilehash: ece2ae14fd8e1198a97f5e772fcce52c47464878
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898288"
---
# <a name="compiler-warning-level-4-c4932"></a>Aviso do compilador (nível 4) C4932

> `__identifier(identifier_1)` e `__identifier(identifier_2)` são indistinguíveis

O compilador não pode distinguir entre **`_finally`** e **`__finally`** ou **`__try`** e **`_try`** como um parâmetro passado para [`__identifier`](../../extensions/identifier-cpp-cli.md) . Você não deve tentar usá-los como identificadores no mesmo programa, pois isso resultará em um erro de [C2374](../../error-messages/compiler-errors-1/compiler-error-c2374.md) .

O exemplo a seguir gera C4932:

```cpp
// C4932.cpp
// compile with: /clr /W4 /WX
int main() {
   int __identifier(_finally) = 245;   // C4932
   int __identifier(__finally) = 25;   // C4932
}
```
