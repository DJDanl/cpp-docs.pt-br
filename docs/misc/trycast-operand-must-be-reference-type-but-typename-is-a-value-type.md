---
title: "O operando &#39;TryCast&#39; deve ser tipo de refer&#234;ncia, mas &#39;&lt; typename &gt;&#39; &#233; um tipo de valor | Microsoft Docs"
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
  - "BC30792"
  - "vbc30792"
helpviewer_keywords: 
  - "BC30792"
ms.assetid: 3325fce5-dbc0-4d1d-9530-31f4720bfe6e
caps.latest.revision: 8
caps.handback.revision: 8
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# O operando &#39;TryCast&#39; deve ser tipo de refer&#234;ncia, mas &#39;&lt; typename &gt;&#39; &#233; um tipo de valor
O `TryCast` operador é usado com um tipo de valor para pelo menos um dos argumentos.  
  
 `TryCast` testes de uma relação de herança ou implementação entre os dois argumentos. Portanto, ele permite apenas tipos de referência para os argumentos. Para obter mais informações, consulte [Tipos de valor e referência](../Topic/Value%20Types%20and%20Reference%20Types.md).  
  
 **ID do erro:** BC30792  
  
### Para corrigir este erro  
  
-   Use `DirectCast` ou `CType` para realizar a conversão. Os dois permitem tipos de valor.  
  
## Consulte também  
 [Operador TryCast](../Topic/TryCast%20Operator%20\(Visual%20Basic\).md)   
 [Operador DirectCast](../Topic/DirectCast%20Operator%20\(Visual%20Basic\).md)   
 [Função CType](../Topic/CType%20Function%20\(Visual%20Basic\).md)   
 [Tipos de valor e referência](../Topic/Value%20Types%20and%20Reference%20Types.md)