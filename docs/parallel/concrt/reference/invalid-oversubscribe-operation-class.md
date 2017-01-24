---
title: "Classe invalid_oversubscribe_operation | Microsoft Docs"
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
  - "concrt/concurrency::invalid_oversubscribe_operation"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe invalid_oversubscribe_operation"
ms.assetid: 0a9c5f08-d5e6-4ad0-90a9-517472b3ac28
caps.latest.revision: 19
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe invalid_oversubscribe_operation
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção gerada quando o método de `Context::Oversubscribe` for chamado com o parâmetro de `_BeginOversubscription` definido como `false` sem uma chamada anterior ao método de `Context::Oversubscribe` com o parâmetro de `_BeginOversubscription` definido como `true`.  
  
## Sintaxe  
  
```  
class invalid_oversubscribe_operation : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor invalid\_oversubscribe\_operation::invalid\_oversubscribe\_operation](../Topic/invalid_oversubscribe_operation::invalid_oversubscribe_operation%20Constructor.md)|Sobrecarregado.  Constrói um objeto `invalid_oversubscribe_operation`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `invalid_oversubscribe_operation`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Método Context::Oversubscribe](../Topic/Context::Oversubscribe%20Method.md)