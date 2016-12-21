---
title: "C3452 de erro do compilador | Microsoft Docs"
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
  - "C3452"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3452"
ms.assetid: e5293dcf-cb70-4133-ae2a-0bb496950ba0
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3452 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

membro de argumento da lista não constante  
  
 Um argumento foi passado para um atributo que espera uma constante, um valor que pode ser avaliada em tempo de compilação.  
  
## Exemplo  
 O exemplo a seguir gera C3452.  
  
```  
// C3452.cpp // compile with: /c int i; [module( name="mod", type=dll, custom={i} ) ];   // C3452 // try the following line instead // [module( name="mod", type=dll, custom={"a"} ) ];  
```