---
title: Compilador aviso (nível 4) C4245
ms.date: 11/04/2016
f1_keywords:
- C4245
helpviewer_keywords:
- C4245
ms.assetid: 85083d53-9cc2-4d12-b58c-6dad28f15cbe
ms.openlocfilehash: 7f22386439803de1b59f3236775aa6cec0254eab
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50436792"
---
# <a name="compiler-warning-level-4-c4245"></a>Compilador aviso (nível 4) C4245

'conversion': conversão de 'type1' em 'type2', incompatibilidade de signed/unsigned

Você tentou converter com um sinal **const** que tem um valor negativo para um `unsigned`.

O exemplo a seguir gera C4245:

```
// C4245.cpp
// compile with: /W4 /c
const int i = -1;
unsigned int j = i; // C4245

const int k = 1;
unsigned int l = k; // okay

int m = -1;
unsigned int n = m; // okay

void Test(size_t i) {}

int main() {
   Test( -19 );   // C4245
}
```