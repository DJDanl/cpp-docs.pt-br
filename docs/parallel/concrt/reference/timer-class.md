---
title: "Classe timer | Microsoft Docs"
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
  - "agents/concurrency::timer"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe timer"
ms.assetid: 4f4dea51-de9f-40f9-93f5-dd724c567b49
caps.latest.revision: 21
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe timer
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Um bloco da mensagem de `timer` é um único destino `source_block` capaz de enviar uma mensagem ao destino depois que um intervalo especificado de tempo decorrido ou em intervalos específicos.  
  
## Sintaxe  
  
```  
template<  
   class _Type  
>  
class timer : public Concurrency::details::_Timer, public source_block<single_link_registry<ITarget<_Type>>>;  
```  
  
#### Parâmetros  
 `_Type`  
 O tipo de carga útil das mensagens de saída dessa bloco.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor timer::timer](../Topic/timer::timer%20Constructor.md)|Sobrecarregado.  Constrói um bloco da mensagem de `timer` que aciona uma mensagem determinada após um intervalo especificado.|  
|[Destruidor timer::~timer](../Topic/timer::~timer%20Destructor.md)|Destrói um bloco da mensagem de `timer` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método timer::pause](../Topic/timer::pause%20Method.md)|Para o bloco da mensagem de `timer` .  Se for um bloco de repetição da mensagem de `timer` , pode ser reiniciado com uma chamada subsequente de `start()` .  Para os timers não repetentes, isso tem o mesmo efeito que uma chamada de `stop` .|  
|[Método timer::start](../Topic/timer::start%20Method.md)|Inicia o bloco da mensagem de `timer` .  O número especificado de milissegundos após isso é chamado, o valor especificado será propagado downstream como `message`.|  
|[Método timer::stop](../Topic/timer::stop%20Method.md)|Para o bloco da mensagem de `timer` .|  
  
### Métodos Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método timer::accept\_message](../Topic/timer::accept_message%20Method.md)|Aceita uma mensagem que é oferecida por esse bloco da mensagem de `timer` , transferindo propriedade ao chamador.|  
|[Método timer::consume\_message](../Topic/timer::consume_message%20Method.md)|Consome uma mensagem anteriormente oferecida por `timer` e reservada pelo destino, transferindo propriedade ao chamador.|  
|[Método timer::link\_target\_notification](../Topic/timer::link_target_notification%20Method.md)|Um retorno de chamada que notifica que um novo destino esteve vinculado a esse bloco da mensagem de `timer` .|  
|[Método timer::propagate\_to\_any\_targets](../Topic/timer::propagate_to_any_targets%20Method.md)|Tenta oferecer a mensagem gerada pelo bloco de `timer` em todos os destinos vinculados.|  
|[Método timer::release\_message](../Topic/timer::release_message%20Method.md)|Libera uma reserva anterior da mensagem. \(Substitui [source\_block::release\_message](../Topic/source_block::release_message%20Method.md).\)|  
|[Método timer::reserve\_message](../Topic/timer::reserve_message%20Method.md)|Reserva uma mensagem oferecida anteriormente por esse bloco da mensagem de `timer` . \(Substitui [source\_block::reserve\_message](../Topic/source_block::reserve_message%20Method.md).\)|  
|[Método timer::resume\_propagation](../Topic/timer::resume_propagation%20Method.md)|Propagação de resumos depois que uma reserva foi liberada. \(Substitui [source\_block::resume\_propagation](../Topic/source_block::resume_propagation%20Method.md).\)|  
  
## Comentários  
 Para obter mais informações, consulte [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## Hierarquia de Herança  
 [ISource](../../../parallel/concrt/reference/isource-class.md)  
  
 [source\_block](../Topic/source_block%20Class.md)  
  
 `timer`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)