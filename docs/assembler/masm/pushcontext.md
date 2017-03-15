---
title: "PUSHCONTEXT | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "PUSHCONTEXT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PUSHCONTEXT directive"
ms.assetid: 18e528ee-df6c-4ce6-8823-b35b40f757fd
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# PUSHCONTEXT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Salva a parte ou todo o atual `context`: registrador de segmento assume valor fracionário, sinalizadores de listagem e cref ou valores de processador\/coprocessador.  The `context` can be **ASSUMES**, `RADIX`, **LISTING**, **CPU**, or **ALL**.  
  
## Sintaxe  
  
```  
  
PUSHCONTEXT context  
```  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)