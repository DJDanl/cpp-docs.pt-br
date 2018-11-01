---
title: Compilador aviso (nível 1) C4313
ms.date: 11/04/2016
f1_keywords:
- C4313
helpviewer_keywords:
- C4313
ms.assetid: bcf64191-e2cf-452e-97b4-423fcec2d07c
ms.openlocfilehash: 774af2d5d29112d56adf97e22d1bdd758a816ef1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50555695"
---
# <a name="compiler-warning-level-1-c4313"></a>Compilador aviso (nível 1) C4313

'function': 'especificador de formato' no formato de cadeia de caracteres está em conflito com o número de argumento do tipo 'type'

Há um conflito entre o formato especificado e o valor que você está passando. Por exemplo, você recebe um parâmetro de 64 bits para um especificador de formato %d não qualificado, que espera um parâmetro de inteiro de 32 bits. Esse aviso é em vigor somente quando o código é compilado para destinos de 64 bits.

## <a name="example"></a>Exemplo

O exemplo de código a seguir gera C4313 quando ele é compilado para um destino de 64 bits.

```
// C4313.cpp
// Compile by using: cl /W1 C4313.cpp
#include <stdio.h>
int main() {
   int * pI = 0;
   printf("%d", pI);   // C4313 on 64-bit platform code
   // Try one of the following lines instead:
   // printf("%p\n", pI);
   // printf("%Id\n", pI);   // %I64d expects 64-bits of information
}
```