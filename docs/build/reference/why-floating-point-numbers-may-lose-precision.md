---
title: "Por que n&#250;meros de ponto flutuante podem perder a precis&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Constante DBL_EPSILON"
  - "números de ponto flutuante, precisão"
  - "Constante FLT_EPSILON"
ms.assetid: 1acb1add-ac06-4134-a2fd-aff13d8c4c15
caps.latest.revision: 10
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Por que n&#250;meros de ponto flutuante podem perder a precis&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os valores decimais de ponto flutuante geralmente não têm uma representação binária exata.  Esse é um efeito colateral de como CPU representa dados de ponto flutuante.  Por isso, você pode apresentar uma perda de precisão, e algumas operações de ponto flutuante podem gerar resultados inesperados.  
  
 Esse comportamento é o resultado de um dos seguintes:  
  
-   A representação binária do número decimal pode não ser preciso.  
  
-   Há uma incompatibilidade entre os números utilizados \(por exemplo, float e double de combinação\).  
  
 Para resolver o comportamento, a maioria dos programadores o garantem que o valor seja maior ou menor do que o necessário, ou a serem obtidos e usem uma biblioteca decimal binário codificado de \(BCD\) que mantém a precisão.  
  
 A representação binária de valores de ponto flutuante afeta a precisão e a precisão de cálculos de ponto flutuante.  Usa [Formato de ponto flutuante IEEE](../../build/reference/ieee-floating-point-representation.md)do Microsoft Visual C\+\+.  
  
## Exemplo  
  
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
  
  **Não são iguais\!  O valor c for 2,4679999352 ou 2,468000**    
## Comentários  
 Para o ÉPSILON, você pode usar constantes FLT\_EPSILON, que é definido para flutuantes como 1.192092896e\-07F, ou DBL\_EPSILON, que é definido para o dobro como 2.2204460492503131e\-016.  Você precisa incluir float.h para essas constantes.  Essas constantes são definidas como o número positivo o menor x, de modo que x\+1.0 não é igual a 1,0.  Como esse é um número muito pequeno, você deve implantar a tolerância definido pelo usuário para cálculos que envolvem números muito grandes.  
  
## Consulte também  
 [Otimizando o código](../../build/reference/optimizing-your-code.md)