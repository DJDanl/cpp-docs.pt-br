---
title: Estrutura ISchedulerProxy | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ISchedulerProxy
- CONCRTRM/concurrency::ISchedulerProxy
- CONCRTRM/concurrency::ISchedulerProxy::ISchedulerProxy::BindContext
- CONCRTRM/concurrency::ISchedulerProxy::ISchedulerProxy::CreateOversubscriber
- CONCRTRM/concurrency::ISchedulerProxy::ISchedulerProxy::RequestInitialVirtualProcessors
- CONCRTRM/concurrency::ISchedulerProxy::ISchedulerProxy::Shutdown
- CONCRTRM/concurrency::ISchedulerProxy::ISchedulerProxy::SubscribeCurrentThread
- CONCRTRM/concurrency::ISchedulerProxy::ISchedulerProxy::UnbindContext
dev_langs:
- C++
helpviewer_keywords:
- ISchedulerProxy structure
ms.assetid: af416973-7a1c-4c30-aa3b-4161c2aaea54
caps.latest.revision: 18
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
ms.openlocfilehash: 3dd95150022ad94f50b456c84f7dacd2d3cef7c5
ms.lasthandoff: 03/17/2017

---
# <a name="ischedulerproxy-structure"></a>Estrutura ISchedulerProxy
A interface pela qual agendadores se comunicar com o Gerenciador de recursos do tempo de execução de simultaneidade para negociar a alocação de recursos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct ISchedulerProxy;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Bindcontext](#bindcontext)|Associa um contexto de execução com um proxy de thread, se ainda não estiver associada a um.|  
|[Createoversubscriber](#createoversubscriber)|Cria uma nova raiz de processador virtual no thread de hardware associado a um recurso existente de execução.|  
|[Requestinitialvirtualprocessors](#requestinitialvirtualprocessors)|Solicita uma alocação inicial de raízes do processador virtual. Raiz de cada processador virtual representa a capacidade de executar um thread que pode executar o trabalho para o Agendador.|  
|[Ischedulerproxy](#shutdown)|Notifica o Gerenciador de recursos que o Agendador está sendo desligado. Isso fará com que o Gerenciador de recursos para recuperar imediatamente todos os recursos concedidos ao Agendador.|  
|[Subscribecurrentthread](#subscribecurrentthread)|Registra o thread atual com o Gerenciador de recursos, associando-o este agendador.|  
|[Unbindcontext](#unbindcontext)|Desassocia um proxy de thread do contexto de execução especificado pelo `pContext` parâmetro e retorna ao pool livre da fábrica de proxy de thread. Este método só pode ser chamado em um contexto de execução que foi vinculado por meio o [Bindcontext](#bindcontext) método e ainda não foi iniciado por meio de sendo o `pContext` parâmetro de um [Ithreadproxy](ithreadproxy-structure.md#switchto) chamada de método.|  
  
## <a name="remarks"></a>Comentários  
 O Gerenciador de recursos de entrega uma `ISchedulerProxy` interface para cada Agendador que registra usando o [Registerscheduler](iresourcemanager-structure.md#registerscheduler) método.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ISchedulerProxy`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="bindcontext"></a>Método Bindcontext  
 Associa um contexto de execução com um proxy de thread, se ainda não estiver associada a um.  
  
```
virtual void BindContext(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 Uma interface para o contexto de execução para associar um proxy de thread.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, o [Ithreadproxy](ithreadproxy-structure.md#switchto) método associará um proxy de thread em um contexto de execução sob demanda. No entanto, há circunstâncias em que é necessário associar um contexto de antecedência para garantir que o `SwitchTo` método alterna para um contexto já está associado. Esse é o caso em um contexto de agendamento, pois ele não é possível chamar métodos que alocam a memória UMS e associação de um proxy de thread pode envolver a alocação de memória se um proxy de thread não está disponível no pool livre da fábrica de proxy de thread.  
  
 `invalid_argument`é lançada se o parâmetro `pContext` tem o valor `NULL`.  
  
##  <a name="createoversubscriber"></a>Método Createoversubscriber  
 Cria uma nova raiz de processador virtual no thread de hardware associado a um recurso existente de execução.  
  
```
virtual IVirtualProcessorRoot* CreateOversubscriber(_Inout_ IExecutionResource* pExecutionResource) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pExecutionResource`  
 Um `IExecutionResource` interface que representa o thread de hardware que você deseja subscrever.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma interface `IVirtualProcessorRoot`.  
  
### <a name="remarks"></a>Comentários  
 Use este método quando quiser que o Agendador subscrever um thread de hardware específico para uma quantidade limitada de tempo. Quando terminar com a raiz do processador virtual, você deve retorná-lo para o Gerenciador de recursos chamando o [remover](iexecutionresource-structure.md#remove) método o `IVirtualProcessorRoot` interface.  
  
 Você mesmo pode subscrever uma raiz de processador virtual existente, porque o `IVirtualProcessorRoot` interface herda o `IExecutionResource` interface.  
  
##  <a name="requestinitialvirtualprocessors"></a>Método Requestinitialvirtualprocessors  
 Solicita uma alocação inicial de raízes do processador virtual. Raiz de cada processador virtual representa a capacidade de executar um thread que pode executar o trabalho para o Agendador.  
  
```
virtual IExecutionResource* RequestInitialVirtualProcessors(bool doSubscribeCurrentThread) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `doSubscribeCurrentThread`  
 Se assinar o thread atual e a conta durante a alocação de recursos.  
  
### <a name="return-value"></a>Valor de retorno  
 O `IExecutionResource` de interface para o thread atual, se o parâmetro `doSubscribeCurrentThread` tem o valor `true`. Se o valor for `false`, o método retorna `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Antes de um agendador executa qualquer trabalho, ele deve usar esse método para solicitar raízes do processador virtual do Gerenciador de recursos. O Gerenciador de recursos irá acessar a política do Agendador usando [Getpolicy](ischeduler-structure.md#getpolicy) e usar os valores para as chaves de política `MinConcurrency`, `MaxConcurrency` e `TargetOversubscriptionFactor` para determinar quantos segmentos de hardware para atribuir ao Agendador inicialmente e quantos raízes de processador virtual para criar para cada thread de hardware. Para obter mais informações sobre como as políticas de Agendador são usadas para determinar a alocação inicial do Agendador, consulte [PolicyElementKey](concurrency-namespace-enums.md).  
  
 O Gerenciador de recursos concede recursos a um agendador chamando o método [Addvirtualprocessors](ischeduler-structure.md#addvirtualprocessors) com uma lista de raízes do processador virtual. O método é invocado como um retorno de chamada para o Agendador antes que este método retorna.  
  
 Se o Agendador solicitado assinatura para o thread atual, definindo o parâmetro `doSubscribeCurrentThread` para `true`, o método retorna um `IExecutionResource` interface. A assinatura deve ser terminada posteriormente usando o [Iexecutionresource](iexecutionresource-structure.md#remove) método.  
  
 Ao determinar quais segmentos de hardware são selecionados, o Gerenciador de recursos tentará otimizar a afinidade do processador. Se a solicitação de assinatura para o thread atual, é uma indicação de que o segmento atual pretende participar do trabalho atribuído a este agendador. Nesse caso, as raízes de processadores virtuais alocados estão localizadas no nó do processador, que o thread atual está em execução, se possível.  
  
 O ato de assinar um thread aumenta o nível de assinatura do thread de hardware subjacentes por um. O nível de assinatura é reduzido por um quando a assinatura for encerrada. Para obter mais informações sobre níveis de assinatura, consulte [Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).  
  
##  <a name="shutdown"></a>Método Ischedulerproxy:  
 Notifica o Gerenciador de recursos que o Agendador está sendo desligado. Isso fará com que o Gerenciador de recursos para recuperar imediatamente todos os recursos concedidos ao Agendador.  
  
```
virtual void Shutdown() = 0;
```  
  
### <a name="remarks"></a>Comentários  
 Todos os `IExecutionContext` interfaces Agendador recebido como resultado de assinar um thread externo usando os métodos `ISchedulerProxy::RequestInitialVirtualProcessors` ou `ISchedulerProxy::SubscribeCurrentThread` deve ser retornado para o Gerenciador de recursos usando `IExecutionResource::Remove` antes que um programador se desliga.  
  
 Se o Agendador tinha qualquer desativado raízes do processador virtual, você deve ativá-los usando [Ivirtualprocessorroot](ivirtualprocessorroot-structure.md#activate)e os proxies do thread em execução neles deixar o `Dispatch` método os contextos de execução, eles são expedição antes de invocar `Shutdown` um proxy do Agendador.  
  
 Não é necessário para o Agendador individualmente retornar todas as raízes do processador virtual concedidas a ele por meio de chamadas para o Gerenciador de recursos de `Remove` método porque todas as raízes de processadores virtuais serão retornadas para o Gerenciador de recursos no desligamento.  
  
##  <a name="subscribecurrentthread"></a>Método Subscribecurrentthread  
 Registra o thread atual com o Gerenciador de recursos, associando-o este agendador.  
  
```
virtual IExecutionResource* SubscribeCurrentThread() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `IExecutionResource` em uma interface que representa o thread atual em tempo de execução.  
  
### <a name="remarks"></a>Comentários  
 Use esse método se você quiser que o Gerenciador de recursos para levar em conta o thread atual ao alocar recursos para o Agendador e outros programadores. Ele é especialmente útil quando os planos de thread participem do trabalho em fila para o Agendador, juntamente com as raízes de processador virtual que Agendador recebe do Gerenciador de recursos. O Gerenciador de recursos usa informações para evitar excesso de assinatura desnecessário de segmentos de hardware do sistema.  
  
 O recurso de execução recebido por esse método deve ser retornado para o Gerenciador de recursos usando o [Iexecutionresource](iexecutionresource-structure.md#remove) método. O thread que chama o `Remove` método deve ser o mesmo thread que chamou anteriormente o `SubscribeCurrentThread` método.  
  
 O ato de assinar um thread aumenta o nível de assinatura do thread de hardware subjacentes por um. O nível de assinatura é reduzido por um quando a assinatura for encerrada. Para obter mais informações sobre níveis de assinatura, consulte [Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).  
  
##  <a name="unbindcontext"></a>Método Unbindcontext  
 Desassocia um proxy de thread do contexto de execução especificado pelo `pContext` parâmetro e retorna ao pool livre da fábrica de proxy de thread. Este método só pode ser chamado em um contexto de execução que foi vinculado por meio o [Bindcontext](#bindcontext) método e ainda não foi iniciado por meio de sendo o `pContext` parâmetro de um [Ithreadproxy](ithreadproxy-structure.md#switchto) chamada de método.  
  
```
virtual void UnbindContext(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 O contexto de execução para desassociar de seu proxy de thread.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura IScheduler](ischeduler-structure.md)   
 [Estrutura IThreadProxy](ithreadproxy-structure.md)   
 [Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)   
 [Estrutura IResourceManager](iresourcemanager-structure.md)

