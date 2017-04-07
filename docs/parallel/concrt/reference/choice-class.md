---
title: Classe Choice | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- choice
- AGENTS/concurrency::choice
- AGENTS/concurrency::choice::choice
- AGENTS/concurrency::choice::accept
- AGENTS/concurrency::choice::acquire_ref
- AGENTS/concurrency::choice::consume
- AGENTS/concurrency::choice::has_value
- AGENTS/concurrency::choice::index
- AGENTS/concurrency::choice::link_target
- AGENTS/concurrency::choice::release
- AGENTS/concurrency::choice::release_ref
- AGENTS/concurrency::choice::reserve
- AGENTS/concurrency::choice::unlink_target
- AGENTS/concurrency::choice::unlink_targets
- AGENTS/concurrency::choice::value
dev_langs:
- C++
helpviewer_keywords:
- choice class
ms.assetid: 4157a539-d5c2-4161-b1ab-536ce2888397
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
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 13110f3a221be47716ca60618c59d2e4bdd6911e
ms.lasthandoff: 03/17/2017

---
# <a name="choice-class"></a>Classe choice
Um `choice` bloco de mensagens é um bloco de várias fonte, destino único que representa uma interação de fluxo de controle com um conjunto de fontes. O bloco de opção aguardará para qualquer uma das várias fontes para produzir uma mensagem e irá propagar o índice da origem que produziu a mensagem.  
  
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
|[Escolha](#ctor)|Sobrecarregado. Constrói um `choice` bloco de mensagens.|  
|[~ Destruidor choice](#dtor)|Destrói o `choice` bloco de mensagens.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[aceitar](#accept)|Aceita uma mensagem que foi oferecida por esse `choice` bloco, transferir a propriedade para o chamador.|  
|[acquire_ref](#acquire_ref)|Adquire uma contagem de referência sobre isso `choice` bloco de mensagens, para impedir a exclusão.|  
|[consumir](#consume)|Consome uma mensagem anteriormente oferecida por esse `choice` bloco de mensagens e reservada com êxito pelo destino, transferindo a propriedade para o chamador.|  
|[has_value](#has_value)|Verifica se este `choice` bloco de mensagens foi inicializado com um valor ainda.|  
|[índice](#index)|Retorna um índice para o `tuple` que representa o elemento selecionado pelo `choice` bloco de mensagens.|  
|[link_target](#link_target)|Um bloco de destino está vinculada a esta `choice` bloco de mensagens.|  
|[release](#release)|Libera uma reserva de mensagem bem-sucedida anterior.|  
|[release_ref](#release_ref)|Libera uma contagem de referência sobre isso `choice` bloco de mensagens.|  
|[reserve](#reserve)|Reserva uma mensagem anteriormente oferecida por esse `choice` bloco de mensagens.|  
|[unlink_target](#unlink_target)|Desvincula um bloco de destino deste `choice` bloco de mensagens.|  
|[unlink_targets](#unlink_targets)|Desvincula todos os destinos neste `choice` bloco de mensagens. (Substitui [ISource](isource-class.md#unlink_targets).)|  
|[value](#value)|Obtém a mensagem cujo índice foi selecionado pelo `choice` bloco de mensagens.|  
  
## <a name="remarks"></a>Comentários  
 O bloco de opção garante que apenas uma das mensagens de entrada é consumida.  
  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](isource-class.md)  
  
 `choice`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="accept"></a>aceitar 

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
  
##  <a name="acquire_ref"></a>acquire_ref 

 Adquire uma contagem de referência sobre isso `choice` bloco de mensagens, para impedir a exclusão.  
  
```  
virtual void acquire_ref(_Inout_ ITarget<size_t>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando este método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo vinculado a esta fonte durante o `link_target` método.  
  
##  <a name="ctor"></a>Escolha 

 Constrói um `choice` bloco de mensagens.  
  
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
 O `Scheduler` objeto dentro do qual a propagação de tarefa para o `choice` bloco de mensagens está agendado.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefa para o `choice` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
 `_Choice`  
 Um `choice` bloco de mensagens para copiar de. Observe que o objeto original fica órfão, tornando isso um construtor de movimentação.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.  
  
 Construção de movimentação não é executada em um bloqueio, o que significa que o usuário para certificar-se de que não existem leve tarefas em andamento no momento da movimentação. Caso contrário, corridas inúmeros podem ocorrer, resultando em estado inconsistente ou exceções.  
  
##  <a name="dtor"></a>~ choice 

 Destrói o `choice` bloco de mensagens.  
  
```  
~choice();
```  
  
##  <a name="consume"></a>consumir 

 Consome uma mensagem anteriormente oferecida por esse `choice` bloco de mensagens e reservada com êxito pelo destino, transferindo a propriedade para o chamador.  
  
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
  
##  <a name="has_value"></a>has_value 

 Verifica se este `choice` bloco de mensagens foi inicializado com um valor ainda.  
  
```  
bool has_value() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o bloco recebeu um valor de `false` caso contrário.  
  
##  <a name="index"></a>índice 

 Retorna um índice para o `tuple` que representa o elemento selecionado pelo `choice` bloco de mensagens.  
  
```  
size_t index();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de mensagem.  
  
### <a name="remarks"></a>Comentários  
 A carga da mensagem pode ser extraída usando o `get` método.  
  
##  <a name="link_target"></a>link_target 

 Um bloco de destino está vinculada a esta `choice` bloco de mensagens.  
  
```  
virtual void link_target(_Inout_ ITarget<size_t>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para um `ITarget` bloco para vincular a este `choice` bloco de mensagens.  
  
##  <a name="release"></a>versão 

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
  
##  <a name="release_ref"></a>release_ref 

 Libera uma contagem de referência sobre isso `choice` bloco de mensagens.  
  
```  
virtual void release_ref(_Inout_ ITarget<size_t>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando este método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de código-fonte pode liberar quaisquer recursos reservados para o bloco de destino.  
  
##  <a name="reserve"></a>reservar 

 Reserva uma mensagem anteriormente oferecida por esse `choice` bloco de mensagens.  
  
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
 `true`Se a mensagem foi reservada com êxito, `false` caso contrário. Reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceito por outro destino, a origem pode negar reservas e assim por diante.  
  
### <a name="remarks"></a>Comentários  
 Depois de você chamar `reserve`, se for bem-sucedida, você deve chamar `consume` ou `release` para levar ou desistir de posse da mensagem, respectivamente.  
  
##  <a name="unlink_target"></a>unlink_target 

 Desvincula um bloco de destino deste `choice` bloco de mensagens.  
  
```  
virtual void unlink_target(_Inout_ ITarget<size_t>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para um `ITarget` bloco de desvinculação disso `choice` bloco de mensagens.  
  
##  <a name="unlink_targets"></a>unlink_targets 

 Desvincula todos os destinos neste `choice` bloco de mensagens.  
  
```  
virtual void unlink_targets();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método não precisa ser chamado a partir do destruidor porque o destruidor de interno `single_assignment` bloco desvinculará corretamente.  
  
##  <a name="value"></a>valor 

 Obtém a mensagem cujo índice foi selecionado pelo `choice` bloco de mensagens.  
  
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
 Porque um `choice` bloco de mensagens pode receber entradas com tipos de carga diferentes, você deve especificar o tipo de carga no ponto de recuperação. Você pode determinar o tipo com base no resultado do `index` método.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe JOIN](join-class.md)   
 [Classe single_assignment](single-assignment-class.md)

