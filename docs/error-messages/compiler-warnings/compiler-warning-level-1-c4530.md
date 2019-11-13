---
title: Aviso do compilador (nível 1) C4530
ms.date: 11/04/2016
f1_keywords:
- C4530
helpviewer_keywords:
- C4530
ms.assetid: a04dcdb2-84db-459d-9e5e-4e743887465f
ms.openlocfilehash: 3139d321bca64b9938badebdabccd3ca1eb96d11
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966255"
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