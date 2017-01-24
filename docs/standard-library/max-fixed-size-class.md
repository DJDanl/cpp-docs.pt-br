---
title: "Classe max_fixed_size | Microsoft Docs"
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
  - "allocators/stdext::max_fixed_size"
  - "max_fixed_size"
  - "stdext::max_fixed_size"
  - "stdext.max_fixed_size"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe max_fixed_size"
ms.assetid: 8c8f4588-37e9-4579-8168-ba3553800914
caps.latest.revision: 18
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe max_fixed_size
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto de [classe max](../standard-library/allocators-header.md) que limita um objeto de [freelist](../Topic/freelist%20Class.md) a um comprimento máximo fixo.  
  
## Sintaxe  
  
```  
template <std::size_t Max> class max_fixed_size  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Max`|A classe máxima que determina o número máximo de elementos armazenar em `freelist`.|  
  
### Construtores  
  
|||  
|-|-|  
|[max\_fixed\_size](../Topic/max_fixed_size::max_fixed_size.md)|Constrói um objeto de tipo `max_fixed_size`.|  
  
### Funções de membro  
  
|||  
|-|-|  
|[atribuído](../Topic/max_fixed_size::allocated.md)|Incrementa a contagem de blocos de memória alocado.|  
|[desalocado](../Topic/max_fixed_size::deallocated.md)|Diminui a contagem de blocos de memória alocado.|  
|[completamente](../Topic/max_fixed_size::full.md)|Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.|  
|[liberado](../Topic/max_fixed_size::released.md)|Diminui a contagem de blocos de memória livre na lista.|  
|[salvo](../Topic/max_fixed_size::saved.md)|Incrementa a contagem de blocos de memória livre na lista.|  
  
## Requisitos  
 alocadores \<de**Cabeçalho:** \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [\<allocators\>](../standard-library/allocators-header.md)