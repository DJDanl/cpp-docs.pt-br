---
title: "Erro do Compilador C2588 | Microsoft Docs"
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
  - "C2588"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2588"
ms.assetid: 19a0cabd-ca13-44a5-9be3-ee676abf9bc4
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2588
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“mais ::~identifier”: destruidor global ilegal  
  
 O destruidor é definido para algo diferente de uma classe, uma estrutura, ou uma união.  Isso não é permitido.  
  
 Esse erro pode ser causado por uma classe, uma estrutura, ou por um nome ausente de união no lado esquerdo do operador de resolução de escopo \(`::`\).  
  
 O seguinte exemplo gera C2588:  
  
```  
// C2588.cpp  
~F();   // C2588  
```