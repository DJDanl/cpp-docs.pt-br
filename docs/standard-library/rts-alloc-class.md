---
title: "Classe rts_alloc | Microsoft Docs"
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
  - "stdext::rts_alloc"
  - "allocators/stdext::rts_alloc"
  - "rts_alloc"
  - "stdext.rts_alloc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe rts_alloc"
ms.assetid: ab41bffa-83d1-4a1c-87b9-5707d516931f
caps.latest.revision: 19
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe rts_alloc
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve a classe de modelo de rts\_alloc um[filtro](../standard-library/allocators-header.md)que contém uma matriz de cache instâncias e determina qual instância a ser usado para alocação e desalocação em tempo de execução, em vez de em tempo de compilação.  
  
## Sintaxe  
  
```  
template <class Cache> class rts_alloc  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Cache`|O tipo de instâncias de cache contidos na matriz.  Isso pode ser[Classe cache\_chunklist](../standard-library/cache-chunklist-class.md)[cache\_freelist](../standard-library/cache-freelist-class.md)ou[cache\_suballoc](../standard-library/cache-suballoc-class.md).|  
  
## Comentários  
 Essa classe de modelo contém blocos de várias instâncias do alocador e determina qual instância a ser usado para alocação ou desalocação em tempo de execução, em vez de em tempo de compilação.  Ele é usado com os compiladores que não é possível compilar reassociar.  
  
### Funções membro  
  
|||  
|-|-|  
|[allocate](../Topic/rts_alloc::allocate.md)|Aloca um bloco de memória.|  
|[desaloque](../Topic/rts_alloc::deallocate.md)|Libera um número especificado de objetos desde o início do armazenamento em uma posição especificada.|  
|[igual a](../Topic/rts_alloc::equals.md)|Compara dois caches de igualdade.|  
  
## Requisitos  
 **Cabeçalho:**\< alocadores \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [ALLOCATOR\_DECL](../Topic/ALLOCATOR_DECL%20\(%3Callocators%3E\).md)   
 [\<allocators\>](../standard-library/allocators-header.md)