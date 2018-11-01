---
title: Compilador aviso (nível 1) C4532
ms.date: 11/04/2016
f1_keywords:
- C4532
helpviewer_keywords:
- C4532
ms.assetid: 4e2a286a-d233-4106-9f65-29be1a94ca02
ms.openlocfilehash: bcadf31eda079ebb8ea7a496efe4c945e16b1ab7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50622833"
---
# <a name="compiler-warning-level-1-c4532"></a>Compilador aviso (nível 1) C4532

'continue': salto para fora do bloco Finally/finally possui comportamento indefinido durante manipulação de encerramento

O compilador encontrou uma das seguintes palavras-chave:

- [continue](../../cpp/continue-statement-cpp.md)

- [break](../../cpp/break-statement-cpp.md)

- [goto](../../cpp/goto-statement-cpp.md)

fazendo com que um salto de uma [Finally](../../cpp/try-finally-statement.md) ou [finalmente](../../dotnet/finally.md) bloco durante um encerramento anormal.

Se ocorrer uma exceção, e enquanto a pilha está sendo desenrolada durante a execução de manipuladores de término (a `__finally` ou blocos finally), e seu código salta fora de um `__finally` bloquear antes do `__finally` bloco termina, o comportamento será indefinido. Controle não pode retornar ao código de desenrolamento, portanto, a exceção não pode ser tratada corretamente.

Se você deve ir de um **Finally** de blocos, verifique primeiro para encerramento anormal.

O exemplo a seguir gera C4532; Comente simplesmente as instruções de salto para resolver os avisos.

```
// C4532.cpp
// compile with: /W1
// C4532 expected
int main() {
   int i;
   for (i = 0; i < 10; i++) {
      __try {
      } __finally {
         // Delete the following line to resolve.
         continue;
      }

      __try {
      } __finally {
         // Delete the following line to resolve.
         break;
      }
   }
}
```