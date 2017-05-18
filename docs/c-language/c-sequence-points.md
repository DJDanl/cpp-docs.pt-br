---
title: "Pontos de sequência C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- sequence points
ms.assetid: c84885a5-4336-4eba-a643-058df4249903
caps.latest.revision: 6
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
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 3a43a1448203e0f47f20bb4b150efa196cdb3b23
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="c-sequence-points"></a>Pontos de sequência C
Entre os "pontos de sequência" consecutivos, o valor de um objeto pode ser modificado apenas uma vez por uma expressão. A linguagem C define os seguintes pontos de sequência:  
  
-   Operando da esquerda do operador AND lógico (**&&**). O operando da esquerda do operador AND lógico é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar. Se o operando da esquerda for avaliado como falso (0), o outro operando não será avaliado.  
  
-   O operando da esquerda do operador OR lógica (`||`). O operando da esquerda do operador OR lógica é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar. Se o operando da esquerda for avaliado como true (diferente de zero), o outro operando não será avaliado.  
  
-   Operando esquerdo do operador vírgula O operando da esquerda do operador vírgula é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar. Os dois operandos do operador vírgula são sempre avaliados. Observe que o operador vírgula em uma chamada de função não garante a ordem de avaliação.  
  
-   Operador de chamada de função. Todos os argumentos para uma função são avaliados e todos os efeitos colaterais são concluídos antes de entrarem na função. Nenhuma ordem de avaliação entre os argumentos é especificada.  
  
-   Primeiro operando do operador condicional. O primeiro operando do operador condicional é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar.  
  
-   O fim de uma expressão de inicialização completa (ou seja, uma expressão que não faz parte de outra expressão, como o fim de uma inicialização em uma instrução de declaração).  
  
-   A expressão em uma instrução de expressão. As instruções da expressão consistem em uma expressão opcional seguida por um ponto e vírgula (**;**). A expressão é avaliada por seus efeitos colaterais e há um ponto de sequência que segue esta avaliação.  
  
-   A expressão de controle em uma instrução de seleção (**if** ou `switch`). A expressão será completamente avaliada e todos os efeitos colaterais serão concluídos antes que o código dependente da seleção seja executado.  
  
-   A expressão de controle de uma instrução `while` ou **do**. A expressão será completamente avaliada e todos os efeitos colaterais serão concluídos antes que as instruções na próxima iteração do loop de `while` ou de **do** sejam executadas.  
  
-   Cada uma das três expressões de uma instrução **for**. As expressões serão completamente avaliadas e todos os efeitos colaterais serão concluídos antes que as instruções na próxima iteração do loop de **for** sejam executadas.  
  
-   A expressão em uma instrução `return`. A expressão será completamente avaliada e todos os efeitos colaterais serão concluídos antes que o controle retorne para a função de chamada.  
  
## <a name="see-also"></a>Consulte também  
 [Avaliação de expressão](../c-language/expression-evaluation-c.md)
