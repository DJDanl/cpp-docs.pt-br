---
title: Compilador aviso (nível 1) C4532 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4532
dev_langs:
- C++
helpviewer_keywords:
- C4532
ms.assetid: 4e2a286a-d233-4106-9f65-29be1a94ca02
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 717af9626866fb20e92342fe90f4dde2b5030774
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46025471"
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