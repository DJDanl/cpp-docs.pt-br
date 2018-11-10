---
title: Instrução break (C)
ms.date: 11/04/2016
f1_keywords:
- break
helpviewer_keywords:
- break keyword [C]
ms.assetid: 015627c7-0924-49b2-a4d1-c77edf5eae6a
ms.openlocfilehash: 54ece86d629fdaff0113c6f4cebaed7d1b46bb5f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50646973"
---
# <a name="break-statement-c"></a>Instrução break (C)

A instrução `break` encerra a execução da instrução delimitadora `do`, `for`, `switch` ou `while` mais próxima em que aparece. O controle passa para a instrução que segue a instrução encerrada.

## <a name="syntax"></a>Sintaxe

*jump-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**break ;**

A instrução `break` é frequentemente usada para encerrar o processamento de um caso específico dentro de uma instrução `switch`. A falta de uma instrução interativa delimitadora ou `switch` gera um erro.

Em instruções aninhadas, a instrução `break` encerra apenas a instrução `do`, `for`, `switch` ou `while` que a delimita imediatamente. Você pode usar uma instrução `return` ou `goto` para transferir o controle para outro lugar fora da estrutura aninhada.

Este exemplo ilustra a instrução `break`:

```
#include <stdio.h>
int main() {
   char c;
   for(;;) {
      printf_s( "\nPress any key, Q to quit: " );

      // Convert to character value
      scanf_s("%c", &c);
      if (c == 'Q')
          break;
   }
} // Loop exits only when 'Q' is pressed
```

## <a name="see-also"></a>Consulte também

[Instrução Break](../cpp/break-statement-cpp.md)