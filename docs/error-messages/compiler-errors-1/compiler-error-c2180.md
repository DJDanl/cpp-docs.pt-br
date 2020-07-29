---
title: Erro do compilador C2180
ms.date: 11/04/2016
f1_keywords:
- C2180
helpviewer_keywords:
- C2180
ms.assetid: ea71b39e-b977-48a7-b7bd-af68ef5e263b
ms.openlocfilehash: 3794a1ce0fcbe60c06cb3efca45a3081e85c17ce
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87210014"
---
# <a name="compiler-error-c2180"></a>Erro do compilador C2180

expressão de controle tem tipo ' type '

A expressão de controle em **`if`** uma **`while`** instrução,, **`for`** ou **`do`** é uma conversão de expressão para **`void`** . Para corrigir esse problema, altere a expressão de controle para uma que produza um **`bool`** ou um tipo que possa ser convertido em **`bool`** .

O exemplo a seguir gera C2180:

```c
// C2180.c

int main() {
   while ((void)1)   // C2180
      return 1;
   while (1)         // OK
      return 0;
}
```
