---
title: "Classe propagator_block | Microsoft Docs"
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
  - "agents/concurrency::propagator_block"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe propagator_block"
ms.assetid: 86aa75fd-eda5-42aa-aadf-25c0c1c9742d
caps.latest.revision: 21
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe propagator_block
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `propagator_block` é uma classe base abstrata para os blocos de mensagem que é uma origem e destino.  Combina a funcionalidade das classes de `source_block` e de `target_block` .  
  
## Sintaxe  
  
```  
template<  
   class _TargetLinkRegistry,  
   class _SourceLinkRegistry,  
   class _MessageProcessorType = ordered_message_processor<typename _TargetLinkRegistry::type::type>  
>  
class propagator_block : public source_block<_TargetLinkRegistry, _MessageProcessorType>, public ITarget<typename _SourceLinkRegistry::type::source_type>;  
```  
  
#### Parâmetros  
 `_TargetLinkRegistry`  
 O Registro de link para ser usado com o destino vincula.  
  
 `_SourceLinkRegistry`  
 O Registro de link para ser usado com a origem vincula.  
  
 `_MessageProcessorType`  
 O tipo de processador para o processamento de mensagem.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`source_iterator`|O tipo de iterador para `source_link_manager` para este `propagator_block`.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor propagator\_block::propagator\_block](../Topic/propagator_block::propagator_block%20Constructor.md)|Constrói um objeto `propagator_block`.|  
|[Destruidor propagator\_block::~propagator\_block](../Topic/propagator_block::~propagator_block%20Destructor.md)|Destrói um objeto de `propagator_block` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método propagator\_block::propagate](../Topic/propagator_block::propagate%20Method.md)|Passa de forma assíncrona uma mensagem de um bloco de origem para este bloco de destino.|  
|[Método propagator\_block::send](../Topic/propagator_block::send%20Method.md)|Inicia de forma síncrona uma mensagem a esse bloco.  Chamado por um bloco de `ISource` .  Quando essa função é concluída, a mensagem será propagado no bloco.|  
  
### Métodos Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método propagator\_block::decline\_incoming\_messages](../Topic/propagator_block::decline_incoming_messages%20Method.md)|Indica ao bloco que as novas mensagens devem ser diminuídas.|  
|[Método propagator\_block::initialize\_source\_and\_target](../Topic/propagator_block::initialize_source_and_target%20Method.md)|Inicializa o objeto base.  Especificamente, o objeto de `message_processor` precisa ser inicializado.|  
|[Método propagator\_block::link\_source](../Topic/propagator_block::link_source%20Method.md)|Vincula um bloco de origem especificado para este objeto de `propagator_block` .|  
|[Método propagator\_block::process\_input\_messages](../Topic/propagator_block::process_input_messages%20Method.md)|Mensagens de entrada do processo.  Isso só é útil para os blocos de propagator, que deriva de source\_block \(substituições [source\_block::process\_input\_messages](../Topic/source_block::process_input_messages%20Method.md).\)|  
|[Método propagator\_block::propagate\_message](../Topic/propagator_block::propagate_message%20Method.md)|Quando substituído em uma classe derivada, esse método passa de forma assíncrona uma mensagem de um bloco de `ISource` a este objeto de `propagator_block` .  É invocado pelo método de `propagate` , quando chamado por um bloco de origem.|  
|[Método propagator\_block::register\_filter](../Topic/propagator_block::register_filter%20Method.md)|Registra um método de filtro que é invocado em cada mensagem recebida.|  
|[Método propagator\_block::remove\_network\_links](../Topic/propagator_block::remove_network_links%20Method.md)|Remove todos os links de rede de origem e de destino deste objeto de `propagator_block` .|  
|[Método propagator\_block::send\_message](../Topic/propagator_block::send_message%20Method.md)|Quando substituído em uma classe derivada, esse método de forma síncrona transmite uma mensagem de um bloco de `ISource` a este objeto de `propagator_block` .  É invocado pelo método de `send` , quando chamado por um bloco de origem.|  
|[Método propagator\_block::unlink\_source](../Topic/propagator_block::unlink_source%20Method.md)|Unlinks um bloco de origem especificado deste objeto de `propagator_block` .|  
|[Método propagator\_block::unlink\_sources](../Topic/propagator_block::unlink_sources%20Method.md)|Unlinks todos os blocos de origem deste objeto de `propagator_block` . \(Substitui [ITarget::unlink\_sources](../Topic/ITarget::unlink_sources%20Method.md).\)|  
  
## Comentários  
 Para evitar a herança múltipla, a classe de `propagator_block` herda da classe e `source_block` da classe abstrata de `ITarget` .  A maioria da funcionalidade na classe de `target_block` é replicada aqui.  
  
## Hierarquia de Herança  
 [ISource](../../../parallel/concrt/reference/isource-class.md)  
  
 [ITarget](../../../parallel/concrt/reference/itarget-class.md)  
  
 [source\_block](../Topic/source_block%20Class.md)  
  
 `propagator_block`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe source\_block](../Topic/source_block%20Class.md)   
 [Classe ITarget](../../../parallel/concrt/reference/itarget-class.md)