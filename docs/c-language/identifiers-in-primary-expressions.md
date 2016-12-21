---
title: "Identificadores em express&#245;es prim&#225;rias | Microsoft Docs"
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
  - "identificadores, projetando objetos"
ms.assetid: d4602fe6-e7e6-40cc-9823-3b1ebf5d3d38
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Identificadores em express&#245;es prim&#225;rias
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os identificadores podem ter integrais, **float**, `enum`, `struct`, **union**, matrizes, ponteiros ou tipos de função.  Um identificador é uma expressão primária contanto que tenha sido declarada como a designação de um objeto \(nesse caso, um l\-value\) ou como uma função \(nesse caso, um designador de função\).  Para obter uma definição de l\-value, consulte [Expressões de L\-value e R\-value](../Topic/L-Value%20and%20R-Value%20Expressions.md).  
  
 O valor do ponteiro representado por um identificador de matriz não é uma variável, portanto, um identificador de matriz não pode formar o operando esquerdo de uma operação de atribuição e, em virtude disso, não é um l\-value modificável.  
  
 Um identificador declarado como uma função representa um ponteiro cujo valor é o endereço da função.  O ponteiro aborda uma função que retorna um valor de um tipo especificado.  Portanto, os identificadores da função também não podem ser l\-values em operações de atribuição.  Para obter mais informações, consulte [Identificadores](../c-language/c-identifiers.md).  
  
## Consulte também  
 [Expressões primárias C](../c-language/c-primary-expressions.md)