---
title: "C3493 de erro do compilador | Microsoft Docs"
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
  - "C3493"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3493"
ms.assetid: 734b4257-12a3-436f-8488-c8c55ec81634
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3493 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'var' não pode ser capturada implicitamente porque nenhum modo de captura padrão foi especificado  
  
 A captura de expressão lambda vazio, `[]`, especifica que a expressão lambda não não explicitamente ou implicitamente capturar quaisquer variáveis.  
  
### Para corrigir este erro  
  
-   Fornecer um modo de captura padrão, ou  
  
-   Capture explicitamente uma ou mais variáveis.  
  
## Exemplo  
 O exemplo a seguir gera C3493 porque ele modifica uma variável externa, mas Especifica a cláusula capture vazia:  
  
```  
// C3493a.cpp int main() { int m = 55; [](int n) { m = n; }(99); // C3493 }  
```  
  
## Exemplo  
 O exemplo a seguir resolve C3493 especificando por referência como o modo de captura padrão.  
  
```  
// C3493b.cpp int main() { int m = 55; [&](int n) { m = n; }(99); }  
```  
  
## Consulte também  
 [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)