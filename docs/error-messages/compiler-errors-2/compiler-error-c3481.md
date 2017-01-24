---
title: "C3481 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C3481"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3481"
ms.assetid: 5d09375a-5ed3-4b61-86ed-45e91fd734c7
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3481 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'var': variável de captura lambda não encontrado  
  
 O compilador não pôde localizar a definição de uma variável que é passado para a lista de captura de uma expressão lambda.  
  
### Para corrigir este erro  
  
-   Remova a variável na lista da expressão lambda captura.  
  
## Exemplo  
 O exemplo a seguir gera C3481 porque a variável `n` não está definido:  
  
```  
// C3481.cpp int main() { [n] {}(); // C3481 }  
```  
  
## Consulte também  
 [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)