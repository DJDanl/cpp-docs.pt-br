---
title: "Classe unsupported_os | Microsoft Docs"
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
  - "concrt/concurrency::unsupported_os"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe unsupported_os"
ms.assetid: 6fa57636-341b-4b51-84cc-261d283ff736
caps.latest.revision: 20
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe unsupported_os
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção acionada quando um sistema operacional sem suporte é usado.  
  
## Sintaxe  
  
```  
class unsupported_os : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor unsupported\_os::unsupported\_os](../Topic/unsupported_os::unsupported_os%20Constructor.md)|Sobrecarregado.  Constrói um objeto `unsupported_os`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `unsupported_os`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)