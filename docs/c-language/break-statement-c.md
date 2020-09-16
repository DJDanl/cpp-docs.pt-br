---
title: Instrução break (C)
ms.date: 11/04/2016
f1_keywords:
- break
helpviewer_keywords:
- break keyword [C]
ms.assetid: 015627c7-0924-49b2-a4d1-c77edf5eae6a
ms.openlocfilehash: 5322f8cb5218882d891e2cd66704f9dbfd1bc149
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90683461"
---
# <a name="break-statement-c"></a>Instrução break (C)

A **`break`** instrução encerra a execução da instrução,,, ou delimitadora mais próxima **`do`** **`for`** **`switch`** **`while`** na qual ela aparece. O controle passa para a instrução que segue a instrução encerrada.

## <a name="syntax"></a>Sintaxe

*instrução de salto*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**break ;**

A **`break`** instrução é frequentemente usada para encerrar o processamento de um caso específico dentro de **`switch`** uma instrução. A falta de uma instrução ou iterativa delimitadora **`switch`** gera um erro.

Em instruções aninhadas, a **`break`** instrução encerra apenas a **`do`** instrução,, **`for`** **`switch`** ou **`while`** que a inclui imediatamente. Você pode usar uma **`return`** **`goto`** instrução or para transferir o controle em outro lugar da estrutura aninhada.

Este exemplo ilustra a **`break`** instrução:

```C
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

## <a name="see-also"></a>Confira também

[Instrução break](../cpp/break-statement-cpp.md)
