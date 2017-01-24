---
title: "Operadores de incremento e de decremento p&#243;s-fixados C | Microsoft Docs"
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
  - "operadores de incremento, sintaxe"
  - "operadores escalares"
  - "tipos [C], escalar"
ms.assetid: 56ba218d-65f9-405f-8684-caccc0ca33aa
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores de incremento e de decremento p&#243;s-fixados C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os operandos dos operadores de incremento e decremento pós\-fixados são tipos escalares que são l\-values modificáveis.  
  
## Sintaxe  
 *postfix\-expression*:  
 *postfix\-expression*  **\+\+**  
  
 *postfix\-expression*  **––**  
  
 O resultado da operação de incremento ou decremento pós\-fixada é o valor do operando.  Depois que o resultado é obtido, o valor do operando é incrementado \(ou decrementado\).  O código a seguir ilustra o operador de incremento pós\-fixado.  
  
```  
if( var++ > 0 )  
    *p++ = *q++;  
```  
  
 Nesse exemplo, a variável `var` é comparada a 0 e depois incrementada.  Se `var` era positiva antes de ser incrementada, a próxima instrução é executada.  Primeiro, o valor do objeto para o qual `q` aponta é atribuído ao objeto para o qual `p` aponta.  Em seguida, `q` e `p` são incrementados.  
  
## Consulte também  
 [Operadores de incremento e de decremento pós\-fixados: \+\+ e \-\-](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)