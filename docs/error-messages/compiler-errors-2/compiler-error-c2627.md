---
title: Erro do compilador C2627
ms.date: 11/04/2016
f1_keywords:
- C2627
helpviewer_keywords:
- C2627
ms.assetid: 7fc6c5ac-c7c9-4f0b-ad52-f52252526458
ms.openlocfilehash: dc976a0c16d19d1fd2340676e43eb71903163aa5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50659050"
---
# <a name="compiler-error-c2627"></a>Erro do compilador C2627

'function': função membro não permitida em union anônima

Uma [união anônima](../../cpp/unions.md#anonymous_unions) não pode ter funções de membro.

O exemplo a seguir gera C2627:

```
// C2627.cpp
int main() {
   union { void f(){} };   // C2627
   union X { void f(){} };
}
```