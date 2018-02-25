---
title: Estrutura ISchedulerProxy | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9fa2a67b432fac1dc7ec685e6563acb87fd69087
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
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
|[ISchedulerProxy::BindContext](#bindcontext)|Associa um contexto de execução com um proxy de thread, se ainda não estiver associada a um.|  
|[ISchedulerProxy::CreateOversubscriber](#createoversubscriber)|Cria uma nova raiz de processador virtual no thread de hardware associado a um recurso de execução existente.|  
|[ISchedulerProxy::RequestInitialVirtualProcessors](#requestinitialvirtualprocessors)|Solicita uma alocação inicial de raízes do processador virtual. Cada raiz do processador virtual representa a capacidade de executar um thread que pode executar o trabalho para o Agendador.|  
|[ISchedulerProxy::Shutdown](#shutdown)|Notifica o Gerenciador de recursos que o Agendador está sendo desligado. Isso fará com que o Gerenciador de recursos para recuperar todos os recursos concedidos para o Agendador.|  
|[ISchedulerProxy::SubscribeCurrentThread](#subscribecurrentthread)|Registra o thread atual com o Gerenciador de recursos, associando-o este agendador.|  
|[ISchedulerProxy::UnbindContext](#unbindcontext)|Desassocia um proxy de thread do contexto de execução especificado pelo `pContext` parâmetro e o retorna ao pool livre da fábrica de proxy de thread. Esse método pode ser chamado apenas em um contexto de execução que foi associado através de [: Bindcontext](#bindcontext) método e ainda não foi iniciada via sendo o `pContext` parâmetro de um [: Switchto ](ithreadproxy-structure.md#switchto) chamada de método.|  
  
## <a name="remarks"></a>Comentários  
 O Gerenciador de recursos passa um `ISchedulerProxy` interface para cada Agendador que registra com ele usando o [: Registerscheduler](iresourcemanager-structure.md#registerscheduler) método.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ISchedulerProxy`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="bindcontext"></a>  ISchedulerProxy::BindContext Method  
 Associa um contexto de execução com um proxy de thread, se ainda não estiver associada a um.  
  
```
virtual void BindContext(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 Uma interface para o contexto de execução para associar um proxy de thread.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, o [: Switchto](ithreadproxy-structure.md#switchto) método associará um proxy de thread a um contexto de execução sob demanda. No entanto, há circunstâncias em que é necessário associar um contexto com antecedência para garantir que o `SwitchTo` método alterna a um contexto já está associado. Esse é o caso em um contexto de agendamento, pois ele não é possível chamar métodos para alocar a memória UMS e associação de um proxy do thread pode envolver a alocação de memória se um proxy de thread não está disponível no pool livre de fábrica de proxy de thread.  
  
 `invalid_argument` será gerada se o parâmetro `pContext` tem o valor `NULL`.  
  
##  <a name="createoversubscriber"></a>  Método: Createoversubscriber  
 Cria uma nova raiz de processador virtual no thread de hardware associado a um recurso de execução existente.  
  
```
virtual IVirtualProcessorRoot* CreateOversubscriber(_Inout_ IExecutionResource* pExecutionResource) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pExecutionResource`  
 Um `IExecutionResource` interface que representa o segmento de hardware que você deseja subscrever.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma interface `IVirtualProcessorRoot`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método quando quiser que o Agendador subscrever um thread de hardware específica para uma quantidade limitada de tempo. Quando terminar com a raiz de processador virtual, você deve retorná-lo para o Gerenciador de recursos chamando o [remover](iexecutionresource-structure.md#remove) método sobre o `IVirtualProcessorRoot` interface.  
  
 Você mesmo pode subscrever uma raiz de processador virtual existente, porque o `IVirtualProcessorRoot` interface herda o `IExecutionResource` interface.  
  
##  <a name="requestinitialvirtualprocessors"></a>  ISchedulerProxy::RequestInitialVirtualProcessors Method  
 Solicita uma alocação inicial de raízes do processador virtual. Cada raiz do processador virtual representa a capacidade de executar um thread que pode executar o trabalho para o Agendador.  
  
```
virtual IExecutionResource* RequestInitialVirtualProcessors(bool doSubscribeCurrentThread) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `doSubscribeCurrentThread`  
 Se assinar o thread atual e conta durante a alocação de recursos.  
  
### <a name="return-value"></a>Valor de retorno  
 O `IExecutionResource` a interface para o thread atual, se o parâmetro `doSubscribeCurrentThread` tem o valor `true`. Se o valor for `false`, o método retornará `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Antes de um agendador executa qualquer trabalho, ele deve usar esse método para solicitar as raízes de processador virtual do Gerenciador de recursos. O Gerenciador de recursos acessará a política do Agendador usando [: Getpolicy](ischeduler-structure.md#getpolicy) e usar os valores para as chaves de política `MinConcurrency`, `MaxConcurrency` e `TargetOversubscriptionFactor` para determinar quantos threads de hardware para atribuir à Agendador inicialmente e quantos raízes de processador virtual para criar para cada thread de hardware. Para obter mais informações sobre como as políticas de Agendador são usadas para determinar a alocação inicial do Agendador, consulte [PolicyElementKey](concurrency-namespace-enums.md).  
  
 O Gerenciador de recursos concede recursos para um agendador chamando o método [: Addvirtualprocessors](ischeduler-structure.md#addvirtualprocessors) com uma lista de raízes de processador virtual. O método é invocado um retorno de chamada para o Agendador antes que este método retorna.  
  
 Se o Agendador solicitados assinatura para o thread atual, definindo o parâmetro `doSubscribeCurrentThread` para `true`, o método retorna um `IExecutionResource` interface. A assinatura deve ser terminada posteriormente usando o [Iexecutionresource](iexecutionresource-structure.md#remove) método.  
  
 Ao determinar quais segmentos de hardware são selecionados, o Gerenciador de recursos tenta otimizar para afinidade de processador. Se a assinatura for solicitada para o thread atual, é uma indicação de que o thread atual pretende participar do trabalho atribuído a este agendador. Nesse caso, as raízes de processadores virtuais alocados estão localizadas no nó de processador que o thread atual está em execução, se possível.  
  
 O ato de assinar um thread aumenta o nível de assinatura do thread de hardware subjacentes por um. O nível de assinatura é reduzido por um quando a assinatura for encerrada. Para obter mais informações sobre níveis de assinatura, consulte [: Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).  
  
##  <a name="shutdown"></a>  Método Ischedulerproxy:  
 Notifica o Gerenciador de recursos que o Agendador está sendo desligado. Isso fará com que o Gerenciador de recursos para recuperar todos os recursos concedidos para o Agendador.  
  
```
virtual void Shutdown() = 0;
```  
  
### <a name="remarks"></a>Comentários  
 Todos os `IExecutionContext` interfaces Agendador recebido como resultado de um thread externo usando os métodos de assinatura `ISchedulerProxy::RequestInitialVirtualProcessors` ou `ISchedulerProxy::SubscribeCurrentThread` devem ser retornados para o Gerenciador de recursos usando `IExecutionResource::Remove` antes de um agendador desliga em si.  
  
 Se o Agendador tinha qualquer desativado raízes de processador virtual, você deve ativá-los usando [Ivirtualprocessorroot](ivirtualprocessorroot-structure.md#activate)e ter os proxies do thread executando neles deixar o `Dispatch` método de execução contextos, eles são expedir antes de você chamar `Shutdown` em um proxy do Agendador.  
  
 Não é necessário para o Agendador para individualmente retornar todas as raízes de processador virtual concedido a ele por meio de chamadas para o Gerenciador de recursos de `Remove` método porque todas as raízes de processadores virtuais serão retornadas para o Gerenciador de recursos durante o desligamento.  
  
##  <a name="subscribecurrentthread"></a>  Método: Subscribecurrentthread  
 Registra o thread atual com o Gerenciador de recursos, associando-o este agendador.  
  
```
virtual IExecutionResource* SubscribeCurrentThread() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `IExecutionResource` em uma interface que representa o thread atual no tempo de execução.  
  
### <a name="remarks"></a>Comentários  
 Use esse método se você quiser que o Gerenciador de recursos durante a alocação de recursos para o Agendador e outros agendadores de conta para o thread atual. É especialmente útil quando os planos de thread participem do trabalho em fila para o Agendador, juntamente com as raízes de processador virtual que Agendador recebe do Gerenciador de recursos. O Gerenciador de recursos usa informações para evitar excesso de assinatura desnecessário de threads de hardware do sistema.  
  
 O recurso de execução recebido por esse método deve ser retornado para o Gerenciador de recursos usando o [Iexecutionresource](iexecutionresource-structure.md#remove) método. O thread que chama o `Remove` método deve ser o mesmo thread que anteriormente chamado de `SubscribeCurrentThread` método.  
  
 O ato de assinar um thread aumenta o nível de assinatura do thread de hardware subjacentes por um. O nível de assinatura é reduzido por um quando a assinatura for encerrada. Para obter mais informações sobre níveis de assinatura, consulte [: Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).  
  
##  <a name="unbindcontext"></a>  ISchedulerProxy::UnbindContext Method  
 Desassocia um proxy de thread do contexto de execução especificado pelo `pContext` parâmetro e o retorna ao pool livre da fábrica de proxy de thread. Esse método pode ser chamado apenas em um contexto de execução que foi associado através de [: Bindcontext](#bindcontext) método e ainda não foi iniciada via sendo o `pContext` parâmetro de um [: Switchto ](ithreadproxy-structure.md#switchto) chamada de método.  
  
```
virtual void UnbindContext(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 O contexto de execução para desassociar a partir do seu proxy de thread.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura IScheduler](ischeduler-structure.md)   
 [Estrutura IThreadProxy](ithreadproxy-structure.md)   
 [Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)   
 [Estrutura IResourceManager](iresourcemanager-structure.md)
