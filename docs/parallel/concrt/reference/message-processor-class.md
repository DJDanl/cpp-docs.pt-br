---
title: "Classe message_processor | Microsoft Docs"
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
  - "agents/concurrency::message_processor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe message_processor"
ms.assetid: 23afb052-daa7-44ed-bf24-d2513db748da
caps.latest.revision: 16
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe message_processor
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `message_processor` é a classe base abstrata para processamento de objetos de `message` .  Não há nenhuma garantia na ordem das mensagens.  
  
## Sintaxe  
  
```  
template<  
   class _Type  
>  
class message_processor;  
```  
  
#### Parâmetros  
 `_Type`  
 O tipo de dados de carga nas mensagens tratadas por esse objeto de `message_processor` .  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`type`|Um alias de tipo para `_Type`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método message\_processor::async\_send](../Topic/message_processor::async_send%20Method.md)|Quando substituído em uma classe derivada, mensagens locais no bloco de forma assíncrona.|  
|[Método message\_processor::sync\_send](../Topic/message_processor::sync_send%20Method.md)|Quando substituído em uma classe derivada, mensagens locais no bloco de forma síncrona.|  
|[Método message\_processor::wait](../Topic/message_processor::wait%20Method.md)|Quando substituído em uma classe derivada, espera para que todas as operações assíncronas serem concluídas.|  
  
### Métodos Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método message\_processor::process\_incoming\_message](../Topic/message_processor::process_incoming_message%20Method.md)|Quando substituído em uma classe derivada, executa o processamento para frente de mensagens em bloco.  Chamado uma vez a cada vez que uma nova mensagem é adicionada e a fila é localizada para estar vazia.|  
  
## Hierarquia de Herança  
 `message_processor`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe ordered\_message\_processor](../Topic/ordered_message_processor%20Class.md)