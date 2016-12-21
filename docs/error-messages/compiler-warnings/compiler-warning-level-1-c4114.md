---
title: "Aviso do compilador (n&#237;vel 1) C4114 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4114"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4114"
ms.assetid: 3983e1c6-e8bb-46dc-8894-e1827db48797
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4114
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o mesmo qualificador de tipo usado mais de uma vez  
  
 Uma declaração ou uma definição do tipo usam um qualificador de tipo \(**const**, `volatile`, **signed**, ou\) `unsigned`mais de uma vez.  Isso causa um aviso com extensões da Microsoft \(\/Ze\) e um erro na compatibilidade ANSI \(\/Za\).  
  
 O seguinte exemplo gera C4114:  
  
```  
// C4114.cpp  
// compile with: /W1 /c  
volatile volatile int i;   // C4114  
```  
  
 O seguinte exemplo gera C4114:  
  
```  
// C4114_b.cpp  
// compile with: /W1 /c  
static const int const * ii;   // C4114  
static const int * const iii;   // OK  
```