---
title: Compilador aviso (nível 4) C4932
ms.date: 11/04/2016
f1_keywords:
- C4932
helpviewer_keywords:
- C4932
ms.assetid: 0b8d88cc-21f6-45cb-a9f5-1795b7db0dfa
ms.openlocfilehash: cd37ee67545918991b286d16d0fe27b47414b3c3
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58769817"
---
# <a name="compiler-warning-level-4-c4932"></a>Compilador aviso (nível 4) C4932

__identifier(Identifier) e \__identifier(identifier) são indistinguíveis

O compilador é capaz de distinguir **_finally** e `__finally` ou `__try` e **_try** como um parâmetro passado para [Identifier](../../extensions/identifier-cpp-cli.md). Você não deve tentar usar ambos como identificadores no mesmo programa, pois isso resultará em uma [C2374](../../error-messages/compiler-errors-1/compiler-error-c2374.md) erro.

O exemplo a seguir gera C4932:

```
// C4932.cpp
// compile with: /clr /W4 /WX
int main() {
   int __identifier(_finally) = 245;   // C4932
   int __identifier(__finally) = 25;   // C4932
}
```