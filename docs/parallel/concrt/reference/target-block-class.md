---
title: Classe target_block | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- target_block
- AGENTS/concurrency::target_block
- AGENTS/concurrency::target_block::target_block
- AGENTS/concurrency::target_block::propagate
- AGENTS/concurrency::target_block::send
- AGENTS/concurrency::target_block::async_send
- AGENTS/concurrency::target_block::decline_incoming_messages
- AGENTS/concurrency::target_block::enable_batched_processing
- AGENTS/concurrency::target_block::initialize_target
- AGENTS/concurrency::target_block::link_source
- AGENTS/concurrency::target_block::process_input_messages
- AGENTS/concurrency::target_block::process_message
- AGENTS/concurrency::target_block::propagate_message
- AGENTS/concurrency::target_block::register_filter
- AGENTS/concurrency::target_block::remove_sources
- AGENTS/concurrency::target_block::send_message
- AGENTS/concurrency::target_block::sync_send
- AGENTS/concurrency::target_block::unlink_source
- AGENTS/concurrency::target_block::unlink_sources
- AGENTS/concurrency::target_block::wait_for_async_sends
dev_langs:
- C++
helpviewer_keywords:
- target_block class
ms.assetid: 3ce181b4-b94a-4894-bf7b-64fc09821f9f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 754bc6add99974ff204c977e47f35486cc830d95
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33693972"
---
# <a name="targetblock-class"></a>Classe target_block
O `target_block` classe é uma classe base abstrata que fornece funcionalidade de gerenciamento básico do link e verificação de erros para o destino apenas blocos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class _SourceLinkRegistry, class _MessageProcessorType = ordered_message_processor<typename _SourceLinkRegistry::type::source_type>>
class target_block : public ITarget<typename _SourceLinkRegistry::type::source_type>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_SourceLinkRegistry`  
 O registro de link a ser usado para manter os links de origem.  
  
 `_MessageProcessorType`  
 O tipo de processador para o processamento de mensagem.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`source_iterator`|O tipo de iterador para o `source_link_manager` para este `target_block` objeto.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[target_block](#ctor)|Constrói um objeto `target_block`.|  
|[~ target_block destruidor](#dtor)|Destrói a `target_block` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[propagate](#propagate)|Assincronamente transmite uma mensagem de um bloco de origem para este bloco de destino.|  
|[send](#send)|Modo síncrono passa uma mensagem de um bloco de origem para este bloco de destino.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[async_send](#async_send)|Envia uma mensagem para processamento de forma assíncrona.|  
|[decline_incoming_messages](#decline_incoming_messages)|Indica para o bloco que devem ser recusadas a novas mensagens.|  
|[enable_batched_processing](#enable_batched_processing)|Habilita em lote de processamento para este bloco.|  
|[initialize_target](#initialize_target)|Inicializa o objeto base. Especificamente, o `message_processor` objeto precisa ser inicializado.|  
|[link_source](#link_source)|Vincula um bloco de origem especificado para este `target_block` objeto.|  
|[process_input_messages](#process_input_messages)|Processa as mensagens recebidas como entradas.|  
|[process_message](#process_message)|Quando substituído em uma classe derivada, processa uma mensagem que foi aceito por este `target_block` objeto.|  
|[propagate_message](#propagate_message)|Quando substituído em uma classe derivada, esse método passa assincronamente uma mensagem de um `ISource` blocos a este `target_block` objeto. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.|  
|[register_filter](#register_filter)|Registra um método de filtro que será invocado em cada mensagem recebida.|  
|[remove_sources](#remove_sources)|Desvincula todas as fontes depois de aguardar a conclusão das operações de envio assíncrono pendente.|  
|[send_message](#send_message)|Quando substituído em uma classe derivada, esse método sincronicamente transmite uma mensagem de um `ISource` blocos a este `target_block` objeto. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.|  
|[sync_send](#sync_send)|Modo síncrono envie uma mensagem para processamento.|  
|[unlink_source](#unlink_source)|Desvincula um bloco de código-fonte especificado neste `target_block` objeto.|  
|[unlink_sources](#unlink_sources)|Desvincula todos os blocos de código-fonte deste `target_block` objeto. (Substitui [: Unlink_sources](itarget-class.md#unlink_sources).)|  
|[wait_for_async_sends](#wait_for_async_sends)|Aguarda até que todas as propagações assíncronas concluir.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ITarget](itarget-class.md)  
  
 `target_block`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="async_send"></a> async_send 

 Envia uma mensagem para processamento de forma assíncrona.  
  
```
void async_send(_Inout_opt_ message<_Source_type>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para a mensagem enviada.  
  
##  <a name="decline_incoming_messages"></a> decline_incoming_messages 

 Indica para o bloco que devem ser recusadas a novas mensagens.  
  
```
void decline_incoming_messages();
```  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado, o destruidor para garantir que as novas mensagens são recusou enquanto destruição está em andamento.  
  
##  <a name="enable_batched_processing"></a> enable_batched_processing 

 Habilita em lote de processamento para este bloco.  
  
```
void enable_batched_processing();
```  
  
##  <a name="initialize_target"></a> initialize_target 

 Inicializa o objeto base. Especificamente, o `message_processor` objeto precisa ser inicializado.  
  
```
void initialize_target(
    _Inout_opt_ Scheduler* _PScheduler = NULL,
    _Inout_opt_ ScheduleGroup* _PScheduleGroup = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PScheduler`  
 O Agendador a ser usado para o agendamento de tarefas.  
  
 `_PScheduleGroup`  
 O grupo de agendamento a ser usado para o agendamento de tarefas.  
  
##  <a name="link_source"></a> link_source 

 Vincula um bloco de origem especificado para este `target_block` objeto.  
  
```
virtual void link_source(_Inout_ ISource<_Source_type>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PSource`  
 Um ponteiro para o `ISource` bloco que deve ser vinculada.  
  
### <a name="remarks"></a>Comentários  
 Essa função não deve ser chamada diretamente em um `target_block` objeto. Blocos devem ser conectados usando o `link_target` método `ISource` blocos, que invocarão o `link_source` método de destino correspondente.  
  
##  <a name="process_input_messages"></a> process_input_messages 

 Processa as mensagens recebidas como entradas.  
  
```
virtual void process_input_messages(_Inout_ message<_Source_type>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
  
##  <a name="process_message"></a> process_message 

 Quando substituído em uma classe derivada, processa uma mensagem que foi aceito por este `target_block` objeto.  
  
```
virtual void process_message(message<_Source_type> *);
```  
  
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
 O método gera uma [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o `_PMessage` ou `_PSource` parâmetro é `NULL`.  
  
##  <a name="propagate_message"></a> propagate_message 

 Quando substituído em uma classe derivada, esse método passa assincronamente uma mensagem de um `ISource` blocos a este `target_block` objeto. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.  
  
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
  
##  <a name="register_filter"></a> register_filter 

 Registra um método de filtro que será invocado em cada mensagem recebida.  
  
```
void register_filter(filter_method const& _Filter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Filter`  
 O método de filtro.  
  
##  <a name="remove_sources"></a> remove_sources 

 Desvincula todas as fontes depois de aguardar a conclusão das operações de envio assíncrono pendente.  
  
```
void remove_sources();
```  
  
### <a name="remarks"></a>Comentários  
 Todos os blocos de destino devem chamar esta rotina para remover as fontes em seu destruidor.  
  
##  <a name="send"></a> Enviar 

 Modo síncrono passa uma mensagem de um bloco de origem para este bloco de destino.  
  
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
 O método gera uma [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o `_PMessage` ou `_PSource` parâmetro é `NULL`.  
  
 Usando o `send` método fora de iniciação de mensagem e propagar as mensagens em uma rede é perigoso e pode resultar em um deadlock.  
  
 Quando `send` retorna, a mensagem seja já foi aceitada e transferida para o bloco de destino, ou ele foi recusado pelo destino.  
  
##  <a name="send_message"></a> send_message 

 Quando substituído em uma classe derivada, esse método sincronicamente transmite uma mensagem de um `ISource` blocos a este `target_block` objeto. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status send_message(
    _Inout_ message<_Source_type> *,
    _Inout_ ISource<_Source_type> *);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse bloco retorna `declined` , a menos que substituído por uma classe derivada.  
  
##  <a name="sync_send"></a> sync_send 

 Modo síncrono envie uma mensagem para processamento.  
  
```
void sync_send(_Inout_opt_ message<_Source_type>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para a mensagem enviada.  
  
##  <a name="ctor"></a> target_block 

 Constrói um objeto `target_block`.  
  
```
target_block();
```  
  
##  <a name="dtor"></a> ~ target_block 

 Destrói a `target_block` objeto.  
  
```
virtual ~target_block();
```  
  
##  <a name="unlink_source"></a> unlink_source 

 Desvincula um bloco de código-fonte especificado neste `target_block` objeto.  
  
```
virtual void unlink_source(_Inout_ ISource<_Source_type>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PSource`  
 Um ponteiro para o `ISource` bloco que deve ser desvinculado.  
  
##  <a name="unlink_sources"></a> unlink_sources 

 Desvincula todos os blocos de código-fonte deste `target_block` objeto.  
  
```
virtual void unlink_sources();
```  
  
##  <a name="wait_for_async_sends"></a> wait_for_async_sends 

 Aguarda até que todas as propagações assíncronas concluir.  
  
```
void wait_for_async_sends();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método é usado pelos destruidores de bloco de mensagem para garantir que todas as operações assíncronas tem tido tempo para concluir antes de destruir o bloco.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe ITarget](itarget-class.md)
