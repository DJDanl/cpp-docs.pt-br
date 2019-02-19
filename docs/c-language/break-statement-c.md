---
title: Instrução break (C)
ms.date: 11/04/2016
f1_keywords:
- break
helpviewer_keywords:
- break keyword [C]
ms.assetid: 015627c7-0924-49b2-a4d1-c77edf5eae6a
ms.openlocfilehash: b38ff6c535c142bd15ea09a4d7c80010c3fff31f
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56149806"
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
