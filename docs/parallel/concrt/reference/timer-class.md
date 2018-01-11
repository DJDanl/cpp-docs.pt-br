---
title: Classe Timer | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- timer
- AGENTS/concurrency::timer
- AGENTS/concurrency::timer::timer
- AGENTS/concurrency::timer::pause
- AGENTS/concurrency::timer::start
- AGENTS/concurrency::timer::stop
- AGENTS/concurrency::timer::accept_message
- AGENTS/concurrency::timer::consume_message
- AGENTS/concurrency::timer::link_target_notification
- AGENTS/concurrency::timer::propagate_to_any_targets
- AGENTS/concurrency::timer::release_message
- AGENTS/concurrency::timer::reserve_message
- AGENTS/concurrency::timer::resume_propagation
dev_langs: C++
helpviewer_keywords: timer class
ms.assetid: 4f4dea51-de9f-40f9-93f5-dd724c567b49
caps.latest.revision: "21"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3ffc58ce0354b4a3226db82a95d5c0b4cc7bc09f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="timer-class"></a>Classe timer
Um `timer` bloco de mensagens é um destino único `source_block` capaz de enviar uma mensagem ao destino após determinado período de tempo ou em intervalos específicos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class timer : public Concurrency::details::_Timer, public source_block<single_link_registry<ITarget<T>>>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de carga das mensagens de saída desse bloco.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Timer](#ctor)|Sobrecarregado. Constrói um `timer` bloco de mensagens que irá disparar uma mensagem fornecida após um intervalo especificado.|  
|[~ timer destruidor](#dtor)|Destrói um `timer` bloco de mensagens.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Pausar](#pause)|Interrompe o `timer` bloco de mensagens. Se for uma repetição `timer` bloco de mensagens, ele pode ser reiniciado com um subsequentes `start()` chamar. Para não repetitivo temporizadores, isso tem o mesmo efeito que um `stop` chamar.|  
|[start](#start)|Inicia o `timer` bloco de mensagens. O número especificado de milissegundos depois de fazer isso é chamado, o valor especificado será propagado downstream como um `message`.|  
|[parar](#stop)|Interrompe o `timer` bloco de mensagens.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[accept_message](#accept_message)|Aceita uma mensagem que foi fornecida por esse `timer` bloco de mensagens, transferir a propriedade para o chamador.|  
|[consume_message](#consume_message)|Consome uma mensagem anteriormente oferecida pelo `timer` e reservado pelo destino, transferir a propriedade para o chamador.|  
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `timer` bloco de mensagens.|  
|[propagate_to_any_targets](#propagate_to_any_targets)|Tenta oferecer a mensagem produzida pelo `timer` bloco para todos os destinos vinculados.|  
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|  
|[reserve_message](#reserve_message)|Reserva uma mensagem anteriormente oferecida por este `timer` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|  
|[resume_propagation](#resume_propagation)|Retoma a propagação depois de uma reserva foi liberada. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](isource-class.md)  
  
 [source_block](source-block-class.md)  
  
 `timer`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="accept_message"></a>accept_message 

 Aceita uma mensagem que foi fornecida por esse `timer` bloco de mensagens, transferir a propriedade para o chamador.  
  
```
virtual message<T>* accept_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do que o oferecido `message` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
##  <a name="consume_message"></a>consume_message 

 Consome uma mensagem anteriormente oferecida pelo `timer` e reservado pelo destino, transferir a propriedade para o chamador.  
  
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
  
##  <a name="link_target_notification"></a>link_target_notification 

 Um retorno de chamada que notifica que um novo destino foi vinculado a este `timer` bloco de mensagens.  
  
```
virtual void link_target_notification(_Inout_ ITarget<T>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o destino recentemente vinculado.  
  
##  <a name="pause"></a>Pausar 

 Interrompe o `timer` bloco de mensagens. Se for uma repetição `timer` bloco de mensagens, ele pode ser reiniciado com um subsequentes `start()` chamar. Para não repetitivo temporizadores, isso tem o mesmo efeito que um `stop` chamar.  
  
```
void pause();
```  
  
##  <a name="propagate_to_any_targets"></a>propagate_to_any_targets 

 Tenta oferecer a mensagem produzida pelo `timer` bloco para todos os destinos vinculados.  
  
```
virtual void propagate_to_any_targets(_Inout_opt_ message<T> *);
```  
  
##  <a name="release_message"></a>release_message 

 Libera uma reserva de mensagem anterior.  
  
```
virtual void release_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` do objeto que está sendo liberado.  
  
##  <a name="reserve_message"></a>reserve_message 

 Reserva uma mensagem anteriormente oferecida por este `timer` bloco de mensagens.  
  
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
  
##  <a name="start"></a>Iniciar 

 Inicia o `timer` bloco de mensagens. O número especificado de milissegundos depois de fazer isso é chamado, o valor especificado será propagado downstream como um `message`.  
  
```
void start();
```  
  
##  <a name="stop"></a>parar 

 Interrompe o `timer` bloco de mensagens.  
  
```
void stop();
```  
  
##  <a name="ctor"></a>Timer 

 Constrói um `timer` bloco de mensagens que irá disparar uma mensagem fornecida após um intervalo especificado.  
  
```
timer(
    unsigned int _Ms,
    T const& value,
    ITarget<T>* _PTarget = NULL,
    bool _Repeating = false);

timer(
    Scheduler& _Scheduler,
    unsigned int _Ms,
    T const& value,
    _Inout_opt_ ITarget<T>* _PTarget = NULL,
    bool _Repeating = false);

timer(
    ScheduleGroup& _ScheduleGroup,
    unsigned int _Ms,
    T const& value,
    _Inout_opt_ ITarget<T>* _PTarget = NULL,
    bool _Repeating = false);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ms`  
 O número de milissegundos que deve decorrer após a chamada ao início da mensagem especificado sejam propagadas downstream.  
  
 `value`  
 O valor que será propagado downstream quando o timer expira.  
  
 `_PTarget`  
 O destino ao qual o timer propagarão sua mensagem.  
  
 `_Repeating`  
 Se for true, indica que o timer será acionado periodicamente cada `_Ms` milissegundos.  
  
 `_Scheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefas para o `timer` bloco de mensagens está agendado está agendada.  
  
 `_ScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefas para o `timer` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_Scheduler` ou `_ScheduleGroup` parâmetros.  
  
##  <a name="dtor"></a>~ timer 

 Destrói um `timer` bloco de mensagens.  
  
```
~timer();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
