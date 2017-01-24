---
title: "C3489 de erro do compilador | Microsoft Docs"
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
  - "C3489"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3489"
ms.assetid: 47b58d69-459d-4499-abc7-5f0b9303d773
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3489 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'var' é necessário quando o modo de captura padrão é por valor  
  
 Quando você especifica o modo de captura padrão para uma expressão lambda é por valor, você não pode passar uma variável pelo valor para a cláusula capture dessa expressão.  
  
### Para corrigir este erro  
  
-   Não passar explicitamente a variável para a cláusula de captura, ou  
  
-   Não especifique por valor como o modo de captura padrão, ou  
  
-   Especifique por referência como o modo de captura padrão, ou  
  
-   A variável é passada por referência para a cláusula de captura. \(Isso pode mudar o comportamento da expressão lambda\).  
  
## Exemplo  
 O exemplo a seguir gera a variável C3489 `n` é exibida pelo valor na cláusula de captura de uma expressão lambda cujo modo padrão é por valor:  
  
```  
// C3489a.cpp int main() { int n = 5; [=, n]() { return n; } (); // C3489 }  
```  
  
## Exemplo  
 O exemplo a seguir mostra quatro possíveis resoluções para C3489:  
  
```  
// C3489b.cpp int main() { int n = 5; // Possible resolution 1: // Do not explicitly pass n to the capture clause. [=]() { return n; } (); // Possible resolution 2: // Do not specify by-value as the default capture mode. [n]() { return n; } (); // Possible resolution 3: // Specify by-reference as the default capture mode. [&, n]() { return n; } (); // Possible resolution 4: // Pass n by reference to the capture clause. [&n]() { return n; } (); }  
```  
  
## Consulte também  
 [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)