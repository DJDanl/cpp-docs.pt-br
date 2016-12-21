---
title: "C3480 de erro do compilador | Microsoft Docs"
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
  - "C3480"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3480"
ms.assetid: 7b2e055a-9604-4d13-861b-b38bda1a6940
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3480 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'var': uma variável de captura lambda deve ser de um escopo delimitador de função  
  
 A variável de captura lambda não é de um escopo delimitador da função.  
  
### Para corrigir este erro  
  
-   Remova a variável na lista da expressão lambda captura.  
  
## Exemplo  
 O exemplo a seguir gera C3480 porque a variável `global` não está em um escopo delimitador de função:  
  
```  
// C3480a.cpp int global = 0; int main() { [&global] { global = 5; }(); // C3480 }  
```  
  
## Exemplo  
 O exemplo a seguir resolve C3480 removendo a variável `global` na lista da expressão lambda captura:  
  
```  
// C3480b.cpp int global = 0; int main() { [] { global = 5; }(); }  
```  
  
## Consulte também  
 [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)