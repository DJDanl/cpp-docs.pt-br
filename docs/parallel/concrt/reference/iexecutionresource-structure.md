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
ms.openlocfilehash: 40799d1ed6e21e6932f1adfbad117c436918b792
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78854111"
---
# <a name="iexecutionresource-structure"></a>Estrutura IExecutionResource

Uma abstração para um thread de hardware.

## <a name="syntax"></a>Sintaxe

```cpp
struct IExecutionResource;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IExecutionResource::CurrentSubscriptionLevel](#currentsubscriptionlevel)|Retorna o número de raízes do processador virtual ativadas e os threads externos assinados atualmente associados ao thread de hardware subjacente que esse recurso de execução representa.|
|[IExecutionResource::GetExecutionResourceId](#getexecutionresourceid)|Retorna um identificador exclusivo para o thread de hardware que este recurso de execução representa.|
|[IExecutionResource:: getnodeid](#getnodeid)|Retorna um identificador exclusivo para o nó do processador ao qual esse recurso de execução pertence.|
|[IExecutionResource:: Remove](#remove)|Retorna esse recurso de execução para o Gerenciador de recursos.|

## <a name="remarks"></a>Comentários

Os recursos de execução podem ser autônomos ou associados a raízes de processador virtual. Um recurso de execução autônomo é criado quando um thread em seu aplicativo cria uma assinatura de thread. Os métodos [ISchedulerProxy:: SubscribeThread](ischedulerproxy-structure.md#subscribecurrentthread) e [ISchedulerProxy:: RequestInitialVirtualProcessors](ischedulerproxy-structure.md#requestinitialvirtualprocessors) criam assinaturas de thread e retornam uma interface de `IExecutionResource` que representa a assinatura. A criação de uma assinatura de thread é uma maneira de informar ao Gerenciador de recursos que um determinado thread participará do trabalho na fila para um Agendador, junto com o Gerenciador de recursos de raízes do processador virtual que atribui ao agendador. O Gerenciador de recursos usa as informações para evitar threads de hardware sobrecarregar onde podem.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IExecutionResource`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="currentsubscriptionlevel"></a>Método IExecutionResource:: CurrentSubscriptionLevel

Retorna o número de raízes do processador virtual ativadas e os threads externos assinados atualmente associados ao thread de hardware subjacente que esse recurso de execução representa.

```cpp
virtual unsigned int CurrentSubscriptionLevel() const = 0;
```

### <a name="return-value"></a>Valor retornado

O nível de assinatura atual.

### <a name="remarks"></a>Comentários

O nível de assinatura informa quantos threads em execução estão associados ao thread de hardware. Isso inclui apenas os threads que o Gerenciador de recursos está ciente na forma de threads assinados e raízes de processador virtual que estão executando ativamente proxies de thread.

Chamar o método [ISchedulerProxy:: SubscribeCurrentThread](ischedulerproxy-structure.md#subscribecurrentthread)ou o método [ISchedulerProxy:: RequestInitialVirtualProcessors](ischedulerproxy-structure.md#requestinitialvirtualprocessors) com o parâmetro `doSubscribeCurrentThread` definido como o valor **true** incrementa o nível de assinatura de um thread de hardware em um. Eles também retornam uma interface de `IExecutionResource` que representa a assinatura. Uma chamada correspondente para [IExecutionResource:: Remove](#remove) Decrementa o nível de assinatura do thread de hardware em um.

O ato de ativar uma raiz de processador virtual usando o método [IVirtualProcessorRoot:: Activate](ivirtualprocessorroot-structure.md#activate) incrementa o nível de assinatura de um thread de hardware em um. Os métodos [IVirtualProcessorRoot::D eactivate](ivirtualprocessorroot-structure.md#deactivate)ou [IExecutionResource:: Remove](#remove) decrementam o nível de assinatura em um quando invocado em uma raiz de processador virtual ativada.

O Gerenciador de recursos usa informações de nível de assinatura como uma das maneiras de determinar quando mover recursos entre os agendadores.

## <a name="getexecutionresourceid"></a>Método IExecutionResource:: GetExecutionResourceId

Retorna um identificador exclusivo para o thread de hardware que este recurso de execução representa.

```cpp
virtual unsigned int GetExecutionResourceId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador exclusivo para o thread de hardware subjacente a esse recurso de execução.

### <a name="remarks"></a>Comentários

Cada thread de hardware recebe um identificador exclusivo pelo Tempo de Execução de Simultaneidade. Se vários recursos de execução estiverem associados ao thread de hardware, todos terão o mesmo identificador de recurso de execução.

## <a name="getnodeid"></a>Método IExecutionResource:: getnodeid

Retorna um identificador exclusivo para o nó do processador ao qual esse recurso de execução pertence.

```cpp
virtual unsigned int GetNodeId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador exclusivo para um nó de processador.

### <a name="remarks"></a>Comentários

A Tempo de Execução de Simultaneidade representa os threads de hardware no sistema em grupos de nós de processador. Normalmente, os nós são derivados da topologia de hardware do sistema. Por exemplo, todos os processadores em um soquete específico ou um nó NUMA específico podem pertencer ao mesmo nó de processador. O Gerenciador de recursos atribui identificadores exclusivos a esses nós, começando com `0` até e incluindo `nodeCount - 1`, em que `nodeCount` representa o número total de nós de processador no sistema.

A contagem de nós pode ser obtida na função [GetProcessorNodeCount](concurrency-namespace-functions.md).

## <a name="remove"></a>Método IExecutionResource:: Remove

Retorna esse recurso de execução para o Gerenciador de recursos.

```cpp
virtual void Remove(_Inout_ IScheduler* pScheduler) = 0;
```

### <a name="parameters"></a>Parâmetros

*pScheduler*<br/>
Uma interface para o Agendador que faz a solicitação para remover esse recurso de execução.

### <a name="remarks"></a>Comentários

Use este método para retornar recursos de execução autônomo, bem como recursos de execução associados a raízes de processador virtual para o Gerenciador de recursos.

Se esse for um recurso de execução autônomo que você recebeu de um dos métodos [ISchedulerProxy:: SubscribeCurrentThread](ischedulerproxy-structure.md#subscribecurrentthread) ou [ISchedulerProxy:: RequestInitialVirtualProcessors](ischedulerproxy-structure.md#requestinitialvirtualprocessors), chamar o método `Remove` encerrará a assinatura de thread que o recurso foi criado para representar. Você precisa encerrar todas as assinaturas de thread antes de desligar um proxy do Agendador e deve chamar `Remove` do thread que criou a assinatura.

Raízes de processador virtual também podem ser retornadas ao Gerenciador de recursos invocando o método `Remove`, porque a interface `IVirtualProcessorRoot` herda da interface `IExecutionResource`. Talvez seja necessário retornar uma raiz do processador virtual em resposta a uma chamada para o método [IScheduler:: RemoveVirtualProcessors](ischeduler-structure.md#removevirtualprocessors) ou quando você terminar com uma raiz do processador virtual com assinatura esscrição obtida do método [ISchedulerProxy:: CreateOversubscriber](ischedulerproxy-structure.md#createoversubscriber) . Para raízes de processador virtual, não há restrições sobre qual thread pode invocar o método `Remove`.

`invalid_argument` será gerada se o parâmetro `pScheduler` for definido como `NULL`.

`invalid_operation` será gerada se o parâmetro `pScheduler` for diferente do Agendador para o qual esse recurso de execução foi criado, ou, com um recurso de execução autônomo, se o thread atual for diferente do thread que criou a assinatura de thread.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)
