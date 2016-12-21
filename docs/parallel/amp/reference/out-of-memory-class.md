---
title: "Classe out_of_memory | Microsoft Docs"
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
  - "amprt/Concurrency::out_of_memory"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe out_of_memory"
ms.assetid: 3aa7e682-8f13-4ae6-9188-31fb423956e4
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe out_of_memory
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A exceção que é lançada quando um método falha devido a perda de memória do sistema ou do dispositivo.  
  
## Sintaxe  
  
```  
class out_of_memory : public runtime_exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor out\_of\_memory::out\_of\_memory](../Topic/out_of_memory::out_of_memory%20Constructor.md)|Inicializa uma nova instância da classe `out_of_memory`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `runtime_exception`  
  
 `out_of_memory`  
  
## Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  
  
## Consulte também  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)