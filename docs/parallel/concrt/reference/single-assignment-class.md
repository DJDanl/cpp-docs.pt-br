---
title: "Classe single_assignment | Microsoft Docs"
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
  - "agents/concurrency::single_assignment"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe single_assignment"
ms.assetid: ccc34728-8de9-4e07-b83d-a36a58d9d2b9
caps.latest.revision: 21
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe single_assignment
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Um bloco da mensagem de `single_assignment` é uma para mais idiomas de destino, várias origem, `propagator_block` ordenado capaz de armazenar um único para gravação, uma vez que `message`.  
  
## Sintaxe  
  
```  
template<  
   class _Type  
>  
class single_assignment : public propagator_block<multi_link_registry<ITarget<_Type>>, multi_link_registry<ISource<_Type>>>;  
```  
  
#### Parâmetros  
 `_Type`  
 O tipo de carga da mensagem do armazenada e propagada pelo buffer.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor single\_assignment::single\_assignment](../Topic/single_assignment::single_assignment%20Constructor.md)|Sobrecarregado.  Constrói um bloco da mensagem de `single_assignment` .|  
|[Destruidor single\_assignment::~single\_assignment](../Topic/single_assignment::~single_assignment%20Destructor.md)|Destrói o bloco da mensagem de `single_assignment` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método single\_assignment::has\_value](../Topic/single_assignment::has_value%20Method.md)|Verifica se este bloco da mensagem de `single_assignment` foi inicializado com um valor ainda.|  
|[Método single\_assignment::value](../Topic/single_assignment::value%20Method.md)|Obtém uma referência à carga atual da mensagem que está sendo armazenada no bloco da mensagem de `single_assignment` .|  
  
### Métodos Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método single\_assignment::accept\_message](../Topic/single_assignment::accept_message%20Method.md)|Aceita uma mensagem que é oferecida por esse bloco da mensagem de `single_assignment` , retornando uma cópia da mensagem ao chamador.|  
|[Método single\_assignment::consume\_message](../Topic/single_assignment::consume_message%20Method.md)|Consome uma mensagem anteriormente oferecida por `single_assignment` e reservada pelo destino, retornando uma cópia da mensagem ao chamador.|  
|[Método single\_assignment::link\_target\_notification](../Topic/single_assignment::link_target_notification%20Method.md)|Um retorno de chamada que notifica que um novo destino esteve vinculado a esse bloco da mensagem de `single_assignment` .|  
|[Método single\_assignment::propagate\_message](../Topic/single_assignment::propagate_message%20Method.md)|Passa de forma assíncrona uma mensagem de um bloco de `ISource` a esse bloco da mensagem de `single_assignment` .  É invocado pelo método de `propagate` , quando chamado por um bloco de origem.|  
|[Método single\_assignment::propagate\_to\_any\_targets](../Topic/single_assignment::propagate_to_any_targets%20Method.md)|Coloca `message``_PMessage` do bloco da mensagem de `single_assignment` e oferece\-o em todos os destinos vinculados.|  
|[Método single\_assignment::release\_message](../Topic/single_assignment::release_message%20Method.md)|Libera uma reserva anterior da mensagem. \(Substitui [source\_block::release\_message](../Topic/source_block::release_message%20Method.md).\)|  
|[Método single\_assignment::reserve\_message](../Topic/single_assignment::reserve_message%20Method.md)|Reserva uma mensagem oferecida anteriormente por esse bloco da mensagem de `single_assignment` . \(Substitui [source\_block::reserve\_message](../Topic/source_block::reserve_message%20Method.md).\)|  
|[Método single\_assignment::resume\_propagation](../Topic/single_assignment::resume_propagation%20Method.md)|Propagação de resumos depois que uma reserva foi liberada. \(Substitui [source\_block::resume\_propagation](../Topic/source_block::resume_propagation%20Method.md).\)|  
|[Método single\_assignment::send\_message](../Topic/single_assignment::send_message%20Method.md)|Passa de forma síncrona uma mensagem de um bloco de `ISource` a esse bloco da mensagem de `single_assignment` .  É invocado pelo método de `send` , quando chamado por um bloco de origem.|  
  
## Comentários  
 Um bloco da mensagem de `single_assignment` propaga out cópias da mensagem a cada destino.  
  
 Para obter mais informações, consulte [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## Hierarquia de Herança  
 [ISource](../../../parallel/concrt/reference/isource-class.md)  
  
 [ITarget](../../../parallel/concrt/reference/itarget-class.md)  
  
 [source\_block](../Topic/source_block%20Class.md)  
  
 [propagator\_block](../../../parallel/concrt/reference/propagator-block-class.md)  
  
 `single_assignment`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe overwrite\_buffer](../../../parallel/concrt/reference/overwrite-buffer-class.md)   
 [Classe unbounded\_buffer](../Topic/unbounded_buffer%20Class.md)