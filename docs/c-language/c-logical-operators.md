---
title: "Operadores lógicos C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- logical operators, expression sequence points
- logical operators, C
- logical AND operator
- '|| operator'
- operators [C], logical
- short-circuit evaluation
- '&& operator'
- logical OR operator
ms.assetid: c0a4e766-ad56-4300-bf76-b28dc0e19b43
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: b97509fbbfdf0bb169af1dae61e07fa6f4ba31d1
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="c-logical-operators"></a>Operadores lógicos C
Os operadores lógicos executam as operações AND lógica (**&&**) e OR lógica ( `||` ).  
  
 **Sintaxe**  
  
 *logical-AND-expression*:  
 *inclusive-OR-expression*  
  
 *logical-AND-expression*  **&&**  *inclusive-OR-expression*  
  
 *logical-OR-expression*:  
 *logical-AND-expression*  
  
 *logical-OR-expression*  **&#124;&#124;**  *logical-AND-expression*  
  
 Os operadores lógicos não executam as conversões aritméticas comuns. Em vez disso, eles avaliam cada operando em termos de sua equivalência a 0. O resultado de uma operação lógica é 0 ou 1. O tipo do resultado é `int`.  
  
 Os operadores lógicos de C são descritos abaixo:  
  
|Operador|Descrição|  
|--------------|-----------------|  
|**&&**|O operador lógico AND produz o valor 1 se os dois operandos tiverem valores diferentes de zero. Se qualquer um dos operandos for igual a 0, o resultado será 0. Se o primeiro operando de uma operação AND lógica for igual a 0, o segundo operando não será avaliado.|  
|`&#124;&#124;`|O operador OR lógico executa uma operação OR inclusiva em seus operandos. O resultado é 0 se os dois operandos tiverem valores 0. Se qualquer um dos operando tiver um valor diferente de zero, o resultado será 1. Se o primeiro operando de uma operação OR lógica tiver um valor diferente de 0, o segundo operando não será avaliado.|  
  
 Os operandos de expressões AND lógica e OR lógica são avaliados da esquerda para a direita. Se o valor do primeiro operando for suficiente para determinar o resultado da operação, o segundo operando não será avaliado. Isso é chamado “avaliação pelo caminho mais curto”. Há um ponto de sequência depois do primeiro operando. Consulte [Pontos de sequência](../c-language/c-sequence-points.md) para obter mais informações.  
  
## <a name="examples"></a>Exemplos  
 Os exemplos a seguir ilustram os operadores lógicos:  
  
```  
int w, x, y, z;  
  
if ( x < y && y < z )  
    printf( "x is less than z\n" );  
```  
  
 Neste exemplo, a função `printf` é chamada para imprimir uma mensagem se `x` for menor que `y` e `y` for menor que `z`. Se `x` for maior que `y`, o segundo operando (`y < z`) não será avaliado e nada será impresso. Observe que isso pode causar problemas nos casos em que o segundo operando tiver efeitos colaterais que sejam usados por algum outro motivo.  
  
```  
printf( "%d" , (x == w || x == y || x == z) );  
```  
  
 Nesse exemplo, se `x` for igual a `w`, `y` ou `z`, o segundo argumento para a função `printf` é avaliado como verdadeiro e o valor 1 é impresso. Caso contrário, será avaliado como false, e o valor 0 será impresso. Assim que uma das condições for avaliada como true, a avaliação é encerrada.  
  
## <a name="see-also"></a>Consulte também  
 [Operador AND lógico: &&](../cpp/logical-and-operator-amp-amp.md)   
 [Operador OR lógico: &#124;&#124;](../cpp/logical-or-operator-pipe-pipe.md)