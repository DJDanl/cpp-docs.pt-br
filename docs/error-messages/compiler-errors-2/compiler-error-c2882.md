---
title: Erro do compilador C2882
ms.date: 11/04/2016
f1_keywords:
- C2882
helpviewer_keywords:
- C2882
ms.assetid: 617018ee-5a0d-4b8d-9612-77e8ae52679b
ms.openlocfilehash: e5fd20695f6922ba5832abb1042cce63b7c4f5a2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50598492"
---
# <a name="compiler-error-c2882"></a>Erro do compilador C2882

'name': uso inválido de identificador de namespace na expressão

Você tentou usar o nome de um namespace em uma expressão.

O exemplo a seguir gera C2882:

```
// C2882.cpp
// compile with: /c
namespace A {
   int k;
}

int i = A;   // C2882, can't assign A to i
```