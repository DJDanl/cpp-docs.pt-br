---
title: "C3488 de erro do compilador | Microsoft Docs"
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
  - "C3488"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3488"
ms.assetid: 0a6fcd76-dd3b-48d7-abb3-22eccda96034
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3488 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'var' não é permitida quando o modo de captura padrão é por referência  
  
 Quando você especifica o modo de captura padrão para uma expressão lambda é por referência, você não pode passar uma variável por referência para a cláusula capture dessa expressão.  
  
### Para corrigir este erro  
  
-   Não passar explicitamente a variável para a cláusula de captura, ou  
  
-   Não especifique por referência como o modo de captura padrão, ou  
  
-   Especifique por valor como o modo de captura padrão, ou  
  
-   Passe a variável pelo valor para a cláusula de captura. \(Isso pode mudar o comportamento da expressão lambda\).  
  
## Exemplo  
 O exemplo a seguir gera C3488 porque uma referência à variável `n` aparece na cláusula de captura de uma expressão lambda cujo modo padrão é por referência:  
  
```  
// C3488a.cpp int main() { int n = 5; [&, &n]() { return n; } (); // C3488 }  
```  
  
## Exemplo  
 O exemplo a seguir mostra quatro possíveis resoluções para C3488:  
  
```  
// C3488b.cpp int main() { int n = 5; // Possible resolution 1: // Do not explicitly pass &n to the capture clause. [&]() { return n; } (); // Possible resolution 2: // Do not specify by-reference as the default capture mode. [&n]() { return n; } (); // Possible resolution 3: // Specify by-value as the default capture mode. [=, &n]() { return n; } (); // Possible resolution 4: // Pass n by value to the capture clause. [n]() { return n; } (); }  
```  
  
## Consulte também  
 [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)