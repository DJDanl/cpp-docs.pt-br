---
title: Compilador aviso (nível 1) C4731
ms.date: 11/04/2016
f1_keywords:
- C4731
helpviewer_keywords:
- C4731
ms.assetid: 5658c24c-3e6f-4505-835b-1fb92d47cab0
ms.openlocfilehash: af091d1d35fff955afcc5af3da48b80416e79f36
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385427"
---
# <a name="compiler-warning-level-1-c4731"></a>Compilador aviso (nível 1) C4731

'ponteiro': 'Registrar' modificado por código de assembly embutido de registro de ponteiro de quadro

Um registro de ponteiro de quadro foi modificado. Você deve salvar e restaurar o registro no seu assembly bloco ou o quadro de variável embutida (local ou parâmetro, dependendo do registro modificado) ou seu código pode não funcionar corretamente.

O exemplo a seguir gera C4731:

```
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

EBP é o ponteiro de quadro (FPO não é permitido) e ele está sendo modificado. Quando `p` posterior referenciado, ele é referenciado relativo a `EBP`. Mas `EBP` foi substituída pelo código, portanto, o programa não funcionará corretamente e ainda pode falhar.