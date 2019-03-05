---
title: Estrutura ISchedulerProxy
ms.date: 11/04/2016
f1_keywords:
- ISchedulerProxy
- CONCRTRM/concurrency::ISchedulerProxy
- CONCRTRM/concurrency::ISchedulerProxy::ISchedulerProxy::BindContext
- CONCRTRM/concurrency::ISchedulerProxy::ISchedulerProxy::CreateOversubscriber
- CONCRTRM/concurrency::ISchedulerProxy::ISchedulerProxy::RequestInitialVirtualProcessors
- CONCRTRM/concurrency::ISchedulerProxy::ISchedulerProxy::Shutdown
- CONCRTRM/concurrency::ISchedulerProxy::ISchedulerProxy::SubscribeCurrentThread
- CONCRTRM/concurrency::ISchedulerProxy::ISchedulerProxy::UnbindContext
helpviewer_keywords:
- ISchedulerProxy structure
ms.assetid: af416973-7a1c-4c30-aa3b-4161c2aaea54
ms.openlocfilehash: 0dddd43a5b3e68992e41f0b95893303e57e7c7ff
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57268844"
---
# <a name="ischedulerproxy-structure"></a>Estrutura ISchedulerProxy

A interface pela qual agendadores de se comunicar com o Gerenciador de recursos do tempo de execução de simultaneidade para negociar a alocação de recursos.

## <a name="syntax"></a>Sintaxe

```
struct ISchedulerProxy;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[ISchedulerProxy::BindContext](#bindcontext)|Associa um contexto de execução com um proxy de thread, se ele não ainda estiver associado a um.|
|[ISchedulerProxy::CreateOversubscriber](#createoversubscriber)|Cria uma nova raiz de processador virtual em que o thread de hardware associado a um recurso de execução existente.|
|[ISchedulerProxy::RequestInitialVirtualProcessors](#requestinitialvirtualprocessors)|Solicita uma alocação inicial de raízes de processador virtual. Cada raiz de processador virtual representa a capacidade de executar um thread que pode executar o trabalho para o Agendador.|
|[ISchedulerProxy::Shutdown](#shutdown)|Notifica o Gerenciador de recursos que o Agendador está sendo desligado. Isso fará com que o Gerenciador de recursos para recuperar todos os recursos concedidos para o Agendador.|
|[ISchedulerProxy::SubscribeCurrentThread](#subscribecurrentthread)|Registra o thread atual com o Gerenciador de recursos, associando-o este agendador.|
|[ISchedulerProxy::UnbindContext](#unbindcontext)|Desassocia um proxy de thread do contexto de execução especificado pelo `pContext` parâmetro e o retorna ao pool da fábrica de proxy de thread livre. Esse método pode ser chamado apenas em um contexto de execução que estava associado por meio de [ischedulerproxy:: Bindcontext](#bindcontext) método e ainda não foi iniciado por meio do que está sendo a `pContext` parâmetro de um [ithreadproxy:: Switchto ](ithreadproxy-structure.md#switchto) chamada de método.|

## <a name="remarks"></a>Comentários

O Gerenciador de recursos passa um `ISchedulerProxy` interface para cada Agendador que registra com ele usando o [iresourcemanager:: Registerscheduler](iresourcemanager-structure.md#registerscheduler) método.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ISchedulerProxy`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

##  <a name="bindcontext"></a>  Método ischedulerproxy:: Bindcontext

Associa um contexto de execução com um proxy de thread, se ele não ainda estiver associado a um.

```
virtual void BindContext(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
Uma interface para o contexto de execução a ser associado a um proxy de thread.

### <a name="remarks"></a>Comentários

Normalmente, o [ithreadproxy:: Switchto](ithreadproxy-structure.md#switchto) método irá vincular um proxy de thread para um contexto de execução sob demanda. No entanto, há circunstâncias em que é necessário associar um contexto de antecedência para garantir que o `SwitchTo` método alterna para um contexto já está associado. Esse é o caso em um contexto de agendamento, pois ele não é possível chamar métodos que alocam memória UMS e um proxy de thread de associação pode envolver a alocação de memória, se um proxy de thread não está prontamente disponível no pool da fábrica de proxy de thread livre.

`invalid_argument` será gerada se o parâmetro `pContext` tem o valor `NULL`.

##  <a name="createoversubscriber"></a>  Método ischedulerproxy:: Createoversubscriber

Cria uma nova raiz de processador virtual em que o thread de hardware associado a um recurso de execução existente.

```
virtual IVirtualProcessorRoot* CreateOversubscriber(_Inout_ IExecutionResource* pExecutionResource) = 0;
```

### <a name="parameters"></a>Parâmetros

*pExecutionResource*<br/>
Um `IExecutionResource` interface que representa o thread de hardware que você deseja substituir.

### <a name="return-value"></a>Valor de retorno

Uma interface `IVirtualProcessorRoot`.

### <a name="remarks"></a>Comentários

Use esse método quando quiser que seu Agendador de subscrever um thread de hardware específico para uma quantidade limitada de tempo. Quando terminar com a raiz do processador virtual, você deve retorná-lo para o Gerenciador de recursos chamando o [remover](iexecutionresource-structure.md#remove) método o `IVirtualProcessorRoot` interface.

Você pode até mesmo substituir uma raiz de processador virtual existente, porque o `IVirtualProcessorRoot` interface herda o `IExecutionResource` interface.

##  <a name="requestinitialvirtualprocessors"></a>  Método ischedulerproxy:: Requestinitialvirtualprocessors

Solicita uma alocação inicial de raízes de processador virtual. Cada raiz de processador virtual representa a capacidade de executar um thread que pode executar o trabalho para o Agendador.

```
virtual IExecutionResource* RequestInitialVirtualProcessors(bool doSubscribeCurrentThread) = 0;
```

### <a name="parameters"></a>Parâmetros

*doSubscribeCurrentThread*<br/>
Se deseja assinar o thread atual e da conta para ele durante a alocação de recursos.

### <a name="return-value"></a>Valor de retorno

O `IExecutionResource` da interface para o thread atual, se o parâmetro `doSubscribeCurrentThread` tem o valor **verdadeiro**. Se o valor for **falsos**, o método retornará NULL.

### <a name="remarks"></a>Comentários

Antes de um agendador executa qualquer trabalho, ele deve usar esse método para solicitar as raízes de processador virtual do Gerenciador de recursos. O Gerenciador de recursos acessará a política do Agendador usando [ischeduler:: Getpolicy](ischeduler-structure.md#getpolicy) e use os valores para as chaves de política `MinConcurrency`, `MaxConcurrency` e `TargetOversubscriptionFactor` para determinar quantos threads de hardware para atribuir à Agendador inicialmente e quantos raízes de processador virtual para criar para cada thread de hardware. Para obter mais informações sobre como as políticas de Agendador são usadas para determinar a alocação inicial do Agendador, consulte [PolicyElementKey](concurrency-namespace-enums.md).

O Gerenciador de recursos concede recursos para um agendador chamando o método [ischeduler:: Addvirtualprocessors](ischeduler-structure.md#addvirtualprocessors) com uma lista de raízes de processador virtual. O método é invocado como um retorno de chamada para o Agendador antes desse método retorna.

Se o Agendador solicitou a assinatura para o thread atual, definindo o parâmetro `doSubscribeCurrentThread` à **verdadeira**, o método retorna um `IExecutionResource` interface. A assinatura deve ser terminada em um momento posterior, usando o [iexecutionresource:: remove](iexecutionresource-structure.md#remove) método.

Ao determinar quais segmentos de hardware são selecionados, o Gerenciador de recursos tentará otimizar para afinidade de nó do processador. Se a assinatura é solicitada para o thread atual, é uma indicação de que o thread atual pretende participar o trabalho atribuído a este agendador. Nesse caso, as raízes de processadores virtuais alocados estão localizadas no nó de processador que o thread atual está sendo executado, se possível.

O ato de assinar um thread aumenta o nível de assinatura do thread de hardware subjacentes por um. O nível de assinatura é reduzido por um quando a assinatura será encerrada. Para obter mais informações sobre os níveis de assinatura, consulte [iexecutionresource:: Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).

##  <a name="shutdown"></a>  Método ischedulerproxy:: Shutdown

Notifica o Gerenciador de recursos que o Agendador está sendo desligado. Isso fará com que o Gerenciador de recursos para recuperar todos os recursos concedidos para o Agendador.

```
virtual void Shutdown() = 0;
```

### <a name="remarks"></a>Comentários

Todos os `IExecutionContext` interfaces o Agendador recebido como resultado de um thread externo usando os métodos de assinatura `ISchedulerProxy::RequestInitialVirtualProcessors` ou `ISchedulerProxy::SubscribeCurrentThread` deve ser retornado para o Resource Manager usando `IExecutionResource::Remove` antes de um agendador se desliga.

Se seu Agendador tinha qualquer desativado raízes de processador virtual, você deve ativá-los usando [ivirtualprocessorroot:: Activate](ivirtualprocessorroot-structure.md#activate)e ter os proxies de thread em execução neles deixar o `Dispatch` método da execução eles são expedição antes de invocar de contextos `Shutdown` em um proxy do Agendador.

Não é necessário para o Agendador para individualmente retornar todas as raízes de processador virtual concedido a ele por meio de chamadas para o Gerenciador de recursos de `Remove` método porque todas as raízes de processadores virtuais serão retornadas para o Gerenciador de recursos no desligamento.

##  <a name="subscribecurrentthread"></a>  Método ischedulerproxy:: Subscribecurrentthread

Registra o thread atual com o Gerenciador de recursos, associando-o este agendador.

```
virtual IExecutionResource* SubscribeCurrentThread() = 0;
```

### <a name="return-value"></a>Valor de retorno

O `IExecutionResource` em uma interface que representa o thread atual no tempo de execução.

### <a name="remarks"></a>Comentários

Use esse método se você quiser que o Gerenciador de recursos para levar em conta o thread atual durante a alocação de recursos para seu Agendador e outros agendadores. Ele é especialmente útil quando os planos de thread participem do trabalho na fila para o Agendador, juntamente com as raízes de processador virtual que o Agendador recebe do Gerenciador de recursos. O Gerenciador de recursos usa informações para evitar o excesso de assinatura desnecessário de segmentos de hardware no sistema.

O recurso de execução recebido por esse método deve ser retornado para o Resource Manager usando o [iexecutionresource:: remove](iexecutionresource-structure.md#remove) método. O thread que chama o `Remove` método deve ser o mesmo thread que chamou anteriormente a `SubscribeCurrentThread` método.

O ato de assinar um thread aumenta o nível de assinatura do thread de hardware subjacentes por um. O nível de assinatura é reduzido por um quando a assinatura será encerrada. Para obter mais informações sobre os níveis de assinatura, consulte [iexecutionresource:: Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).

##  <a name="unbindcontext"></a>  Método ischedulerproxy:: Unbindcontext

Desassocia um proxy de thread do contexto de execução especificado pelo `pContext` parâmetro e o retorna ao pool da fábrica de proxy de thread livre. Esse método pode ser chamado apenas em um contexto de execução que estava associado por meio de [ischedulerproxy:: Bindcontext](#bindcontext) método e ainda não foi iniciado por meio do que está sendo a `pContext` parâmetro de um [ithreadproxy:: Switchto ](ithreadproxy-structure.md#switchto) chamada de método.

```
virtual void UnbindContext(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
O contexto de execução para desassociar a partir de seu proxy de thread.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IScheduler](ischeduler-structure.md)<br/>
[Estrutura IThreadProxy](ithreadproxy-structure.md)<br/>
[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)<br/>
[Estrutura IResourceManager](iresourcemanager-structure.md)
