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
ms.openlocfilehash: 9f8f5c5629e9794ca8ee2cc6bedbc4ba6bfdb24d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62262509"
---
# <a name="iexecutionresource-structure"></a>Estrutura IExecutionResource

Uma abstração para um thread de hardware.

## <a name="syntax"></a>Sintaxe

```
struct IExecutionResource;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IExecutionResource::CurrentSubscriptionLevel](#currentsubscriptionlevel)|Retorna o número de processador virtual ativado raízes e assinado threads externos associados atualmente com o thread de hardware subjacente, que esse recurso de execução representa.|
|[IExecutionResource::GetExecutionResourceId](#getexecutionresourceid)|Retorna um identificador exclusivo para o thread de hardware que representa esse recurso de execução.|
|[IExecutionResource::GetNodeId](#getnodeid)|Retorna um identificador exclusivo para o nó de processador pertencente a esse recurso de execução.|
|[IExecutionResource::Remove](#remove)|Retorna este recurso de execução para o Gerenciador de recursos.|

## <a name="remarks"></a>Comentários

Recursos de execução podem ser autônomo ou associados com raízes de processador virtual. Um recurso de execução autônoma é criado quando um thread em seu aplicativo cria uma assinatura de thread. Os métodos [ISchedulerProxy::SubscribeThread](ischedulerproxy-structure.md#subscribecurrentthread) e [ischedulerproxy:: Requestinitialvirtualprocessors](ischedulerproxy-structure.md#requestinitialvirtualprocessors) criar assinaturas de thread e retornar um `IExecutionResource` interface que representa o assinatura. Criando uma assinatura de thread é uma maneira de informar o Gerenciador de recursos que um determinado thread farão parte no trabalho na fila para um agendador, juntamente com as raízes de processador virtual do Resource Manager atribui ao Agendador. O Gerenciador de recursos usa as informações para evitar sobrecarregar a segmentos de hardware, onde possível.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IExecutionResource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

##  <a name="currentsubscriptionlevel"></a>  Método iexecutionresource:: Currentsubscriptionlevel

Retorna o número de processador virtual ativado raízes e assinado threads externos associados atualmente com o thread de hardware subjacente, que esse recurso de execução representa.

```
virtual unsigned int CurrentSubscriptionLevel() const = 0;
```

### <a name="return-value"></a>Valor de retorno

O nível de assinatura atual.

### <a name="remarks"></a>Comentários

O nível de assinatura informa quantos threads em execução estão associados com o thread de hardware. Isso inclui apenas os threads que o Gerenciador de recursos está ciente de na forma de segmentos assinados e raízes de processador virtual que estão em execução ativamente a proxies de thread.

Chamar o método [ischedulerproxy:: Subscribecurrentthread](ischedulerproxy-structure.md#subscribecurrentthread), ou o método [ischedulerproxy:: Requestinitialvirtualprocessors](ischedulerproxy-structure.md#requestinitialvirtualprocessors) com o parâmetro `doSubscribeCurrentThread` definido como o valor **verdadeiro** incrementa o nível de assinatura de um thread de hardware em um. Eles também retornam um `IExecutionResource` interface que representa a assinatura. Uma chamada correspondente para o [iexecutionresource:: remove](#remove) diminui nível de assinatura do thread de hardware por um.

O ato de ativação de uma raiz de processador virtual usando o método [ivirtualprocessorroot:: Activate](ivirtualprocessorroot-structure.md#activate) incrementa o nível de assinatura de um thread de hardware em um. Os métodos [ivirtualprocessorroot:: Deactivate](ivirtualprocessorroot-structure.md#deactivate), ou [iexecutionresource:: remove](#remove) diminuir o nível de assinatura por um quando invocado em uma raiz de processador virtual ativado.

O Gerenciador de recursos usa informações de nível de assinatura como uma das maneiras em que determinar quando mover recursos entre os agendadores.

##  <a name="getexecutionresourceid"></a>  Método iexecutionresource:: Getexecutionresourceid

Retorna um identificador exclusivo para o thread de hardware que representa esse recurso de execução.

```
virtual unsigned int GetExecutionResourceId() const = 0;
```

### <a name="return-value"></a>Valor de retorno

Um identificador exclusivo para o thread de hardware subjacente a esse recurso de execução.

### <a name="remarks"></a>Comentários

Cada thread de hardware é atribuído um identificador exclusivo no tempo de execução de simultaneidade. Se vários recursos de execução são hardware associado thread, eles terão o mesmo identificador de recurso de execução.

##  <a name="getnodeid"></a>  Método iexecutionresource:: Getnodeid

Retorna um identificador exclusivo para o nó de processador pertencente a esse recurso de execução.

```
virtual unsigned int GetNodeId() const = 0;
```

### <a name="return-value"></a>Valor de retorno

Um identificador exclusivo para um nó de processador.

### <a name="remarks"></a>Comentários

O tempo de execução de simultaneidade representa threads de hardware no sistema em grupos de nós de processador. Nós geralmente são derivados da topologia do hardware do sistema. Por exemplo, todos os processadores em um soquete específico ou um nó NUMA específico podem pertencer ao mesmo nó de processador. O Gerenciador de recursos atribui identificadores exclusivos para esses nós começando com `0` até e incluindo `nodeCount - 1`, onde `nodeCount` representa o número total de nós de processador no sistema.

A contagem de nós pode ser obtida da função [GetProcessorNodeCount](concurrency-namespace-functions.md).

##  <a name="remove"></a>  Método iexecutionresource:: remove

Retorna este recurso de execução para o Gerenciador de recursos.

```
virtual void Remove(_Inout_ IScheduler* pScheduler) = 0;
```

### <a name="parameters"></a>Parâmetros

*pScheduler*<br/>
Uma interface para o Agendador está fazendo a solicitação para remover esse recurso de execução.

### <a name="remarks"></a>Comentários

Use esse método para retornar os recursos de execução autônoma, bem como recursos de execução associados com raízes de processador virtual para o Gerenciador de recursos.

Quando se trata de um recurso de execução autônomo que você recebeu de qualquer um dos métodos [ischedulerproxy:: Subscribecurrentthread](ischedulerproxy-structure.md#subscribecurrentthread) ou [ischedulerproxy:: Requestinitialvirtualprocessors](ischedulerproxy-structure.md#requestinitialvirtualprocessors), chamar o método `Remove` terminará a assinatura de thread que o recurso foi criado para representar. São necessárias para encerrar todas as assinaturas do thread antes de desligar um proxy do Agendador e deve chamar `Remove` do thread que criou a assinatura.

Raízes de processador virtual, também, podem ser retornados para o Gerenciador de recursos, invocando o `Remove` método, porque a interface `IVirtualProcessorRoot` herda o `IExecutionResource` interface. Talvez você precise retornar uma raiz virtual do processador em resposta a uma chamada para o [ischeduler:: Removevirtualprocessors](ischeduler-structure.md#removevirtualprocessors) método, ou quando você terminar com uma raiz de processador virtual assinadas obtida do [ Ischedulerproxy:: Createoversubscriber](ischedulerproxy-structure.md#createoversubscriber) método. Para as raízes de processador virtual, não há nenhuma restrição em qual thread pode invocar o `Remove` método.

`invalid_argument` será gerada se o parâmetro `pScheduler` é definido como `NULL`.

`invalid_operation` será gerada se o parâmetro `pScheduler` é diferente do Agendador que este recurso de execução foi criado para ou, com um recurso de execução autônoma, se o thread atual é diferente do thread que criou a assinatura de thread.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)
