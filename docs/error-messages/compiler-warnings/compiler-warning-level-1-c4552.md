---
title: Compilador aviso (nível 1) C4552
ms.date: 11/04/2016
f1_keywords:
- C4552
helpviewer_keywords:
- C4552
ms.assetid: ebbbb5ee-1c19-45bd-b386-41a19630fc76
ms.openlocfilehash: 1fb2dc7fd4bc685e457898b47c513c21009146ce
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50585543"
---
# <a name="compiler-warning-level-1-c4552"></a>Compilador aviso (nível 1) C4552

'operator': operador não tem nenhum efeito; operador esperado com efeito colateral

Se uma instrução de expressão tem um operador com nenhum efeito colateral, como a parte superior da expressão, ele é provavelmente um erro.

Para substituir esse aviso, coloque a expressão entre parênteses.

O exemplo a seguir gera C4552:

```
// C4552.cpp
// compile with: /W1
int main() {
   int i, j;
   i + j;   // C4552
   // try the following line instead
   // (i + j);
}
```