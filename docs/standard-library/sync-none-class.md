---
title: "Classe sync_none | Microsoft Docs"
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
  - "stdext.sync_none"
  - "sync_none"
  - "allocators/stdext::sync_none"
  - "stdext::sync_none"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe sync_none"
ms.assetid: f7473cee-14f3-4fe1-88bc-68cd085e59e1
caps.latest.revision: 21
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe sync_none
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve [filtro de sincronização](../standard-library/allocators-header.md) que não fornece nenhuma sincronização.  
  
## Sintaxe  
  
```  
template <class Cache> class sync_none  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Cache`|O tipo de cache associado com o filtro de sincronização.  Esse pode ser [cache\_chunklist](../standard-library/cache-chunklist-class.md), [cache\_freelist](../standard-library/cache-freelist-class.md), ou [cache\_suballoc](../standard-library/cache-suballoc-class.md).|  
  
### Funções de membro  
  
|||  
|-|-|  
|[aloque](../Topic/sync_none::allocate.md)|Atribui um bloco de memória.|  
|[desaloque](../Topic/sync_none::deallocate.md)|Libera um número especificado de objetos do início do armazenamento em uma posição especificada.|  
|[iguais](../Topic/sync_none::equals.md)|Compara dois caches para fins de igualdade.|  
  
## Requisitos  
 alocadores \<de**Cabeçalho:** \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [\<allocators\>](../standard-library/allocators-header.md)