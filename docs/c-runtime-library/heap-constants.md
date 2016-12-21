---
title: "Constantes de heap | Microsoft Docs"
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
  - "_HEAPBADPTR"
  - "_HEAPEMPTY"
  - "_HEAPBADBEGIN"
  - "_HEAPOK"
  - "_HEAPBADNODE"
  - "_HEAPEND"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constantes _HEAPBADBEGIN"
  - "Constantes _HEAPBADNODE"
  - "Constantes _HEAPBADPTR"
  - "Constantes _HEAPEMPTY"
  - "Constantes _HEAPEND"
  - "Constantes _HEAPOK"
  - "constantes de heap"
  - "Constantes HEAPBADBEGIN"
  - "Constantes HEAPBADNODE"
  - "Constantes HEAPBADPTR"
  - "Constantes HEAPEMPTY"
  - "Constantes HEAPEND"
  - "Constantes HEAPOK"
ms.assetid: 3f751bb9-2dc4-486f-b5f5-9061c96d3754
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes de heap
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <malloc.h>  
  
```  
  
## Comentários  
 Essas constantes fornecem o valor de retorno que indica o status do heap.  
  
|Constante|Significado|  
|---------------|-----------------|  
|`_HEAPBADBEGIN`|Informações de cabeçalho inicial não foi encontrada ou não era válido.|  
|`_HEAPBADNODE`|O nó incorreto foi encontrado, ou heap é danificado.|  
|`_HEAPBADPTR`|o campo de**\_pentry** da estrutura de **\_HEAPINFO** não contém o ponteiro válido no heap \(rotina de`_heapwalk` apenas\).|  
|`_HEAPEMPTY`|O heap não foi inicializado.|  
|`_HEAPEND`|A extremidade do heap foi alcançado com êxito \(rotina de`_heapwalk` apenas\).|  
|`_HEAPOK`|O heap é consistente \(`_heapset` e rotinas de `_heapchk` apenas\).  Os erros até agora; a estrutura de **\_HEAPINFO** contém informações sobre a próxima entrada \(rotina de`_heapwalk` apenas\).|  
  
## Consulte também  
 [\_heapchk](../c-runtime-library/reference/heapchk.md)   
 [\_heapset](../c-runtime-library/heapset.md)   
 [\_heapwalk](../Topic/_heapwalk.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)