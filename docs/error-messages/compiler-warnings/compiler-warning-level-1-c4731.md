---
title: Compilador aviso (nível 1) C4731 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4731
dev_langs:
- C++
helpviewer_keywords:
- C4731
ms.assetid: 5658c24c-3e6f-4505-835b-1fb92d47cab0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 75117b34e63694cfa6aeec97abf178ff8e61a7da
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46086470"
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