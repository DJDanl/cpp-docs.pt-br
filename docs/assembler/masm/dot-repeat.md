---
title: ".REPEAT | Microsoft Docs"
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
  - ".REPEAT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".REPEAT directive"
ms.assetid: cb8ad8c6-587b-42f9-a0ad-b5316a24918c
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# .REPEAT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gera o código que repete a execução do bloco de  *instruções*  até `condition` se torne verdadeira.  [.UNTILCXZ](../../assembler/masm/dot-untilcxz.md), que se torne verdadeira quando CX é zero, pode ser substituído por  [.Até que](../../assembler/masm/dot-until.md).  O `condition` é opcional com  **.UNTILCXZ**.  
  
## Sintaxe  
  
```  
  
   .REPEAT  
statements  
.UNTIL condition  
```  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)