---
title: Classe ordered_message_processor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ordered_message_processor
- AGENTS/concurrency::ordered_message_processor
- AGENTS/concurrency::ordered_message_processor::ordered_message_processor
- AGENTS/concurrency::ordered_message_processor::async_send
- AGENTS/concurrency::ordered_message_processor::initialize
- AGENTS/concurrency::ordered_message_processor::initialize_batched_processing
- AGENTS/concurrency::ordered_message_processor::sync_send
- AGENTS/concurrency::ordered_message_processor::wait
- AGENTS/concurrency::ordered_message_processor::process_incoming_message
dev_langs: C++
helpviewer_keywords: ordered_message_processor class
ms.assetid: 787adfb7-7f79-4a70-864a-80e3b64088cd
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5b97d0003469acbe307b75b3278c8821628e333d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="orderedmessageprocessor-class"></a>Classe ordered_message_processor
Um `ordered_message_processor` é um `message_processor` que permite que os blocos de mensagens processar mensagens na ordem em que foram recebidas.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class ordered_message_processor : public message_processor<T>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de carga de mensagens tratadas por processador.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`type`|Um alias de tipo para `T`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[ordered_message_processor](#ctor)|Constrói uma `ordered_message_processor` objeto.|  
|[~ ordered_message_processor destruidor](#dtor)|Destrói a `ordered_message_processor` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[async_send](#async_send)|Filas de mensagens e inicia uma tarefa de processamento, se isso não já foi feito de forma assíncrona. (Substitui [message_processor:: async_send](message-processor-class.md#async_send).)|  
|[inicializar](#initialize)|Inicializa o `ordered_message_processor` objeto com o grupo de função, o Agendador e o agendamento de retorno de chamada apropriados.|  
|[initialize_batched_processing](#initialize_batched_processing)|Inicializar o processamento em lotes de mensagens|  
|[sync_send](#sync_send)|Modo síncrono Enfileira mensagens e inicia uma tarefa de processamento, se isso não já foi feito. (Substitui [message_processor:: sync_send](message-processor-class.md#sync_send).)|  
|[Aguarde](#wait)|Uma espera de rotação específicos de processador usada em destruidores de blocos de mensagens para certificar-se de que todas as tarefas de processamento assíncrono tem tempo para concluir antes de destruir o bloco. (Substitui [message_processor:: wait](message-processor-class.md#wait).)|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[process_incoming_message](#process_incoming_message)|A função de processamento que é chamada de forma assíncrona. Ele remove da fila de mensagens e começa a processá-las. (Substitui [message_processor:: process_incoming_message](message-processor-class.md#process_incoming_message).)|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [message_processor](message-processor-class.md)  
  
 `ordered_message_processor`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="async_send"></a>async_send 

 Filas de mensagens e inicia uma tarefa de processamento, se isso não já foi feito de forma assíncrona.  
  
```
virtual void async_send(_Inout_opt_ message<T>* _Msg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Msg`  
 Um ponteiro para uma mensagem.  
  
##  <a name="initialize"></a>inicializar 

 Inicializa o `ordered_message_processor` objeto com o grupo de função, o Agendador e o agendamento de retorno de chamada apropriados.  
  
```
void initialize(
    _Inout_opt_ Scheduler* _PScheduler,
    _Inout_opt_ ScheduleGroup* _PScheduleGroup,
    _Handler_method const& _Handler);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PScheduler`  
 Um ponteiro para o Agendador a ser usado para agendar tarefas leves.  
  
 `_PScheduleGroup`  
 Um ponteiro para o grupo de agendamento a ser usado para agendar tarefas leves.  
  
 `_Handler`  
 O functor manipulador invocado durante o retorno de chamada.  
  
##  <a name="initialize_batched_processing"></a>initialize_batched_processing 

 Inicializar o processamento em lotes de mensagens  
  
```
virtual void initialize_batched_processing(
    _Handler_method const& _Processor,
    _Propagator_method const& _Propagator);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Processor`  
 O functor processador chamado durante o retorno de chamada.  
  
 `_Propagator`  
 O functor propagador invocado durante o retorno de chamada.  
  
##  <a name="ctor"></a>ordered_message_processor 

 Constrói uma `ordered_message_processor` objeto.  
  
```
ordered_message_processor();
```  
  
### <a name="remarks"></a>Comentários  
 Isso `ordered_message_processor` não agende manipuladores assíncronos ou síncronos até que o `initialize` função é chamada.  
  
##  <a name="dtor"></a>~ ordered_message_processor 

 Destrói a `ordered_message_processor` objeto.  
  
```
virtual ~ordered_message_processor();
```  
  
### <a name="remarks"></a>Comentários  
 Espera que todas as operações assíncronas pendentes antes de destruir o processador.  
  
##  <a name="process_incoming_message"></a>process_incoming_message 

 A função de processamento que é chamada de forma assíncrona. Ele remove da fila de mensagens e começa a processá-las.  
  
```
virtual void process_incoming_message();
```  
  
##  <a name="sync_send"></a>sync_send 

 Modo síncrono Enfileira mensagens e inicia uma tarefa de processamento, se isso não já foi feito.  
  
```
virtual void sync_send(_Inout_opt_ message<T>* _Msg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Msg`  
 Um ponteiro para uma mensagem.  
  
##  <a name="wait"></a>Aguarde 

 Uma espera de rotação específicos de processador usada em destruidores de blocos de mensagens para certificar-se de que todas as tarefas de processamento assíncrono tem tempo para concluir antes de destruir o bloco.  
  
```
virtual void wait();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
