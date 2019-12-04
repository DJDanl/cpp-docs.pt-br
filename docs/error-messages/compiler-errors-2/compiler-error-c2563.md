---
title: Erro do compilador C2563
ms.date: 11/04/2016
f1_keywords:
- C2563
helpviewer_keywords:
- C2563
ms.assetid: 54abba68-6458-4ca5-894d-3babdb7b3552
ms.openlocfilehash: 983788f041651fcd313c0707a4a7c64cc6e33c5a
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755532"
---
# <a name="compiler-error-c2563"></a>Erro do compilador C2563

incompatibilidade na lista de parâmetros formais

A lista de parâmetros formais de uma função (ou um ponteiro para uma função) não corresponde àquelas de outra função (ou ponteiro para uma função de membro). Como resultado, a atribuição de funções ou ponteiros não pode ser feita.

O exemplo a seguir gera C2563:

```cpp
// C2563.cpp
void func( int );
void func( int, int );
int main() {
   void *fp();
   fp = func;   // C2563
}
```
