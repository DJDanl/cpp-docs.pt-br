---
title: "Classe invalid_link_target | Microsoft Docs"
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
  - "concrt/concurrency::invalid_link_target"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe invalid_link_target"
ms.assetid: 33b64885-34d8-4d4e-a893-02e9f19c958e
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe invalid_link_target
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção gerada quando o método de `link_target` de um bloco da mensagem é chamado e o bloco da mensagem é incapaz de vincular ao destino.  Esse pode ser o resultado de exceder o número de links que o bloco da mensagem é permitido ou tentativa de vincular duas vezes em um destino específico para a mesma origem.  
  
## Sintaxe  
  
```  
class invalid_link_target : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor invalid\_link\_target::invalid\_link\_target](../Topic/invalid_link_target::invalid_link_target%20Constructor.md)|Sobrecarregado.  Constrói um objeto `invalid_link_target`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `invalid_link_target`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md)