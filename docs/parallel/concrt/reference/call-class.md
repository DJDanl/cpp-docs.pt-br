---
title: Classe da chamada | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- call
- AGENTS/concurrency::call
- AGENTS/concurrency::call::call
- AGENTS/concurrency::call::process_input_messages
- AGENTS/concurrency::call::process_message
- AGENTS/concurrency::call::propagate_message
- AGENTS/concurrency::call::send_message
- AGENTS/concurrency::call::supports_anonymous_source
dev_langs:
- C++
helpviewer_keywords:
- call class
ms.assetid: 1521970a-1e9c-4b0c-a681-d18e40976f49
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9a63873b7666e4f75ddd39fbf684ebb80c1f85e8
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="call-class"></a>Classe da chamada
Um `call` bloco de mensagens é um várias fontes, ordenados `target_block` que invoca uma função especificada ao receber uma mensagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T, class _FunctorType = std::function<void(T const&)>>
class call : public target_block<multi_link_registry<ISource<T>>>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de carga de mensagens são propagadas para este bloco.  
  
 `_FunctorType`  
 A assinatura de funções que este bloco pode aceitar.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[call](#ctor)|Sobrecarregado. Constrói um `call` bloco de mensagens.|  
|[~ chamar destruidor](#dtor)|Destrói a `call` bloco de mensagens.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[process_input_messages](#process_input_messages)|Executa a função de chamada nas mensagens de entrada.|  
|[process_message](#process_message)|Processa uma mensagem que foi aceito por este `call` bloco de mensagens.|  
|[propagate_message](#propagate_message)|Assincronamente transmite uma mensagem de um `ISource` blocos a este `call` bloco de mensagens. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.|  
|[send_message](#send_message)|Modo síncrono transmite uma mensagem de um `ISource` blocos a este `call` bloco de mensagens. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.|  
|[supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada. (Substitui [: Supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ITarget](itarget-class.md)  
  
 [target_block](target-block-class.md)  
  
 `call`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a> call 

 Constrói um `call` bloco de mensagens.  
  
```
call(
    _Call_method const& _Func);

call(
    _Call_method const& _Func,
    filter_method const& _Filter);

call(
    Scheduler& _PScheduler,
    _Call_method const& _Func);

call(
    Scheduler& _PScheduler,
    _Call_method const& _Func,
    filter_method const& _Filter);

call(
    ScheduleGroup& _PScheduleGroup,
    _Call_method const& _Func);

call(
    ScheduleGroup& _PScheduleGroup,
    _Call_method const& _Func,
    filter_method const& _Filter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Func`  
 Uma função que será chamada para cada mensagem aceita.  
  
 `_Filter`  
 Uma função de filtro que determina se as mensagens oferecidas devem ser aceita.  
  
 `_PScheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefas para o `call` bloco de mensagens está agendado.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefas para o `call` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.  
  
 O tipo `_Call_method` é um functor com assinatura `void (T const &)` que é invocado por este `call` bloco de mensagens para processar uma mensagem.  
  
 O tipo `filter_method` é um functor com assinatura `bool (T const &)` que é invocado por este `call` bloco de mensagens para determinar se ele deve aceitar uma mensagem oferecida.  
  
##  <a name="dtor"></a> ~call 

 Destrói a `call` bloco de mensagens.  
  
```
~call();
```  
  
##  <a name="process_input_messages"></a> process_input_messages 

 Executa a função de chamada nas mensagens de entrada.  
  
```
virtual void process_input_messages(_Inout_ message<T>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
  
##  <a name="process_message"></a> process_message 

 Processa uma mensagem que foi aceito por este `call` bloco de mensagens.  
  
```
virtual void process_message(_Inout_ message<T>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para a mensagem a ser manipulada.  
  
##  <a name="propagate_message"></a> propagate_message 

 Assincronamente transmite uma mensagem de um `ISource` blocos a este `call` bloco de mensagens. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status propagate_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferta a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="send_message"></a> send_message 

 Modo síncrono transmite uma mensagem de um `ISource` blocos a este `call` bloco de mensagens. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status send_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferta a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="supports_anonymous_source"></a> supports_anonymous_source 

 Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada.  
  
```
virtual bool supports_anonymous_source();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` como o bloco não adiar oferecido mensagens.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe transformer](transformer-class.md)
