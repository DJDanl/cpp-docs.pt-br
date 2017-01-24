---
title: "Operadores n&#227;o podem ser declarados &#39;&lt; palavra-chave &gt;&#39; | Microsoft Docs"
ms.custom: ""
ms.date: "11/17/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-visual-basic"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vbc33013"
  - "bc33013"
helpviewer_keywords: 
  - "BC33013"
ms.assetid: bfd805f4-e30e-4553-9cb7-2690595f0480
caps.latest.revision: 9
caps.handback.revision: 9
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# Operadores n&#227;o podem ser declarados &#39;&lt; palavra-chave &gt;&#39;
Um operador é declarado com uma palavra\-chave não é válida para definições de operador.  
  
 Cada operador deve ser declarado como [Público](../Topic/Public%20\(Visual%20Basic\).md) e [Compartilhado](../Topic/Shared%20\(Visual%20Basic\).md). Além disso, um operador de conversão deve ser declarado com um [Widening](../Topic/Widening%20\(Visual%20Basic\).md) ou [Narrowing](../Topic/Narrowing%20\(Visual%20Basic\).md), mas não ambos. Uma definição do operador, opcionalmente, pode incluir o [Sobrecargas](../Topic/Overloads%20\(Visual%20Basic\).md) ou [Sombras](../Topic/Shadows%20\(Visual%20Basic\).md) palavras\-chave. Não há outras palavras\-chave é permitidos em um [Instrução Operator](../Topic/Operator%20Statement.md).  
  
 **ID do erro:** BC33013  
  
### Para corrigir este erro  
  
-   Remova a palavra\-chave inválida da definição do operador.  
  
## Consulte também  
 [Procedimentos do operador](../Topic/Operator%20Procedures%20\(Visual%20Basic\).md)   
 [Como definir um operador](../Topic/How%20to:%20Define%20an%20Operator%20\(Visual%20Basic\).md)   
 [Como definir um operador de conversão](../Topic/How%20to:%20Define%20a%20Conversion%20Operator%20\(Visual%20Basic\).md)