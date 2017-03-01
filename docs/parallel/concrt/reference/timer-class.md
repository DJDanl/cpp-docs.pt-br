---
title: Classe Timer | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- agents/concurrency::timer
dev_langs:
- C++
helpviewer_keywords:
- timer class
ms.assetid: 4f4dea51-de9f-40f9-93f5-dd724c567b49
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
ms.openlocfilehash: 769ccd051c68f0a4d74511392f0f1a811e36e3e7
ms.lasthandoff: 02/25/2017

---
# <a name="timer-class"></a>Classe timer
A `timer` bloco de mensagens é um destino único `source_block` capaz de enviar uma mensagem para seu destino após um período de tempo decorrido ou em intervalos específicos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class timer : public Concurrency::details::_Timer, public source_block<single_link_registry<ITarget<T>>>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de carga das mensagens de saída desse bloco.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor Timer](#ctor)|Sobrecarregado. Constrói um `timer` bloco de mensagens que irá disparar uma determinada mensagem após um intervalo especificado.|  
|[~ timer destruidor](#dtor)|Destrói um `timer` bloco de mensagens.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método pause](#pause)|Interrompe o `timer` bloco de mensagens. Se for uma repetição `timer` bloco de mensagens, ele pode ser reiniciado com um subsequentes `start()` chamar. Para não-repetição temporizadores, isso tem o mesmo efeito que uma `stop` chamar.|  
|[Método Start](#start)|Inicia o `timer` bloco de mensagens. O número especificado de milissegundos depois de fazer isso é chamado, o valor especificado será propagado downstream como um `message`.|  
|[Método Stop](#stop)|Interrompe o `timer` bloco de mensagens.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método accept_message](#accept_message)|Aceita uma mensagem que foi oferecida por esse `timer` bloco de mensagens, transferindo a propriedade para o chamador.|  
|[Método consume_message](#consume_message)|Consome uma mensagem anteriormente oferecida pelo `timer` e reservado pelo destino, transferindo a propriedade para o chamador.|  
|[Método link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `timer` bloco de mensagens.|  
|[Método propagate_to_any_targets](#propagate_to_any_targets)|Tenta oferecer a mensagem produzida pelo `timer` bloco para todos os destinos vinculados.|  
|[Método release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|  
|[Método reserve_message](#reserve_message)|Reserva uma mensagem anteriormente oferecida por esse `timer` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|  
|[Método resume_propagation](#resume_propagation)|Retoma a propagação após uma reserva foi lançada. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](isource-class.md)  
  
 [source_block](source-block-class.md)  
  
 `timer`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-nameacceptmessagea-acceptmessage"></a><a name="accept_message"></a>accept_message 

 Aceita uma mensagem que foi oferecida por esse `timer` bloco de mensagens, transferindo a propriedade para o chamador.  
  
```
virtual message<T>* accept_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` da oferecida `message` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
##  <a name="a-nameconsumemessagea-consumemessage"></a><a name="consume_message"></a>consume_message 

 Consome uma mensagem anteriormente oferecida pelo `timer` e reservado pelo destino, transferindo a propriedade para o chamador.  
  
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
  
##  <a name="a-namelinktargetnotificationa-linktargetnotification"></a><a name="link_target_notification"></a>link_target_notification 

 Um retorno de chamada que notifica que um novo destino foi vinculado a este `timer` bloco de mensagens.  
  
```
virtual void link_target_notification(_Inout_ ITarget<T>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o destino vinculado recentemente.  
  
##  <a name="a-namepausea-pause"></a><a name="pause"></a>Pausar 

 Interrompe o `timer` bloco de mensagens. Se for uma repetição `timer` bloco de mensagens, ele pode ser reiniciado com um subsequentes `start()` chamar. Para não-repetição temporizadores, isso tem o mesmo efeito que uma `stop` chamar.  
  
```
void pause();
```  
  
##  <a name="a-namepropagatetoanytargetsa-propagatetoanytargets"></a><a name="propagate_to_any_targets"></a>propagate_to_any_targets 

 Tenta oferecer a mensagem produzida pelo `timer` bloco para todos os destinos vinculados.  
  
```
virtual void propagate_to_any_targets(_Inout_opt_ message<T> *);
```  
  
##  <a name="a-namereleasemessagea-releasemessage"></a><a name="release_message"></a>release_message 

 Libera uma reserva de mensagem anterior.  
  
```
virtual void release_message(runtime_object_identity _MsgId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` objeto sendo lançada.  
  
##  <a name="a-namereservemessagea-reservemessage"></a><a name="reserve_message"></a>reserve_message 

 Reserva uma mensagem anteriormente oferecida por esse `timer` bloco de mensagens.  
  
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
  
##  <a name="a-namestarta-start"></a><a name="start"></a>Iniciar 

 Inicia o `timer` bloco de mensagens. O número especificado de milissegundos depois de fazer isso é chamado, o valor especificado será propagado downstream como um `message`.  
  
```
void start();
```  
  
##  <a name="a-namestopa-stop"></a><a name="stop"></a>parar 

 Interrompe o `timer` bloco de mensagens.  
  
```
void stop();
```  
  
##  <a name="a-namectora-timer"></a><a name="ctor"></a>Timer 

 Constrói um `timer` bloco de mensagens que irá disparar uma determinada mensagem após um intervalo especificado.  
  
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
 O número de milissegundos que deve decorrer após a chamada ao início da mensagem especificado seja propagada downstream.  
  
 `value`  
 O valor que será propagado downstream quando o timer expira.  
  
 `_PTarget`  
 O destino ao qual o timer propagarão sua mensagem.  
  
 `_Repeating`  
 Se for verdadeiro, indica que o temporizador será acionado periodicamente cada `_Ms` milissegundos.  
  
 `_Scheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefa para o `timer` bloco de mensagens está agendado está agendada.  
  
 `_ScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefa para o `timer` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_Scheduler` ou `_ScheduleGroup` parâmetros.  
  
##  <a name="a-namedtora-timer"></a><a name="dtor"></a>~ timer 

 Destrói um `timer` bloco de mensagens.  
  
```
~timer();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

