---
title: "Operador de avaliação sequencial | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], sequential-evaluation
- sequential-evaluation operator
- comma operator
ms.assetid: 587514f4-c8e2-44e9-81a8-7a553ce1453a
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
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
translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 59e3fa3daec861d580fda1d5605fdd33e7e955cc
ms.lasthandoff: 04/01/2017

---
# <a name="sequential-evaluation-operator"></a>Operador de avaliação sequencial
O operador de avaliação sequencial, também chamado de "operador vírgula", avalia seus dois operandos em sequência da esquerda para a direita.  
  
## <a name="syntax"></a>Sintaxe  
 *expression*:  
 *assignment-expression*  
  
 *expression*  **,**  *assignment-expression*  
  
 O operando esquerdo do operador de avaliação sequencial é avaliado como uma expressão `void`. O resultado da operação tem o mesmo valor e tipo que o operando direito. Cada operando pode ser de qualquer tipo. O operador de avaliação sequencial não executa conversões de tipos entre seus operandos e não produz um l-value. Há um ponto de sequência depois do primeiro operando, o que significa que todos os efeitos colaterais da avaliação do operando esquerdo são concluídos antes de iniciar a avaliação do operando direito. Consulte [Pontos de sequência](../c-language/c-sequence-points.md) para obter mais informações.  
  
 Geralmente, o operador de avaliação sequencial é usado para avaliar duas ou mais expressões em contextos em que apenas uma expressão é permitida.  
  
 As vírgulas podem ser usadas como separadores em alguns contextos. Porém, você deve ter cuidado para não confundir o uso da vírgula como separador com seu uso como operador; os dois usos são completamente diferentes.  
  
## <a name="example"></a>Exemplo  
 Este exemplo ilustra o operador de avaliação sequencial:  
  
```  
for ( i = j = 1; i + j < 20; i += i, j-- );  
```  
  
 Neste exemplo, cada operando da terceira expressão da instrução **for** é avaliado de maneira independente. O operando esquerdo, `i += i`, é avaliado primeiro; em seguida, é a vez do operando direito, `j--`.  
  
```  
func_one( x, y + 2, z );  
func_two( (x--, y + 2), z );  
```  
  
 Na chamada de função para `func_one`, três argumentos, separados por vírgulas, são passados: `x`, `y + 2` e `z`. Na chamada da função para `func_two`, os parênteses forçam o compilador a interpretar a primeira vírgula como o operador de avaliação sequencial. Essa chamada de função passa dois argumentos para `func_two`. O primeiro argumento é o resultado da operação de avaliação sequencial `(x--, y + 2)`, que tem o valor e o tipo da expressão `y + 2`; o segundo argumento é `z`.  
  
## <a name="see-also"></a>Consulte também  
 [Operador vírgula: ,](../cpp/comma-operator.md)
