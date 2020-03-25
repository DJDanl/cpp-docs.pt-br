---
title: Aviso do compilador (nível 1) C4313
ms.date: 11/04/2016
f1_keywords:
- C4313
helpviewer_keywords:
- C4313
ms.assetid: bcf64191-e2cf-452e-97b4-423fcec2d07c
ms.openlocfilehash: 14ac938d62b4c5b6f22957268721aea9c3ffef22
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80163044"
---
# <a name="compiler-warning-level-1-c4313"></a>Aviso do compilador (nível 1) C4313

' function ': ' o especificador de formato ' na cadeia de caracteres de formato está em conflito com o número de argumento do tipo ' type '

Há um conflito entre o formato especificado e o valor que você está passando. Por exemplo, você passou um parâmetro de 64 bits para um especificador de formato% d não qualificado, que espera um parâmetro inteiro de 32 bits. Esse aviso só estará em vigor quando o código for compilado para destinos de 64 bits.

## <a name="example"></a>Exemplo

O exemplo de código a seguir gera C4313 quando é compilado para um destino de 64 bits.

```cpp
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
