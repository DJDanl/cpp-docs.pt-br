---
title: "&#39;Group&#39; n&#227;o permitido neste contexto; Identificador esperado | Microsoft Docs"
ms.custom: ""
ms.date: "11/23/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-visual-basic"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "bc36708"
  - "vbc36708"
helpviewer_keywords: 
  - "BC36708"
ms.assetid: ef6b453e-68e7-47c2-997c-9fd1ca074217
caps.latest.revision: 3
caps.handback.revision: 3
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# &#39;Group&#39; n&#227;o permitido neste contexto; Identificador esperado
O `Group` palavra\-chave está incluído no `Into` seção um `Aggregate` cláusula. O `Group` palavra\-chave só é válido na `Group By` ou `Group Join` cláusulas.  
  
 **ID do erro:** BC36618  
  
### Para corrigir este erro  
  
-   Remover o `Group` palavra\-chave from a `Aggregate` cláusula. Você pode adicionar uma `Group By` cláusula à consulta para agrupar resultados.  
  
## Consulte também  
 [Cláusula Aggregate](../Topic/Aggregate%20Clause%20\(Visual%20Basic\).md)   
 [Cláusula Group By](../Topic/Group%20By%20Clause%20\(Visual%20Basic\).md)   
 [Cláusula Group Join](../Topic/Group%20Join%20Clause%20\(Visual%20Basic\).md)   
 [Introdução a LINQ no Visual Basic](../Topic/Introduction%20to%20LINQ%20in%20Visual%20Basic.md)   
 [LINQ](../Topic/LINQ%20in%20Visual%20Basic.md)