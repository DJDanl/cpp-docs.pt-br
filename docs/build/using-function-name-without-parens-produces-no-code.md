---
title: O uso do nome de função sem () não produz código
ms.date: 11/04/2016
helpviewer_keywords:
- functions [C++], without parentheses
ms.assetid: edf4a177-a160-44aa-8436-e077b5b27809
ms.openlocfilehash: 51be77dc8f4fe072ea6cc46dd51e38862649feda
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62314592"
---
# <a name="using-function-name-without--produces-no-code"></a>O uso do nome de função sem () não produz código

Quando um nome de função declarado em seu programa é usado sem parênteses, o compilador não produz código. Isso ocorre independentemente de a função usar ou não parâmetros porque o compilador calcula o endereço da função; no entanto, como o operador de chamada de função "()" não está presente, nenhuma chamada é feita. Esse resultado é semelhante ao seguinte:

```
// compile with /Wall to generate a warning
int a;
a;      // no code generated here either
```

Em Visual C++, mesmo o uso do nível de aviso 4 não gera nenhuma saída de diagnóstico. Nenhum aviso é emitido; nenhum código é produzido.

O código de exemplo a seguir compila (com um aviso) e links corretamente sem erros, mas não produz nenhum código em `funcn( )`referência a. Para que isso funcione corretamente, adicione o operador de chamada de função "()".

```
#include <stdio.h>
void funcn();

int main() {
   funcn;      /* missing function call operator;
                  call will fail.  Use funcn() */
   }

void funcn() {
   printf("\nHello World\n");
}
```

## <a name="see-also"></a>Confira também

[Otimizando o código](optimizing-your-code.md)
