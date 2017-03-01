---
title: "Compilador aviso (nível 2) C4146 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4146
dev_langs:
- C++
helpviewer_keywords:
- C4146
ms.assetid: d6c31ab1-3120-40d5-8d80-32b5f7046e32
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0bf2a66c5f21ea6149160fa1aeaf13f42bfa7a92
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-2-c4146"></a>Compilador C4146 de aviso (nível 2)
operador menos unário aplicado a tipo unsigned, resultado permanece unsigned  
  
 Tipos não assinados podem conter apenas valores não negativos, para que subtração (negação) unária geralmente não faz sentido quando aplicado a um tipo sem sinal. O operando e o resultado são não-negativo.  
  
 Praticamente, isso ocorre quando o programador está tentando expressar o valor mínimo inteiro, que é de -2147483648. Esse valor não pode ser gravado como -2147483648 porque a expressão é processada em dois estágios:  
  
1.  O número 2147483648 é avaliado. Como é maior que o valor inteiro máximo de 2147483647, o tipo de 2147483648 não é [int](../../c-language/integer-types.md), mas `unsigned int`.  
  
2.  Operador unário menos é aplicado ao valor, com um resultado não assinado, que também é 2147483648.  
  
 O tipo não assinado do resultado pode causar um comportamento inesperado. Se o resultado é usado em uma comparação, uma comparação sem sinal pode ser usada, por exemplo, quando o outro operando é um `int`. Isso explica por que o programa de exemplo a seguir imprime apenas uma linha.  
  
 A segunda linha esperada, `1 is greater than the most negative int`, não será impresso porque `((unsigned int)1) > 2147483648` é false.  
  
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
