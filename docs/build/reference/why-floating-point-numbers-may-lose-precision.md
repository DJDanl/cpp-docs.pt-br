---
title: "Por que números de ponto flutuante podem perder a precisão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- DBL_EPSILON constant
- FLT_EPSILON constant
- floating-point numbers, precision
ms.assetid: 1acb1add-ac06-4134-a2fd-aff13d8c4c15
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 371aad5dc573a13ca834d8d6d9667a43bb40324e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="why-floating-point-numbers-may-lose-precision"></a>Por que números de ponto flutuante podem perder a precisão
Valores decimais de ponto flutuantes geralmente não têm uma representação binária exata. Este é um efeito colateral de como a CPU representa dados de ponto flutuante. Por esse motivo, você pode enfrentar alguma perda de precisão e algumas operações de ponto flutuantes podem produzir resultados inesperados.  
  
 Esse comportamento é o resultado de uma das seguintes opções:  
  
-   A representação binária do número decimal pode não ser exata.  
  
-   Há uma incompatibilidade entre os números usados (por exemplo, combinação float e double).  
  
 Para resolver o problema, a maioria dos programadores, certifique-se que o valor é maior ou menor do que o que é necessário, ou obter e usar uma biblioteca de Binary Coded Decimal (BCD) que mantém a precisão.  
  
 Representação binária de valores de ponto flutuante afeta a precisão e a precisão dos cálculos de ponto flutuante. Microsoft Visual C++ usa [formato de ponto flutuante IEEE](../../build/reference/ieee-floating-point-representation.md).  
  
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
 Para ÉPSILON, você pode usar as constantes FLT_EPSILON, que é definido para ponto flutuante como 1.192092896e-07F, ou DBL_EPSILON, que é definido para dois como 2.2204460492503131e-016. Você precisa incluir float. h para constantes. Essas constantes são definidos como ' positivo menor número x, como x + 1.0 não é igual a 1.0. Como esse é um número muito pequeno, você deve empregar tolerância definida pelo usuário para cálculos que envolvem números muito grandes.  
  
## <a name="see-also"></a>Consulte também  
 [Otimizando seu código](../../build/reference/optimizing-your-code.md)