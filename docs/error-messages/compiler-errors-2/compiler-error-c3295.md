---
title: "C3295 de erro do compilador | Microsoft Docs"
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
  - "C3295"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3295"
ms.assetid: 83f0aa4d-0e0a-4905-9f66-fcf9991fc07a
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3295 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'\#pragma pragma' só pode ser usada em global ou escopo de namespace  
  
 Alguns pragmas não pode ser usado em uma função.  Consulte [Diretivas Pragma e a palavra\-chave \_\_Pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md) para obter mais informações.  
  
## Exemplo  
 O exemplo a seguir gera C3295.  
  
```  
// C3295.cpp int main() { #pragma managed   // C3295 }  
```