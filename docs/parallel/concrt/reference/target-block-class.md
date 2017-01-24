---
title: "Classe target_block | Microsoft Docs"
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
  - "agents/concurrency::target_block"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe target_block"
ms.assetid: 3ce181b4-b94a-4894-bf7b-64fc09821f9f
caps.latest.revision: 21
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe target_block
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `target_block` é uma classe base abstrata que fornece a funcionalidade básica de gerenciamento do link e os erros que verifica o destino bloqueem somente.  
  
## Sintaxe  
  
```  
template<  
   class _SourceLinkRegistry,  
   class _MessageProcessorType = ordered_message_processor<typename _SourceLinkRegistry::type::source_type>  
>  
class target_block : public ITarget<typename _SourceLinkRegistry::type::source_type>;  
```  
  
#### Parâmetros  
 `_SourceLinkRegistry`  
 O Registro de link para ser usado com a origem vincula.  
  
 `_MessageProcessorType`  
 O tipo de processador para o processamento de mensagem.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`source_iterator`|O tipo de iterador para `source_link_manager` para este objeto de `target_block` .|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor target\_block::target\_block](../Topic/target_block::target_block%20Constructor.md)|Constrói um objeto `target_block`.|  
|[Destruidor target\_block::~target\_block](../Topic/target_block::~target_block%20Destructor.md)|Destrói o objeto `target_block`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método target\_block::propagate](../Topic/target_block::propagate%20Method.md)|Passa de forma assíncrona uma mensagem de um bloco de origem para este bloco de destino.|  
|[Método target\_block::send](../Topic/target_block::send%20Method.md)|Passa de forma síncrona uma mensagem de um bloco de origem para este bloco de destino.|  
  
### Métodos Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método target\_block::async\_send](../Topic/target_block::async_send%20Method.md)|Envia uma mensagem de forma assíncrona para processamento.|  
|[Método target\_block::decline\_incoming\_messages](../Topic/target_block::decline_incoming_messages%20Method.md)|Indica ao bloco que as novas mensagens devem ser diminuídas.|  
|[Método target\_block::enable\_batched\_processing](../Topic/target_block::enable_batched_processing%20Method.md)|Habilita processamento em lotes o processamento para este bloco.|  
|[Método target\_block::initialize\_target](../Topic/target_block::initialize_target%20Method.md)|Inicializa o objeto base.  Especificamente, o objeto de `message_processor` precisa ser inicializado.|  
|[Método target\_block::link\_source](../Topic/target_block::link_source%20Method.md)|Vincula um bloco de origem especificado para este objeto de `target_block` .|  
|[Método target\_block::process\_input\_messages](../Topic/target_block::process_input_messages%20Method.md)|Processa as mensagens recebidas como entradas.|  
|[Método target\_block::process\_message](../Topic/target_block::process_message%20Method.md)|Quando substituído em uma classe derivada, o processa uma mensagem que foi aceita por esse objeto de `target_block` .|  
|[Método target\_block::propagate\_message](../Topic/target_block::propagate_message%20Method.md)|Quando substituído em uma classe derivada, esse método passa de forma assíncrona uma mensagem de um bloco de `ISource` a este objeto de `target_block` .  É invocado pelo método de `propagate` , quando chamado por um bloco de origem.|  
|[Método target\_block::register\_filter](../Topic/target_block::register_filter%20Method.md)|Registra um método de filtro que é invocado em cada mensagem recebida.|  
|[Método target\_block::remove\_sources](../Topic/target_block::remove_sources%20Method.md)|Unlinks todas as fontes depois de esperado operações assíncronas pendentes de envio para concluir.|  
|[Método target\_block::send\_message](../Topic/target_block::send_message%20Method.md)|Quando substituído em uma classe derivada, esse método de forma síncrona transmite uma mensagem de um bloco de `ISource` a este objeto de `target_block` .  É invocado pelo método de `send` , quando chamado por um bloco de origem.|  
|[Método target\_block::sync\_send](../Topic/target_block::sync_send%20Method.md)|De forma síncrona enviar uma mensagem para processamento.|  
|[Método target\_block::unlink\_source](../Topic/target_block::unlink_source%20Method.md)|Unlinks um bloco de origem especificado deste objeto de `target_block` .|  
|[Método target\_block::unlink\_sources](../Topic/target_block::unlink_sources%20Method.md)|Unlinks todos os blocos de origem deste objeto de `target_block` . \(Substitui [ITarget::unlink\_sources](../Topic/ITarget::unlink_sources%20Method.md).\)|  
|[Método target\_block::wait\_for\_async\_sends](../Topic/target_block::wait_for_async_sends%20Method.md)|Espera para que todas as propagações assíncronas serem concluídas.|  
  
## Hierarquia de Herança  
 [ITarget](../../../parallel/concrt/reference/itarget-class.md)  
  
 `target_block`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe ITarget](../../../parallel/concrt/reference/itarget-class.md)