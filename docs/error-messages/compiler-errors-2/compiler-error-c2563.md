---
title: Erro do compilador C2563
ms.date: 11/04/2016
f1_keywords:
- C2563
helpviewer_keywords:
- C2563
ms.assetid: 54abba68-6458-4ca5-894d-3babdb7b3552
ms.openlocfilehash: 04a10c82fa6aa39bcf1098d6d4aabfc2f769e7c8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50539302"
---
# <a name="compiler-error-c2563"></a>Erro do compilador C2563

incompatibilidade na lista de parâmetros formais

Lista de parâmetros formais de uma função (ou um ponteiro para uma função) não corresponde às de outra função (ou ponteiro para uma função de membro). Como resultado, a atribuição de funções ou ponteiros não pode ser feita.

O exemplo a seguir gera C2563:

```
// C2563.cpp
void func( int );
void func( int, int );
int main() {
   void *fp();
   fp = func;   // C2563
}
```