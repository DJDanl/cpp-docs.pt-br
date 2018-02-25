---
title: Classe multitype_join | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- multitype_join
- AGENTS/concurrency::multitype_join
- AGENTS/concurrency::multitype_join::multitype_join
- AGENTS/concurrency::multitype_join::accept
- AGENTS/concurrency::multitype_join::acquire_ref
- AGENTS/concurrency::multitype_join::consume
- AGENTS/concurrency::multitype_join::link_target
- AGENTS/concurrency::multitype_join::release
- AGENTS/concurrency::multitype_join::release_ref
- AGENTS/concurrency::multitype_join::reserve
- AGENTS/concurrency::multitype_join::unlink_target
- AGENTS/concurrency::multitype_join::unlink_targets
dev_langs:
- C++
helpviewer_keywords:
- multitype_join class
ms.assetid: 236e87a0-4867-49fd-869a-bef4010e49a7
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 62d91f878a8330b6e4fe60f7e24ad25c779b868d
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="multitypejoin-class"></a>Classe multitype_join
Um `multitype_join` bloco de mensagens é um bloco de mensagens várias fonte, destino único que juntos combina mensagens de tipos diferentes de cada uma das suas fontes e oferece uma tupla das mensagens combinadas para seus destinos.  
  
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
|[multitype_join](#ctor)|Sobrecarregado. Constrói um `multitype_join` bloco de mensagens.|  
|[~ multitype_join destruidor](#dtor)|Destrói a `multitype_join` bloco de mensagens.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[accept](#accept)|Aceita uma mensagem que foi fornecida por esse `multitype_join` bloco, transferir a propriedade para o chamador.|  
|[acquire_ref](#acquire_ref)|Adquire uma contagem de referência neste `multitype_join` bloco de mensagens, para impedir a exclusão.|  
|[consume](#consume)|Consome uma mensagem anteriormente oferecida pelo `multitype_join` bloco de mensagens e reservada com êxito pelo destino, transferir a propriedade para o chamador.|  
|[link_target](#link_target)|Vincula um bloco de destino para este `multitype_join` bloco de mensagens.|  
|[release](#release)|Libera uma reserva de mensagem bem-sucedida anterior.|  
|[release_ref](#release_ref)|Libera uma contagem de referência neste `multiple_join` bloco de mensagens.|  
|[reserve](#reserve)|Reserva uma mensagem anteriormente oferecida por este `multitype_join` bloco de mensagens.|  
|[unlink_target](#unlink_target)|Desvincula um bloco de destino deste `multitype_join` bloco de mensagens.|  
|[unlink_targets](#unlink_targets)|Desvincula todos os destinos neste `multitype_join` bloco de mensagens. (Substitui [ISource](isource-class.md#unlink_targets).)|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ISource](isource-class.md)  
  
 `multitype_join`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="accept"></a> Aceitar 

 Aceita uma mensagem que foi fornecida por esse `multitype_join` bloco, transferir a propriedade para o chamador.  
  
```  
virtual message<_Destination_type>* accept(
    runtime_object_identity _MsgId,  
    _Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do que o oferecido `message` objeto.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `accept` método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a mensagem de que o chamador agora tem a propriedade do.  
  
##  <a name="acquire_ref"></a> acquire_ref 

 Adquire uma contagem de referência neste `multitype_join` bloco de mensagens, para impedir a exclusão.  
  
```  
virtual void acquire_ref(_Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que é chamar esse método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo vinculado a esta fonte durante o `link_target` método.  
  
##  <a name="consume"></a> Consumir 

 Consome uma mensagem anteriormente oferecida pelo `multitype_join` bloco de mensagens e reservada com êxito pelo destino, transferir a propriedade para o chamador.  
  
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
  
##  <a name="link_target"></a> link_target 

 Vincula um bloco de destino para este `multitype_join` bloco de mensagens.  
  
```  
virtual void link_target(_Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para um `ITarget` bloco para vincular a este `multitype_join` bloco de mensagens.  
  
##  <a name="ctor"></a> multitype_join 

 Constrói um `multitype_join` bloco de mensagens.  
  
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
 Um `tuple` de fontes para este `multitype_join` bloco de mensagens.  
  
 `_PScheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefas para o `multitype_join` bloco de mensagens está agendado.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefas para o `multitype_join` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
 `_Join`  
 Um `multitype_join` bloco de mensagens para copiar de. Observe que o objeto original ficar órfão, tornando isso um construtor de movimento.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.  
  
 Construção de movimentação não é executada em um bloqueio, o que significa que ele esteja o usuário para certificar-se de que não existem leve tarefas em andamento no momento da movimentação. Caso contrário, vários corridas podem ocorrer, resultando em estado inconsistente ou exceções.  
  
##  <a name="dtor"></a> ~multitype_join 

 Destrói a `multitype_join` bloco de mensagens.  
  
```  
~multitype_join();
```  
  
##  <a name="release"></a> versão 

 Libera uma reserva de mensagem bem-sucedida anterior.  
  
```  
virtual void release(
    runtime_object_identity _MsgId,  
    _Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MsgId`  
 O `runtime_object_identity` do `message` do objeto que está sendo liberado.  
  
 `_PTarget`  
 Um ponteiro para o bloco de destino que está chamando o `release` método.  
  
##  <a name="release_ref"></a> release_ref 

 Libera uma contagem de referência neste `multiple_join` bloco de mensagens.  
  
```  
virtual void release_ref(_Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para o bloco de destino que é chamar esse método.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de código-fonte pode liberar quaisquer recursos reservados para o bloco de destino.  
  
##  <a name="reserve"></a> reserva 

 Reserva uma mensagem anteriormente oferecida por este `multitype_join` bloco de mensagens.  
  
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
 `true` Se a mensagem foi reservada com êxito, `false` caso contrário. Reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceito por outro destino, a fonte pode negar reservas e assim por diante.  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar `reserve`, se tiver êxito, você deve chamar `consume` ou `release` para levar ou dar a posse da mensagem, respectivamente.  
  
##  <a name="unlink_target"></a> unlink_target 

 Desvincula um bloco de destino deste `multitype_join` bloco de mensagens.  
  
```  
virtual void unlink_target(_Inout_ ITarget<_Destination_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 Um ponteiro para um `ITarget` blocos de desvinculação disso `multitype_join` bloco de mensagens.  
  
##  <a name="unlink_targets"></a> unlink_targets 

 Desvincula todos os destinos neste `multitype_join` bloco de mensagens.  
  
```  
virtual void unlink_targets();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe Choice](choice-class.md)   
 [Classe join](join-class.md)
