---
title: "Classe auto_partitioner | Microsoft Docs"
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
  - "ppl/concurrency::auto_partitioner"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe auto_partitioner"
ms.assetid: 7cc08e5d-20b4-47a4-b4b5-c214a78f5a9e
caps.latest.revision: 8
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe auto_partitioner
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `auto_partitioner` representa o método padrão `parallel_for`, `parallel_for_each` e uso de `parallel_transform` dividir o intervalo a iteração por.  Este método de intervalo de employes de particionamento que rouba para o balanceamento de carga bem como itera pelo cancelamento.  
  
## Sintaxe  
  
```  
class auto_partitioner;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor auto\_partitioner::auto\_partitioner](../Topic/auto_partitioner::auto_partitioner%20Constructor.md)|Constrói um objeto `auto_partitioner`.|  
|[Destruidor auto\_partitioner::~auto\_partitioner](../Topic/auto_partitioner::~auto_partitioner%20Destructor.md)|Destrói um objeto de `auto_partitioner` .|  
  
## Hierarquia de Herança  
 `auto_partitioner`  
  
## Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)