---
title: "Classe sync_per_thread | Microsoft Docs"
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
  - "stdext::sync_per_thread"
  - "sync_per_thread"
  - "allocators/stdext::sync_per_thread"
  - "stdext.sync_per_thread"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe sync_per_thread"
ms.assetid: 47bf75f8-5b02-4760-b1d3-3099d08fe14c
caps.latest.revision: 19
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe sync_per_thread
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve [filtro de sincronização](../standard-library/allocators-header.md) que fornece um objeto separado de cache para cada thread.  
  
## Sintaxe  
  
```  
template <class Cache> class sync_per_thread  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Cache`|O tipo de cache associado com o filtro de sincronização.  Esse pode ser [cache\_chunklist](../standard-library/cache-chunklist-class.md), [cache\_freelist](../standard-library/cache-freelist-class.md), ou [cache\_suballoc](../standard-library/cache-suballoc-class.md).|  
  
## Comentários  
 Os alocadores que usam `sync_per_thread` podem comparação igual mesmo que os blocos atribuídos em um thread não possam ser desalocado de outro thread.  Quando usar um destes blocos de memória de alocadores atribuídos em um thread não deva ser tornada visível a outros threads.  Na prática isso significa que um contêiner que use um destes alocadores deve ser acessado somente por um thread único.  
  
### Funções de membro  
  
|||  
|-|-|  
|[aloque](../Topic/sync_per_thread::allocate.md)|Atribui um bloco de memória.|  
|[desaloque](../Topic/sync_per_thread::deallocate.md)|Libera um número especificado de objetos do início do armazenamento em uma posição especificada.|  
|[iguais](../Topic/sync_per_thread::equals.md)|Compara dois caches para fins de igualdade.|  
  
## Requisitos  
 alocadores \<de**Cabeçalho:** \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [\<allocators\>](../standard-library/allocators-header.md)