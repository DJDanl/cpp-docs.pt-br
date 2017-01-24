---
title: "C3495 de erro do compilador | Microsoft Docs"
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
  - "C3495"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3495"
ms.assetid: 1fd40cb8-8373-403d-b8a8-f08424a50807
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3495 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'var': uma captura lambda deve ter duração automática de armazenamento  
  
 Não será possível capturar uma variável que não tem duração de armazenamento automático, como uma variável que está marcado como `static` ou `extern`.  
  
### Para corrigir este erro  
  
-   Não transmita um `static` ou `extern` variável à lista de captura da expressão lambda.  
  
## Exemplo  
 O exemplo a seguir gera C3495 porque o `static` variável `n` aparece na lista de captura de uma expressão lambda:  
  
```  
// C3495.cpp int main() { static int n = 66; [&n]() { return n; }(); // C3495 }  
```  
  
## Consulte também  
 [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)   
 [\(NOTINBUILD\) Especificadores de classe de armazenamento](http://msdn.microsoft.com/pt-br/10b3d22d-cb40-450b-994b-08cf9a211b6c)