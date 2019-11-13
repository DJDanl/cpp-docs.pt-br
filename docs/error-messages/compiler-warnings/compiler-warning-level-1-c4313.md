---
title: Aviso do compilador (nível 1) C4313
ms.date: 11/04/2016
f1_keywords:
- C4313
helpviewer_keywords:
- C4313
ms.assetid: bcf64191-e2cf-452e-97b4-423fcec2d07c
ms.openlocfilehash: 4000ba2254c868bf9959a6f0fb6f8e76255f7590
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966077"
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