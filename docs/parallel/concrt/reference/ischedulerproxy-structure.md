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
ms.openlocfilehash: 776f70f9b93eb2e38151ceb5e84b4664420cf954
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78854109"
---
# <a name="ischedulerproxy-structure"></a>Estrutura ISchedulerProxy

A interface pela qual os agendadores se comunicam com o Gerenciador de recursos do Tempo de Execução de Simultaneidade para negociar a alocação de recursos.

## <a name="syntax"></a>Sintaxe

```cpp
struct ISchedulerProxy;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[ISchedulerProxy::BindContext](#bindcontext)|Associa um contexto de execução a um proxy de thread, se ele ainda não estiver associado a um.|
|[ISchedulerProxy::CreateOversubscriber](#createoversubscriber)|Cria uma nova raiz de processador virtual no thread de hardware associado a um recurso de execução existente.|
|[ISchedulerProxy::RequestInitialVirtualProcessors](#requestinitialvirtualprocessors)|Solicita uma alocação inicial de raízes de processador virtual. Cada raiz de processador virtual representa a capacidade de executar um thread que pode executar trabalho para o Agendador.|
|[ISchedulerProxy:: Shutdown](#shutdown)|Notifica o Gerenciador de recursos de que o Agendador está sendo desligado. Isso fará com que o Gerenciador de recursos recupere imediatamente todos os recursos concedidos ao agendador.|
|[ISchedulerProxy::SubscribeCurrentThread](#subscribecurrentthread)|Registra o thread atual com o Gerenciador de recursos, associando-o a este Agendador.|
|[ISchedulerProxy::UnbindContext](#unbindcontext)|Desassocia um proxy de thread do contexto de execução especificado pelo parâmetro `pContext` e o retorna ao pool gratuito da fábrica de proxy de thread. Esse método só pode ser chamado em um contexto de execução que foi associado por meio do método [ISchedulerProxy:: BindContext](#bindcontext) e ainda não foi iniciado por ser o parâmetro `pContext` de uma chamada de método [IThreadProxy:: SwitchTo](ithreadproxy-structure.md#switchto) .|

## <a name="remarks"></a>Comentários

O Gerenciador de recursos passa uma interface `ISchedulerProxy` para cada Agendador que se registra com ele usando o método [IResourceManager:: RegisterScheduler](iresourcemanager-structure.md#registerscheduler) .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ISchedulerProxy`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="bindcontext"></a>Método ISchedulerProxy:: BindContext

Associa um contexto de execução a um proxy de thread, se ele ainda não estiver associado a um.

```cpp
virtual void BindContext(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
Uma interface para o contexto de execução a ser associada a um proxy de thread.

### <a name="remarks"></a>Comentários

Normalmente, o método [IThreadProxy:: SwitchTo](ithreadproxy-structure.md#switchto) associará um proxy de thread a um contexto de execução sob demanda. No entanto, há circunstâncias em que é necessário associar um contexto com antecedência para garantir que o método `SwitchTo` alterne para um contexto já associado. Esse é o caso em um contexto de agendamento de UMS, pois ele não pode chamar métodos que alocam memória, e a associação de um proxy de thread pode envolver a alocação de memória se um proxy de thread não estiver prontamente disponível no pool gratuito da fábrica de proxy de thread.

`invalid_argument` será gerada se o parâmetro `pContext` tiver o valor `NULL`.

## <a name="createoversubscriber"></a>Método ISchedulerProxy:: CreateOversubscriber

Cria uma nova raiz de processador virtual no thread de hardware associado a um recurso de execução existente.

```cpp
virtual IVirtualProcessorRoot* CreateOversubscriber(_Inout_ IExecutionResource* pExecutionResource) = 0;
```

### <a name="parameters"></a>Parâmetros

*pExecutionResource*<br/>
Uma interface `IExecutionResource` que representa o thread de hardware que você deseja assinar.

### <a name="return-value"></a>Valor retornado

Uma interface `IVirtualProcessorRoot`.

### <a name="remarks"></a>Comentários

Use esse método quando o Agendador quiser se inscrever em um determinado thread de hardware por um período limitado. Depois de concluir a raiz do processador virtual, você deve retorná-la ao Gerenciador de recursos chamando o método [Remove](iexecutionresource-structure.md#remove) na interface `IVirtualProcessorRoot`.

Você pode até mesmo se inscrever em uma raiz de processador virtual existente, pois a interface de `IVirtualProcessorRoot` herda da interface `IExecutionResource`.

## <a name="requestinitialvirtualprocessors"></a>Método ISchedulerProxy:: RequestInitialVirtualProcessors

Solicita uma alocação inicial de raízes de processador virtual. Cada raiz de processador virtual representa a capacidade de executar um thread que pode executar trabalho para o Agendador.

```cpp
virtual IExecutionResource* RequestInitialVirtualProcessors(bool doSubscribeCurrentThread) = 0;
```

### <a name="parameters"></a>Parâmetros

*doSubscribeCurrentThread*<br/>
Se deseja assinar o thread atual e conta para ele durante a alocação de recursos.

### <a name="return-value"></a>Valor retornado

A interface `IExecutionResource` para o thread atual, se o parâmetro `doSubscribeCurrentThread` tiver o valor **true**. Se o valor for **false**, o método retornará NULL.

### <a name="remarks"></a>Comentários

Antes que um Agendador execute qualquer trabalho, ele deve usar esse método para solicitar raízes de processador virtual do Gerenciador de recursos. O Gerenciador de recursos acessará a política do Agendador usando [IScheduler:: GetPolicy](ischeduler-structure.md#getpolicy) e usará os valores para as chaves de política `MinConcurrency`, `MaxConcurrency` e `TargetOversubscriptionFactor` para determinar quantos threads de hardware serão atribuídos ao agendador inicialmente e quantas raízes do processador virtual serão criadas para cada thread de hardware. Para obter mais informações sobre como as políticas do Agendador são usadas para determinar a alocação inicial de um Agendador, consulte [PolicyElementKey](concurrency-namespace-enums.md).

O Gerenciador de recursos concede recursos a um Agendador chamando o método [IScheduler:: AddVirtualProcessors](ischeduler-structure.md#addvirtualprocessors) com uma lista de raízes de processador virtual. O método é invocado como um retorno de chamada no Agendador antes que esse método seja retornado.

Se o Agendador solicitou a assinatura para o thread atual definindo o parâmetro `doSubscribeCurrentThread` como **true**, o método retornará uma interface `IExecutionResource`. A assinatura deve ser encerrada em um ponto posterior usando o método [IExecutionResource:: Remove](iexecutionresource-structure.md#remove) .

Ao determinar quais threads de hardware são selecionados, o Gerenciador de recursos tentará otimizar a afinidade de nó de processador. Se a assinatura for solicitada para o thread atual, é uma indicação de que o thread atual pretende participar do trabalho atribuído a esse Agendador. Nesse caso, as raízes dos processadores virtuais alocados estão localizadas no nó do processador no qual o thread atual está sendo executado, se possível.

O ato de assinar um thread aumenta o nível de assinatura do thread de hardware subjacente em um. O nível de assinatura é reduzido em um quando a assinatura é encerrada. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource:: CurrentSubscriptionLevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="shutdown"></a>Método ISchedulerProxy:: Shutdown

Notifica o Gerenciador de recursos de que o Agendador está sendo desligado. Isso fará com que o Gerenciador de recursos recupere imediatamente todos os recursos concedidos ao agendador.

```cpp
virtual void Shutdown() = 0;
```

### <a name="remarks"></a>Comentários

Todas as `IExecutionContext` interfaces que o Agendador recebeu como resultado da assinatura de um thread externo usando os métodos `ISchedulerProxy::RequestInitialVirtualProcessors` ou `ISchedulerProxy::SubscribeCurrentThread` devem ser retornados ao Gerenciador de recursos usando `IExecutionResource::Remove` antes que um Agendador seja desligado.

Se o Agendador tiver uma raiz de processador virtual desativada, você deverá ativá-las usando [IVirtualProcessorRoot:: Activate](ivirtualprocessorroot-structure.md#activate)e fazer com que os proxies de thread sejam executados nelas, deixe o método `Dispatch` dos contextos de execução que eles estão expedindo antes de invocar `Shutdown` em um proxy de Agendador.

Não é necessário que o Agendador retorne individualmente todas as raízes de processador virtual que o Gerenciador de recursos concedeu a ele por meio de chamadas para o método `Remove` porque todas as raízes de processadores virtuais serão retornadas ao Gerenciador de recursos no desligamento.

## <a name="subscribecurrentthread"></a>Método ISchedulerProxy:: SubscribeCurrentThread

Registra o thread atual com o Gerenciador de recursos, associando-o a este Agendador.

```cpp
virtual IExecutionResource* SubscribeCurrentThread() = 0;
```

### <a name="return-value"></a>Valor retornado

A `IExecutionResource` interface de representação que representa o thread atual no tempo de execução.

### <a name="remarks"></a>Comentários

Use esse método se desejar que o Gerenciador de recursos acesse o thread atual ao alocar recursos para o Agendador e outros agendadores. Ele é especialmente útil quando o thread planeja participar do trabalho na fila para o seu Agendador, juntamente com as raízes do processador virtual que o Agendador recebe do Gerenciador de recursos. O Gerenciador de recursos usa informações para evitar a excesso de assinaturas desnecessárias de threads de hardware no sistema.

O recurso de execução recebido por esse método deve ser retornado para o Gerenciador de recursos usando o método [IExecutionResource:: Remove](iexecutionresource-structure.md#remove) . O thread que chama o método `Remove` deve ser o mesmo thread que anteriormente chamou o método `SubscribeCurrentThread`.

O ato de assinar um thread aumenta o nível de assinatura do thread de hardware subjacente em um. O nível de assinatura é reduzido em um quando a assinatura é encerrada. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource:: CurrentSubscriptionLevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="unbindcontext"></a>Método ISchedulerProxy:: UnbindContext

Desassocia um proxy de thread do contexto de execução especificado pelo parâmetro `pContext` e o retorna ao pool gratuito da fábrica de proxy de thread. Esse método só pode ser chamado em um contexto de execução que foi associado por meio do método [ISchedulerProxy:: BindContext](#bindcontext) e ainda não foi iniciado por ser o parâmetro `pContext` de uma chamada de método [IThreadProxy:: SwitchTo](ithreadproxy-structure.md#switchto) .

```cpp
virtual void UnbindContext(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
O contexto de execução para desassociar de seu proxy de thread.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IScheduler](ischeduler-structure.md)<br/>
[Estrutura IThreadProxy](ithreadproxy-structure.md)<br/>
[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)<br/>
[Estrutura IResourceManager](iresourcemanager-structure.md)
