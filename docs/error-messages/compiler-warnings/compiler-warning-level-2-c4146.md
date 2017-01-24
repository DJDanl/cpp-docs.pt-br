---
title: "Aviso do compilador (n&#237;vel 2) C4146 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4146"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4146"
ms.assetid: d6c31ab1-3120-40d5-8d80-32b5f7046e32
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 2) C4146
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

unária o operador aplicado ao tipo não assinados, de resultados ainda não assinados  
  
 Os tipos não assinados podem conter somente valores não negativos, tão \(negação\) unária normalmente não faz sentido quando aplicado a um tipo sem assinatura.  O operando e o resultado não forem negativos.  
  
 Praticamente, isso ocorre quando o programador está tentando expressar o valor inteiro mínimo, que é \-2147483648.  Esse valor não pode ser escrito como \-2147483648 porque a expressão é processada em duas fases:  
  
1.  O número 2147483648 é avaliado.  Como é maior que o valor inteiro máximo de 2147483647, o tipo de 2147483648 não [int](../../c-language/integer-types.md), mas `unsigned int`.  
  
2.  Unária é aplicado ao valor de, com um resultado sem assinatura, que também ocorra ser 2147483648.  
  
 O tipo não assinado do resultado pode provocar comportamento inesperado.  Se o resultado for usado em uma comparação, uma comparação sem assinatura poderá ser usada, por exemplo, quando o outro operando for `int`.  Isto explica como o programa de exemplo a seguir copia apenas uma linha.  
  
 A segunda linha esperada, `1 is greater than the most negative int`, não é impressa porque `((unsigned int)1) > 2147483648` será false.  
  
 Você pode evitar C4146 usando INT\_MIN de limits.h, que contém o tipo **signed int**.  
  
## Exemplo  
 O seguinte exemplo gera C4146:  
  
```  
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