---
title: "Efeitos colaterais | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "avaliação de expressão, efeitos colaterais"
  - "efeitos colaterais na avaliação da expressão"
ms.assetid: d9b3004a-830e-43a0-bea5-8989d501d670
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Efeitos colaterais
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A ordem de avaliação das expressões é definida pela implementação específica, exceto quando a linguagem garante uma determinada ordem de avaliação \(conforme descrito em [Precedência e ordem de avaliação](../Topic/Precedence%20and%20Order%20of%20Evaluation.md)\).  Por exemplo, os efeitos colaterais ocorrem nas seguintes chamadas de função:  
  
```  
add( i + 1, i = j + 2 );  
myproc( getc(), getc() );  
```  
  
 Os argumentos de uma chamada de função podem ser avaliados em qualquer ordem.  A expressão `i + 1` pode ser avaliada antes de `i = j + 2`, ou `i = j + 2` pode ser avaliada antes de `i + 1`.  O resultado é diferente em cada caso.  De maneira similar, não é possível garantir quais caracteres serão passados para `myproc`.  Como os incrementos unários e operações de redução envolvem atribuições, essas operações podem causar efeitos colaterais, conforme mostrado no seguinte exemplo:  
  
```  
x[i] = i++;  
```  
  
 Neste exemplo, o valor de `x` alterado é imprevisível.  O valor do subscrito pode ser o valor novo ou antigo de `i`.  O resultado pode variar em compiladores diferentes ou níveis de otimização diferentes.  
  
 Como C não define a ordem de avaliação de efeitos colaterais, ambos os métodos de avaliação discutidos anteriormente estão corretos e qualquer um pode ser implementado.  Para garantir que o seu código seja portátil e claro, evite as instruções que dependem de um pedido específico de avaliação quanto aos efeitos colaterais.  
  
## Consulte também  
 [Avaliação de expressão](../Topic/Expression%20Evaluation%20\(C\).md)