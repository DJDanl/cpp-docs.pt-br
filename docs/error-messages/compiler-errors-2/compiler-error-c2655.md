---
title: Erro do compilador C2655
ms.date: 11/04/2016
f1_keywords:
- C2655
helpviewer_keywords:
- C2655
ms.assetid: beaefa6e-51b3-4df9-9150-960f3fbf40e0
ms.openlocfilehash: 094dabb5ad07796194ae391000ca1e9025602d93
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50506763"
---
# <a name="compiler-error-c2655"></a>Erro do compilador C2655

'identifier': definição ou redeclaração inválida no escopo atual

Um identificador pode ser declarado novamente somente no escopo global.

O exemplo a seguir gera C2655:

```
// C2655.cpp
class A {};
class B {
public:
   static int i;
};

int B::i;  // OK

int main() {
   A B::i;  // C2655
}
```