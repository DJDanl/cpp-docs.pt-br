---
title: "Classe choice | Microsoft Docs"
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
  - "agents/concurrency::choice"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe choice"
ms.assetid: 4157a539-d5c2-4161-b1ab-536ce2888397
caps.latest.revision: 21
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe choice
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Um `choice` Bloco de mensagens é um bloco de várias fonte, destino único que representa uma interação de fluxo de controle com um conjunto de fontes. O bloco de opção aguardará para qualquer uma das várias fontes para produzir uma mensagem e irá propagar o índice da origem que produziu a mensagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<
    class T  
>  
class choice: public ISource<size_t>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Um `tuple`-com base em tipo que representa as cargas das fontes de entrada.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`type`|Um alias de tipo para `T`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Choice:: Choice construtor](#choice__choice_constructor)|Sobrecarregado. Constrói um `choice` Bloco de mensagens.|  
|[Escolha:: ~ choice destruidor](#choice___dtorchoice_destructor)|Destrói o `choice` Bloco de mensagens.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Choice:: Accept](#choice__accept_method)|Aceita uma mensagem que foi oferecida por esse `choice` bloco, transferir a propriedade para o chamador.|  
|[Método Choice:: acquire_ref](#choice__acquire_ref_method)|Adquire uma contagem de referência sobre isso `choice` Bloco de mensagens, para impedir a exclusão.|  
|[Método Choice:: Consume](#choice__consume_method)|Consome uma mensagem anteriormente oferecida por esse `choice` Bloco de mensagens e reservada com êxito pelo destino, transferindo a propriedade para o chamador.|  
|[Método Choice:: has_value](#choice__has_value_method)|Verifica se este `choice` Bloco de mensagens foi inicializado com um valor ainda.|  
|[Método Choice:: index](#choice__index_method)|Retorna um índice para o `tuple` que representa o elemento selecionado pelo `choice` Bloco de mensagens.|  
|[Método Choice:: link_target](#choice__link_target_method)|Um bloco de destino está vinculada a esta `choice` Bloco de mensagens.|  
|[Método Choice:: Release](#choice__release_method)|Libera uma reserva de mensagem bem-sucedida anterior.|  
|[Método Choice:: release_ref](#choice__release_ref_method)|Libera uma contagem de referência sobre isso `choice` Bloco de mensagens.|  
|[Método Choice:: Reserve](#choice__reserve_method)|Reserva uma mensagem anteriormente oferecida por esse `choice` Bloco de mensagens.|  
|[Método Choice:: unlink_target](#choice__unlink_target_method)|Desvincula um bloco de destino deste `choice` Bloco de mensagens.|  
|[Método Choice:: unlink_targets](#choice__unlink_targets_method)|Desvincula todos os destinos neste `choice` Bloco de mensagens. (Substitui [ISource](../../../parallel/concrt/reference/isource-class.md#isource__unlink_targets_method).)|  
|[Método Choice:: Value](#choice__value_method)|Obtém a mensagem cujo índice foi selecionado pelo `choice` Bloco de mensagens.|  
  
## <a name="remarks"></a>Comentários  
 O bloco de opção garante que apenas uma das mensagens de entrada é consumida.  
  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](../../../parallel/concrt/reference/isource-class.md)  
  
 `choice`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namechoiceacceptmethoda-choiceaccept-method"></a><a name="choice__accept_method"></a>  Método Choice:: Accept  
 Aceita uma mensagem que foi oferecida por esse `choice` bloco, transferir a propriedade para o chamador.  
  
```  
virtual message<size_t>* accept(
    runtime_object_identity _MsgId,  
    _Inout_ ITarget<size_t>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` da oferecida `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `accept` método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a mensagem que o chamador agora é o proprietário.  
  
##  <a name="a-namechoiceacquirerefmethoda-choiceacquireref-method"></a><a name="choice__acquire_ref_method"></a>  Método Choice:: acquire_ref  
 Adquire uma contagem de referência sobre isso `choice` Bloco de mensagens, para impedir a exclusão.  
  
```  
virtual void acquire_ref(_Inout_ ITarget<size_t>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando este método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo vinculado a esta fonte durante o `link_target` método.  
  
##  <a name="a-namechoicechoiceconstructora-choicechoice-constructor"></a><a name="choice__choice_constructor"></a>  Choice:: Choice construtor  
 Constrói um `choice` Bloco de mensagens.  
  
```  
explicit choice(
    T _Tuple);

 
choice(
    Scheduler& _PScheduler,  
    T _Tuple);

 
choice(
    ScheduleGroup& _PScheduleGroup,  
    T _Tuple);

 
choice(
    choice&& _Choice);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Tuple`  
 Um `tuple` de fontes para a opção.  
  
 `_PScheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefa para o `choice` Bloco de mensagens está agendado.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefa para o `choice` Bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
 `_Choice`  
 Um `choice` Bloco de mensagens para copiar de. Observe que o objeto original fica órfão, tornando isso um construtor de movimentação.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.  
  
 Construção de movimentação não é executada em um bloqueio, o que significa que o usuário para certificar-se de que não existem leve tarefas em andamento no momento da movimentação. Caso contrário, corridas inúmeros podem ocorrer, resultando em estado inconsistente ou exceções.  
  
##  <a name="a-namechoicedtorchoicedestructora-choicechoice-destructor"></a><a name="choice___dtorchoice_destructor"></a>  Escolha:: ~ choice destruidor  
 Destrói o `choice` Bloco de mensagens.  
  
```  
~choice();
```  
  
##  <a name="a-namechoiceconsumemethoda-choiceconsume-method"></a><a name="choice__consume_method"></a>  Método Choice:: Consume  
 Consome uma mensagem anteriormente oferecida por esse `choice` Bloco de mensagens e reservada com êxito pelo destino, transferindo a propriedade para o chamador.  
  
```  
virtual message<size_t>* consume(
    runtime_object_identity _MsgId,  
    _Inout_ ITarget<size_t>* _PTarget);
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
  
##  <a name="a-namechoicehasvaluemethoda-choicehasvalue-method"></a><a name="choice__has_value_method"></a>  Método Choice:: has_value  
 Verifica se este `choice` Bloco de mensagens foi inicializado com um valor ainda.  
  
```  
bool has_value() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o bloco recebeu um valor de `false` caso contrário.  
  
##  <a name="a-namechoiceindexmethoda-choiceindex-method"></a><a name="choice__index_method"></a>  Método Choice:: index  
 Retorna um índice para o `tuple` que representa o elemento selecionado pelo `choice` Bloco de mensagens.  
  
```  
size_t index();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de mensagem.  
  
### <a name="remarks"></a>Comentários  
 A carga da mensagem pode ser extraída usando o `get` método.  
  
##  <a name="a-namechoicelinktargetmethoda-choicelinktarget-method"></a><a name="choice__link_target_method"></a>  Método Choice:: link_target  
 Um bloco de destino está vinculada a esta `choice` Bloco de mensagens.  
  
```  
virtual void link_target(_Inout_ ITarget<size_t>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para um `ITarget` bloco para vincular a este `choice` Bloco de mensagens.  
  
##  <a name="a-namechoicereleasemethoda-choicerelease-method"></a><a name="choice__release_method"></a>  Método Choice:: Release  
 Libera uma reserva de mensagem bem-sucedida anterior.  
  
```  
virtual void release(
    runtime_object_identity _MsgId,  
    _Inout_ ITarget<size_t>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` objeto sendo lançada.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `release` método.  
  
##  <a name="a-namechoicereleaserefmethoda-choicereleaseref-method"></a><a name="choice__release_ref_method"></a>  Método Choice:: release_ref  
 Libera uma contagem de referência sobre isso `choice` Bloco de mensagens.  
  
```  
virtual void release_ref(_Inout_ ITarget<size_t>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando este método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de código-fonte pode liberar quaisquer recursos reservados para o bloco de destino.  
  
##  <a name="a-namechoicereservemethoda-choicereserve-method"></a><a name="choice__reserve_method"></a>  Método Choice:: Reserve  
 Reserva uma mensagem anteriormente oferecida por esse `choice` Bloco de mensagens.  
  
```  
virtual bool reserve(
    runtime_object_identity _MsgId,  
    _Inout_ ITarget<size_t>* _PTarget);
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
  
##  <a name="a-namechoiceunlinktargetmethoda-choiceunlinktarget-method"></a><a name="choice__unlink_target_method"></a>  Método Choice:: unlink_target  
 Desvincula um bloco de destino deste `choice` Bloco de mensagens.  
  
```  
virtual void unlink_target(_Inout_ ITarget<size_t>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para um `ITarget` Bloco de desvinculação disso `choice` Bloco de mensagens.  
  
##  <a name="a-namechoiceunlinktargetsmethoda-choiceunlinktargets-method"></a><a name="choice__unlink_targets_method"></a>  Método Choice:: unlink_targets  
 Desvincula todos os destinos neste `choice` Bloco de mensagens.  
  
```  
virtual void unlink_targets();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método não precisa ser chamado a partir do destruidor porque o destruidor de interno `single_assignment` bloco desvinculará corretamente.  
  
##  <a name="a-namechoicevaluemethoda-choicevalue-method"></a><a name="choice__value_method"></a>  Método Choice:: Value  
 Obtém a mensagem cujo índice foi selecionado pelo `choice` Bloco de mensagens.  
  
```  
template <
    typename _Payload_type  
>  
_Payload_type const& value();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Payload_type`  
 O tipo de carga da mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 A carga da mensagem.  
  
### <a name="remarks"></a>Comentários  
 Porque um `choice` Bloco de mensagens pode receber entradas com tipos de carga diferentes, você deve especificar o tipo de carga no ponto de recuperação. Você pode determinar o tipo com base no resultado do `index` método.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe JOIN](../Topic/join%20Class.md)   
 [Classe single_assignment](../../../parallel/concrt/reference/single-assignment-class.md)
