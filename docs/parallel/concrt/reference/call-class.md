---
title: Classe da chamada | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concurrency::call
- agents/concurrency::call
dev_langs:
- C++
helpviewer_keywords:
- call class
ms.assetid: 1521970a-1e9c-4b0c-a681-d18e40976f49
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
ms.sourcegitcommit: 19244e5527207f852256e646abd18ad298fb28cd
ms.openlocfilehash: b3cfec104346b212217a6854af2390c412c9e015
ms.lasthandoff: 02/25/2017

---
# <a name="call-class"></a>Classe da chamada
A `call` bloco de mensagens é um várias fontes, ordenados `target_block` que chama uma função especificada quando receber uma mensagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T, class _FunctorType = std::function<void(T const&)>>
class call : public target_block<multi_link_registry<ISource<T>>>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de carga das mensagens são propagadas para este bloco.  
  
 `_FunctorType`  
 A assinatura de funções que este bloco pode aceitar.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[chamada de construtor](#ctor)|Sobrecarregado. Constrói um `call` bloco de mensagens.|  
|[~ chamar destruidor](#dtor)|Destrói o `call` bloco de mensagens.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método process_input_messages](#process_input_messages)|Executa a função de chamada nas mensagens de entrada.|  
|[Método process_message](#process_message)|Processa uma mensagem que foi aceita por este `call` bloco de mensagens.|  
|[Método propagate_message](#propagate_message)|Assincronamente transmite uma mensagem de uma `ISource` bloco a esta `call` bloco de mensagens. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.|  
|[Método send_message](#send_message)|Sincronicamente transmite uma mensagem de uma `ISource` bloco a esta `call` bloco de mensagens. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.|  
|[Método supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada. (Substitui [Supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ITarget](itarget-class.md)  
  
 [target_block](target-block-class.md)  
  
 `call`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-call"></a><a name="ctor"></a>chamada 

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
 Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.  
  
 `_PScheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefa para o `call` bloco de mensagens está agendado.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefa para o `call` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.  
  
 O tipo `_Call_method` é um functor com assinatura `void (T const &)` que é invocado por este `call` bloco de mensagens para processar uma mensagem.  
  
 O tipo `filter_method` é um functor com assinatura `bool (T const &)` que é invocado por este `call` bloco de mensagens para determinar se ele deve aceitar uma mensagem oferecida.  
  
##  <a name="a-namedtora-call"></a><a name="dtor"></a>~ call 

 Destrói o `call` bloco de mensagens.  
  
```
~call();
```  
  
##  <a name="a-nameprocessinputmessagesa-processinputmessages"></a><a name="process_input_messages"></a>process_input_messages 

 Executa a função de chamada nas mensagens de entrada.  
  
```
virtual void process_input_messages(_Inout_ message<T>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
  
##  <a name="a-nameprocessmessagea-processmessage"></a><a name="process_message"></a>process_message 

 Processa uma mensagem que foi aceita por este `call` bloco de mensagens.  
  
```
virtual void process_message(_Inout_ message<T>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para a mensagem que deve ser tratados.  
  
##  <a name="a-namepropagatemessagea-propagatemessage"></a><a name="propagate_message"></a>propagate_message 

 Assincronamente transmite uma mensagem de uma `ISource` bloco a esta `call` bloco de mensagens. Ele é invocado com o `propagate` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status propagate_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 A [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="a-namesendmessagea-sendmessage"></a><a name="send_message"></a>send_message 

 Sincronicamente transmite uma mensagem de uma `ISource` bloco a esta `call` bloco de mensagens. Ele é invocado com o `send` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status send_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PMessage`  
 Um ponteiro para o `message` objeto.  
  
 `_PSource`  
 Um ponteiro para o bloco de código-fonte oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 A [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="a-namesupportsanonymoussourcea-supportsanonymoussource"></a><a name="supports_anonymous_source"></a>supports_anonymous_source 

 Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada.  
  
```
virtual bool supports_anonymous_source();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`como o bloco não adie oferecido mensagens.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe Transformer](transformer-class.md)

