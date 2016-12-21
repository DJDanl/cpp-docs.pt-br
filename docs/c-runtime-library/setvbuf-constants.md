---
title: "Constantes setvbuf | Microsoft Docs"
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
  - "_IOFBF"
  - "_IONBF"
  - "_IOLBF"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _IOFBF"
  - "Constante _IOLBF"
  - "Constante _IONBF"
  - "Constante IOFBF"
  - "Constante IOLBF"
  - "Constante IONBF"
ms.assetid: a6ec4dd5-1f24-498c-871a-e874cd28d33c
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes setvbuf
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <stdio.h>  
  
```  
  
## Comentários  
 Essas constantes representam o tipo de buffer para `setvbuf`.  
  
 Os valores possíveis são dados por seguintes constantes manifestas:  
  
|Constante|Significado|  
|---------------|-----------------|  
|`_IOFBF`|Proteção completa: O buffer especificado na chamada de `setvbuf` é usado e seu tamanho é como especificado na chamada de `setvbuf` .  Se o ponteiro de buffer é **nulo**, o buffer atribuído automaticamente o tamanho especificado será usado.|  
|`_IOLBF`|Mesmo que `_IOFBF`.|  
|`_IONBF`|Nenhum buffer é usado, independentemente dos argumentos na chamada de `setvbuf`.|  
  
## Consulte também  
 [setbuf](../c-runtime-library/reference/setbuf.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)