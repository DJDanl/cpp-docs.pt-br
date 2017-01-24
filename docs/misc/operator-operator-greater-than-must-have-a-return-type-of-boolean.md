---
title: "O operador &#39;&lt; operador &gt;&#39; deve ter um tipo de retorno booleano | Microsoft Docs"
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
  - "vbc33023"
  - "bc33023"
helpviewer_keywords: 
  - "BC33023"
ms.assetid: 18e066f4-d71e-4e38-b0bc-8af9145f6015
caps.latest.revision: 8
caps.handback.revision: 8
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# O operador &#39;&lt; operador &gt;&#39; deve ter um tipo de retorno booleano
Um operador lógico ou comparação é declarado com um tipo de retorno diferente de [Tipo de dados booliano](../Topic/Boolean%20Data%20Type%20\(Visual%20Basic\).md).  
  
 O resultado de um operador de comparação \(`=`, `<>`, `<`, `<=`, `>`, `>=`, `Is`, `IsNot`, `IsFalse`, `IsTrue`, `Like`, `TypeOf`\) pode ser apenas `True` ou `False`. Para obter mais informações, consulte [Operadores de comparação no Visual Basic](../Topic/Comparison%20Operators%20in%20Visual%20Basic.md).  
  
 Operadores lógicos \(`And`, `AndAlso`, `Not`, `Or`, `OrElse`, `Xor`\) trabalham totalmente dentro do domínio de valores booleanos. Para obter mais informações, consulte [Operadores lógicos e bit a bit no Visual Basic](../Topic/Logical%20and%20Bitwise%20Operators%20in%20Visual%20Basic.md).  
  
 **ID do erro:** BC33023  
  
### Para corrigir este erro  
  
-   Substitua o tipo de retorno dessa comparação ou um operador lógico com `Boolean`.  
  
## Consulte também  
 [Procedimentos do operador](../Topic/Operator%20Procedures%20\(Visual%20Basic\).md)   
 [Instrução Operator](../Topic/Operator%20Statement.md)   
 [Como definir um operador](../Topic/How%20to:%20Define%20an%20Operator%20\(Visual%20Basic\).md)   
 [Como definir um operador de conversão](../Topic/How%20to:%20Define%20a%20Conversion%20Operator%20\(Visual%20Basic\).md)