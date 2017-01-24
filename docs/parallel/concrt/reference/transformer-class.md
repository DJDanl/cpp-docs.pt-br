---
title: "Classe transformer | Microsoft Docs"
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
  - "agents/concurrency::transformer"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe transformer"
ms.assetid: eea71925-7043-4a92-bfd4-dbc0ece5d081
caps.latest.revision: 22
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe transformer
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Um bloco da mensagem de `transformer` é um único destino, várias origem, `propagator_block` ordenado que podem aceitar mensagens de um tipo e é capaz de armazenar um número ilimitado de mensagens de um tipo diferente.  
  
## Sintaxe  
  
```  
template<  
   class _Input,  
   class _Output  
>  
class transformer : public propagator_block<single_link_registry<ITarget<_Output>>, multi_link_registry<ISource<_Input>>>;  
```  
  
#### Parâmetros  
 `_Input`  
 O tipo de carga útil de mensagens aceitas pelo buffer.  
  
 `_Output`  
 O tipo de carga útil de mensagens armazenadas e propagadas para fora por buffer.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor transformer::transformer](../Topic/transformer::transformer%20Constructor.md)|Sobrecarregado.  Constrói um bloco da mensagem de `transformer` .|  
|[Destruidor transformer::~transformer](../Topic/transformer::~transformer%20Destructor.md)|Destrói o bloco da mensagem de `transformer` .|  
  
### Métodos Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método transformer::accept\_message](../Topic/transformer::accept_message%20Method.md)|Aceita uma mensagem que é oferecida por esse bloco da mensagem de `transformer` , transferindo propriedade ao chamador.|  
|[Método transformer::consume\_message](../Topic/transformer::consume_message%20Method.md)|Consome uma mensagem anteriormente oferecida por `transformer` e reservada pelo destino, transferindo propriedade ao chamador.|  
|[Método transformer::link\_target\_notification](../Topic/transformer::link_target_notification%20Method.md)|Um retorno de chamada que notifica que um novo destino esteve vinculado a esse bloco da mensagem de `transformer` .|  
|[Método transformer::propagate\_message](../Topic/transformer::propagate_message%20Method.md)|Passa de forma assíncrona uma mensagem de um bloco de `ISource` a esse bloco da mensagem de `transformer` .  É invocado pelo método de `propagate` , quando chamado por um bloco de origem.|  
|[Método transformer::propagate\_to\_any\_targets](../Topic/transformer::propagate_to_any_targets%20Method.md)|Executa a função de transformador em mensagens de entrada.|  
|[Método transformer::release\_message](../Topic/transformer::release_message%20Method.md)|Libera uma reserva anterior da mensagem. \(Substitui [source\_block::release\_message](../Topic/source_block::release_message%20Method.md).\)|  
|[Método transformer::reserve\_message](../Topic/transformer::reserve_message%20Method.md)|Reserva uma mensagem oferecida anteriormente por esse bloco da mensagem de `transformer` . \(Substitui [source\_block::reserve\_message](../Topic/source_block::reserve_message%20Method.md).\)|  
|[Método transformer::resume\_propagation](../Topic/transformer::resume_propagation%20Method.md)|Propagação de resumos depois que uma reserva foi liberada. \(Substitui [source\_block::resume\_propagation](../Topic/source_block::resume_propagation%20Method.md).\)|  
|[Método transformer::send\_message](../Topic/transformer::send_message%20Method.md)|Passa de forma síncrona uma mensagem de um bloco de `ISource` a esse bloco da mensagem de `transformer` .  É invocado pelo método de `send` , quando chamado por um bloco de origem.|  
|[Método transformer::supports\_anonymous\_source](../Topic/transformer::supports_anonymous_source%20Method.md)|Substitui o método de `supports_anonymous_source` para indicar que esse bloco pode aceitar as mensagens são oferecidas a ele por uma origem que não seja vinculada. \(Substitui [ITarget::supports\_anonymous\_source](../Topic/ITarget::supports_anonymous_source%20Method.md).\)|  
  
## Comentários  
 Para obter mais informações, consulte [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## Hierarquia de Herança  
 [ISource](../../../parallel/concrt/reference/isource-class.md)  
  
 [ITarget](../../../parallel/concrt/reference/itarget-class.md)  
  
 [source\_block](../Topic/source_block%20Class.md)  
  
 [propagator\_block](../../../parallel/concrt/reference/propagator-block-class.md)  
  
 `transformer`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [classe da chamada](../../../parallel/concrt/reference/call-class.md)