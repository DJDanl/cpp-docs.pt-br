---
title: "Erro de sintaxe no operador cast; dois argumentos separados por v&#237;rgula s&#227;o necess&#225;rios | Microsoft Docs"
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
  - "vbc30944"
  - "bc30944"
helpviewer_keywords: 
  - "BC30944"
ms.assetid: 1f7ed4a1-6ff5-4836-8424-21618c68ff45
caps.latest.revision: 6
caps.handback.revision: 6
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# Erro de sintaxe no operador cast; dois argumentos separados por v&#237;rgula s&#227;o necess&#225;rios
Uma expressão usa a `CType` função de conversão ou `DirectCast` ou `TryCast` palavra\-chave conversão mas fornece somente um argumento.  
  
 `CType`, `DirectCast`, e `TryCast` exigem dois argumentos. A primeira é uma expressão a ser convertida e o segundo é o tipo de dados ou tipo de classe para qual converter.  
  
 **ID do erro:** BC30944  
  
### Para corrigir este erro  
  
-   Fornece os dois argumentos conforme necessário para a conversão.  
  
-   Se você pretende usar um específico [Funções de conversão do tipo](../Topic/Type%20Conversion%20Functions%20\(Visual%20Basic\).md) como `CString`, você deve usar esse nome de função em vez de `CType`. Em seguida, apenas um argumento é necessário.  
  
## Consulte também  
 [Função CType](../Topic/CType%20Function%20\(Visual%20Basic\).md)   
 [Operador DirectCast](../Topic/DirectCast%20Operator%20\(Visual%20Basic\).md)   
 [Operador TryCast](../Topic/TryCast%20Operator%20\(Visual%20Basic\).md)   
 [Funções de conversão do tipo](../Topic/Type%20Conversion%20Functions%20\(Visual%20Basic\).md)