---
title: Erro do compilador C2469
ms.date: 11/04/2016
f1_keywords:
- C2469
helpviewer_keywords:
- C2469
ms.assetid: 3814bdff-581a-4d3e-8b47-8de6887cea69
ms.openlocfilehash: e9c447451b052841da2ef0c7be582257ee216785
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62303056"
---
# <a name="compiler-error-c2469"></a>Erro do compilador C2469

'operator': não é possível alocar o objeto 'type'

Um operador foi passado um tipo inválido.

O exemplo a seguir gera C2469:

```
// C2469.cpp
int main() {
   int *i = new void;   // C2469
   int *i = new int;   // OK
}
```