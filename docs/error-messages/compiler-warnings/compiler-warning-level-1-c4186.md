---
title: "Compilador C4186 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4186"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4186"
ms.assetid: caf3f7d8-f305-426b-8d4e-2b96f5c269ea
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4186 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

atributo \#import 'attribute' requer argumentos de contagem; ignorado  
  
 Um `#import` atributo tem um número incorreto de argumentos.  
  
## Exemplo  
  
```  
// C4186.cpp // compile with: /W1 /c #import "stdole2.tlb" no_namespace("abc") rename("a","b","c")  // C4186  
```  
  
 O `no_namespace` atributo não utiliza argumentos. O **Renomear** atributo leva apenas dois argumentos.