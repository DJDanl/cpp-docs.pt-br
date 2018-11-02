---
title: Compilador aviso (nível 1) C4530
ms.date: 11/04/2016
f1_keywords:
- C4530
helpviewer_keywords:
- C4530
ms.assetid: a04dcdb2-84db-459d-9e5e-4e743887465f
ms.openlocfilehash: a542f9b6bb73e561592e1e779aa6ee493612e6ac
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50554083"
---
# <a name="compiler-warning-level-1-c4530"></a>Compilador aviso (nível 1) C4530

Manipulador de exceção de C++ usado, mas semântica de liberação não estão habilitados. Especifique /EHsc

Tratamento de exceções C++ foi usado, mas [/EHsc](../../build/reference/eh-exception-handling-model.md) não foi selecionada.

Quando a opção de /EHsc não foi habilitada, um objeto com armazenamento automático no quadro, entre a função fazendo o throw e a função capturando throw, não será destruído. No entanto, um objeto com o armazenamento automático criado em uma **tente** ou **catch** bloco será destruído.

O exemplo a seguir gera C4530:

```
// C4530.cpp
// compile with: /W1
int main() {
   try{} catch(int*) {}   // C4530
}
```

Compile o exemplo com /EHsc para resolver o aviso.