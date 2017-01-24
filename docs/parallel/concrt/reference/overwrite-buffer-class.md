---
title: "Classe overwrite_buffer | Microsoft Docs"
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
  - "agents/concurrency::overwrite_buffer"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe overwrite_buffer"
ms.assetid: 5cc428fe-3697-419c-9fb2-78f6181c9293
caps.latest.revision: 22
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe overwrite_buffer
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Um bloco da mensagem de `overwrite_buffer` é uma para mais idiomas de destino, várias origem, `propagator_block` ordenado capaz de armazenar uma única mensagem por vez.  As novas mensagens substituem tinham anteriormente.  
  
## Sintaxe  
  
```  
template<  
   class _Type  
>  
class overwrite_buffer : public propagator_block<multi_link_registry<ITarget<_Type>>, multi_link_registry<ISource<_Type>>>;  
```  
  
#### Parâmetros  
 `_Type`  
 O tipo de carga útil de mensagens armazenadas e propagadas pelo buffer.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor overwrite\_buffer::overwrite\_buffer](../Topic/overwrite_buffer::overwrite_buffer%20Constructor.md)|Sobrecarregado.  Constrói um bloco da mensagem de `overwrite_buffer` .|  
|[Destruidor overwrite\_buffer::~overwrite\_buffer](../Topic/overwrite_buffer::~overwrite_buffer%20Destructor.md)|Destrói o bloco da mensagem de `overwrite_buffer` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método overwrite\_buffer::has\_value](../Topic/overwrite_buffer::has_value%20Method.md)|Verifica se este bloco da mensagem de `overwrite_buffer` tem um valor ainda.|  
|[Método overwrite\_buffer::value](../Topic/overwrite_buffer::value%20Method.md)|Obtém uma referência à carga atual da mensagem que está sendo armazenada no bloco da mensagem de `overwrite_buffer` .|  
  
### Métodos Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método overwrite\_buffer::accept\_message](../Topic/overwrite_buffer::accept_message%20Method.md)|Aceita uma mensagem que é oferecida por esse bloco da mensagem de `overwrite_buffer` , retornando uma cópia da mensagem ao chamador.|  
|[Método overwrite\_buffer::consume\_message](../Topic/overwrite_buffer::consume_message%20Method.md)|Consome uma mensagem anteriormente oferecida pelo bloco da mensagem de `overwrite_buffer` e reservada pelo destino, retornando uma cópia da mensagem ao chamador.|  
|[Método overwrite\_buffer::link\_target\_notification](../Topic/overwrite_buffer::link_target_notification%20Method.md)|Um retorno de chamada que notifica que um novo destino esteve vinculado a esse bloco da mensagem de `overwrite_buffer` .|  
|[Método overwrite\_buffer::propagate\_message](../Topic/overwrite_buffer::propagate_message%20Method.md)|Passa de forma assíncrona uma mensagem de um bloco de `ISource` a esse bloco da mensagem de `overwrite_buffer` .  É invocado pelo método de `propagate` , quando chamado por um bloco de origem.|  
|[Método overwrite\_buffer::propagate\_to\_any\_targets](../Topic/overwrite_buffer::propagate_to_any_targets%20Method.md)|Coloca `message``_PMessage` do bloco da mensagem de `overwrite_buffer` e oferece\-o em todos os destinos vinculados.|  
|[Método overwrite\_buffer::release\_message](../Topic/overwrite_buffer::release_message%20Method.md)|Libera uma reserva anterior da mensagem. \(Substitui [source\_block::release\_message](../Topic/source_block::release_message%20Method.md).\)|  
|[Método overwrite\_buffer::reserve\_message](../Topic/overwrite_buffer::reserve_message%20Method.md)|Reserva uma mensagem oferecida anteriormente por esse bloco da mensagem de `overwrite_buffer` . \(Substitui [source\_block::reserve\_message](../Topic/source_block::reserve_message%20Method.md).\)|  
|[Método overwrite\_buffer::resume\_propagation](../Topic/overwrite_buffer::resume_propagation%20Method.md)|Propagação de resumos depois que uma reserva foi liberada. \(Substitui [source\_block::resume\_propagation](../Topic/source_block::resume_propagation%20Method.md).\)|  
|[Método overwrite\_buffer::send\_message](../Topic/overwrite_buffer::send_message%20Method.md)|Passa de forma síncrona uma mensagem de um bloco de `ISource` a esse bloco da mensagem de `overwrite_buffer` .  É invocado pelo método de `send` , quando chamado por um bloco de origem.|  
|[Método overwrite\_buffer::supports\_anonymous\_source](../Topic/overwrite_buffer::supports_anonymous_source%20Method.md)|Substitui o método de `supports_anonymous_source` para indicar que esse bloco pode aceitar as mensagens são oferecidas a ele por uma origem que não seja vinculada. \(Substitui [ITarget::supports\_anonymous\_source](../Topic/ITarget::supports_anonymous_source%20Method.md).\)|  
  
## Comentários  
 Um bloco da mensagem de `overwrite_buffer` propaga out cópias da mensagem do armazenada para cada um de seus destinos.  
  
 Para obter mais informações, consulte [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## Hierarquia de Herança  
 [ISource](../../../parallel/concrt/reference/isource-class.md)  
  
 [ITarget](../../../parallel/concrt/reference/itarget-class.md)  
  
 [source\_block](../Topic/source_block%20Class.md)  
  
 [propagator\_block](../../../parallel/concrt/reference/propagator-block-class.md)  
  
 `overwrite_buffer`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe unbounded\_buffer](../Topic/unbounded_buffer%20Class.md)   
 [Classe single\_assignment](../../../parallel/concrt/reference/single-assignment-class.md)