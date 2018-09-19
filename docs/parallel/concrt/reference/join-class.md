---
title: Classe JOIN | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- join
- AGENTS/concurrency::join
- AGENTS/concurrency::join::join
- AGENTS/concurrency::join::accept_message
- AGENTS/concurrency::join::consume_message
- AGENTS/concurrency::join::link_target_notification
- AGENTS/concurrency::join::propagate_message
- AGENTS/concurrency::join::propagate_to_any_targets
- AGENTS/concurrency::join::release_message
- AGENTS/concurrency::join::reserve_message
- AGENTS/concurrency::join::resume_propagation
dev_langs:
- C++
helpviewer_keywords:
- join class
ms.assetid: d2217119-70a1-40b6-809f-c1c13a571c3f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 46073d07cbca27256ca169ab94e0fe027bf98b15
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46118850"
---
# <a name="join-class"></a>Classe join
Um `join` bloco de mensagem é um destino de único, várias fontes, ordenada `propagator_block` que combina as mensagens do tipo `T` de cada uma das suas fontes.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T,
    join_type _Jtype = non_greedy>
class join : public propagator_block<single_link_registry<ITarget<std::vector<T>>>,
    multi_link_registry<ISource<T>>>;
```   
  
#### <a name="parameters"></a>Parâmetros  
*T*<br/>
O tipo de carga das mensagens ingressou e propagada pelo bloco.  
  
*_Jtype*<br/>
O tipo de `join` bloco é `greedy` ou `non_greedy`  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[join](#ctor)|Sobrecarregado. Constrói um `join` bloco de mensagem.|  
|[~ join destruidor](#dtor)|Destrói o `join` bloco.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[accept_message](#accept_message)|Aceita uma mensagem que era oferecida por este `join` bloco de mensagens, transferindo a propriedade para o chamador.|  
|[consume_message](#consume_message)|Consome uma mensagem anteriormente oferecida pelos `join` bloco de mensagens e reservado pelo destino, transferindo a propriedade para o chamador.|  
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `join` bloco de mensagem.|  
|[propagate_message](#propagate_message)|Passa assincronamente uma mensagem de um `ISource` bloco a este `join` bloco de mensagem. Ele é invocado pelo `propagate` método, quando chamado por um bloco de código-fonte.|  
|[propagate_to_any_targets](#propagate_to_any_targets)|Constrói uma mensagem de saída que contém uma mensagem de entrada de cada fonte quando eles forem propagados uma mensagem. Envia essa mensagem de saída para cada um dos seus destinos.|  
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|  
|[reserve_message](#reserve_message)|Reserva uma mensagem anteriormente oferecida por este `join` bloco de mensagem. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|  
|[resume_propagation](#resume_propagation)|Retoma a propagação depois de uma reserva foi liberada. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](isource-class.md)  
  
 [ITarget](itarget-class.md)  
  
 [source_block](source-block-class.md)  
  
 [propagator_block](propagator-block-class.md)  
  
 `join`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Agents. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="accept_message"></a> accept_message 

 Aceita uma mensagem que era oferecida por este `join` bloco de mensagens, transferindo a propriedade para o chamador.  
  
```
virtual message<_OutputType>* accept_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
*_MsgId*<br/>
O `runtime_object_identity` do que o oferecido `message` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.  
  
##  <a name="consume_message"></a> consume_message 

 Consome uma mensagem anteriormente oferecida pelos `join` bloco de mensagens e reservado pelo destino, transferindo a propriedade para o chamador.  
  
```
virtual message<_OutputType>* consume_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo consumido.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.  
  
### <a name="remarks"></a>Comentários  
 Semelhante ao `accept`, mas sempre é precedido por uma chamada para `reserve`.  
  
##  <a name="ctor"></a> junção 

 Constrói um `join` bloco de mensagem.  
  
```
join(
    size_t _NumInputs);

join(
    size_t _NumInputs,
    filter_method const& _Filter);

join(
    Scheduler& _PScheduler,
    size_t _NumInputs);

join(
    Scheduler& _PScheduler,
    size_t _NumInputs,
    filter_method const& _Filter);

join(
    ScheduleGroup& _PScheduleGroup,
    size_t _NumInputs);

join(
    ScheduleGroup& _PScheduleGroup,
    size_t _NumInputs,
    filter_method const& _Filter);
```  
  
### <a name="parameters"></a>Parâmetros  
*_NumInputs*<br/>
O número de entradas isso `join` bloco será permitido.  
  
*Filtro*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.  
  
*_PScheduler*<br/>
O `Scheduler` objeto dentro do qual a tarefa de propagação para o `join` bloco de mensagem está agendado.  
  
*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto dentro do qual a tarefa de propagação para o `join` bloco de mensagem está agendado. O `Scheduler` objeto usado é inferido pelo grupo agendado.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão, se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.  
  
 O tipo `filter_method` é um funtor com assinatura `bool (T const &)` que é invocado por este `join` bloco de mensagem para determinar se ele deve aceitar uma mensagem oferecida.  
  
##  <a name="dtor"></a> ~join 

 Destrói o `join` bloco.  
  
```
~join();
```  
  
##  <a name="link_target_notification"></a> link_target_notification 

 Um retorno de chamada que notifica que um novo destino foi vinculado a este `join` bloco de mensagem.  
  
```
virtual void link_target_notification(_Inout_ ITarget<std::vector<T>> *);
```  
  
##  <a name="propagate_message"></a> propagate_message 

 Passa assincronamente uma mensagem de um `ISource` bloco a este `join` bloco de mensagem. Ele é invocado pelo `propagate` método, quando chamado por um bloco de código-fonte.  
  
```
message_status propagate_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
*_PMessage*<br/>
Um ponteiro para o `message` objeto.  
  
*_PSource*<br/>
Um ponteiro para o bloco de código-fonte, oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="propagate_to_any_targets"></a> propagate_to_any_targets 

 Constrói uma mensagem de saída que contém uma mensagem de entrada de cada fonte quando eles forem propagados uma mensagem. Envia essa mensagem de saída para cada um dos seus destinos.  
  
```
void propagate_to_any_targets(_Inout_opt_ message<_OutputType> *);
```  
  
##  <a name="release_message"></a> release_message 

 Libera uma reserva de mensagem anterior.  
  
```
virtual void release_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo lançada.  
  
##  <a name="reserve_message"></a> reserve_message 

 Reserva uma mensagem anteriormente oferecida por este `join` bloco de mensagem.  
  
```
virtual bool reserve_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
*_MsgId*<br/>
O `runtime_object_identity` do que o oferecido `message` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se a mensagem foi reservada com êxito, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Após `reserve` é chamado, se ele retornar `true`, ambos `consume` ou `release` deve ser chamado para executar ou liberar a propriedade da mensagem.  
  
##  <a name="resume_propagation"></a> resume_propagation 

 Retoma a propagação depois de uma reserva foi liberada.  
  
```
virtual void resume_propagation();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe Choice](choice-class.md)   
 [Classe multitype_join](multitype-join-class.md)
