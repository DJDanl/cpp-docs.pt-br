---
title: "Classe unsupported_feature | Microsoft Docs"
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
  - "amprt/Concurrency::unsupported_feature"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe unsupported_feature"
ms.assetid: 6b1ab917-df13-48c7-9648-7cb2465a0ff5
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe unsupported_feature
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A exceção que é lançada quando um recurso sem suporte é usado.  
  
## Sintaxe  
  
```  
class unsupported_feature : public runtime_exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor unsupported\_feature::unsupported\_feature](../Topic/unsupported_feature::unsupported_feature%20Constructor.md)|Constrói uma nova instância da exceção `unsupported_feature`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `runtime_exception`  
  
 `unsupported_feature`  
  
## Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  
  
## Consulte também  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)