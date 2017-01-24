---
title: "Classe scheduler_resource_allocation_error | Microsoft Docs"
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
  - "concrt/concurrency::scheduler_resource_allocation_error"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe scheduler_resource_allocation_error"
ms.assetid: 8b40449a-7abb-4d0a-bb85-c0e9a495ae97
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe scheduler_resource_allocation_error
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção lançada por causa de uma falha adquirir um recurso crítico no tempo de execução de simultaneidade.  
  
## Sintaxe  
  
```  
class scheduler_resource_allocation_error : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor scheduler\_resource\_allocation\_error::scheduler\_resource\_allocation\_error](../Topic/scheduler_resource_allocation_error::scheduler_resource_allocation_error%20Constructor.md)|Sobrecarregado.  Constrói um objeto `scheduler_resource_allocation_error`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método scheduler\_resource\_allocation\_error::get\_error\_code](../Topic/scheduler_resource_allocation_error::get_error_code%20Method.md)|Retorna o código de erro que causou a exceção.|  
  
## Comentários  
 Esta exceção é lançada normalmente quando uma chamada para o sistema operacional de no tempo de execução de simultaneidade falha.  O código de erro que normalmente seria retornado de uma chamada para o método `GetLastError` do Win32 é convertido em um valor do tipo `HRESULT` e pode ser recuperada usando o método de `get_error_code` .  
  
## Hierarquia de Herança  
 `exception`  
  
 `scheduler_resource_allocation_error`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)