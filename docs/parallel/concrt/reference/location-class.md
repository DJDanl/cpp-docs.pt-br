---
title: "Classe location | Microsoft Docs"
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
  - "concrt/concurrency::location"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de local"
ms.assetid: c3289f51-5bf1-4dff-a18d-d0dab8e5d9c7
caps.latest.revision: 10
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe location
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Uma abstração de uma localização física em hardware.  
  
## Sintaxe  
  
```  
class location;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor location::location](../Topic/location::location%20Constructor.md)|Sobrecarregado.  Constrói um objeto `location`.|  
|[Destruidor location::~location](../Topic/location::~location%20Destructor.md)|Destrói um objeto de `location` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método location::current](../Topic/location::current%20Method.md)|Retorna um objeto de `location` que representa o local em que o mais específico o thread de chamada está em execução.|  
|[Método location::from\_numa\_node](../Topic/location::from_numa_node%20Method.md)|Retorna um objeto de `location` que representa um nó EM UMA especificado.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador location::operator\!\=](../Topic/location::operator!=%20Operator.md)|Determina se dois objetos de `location` representam o local diferente.|  
|[Operador location::operator\=](../Topic/location::operator=%20Operator.md)|Atribui o conteúdo de um objeto diferente de `location` para este.|  
|[Operador location::operator\=\=](../Topic/location::operator==%20Operator.md)|Determina se dois objetos de `location` representam o mesmo local.|  
  
## Hierarquia de Herança  
 `location`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)