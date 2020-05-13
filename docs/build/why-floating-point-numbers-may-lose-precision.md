---
title: Por que números de ponto flutuante podem perder a precisão
ms.date: 11/04/2016
helpviewer_keywords:
- DBL_EPSILON constant
- FLT_EPSILON constant
- floating-point numbers, precision
ms.assetid: 1acb1add-ac06-4134-a2fd-aff13d8c4c15
ms.openlocfilehash: 373ce9fa2c2c96fac349940076873a4a637a9dbe
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75298708"
---
# <a name="why-floating-point-numbers-may-lose-precision"></a>Por que números de ponto flutuante podem perder a precisão

Valores decimais de ponto flutuante geralmente não têm uma representação binária exata. Esse é um efeito colateral de como a CPU representa dados de ponto flutuante. Por esse motivo, você pode experimentar alguma perda de precisão e algumas operações de ponto flutuante podem produzir resultados inesperados.

Esse comportamento é o resultado de um dos seguintes:

- A representação binária do número decimal pode não ser exata.

- Há uma incompatibilidade de tipos entre os números usados (por exemplo, a combinação de float e Double).

Para resolver o comportamento, a maioria dos programadores garante que o valor seja maior ou menor do que o necessário, ou que eles obtenham e usem uma biblioteca de BCD codificado em binários que manterá a precisão.

A representação binária de valores de ponto flutuante afeta a precisão e a precisão dos cálculos de ponto flutuante. Microsoft Visual C++ usa o [formato de ponto flutuante IEEE](ieee-floating-point-representation.md).

## <a name="example"></a>Exemplo

```c
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

Para épsilon, você pode usar as constantes FLT_EPSILON, que são definidas para float como 1.192092896 e-07F, ou DBL_EPSILON, que é definido para Double como 2.2204460492503131 e-016. Você precisa incluir float. h para essas constantes. Essas constantes são definidas como o menor número positivo x, de modo que x + 1.0 não seja igual a 1,0. Como esse é um número muito pequeno, você deve empregar a tolerância definida pelo usuário para cálculos que envolvem números muito grandes.

## <a name="see-also"></a>Confira também

[Otimizando o código](optimizing-your-code.md)
