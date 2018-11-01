---
title: Erro do compilador C2180
ms.date: 11/04/2016
f1_keywords:
- C2180
helpviewer_keywords:
- C2180
ms.assetid: ea71b39e-b977-48a7-b7bd-af68ef5e263b
ms.openlocfilehash: 16fcf15eb29743f74bbf2edcb1016f2e15228e5a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50553304"
---
# <a name="compiler-error-c2180"></a>Erro do compilador C2180

expressão de controle possui tipo 'type'

A expressão de controle em uma `if`, `while`, `for`, ou `do` instrução é uma expressão convertida em `void`. Para corrigir esse problema, altere a expressão de controle para um que produz um `bool` ou um tipo que pode ser convertido em `bool`.

O exemplo a seguir gera C2180:

```
// C2180.c

int main() {
   while ((void)1)   // C2180
      return 1;
   while (1)         // OK
      return 0;
}
```