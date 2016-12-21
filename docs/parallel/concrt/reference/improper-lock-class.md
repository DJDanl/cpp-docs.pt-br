---
title: "Classe improper_lock | Microsoft Docs"
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
  - "concrt/concurrency::improper_lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe improper_lock"
ms.assetid: 8f494942-7748-4a2a-8de2-23414bfe6346
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe improper_lock
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção lançada quando um bloqueio é adquirido de forma incorreta.  
  
## Sintaxe  
  
```  
class improper_lock : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor improper\_lock::improper\_lock](../Topic/improper_lock::improper_lock%20Constructor.md)|Sobrecarregado.  Constrói um `improper_lock exception`.|  
  
## Comentários  
 Normalmente, essa exceção será gerada quando é realizada uma tentativa para adquirir um bloqueio recursivamente não reentrante no mesmo contexto.  
  
## Hierarquia de Herança  
 `exception`  
  
 `improper_lock`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe critical\_section](../../../parallel/concrt/reference/critical-section-class.md)   
 [Classe reader\_writer\_lock](../Topic/reader_writer_lock%20Class.md)