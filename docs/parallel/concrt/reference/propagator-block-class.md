---
title: Classe propagator_block | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- propagator_block
- AGENTS/concurrency::propagator_block
- AGENTS/concurrency::propagator_block::propagator_block
- AGENTS/concurrency::propagator_block::propagate
- AGENTS/concurrency::propagator_block::send
- AGENTS/concurrency::propagator_block::decline_incoming_messages
- AGENTS/concurrency::propagator_block::initialize_source_and_target
- AGENTS/concurrency::propagator_block::link_source
- AGENTS/concurrency::propagator_block::process_input_messages
- AGENTS/concurrency::propagator_block::propagate_message
- AGENTS/concurrency::propagator_block::register_filter
- AGENTS/concurrency::propagator_block::remove_network_links
- AGENTS/concurrency::propagator_block::send_message
- AGENTS/concurrency::propagator_block::unlink_source
- AGENTS/concurrency::propagator_block::unlink_sources
dev_langs:
- C++
helpviewer_keywords:
- propagator_block class
ms.assetid: 86aa75fd-eda5-42aa-aadf-25c0c1c9742d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3ff6e543702fc366e72f1473f0f70608a1daabc6
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="propagatorblock-class"></a>Classe propagator_block
O `propagator_block` classe é uma classe base abstrata para blocos de mensagens de uma origem e destino. Ele combina a funcionalidade de ambos os `source_block` e `target_block` classes.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class _TargetLinkRegistry, class _SourceLinkRegistry, class _MessageProcessorType = ordered_message_processor<typename _TargetLinkRegistry::type::type>>
class propagator_block : public source_block<_TargetLinkRegistry,
    _MessageProcessorType>,
 public ITarget<typename _SourceLinkRegistry::type::source_type>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_TargetLinkRegistry`  
 O registro de link a ser usado para manter os links de destino.  
  
 `_SourceLinkRegistry`  
 O registro de link a ser usado para manter os links de origem.  
  
 `_MessageProcessorType`  
 O tipo de processador para o processamento de mensagem.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`source_iterator`|O tipo de iterador para o `source_link_manager` para este `propagator_block`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[propagator_block](#ctor)|Constrói um objeto `propagator_block`.|  
|[~propagator_block Destructor](#dtor)|Destrói um objeto `propagator_block`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[propagate](#propagate)|Assincronamente transmite uma mensagem de um bloco de origem para este bloco de destino.|  
|[send](#send)|Inicia sincronicamente uma mensagem para este bloco. Chamado por um `ISource` bloco. Quando essa função é concluída, a mensagem serão já ter propagadas no bloco.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[decline_incoming_messages](#decline_incoming_messages)|Indica para o bloco que devem ser recusadas a novas mensagens.|  
|[initialize_source_and_target](#initialize_source_and_target)|Inicializa o objeto base. Especificamente, o `message_processor` objeto precisa ser inicializado.|  
|[link_source](#link_source)|Vincula um bloco de origem especificado para este `propagator_block` objeto.|  
|[process_input_messages](#process_input_messages)|Processar mensagens de entrada. Isso só é útil para blocos de propagador, que derivam de source_block (substitui [source_block:: process_input_messages](source-block-class.md#process_input_messages).)|  
|[propagate_message](#propagate_message)|Quando substituído em uma classe derivada, esse método passa assincronamente uma mensagem de um `ISource` blocos a este `propagator_block` objeto. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.|  
|[register_filter](#register_filter)|Registra um método de filtro que será invocado em cada mensagem recebida.|  
|[remove_network_links](#remove_network_links)|Remove todos os de origem e destino links de rede deste `propagator_block` objeto.|  
|[send_message](#send_message)|Quando substituído em uma classe derivada, esse método sincronicamente transmite uma mensagem de um `ISource` blocos a este `propagator_block` objeto. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.|  
|[unlink_source](#unlink_source)|Desvincula um bloco de código-fonte especificado neste `propagator_block` objeto.|  
|[unlink_sources](#unlink_sources)|Desvincula todos os blocos de código-fonte deste `propagator_block` objeto. (Substitui [: Unlink_sources](itarget-class.md#unlink_sources).)|  
  
## <a name="remarks"></a>Comentários  
 Para evitar várias heranças, o `propagator_block` classe herda o `source_block` classe e `ITarget` classe abstrata. A maioria das funcionalidades no `target_block` classe é replicada aqui.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](isource-class.md)  
  
 [ITarget](itarget-class.md)  
  
 [source_block](source-block-class.md)  
  
 `propagator_block`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="decline_incoming_messages"></a> decline_incoming_messages 

 Indica para o bloco que devem ser recusadas a novas mensagens.  
  
```
void decline_incoming_messages();
```  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado, o destruidor para garantir que as novas mensagens são recusou enquanto destruição está em andamento.  
  
##  <a name="initialize_source_and_target"></a> initialize_source_and_target 

 Inicializa o objeto base. Especificamente, o `message_processor` objeto precisa ser inicializado.  
  
```
void initialize_source_and_target(
    _Inout_opt_ Scheduler* _PScheduler = NULL,
    _Inout_opt_ ScheduleGroup* _PScheduleGroup = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PScheduler`  
 O Agendador a ser usado para o agendamento de tarefas.  
  
 `_PScheduleGroup`  
 O grupo de agendamento a ser usado para o agendamento de tarefas.  
  
##  <a name="link_source"></a> link_source 

 Vincula um bloco de origem especificado para este `propagator_block` objeto.  
  
```
virtual void link_source(_Inout_ ISource<_Source_type>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PSource`  
 Um ponteiro para o `ISource` bloco que deve ser vinculada.  
  
##  <a name="process_input_messages"></a> process_input_messages 

 Processar mensagens de entrada. Isso só é útil para blocos de propagador, que derivam de source_block  
  
```
virtual void process_input_messages(_Inout_ message<_Target_type>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
  
##  <a name="propagate"></a> Propagar 

 Assincronamente transmite uma mensagem de um bloco de origem para este bloco de destino.  
  
```
virtual message_status propagate(
    _Inout_opt_ message<_Source_type>* _PMessage,
    _Inout_opt_ ISource<_Source_type>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferta a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
### <a name="remarks"></a>Comentários  
 O `propagate` método é chamado em um bloco de destino por um bloco de origem vinculado. Ele enfileira uma tarefa assíncrona para manipular a mensagem, se ainda não estiver já enfileirado ou em execução.  
  
 O método gera uma [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o `_PMessage` ou `_PSource` parâmetro é `NULL`.  
  
##  <a name="propagate_message"></a> propagate_message 

 Quando substituído em uma classe derivada, esse método passa assincronamente uma mensagem de um `ISource` blocos a este `propagator_block` objeto. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status propagate_message(
    _Inout_ message<_Source_type>* _PMessage,
    _Inout_ ISource<_Source_type>* _PSource) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferta a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="ctor"></a> propagator_block 

 Constrói um objeto `propagator_block`.  
  
```
propagator_block();
```  
  
##  <a name="dtor"></a> ~propagator_block 

 Destrói um objeto `propagator_block`.  
  
```
virtual ~propagator_block();
```  
  
##  <a name="register_filter"></a> register_filter 

 Registra um método de filtro que será invocado em cada mensagem recebida.  
  
```
void register_filter(filter_method const& _Filter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Filter`  
 O método de filtro.  
  
##  <a name="remove_network_links"></a> remove_network_links 

 Remove todos os de origem e destino links de rede deste `propagator_block` objeto.  
  
```
void remove_network_links();
```  
  
##  <a name="send"></a> Enviar 

 Inicia sincronicamente uma mensagem para este bloco. Chamado por um `ISource` bloco. Quando essa função é concluída, a mensagem serão já ter propagadas no bloco.  
  
```
virtual message_status send(
    _Inout_ message<_Source_type>* _PMessage,
    _Inout_ ISource<_Source_type>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferta a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
### <a name="remarks"></a>Comentários  
 Este método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o `_PMessage` ou `_PSource` parâmetro é `NULL`.  
  
##  <a name="send_message"></a> send_message 

 Quando substituído em uma classe derivada, esse método sincronicamente transmite uma mensagem de um `ISource` blocos a este `propagator_block` objeto. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status send_message(
    _Inout_ message<_Source_type> *,
    _Inout_ ISource<_Source_type> *);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse bloco retorna `declined` , a menos que substituído por uma classe derivada.  
  
##  <a name="unlink_source"></a> unlink_source 

 Desvincula um bloco de código-fonte especificado neste `propagator_block` objeto.  
  
```
virtual void unlink_source(_Inout_ ISource<_Source_type>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PSource`  
 Um ponteiro para o `ISource` bloco que deve ser desvinculado.  
  
##  <a name="unlink_sources"></a> unlink_sources 

 Desvincula todos os blocos de código-fonte deste `propagator_block` objeto.  
  
```
virtual void unlink_sources();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe source_block](source-block-class.md)   
 [Classe ITarget](itarget-class.md)
