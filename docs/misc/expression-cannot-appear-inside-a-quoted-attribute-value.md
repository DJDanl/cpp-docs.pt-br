---
title: "A express&#227;o n&#227;o pode aparecer dentro de um valor de atributo entre aspas | Microsoft Docs"
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
  - "bc31155"
  - "vbc31155"
helpviewer_keywords: 
  - "BC31155"
ms.assetid: ed3e618e-de94-4e4e-afaf-72b11073fb1d
caps.latest.revision: 6
caps.handback.revision: 6
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# A express&#227;o n&#227;o pode aparecer dentro de um valor de atributo entre aspas
A expressão não pode aparecer dentro de um valor de atributo entre aspas. Tente remover as aspas.  
  
 Uma expressão inserida em um valor de atributo para um literal XML está contida entre aspas.  
  
 **ID do erro:** BC31155  
  
### Para corrigir este erro  
  
-   Remova as aspas delimitação o valor do atributo. Este é um exemplo:  
  
    ```vb#  
    ' Generates an error. Dim elem = <outer attr="<%= value %>" /> ' Does not generate an error. Dim elem = <outer attr=<%= value %> />  
    ```  
  
## Consulte também  
 [Expressões inseridas no XML](../Topic/Embedded%20Expressions%20in%20XML%20\(Visual%20Basic\).md)   
 [Literais XML](../Topic/XML%20Literals%20\(Visual%20Basic\).md)   
 [XML](../Topic/XML%20in%20Visual%20Basic.md)