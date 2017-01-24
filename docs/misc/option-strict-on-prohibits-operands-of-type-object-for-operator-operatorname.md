---
title: "Option Strict On pro&#237;be operandos do tipo objeto para o operador &#39;&lt; operatorname &gt;&#39; | Microsoft Docs"
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
  - "bc30038"
  - "vbc30038"
helpviewer_keywords: 
  - "BC30038"
ms.assetid: eb047d36-1fb4-460d-ae98-c76f31a89bed
caps.latest.revision: 8
caps.handback.revision: 8
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# Option Strict On pro&#237;be operandos do tipo objeto para o operador &#39;&lt; operatorname &gt;&#39;
Somente operadores definidos para as variáveis de objeto são `Is` e `TypeOf...Is`. Quando `Option Strict` é `On`, todos os operandos devem ser de tipos de dados definidos para determinado operador.  
  
 **ID do erro:** BC30038  
  
### Para corrigir este erro  
  
-   Use as funções de conversão de tipo apropriado, como `CInt` ou `CStr`, para converter os operandos para tipos de dados definidos para o operador.  
  
## Consulte também  
 [Operador Is](../Topic/Is%20Operator%20\(Visual%20Basic\).md)   
 [Operadores de comparação no Visual Basic](../Topic/Comparison%20Operators%20in%20Visual%20Basic.md)   
 [Funções de conversão do tipo](../Topic/Type%20Conversion%20Functions%20\(Visual%20Basic\).md)