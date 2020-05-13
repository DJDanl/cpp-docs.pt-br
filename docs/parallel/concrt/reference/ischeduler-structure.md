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
ms.openlocfilehash: ccd82b5c5112bc322717f2b58d79d4c8f34f5bbd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368168"
---
# <a name="ischeduler-structure"></a>Estrutura IScheduler

Uma interface para uma abstração de um agendador de trabalho. O Gerenciador de Recursos do Concurrency Runtime usa essa interface para se comunicar com agendadores de trabalho.

## <a name="syntax"></a>Sintaxe

```cpp
struct IScheduler;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IScheduler::Adicionarprocessadores virtuais](#addvirtualprocessors)|Fornece um agendador com um conjunto de raízes de processador virtual para seu uso. Cada `IVirtualProcessorRoot` interface representa o direito de executar um único segmento que pode executar o trabalho em nome do agendador.|
|[IScheduler::GetId](#getid)|Retorna um identificador exclusivo para o agendador.|
|[IScheduler::GetPolicy](#getpolicy)|Devolve uma cópia da política do agendador. Para obter mais informações sobre políticas de agendadores, consulte [SchedulerPolicy](schedulerpolicy-class.md).|
|[iScheduler::NotificarrecursosExternamenteocupado](#notifyresourcesexternallybusy)|Notifica este agendador que os segmentos de hardware representados `ppVirtualProcessorRoots` pelo conjunto de raízes do processador virtual no array estão sendo usados por outros agendadores.|
|[iScheduler::NotificarRecursosExternallyIdle](#notifyresourcesexternallyidle)|Notifica este agendador que os segmentos de hardware representados `ppVirtualProcessorRoots` pelo conjunto de raízes do processador virtual no array não estão sendo usados por outros agendadores.|
|[IScheduler::RemoveVirtualProcessors](#removevirtualprocessors)|Inicia a remoção das raízes do processador virtual que foram previamente alocadas a este agendador.|
|[IScheduler::Estatísticas](#statistics)|Fornece informações relacionadas às taxas de chegada e conclusão de tarefas e altera o comprimento da fila para um agendador.|

## <a name="remarks"></a>Comentários

Se você estiver implementando um agendador personalizado que se comunica com `IScheduler` o Gerenciador de Recursos, você deve fornecer uma implementação da interface. Esta interface é uma extremidade de um canal de comunicação bidirecional entre um agendador e o Gerenciador de Recursos. A outra extremidade é `IResourceManager` `ISchedulerProxy` representada pelas interfaces que são implementadas pelo Gerenciador de Recursos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IScheduler`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="ischeduleraddvirtualprocessors-method"></a><a name="addvirtualprocessors"></a>iScheduler::Adicionar método de processadores virtuais

Fornece um agendador com um conjunto de raízes de processador virtual para seu uso. Cada `IVirtualProcessorRoot` interface representa o direito de executar um único segmento que pode executar o trabalho em nome do agendador.

```cpp
virtual void AddVirtualProcessors(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```

### <a name="parameters"></a>Parâmetros

*ppVirtualProcessorroots*<br/>
Uma série `IVirtualProcessorRoot` de interfaces representando as raízes do processador virtual sendo adicionadas ao agendador.

*contagem*<br/>
O número `IVirtualProcessorRoot` de interfaces na matriz.

### <a name="remarks"></a>Comentários

O Gerenciador de `AddVirtualProcessor` recursos invoca o método para conceder um conjunto inicial de raízes de processador virtual a um agendador. Ele também poderia invocar o método para adicionar raízes de processador virtuais ao agendador quando ele reequilibra recursos entre agendadores.

## <a name="ischedulergetid-method"></a><a name="getid"></a>IScheduler::Método GetId

Retorna um identificador exclusivo para o agendador.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador inteiro único.

### <a name="remarks"></a>Comentários

Você deve usar a função [GetSchedulerId](concurrency-namespace-functions.md) para obter um identificador exclusivo para o objeto que implementa a `IScheduler` interface, antes de usar a interface como parâmetro para métodos fornecidos pelo Gerenciador de recursos. Espera-se que retorne o mesmo `GetId` identificador quando a função for invocada.

Um identificador obtido de uma fonte diferente pode resultar em comportamento indefinido.

## <a name="ischedulergetpolicy-method"></a><a name="getpolicy"></a>IScheduler::GetPolicy Method

Devolve uma cópia da política do agendador. Para obter mais informações sobre políticas de agendadores, consulte [SchedulerPolicy](schedulerpolicy-class.md).

```cpp
virtual SchedulerPolicy GetPolicy() const = 0;
```

### <a name="return-value"></a>Valor retornado

Uma cópia da política do agendador.

## <a name="ischedulernotifyresourcesexternallybusy-method"></a><a name="notifyresourcesexternallybusy"></a>iScheduler::NotificarrecursosMétodoocupado externamente

Notifica este agendador que os segmentos de hardware representados `ppVirtualProcessorRoots` pelo conjunto de raízes do processador virtual no array estão sendo usados por outros agendadores.

```cpp
virtual void NotifyResourcesExternallyBusy(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```

### <a name="parameters"></a>Parâmetros

*ppVirtualProcessorroots*<br/>
Uma matriz `IVirtualProcessorRoot` de interfaces associadas aos threads de hardware nos quais outros agendadores ficaram ocupados.

*contagem*<br/>
O número `IVirtualProcessorRoot` de interfaces na matriz.

### <a name="remarks"></a>Comentários

É possível que um segmento de hardware específico seja atribuído a vários agendadores ao mesmo tempo. Uma das razões para isso pode ser que não há threads de hardware suficientes no sistema para satisfazer a concorrência mínima para todos os agendadores, sem compartilhar recursos. Outra possibilidade é que os recursos sejam temporariamente atribuídos a outros agendadores quando o agendador de propriedade não os estiver usando, por meio de todas as suas raízes de processador virtuais naquele segmento de hardware sendo desativado.

O nível de assinatura de um segmento de hardware é denotado pelo número de threads subscritos e raízes ativadas do processador virtual associadas a esse segmento de hardware. Do ponto de vista de um programador específico, o nível de assinatura externa de um segmento de hardware é a parte da assinatura que outros agendadores contribuem. Notificações de que os recursos estão ocupados externamente são enviadas a um agendador quando o nível de assinatura externa de um segmento de hardware se move de zero para território positivo.

As notificações através deste método são enviadas apenas para agendadores que possuem uma política onde o valor para a chave de `MinConcurrency` política é igual ao valor da chave de `MaxConcurrency` política. Para obter mais informações sobre políticas de agendadores, consulte [SchedulerPolicy](schedulerpolicy-class.md).

Um agendador que se qualifica para notificações recebe um conjunto de notificações iniciais quando é criado, informando se os recursos que foi atribuído são ocupados externamente ou ociosos.

## <a name="ischedulernotifyresourcesexternallyidle-method"></a><a name="notifyresourcesexternallyidle"></a>iScheduler::NotificarrecursosMétodoExternomenteIdle

Notifica este agendador que os segmentos de hardware representados `ppVirtualProcessorRoots` pelo conjunto de raízes do processador virtual no array não estão sendo usados por outros agendadores.

```cpp
virtual void NotifyResourcesExternallyIdle(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```

### <a name="parameters"></a>Parâmetros

*ppVirtualProcessorroots*<br/>
Uma matriz `IVirtualProcessorRoot` de interfaces associadas a threads de hardware nos quais outros agendadores ficaram ociosos.

*contagem*<br/>
O número `IVirtualProcessorRoot` de interfaces na matriz.

### <a name="remarks"></a>Comentários

É possível que um segmento de hardware específico seja atribuído a vários agendadores ao mesmo tempo. Uma das razões para isso pode ser que não há threads de hardware suficientes no sistema para satisfazer a concorrência mínima para todos os agendadores, sem compartilhar recursos. Outra possibilidade é que os recursos sejam temporariamente atribuídos a outros agendadores quando o agendador de propriedade não os estiver usando, por meio de todas as suas raízes de processador virtuais naquele segmento de hardware sendo desativado.

O nível de assinatura de um segmento de hardware é denotado pelo número de threads subscritos e raízes ativadas do processador virtual associadas a esse segmento de hardware. Do ponto de vista de um programador específico, o nível de assinatura externa de um segmento de hardware é a parte da assinatura que outros agendadores contribuem. Notificações de que os recursos estão ocupados externamente são enviadas a um agendador quando o nível de assinatura externa de um segmento de hardware cai para zero de um valor positivo anterior.

As notificações através deste método são enviadas apenas para agendadores que possuem uma política onde o valor para a chave de `MinConcurrency` política é igual ao valor da chave de `MaxConcurrency` política. Para obter mais informações sobre políticas de agendadores, consulte [SchedulerPolicy](schedulerpolicy-class.md).

Um agendador que se qualifica para notificações recebe um conjunto de notificações iniciais quando é criado, informando se os recursos que foi atribuído são ocupados externamente ou ociosos.

## <a name="ischedulerremovevirtualprocessors-method"></a><a name="removevirtualprocessors"></a>iScheduler::Remover método deprocessadores virtuais

Inicia a remoção das raízes do processador virtual que foram previamente alocadas a este agendador.

```cpp
virtual void RemoveVirtualProcessors(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```

### <a name="parameters"></a>Parâmetros

*ppVirtualProcessorroots*<br/>
Uma matriz `IVirtualProcessorRoot` de interfaces representando as raízes do processador virtual a serem removidas.

*contagem*<br/>
O número `IVirtualProcessorRoot` de interfaces na matriz.

### <a name="remarks"></a>Comentários

O Gerenciador de `RemoveVirtualProcessors` recursos invoca o método para retomar um conjunto de raízes de processador virtuais de um agendador. Espera-se que o agendador invoque o método [Remover](iexecutionresource-structure.md#remove) em cada interface quando for feito com as raízes do processador virtual. Não use `IVirtualProcessorRoot` uma interface depois de `Remove` ter invocado o método nela.

O parâmetro `ppVirtualProcessorRoots` aponta para uma matriz de interfaces. Entre o conjunto de raízes do processador virtual a serem removidas, as `Remove` raízes nunca foram ativadas podem ser devolvidas imediatamente usando o método. As raízes que foram ativadas e estão executando o trabalho, ou foram desativadas e aguardam a chegada do trabalho, devem ser devolvidas assíncronamente. O agendador deve fazer todas as tentativas de remover a raiz do processador virtual o mais rápido possível. Atrasar a remoção das raízes do processador virtual pode resultar em superassinatura não intencional dentro do agendador.

## <a name="ischedulerstatistics-method"></a><a name="statistics"></a>IScheduler::Método de estatística

Fornece informações relacionadas às taxas de chegada e conclusão de tarefas e altera o comprimento da fila para um agendador.

```cpp
virtual void Statistics(
    _Out_ unsigned int* pTaskCompletionRate,
    _Out_ unsigned int* pTaskArrivalRate,
    _Out_ unsigned int* pNumberOfTasksEnqueued) = 0;
```

### <a name="parameters"></a>Parâmetros

*taxa de conclusão de tarefas pTask*<br/>
O número de tarefas que foram concluídas pelo agendador desde a última chamada para este método.

*pTaskArrivalRate*<br/>
O número de tarefas que chegaram ao agendador desde a última chamada para este método.

*pNumberOfTasksEnued*<br/>
O número total de tarefas em todas as filas do agendador.

### <a name="remarks"></a>Comentários

Este método é invocado pelo Gerenciador de Recursos para coletar estatísticas para um agendador. As estatísticas coletadas aqui serão usadas para impulsionar algoritmos de feedback dinâmico para determinar quando é apropriado atribuir mais recursos ao agendador e quando tirar recursos. Os valores fornecidos pelo agendador podem ser otimistas e não necessariamente têm que refletir a contagem atual com precisão.

Você deve implementar esse método se quiser que o Gerenciador de recursos use feedback sobre coisas como chegada de tarefas para determinar como equilibrar recursos entre seu agendador e outros agendadores registrados no Gerenciador de Recursos. Se você optar por não reunir estatísticas, `DynamicProgressFeedback` você `DynamicProgressFeedbackDisabled` pode definir a chave de política para o valor na política do seu agendador, e o Gerenciador de recursos não invocará esse método no seu agendador.

Na ausência de informações estatísticas, o Resource Manager usará os níveis de assinatura do segmento de hardware para tomar decisões de alocação de recursos e migração. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource::CurrentSubscriptionLevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)<br/>
[PolicyElementKey](concurrency-namespace-enums.md)<br/>
[Classe SchedulerPolicy](schedulerpolicy-class.md)<br/>
[Estrutura IExecutionContext](iexecutioncontext-structure.md)<br/>
[Estrutura IThreadProxy](ithreadproxy-structure.md)<br/>
[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)<br/>
[Estrutura IResourceManager](iresourcemanager-structure.md)
