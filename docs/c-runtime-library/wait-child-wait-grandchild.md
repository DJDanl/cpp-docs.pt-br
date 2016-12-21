---
title: "_WAIT_CHILD, _WAIT_GRANDCHILD | Microsoft Docs"
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
  - "_WAIT_GRANDCHILD"
  - "WAIT_CHILD"
  - "WAIT_GRANDCHILD"
  - "_WAIT_CHILD"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _WAIT_CHILD"
  - "Constante _WAIT_GRANDCHILD"
  - "Constante WAIT_CHILD"
  - "Constante WAIT_GRANDCHILD"
ms.assetid: 7acd96fa-d118-4339-bb00-e5afaf286945
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _WAIT_CHILD, _WAIT_GRANDCHILD
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <process.h>  
  
```  
  
## Comentários  
 A função de `_cwait` pode ser usada por qualquer processo para aguardar qualquer outro processo \(se a ID do processo é conhecido\).  O argumento de ação pode ser um dos seguintes valores:  
  
|Constante|Significado|  
|---------------|-----------------|  
|`_WAIT_CHILD`|As esperas do processo de chamada até o novo processo especificado será encerrado.|  
|`_WAIT_GRANDCHILD`|As esperas do processo de chamada até novo processo especificado, e todos os processos criados por esse novo processo, será encerrado.|  
  
## Consulte também  
 [\_cwait](../c-runtime-library/reference/cwait.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)