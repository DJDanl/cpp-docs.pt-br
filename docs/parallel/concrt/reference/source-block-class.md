---
title: Classe source_block | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- agents/concurrency::source_block
dev_langs:
- C++
helpviewer_keywords:
- source_block class
ms.assetid: fbdd4146-e8d0-42e8-b714-fe633f69ffbf
caps.latest.revision: 20
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
ms.openlocfilehash: 7d459d03153e95b779b8f8b19d2a68602b33acf8
ms.lasthandoff: 02/25/2017

---
# <a name="sourceblock-class"></a>Classe source_block
O `source_block` classe é uma classe base abstrata para blocos de código-fonte. A classe fornece funcionalidade de gerenciamento básico de link como comuns bem como verificações de erro.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class _TargetLinkRegistry, class _MessageProcessorType = ordered_message_processor<typename _TargetLinkRegistry::type::type>>
class source_block : public ISource<typename _TargetLinkRegistry::type::type>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_TargetLinkRegistry`  
 Registro de link a ser usado para manter os links de destino.  
  
 `_MessageProcessorType`  
 Tipo de processador para o processamento da mensagem.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`target_iterator`|O iterador para percorrer os destinos conectados.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor source_block](#ctor)|Constrói um objeto `source_block`.|  
|[~ source_block destruidor](#dtor)|Destrói o `source_block` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Accept](#accept)|Aceita uma mensagem que foi oferecida por esse `source_block` objeto, transferir a propriedade para o chamador.|  
|[Método acquire_ref](#acquire_ref)|Adquire uma contagem de referência sobre isso `source_block` objeto, para impedir a exclusão.|  
|[Método Consume](#consume)|Consome uma mensagem anteriormente oferecida por esse `source_block` object e reservada com êxito pelo destino, transferindo a propriedade para o chamador.|  
|[Método link_target](#link_target)|Um bloco de destino está vinculada a esta `source_block` objeto.|  
|[Método de liberação](#release)|Libera uma reserva de mensagem bem-sucedida anterior.|  
|[Método release_ref](#release_ref)|Libera uma contagem de referência sobre isso `source_block` objeto.|  
|[Método Reserve](#reserve)|Reserva uma mensagem anteriormente oferecida por esse `source_block` objeto.|  
|[Método unlink_target](#unlink_target)|Desvincula um bloco de destino deste `source_block` objeto.|  
|[Método unlink_targets](#unlink_targets)|Desvincula todos os blocos de destino deste `source_block` objeto. (Substitui [ISource](isource-class.md#unlink_targets).)|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método accept_message](#accept_message)|Quando substituído em uma classe derivada, aceita uma mensagem oferecida pela origem. Blocos de mensagens devem substituir esse método para validar o `_MsgId` e retornar uma mensagem.|  
|[Método async_send](#async_send)|Enfileira mensagens de forma assíncrona e inicia uma tarefa de propagação, se isso não foi feito já|  
|[Método consume_message](#consume_message)|Quando substituído em uma classe derivada, consome uma mensagem que foi reservada anteriormente.|  
|[Método enable_batched_processing](#enable_batched_processing)|Habilita em lote de processamento para este bloco.|  
|[Método initialize_source](#initialize_source)|Inicializa o `message_propagator` dentro dessa `source_block`.|  
|[Método link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `source_block` objeto.|  
|[Método process_input_messages](#process_input_messages)|Processar mensagens de entrada. Isso é útil somente para blocos de propagador, que derivam de source_block|  
|[Método propagate_output_messages](#propagate_output_messages)|Propaga as mensagens para destinos.|  
|[Método propagate_to_any_targets](#propagate_to_any_targets)|Quando substituído em uma classe derivada, propaga a mensagem determinada a alguns ou todos os destinos vinculados. Isso é a rotina de propagação principal para blocos de mensagens.|  
|[Método release_message](#release_message)|Quando substituído em uma classe derivada, libera uma reserva de mensagem anterior.|  
|[Método remove_targets](#remove_targets)|Remove todos os links de destino para este bloco de código-fonte. Isso deve ser chamado de destruidor.|  
|[Método reserve_message](#reserve_message)|Quando substituído em uma classe derivada, reserva uma mensagem anteriormente oferecida por esse `source_block` objeto.|  
|[Método resume_propagation](#resume_propagation)|Quando substituído em uma classe derivada, continua a propagação após uma reserva foi lançada.|  
|[Método sync_send](#sync_send)|De forma síncrona filas de mensagens e inicia uma tarefa de propagação, se isso não foi feito já.|  
|[Método unlink_target_notification](#unlink_target_notification)|Um retorno de chamada que notifica que um destino foi desvinculado disso `source_block` objeto.|  
|[Método wait_for_outstanding_async_sends](#wait_for_outstanding_async_sends)|Aguarda até que todas as propagações assíncronas concluir. Essa espera de rotação propagador específico é usada em destruidores de blocos de mensagens para certificar-se de que todas as propagações assíncronas tem tempo para concluir antes de destruir o bloco.|  
  
## <a name="remarks"></a>Comentários  
 Blocos de mensagens devem derivar desse bloco para tirar proveito do gerenciamento de link e sincronização fornecidos por essa classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](isource-class.md)  
  
 `source_block`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-nameaccepta-accept"></a><a name="accept"></a>aceitar 

 Aceita uma mensagem que foi oferecida por esse `source_block` objeto, transferir a propriedade para o chamador.  
  
```
virtual message<_Target_type>* accept(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Target_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` da oferecida `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `accept` método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
### <a name="remarks"></a>Comentários  
 O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_PTarget` é `NULL`.  
  
 O `accept` método é chamado por um destino, enquanto uma mensagem está sendo oferecida por esse `ISource` bloco. O ponteiro de mensagem retornado pode ser diferente do passado para o `propagate` método o `ITarget` bloquear, se essa fonte decide fazer uma cópia da mensagem.  
  
##  <a name="a-nameacceptmessagea-acceptmessage"></a><a name="accept_message"></a>accept_message 

 Quando substituído em uma classe derivada, aceita uma mensagem oferecida pela origem. Blocos de mensagens devem substituir esse método para validar o `_MsgId` e retornar uma mensagem.  
  
```
virtual message<_Target_type>* accept_message(runtime_object_identity _MsgId) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 A identidade do objeto de tempo de execução do `message` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a mensagem que o chamador agora é o proprietário.  
  
### <a name="remarks"></a>Comentários  
 Para transferir a propriedade, o ponteiro original da mensagem deve ser retornado. Para manter a propriedade, uma cópia da carga da mensagem deve ser feita e retornado.  
  
##  <a name="a-nameacquirerefa-acquireref"></a><a name="acquire_ref"></a>acquire_ref 

 Adquire uma contagem de referência sobre isso `source_block` objeto, para impedir a exclusão.  
  
```
virtual void acquire_ref(_Inout_ ITarget<_Target_type> *);
```  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo vinculado a esta fonte durante o `link_target` método.  
  
##  <a name="a-nameasyncsenda-asyncsend"></a><a name="async_send"></a>async_send 

 Enfileira mensagens de forma assíncrona e inicia uma tarefa de propagação, se isso não foi feito já  
  
```
virtual void async_send(_Inout_opt_ message<_Target_type>* _Msg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Msg`  
 Um ponteiro para um `message` objeto a ser enviado de forma assíncrona.  
  
##  <a name="a-nameconsumea-consume"></a><a name="consume"></a>consumir 

 Consome uma mensagem anteriormente oferecida por esse `source_block` object e reservada com êxito pelo destino, transferindo a propriedade para o chamador.  
  
```
virtual message<_Target_type>* consume(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Target_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` de reservado `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `consume` método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
### <a name="remarks"></a>Comentários  
 O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_PTarget` é `NULL`.  
  
 O método lança um [bad_target](bad-target-class.md) exceção se o parâmetro `_PTarget` não representa o destino chamado `reserve`.  
  
 O `consume` método é semelhante ao `accept`, mas sempre deve ser precedido por uma chamada para `reserve` que retornou `true`.  
  
##  <a name="a-nameconsumemessagea-consumemessage"></a><a name="consume_message"></a>consume_message 

 Quando substituído em uma classe derivada, consome uma mensagem que foi reservada anteriormente.  
  
```
virtual message<_Target_type>* consume_message(runtime_object_identity _MsgId) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` do objeto que está sendo consumida.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a mensagem que o chamador agora é o proprietário.  
  
### <a name="remarks"></a>Comentários  
 Semelhante ao `accept`, mas sempre é precedido por uma chamada para `reserve`.  
  
##  <a name="a-nameenablebatchedprocessinga-enablebatchedprocessing"></a><a name="enable_batched_processing"></a>enable_batched_processing 

 Habilita em lote de processamento para este bloco.  
  
```
void enable_batched_processing();
```  
  
##  <a name="a-nameinitializesourcea-initializesource"></a><a name="initialize_source"></a>initialize_source 

 Inicializa o `message_propagator` dentro dessa `source_block`.  
  
```
void initialize_source(
    _Inout_opt_ Scheduler* _PScheduler = NULL,
    _Inout_opt_ ScheduleGroup* _PScheduleGroup = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PScheduler`  
 O Agendador a ser usado para o agendamento de tarefas.  
  
 `_PScheduleGroup`  
 O grupo de programação a ser usado para o agendamento de tarefas.  
  
##  <a name="a-namelinktargeta-linktarget"></a><a name="link_target"></a>link_target 

 Um bloco de destino está vinculada a esta `source_block` objeto.  
  
```
virtual void link_target(_Inout_ ITarget<_Target_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para um `ITarget` bloco para vincular a este `source_block` objeto.  
  
### <a name="remarks"></a>Comentários  
 O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_PTarget` é `NULL`.  
  
##  <a name="a-namelinktargetnotificationa-linktargetnotification"></a><a name="link_target_notification"></a>link_target_notification 

 Um retorno de chamada que notifica que um novo destino foi vinculado a este `source_block` objeto.  
  
```
virtual void link_target_notification(_Inout_ ITarget<_Target_type> *);
```  
  
##  <a name="a-nameprocessinputmessagesa-processinputmessages"></a><a name="process_input_messages"></a>process_input_messages 

 Processar mensagens de entrada. Isso é útil somente para blocos de propagador, que derivam de source_block  
  
```
virtual void process_input_messages(_Inout_ message<_Target_type>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
  
##  <a name="a-namepropagateoutputmessagesa-propagateoutputmessages"></a><a name="propagate_output_messages"></a>propagate_output_messages 

 Propaga as mensagens para destinos.  
  
```
virtual void propagate_output_messages();
```  
  
##  <a name="a-namepropagatetoanytargetsa-propagatetoanytargets"></a><a name="propagate_to_any_targets"></a>propagate_to_any_targets 

 Quando substituído em uma classe derivada, propaga a mensagem determinada a alguns ou todos os destinos vinculados. Isso é a rotina de propagação principal para blocos de mensagens.  
  
```
virtual void propagate_to_any_targets(_Inout_opt_ message<_Target_type>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para a mensagem a ser propagado.  
  
##  <a name="a-namereleasea-release"></a><a name="release"></a>versão 

 Libera uma reserva de mensagem bem-sucedida anterior.  
  
```
virtual void release(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Target_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` de reservado `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `release` método.  
  
### <a name="remarks"></a>Comentários  
 O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_PTarget` é `NULL`.  
  
 O método lança um [bad_target](bad-target-class.md) exceção se o parâmetro `_PTarget` não representa o destino chamado `reserve`.  
  
##  <a name="a-namereleasemessagea-releasemessage"></a><a name="release_message"></a>release_message 

 Quando substituído em uma classe derivada, libera uma reserva de mensagem anterior.  
  
```
virtual void release_message(runtime_object_identity _MsgId) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` objeto sendo lançada.  
  
##  <a name="a-namereleaserefa-releaseref"></a><a name="release_ref"></a>release_ref 

 Libera uma contagem de referência sobre isso `source_block` objeto.  
  
```
virtual void release_ref(_Inout_ ITarget<_Target_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando este método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de código-fonte pode liberar quaisquer recursos reservados para o bloco de destino.  
  
##  <a name="a-nameremovetargetsa-removetargets"></a><a name="remove_targets"></a>remove_targets 

 Remove todos os links de destino para este bloco de código-fonte. Isso deve ser chamado de destruidor.  
  
```
void remove_targets();
```  
  
##  <a name="a-namereservea-reserve"></a><a name="reserve"></a>reservar 

 Reserva uma mensagem anteriormente oferecida por esse `source_block` objeto.  
  
```
virtual bool reserve(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Target_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` da oferecida `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `reserve` método.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se a mensagem foi reservada com êxito, `false` caso contrário. Reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceito por outro destino, a origem pode negar reservas e assim por diante.  
  
### <a name="remarks"></a>Comentários  
 O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_PTarget` é `NULL`.  
  
 Depois de você chamar `reserve`, se for bem-sucedida, você deve chamar `consume` ou `release` para levar ou desistir de posse da mensagem, respectivamente.  
  
##  <a name="a-namereservemessagea-reservemessage"></a><a name="reserve_message"></a>reserve_message 

 Quando substituído em uma classe derivada, reserva uma mensagem anteriormente oferecida por esse `source_block` objeto.  
  
```
virtual bool reserve_message(runtime_object_identity _MsgId) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` do objeto que está sendo reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se a mensagem foi reservada com êxito, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Depois de `reserve` é chamado, se ele retorna `true`, `consume` ou `release` deve ser chamado para executar ou liberar a propriedade da mensagem.  
  
##  <a name="a-nameresumepropagationa-resumepropagation"></a><a name="resume_propagation"></a>resume_propagation 

 Quando substituído em uma classe derivada, continua a propagação após uma reserva foi lançada.  
  
```
virtual void resume_propagation() = 0;
```  
  
##  <a name="a-namectora-sourceblock"></a><a name="ctor"></a>source_block 

 Constrói um objeto `source_block`.  
  
```
source_block();
```  
  
##  <a name="a-namedtora-sourceblock"></a><a name="dtor"></a>~ source_block 

 Destrói o `source_block` objeto.  
  
```
virtual ~source_block();
```  
  
##  <a name="a-namesyncsenda-syncsend"></a><a name="sync_send"></a>sync_send 

 De forma síncrona filas de mensagens e inicia uma tarefa de propagação, se isso não foi feito já.  
  
```
virtual void sync_send(_Inout_opt_ message<_Target_type>* _Msg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Msg`  
 Um ponteiro para um `message` objeto a ser enviado de forma síncrona.  
  
##  <a name="a-nameunlinktargeta-unlinktarget"></a><a name="unlink_target"></a>unlink_target 

 Desvincula um bloco de destino deste `source_block` objeto.  
  
```
virtual void unlink_target(_Inout_ ITarget<_Target_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para um `ITarget` bloco de desvinculação disso `source_block` objeto.  
  
### <a name="remarks"></a>Comentários  
 O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_PTarget` é `NULL`.  
  
##  <a name="a-nameunlinktargetnotificationa-unlinktargetnotification"></a><a name="unlink_target_notification"></a>unlink_target_notification 

 Um retorno de chamada que notifica que um destino foi desvinculado disso `source_block` objeto.  
  
```
virtual void unlink_target_notification(_Inout_ ITarget<_Target_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 O `ITarget` bloco foi desvinculado.  
  
##  <a name="a-nameunlinktargetsa-unlinktargets"></a><a name="unlink_targets"></a>unlink_targets 

 Desvincula todos os blocos de destino deste `source_block` objeto.  
  
```
virtual void unlink_targets();
```  
  
##  <a name="a-namewaitforoutstandingasyncsendsa-waitforoutstandingasyncsends"></a><a name="wait_for_outstanding_async_sends"></a>wait_for_outstanding_async_sends 

 Aguarda até que todas as propagações assíncronas concluir. Essa espera de rotação propagador específico é usada em destruidores de blocos de mensagens para certificar-se de que todas as propagações assíncronas tem tempo para concluir antes de destruir o bloco.  
  
```
void wait_for_outstanding_async_sends();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe ISource](isource-class.md)

