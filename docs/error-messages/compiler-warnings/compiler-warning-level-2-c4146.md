---
title: Compilador (nível 2) do aviso C4146 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4146
dev_langs:
- C++
helpviewer_keywords:
- C4146
ms.assetid: d6c31ab1-3120-40d5-8d80-32b5f7046e32
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 40a94d2aed0b455fda646214f4488c53045b7f6f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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