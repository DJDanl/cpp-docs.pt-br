---
title: Aviso do compilador (nível 1) C4530
ms.date: 11/04/2016
f1_keywords:
- C4530
helpviewer_keywords:
- C4530
ms.assetid: a04dcdb2-84db-459d-9e5e-4e743887465f
ms.openlocfilehash: 69ca60e2cba338bf1bd1ac3470e583739e72a68e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80186446"
---
# <a name="compiler-warning-level-1-c4530"></a>Aviso do compilador (nível 1) C4530

C++manipulador de exceção usado, mas semântica de liberação não está habilitada. Especificar/EHsc

C++o tratamento de exceção foi usado, mas [/EHsc](../../build/reference/eh-exception-handling-model.md) não foi selecionado.

Quando a opção/EHsc não foi habilitada, um objeto com armazenamento automático no quadro, entre a função que faz o lançamento e a função capturando a throw, não será destruído. No entanto, um objeto com armazenamento automático criado em um bloco **try** ou **Catch** será destruído.

O exemplo a seguir gera C4530:

```cpp
// C4530.cpp
// compile with: /W1
int main() {
   try{} catch(int*) {}   // C4530
}
```

Compile o exemplo com/EHsc para resolver o aviso.
