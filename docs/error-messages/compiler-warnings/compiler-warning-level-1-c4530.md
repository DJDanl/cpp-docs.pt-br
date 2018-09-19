---
title: Compilador aviso (nível 1) C4530 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4530
dev_langs:
- C++
helpviewer_keywords:
- C4530
ms.assetid: a04dcdb2-84db-459d-9e5e-4e743887465f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bbfbc67377dd48eeb692bdd4cac1f113fbdf7f6a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46110452"
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