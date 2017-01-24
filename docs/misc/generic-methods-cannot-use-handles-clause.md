---
title: "M&#233;todos gen&#233;ricos n&#227;o &#233; poss&#237;vel usar a cl&#225;usula &#39;Handles&#39; | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-visual-basic"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vbc32080"
  - "BC32080"
helpviewer_keywords: 
  - "BC32080"
ms.assetid: 88c62a1c-aee3-46b2-ad78-76790022c04c
caps.latest.revision: 10
caps.handback.revision: 10
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# M&#233;todos gen&#233;ricos n&#227;o &#233; poss&#237;vel usar a cl&#225;usula &#39;Handles&#39;
Genérico `Sub` procedimento inclui um [Handles](../Topic/Handles%20Clause%20\(Visual%20Basic\).md) cláusula na sua declaração.  
  
 Um `Handles` cláusula Especifica uma lista de eventos que o `Sub` identificadores de procedimento. Para ser um manipulador de eventos, o `Sub` procedimento deve ter a mesma assinatura de cada evento a manipular. Um procedimento genérico pode ser criado mais de uma vez, com assinaturas que [!INCLUDE[vbprvb](../Token/vbprvb_md.md)] não pode prever em tempo de compilação. Portanto, [!INCLUDE[vbprvb](../Token/vbprvb_md.md)] não pode garantir uma assinatura que corresponde dos eventos de `Handles` cláusula.  
  
 **ID do erro:** BC32080  
  
### Para corrigir este erro  
  
-   Se o `Sub` procedimento precisa ser genérico, remova o `Handles` cláusula de sua declaração. Use o [Instrução AddHandler](../Topic/AddHandler%20Statement.md) para associar este manipulador de eventos com um evento.  
  
-   Se o `Sub` procedimento precisa usar o `Handles` cláusula para associar eventos, remova o [Of](../Topic/Of%20Clause%20\(Visual%20Basic\).md) cláusula de sua declaração. Você deve usar um procedimento não\-genérico com `Handles`.  
  
## Consulte também  
 [Tipos genéricos no Visual Basic](../Topic/Generic%20Types%20in%20Visual%20Basic%20\(Visual%20Basic\).md)   
 [NÃO nos manipuladores de eventos e eventos de compilação:](http://msdn.microsoft.com/pt-br/95074a0d-1cbc-4221-a95a-964185c7f962)