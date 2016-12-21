---
title: "Classe uninitialized_object | Microsoft Docs"
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
  - "amprt/Concurrency::uninitialized_object"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe uninitialized_object"
ms.assetid: 6ae3c4e8-64a6-4511-a158-03be197b63af
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe uninitialized_object
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A exceção que é lançada quando um objeto não inicializado é usado.  
  
## Sintaxe  
  
```  
class uninitialized_object : public runtime_exception;  
  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor uninitialized\_object::uninitialized\_object](../Topic/uninitialized_object::uninitialized_object%20Constructor.md)|Inicializa uma nova instância da classe `uninitialized_object`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `runtime_exception`  
  
 `uninitialized_object`  
  
## Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  
  
## Consulte também  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)