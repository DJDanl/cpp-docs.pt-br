---
title: Aviso do compilador (nível 2) C4146
ms.date: 11/04/2016
f1_keywords:
- C4146
helpviewer_keywords:
- C4146
ms.assetid: d6c31ab1-3120-40d5-8d80-32b5f7046e32
ms.openlocfilehash: d595befc80d954c8fb84f83ad6c4e0cb5f4fcf26
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052163"
---
# <a name="compiler-warning-level-2-c4146"></a>Aviso do compilador (nível 2) C4146

operador de subtração unário aplicado a tipo não assinado, resultado ainda não assinado

Os tipos não assinados podem conter apenas valores não negativos, portanto, o menos unário (negação) geralmente não faz sentido quando aplicado a um tipo não assinado. O operando e o resultado são não negativos.

Praticamente, isso ocorre quando o programador está tentando expressar o valor inteiro mínimo, que é-2147483648. Esse valor não pode ser gravado como-2147483648 porque a expressão é processada em dois estágios:

1. O número 2147483648 é avaliado. Como é maior que o valor inteiro máximo de 2147483647, o tipo de 2147483648 não é [int](../../c-language/integer-types.md), mas `unsigned int`.

1. A subtração unário é aplicada ao valor, com um resultado não assinado, que também é 2147483648.

O tipo não assinado do resultado pode causar um comportamento inesperado. Se o resultado for usado em uma comparação, uma comparação não assinada poderá ser usada, por exemplo, quando o outro operando for um `int`. Isso explica por que o programa de exemplo abaixo imprime apenas uma linha.

A segunda linha esperada, `1 is greater than the most negative int`, não é impressa porque `((unsigned int)1) > 2147483648` é false.

Você pode evitar C4146 usando INT_MIN de Limits. h, que tem o tipo **assinado int**.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4146:

```cpp
// C4146.cpp
// compile with: /W2
#include <stdio.h>

void check(int i)
{
    if (i > -2147483648)   // C4146
        printf_s("%d is greater than the most negative int\n", i);
}

int main()
{
    check(-100);
    check(1);
}
```