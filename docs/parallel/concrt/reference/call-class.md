---
title: Chame a classe | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 585a490ec64152a1268b7707971ea94e69bf9fbf
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46109711"
---
# <a name="call-class"></a>Classe da chamada
Um `call` bloco de mensagem é uma origem de várias, ordenados `target_block` que invoca uma função especificada ao receber uma mensagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T, class _FunctorType = std::function<void(T const&)>>
class call : public target_block<multi_link_registry<ISource<T>>>;
```  
  
#### <a name="parameters"></a>Parâmetros  
*T*<br/>
O tipo de carga das mensagens propagadas a este bloco.  
  
*_FunctorType*<br/>
A assinatura de funções que este bloco pode aceitar.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[call](#ctor)|Sobrecarregado. Constrói um `call` bloco de mensagem.|  
|[~ chamar destruidor](#dtor)|Destrói o `call` bloco de mensagem.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[process_input_messages](#process_input_messages)|Executa a função de chamada nas mensagens de entrada.|  
|[process_message](#process_message)|Processa uma mensagem que foi aceito por este `call` bloco de mensagem.|  
|[propagate_message](#propagate_message)|Passa assincronamente uma mensagem de um `ISource` bloco a este `call` bloco de mensagem. Ele é invocado pelo `propagate` método, quando chamado por um bloco de código-fonte.|  
|[send_message](#send_message)|Forma síncrona transmite uma mensagem de um `ISource` bloco a este `call` bloco de mensagem. Ele é invocado pelo `send` método, quando chamado por um bloco de código-fonte.|  
|[supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada. (Substitui [ITarget:: Supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [ITarget](itarget-class.md)  
  
 [target_block](target-block-class.md)  
  
 `call`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Agents. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a> Chamada 

 Constrói um `call` bloco de mensagem.  
  
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
*_Func*<br/>
Uma função que será invocada para cada mensagem aceita.  
  
*Filtro*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.  
  
*_PScheduler*<br/>
O `Scheduler` objeto dentro do qual a tarefa de propagação para o `call` bloco de mensagem está agendado.  
  
*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto dentro do qual a tarefa de propagação para o `call` bloco de mensagem está agendado. O `Scheduler` objeto usado é inferido pelo grupo agendado.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão, se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.  
  
 O tipo `_Call_method` é um funtor com assinatura `void (T const &)` que é invocado por este `call` bloco de mensagem para processar uma mensagem.  
  
 O tipo `filter_method` é um funtor com assinatura `bool (T const &)` que é invocado por este `call` bloco de mensagem para determinar se ele deve aceitar uma mensagem oferecida.  
  
##  <a name="dtor"></a> ~ call 

 Destrói o `call` bloco de mensagem.  
  
```
~call();
```  
  
##  <a name="process_input_messages"></a> process_input_messages 

 Executa a função de chamada nas mensagens de entrada.  
  
```
virtual void process_input_messages(_Inout_ message<T>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
*_PMessage*<br/>
Um ponteiro para a mensagem que deve ser tratados.  
  
##  <a name="process_message"></a> process_message 

 Processa uma mensagem que foi aceito por este `call` bloco de mensagem.  
  
```
virtual void process_message(_Inout_ message<T>* _PMessage);
```  
  
### <a name="parameters"></a>Parâmetros  
*_PMessage*<br/>
Um ponteiro para a mensagem que deve ser tratados.  
  
##  <a name="propagate_message"></a> propagate_message 

 Passa assincronamente uma mensagem de um `ISource` bloco a este `call` bloco de mensagem. Ele é invocado pelo `propagate` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status propagate_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
*_PMessage*<br/>
Um ponteiro para o `message` objeto.  
  
*_PSource*<br/>
Um ponteiro para o bloco de código-fonte, oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="send_message"></a> send_message 

 Forma síncrona transmite uma mensagem de um `ISource` bloco a este `call` bloco de mensagem. Ele é invocado pelo `send` método, quando chamado por um bloco de código-fonte.  
  
```
virtual message_status send_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```  
  
### <a name="parameters"></a>Parâmetros  
*_PMessage*<br/>
Um ponteiro para o `message` objeto.  
  
*_PSource*<br/>
Um ponteiro para o bloco de código-fonte, oferecendo a mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.  
  
##  <a name="supports_anonymous_source"></a> supports_anonymous_source 

 Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada.  
  
```
virtual bool supports_anonymous_source();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` porque o bloco não adiar as mensagens oferecidas.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe transformer](transformer-class.md)
