---
title: O uso do nome de função sem () não produz código
ms.date: 11/04/2016
helpviewer_keywords:
- functions [C++], without parentheses
ms.assetid: edf4a177-a160-44aa-8436-e077b5b27809
ms.openlocfilehash: 51be77dc8f4fe072ea6cc46dd51e38862649feda
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824611"
---
# <a name="using-function-name-without--produces-no-code"></a>O uso do nome de função sem () não produz código

Quando o nome de uma função declarado em seu programa for usado sem parênteses, o compilador não produz código. Isso ocorre independentemente de estarem ou não a função utiliza parâmetros, porque o compilador calcula o endereço de função; No entanto, como o operador de chamada de função "()" não está presente, nenhuma chamada é feita. Esse resultado é semelhante ao seguinte:

```
// compile with /Wall to generate a warning
int a;
a;      // no code generated here either
```

No Visual C++, mesmo usando o nível de aviso 4 não gera nenhuma saída de diagnóstico. Nenhum aviso é emitido; Nenhum código é produzido.

O código de exemplo a seguir é compilado (com um aviso) e vincula corretamente sem erros, mas não produz código referência ao `funcn( )`. Para que isso funcione corretamente, adicione o operador de chamada de função "()".

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

## <a name="see-also"></a>Consulte também

[Otimizando seu código](optimizing-your-code.md)
