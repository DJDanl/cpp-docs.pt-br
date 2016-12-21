---
title: "Classe max_unbounded | Microsoft Docs"
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
  - "allocators/stdext::max_unbounded"
  - "stdext::max_unbounded"
  - "stdext.max_unbounded"
  - "max_unbounded"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe max_unbounded"
ms.assetid: e34627a9-c231-4031-a483-cbb0514fff46
caps.latest.revision: 18
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe max_unbounded
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um [máxima da classe](../standard-library/allocators-header.md) objeto que não limita o tamanho máximo de um [freelist](../Topic/freelist%20Class.md) objeto.  
  
## Sintaxe  
  
```  
class max_unbounded  
```  
  
### Funções membro  
  
|||  
|-|-|  
|[alocado](../Topic/max_unbounded::allocated.md)|Incrementa a contagem de blocos de memória alocada.|  
|[desalocada](../Topic/max_unbounded::deallocated.md)|Diminui a contagem de alocar blocos de memória.|  
|[completo](../Topic/max_unbounded::full.md)|Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.|  
|[lançado](../Topic/max_unbounded::released.md)|Diminui a contagem de memória bloqueia na lista livre.|  
|[salvo](../Topic/max_unbounded::saved.md)|Incrementa a contagem de blocos de memória na lista livre.|  
  
## Requisitos  
 **Cabeçalho:** \< alocadores \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [\<allocators\>](../standard-library/allocators-header.md)