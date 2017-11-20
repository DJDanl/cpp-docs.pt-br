---
title: "Compilador (nível 2) do aviso C4146 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4146
dev_langs: C++
helpviewer_keywords: C4146
ms.assetid: d6c31ab1-3120-40d5-8d80-32b5f7046e32
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 6f88b4e0dde56bc63619257264d46a7d2770fa58
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-2-c4146"></a>Compilador C4146 de aviso (nível 2)
operador menos unário aplicado a tipo unsigned, resultado permanece unsigned  
  
 Tipos não assinados podem conter apenas valores não negativos, forma unária de subtração (negação) não faz sentido quando aplicado a um tipo não assinado normalmente. O operando e o resultado são não-negativo.  
  
 Praticamente, isso ocorre quando o programador está tentando expressar o valor mínimo inteiro, que é de -2147483648. Esse valor não pode ser gravado como -2147483648 porque a expressão é processada em duas fases:  
  
1.  O número 2147483648 é avaliado. Porque ele é maior que o valor inteiro máximo de 2147483647, o tipo de 2147483648 não é [int](../../c-language/integer-types.md), mas `unsigned int`.  
  
2.  Operador unário menos é aplicado ao valor, com um resultado não assinado, o que também é 2147483648.  
  
 O tipo não assinado do resultado pode causar um comportamento inesperado. Se o resultado é usado em uma comparação, uma comparação não assinada pode ser usada, por exemplo, quando o outro operando for um `int`. Isso explica por que o programa de exemplo a seguir imprime apenas uma linha.  
  
 A segunda linha esperada, `1 is greater than the most negative int`, não é impresso porque `((unsigned int)1) > 2147483648` é false.  
  
 Você pode evitar C4146 usando INT_MIN de Limits. h, que tem o tipo **assinado int**.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4146:  
  
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