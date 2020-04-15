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
ms.openlocfilehash: f4a9e79c2da56406610ad6da08fb438e2f92923d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368155"
---
# <a name="ischedulerproxy-structure"></a>Estrutura ISchedulerProxy

A interface pela qual os agendadores se comunicam com o Gerenciador de Recursos do Concurrency Runtime para negociar a alocação de recursos.

## <a name="syntax"></a>Sintaxe

```cpp
struct ISchedulerProxy;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[ISchedulerProxy::BindContext](#bindcontext)|Associa um contexto de execução a um proxy de thread, se ele ainda não estiver associado a um.|
|[ISchedulerProxy::CreateOversubscriber](#createoversubscriber)|Cria uma nova raiz de processador virtual no segmento de hardware associada a um recurso de execução existente.|
|[ISchedulerProxy::RequestInitialVirtualProcessors](#requestinitialvirtualprocessors)|Solicita uma alocação inicial de raízes do processador virtual. Cada raiz de processador virtual representa a capacidade de executar um segmento que pode executar o trabalho para o agendador.|
|[ISchedulerProxy::Shutdown](#shutdown)|Notifica o Gerenciador de Recursos de que o agendador está sendo desligado. Isso fará com que o Gerenciador de Recursos recupere imediatamente todos os recursos concedidos ao agendador.|
|[ISchedulerProxy::SubscribeCurrentCurrentThread](#subscribecurrentthread)|Registra o segmento atual com o Gerenciador de Recursos, associando-o a este agendador.|
|[ISchedulerProxy::DesvincularContexto](#unbindcontext)|Desassocia um proxy de segmento do `pContext` contexto de execução especificado pelo parâmetro e o devolve ao pool livre da fábrica de proxy thread. Esse método só pode ser chamado em um contexto de execução que foi vinculado através do `pContext` método [ISchedulerProxy::BindContext](#bindcontext) e ainda não foi iniciado por ser o parâmetro de uma chamada de método [IThreadProxy::SwitchTo.](ithreadproxy-structure.md#switchto)|

## <a name="remarks"></a>Comentários

O Gerenciador `ISchedulerProxy` de recursos entrega uma interface a cada agendador que se registra com ele usando o método [IResourceManager::RegisterScheduler.](iresourcemanager-structure.md#registerscheduler)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ISchedulerProxy`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="ischedulerproxybindcontext-method"></a><a name="bindcontext"></a>ISchedulerProxy::BindContext Method

Associa um contexto de execução a um proxy de thread, se ele ainda não estiver associado a um.

```cpp
virtual void BindContext(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
Uma interface para o contexto de execução para associar a um proxy de segmento.

### <a name="remarks"></a>Comentários

Normalmente, o método [IThreadProxy::SwitchTo](ithreadproxy-structure.md#switchto) vinculará um proxy de segmento a um contexto de execução sob demanda. Há, no entanto, circunstâncias em que é necessário vincular `SwitchTo` um contexto com antecedência para garantir que o método mude para um contexto já vinculado. Este é o caso em um contexto de agendamento ums, pois ele não pode chamar métodos que alocam memória e vincular um proxy de segmento pode envolver a alocação de memória se um proxy de segmento não estiver prontamente disponível no pool livre da fábrica de proxy thread.

`invalid_argument`é jogado se `pContext` o parâmetro `NULL`tiver o valor .

## <a name="ischedulerproxycreateoversubscriber-method"></a><a name="createoversubscriber"></a>ISchedulerProxy::CreateOversubscriber Method

Cria uma nova raiz de processador virtual no segmento de hardware associada a um recurso de execução existente.

```cpp
virtual IVirtualProcessorRoot* CreateOversubscriber(_Inout_ IExecutionResource* pExecutionResource) = 0;
```

### <a name="parameters"></a>Parâmetros

*pExecutionResource*<br/>
Uma `IExecutionResource` interface que representa o segmento de hardware que você deseja subscrever demais.

### <a name="return-value"></a>Valor retornado

Uma interface `IVirtualProcessorRoot`.

### <a name="remarks"></a>Comentários

Use este método quando o seu agendador quiser subscrever um segmento de hardware específico por um período limitado de tempo. Depois de terminar com a raiz do processador virtual, você deve devolvê-lo ao gerenciador de recursos chamando o método [Remover](iexecutionresource-structure.md#remove) na `IVirtualProcessorRoot` interface.

Você pode até mesmo assinar demais uma `IVirtualProcessorRoot` raiz de `IExecutionResource` processador virtual existente, porque a interface herda da interface.

## <a name="ischedulerproxyrequestinitialvirtualprocessors-method"></a><a name="requestinitialvirtualprocessors"></a>ISchedulerProxy::RequestInitialVirtualProcessors Method

Solicita uma alocação inicial de raízes do processador virtual. Cada raiz de processador virtual representa a capacidade de executar um segmento que pode executar o trabalho para o agendador.

```cpp
virtual IExecutionResource* RequestInitialVirtualProcessors(bool doSubscribeCurrentThread) = 0;
```

### <a name="parameters"></a>Parâmetros

*doSubscribeCurrentThread*<br/>
Se para assinar o thread atual e contabilizá-lo durante a alocação de recursos.

### <a name="return-value"></a>Valor retornado

A `IExecutionResource` interface para o segmento atual, se o parâmetro `doSubscribeCurrentThread` tiver o valor **verdadeiro**. Se o valor for **falso,** o método retorna NULL.

### <a name="remarks"></a>Comentários

Antes que um agendador execute qualquer trabalho, ele deve usar esse método para solicitar raízes de processador virtuais do Gerenciador de recursos. O Gerenciador de recursos acessará a política do agendador usando [o IScheduler::GetPolicy](ischeduler-structure.md#getpolicy) e usará os valores para as chaves de `MinConcurrency`diretiva `MaxConcurrency` e `TargetOversubscriptionFactor` para determinar quantos threads de hardware atribuir ao agendador inicialmente e quantas raízes de processador virtuais a serem criadas para cada segmento de hardware. Para obter mais informações sobre como as políticas do agendador são usadas para determinar a alocação inicial de um agendador, consulte [PolicyElementKey](concurrency-namespace-enums.md).

O Gerenciador de recursos concede recursos a um agendador chamando o método [IScheduler::AddVirtualProcessors](ischeduler-structure.md#addvirtualprocessors) com uma lista de raízes de processadores virtuais. O método é invocado como um retorno de chamada para o agendador antes que este método retorne.

Se o agendador solicitou a assinatura do segmento `doSubscribeCurrentThread` atual definindo o `IExecutionResource` parâmetro como **verdadeiro,** o método reavou uma interface. A assinatura deve ser encerrada posteriormente usando o método [IExecutionResource::Remove.](iexecutionresource-structure.md#remove)

Ao determinar quais segmentos de hardware são selecionados, o Gerenciador de recursos tentará otimizar a afinidade do nó do processador. Se a assinatura for solicitada para o segmento atual, é um indicativo de que o segmento atual pretende participar do trabalho atribuído a este agendador. Nesse caso, as raízes dos processadores virtuais alocados estão localizadas no nó do processador em que o segmento atual está sendo executado, se possível.

O ato de assinar um segmento aumenta o nível de assinatura do segmento de hardware subjacente por um. O nível de assinatura é reduzido em um quando a assinatura é encerrada. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource::CurrentSubscriptionLevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="ischedulerproxyshutdown-method"></a><a name="shutdown"></a>ISchedulerProxy::Método de desligamento

Notifica o Gerenciador de Recursos de que o agendador está sendo desligado. Isso fará com que o Gerenciador de Recursos recupere imediatamente todos os recursos concedidos ao agendador.

```cpp
virtual void Shutdown() = 0;
```

### <a name="remarks"></a>Comentários

Todas `IExecutionContext` as interfaces que o agendador recebeu como resultado `ISchedulerProxy::RequestInitialVirtualProcessors` da `ISchedulerProxy::SubscribeCurrentThread` assinatura de um segmento `IExecutionResource::Remove` externo usando os métodos ou devem ser devolvidas ao Gerenciador de Recursos usando antes que um agendador se desligue.

Se o seu agendador tivesse raízes de processador virtuais desativadas, você deve ativá-las usando [iVirtualProcessorRoot::Activate](ivirtualprocessorroot-structure.md#activate), e fazer com que os proxies de thread executando sobre eles deixem o `Dispatch` método dos contextos de execução que estão despachando antes de invocar `Shutdown` um proxy do agendador.

Não é necessário que o agendador retorne individualmente todas as raízes do processador `Remove` virtual que o Gerenciador de Recursos lhe concedeu através de chamadas para o método, pois todas as raízes de processadores virtuais serão devolvidas ao Gerenciador de Recursos no desligamento.

## <a name="ischedulerproxysubscribecurrentthread-method"></a><a name="subscribecurrentthread"></a>ISchedulerProxy::SubscribeCurrentThread Method

Registra o segmento atual com o Gerenciador de Recursos, associando-o a este agendador.

```cpp
virtual IExecutionResource* SubscribeCurrentThread() = 0;
```

### <a name="return-value"></a>Valor retornado

A `IExecutionResource` interface representando o segmento atual no tempo de execução.

### <a name="remarks"></a>Comentários

Use este método se quiser que o Gerenciador de recursos contabilize o segmento atual enquanto aloca recursos para seu agendador e outros agendadores. É especialmente útil quando o thread planeja participar do trabalho enfileirado ao seu agendador, juntamente com as raízes do processador virtual que o agendador recebe do Gerenciador de Recursos. O Gerenciador de recursos usa informações para evitar a superassinatura desnecessária de threads de hardware no sistema.

O recurso de execução recebido através deste método deve ser devolvido ao Gerenciador de recursos usando o método [IExecutionResource::Remove.](iexecutionresource-structure.md#remove) O segmento que `Remove` chama o método deve ser `SubscribeCurrentThread` o mesmo segmento que anteriormente chamava o método.

O ato de assinar um segmento aumenta o nível de assinatura do segmento de hardware subjacente por um. O nível de assinatura é reduzido em um quando a assinatura é encerrada. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource::CurrentSubscriptionLevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="ischedulerproxyunbindcontext-method"></a><a name="unbindcontext"></a>ISchedulerProxy::Desvincularmétodo decontexto

Desassocia um proxy de segmento do `pContext` contexto de execução especificado pelo parâmetro e o devolve ao pool livre da fábrica de proxy thread. Esse método só pode ser chamado em um contexto de execução que foi vinculado através do `pContext` método [ISchedulerProxy::BindContext](#bindcontext) e ainda não foi iniciado por ser o parâmetro de uma chamada de método [IThreadProxy::SwitchTo.](ithreadproxy-structure.md#switchto)

```cpp
virtual void UnbindContext(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
O contexto de execução para desassociar-se de seu proxy thread.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)<br/>
[Estrutura IScheduler](ischeduler-structure.md)<br/>
[Estrutura IThreadProxy](ithreadproxy-structure.md)<br/>
[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)<br/>
[Estrutura IResourceManager](iresourcemanager-structure.md)
