---
title: ".DOSSEG | Microsoft Docs"
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
  - ".DOSSEG"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".DOSSEG directive"
ms.assetid: 175ad470-0a2b-4e2b-b078-65e224fec040
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# .DOSSEG
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Ordena os segmentos de acordo com a convenção de segmento do MS\-DOS: código primeiro, segmentos, em seguida, não no DGROUP e segmentos, em seguida, em DGROUP.  
  
## Sintaxe  
  
```  
  
.DOSSEG  
  
```  
  
## Comentários  
 Os segmentos de DGROUP seguem nesta ordem: segmentos não na pilha, ou de BSS, em seguida, segmentos BSS e, finalmente, os segmentos de pilha.  Usado principalmente para garantir suporte CodeView em programas MASM autônomos.  Mesmo que  [DOSSEG](../../assembler/masm/dosseg.md).  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)