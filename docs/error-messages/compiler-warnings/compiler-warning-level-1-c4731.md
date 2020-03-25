---
title: Aviso do compilador (nível 1) C4731
ms.date: 11/04/2016
f1_keywords:
- C4731
helpviewer_keywords:
- C4731
ms.assetid: 5658c24c-3e6f-4505-835b-1fb92d47cab0
ms.openlocfilehash: 72483b734a1463b7b211c49ef21a01536ffa0ea1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185718"
---
# <a name="compiler-warning-level-1-c4731"></a>Aviso do compilador (nível 1) C4731

' pointer ': ponteiro de quadro registra ' Register ' modificado por código de assembly embutido

Um registro de ponteiro de quadro foi modificado. Você deve salvar e restaurar o registro em sua variável de quadro ou bloco de assembly embutido (local ou parâmetro, dependendo do registro modificado) ou o seu código pode não funcionar corretamente.

O exemplo a seguir gera C4731:

```cpp
// C4731.cpp
// compile with: /W1 /LD
// processor: x86
// C4731 expected
void bad(int p) {
   __asm
   {
      mov ebp, 1
   }

   if (p == 1)
   {
      // ...
   }
}
```

EBP é o ponteiro de quadro (FPO não é permitido) e está sendo modificado. Quando `p` é referenciado posteriormente, ele é referenciado em relação a `EBP`. Mas `EBP` foi substituído pelo código, portanto, o programa não funcionará corretamente e pode até mesmo falhar.
