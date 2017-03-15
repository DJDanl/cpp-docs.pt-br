---
title: "LABEL (MASM) | Microsoft Docs"
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
  - "Label"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LABEL directive"
ms.assetid: 39ec44e8-91e6-4f3c-8cf0-b66479974e42
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# LABEL (MASM)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria uma nova etiqueta, atribuindo o valor do contador do local atual e a determinado `type` para  *nome*.  
  
## Sintaxe  
  
```  
  
      name LABEL type  
name LABEL [[NEAR | FAR | PROC]] PTR [[type]]   
```  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)