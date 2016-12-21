---
title: "Classe cache_freelist | Microsoft Docs"
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
  - "stdext.cache_freelist"
  - "allocators/stdext::cache_freelist"
  - "stdext::cache_freelist"
  - "cache_freelist"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe cache_freelist"
ms.assetid: 840694de-36ba-470f-8dae-2b723d5a8cd9
caps.latest.revision: 19
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe cache_freelist
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define um [Bloquear alocador](../standard-library/allocators-header.md) que aloca e desaloca os blocos de memória de um único tamanho.  
  
## Sintaxe  
  
```  
template <std::size_t Sz, class Max> class cache_freelist  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Sz`|O número de elementos na matriz a ser alocado.|  
|`Max`|A classe max que representa o tamanho máximo da lista livre. Isso pode ser [max\_fixed\_size](../standard-library/max-fixed-size-class.md), [max\_none](../Topic/max_none%20Class.md), [max\_unbounded](../standard-library/max-unbounded-class.md), ou [max\_variable\_size](../standard-library/max-variable-size-class.md).|  
  
## Comentários  
 A classe de modelo cache\_freelist mantém uma lista livre de blocos de memória de tamanho `Sz`. Quando a lista livre estiver completa, ele usa `operator delete` desalocar memória bloqueia. Quando a lista livre estiver vazia, ele usa `operator new` para alocar novos blocos de memória. O tamanho máximo da lista livre é determinado pela classe de classe max passado a `Max` parâmetro.  
  
 Cada bloco de memória contém `Sz` bytes de memória utilizável e os dados que `operator new` e `operator delete` exigem.  
  
### Construtores  
  
|||  
|-|-|  
|[cache\_freelist](../Topic/cache_freelist::cache_freelist.md)|Constrói um objeto do tipo `cache_freelist`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[allocate](../Topic/cache_freelist::allocate.md)|Aloca um bloco de memória.|  
|[desalocar](../Topic/cache_freelist::deallocate.md)|Libera um número especificado de objetos desde o início do armazenamento em uma posição especificada.|  
  
## Requisitos  
 **Cabeçalho:** \< alocadores \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [\<allocators\>](../standard-library/allocators-header.md)