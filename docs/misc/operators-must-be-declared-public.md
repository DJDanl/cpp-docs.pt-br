---
title: "Os operadores devem ser declarados como &#39;Public&#39; | Microsoft Docs"
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
  - "vbc33011"
  - "bc33011"
helpviewer_keywords: 
  - "BC33011"
ms.assetid: 67fc0dee-4ef5-4afc-a63a-f7d20bce7954
caps.latest.revision: 8
caps.handback.revision: 8
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# Os operadores devem ser declarados como &#39;Public&#39;
Um [Instrução Operator](../Topic/Operator%20Statement.md) não inclui o [Público](../Topic/Public%20\(Visual%20Basic\).md) palavra\-chave.  
  
 Um `Operator` procedimento requer a `Public` e [Compartilhado](../Topic/Shared%20\(Visual%20Basic\).md) palavras\-chave e um operador de conversão também requer o [Widening](../Topic/Widening%20\(Visual%20Basic\).md) ou o [Narrowing](../Topic/Narrowing%20\(Visual%20Basic\).md) palavra\-chave.  
  
 **ID do erro:** BC33011  
  
### Para corrigir este erro  
  
-   Adicionar o `Public` palavra\-chave para o `Operator` instrução.  
  
## Consulte também  
 [Procedimentos do operador](../Topic/Operator%20Procedures%20\(Visual%20Basic\).md)   
 [Instrução Operator](../Topic/Operator%20Statement.md)   
 [Como definir um operador](../Topic/How%20to:%20Define%20an%20Operator%20\(Visual%20Basic\).md)   
 [Como definir um operador de conversão](../Topic/How%20to:%20Define%20a%20Conversion%20Operator%20\(Visual%20Basic\).md)