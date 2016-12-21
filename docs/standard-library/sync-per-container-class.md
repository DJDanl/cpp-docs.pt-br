---
title: "Classe sync_per_container | Microsoft Docs"
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
  - "stdext.sync_per_container"
  - "sync_per_container"
  - "stdext::sync_per_container"
  - "allocators/stdext::sync_per_container"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe sync_per_container"
ms.assetid: 0b4b2904-b668-4d94-a422-d4f919cbffab
caps.latest.revision: 21
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe sync_per_container
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve [filtro de sincronização](../standard-library/allocators-header.md) que fornece um objeto separado de cache para cada objeto do alocador.  
  
## Sintaxe  
  
```  
template <class Cache> class sync_per_container  
    : public Cache  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Cache`|O tipo de cache associado com o filtro de sincronização.  Esse pode ser [cache\_chunklist](../standard-library/cache-chunklist-class.md), [cache\_freelist](../standard-library/cache-freelist-class.md), ou [cache\_suballoc](../standard-library/cache-suballoc-class.md).|  
  
### Funções de membro  
  
|||  
|-|-|  
|[iguais](../Topic/sync_per_container::equals.md)|Compara dois caches para fins de igualdade.|  
  
## Requisitos  
 alocadores \<de**Cabeçalho:** \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [\<allocators\>](../standard-library/allocators-header.md)