---
title: Aviso do compilador (nível 1) C4731
ms.date: 11/04/2016
f1_keywords:
- C4731
helpviewer_keywords:
- C4731
ms.assetid: 5658c24c-3e6f-4505-835b-1fb92d47cab0
ms.openlocfilehash: b2591756dfaa8887affbe4e470f1c98738b6b680
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052424"
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