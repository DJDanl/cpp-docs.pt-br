---
title: Efeitos colaterais | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- expression evaluation, side effects
- side effects in expression evaluation
ms.assetid: d9b3004a-830e-43a0-bea5-8989d501d670
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f20a73d9cf61873bb92ddd46f685a3257a18bc53
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32387005"
---
# <a name="side-effects"></a>Efeitos colaterais
A ordem de avaliação das expressões é definida pela implementação específica, exceto quando a linguagem garante uma determinada ordem de avaliação (conforme descrito em [Precedência e ordem de avaliação](../c-language/precedence-and-order-of-evaluation.md)). Por exemplo, os efeitos colaterais ocorrem nas seguintes chamadas de função:  
  
```  
add( i + 1, i = j + 2 );  
myproc( getc(), getc() );  
```  
  
 Os argumentos de uma chamada de função podem ser avaliados em qualquer ordem. A expressão `i + 1` pode ser avaliada antes de `i = j + 2`, ou `i = j + 2` pode ser avaliada antes de `i + 1`. O resultado é diferente em cada caso. De maneira similar, não é possível garantir quais caracteres serão passados para `myproc`. Como os incrementos unários e operações de redução envolvem atribuições, essas operações podem causar efeitos colaterais, conforme mostrado no seguinte exemplo:  
  
```  
x[i] = i++;  
```  
  
 Neste exemplo, o valor de `x` alterado é imprevisível. O valor do subscrito pode ser o valor novo ou antigo de `i`. O resultado pode variar em compiladores diferentes ou níveis de otimização diferentes.  
  
 Como C não define a ordem de avaliação de efeitos colaterais, ambos os métodos de avaliação discutidos anteriormente estão corretos e qualquer um pode ser implementado. Para garantir que o seu código seja portátil e claro, evite as instruções que dependem de um pedido específico de avaliação quanto aos efeitos colaterais.  
  
## <a name="see-also"></a>Consulte também  
 [Avaliação de expressão](../c-language/expression-evaluation-c.md)