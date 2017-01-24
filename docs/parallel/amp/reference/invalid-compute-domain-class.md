---
title: "Classe invalid_compute_domain | Microsoft Docs"
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
  - "amprt/Concurrency::invalid_compute_domain"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe invalid_compute_domain"
ms.assetid: ac7a7166-8bdb-4db1-8caf-ea129ab5117e
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe invalid_compute_domain
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A exceção que é lançada quando o tempo de execução não pode iniciar um kernel usando o domínio de cálculo especificado no site de chamada de [parallel\_for\_each](../Topic/parallel_for_each%20Function%20\(C++%20AMP\).md).  
  
## Sintaxe  
  
```  
class invalid_compute_domain : public runtime_exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor invalid\_compute\_domain::invalid\_compute\_domain](../Topic/invalid_compute_domain::invalid_compute_domain%20Constructor.md)|Inicializa uma nova instância da classe `invalid_compute_domain`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `runtime_exception`  
  
 `invalid_compute_domain`  
  
## Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  
  
## Consulte também  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)