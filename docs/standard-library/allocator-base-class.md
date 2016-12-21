---
title: "Classe allocator_base | Microsoft Docs"
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
  - "allocators.allocator_base"
  - "stdext.allocators.allocator_base"
  - "allocator_base"
  - "allocators/stdext::allocator_base"
  - "stdext::allocator_base"
  - "stdext::allocators::allocator_base"
  - "allocators/stdext::allocators::allocator_base"
  - "allocators::allocator_base"
  - "stdext.allocator_base"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe allocator_base"
ms.assetid: f920b45f-2a88-4bb0-8ead-b6126b426ed4
caps.latest.revision: 17
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe allocator_base
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define a classe base e funções comuns necessárias para criar um alocador definido pelo usuário de um filtro de sincronização.  
  
## Sintaxe  
  
```  
template <class Type, class Sync> class allocator_base  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Type`|O tipo dos elementos alocada pelo alocador de.|  
|`Sync`|A política de sincronização para o alocador, que é [Classe sync\_none](../standard-library/sync-none-class.md), [Classe sync\_per\_container](../standard-library/sync-per-container-class.md), [Classe sync\_per\_thread](../standard-library/sync-per-thread-class.md), ou [Classe sync\_shared](../Topic/sync_shared%20Class.md).|  
  
### Construtores  
  
|||  
|-|-|  
|[allocator\_base](../Topic/allocator_base::allocator_base.md)|Constrói um objeto do tipo `allocator_base`.|  
  
### Definições de tipo  
  
|||  
|-|-|  
|[const\_pointer](../Topic/allocator_base::const_pointer.md)|Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador de constante.|  
|[const\_reference](../Topic/allocator_base::const_reference.md)|Um tipo que fornece uma referência para o tipo de objeto gerenciado pelo alocador de constante.|  
|[difference\_type](../Topic/allocator_base::difference_type.md)|Um tipo integral assinado que pode representar a diferença entre valores de ponteiros para o tipo de objeto gerenciado pelo alocador de.|  
|[pointer](../Topic/allocator_base::pointer.md)|Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador de.|  
|[referência](../Topic/allocator_base::reference.md)|Um tipo que fornece uma referência para o tipo de objeto gerenciado pelo alocador de.|  
|[size\_type](../Topic/allocator_base::size_type.md)|Um tipo integral não assinado que pode representar o comprimento de qualquer seqüência que um objeto da classe de modelo `allocator_base` pode alocar.|  
|[value\_type](../Topic/allocator_base::value_type.md)|Um tipo que é gerenciado pelo alocador de.|  
  
### Funções membro  
  
|||  
|-|-|  
|[Charalloc](../Topic/allocator_base::_Charalloc.md)|Aloca armazenamento para uma matriz do tipo `char`.|  
|[Chardealloc](../Topic/allocator_base::_Chardealloc.md)|Libera o armazenamento para a matriz que contém elementos do tipo `char`.|  
|[endereço](../Topic/allocator_base::address.md)|Localiza o endereço de um objeto cujo valor é especificado.|  
|[allocate](../Topic/allocator_base::allocate.md)|Aloca um bloco de memória grande o suficiente para armazenar a pelo menos um número especificado de elementos.|  
|[Construir](../Topic/allocator_base::construct.md)|Constrói um tipo específico de objeto em um endereço especificado que é inicializado com um valor especificado.|  
|[desaloque](../Topic/allocator_base::deallocate.md)|Libera um número especificado de objetos desde o início do armazenamento em uma posição especificada.|  
|[destruir](../Topic/allocator_base::destroy.md)|Chama um destruidor de objetos sem desalocar a memória em que o objeto foi armazenado.|  
|[max\_size](../Topic/allocator_base::max_size.md)|Retorna o número de elementos do tipo `Type` que pode ser alocado por um objeto de alocador de classe antes da memória livre é usada.|  
  
## Requisitos  
 **Cabeçalho:** \< alocadores \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [\<allocators\>](../standard-library/allocators-header.md)