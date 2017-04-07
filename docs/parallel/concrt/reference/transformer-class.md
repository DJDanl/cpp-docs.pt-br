---
title: Classe Transformer | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- transformer
- AGENTS/concurrency::transformer
- AGENTS/concurrency::transformer::transformer
- AGENTS/concurrency::transformer::accept_message
- AGENTS/concurrency::transformer::consume_message
- AGENTS/concurrency::transformer::link_target_notification
- AGENTS/concurrency::transformer::propagate_message
- AGENTS/concurrency::transformer::propagate_to_any_targets
- AGENTS/concurrency::transformer::release_message
- AGENTS/concurrency::transformer::reserve_message
- AGENTS/concurrency::transformer::resume_propagation
- AGENTS/concurrency::transformer::send_message
- AGENTS/concurrency::transformer::supports_anonymous_source
dev_langs:
- C++
helpviewer_keywords:
- transformer class
ms.assetid: eea71925-7043-4a92-bfd4-dbc0ece5d081
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 994cfbaa79594389d8d3b8390bfc46a5aa75a525
ms.lasthandoff: 03/17/2017

---
# <a name="transformer-class"></a>Classe transformer
A `transformer` bloco de mensagens é um único destino, com várias fontes, ordenada `propagator_block` que pode aceitar mensagens de um tipo e é capaz de armazenar um número ilimitado de mensagens de um tipo diferente.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class _Input, class _Output>
class transformer : public propagator_block<single_link_registry<ITarget<_Output>>,
    multi_link_registry<ISource<_Input>>>;
```   
  
#### <a name="parameters"></a>Parâmetros  
 `_Input`  
 O tipo de carga das aceitas pelo buffer de mensagens.  
  
 `_Output`  
 O tipo de carga de mensagens armazenadas e propagada pelo buffer.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[transformador](#ctor)|Sobrecarregado. Constrói um `transformer` bloco de mensagens.|  
|[~ transformer destruidor](#dtor)|Destrói o `transformer` bloco de mensagens.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[accept_message](#accept_message)|Aceita uma mensagem que foi oferecida por esse `transformer` bloco de mensagens, transferindo a propriedade para o chamador.|  
|[consume_message](#consume_message)|Consome uma mensagem anteriormente oferecida pelo `transformer` e reservado pelo destino, transferindo a propriedade para o chamador.|  
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `transformer` bloco de mensagens.|  
|[propagate_message](#propagate_message)|Assincronamente transmite uma mensagem de uma `ISource` bloco a esta `transformer` bloco de mensagens. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.|  
|[propagate_to_any_targets](#propagate_to_any_targets)|Executa a função transformador nas mensagens de entrada.|  
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|  
|[reserve_message](#reserve_message)|Reserva uma mensagem anteriormente oferecida por esse `transformer` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|  
|[resume_propagation](#resume_propagation)|Retoma a propagação após uma reserva foi lançada. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|  
|[send_message](#send_message)|Sincronicamente transmite uma mensagem de uma `ISource` bloco a esta `transformer` bloco de mensagens. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.|  
|[supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada. (Substitui [Supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](isource-class.md)  
  
 [ITarget](itarget-class.md)  
  
 [source_block](source-block-class.md)  
  
 [propagator_block](propagator-block-class.md)  
  
 `transformer`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="accept_message"></a>accept_message 

 Aceita uma mensagem que foi oferecida por esse `transformer` bloco de mensagens, transferindo a propriedade para o chamador.  
  
```
virtual message<_Output>* accept_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` da oferecida `message` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
##  <a name="consume_message"></a>consume_message 

 Consome uma mensagem anteriormente oferecida pelo `transformer` e reservado pelo destino, transferindo a propriedade para o chamador.  
  
```
virtual message<_Output>* consume_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` do objeto que está sendo consumida.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
### <a name="remarks"></a>Comentários  
 Semelhante ao `accept`, mas sempre é precedido por uma chamada para `reserve`.  
  
##  <a name="link_target_notification"></a>link_target_notification 

 Um retorno de chamada que notifica que um novo destino foi vinculado a este `transformer` bloco de mensagens.  
  
```
virtual void link_target_notification(_Inout_ ITarget<_Output> *);
```  
  
##  <a name="propagate_message"></a>propagate_message 

 Assincronamente transmite uma mensagem de uma `ISource` bloco a esta `transformer` bloco de mensagens. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status propagate_message(
    _Inout_ message<_Input>* _PMessage,
    _Inout_ ISource<_Input>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 A [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="propagate_to_any_targets"></a>propagate_to_any_targets 

 Executa a função transformador nas mensagens de entrada.  
  
```
virtual void propagate_to_any_targets(_Inout_opt_ message<_Output> *);
```  
  
##  <a name="release_message"></a>release_message 

 Libera uma reserva de mensagem anterior.  
  
```
virtual void release_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` objeto sendo lançada.  
  
##  <a name="reserve_message"></a>reserve_message 

 Reserva uma mensagem anteriormente oferecida por esse `transformer` bloco de mensagens.  
  
```
virtual bool reserve_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` do objeto que está sendo reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se a mensagem foi reservada com êxito, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Depois de `reserve` é chamado, se ele retorna `true`, `consume` ou `release` deve ser chamado para executar ou liberar a propriedade da mensagem.  
  
##  <a name="resume_propagation"></a>resume_propagation 

 Retoma a propagação após uma reserva foi lançada.  
  
```
virtual void resume_propagation();
```  
  
##  <a name="send_message"></a>send_message 

 Sincronicamente transmite uma mensagem de uma `ISource` bloco a esta `transformer` bloco de mensagens. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status send_message(
    _Inout_ message<_Input>* _PMessage,
    _Inout_ ISource<_Input>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 A [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="supports_anonymous_source"></a>supports_anonymous_source 

 Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada.  
  
```
virtual bool supports_anonymous_source();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`como o bloco não adie oferecido mensagens.  
  
##  <a name="ctor"></a>transformador 

 Constrói um `transformer` bloco de mensagens.  
  
```
transformer(
    _Transform_method const& _Func,
    _Inout_opt_ ITarget<_Output>* _PTarget = NULL);

transformer(
    _Transform_method const& _Func,
    _Inout_opt_ ITarget<_Output>* _PTarget,
    filter_method const& _Filter);

transformer(
    Scheduler& _PScheduler,
    _Transform_method const& _Func,
    _Inout_opt_ ITarget<_Output>* _PTarget = NULL);

transformer(
    Scheduler& _PScheduler,
    _Transform_method const& _Func,
    _Inout_opt_ ITarget<_Output>* _PTarget,
    filter_method const& _Filter);

transformer(
    ScheduleGroup& _PScheduleGroup,
    _Transform_method const& _Func,
    _Inout_opt_ ITarget<_Output>* _PTarget = NULL);

transformer(
    ScheduleGroup& _PScheduleGroup,
    _Transform_method const& _Func,
    _Inout_opt_ ITarget<_Output>* _PTarget,
    filter_method const& _Filter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Func`  
 Uma função que será chamada para cada mensagem aceita.  
  
 `_PTarget`  
 Um ponteiro para um bloco de destino para o link com o transformador.  
  
 `_Filter`  
 Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.  
  
 `_PScheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefa para o `transformer` bloco de mensagens está agendado.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefa para o `transformer` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.  
  
 O tipo `_Transform_method` é um functor com assinatura `_Output (_Input const &)` que é invocado por este `transformer` bloco de mensagens para processar uma mensagem.  
  
 O tipo `filter_method` é um functor com assinatura `bool (_Input const &)` que é invocado por este `transformer` bloco de mensagens para determinar se ele deve aceitar uma mensagem oferecida.  
  
##  <a name="dtor"></a>~ transformer 

 Destrói o `transformer` bloco de mensagens.  
  
```
~transformer();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe call](call-class.md)

