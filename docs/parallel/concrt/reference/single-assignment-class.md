---
title: Classe single_assignment | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- agents/concurrency::single_assignment
dev_langs:
- C++
helpviewer_keywords:
- single_assignment class
ms.assetid: ccc34728-8de9-4e07-b83d-a36a58d9d2b9
caps.latest.revision: 21
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
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: a2a500353b06219713c5d9f3e68f82b247c1604f
ms.lasthandoff: 02/25/2017

---
# <a name="singleassignment-class"></a>Classe single_assignment
Um `single_assignment` bloco de mensagens é um destino de vários com várias fontes, ordenada `propagator_block` capaz de armazenar uma única gravação-depois de `message`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class single_assignment : public propagator_block<multi_link_registry<ITarget<T>>, multi_link_registry<ISource<T>>>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de carga da mensagem armazenados e propagada pelo buffer.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor single_assignment](#ctor)|Sobrecarregado. Constrói um `single_assignment` bloco de mensagens.|  
|[~ single_assignment destruidor](#dtor)|Destrói o `single_assignment` bloco de mensagens.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método has_value](#has_value)|Verifica se este `single_assignment` bloco de mensagens foi inicializado com um valor ainda.|  
|[Método de valor](#value)|Obtém uma referência para a carga atual da mensagem que está sendo armazenada na `single_assignment` bloco de mensagens.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método accept_message](#accept_message)|Aceita uma mensagem que foi oferecida por esse `single_assignment` bloco de mensagens, retornando uma cópia da mensagem para o chamador.|  
|[Método consume_message](#consume_message)|Consome uma mensagem anteriormente oferecida pelo `single_assignment` e reservado pelo destino, retornando uma cópia da mensagem para o chamador.|  
|[Método link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `single_assignment` bloco de mensagens.|  
|[Método propagate_message](#propagate_message)|Assincronamente transmite uma mensagem de uma `ISource` bloco a esta `single_assignment` bloco de mensagens. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.|  
|[Método propagate_to_any_targets](#propagate_to_any_targets)|Locais de `message``_PMessage` neste `single_assignment` bloco de mensagens e oferece a todos os destinos vinculados.|  
|[Método release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|  
|[Método reserve_message](#reserve_message)|Reserva uma mensagem anteriormente oferecida por esse `single_assignment` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|  
|[Método resume_propagation](#resume_propagation)|Retoma a propagação após uma reserva foi lançada. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|  
|[Método send_message](#send_message)|Sincronicamente transmite uma mensagem de uma `ISource` bloco a esta `single_assignment` bloco de mensagens. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.|  
  
## <a name="remarks"></a>Comentários  
 Um `single_assignment` bloco de mensagens propaga cópias de sua mensagem para cada destino.  
  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](isource-class.md)  
  
 [ITarget](itarget-class.md)  
  
 [source_block](source-block-class.md)  
  
 [propagator_block](propagator-block-class.md)  
  
 `single_assignment`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-nameacceptmessagea-acceptmessage"></a><a name="accept_message"></a>accept_message 

 Aceita uma mensagem que foi oferecida por esse `single_assignment` bloco de mensagens, retornando uma cópia da mensagem para o chamador.  
  
```
virtual message<T>* accept_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` da oferecida `message` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
### <a name="remarks"></a>Comentários  
 O `single_assignment` bloco retorna cópias da mensagem para seus destinos de mensagens, em vez de transferir a propriedade da mensagem mantida atualmente.  
  
##  <a name="a-nameconsumemessagea-consumemessage"></a><a name="consume_message"></a>consume_message 

 Consome uma mensagem anteriormente oferecida pelo `single_assignment` e reservado pelo destino, retornando uma cópia da mensagem para o chamador.  
  
```
virtual message<T>* consume_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` do objeto que está sendo consumida.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
### <a name="remarks"></a>Comentários  
 Semelhante ao `accept`, mas sempre é precedido por uma chamada para `reserve`.  
  
##  <a name="a-namehasvaluea-hasvalue"></a><a name="has_value"></a>has_value 

 Verifica se este `single_assignment` bloco de mensagens foi inicializado com um valor ainda.  
  
```
bool has_value() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o bloco recebeu um valor de `false` caso contrário.  
  
##  <a name="a-namelinktargetnotificationa-linktargetnotification"></a><a name="link_target_notification"></a>link_target_notification 

 Um retorno de chamada que notifica que um novo destino foi vinculado a este `single_assignment` bloco de mensagens.  
  
```
virtual void link_target_notification(_Inout_ ITarget<T>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o destino vinculado recentemente.  
  
##  <a name="a-namepropagatemessagea-propagatemessage"></a><a name="propagate_message"></a>propagate_message 

 Assincronamente transmite uma mensagem de uma `ISource` bloco a esta `single_assignment` bloco de mensagens. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status propagate_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 A [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="a-namepropagatetoanytargetsa-propagatetoanytargets"></a><a name="propagate_to_any_targets"></a>propagate_to_any_targets 

 Locais de `message``_PMessage` neste `single_assignment` bloco de mensagens e oferece a todos os destinos vinculados.  
  
```
virtual void propagate_to_any_targets(_Inout_opt_ message<T>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para um `message` que este `single_assignment` tem assumir a propriedade do bloco de mensagens.  
  
##  <a name="a-namereleasemessagea-releasemessage"></a><a name="release_message"></a>release_message 

 Libera uma reserva de mensagem anterior.  
  
```
virtual void release_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` objeto sendo lançada.  
  
##  <a name="a-namereservemessagea-reservemessage"></a><a name="reserve_message"></a>reserve_message 

 Reserva uma mensagem anteriormente oferecida por esse `single_assignment` bloco de mensagens.  
  
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
  
##  <a name="a-nameresumepropagationa-resumepropagation"></a><a name="resume_propagation"></a>resume_propagation 

 Retoma a propagação após uma reserva foi lançada.  
  
```
virtual void resume_propagation();
```  
  
##  <a name="a-namesendmessagea-sendmessage"></a><a name="send_message"></a>send_message 

 Sincronicamente transmite uma mensagem de uma `ISource` bloco a esta `single_assignment` bloco de mensagens. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status send_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 A [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="a-namectora-singleassignment"></a><a name="ctor"></a>single_assignment 

 Constrói um `single_assignment` bloco de mensagens.  
  
```
single_assignment();

single_assignment(
    filter_method const& _Filter);

single_assignment(
    Scheduler& _PScheduler);

single_assignment(
    Scheduler& _PScheduler,
    filter_method const& _Filter);

single_assignment(
    ScheduleGroup& _PScheduleGroup);

single_assignment(
    ScheduleGroup& _PScheduleGroup,
    filter_method const& _Filter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Filter`  
 Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.  
  
 `_PScheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefa para o `single_assignment` bloco de mensagens está agendado.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefa para o `single_assignment` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.  
  
 O tipo `filter_method` é um functor com assinatura `bool (T const &)` que é invocado por este `single_assignment` bloco de mensagens para determinar se ele deve aceitar uma mensagem oferecida.  
  
##  <a name="a-namedtora-singleassignment"></a><a name="dtor"></a>~ single_assignment 

 Destrói o `single_assignment` bloco de mensagens.  
  
```
~single_assignment();
```  
  
##  <a name="a-namevaluea-value"></a><a name="value"></a>valor 

 Obtém uma referência para a carga atual da mensagem que está sendo armazenada na `single_assignment` bloco de mensagens.  
  
```
T const& value();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A carga da mensagem armazenada.  
  
### <a name="remarks"></a>Comentários  
 Esse método aguardará até que uma mensagem chega se nenhuma mensagem estiver atualmente armazenada na `single_assignment` bloco de mensagens.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe overwrite_buffer](overwrite-buffer-class.md)   
 [Classe unbounded_buffer](unbounded-buffer-class.md)


