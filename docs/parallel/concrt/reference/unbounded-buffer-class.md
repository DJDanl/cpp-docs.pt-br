---
title: Classe unbounded_buffer | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- unbounded_buffer
dev_langs:
- C++
ms.assetid: 6b1a939a-1819-4385-b1d8-708f83d4ec47
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 561f2eea7a2eb19d8cc0162df8bf659f22da1065
ms.lasthandoff: 02/25/2017

---


Um `unbounded_buffer` bloco de mensagens é um destino de vários com várias fontes, ordenada `propagator_block` capaz de armazenar um número ilimitado de mensagens.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<  
   class             _Type  
>  
class unbounded_buffer : public propagator_block<multi_link_registry<ITarget<            _Type>>, multi_link_registry<ISource<            _Type>>>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Type`  
 O tipo de carga de mensagens armazenadas e propagada pelo buffer.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor unbounded_buffer](#ctor)|Sobrecarregado. Constrói um `unbounded_buffer` bloco de mensagens.|  
|[~ unbounded_buffer destruidor](#dtor)|Destrói o `unbounded_buffer` bloco de mensagens.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método dequeue](#dequeue)|Remove um item do `unbounded_buffer` bloco de mensagens.|  
|[Método enqueue](#enqueue)|Adiciona um item para o `unbounded_buffer` bloco de mensagens.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método accept_message](#accept_message)|Aceita uma mensagem que foi oferecida por esse `unbounded_buffer` bloco de mensagens, transferindo a propriedade para o chamador.|  
|[Método consume_message](#consume_message)|Consome uma mensagem anteriormente oferecida pelo `unbounded_buffer` bloco de mensagens e reservado pelo destino, transferindo a propriedade para o chamador.|  
|[Método link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `unbounded_buffer` bloco de mensagens.|  
|[Método process_input_messages](#process_input_messages)|Locais de `message``_PMessage` neste `unbounded_buffer` bloco de mensagens e tenta oferecê-lo para todos os destinos vinculados.|  
|[Método propagate_message](#propagate_message)|Assincronamente transmite uma mensagem de uma `ISource` bloco a esta `unbounded_buffer` bloco de mensagens. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.|  
|[Método propagate_output_messages](#propagate_output_messages)|Locais de `message``_PMessage` neste `unbounded_buffer` bloco de mensagens e tenta oferecê-lo para todos os destinos vinculados. (Substitui [source_block:: propagate_output_messages](source-block-class.md#propagate_output_messages).)|  
|[Método release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|  
|[Método reserve_message](#reserve_message)|Reserva uma mensagem anteriormente oferecida por esse `unbounded_buffer` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|  
|[Método resume_propagation](#resume_propagation)|Retoma a propagação após uma reserva foi lançada. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|  
|[Método send_message](#send_message)|Sincronicamente transmite uma mensagem de uma `ISource` bloco a esta `unbounded_buffer` bloco de mensagens. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.|  
|[Método supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada. (Substitui [Supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|  

 Para obter mais informações, consulte [blocos de mensagens assíncronas](../asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](isource-class.md)  
  
 [ITarget](itarget-class.md)  
  
 [source_block](source-block-class.md)  
  
 [propagator_block](propagator-block-class.md)  
  
 `unbounded_buffer`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-nameacceptmessagea-acceptmessage"></a><a name="accept_message"></a>accept_message 

 Aceita uma mensagem que foi oferecida por esse `unbounded_buffer` bloco de mensagens, transferindo a propriedade para o chamador.  
  
```  
virtual message<_Type> * accept_message(  
   runtime_object_identity                 _MsgId  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` da oferecida `message` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
##  <a name="a-nameconsumemessagea-consumemessage"></a><a name="consume_message"></a>consume_message 

 Consome uma mensagem anteriormente oferecida pelo `unbounded_buffer` bloco de mensagens e reservado pelo destino, transferindo a propriedade para o chamador.  
  
```  
virtual message<_Type> * consume_message(  
   runtime_object_identity                 _MsgId  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` do objeto que está sendo consumida.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
### <a name="remarks"></a>Comentários  
 Semelhante ao `accept`, mas sempre é precedido por uma chamada para `reserve`.  
  
##  <a name="a-namedequeuea-dequeue"></a><a name="dequeue"></a>remoção da fila 

 Remove um item do `unbounded_buffer` bloco de mensagens.  
  
```  
_Type dequeue();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A carga da mensagem removida a `unbounded_buffer`.  
  
##  <a name="a-nameenqueuea-enqueue"></a><a name="enqueue"></a>enqueue 

 Adiciona um item para o `unbounded_buffer` bloco de mensagens.  
  
```  
bool enqueue(  
   _Type const&                 _Item  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Item`  
 Item a ser adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o item tiver sido aceita, `false` caso contrário.  
  
##  <a name="a-namelinktargetnotificationa-linktargetnotification"></a><a name="link_target_notification"></a>link_target_notification 

 Um retorno de chamada que notifica que um novo destino foi vinculado a este `unbounded_buffer` bloco de mensagens.  
  
```  
virtual void link_target_notification(  
   _Inout_ ITarget<_Type> *                 _PTarget  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o destino vinculado recentemente.  
  
##  <a name="a-namepropagatemessagea-propagatemessage"></a><a name="propagate_message"></a>propagate_message 

 Assincronamente transmite uma mensagem de uma `ISource` bloco a esta `unbounded_buffer` bloco de mensagens. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.  
  
```  
virtual message_status propagate_message(  
   _Inout_ message<_Type> *                 _PMessage,  
   _Inout_ ISource<_Type> *                 _PSource  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 A [message_status](concurrency-namespace-enums.md#message_status) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="a-namepropagateoutputmessagesa-propagateoutputmessages"></a><a name="propagate_output_messages"></a>propagate_output_messages 

 Locais de `message``_PMessage` neste `unbounded_buffer` bloco de mensagens e tenta oferecê-lo para todos os destinos vinculados.  
  
```  
virtual void propagate_output_messages();  
```  
  
### <a name="remarks"></a>Comentários  
 Se outra mensagem já está à frente no `unbounded_buffer`, a propagação para destinos vinculados não ocorrerá até que todas as mensagens anteriores foram aceitas ou consumidas. A primeira vinculado do destino com êxito `accept` ou `consume` apropria-se a mensagem e nenhum outro destino, em seguida, pode receber a mensagem.  
  
##  <a name="a-nameprocessinputmessagesa-processinputmessages"></a><a name="process_input_messages"></a>process_input_messages 

 Locais de `message``_PMessage` neste `unbounded_buffer` bloco de mensagens e tenta oferecê-lo para todos os destinos vinculados.  
  
```  
virtual void process_input_messages(  
   _Inout_ message<_Type> *                 _PMessage  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
  
##  <a name="a-namereleasemessagea-releasemessage"></a><a name="release_message"></a>release_message 

 Libera uma reserva de mensagem anterior.  
  
```  
virtual void release_message(  
   runtime_object_identity                 _MsgId  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` objeto sendo lançada.  
  
##  <a name="a-namereservemessagea-reservemessage"></a><a name="reserve_message"></a>reserve_message 

 Reserva uma mensagem anteriormente oferecida por esse `unbounded_buffer` bloco de mensagens.  
  
```  
virtual bool reserve_message(  
   runtime_object_identity                 _MsgId  
);  
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

 Sincronicamente transmite uma mensagem de uma `ISource` bloco a esta `unbounded_buffer` bloco de mensagens. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.  
  
```  
virtual message_status send_message(  
   _Inout_ message<_Type> *                 _PMessage,  
   _Inout_ ISource<_Type> *                 _PSource  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 A [message_status](concurrency-namespace-enums.md#message_status) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="a-namesupportsanonymoussourcea-supportsanonymoussource"></a><a name="supports_anonymous_source"></a>supports_anonymous_source 

 Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada.  
  
```  
virtual bool supports_anonymous_source();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`como o bloco não adie oferecido mensagens.  
  
##  <a name="a-namectora-unboundedbuffer"></a><a name="ctor"></a>unbounded_buffer 

 Constrói um `unbounded_buffer` bloco de mensagens.  
  
```  
unbounded_buffer();  
  
unbounded_buffer(  
   filter_method const&                 _Filter  
);  
  
unbounded_buffer(  
   Scheduler&                 _PScheduler  
);  
  
unbounded_buffer(  
   Scheduler&                 _PScheduler,  
   filter_method const&                 _Filter  
);  
  
unbounded_buffer(  
   ScheduleGroup&                 _PScheduleGroup  
);  
  
unbounded_buffer(  
   ScheduleGroup&                 _PScheduleGroup,  
   filter_method const&                 _Filter  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Filter`  
 Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.  
  
 `_PScheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefa para o `unbounded_buffer` bloco de mensagens está agendado.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefa para o `unbounded_buffer` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.  
  
 O tipo `filter_method` é um functor com assinatura `bool (_Type const &)` que é invocado por este `unbounded_buffer` bloco de mensagens para determinar se ele deve aceitar uma mensagem oferecida.  
  
##  <a name="a-namedtora-unboundedbuffer"></a><a name="dtor"></a>~ unbounded_buffer 

 Destrói o `unbounded_buffer` bloco de mensagens.  
  
```  
~unbounded_buffer();  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe overwrite_buffer](overwrite-buffer-class.md)   
 [Classe single_assignment](single-assignment-class.md)



