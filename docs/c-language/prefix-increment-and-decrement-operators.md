---
title: "Operadores de incremento e de decremento pr&#233;-fixados | Microsoft Docs"
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
  - "operadores de decremento"
  - "operadores de decremento, sintaxe"
  - "operadores de incremento, tipos de"
ms.assetid: 9a441bb9-d94a-4b6a-9db2-0d0d76bc480d
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores de incremento e de decremento pr&#233;-fixados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os operadores unários \(`++` and **––**\) são chamados operadores de incremento ou diminuição de “prefixo” quando os operadores de incremento ou diminuição aparecem antes do operando.  O incremento e a diminuição de pós\-fixação têm precedência maior que o incremento e a diminuição de prefixo.  O operando deve ter tipo integral, flutuante ou de ponteiro e deve ser uma expressão I\-value modificável \(uma expressão sem o atributo **const**\).  O resultado é um l\-value.  
  
 Quando o operador aparecer antes de seu operando, o operando será incrementado ou diminuído, e seu novo valor será o resultado da expressão.  
  
 Um operando tipo integral ou flutuante é incrementado ou decrementado pelo valor inteiro 1.  O tipo do resultado é igual ao tipo do operando.  Um operando do tipo ponteiro é incrementado ou decrementado pelo tamanho do objeto pertinente.  Um ponteiro incrementado aponta para o próximo objeto;um ponteiro decrementado aponta para o objeto anterior.  
  
## Exemplo  
 Este exemplo ilustra o operador unário de diminuição de prefixo:  
  
```  
if( line[--i] != '\n' )  
    return;  
```  
  
 Neste exemplo, a variável `i` é diminuída antes de ser usada como um subscrito para `line`.  
  
## Consulte também  
 [Operadores unários C](../c-language/c-unary-operators.md)