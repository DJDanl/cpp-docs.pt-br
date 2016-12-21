---
title: "Chamada de fun&#231;&#227;o (C) | Microsoft Docs"
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
  - "chamadas de função"
  - "chamadas de função, funções C"
  - "funções [C], Chamando "
ms.assetid: 35c66719-3f15-4d3b-97da-4e19dc97b308
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Chamada de fun&#231;&#227;o (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma “chamada de função” é uma expressão que inclui o nome da função que está sendo chamada ou o valor de um ponteiro de função e, opcionalmente, os argumentos que estão sendo passados para a função.  
  
## Sintaxe  
 *postfix\-expression*:  
 *postfix\-expression*  **\(**  *argument\-expression\-list*  opt **\)**  
  
 *argument\-expression\-list*:  
 *assignment\-expression*  
  
 *argument\-expression\-list*  **,**  *assignment\-expression*  
  
 O elemento *postfix\-expression* deve ser avaliado no endereço de uma função \(por exemplo, um identificador de função ou o valor de um ponteiro de função\), e o elemento *argument\-expression\-list* é uma lista de expressões \(separadas por vírgulas\) cujos valores \("argumentos"\) são passados para a função.  O argumento *argument\-expression\-list* pode estar vazio.  
  
 Uma expressão de chamada de função tem o valor e o tipo do valor de retorno da função.  Uma função não pode retornar um objeto do tipo de matriz.  Se o tipo de retorno da função for `void` \(isto é, a função foi declarada para nunca retornar um valor\), a expressão de chamada de função também terá o tipo `void`. \(Consulte [Chamadas de função](../c-language/function-calls.md) para obter mais informações.\)  
  
## Consulte também  
 [Operador de chamada da função: \(\)](../cpp/function-call-operator-parens.md)