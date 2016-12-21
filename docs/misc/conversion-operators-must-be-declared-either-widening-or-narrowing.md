---
title: "Operadores de convers&#227;o devem ser declarados &#39;Widening&#39; ou &#39;Narrowing&#39; | Microsoft Docs"
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
  - "vbc33017"
  - "bc33017"
helpviewer_keywords: 
  - "BC33017"
ms.assetid: 5972d955-ce1d-4348-a021-167eecb3a507
caps.latest.revision: 8
caps.handback.revision: 8
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# Operadores de convers&#227;o devem ser declarados &#39;Widening&#39; ou &#39;Narrowing&#39;
Um [Instrução Operator](../Topic/Operator%20Statement.md) não especifica nem [Widening](../Topic/Widening%20\(Visual%20Basic\).md) ou [Narrowing](../Topic/Narrowing%20\(Visual%20Basic\).md).  
  
 Quando você define um operador de conversão, você deve declará\-la como `Widening` ou `Narrowing`. Essas são características mutuamente, portanto, não é possível especificar ambos.  
  
 **ID do erro:** BC33017  
  
### Para corrigir este erro  
  
-   Decida se o operador de conversão deve ser `Widening` ou `Narrowing`, e inclua a palavra\-chave apropriada no `Operator` instrução. Você deve especificar um ou outro.  
  
## Consulte também  
 [Conversões de Widening e Narrowing](../Topic/Widening%20and%20Narrowing%20Conversions%20\(Visual%20Basic\).md)   
 [Procedimentos do operador](../Topic/Operator%20Procedures%20\(Visual%20Basic\).md)   
 [Instrução Operator](../Topic/Operator%20Statement.md)   
 [Como definir um operador](../Topic/How%20to:%20Define%20an%20Operator%20\(Visual%20Basic\).md)   
 [Como definir um operador de conversão](../Topic/How%20to:%20Define%20a%20Conversion%20Operator%20\(Visual%20Basic\).md)