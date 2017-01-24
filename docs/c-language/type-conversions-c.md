---
title: "Convers&#245;es de tipo (C) | Microsoft Docs"
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
  - "conversões, Tipo "
  - "convertendo tipos"
  - "promoções integrais"
  - "conversões de tipo, quando executados"
  - "conversão de tipo"
ms.assetid: d130ee7c-03c3-48f4-af7b-1fdba0d3b086
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#245;es de tipo (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As conversões de tipos dependem do operador especificado e do tipo de operando ou dos operadores.  As conversões de tipo são executadas nos seguintes casos:  
  
-   Quando um valor de um tipo é atribuído a uma variável de um tipo diferente ou um operador converte o tipo do seu operando ou operandos antes de executar uma operação  
  
-   Quando um valor de um tipo é explicitamente convertido em um tipo diferente  
  
-   Quando um valor é passado como um argumento para uma função ou quando um tipo é retornado de uma função  
  
 Um caractere, inteiro curto ou campo de bit de inteiro, todos assinados ou não, ou um objeto de tipo de enumeração, podem ser usados em uma expressão sempre que um inteiro puder ser usado.  Se `int` puder representar todos os valores do tipo original, o valor será convertido em `int`; caso contrário, ele será convertido em `unsigned int`.  Esse processo é chamado de “promoção de integral”. As promoções de integral preservam os valores.  Ou seja, o valor após a promoção tem a garantia de ser o mesmo que antes de promoção.  Consulte [Conversões aritméticas usuais](../c-language/usual-arithmetic-conversions.md) para obter mais informações.  
  
## Consulte também  
 [Expressões e atribuições](../c-language/expressions-and-assignments.md)