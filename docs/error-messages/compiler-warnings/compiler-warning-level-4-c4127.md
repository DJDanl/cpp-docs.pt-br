---
title: Compilador aviso (nível 4) C4127
ms.date: 09/13/2018
f1_keywords:
- C4127
helpviewer_keywords:
- C4127
ms.assetid: f59ded9e-5227-45bd-ac43-2aa861581363
ms.openlocfilehash: 7f1e23d15d8daa126987278611cb5a85a5a36fc9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401301"
---
# <a name="compiler-warning-level-4-c4127"></a>Compilador aviso (nível 4) C4127

> expressão condicional é constante

## <a name="remarks"></a>Comentários

A expressão de controle de um **se** instrução ou **enquanto** loop for avaliada como uma constante. Devido ao seu uso de expressões idiomática comuns, a partir do Visual Studio 2015 atualização 3, constantes triviais, como 1 ou **verdadeira** não disparam o aviso, a menos que eles são o resultado de uma operação em uma expressão.

Se a expressão de controle de um **enquanto** loop é uma constante, porque o loop é encerrado no meio, considere substituir o **enquanto** loop com um **para** loop. Você pode omitir a inicialização, o teste de encerramento e executar um loop incremento de uma **para** loop, o que faz com que o loop infinito, assim como `while(1)`, e você pode sair do loop do corpo dos **para** instrução.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra duas maneiras de C4127 é gerado e mostra como usar um loop evitar o aviso for:

```cpp
// C4127.cpp
// compile with: /W4
#include <stdio.h>
int main() {
   if (true) {}           // OK in VS2015 update 3 and later
   if (1 == 1) {}         // C4127
   while (42) { break; }  // C4127

   // OK
   for ( ; ; ) {
      printf("test\n");
      break;
   }
}
```