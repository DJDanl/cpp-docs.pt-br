---
title: Estrutura IExecutionResource
ms.date: 11/04/2016
f1_keywords:
- IExecutionResource
- CONCRTRM/concurrency::IExecutionResource
- CONCRTRM/concurrency::IExecutionResource::IExecutionResource::CurrentSubscriptionLevel
- CONCRTRM/concurrency::IExecutionResource::IExecutionResource::GetExecutionResourceId
- CONCRTRM/concurrency::IExecutionResource::IExecutionResource::GetNodeId
- CONCRTRM/concurrency::IExecutionResource::IExecutionResource::Remove
helpviewer_keywords:
- IExecutionResource structure
ms.assetid: 6b27042b-b98c-4f7f-b831-566950af84cd
ms.openlocfilehash: 4305948aa4e5da36023c1d4fe8b0b84aa4d59e23
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377306"
---
# <a name="iexecutionresource-structure"></a>Estrutura IExecutionResource

Uma abstração para um segmento de hardware.

## <a name="syntax"></a>Sintaxe

```cpp
struct IExecutionResource;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[iExecutionResource::CurrentSubscriptionLevel](#currentsubscriptionlevel)|Retorna o número de raízes de processador virtual ativadas e threads externos subscritos atualmente associados ao segmento de hardware subjacente que este recurso de execução representa.|
|[IExecutionResource::GetExecutionResourceId](#getexecutionresourceid)|Retorna um identificador exclusivo para o segmento de hardware que este recurso de execução representa.|
|[iExecutionResource::GetNodeId](#getnodeid)|Retorna um identificador exclusivo para o nó do processador ao qual este recurso de execução pertence.|
|[iExecutionResource::Remove](#remove)|Retorna esse recurso de execução ao Gerenciador de Recursos.|

## <a name="remarks"></a>Comentários

Os recursos de execução podem ser autônomos ou associados às raízes do processador virtual. Um recurso de execução autônomo é criado quando um segmento em seu aplicativo cria uma assinatura de thread. Os métodos [ISchedulerProxy::SubscribeThread](ischedulerproxy-structure.md#subscribecurrentthread) e [ISchedulerProxy::RequestInitialVirtualProcessors](ischedulerproxy-structure.md#requestinitialvirtualprocessors) criam assinaturas `IExecutionResource` de thread e retornam uma interface representando a assinatura. Criar uma assinatura de thread é uma maneira de informar o Gerenciador de recursos que um determinado segmento participará do trabalho enfileirado a um agendador, juntamente com as raízes do processador virtual que o Resource Manager atribui ao agendador. O Gerenciador de recursos usa as informações para evitar a subscrição excessiva de threads de hardware onde puder.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IExecutionResource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="iexecutionresourcecurrentsubscriptionlevel-method"></a><a name="currentsubscriptionlevel"></a>IExecutionResource::CurrentSubscriptionLevel Method

Retorna o número de raízes de processador virtual ativadas e threads externos subscritos atualmente associados ao segmento de hardware subjacente que este recurso de execução representa.

```cpp
virtual unsigned int CurrentSubscriptionLevel() const = 0;
```

### <a name="return-value"></a>Valor retornado

O nível de assinatura atual.

### <a name="remarks"></a>Comentários

O nível de assinatura informa quantos threads em execução estão associados ao segmento de hardware. Isso só inclui threads que o Resource Manager está ciente na forma de threads subscritos e raízes de processadorvirtuais virtuais que estão executando ativamente os proxies de thread.

Chamando o método [ISchedulerProxy::SubscribeCurrentThread](ischedulerproxy-structure.md#subscribecurrentthread)ou o método [ISchedulerProxy::RequestInitialVirtualProcessors](ischedulerproxy-structure.md#requestinitialvirtualprocessors) com o parâmetro `doSubscribeCurrentThread` definido para o valor **verdadeiro** incrementa o nível de assinatura de um segmento de hardware por um. Eles também `IExecutionResource` retornam uma interface representando a assinatura. Uma chamada correspondente ao [IExecutionResource::Remover](#remove) diminui o nível de assinatura do segmento de hardware por um.

O ato de ativar uma raiz de processador virtual usando o método [IVirtualProcessorRoot::Ativar](ivirtualprocessorroot-structure.md#activate) incrementa o nível de assinatura de um segmento de hardware por um. Os métodos [IVirtualProcessorRoot::Deactivate](ivirtualprocessorroot-structure.md#deactivate), ou [IExecutionResource::Remove](#remove) decredção do nível de assinatura por um quando invocado em uma raiz de processador virtual ativada.

O Gerenciador de Recursos usa as informações de nível de assinatura como uma das maneiras pelas quais determinar quando mover recursos entre agendadores.

## <a name="iexecutionresourcegetexecutionresourceid-method"></a><a name="getexecutionresourceid"></a>IExecutionResource::GetExecutionResourceId Method

Retorna um identificador exclusivo para o segmento de hardware que este recurso de execução representa.

```cpp
virtual unsigned int GetExecutionResourceId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador exclusivo para o segmento de hardware subjacente a este recurso de execução.

### <a name="remarks"></a>Comentários

Cada segmento de hardware é atribuído a um identificador exclusivo pelo Tempo de Execução de Concorrência. Se vários recursos de execução estiverem associados ao segmento de hardware, todos eles terão o mesmo identificador de recursos de execução.

## <a name="iexecutionresourcegetnodeid-method"></a><a name="getnodeid"></a>IExecutionResource::GetNodeId Method

Retorna um identificador exclusivo para o nó do processador ao qual este recurso de execução pertence.

```cpp
virtual unsigned int GetNodeId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador exclusivo para um nó de processador.

### <a name="remarks"></a>Comentários

O Tempo de Execução de Concorrência representa threads de hardware no sistema em grupos de nós do processador. Os nós são geralmente derivados da topologia de hardware do sistema. Por exemplo, todos os processadores em um soquete específico ou um nó NUMA específico podem pertencer ao mesmo nó do processador. O Gerenciador de recursos atribui identificadores exclusivos a esses nós, começando `0` com e incluindo, `nodeCount - 1`onde `nodeCount` representa o número total de nós do processador no sistema.

A contagem de nós pode ser obtida a partir da função [GetProcessorNodeCount](concurrency-namespace-functions.md).

## <a name="iexecutionresourceremove-method"></a><a name="remove"></a>IExecutionResource::Remove Method

Retorna esse recurso de execução ao Gerenciador de Recursos.

```cpp
virtual void Remove(_Inout_ IScheduler* pScheduler) = 0;
```

### <a name="parameters"></a>Parâmetros

*pScheduler*<br/>
Uma interface para o agendador fazendo a solicitação para remover esse recurso de execução.

### <a name="remarks"></a>Comentários

Use esse método para retornar recursos de execução autônomos, bem como recursos de execução associados às raízes do processador virtual ao Gerenciador de recursos.

Se este for um recurso de execução autônomo que você recebeu de qualquer um dos métodos [ISchedulerProxy::SubscribeCurrentThread](ischedulerproxy-structure.md#subscribecurrentthread) ou [ISchedulerProxy::RequestInitialVirtualProcessors](ischedulerproxy-structure.md#requestinitialvirtualprocessors), chamando o método `Remove` acabará com a assinatura de thread que o recurso foi criado para representar. Você é obrigado a terminar todas as assinaturas de thread `Remove` antes de desligar um proxy do agendador e deve ligar a partir do thread que criou a assinatura.

As raízes do processador virtual, também, podem ser devolvidas ao Resource Manager invocando o `Remove` método, porque a interface `IVirtualProcessorRoot` herda da `IExecutionResource` interface. Você pode precisar retornar uma raiz de processador virtual em resposta a uma chamada para o método [IScheduler::RemoveVirtualProcessors](ischeduler-structure.md#removevirtualprocessors) ou quando você terminar com uma raiz de processador virtual subscrita em excesso que você obteve do método [ISchedulerProxy::CreateOversubscriber.](ischedulerproxy-structure.md#createoversubscriber) Para raízes virtuais do processador, não há restrições sobre qual segmento pode invocar o `Remove` método.

`invalid_argument`é jogado se `pScheduler` o parâmetro `NULL`for definido para .

`invalid_operation`é jogado se `pScheduler` o parâmetro for diferente do programador para o que esse recurso de execução foi criado, ou, com um recurso de execução autônomo, se o segmento atual for diferente do segmento que criou a assinatura do segmento.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)<br/>
[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)
