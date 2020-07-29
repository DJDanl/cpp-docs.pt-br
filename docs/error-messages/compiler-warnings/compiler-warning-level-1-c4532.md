---
title: Aviso do compilador (nível 1) C4532
ms.date: 11/04/2016
f1_keywords:
- C4532
helpviewer_keywords:
- C4532
ms.assetid: 4e2a286a-d233-4106-9f65-29be1a94ca02
ms.openlocfilehash: b8c7503c7d1c1b711006415a327c360731222042
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87196338"
---
# <a name="compiler-warning-level-1-c4532"></a>Aviso do compilador (nível 1) C4532

' continue ': salto para fora de __finally bloco/finally tem comportamento indefinido durante tratamento de encerramento

O compilador encontrou uma das seguintes palavras-chave:

- [continua](../../cpp/continue-statement-cpp.md)

- [break](../../cpp/break-statement-cpp.md)

- [goto](../../cpp/goto-statement-cpp.md)

fazendo com que um salto saia de um bloco de [__finally](../../cpp/try-finally-statement.md) ou [finally](../../dotnet/finally.md) durante o encerramento anormal.

Se ocorrer uma exceção e enquanto a pilha estiver sendo desbobinada durante a execução dos manipuladores de encerramento (os **`__finally`** blocos ou finally) e o código sair de um **`__finally`** bloco antes de o **`__finally`** bloco terminar, o comportamento será indefinido. O controle não pode retornar ao código de desenrolamento, portanto, a exceção pode não ser manipulada corretamente.

Se você precisar sair de um **`__finally`** bloco, verifique a conclusão anormal primeiro.

O exemplo a seguir gera C4532; Basta comentar as instruções de salto para resolver os avisos.

```cpp
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
