---
title: "Classe cache_suballoc | Microsoft Docs"
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
  - "stdext.cache_suballoc"
  - "allocators/stdext::cache_suballoc"
  - "stdext::cache_suballoc"
  - "cache_suballoc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe cache_suballoc"
ms.assetid: 9ea9c5e9-1dcc-45d0-b3a7-a56a93d88898
caps.latest.revision: 17
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe cache_suballoc
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define um [Bloquear alocador](../standard-library/allocators-header.md) que aloca e desaloca os blocos de memória de um único tamanho.  
  
## Sintaxe  
  
```  
template <std::size_t Sz, size_t Nelts = 20> class cache_suballoc  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Sz`|O número de elementos na matriz a ser alocado.|  
  
## Comentários  
 A classe de modelo cache\_suballoc armazena blocos de memória liberada em uma lista livre com comprimento ilimitado, usando `freelist<sizeof(Type), max_unbounded>`, e suballocates blocos de memória de uma parte maior alocada com `operator new` quando a lista livre está vazia.  
  
 Cada fragmento contém `Sz * Nelts` bytes de memória utilizável e os dados que `operator new` e `operator delete` exigem. Partes alocados nunca são liberados.  
  
### Construtores  
  
|||  
|-|-|  
|[cache\_suballoc](../Topic/cache_suballoc::cache_suballoc.md)|Constrói um objeto do tipo `cache_suballoc`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[allocate](../Topic/cache_suballoc::allocate.md)|Aloca um bloco de memória.|  
|[desalocar](../Topic/cache_suballoc::deallocate.md)|Libera um número especificado de objetos desde o início do armazenamento em uma posição especificada.|  
  
## Requisitos  
 **Cabeçalho:** \< alocadores \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [\<allocators\>](../standard-library/allocators-header.md)