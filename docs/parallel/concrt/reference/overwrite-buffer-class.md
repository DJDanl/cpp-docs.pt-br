---
title: Classe overwrite_buffer | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- overwrite_buffer
- AGENTS/concurrency::overwrite_buffer
- AGENTS/concurrency::overwrite_buffer::overwrite_buffer
- AGENTS/concurrency::overwrite_buffer::has_value
- AGENTS/concurrency::overwrite_buffer::value
- AGENTS/concurrency::overwrite_buffer::accept_message
- AGENTS/concurrency::overwrite_buffer::consume_message
- AGENTS/concurrency::overwrite_buffer::link_target_notification
- AGENTS/concurrency::overwrite_buffer::propagate_message
- AGENTS/concurrency::overwrite_buffer::propagate_to_any_targets
- AGENTS/concurrency::overwrite_buffer::release_message
- AGENTS/concurrency::overwrite_buffer::reserve_message
- AGENTS/concurrency::overwrite_buffer::resume_propagation
- AGENTS/concurrency::overwrite_buffer::send_message
- AGENTS/concurrency::overwrite_buffer::supports_anonymous_source
dev_langs: C++
helpviewer_keywords: overwrite_buffer class
ms.assetid: 5cc428fe-3697-419c-9fb2-78f6181c9293
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f41348b77d65f3ade8016c9e23a31555db2d3612
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="overwritebuffer-class"></a>Classe overwrite_buffer
Um `overwrite_buffer` bloco de mensagens é um multi-destino de várias fontes, ordenada `propagator_block` capaz de armazenar uma única mensagem por vez. Novas mensagens substituem aqueles mantido anteriormente.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class overwrite_buffer : public propagator_block<multi_link_registry<ITarget<T>>, multi_link_registry<ISource<T>>>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de carga de mensagens armazenadas e propagada pelo buffer.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[overwrite_buffer](#ctor)|Sobrecarregado. Constrói um `overwrite_buffer` bloco de mensagens.|  
|[~ overwrite_buffer destruidor](#dtor)|Destrói a `overwrite_buffer` bloco de mensagens.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[has_value](#has_value)|Verifica se este `overwrite_buffer` bloco de mensagens tem um valor ainda.|  
|[value](#value)|Obtém uma referência para a carga atual da mensagem que está sendo armazenada na `overwrite_buffer` bloco de mensagens.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[accept_message](#accept_message)|Aceita uma mensagem que foi fornecida por esse `overwrite_buffer` bloco de mensagens, retornando uma cópia da mensagem para o chamador.|  
|[consume_message](#consume_message)|Consome uma mensagem anteriormente oferecida pelo `overwrite_buffer` bloco de mensagens e reservado pelo destino, retornando uma cópia da mensagem para o chamador.|  
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `overwrite_buffer` bloco de mensagens.|  
|[propagate_message](#propagate_message)|Assincronamente transmite uma mensagem de um `ISource` blocos a este `overwrite_buffer` bloco de mensagens. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.|  
|[propagate_to_any_targets](#propagate_to_any_targets)|Locais de `message _PMessage` neste `overwrite_buffer` bloco de mensagens e oferece a todos os destinos vinculados.|  
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|  
|[reserve_message](#reserve_message)|Reserva uma mensagem anteriormente oferecida por este `overwrite_buffer` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|  
|[resume_propagation](#resume_propagation)|Retoma a propagação depois de uma reserva foi liberada. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|  
|[send_message](#send_message)|Modo síncrono transmite uma mensagem de um `ISource` blocos a este `overwrite_buffer` bloco de mensagens. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.|  
|[supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada. (Substitui [: Supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|  
  
## <a name="remarks"></a>Comentários  
 Um `overwrite_buffer` bloco de mensagens propaga cópias de sua mensagem armazenada para cada um de seus destinos.  
  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](isource-class.md)  
  
 [ITarget](itarget-class.md)  
  
 [source_block](source-block-class.md)  
  
 [propagator_block](propagator-block-class.md)  
  
 `overwrite_buffer`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="accept_message"></a>accept_message 

 Aceita uma mensagem que foi fornecida por esse `overwrite_buffer` bloco de mensagens, retornando uma cópia da mensagem para o chamador.  
  
```
virtual message<T>* accept_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do que o oferecido `message` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
### <a name="remarks"></a>Comentários  
 O `overwrite_buffer` bloco retorna cópias da mensagem para seus destinos de mensagens, em vez de transferir a propriedade da mensagem mantida atualmente.  
  
##  <a name="consume_message"></a>consume_message 

 Consome uma mensagem anteriormente oferecida pelo `overwrite_buffer` bloco de mensagens e reservado pelo destino, retornando uma cópia da mensagem para o chamador.  
  
```
virtual message<T>* consume_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` do objeto que está sendo consumido.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
### <a name="remarks"></a>Comentários  
 Semelhante ao `accept`, mas sempre é precedido por uma chamada para `reserve`.  
  
##  <a name="has_value"></a>has_value 

 Verifica se este `overwrite_buffer` bloco de mensagens tem um valor ainda.  
  
```
bool has_value() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o bloco recebeu um valor de `false` caso contrário.  
  
##  <a name="link_target_notification"></a>link_target_notification 

 Um retorno de chamada que notifica que um novo destino foi vinculado a este `overwrite_buffer` bloco de mensagens.  
  
```
virtual void link_target_notification(_Inout_ ITarget<T>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o destino recentemente vinculado.  
  
##  <a name="dtor"></a>~ overwrite_buffer 

 Destrói a `overwrite_buffer` bloco de mensagens.  
  
```
~overwrite_buffer();
```  
  
##  <a name="ctor"></a>overwrite_buffer 

 Constrói um `overwrite_buffer` bloco de mensagens.  
  
```
overwrite_buffer();

overwrite_buffer(
    filter_method const& _Filter);

overwrite_buffer(
    Scheduler& _PScheduler);

overwrite_buffer(
    Scheduler& _PScheduler,
    filter_method const& _Filter);

overwrite_buffer(
    ScheduleGroup& _PScheduleGroup);

overwrite_buffer(
    ScheduleGroup& _PScheduleGroup,
    filter_method const& _Filter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Filter`  
 Uma função de filtro que determina se as mensagens oferecidas devem ser aceita.  
  
 `_PScheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefas para o `overwrite_buffer` bloco de mensagens está agendado.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefas para o `overwrite_buffer` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.  
  
 O tipo `filter_method` é um functor com assinatura `bool (T const &)` que é invocado por este `overwrite_buffer` bloco de mensagens para determinar se ele deve aceitar uma mensagem oferecida.  
  
##  <a name="propagate_message"></a>propagate_message 

 Assincronamente transmite uma mensagem de um `ISource` blocos a este `overwrite_buffer` bloco de mensagens. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status propagate_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferta a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="propagate_to_any_targets"></a>propagate_to_any_targets 

 Locais de `message _PMessage` neste `overwrite_buffer` bloco de mensagens e oferece a todos os destinos vinculados.  
  
```
virtual void propagate_to_any_targets(_Inout_ message<T>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para um `message` objeto que este `overwrite_buffer` assumir a propriedade do.  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui a mensagem atual no `overwrite_buffer` com a mensagem recentemente aceita `_PMessage`.  
  
##  <a name="send_message"></a>send_message 

 Modo síncrono transmite uma mensagem de um `ISource` blocos a este `overwrite_buffer` bloco de mensagens. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status send_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferta a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="supports_anonymous_source"></a>supports_anonymous_source 

 Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada.  
  
```
virtual bool supports_anonymous_source();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`como o bloco não adiar oferecido mensagens.  
  
##  <a name="release_message"></a>release_message 

 Libera uma reserva de mensagem anterior.  
  
```
virtual void release_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` do objeto que está sendo liberado.  
  
##  <a name="reserve_message"></a>reserve_message 

 Reserva uma mensagem anteriormente oferecida por este `overwrite_buffer` bloco de mensagens.  
  
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

 Retoma a propagação depois de uma reserva foi liberada.  
  
```
virtual void resume_propagation();
```  
  
##  <a name="value"></a>valor 

 Obtém uma referência para a carga atual da mensagem que está sendo armazenada na `overwrite_buffer` bloco de mensagens.  
  
```
T value();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A carga da mensagem está armazenada.  
  
### <a name="remarks"></a>Comentários  
 O valor armazenado na `overwrite_buffer` pode alterar imediatamente depois que este método retorna. Esse método aguardará até que uma mensagem chega se nenhuma mensagem estiver atualmente armazenada na `overwrite_buffer`.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe unbounded_buffer](unbounded-buffer-class.md)   
 [Classe single_assignment](single-assignment-class.md)
