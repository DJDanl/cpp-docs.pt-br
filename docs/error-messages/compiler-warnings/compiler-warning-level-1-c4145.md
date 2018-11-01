---
title: Compilador aviso (nível 1) C4145
ms.date: 11/04/2016
f1_keywords:
- C4145
helpviewer_keywords:
- C4145
ms.assetid: 0440777a-cca2-4159-aff5-e67a254ad64a
ms.openlocfilehash: 10c0211bfda354a00e05cba3131d047fce843df8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50553784"
---
# <a name="compiler-warning-level-1-c4145"></a>Compilador aviso (nível 1) C4145

'expression1': expressão relacional como expressão de switch; possível confusão com 'expression2'

Um `switch` instrução usa uma expressão relacional como expressão seu controle, o que resulta em um valor booleano para o **caso** instruções. Você quis dizer *expression2*?

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4145:

```
// C4145.cpp
// compile with: /W1
int main() {
   int i = 0;
   switch(i == 1) {   // C4145, use i instead of i == 1 to resolve
      case 1:
         break;
      default:
         break;
   }
}
```