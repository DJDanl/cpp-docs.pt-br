---
title: Por que números de ponto flutuante podem perder a precisão
ms.date: 11/04/2016
helpviewer_keywords:
- DBL_EPSILON constant
- FLT_EPSILON constant
- floating-point numbers, precision
ms.assetid: 1acb1add-ac06-4134-a2fd-aff13d8c4c15
ms.openlocfilehash: 6e6f758e7a683a28189123b03252223476ac732a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50442660"
---
# <a name="why-floating-point-numbers-may-lose-precision"></a>Por que números de ponto flutuante podem perder a precisão

Valores decimais de ponto flutuantes geralmente não têm uma representação binária exata. Isso é um efeito colateral de como a CPU representa dados de ponto flutuante. Por esse motivo, você pode enfrentar alguma perda de precisão e algumas operações de ponto flutuantes podem produzir resultados inesperados.

Esse comportamento é o resultado de uma das seguintes opções:

- A representação binária do número decimal pode não ser exata.

- Há uma incompatibilidade de tipo entre os números usados (por exemplo, mixagem float e double).

Para resolver o comportamento, a maioria dos programadores, certifique-se de que o valor é maior ou menor que o que é necessária, ou eles obterem e usam uma biblioteca de Binary Coded Decimal (BCD) que manterá a precisão.

Representação binária de valores de ponto flutuante afeta a precisão e a precisão dos cálculos de ponto flutuante. Usa o Microsoft Visual C++ [formato de ponto flutuante IEEE](../../build/reference/ieee-floating-point-representation.md).

## <a name="example"></a>Exemplo

```
// Floating-point_number_precision.c
// Compile options needed: none. Value of c is printed with a decimal
// point precision of 10 and 6 (printf rounded value by default) to
// show the difference
#include <stdio.h>

#define EPSILON 0.0001   // Define your own tolerance
#define FLOAT_EQ(x,v) (((v - EPSILON) < x) && (x <( v + EPSILON)))

int main() {
   float a, b, c;

   a = 1.345f;
   b = 1.123f;
   c = a + b;
   // if (FLOAT_EQ(c, 2.468)) // Remove comment for correct result
   if (c == 2.468)            // Comment this line for correct result
      printf_s("They are equal.\n");
   else
      printf_s("They are not equal! The value of c is %13.10f "
                "or %f",c,c);
}
```

```Output
They are not equal! The value of c is  2.4679999352 or 2.468000
```

## <a name="comments"></a>Comentários

Para ÉPSILON, você pode usar as constantes FLT_EPSILON, que é definido para ponto flutuante como 1.192092896e-07F, ou DBL_EPSILON, que é definido para dupla como 2.2204460492503131e-016. Você precisa incluir float. h para constantes. Essas constantes são definidas como positivo o menor número x, tal que x + 1,0 não é igual a 1,0. Como esse é um número muito pequeno, você deve empregar tolerância definida pelo usuário para cálculos que envolvem números muito grandes.

## <a name="see-also"></a>Consulte também

[Otimizando seu código](../../build/reference/optimizing-your-code.md)