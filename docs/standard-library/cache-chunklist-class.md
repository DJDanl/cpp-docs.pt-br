---
title: "Classe cache_chunklist | Microsoft Docs"
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
  - "allocators/stdext::cache_chunklist"
  - "stdext.cache_chunklist"
  - "stdext::cache_chunklist"
  - "cache_chunklist"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe cache_chunklist"
ms.assetid: af19eccc-4ae7-4a34-bbb2-81e397424cb9
caps.latest.revision: 17
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe cache_chunklist
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define [alocador do bloco](../standard-library/allocators-header.md) que aloca e desaloca blocos de memória de um único tamanho.  
  
## Sintaxe  
  
```  
template <std::size_t Sz, std::size_t Nelts = 20> class cache_chunklist  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Sz`|O número de elementos na matriz a ser atribuído.|  
  
## Comentários  
 Essa classe do modelo usa `operator new` para atribuir as partes de memória bruto, suballocating blocos para atribuir o armazenamento de um bloco de memória quando necessário; armazena blocos de memória livre desalocados em uma lista separada para cada parte, e usa `operator delete` para desalocar uma parte quando nenhum de seus blocos de memória está em uso.  
  
 Cada bloco de memória mantém bytes de `Sz` de memória útil e um ponteiro para a parte que pertence.  Cada parte contém os blocos de memória de `Nelts` , os três ponteiros, um int e os dados que `operator new` e `operator delete` exigem.  
  
### Construtores  
  
|||  
|-|-|  
|[cache\_chunklist](../Topic/cache_chunklist::cache_chunklist.md)|Constrói um objeto de tipo `cache_chunklist`.|  
  
### Funções de membro  
  
|||  
|-|-|  
|[aloque](../Topic/cache_chunklist::allocate.md)|Atribui um bloco de memória.|  
|[desaloque](../Topic/cache_chunklist::deallocate.md)|Libera um número especificado de objetos do início do armazenamento em uma posição especificada.|  
  
## Requisitos  
 alocadores \<de**Cabeçalho:** \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [\<allocators\>](../standard-library/allocators-header.md)