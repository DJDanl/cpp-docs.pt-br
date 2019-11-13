---
title: Aviso do compilador (nível 1) C4532
ms.date: 11/04/2016
f1_keywords:
- C4532
helpviewer_keywords:
- C4532
ms.assetid: 4e2a286a-d233-4106-9f65-29be1a94ca02
ms.openlocfilehash: b47eb192bc01e6fe2c6c9423ed2c672f16c6818f
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966247"
---
# <a name="compiler-warning-level-1-c4532"></a>Aviso do compilador (nível 1) C4532

' continue ': salto para fora de __finally bloco/finally tem comportamento indefinido durante tratamento de encerramento

O compilador encontrou uma das seguintes palavras-chave:

- [continue](../../cpp/continue-statement-cpp.md)

- [break](../../cpp/break-statement-cpp.md)

- [goto](../../cpp/goto-statement-cpp.md)

fazendo com que um salto saia de um bloco de [__finally](../../cpp/try-finally-statement.md) ou [finally](../../dotnet/finally.md) durante o encerramento anormal.

Se ocorrer uma exceção e enquanto a pilha estiver sendo desfeita durante a execução dos manipuladores de terminação (os blocos `__finally` ou finally) e seu código sair de um bloco de `__finally` antes de o bloco de `__finally` terminar, o comportamento será indefinido. O controle não pode retornar ao código de desenrolamento, portanto, a exceção pode não ser manipulada corretamente.

Se você precisar sair de um bloco de **__finally** , verifique a conclusão anormal primeiro.

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