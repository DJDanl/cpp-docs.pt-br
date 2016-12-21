---
title: "Classe multitype_join | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "agents/concurrency::multitype_join"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe multitype_join"
ms.assetid: 236e87a0-4867-49fd-869a-bef4010e49a7
caps.latest.revision: 20
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe multitype_join
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Um `multitype_join` Bloco de mensagens é um bloco de mensagens com várias fonte, destino único que juntos combina mensagens de diferentes tipos de cada uma das suas fontes e oferece uma tupla das mensagens combinadas para seus destinos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<
    typename T,  
    join_type _Jtype = non_greedy  
>  
class multitype_join: public ISource<typename _Unwrap<T>::type>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O `tuple` tipo de carga de mensagens ingressou e propagada pelo bloco.  
  
 `_Jtype`  
 O tipo de `join` bloco é `greedy` ou `non_greedy`  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`type`|Um alias de tipo para `T`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[multitype_join:: multitype_join construtor](#multitype_join__multitype_join_constructor)|Sobrecarregado. Constrói um `multitype_join` Bloco de mensagens.|  
|[multitype_join:: ~ multitype_join destruidor](#multitype_join___dtormultitype_join_destructor)|Destrói o `multitype_join` Bloco de mensagens.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[multitype_join:: método Accept](#multitype_join__accept_method)|Aceita uma mensagem que foi oferecida por esse `multitype_join` bloco, transferir a propriedade para o chamador.|  
|[Método multitype_join:: acquire_ref](#multitype_join__acquire_ref_method)|Adquire uma contagem de referência sobre isso `multitype_join` Bloco de mensagens, para impedir a exclusão.|  
|[Método multitype_join:: Consume](#multitype_join__consume_method)|Consome uma mensagem anteriormente oferecida pelo `multitype_join` Bloco de mensagens e reservada com êxito pelo destino, transferindo a propriedade para o chamador.|  
|[Método multitype_join:: link_target](#multitype_join__link_target_method)|Um bloco de destino está vinculada a esta `multitype_join` Bloco de mensagens.|  
|[Método multitype_join:: Release](#multitype_join__release_method)|Libera uma reserva de mensagem bem-sucedida anterior.|  
|[Método multitype_join:: release_ref](#multitype_join__release_ref_method)|Libera uma contagem de referência sobre isso `multiple_join` Bloco de mensagens.|  
|[Método multitype_join:: Reserve](#multitype_join__reserve_method)|Reserva uma mensagem anteriormente oferecida por esse `multitype_join` Bloco de mensagens.|  
|[Método multitype_join:: unlink_target](#multitype_join__unlink_target_method)|Desvincula um bloco de destino deste `multitype_join` Bloco de mensagens.|  
|[Método multitype_join:: unlink_targets](#multitype_join__unlink_targets_method)|Desvincula todos os destinos neste `multitype_join` Bloco de mensagens. (Substitui [ISource](../../../parallel/concrt/reference/isource-class.md#isource__unlink_targets_method).)|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](../../../parallel/concrt/reference/isource-class.md)  
  
 `multitype_join`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namemultitypejoinacceptmethoda-multitypejoinaccept-method"></a><a name="multitype_join__accept_method"></a>  multitype_join:: método Accept  
 Aceita uma mensagem que foi oferecida por esse `multitype_join` bloco, transferir a propriedade para o chamador.  
  
```  
virtual message<_Destination_type>* accept(
    runtime_object_identity _MsgId,  
    _Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` da oferecida `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `accept` método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a mensagem que o chamador agora é o proprietário.  
  
##  <a name="a-namemultitypejoinacquirerefmethoda-multitypejoinacquireref-method"></a><a name="multitype_join__acquire_ref_method"></a>  Método multitype_join:: acquire_ref  
 Adquire uma contagem de referência sobre isso `multitype_join` Bloco de mensagens, para impedir a exclusão.  
  
```  
virtual void acquire_ref(_Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando este método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo vinculado a esta fonte durante o `link_target` método.  
  
##  <a name="a-namemultitypejoinconsumemethoda-multitypejoinconsume-method"></a><a name="multitype_join__consume_method"></a>  Método multitype_join:: Consume  
 Consome uma mensagem anteriormente oferecida pelo `multitype_join` Bloco de mensagens e reservada com êxito pelo destino, transferindo a propriedade para o chamador.  
  
```  
virtual message<_Destination_type>* consume(
    runtime_object_identity _MsgId,  
    _Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` de reservado `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `consume` método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `message` que o chamador agora tem a propriedade do objeto.  
  
### <a name="remarks"></a>Comentários  
 O `consume` método é semelhante ao `accept`, mas sempre deve ser precedido por uma chamada para `reserve` que retornou `true`.  
  
##  <a name="a-namemultitypejoinlinktargetmethoda-multitypejoinlinktarget-method"></a><a name="multitype_join__link_target_method"></a>  Método multitype_join:: link_target  
 Um bloco de destino está vinculada a esta `multitype_join` Bloco de mensagens.  
  
```  
virtual void link_target(_Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para um `ITarget` bloco para vincular a este `multitype_join` Bloco de mensagens.  
  
##  <a name="a-namemultitypejoinmultitypejoinconstructora-multitypejoinmultitypejoin-constructor"></a><a name="multitype_join__multitype_join_constructor"></a>  multitype_join:: multitype_join construtor  
 Constrói um `multitype_join` Bloco de mensagens.  
  
```  
explicit multitype_join(
    T _Tuple);

 
multitype_join(
    Scheduler& _PScheduler,  
    T _Tuple);

 
multitype_join(
    ScheduleGroup& _PScheduleGroup,  
    T _Tuple);

 
multitype_join(
    multitype_join&& _Join);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Tuple`  
 Um `tuple` de fontes para isso `multitype_join` Bloco de mensagens.  
  
 `_PScheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefa para o `multitype_join` Bloco de mensagens está agendado.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefa para o `multitype_join` Bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
 `_Join`  
 Um `multitype_join` Bloco de mensagens para copiar de. Observe que o objeto original fica órfão, tornando isso um construtor de movimentação.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.  
  
 Construção de movimentação não é executada em um bloqueio, o que significa que o usuário para certificar-se de que não existem leve tarefas em andamento no momento da movimentação. Caso contrário, corridas inúmeros podem ocorrer, resultando em estado inconsistente ou exceções.  
  
##  <a name="a-namemultitypejoindtormultitypejoindestructora-multitypejoinmultitypejoin-destructor"></a><a name="multitype_join___dtormultitype_join_destructor"></a>  multitype_join:: ~ multitype_join destruidor  
 Destrói o `multitype_join` Bloco de mensagens.  
  
```  
~multitype_join();
```  
  
##  <a name="a-namemultitypejoinreleasemethoda-multitypejoinrelease-method"></a><a name="multitype_join__release_method"></a>  Método multitype_join:: Release  
 Libera uma reserva de mensagem bem-sucedida anterior.  
  
```  
virtual void release(
    runtime_object_identity _MsgId,  
    _Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` objeto sendo lançada.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `release` método.  
  
##  <a name="a-namemultitypejoinreleaserefmethoda-multitypejoinreleaseref-method"></a><a name="multitype_join__release_ref_method"></a>  Método multitype_join:: release_ref  
 Libera uma contagem de referência sobre isso `multiple_join` Bloco de mensagens.  
  
```  
virtual void release_ref(_Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando este método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de código-fonte pode liberar quaisquer recursos reservados para o bloco de destino.  
  
##  <a name="a-namemultitypejoinreservemethoda-multitypejoinreserve-method"></a><a name="multitype_join__reserve_method"></a>  Método multitype_join:: Reserve  
 Reserva uma mensagem anteriormente oferecida por esse `multitype_join` Bloco de mensagens.  
  
```  
virtual bool reserve(
    runtime_object_identity _MsgId,  
    _Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` do objeto que está sendo reservado.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `reserve` método.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se a mensagem foi reservada com êxito, `false` caso contrário. Reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceito por outro destino, a origem pode negar reservas e assim por diante.  
  
### <a name="remarks"></a>Comentários  
 Depois de você chamar `reserve`, se for bem-sucedida, você deve chamar `consume` ou `release` para levar ou desistir de posse da mensagem, respectivamente.  
  
##  <a name="a-namemultitypejoinunlinktargetmethoda-multitypejoinunlinktarget-method"></a><a name="multitype_join__unlink_target_method"></a>  Método multitype_join:: unlink_target  
 Desvincula um bloco de destino deste `multitype_join` Bloco de mensagens.  
  
```  
virtual void unlink_target(_Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para um `ITarget` Bloco de desvinculação disso `multitype_join` Bloco de mensagens.  
  
##  <a name="a-namemultitypejoinunlinktargetsmethoda-multitypejoinunlinktargets-method"></a><a name="multitype_join__unlink_targets_method"></a>  Método multitype_join:: unlink_targets  
 Desvincula todos os destinos neste `multitype_join` Bloco de mensagens.  
  
```  
virtual void unlink_targets();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe Choice](../../../parallel/concrt/reference/choice-class.md)   
 [Classe JOIN](../Topic/join%20Class.md)
