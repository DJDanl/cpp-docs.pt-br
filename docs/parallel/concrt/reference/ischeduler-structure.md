---
title: Estrutura IScheduler
ms.date: 11/04/2016
f1_keywords:
- IScheduler
- CONCRTRM/concurrency::IScheduler
- CONCRTRM/concurrency::IScheduler::IScheduler::AddVirtualProcessors
- CONCRTRM/concurrency::IScheduler::IScheduler::GetId
- CONCRTRM/concurrency::IScheduler::IScheduler::GetPolicy
- CONCRTRM/concurrency::IScheduler::IScheduler::NotifyResourcesExternallyBusy
- CONCRTRM/concurrency::IScheduler::IScheduler::NotifyResourcesExternallyIdle
- CONCRTRM/concurrency::IScheduler::IScheduler::RemoveVirtualProcessors
- CONCRTRM/concurrency::IScheduler::IScheduler::Statistics
helpviewer_keywords:
- IScheduler structure
ms.assetid: 471de85a-2b1a-4b6d-ab81-2eff2737161e
ms.openlocfilehash: cd7b04b0dc5ca1bc496ce87a6459d00ed5813bf7
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142317"
---
# <a name="ischeduler-structure"></a>Estrutura IScheduler

Uma interface para uma abstração de um Agendador de trabalho. O Gerenciador de recursos do Tempo de Execução de Simultaneidade usa essa interface para se comunicar com agendadores de trabalho.

## <a name="syntax"></a>Sintaxe

```cpp
struct IScheduler;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IScheduler:: AddVirtualProcessors](#addvirtualprocessors)|Fornece um Agendador com um conjunto de raízes de processador virtual para seu uso. Cada interface de `IVirtualProcessorRoot` representa o direito de executar um único thread que pode executar o trabalho em nome do Agendador.|
|[IScheduler:: GetId](#getid)|Retorna um identificador exclusivo para o Agendador.|
|[IScheduler:: GetPolicy](#getpolicy)|Retorna uma cópia da política do Agendador. Para obter mais informações sobre as políticas do Agendador, consulte [SchedulerPolicy](schedulerpolicy-class.md).|
|[IScheduler:: NotifyResourcesExternallyBusy](#notifyresourcesexternallybusy)|Notifica este Agendador que os threads de hardware representados pelo conjunto de raízes de processador virtual na matriz `ppVirtualProcessorRoots` agora estão sendo usados por outros agendadores.|
|[IScheduler:: NotifyResourcesExternallyIdle](#notifyresourcesexternallyidle)|Notifica este Agendador que os threads de hardware representados pelo conjunto de raízes de processador virtual na matriz `ppVirtualProcessorRoots` não estão sendo usados por outros agendadores.|
|[IScheduler:: RemoveVirtualProcessors](#removevirtualprocessors)|Inicia a remoção de raízes de processador virtual que foram alocadas anteriormente para este Agendador.|
|[IScheduler:: Statistics](#statistics)|Fornece informações relacionadas à chegada da tarefa e às taxas de conclusão e alteração no comprimento da fila para um Agendador.|

## <a name="remarks"></a>Comentários

Se você estiver implementando um Agendador personalizado que se comunica com o Gerenciador de recursos, você deve fornecer uma implementação da interface `IScheduler`. Essa interface é uma extremidade de um canal bidirecional de comunicação entre um Agendador e o Gerenciador de recursos. A outra extremidade é representada pelas interfaces `IResourceManager` e `ISchedulerProxy` que são implementadas pelo Gerenciador de recursos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IScheduler`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="addvirtualprocessors"></a>Método IScheduler:: AddVirtualProcessors

Fornece um Agendador com um conjunto de raízes de processador virtual para seu uso. Cada interface de `IVirtualProcessorRoot` representa o direito de executar um único thread que pode executar o trabalho em nome do Agendador.

```cpp
virtual void AddVirtualProcessors(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```

### <a name="parameters"></a>Parâmetros

*ppVirtualProcessorRoots*<br/>
Uma matriz de interfaces de `IVirtualProcessorRoot` que representa as raízes do processador virtual que estão sendo adicionadas ao agendador.

*contagem*<br/>
O número de interfaces `IVirtualProcessorRoot` na matriz.

### <a name="remarks"></a>Comentários

O Gerenciador de recursos invoca o método `AddVirtualProcessor` para conceder um conjunto inicial de raízes de processador virtual a um Agendador. Ele também pode invocar o método para adicionar raízes de processador virtual ao agendador ao reequilibrar os recursos entre os agendadores.

## <a name="getid"></a>Método IScheduler:: GetId

Retorna um identificador exclusivo para o Agendador.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador inteiro exclusivo.

### <a name="remarks"></a>Comentários

Você deve usar a função [GetSchedulerId](concurrency-namespace-functions.md) para obter um identificador exclusivo para o objeto que implementa a interface `IScheduler`, antes de usar a interface como um parâmetro para os métodos fornecidos pelo Gerenciador de recursos. Você deve retornar o mesmo identificador quando a função `GetId` for invocada.

Um identificador obtido de uma fonte diferente poderia resultar em um comportamento indefinido.

## <a name="getpolicy"></a>Método IScheduler:: GetPolicy

Retorna uma cópia da política do Agendador. Para obter mais informações sobre as políticas do Agendador, consulte [SchedulerPolicy](schedulerpolicy-class.md).

```cpp
virtual SchedulerPolicy GetPolicy() const = 0;
```

### <a name="return-value"></a>Valor retornado

Uma cópia da política do Agendador.

## <a name="notifyresourcesexternallybusy"></a>Método IScheduler:: NotifyResourcesExternallyBusy

Notifica este Agendador que os threads de hardware representados pelo conjunto de raízes de processador virtual na matriz `ppVirtualProcessorRoots` agora estão sendo usados por outros agendadores.

```cpp
virtual void NotifyResourcesExternallyBusy(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```

### <a name="parameters"></a>Parâmetros

*ppVirtualProcessorRoots*<br/>
Uma matriz de interfaces `IVirtualProcessorRoot` associadas aos threads de hardware nos quais outros agendadores se tornaram ocupados.

*contagem*<br/>
O número de interfaces `IVirtualProcessorRoot` na matriz.

### <a name="remarks"></a>Comentários

É possível que um determinado thread de hardware seja atribuído a vários agendadores ao mesmo tempo. Um motivo para isso pode ser que não haja threads de hardware suficientes no sistema para atender à simultaneidade mínima para todos os agendadores, sem compartilhar recursos. Outra possibilidade é que os recursos sejam atribuídos temporariamente a outros agendadores quando o Agendador proprietário não estiver usando-os, por meio de todas as raízes de processador virtual no thread de hardware que está sendo desativado.

O nível de assinatura de um thread de hardware é indicado pelo número de threads assinados e raízes de processador virtual ativadas associadas a esse thread de hardware. De um ponto de vista de um Agendador específico, o nível de assinatura externa de um thread de hardware é a parte da assinatura que outros agendadores contribuem para o. As notificações de que os recursos estão externos ocupados são enviadas a um Agendador quando o nível de assinatura externo para um thread de hardware é movido de zero para uma região positiva.

As notificações por meio desse método são enviadas somente aos agendadores que têm uma política em que o valor para a chave de política de `MinConcurrency` é igual ao valor da chave de política de `MaxConcurrency`. Para obter mais informações sobre as políticas do Agendador, consulte [SchedulerPolicy](schedulerpolicy-class.md).

Um Agendador que se qualifica para notificações obtém um conjunto de notificações iniciais quando ele é criado, informando se os recursos que acabou de ser atribuído estão externos ou ociosos.

## <a name="notifyresourcesexternallyidle"></a>Método IScheduler:: NotifyResourcesExternallyIdle

Notifica este Agendador que os threads de hardware representados pelo conjunto de raízes de processador virtual na matriz `ppVirtualProcessorRoots` não estão sendo usados por outros agendadores.

```cpp
virtual void NotifyResourcesExternallyIdle(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```

### <a name="parameters"></a>Parâmetros

*ppVirtualProcessorRoots*<br/>
Uma matriz de interfaces `IVirtualProcessorRoot` associadas a threads de hardware nos quais outros agendadores se tornaram ociosos.

*contagem*<br/>
O número de interfaces `IVirtualProcessorRoot` na matriz.

### <a name="remarks"></a>Comentários

É possível que um determinado thread de hardware seja atribuído a vários agendadores ao mesmo tempo. Um motivo para isso pode ser que não haja threads de hardware suficientes no sistema para atender à simultaneidade mínima para todos os agendadores, sem compartilhar recursos. Outra possibilidade é que os recursos sejam atribuídos temporariamente a outros agendadores quando o Agendador proprietário não estiver usando-os, por meio de todas as raízes de processador virtual no thread de hardware que está sendo desativado.

O nível de assinatura de um thread de hardware é indicado pelo número de threads assinados e raízes de processador virtual ativadas associadas a esse thread de hardware. De um ponto de vista de um Agendador específico, o nível de assinatura externa de um thread de hardware é a parte da assinatura que outros agendadores contribuem para o. As notificações de que os recursos estão externos ocupados são enviadas a um Agendador quando o nível de assinatura externo para um thread de hardware cai para zero a partir de um valor positivo anterior.

As notificações por meio desse método são enviadas somente aos agendadores que têm uma política em que o valor para a chave de política de `MinConcurrency` é igual ao valor da chave de política de `MaxConcurrency`. Para obter mais informações sobre as políticas do Agendador, consulte [SchedulerPolicy](schedulerpolicy-class.md).

Um Agendador que se qualifica para notificações obtém um conjunto de notificações iniciais quando ele é criado, informando se os recursos que acabou de ser atribuído estão externos ou ociosos.

## <a name="removevirtualprocessors"></a>Método IScheduler:: RemoveVirtualProcessors

Inicia a remoção de raízes de processador virtual que foram alocadas anteriormente para este Agendador.

```cpp
virtual void RemoveVirtualProcessors(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```

### <a name="parameters"></a>Parâmetros

*ppVirtualProcessorRoots*<br/>
Uma matriz de interfaces de `IVirtualProcessorRoot` que representa as raízes do processador virtual a serem removidas.

*contagem*<br/>
O número de interfaces `IVirtualProcessorRoot` na matriz.

### <a name="remarks"></a>Comentários

O Gerenciador de recursos invoca o método `RemoveVirtualProcessors` para retornar um conjunto de raízes de processador virtual de um Agendador. Espera-se que o Agendador invoque o método [Remove](iexecutionresource-structure.md#remove) em cada interface quando for feito com as raízes do processador virtual. Não use uma interface `IVirtualProcessorRoot` depois de invocar o método `Remove` nela.

O parâmetro `ppVirtualProcessorRoots` aponta para uma matriz de interfaces. Entre o conjunto de raízes do processador virtual a ser removido, as raízes nunca foram ativadas pode ser retornadas imediatamente usando o método `Remove`. As raízes que foram ativadas e estão executando o trabalho ou foram desativadas e aguardando o trabalho chegar, devem ser retornadas de forma assíncrona. O Agendador deve fazer todas as tentativas de remover a raiz do processador virtual o mais rápido possível. Atrasar a remoção das raízes do processador virtual pode resultar em excesso de assinaturas não intencional dentro do Agendador.

## <a name="statistics"></a>Método IScheduler:: Statistics

Fornece informações relacionadas à chegada da tarefa e às taxas de conclusão e alteração no comprimento da fila para um Agendador.

```cpp
virtual void Statistics(
    _Out_ unsigned int* pTaskCompletionRate,
    _Out_ unsigned int* pTaskArrivalRate,
    _Out_ unsigned int* pNumberOfTasksEnqueued) = 0;
```

### <a name="parameters"></a>Parâmetros

*pTaskCompletionRate*<br/>
O número de tarefas que foram concluídas pelo Agendador desde a última chamada para esse método.

*pTaskArrivalRate*<br/>
O número de tarefas que chegaram no Agendador desde a última chamada para esse método.

*pNumberOfTasksEnqueued*<br/>
O número total de tarefas em todas as filas do Agendador.

### <a name="remarks"></a>Comentários

Esse método é invocado pelo Gerenciador de recursos para reunir estatísticas para um Agendador. As estatísticas coletadas aqui serão usadas para direcionar os algoritmos de comentários dinâmicos para determinar quando é apropriado atribuir mais recursos ao agendador e quando retirar recursos. Os valores fornecidos pelo Agendador podem ser otimistas e não necessariamente precisam refletir a contagem atual com precisão.

Você deve implementar esse método se quiser que o Gerenciador de recursos use comentários sobre coisas como a chegada da tarefa para determinar como balancear o recurso entre o Agendador e outros agendadores registrados com o Gerenciador de recursos. Se você optar por não coletar estatísticas, poderá definir a chave de política `DynamicProgressFeedback` como o valor `DynamicProgressFeedbackDisabled` na política do Agendador e o Gerenciador de recursos não invocará esse método no Agendador.

Na ausência de informações estatísticas, o Gerenciador de recursos usará níveis de assinatura de thread de hardware para tomar decisões de migração e alocação de recursos. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource:: CurrentSubscriptionLevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[PolicyElementKey](concurrency-namespace-enums.md)<br/>
[Classe SchedulerPolicy](schedulerpolicy-class.md)<br/>
[Estrutura IExecutionContext](iexecutioncontext-structure.md)<br/>
[Estrutura IThreadProxy](ithreadproxy-structure.md)<br/>
[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)<br/>
[Estrutura IResourceManager](iresourcemanager-structure.md)
