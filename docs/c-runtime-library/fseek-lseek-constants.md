---
title: "Constantes fseek, _lseek | Microsoft Docs"
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
  - "SEEK_END"
  - "SEEK_SET"
  - "SEEK_CUR"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante SEEK_CUR"
  - "Constante SEEK_END"
  - "Constante SEEK_SET"
ms.assetid: 9deeb13e-5aa3-4c33-80d8-721c80a4de9d
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes fseek, _lseek
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <stdio.h>  
  
```  
  
## Comentários  
 O argumento *de origem* especifica a posição inicial e pode ser uma das seguintes constantes manifestas:  
  
|Constante|Significado|  
|---------------|-----------------|  
|`SEEK_END`|Fim de arquivo|  
|`SEEK_CUR`|A posição atual do ponteiro de arquivo|  
|`SEEK_SET`|Início do arquivo|  
  
## Consulte também  
 [fseek, \_fseeki64](../c-runtime-library/reference/fseek-fseeki64.md)   
 [\_lseek, \_lseeki64](../c-runtime-library/reference/lseek-lseeki64.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)