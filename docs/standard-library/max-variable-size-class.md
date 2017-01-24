---
title: "Classe max_variable_size | Microsoft Docs"
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
  - "stdext::max_variable_size"
  - "allocators/stdext::max_variable_size"
  - "stdext.max_variable_size"
  - "max_variable_size"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe max_variable_size"
ms.assetid: 9f2e9df0-4148-4b37-bc30-f8eca0ef86ae
caps.latest.revision: 18
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe max_variable_size
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um [máxima da classe](../standard-library/allocators-header.md) objeto limita um [freelist](../Topic/freelist%20Class.md) alocar o objeto a um comprimento máximo é de aproximadamente proporcional ao número de blocos de memória.  
  
## Sintaxe  
  
```  
class max_variable_size  
```  
  
### Construtores  
  
|||  
|-|-|  
|[max\_variable\_size](../Topic/max_variable_size::max_variable_size.md)|Constrói um objeto do tipo `max_variable_size`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[alocado](../Topic/max_variable_size::allocated.md)|Incrementa a contagem de blocos de memória alocada.|  
|[desalocada](../Topic/max_variable_size::deallocated.md)|Diminui a contagem de alocar blocos de memória.|  
|[completo](../Topic/max_variable_size::full.md)|Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.|  
|[lançado](../Topic/max_variable_size::released.md)|Diminui a contagem de memória bloqueia na lista livre.|  
|[salvo](../Topic/max_variable_size::saved.md)|Incrementa a contagem de blocos de memória na lista livre.|  
  
## Requisitos  
 **Cabeçalho:** \< alocadores \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [\<allocators\>](../standard-library/allocators-header.md)