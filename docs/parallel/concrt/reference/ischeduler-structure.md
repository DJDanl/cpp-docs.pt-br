---
title: Estrutura IScheduler | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- IScheduler structure
ms.assetid: 471de85a-2b1a-4b6d-ab81-2eff2737161e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4c926589165cbf93bd517612514bc27c88f28e15
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46378859"
---
# <a name="ischeduler-structure"></a>Estrutura IScheduler

Uma interface para uma abstração de um agendador de trabalho. Gerenciador de recursos do tempo de execução de simultaneidade usa essa interface para se comunicar com os agendadores de trabalho.

## <a name="syntax"></a>Sintaxe

```
struct IScheduler;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IScheduler::AddVirtualProcessors](#addvirtualprocessors)|Fornece um agendador com um conjunto de raízes de processador virtual para seu uso. Cada `IVirtualProcessorRoot` interface representa o direito de executar um thread único que pode executar o trabalho em nome do Agendador.|
|[IScheduler::GetId](#getid)|Retorna um identificador exclusivo para o Agendador.|
|[IScheduler::GetPolicy](#getpolicy)|Retorna uma cópia da política do Agendador. Para obter mais informações sobre políticas de Agendador, consulte [SchedulerPolicy](schedulerpolicy-class.md).|
|[IScheduler::NotifyResourcesExternallyBusy](#notifyresourcesexternallybusy)|Notifica este agendador que os threads de hardware são representados pelo conjunto de raízes de processador virtual na matriz `ppVirtualProcessorRoots` agora estão sendo usados por outros agendadores.|
|[IScheduler::NotifyResourcesExternallyIdle](#notifyresourcesexternallyidle)|Notifica este agendador que os threads de hardware são representados pelo conjunto de raízes de processador virtual na matriz `ppVirtualProcessorRoots` não estão sendo usados por outros agendadores.|
|[IScheduler::RemoveVirtualProcessors](#removevirtualprocessors)|Inicia a remoção de raízes de processador virtual que foram alocados anteriormente a este agendador.|
|[Ischeduler:: statistics](#statistics)|Fornece informações relacionadas às taxas de chegada e a conclusão da tarefa e a alteração no tamanho da fila para um agendador.|

## <a name="remarks"></a>Comentários

Se você estiver implementando um agendador personalizado que se comunica com o Gerenciador de recursos, você deve fornecer uma implementação do `IScheduler` interface. Essa interface é uma extremidade de um canal bidirecional de comunicação entre um agendador e o Gerenciador de recursos. A outra extremidade é representada pela `IResourceManager` e `ISchedulerProxy` interfaces que são implementadas pelo Gerenciador de recursos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IScheduler`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

##  <a name="addvirtualprocessors"></a>  Método ischeduler:: Addvirtualprocessors

Fornece um agendador com um conjunto de raízes de processador virtual para seu uso. Cada `IVirtualProcessorRoot` interface representa o direito de executar um thread único que pode executar o trabalho em nome do Agendador.

```
virtual void AddVirtualProcessors(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```

### <a name="parameters"></a>Parâmetros

*ppVirtualProcessorRoots*<br/>
Uma matriz de `IVirtualProcessorRoot` raízes de interfaces que representa o processador virtual que está sendo adicionado ao Agendador.

*count*<br/>
O número de `IVirtualProcessorRoot` interfaces na matriz.

### <a name="remarks"></a>Comentários

O Gerenciador de recursos invoca o `AddVirtualProcessor` método conceder um conjunto inicial de raízes de processador virtual para um agendador. Ele também pode invocar o método para adicionar as raízes de processador virtual para o Agendador quando reequilibrar recursos entre os agendadores.

##  <a name="getid"></a>  Método ischeduler:: GetID

Retorna um identificador exclusivo para o Agendador.

```
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor de retorno

Um identificador inteiro exclusivo.

### <a name="remarks"></a>Comentários

Você deve usar o [GetSchedulerId](concurrency-namespace-functions.md) função para obter um identificador exclusivo para o objeto que implementa o `IScheduler` interface, antes de usar a interface como um parâmetro para métodos fornecidos pelo Gerenciador de recursos. Você deve retornar o mesmo identificador quando o `GetId` função é invocada.

Um identificador obtido de uma fonte diferente poderá resultar em comportamento indefinido.

##  <a name="getpolicy"></a>  Método ischeduler:: Getpolicy

Retorna uma cópia da política do Agendador. Para obter mais informações sobre políticas de Agendador, consulte [SchedulerPolicy](schedulerpolicy-class.md).

```
virtual SchedulerPolicy GetPolicy() const = 0;
```

### <a name="return-value"></a>Valor de retorno

Uma cópia da política do Agendador.

##  <a name="notifyresourcesexternallybusy"></a>  Método ischeduler:: Notifyresourcesexternallybusy

Notifica este agendador que os threads de hardware são representados pelo conjunto de raízes de processador virtual na matriz `ppVirtualProcessorRoots` agora estão sendo usados por outros agendadores.

```
virtual void NotifyResourcesExternallyBusy(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```

### <a name="parameters"></a>Parâmetros

*ppVirtualProcessorRoots*<br/>
Uma matriz de `IVirtualProcessorRoot` interfaces associadas com os threads de hardware no qual outros agendadores têm se tornado ocupados.

*count*<br/>
O número de `IVirtualProcessorRoot` interfaces na matriz.

### <a name="remarks"></a>Comentários

É possível que um thread de hardware específica a ser atribuído para vários agendadores, ao mesmo tempo. Um motivo para isso pode ser que não há threads suficientes hardware do sistema para satisfazer a simultaneidade mínimo para todos os agendadores, sem compartilhamento de recursos. Outra possibilidade é que recursos são atribuídos temporariamente a outros agendadores quando o Agendador de proprietário não está usando, por meio de todas as suas raízes de processador virtual nesse thread de hardware que está sendo desativado.

O nível de assinatura de um thread de hardware é indicado pelo número de segmentos assinados e ativado as raízes de processador virtual associados a esse thread de hardware. Do ponto de vista de um agendador específico, o nível de assinatura externa de um thread de hardware é a parte da assinatura colaborar com outros agendadores. Que recursos estejam ocupados externamente de notificações são enviadas para um agendador quando o nível de assinatura externa para um thread de hardware é movido de zero em território positivo.

As notificações por esse método só são enviadas a agendadores que têm uma política em que o valor para o `MinConcurrency` chave de política é igual ao valor para o `MaxConcurrency` chave de política. Para obter mais informações sobre políticas de Agendador, consulte [SchedulerPolicy](schedulerpolicy-class.md).

Um agendador que qualificam-se para notificações obtém um conjunto de notificações inicias quando ela é criada, informando-o se os recursos que ele recebeu são externamente ocupado ou ocioso.

##  <a name="notifyresourcesexternallyidle"></a>  Método ischeduler:: Notifyresourcesexternallyidle

Notifica este agendador que os threads de hardware são representados pelo conjunto de raízes de processador virtual na matriz `ppVirtualProcessorRoots` não estão sendo usados por outros agendadores.

```
virtual void NotifyResourcesExternallyIdle(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```

### <a name="parameters"></a>Parâmetros

*ppVirtualProcessorRoots*<br/>
Uma matriz de `IVirtualProcessorRoot` interfaces associadas a segmentos de hardware no qual outros agendadores têm se tornado ociosos.

*count*<br/>
O número de `IVirtualProcessorRoot` interfaces na matriz.

### <a name="remarks"></a>Comentários

É possível que um thread de hardware específica a ser atribuído para vários agendadores, ao mesmo tempo. Um motivo para isso pode ser que não há threads suficientes hardware do sistema para satisfazer a simultaneidade mínimo para todos os agendadores, sem compartilhamento de recursos. Outra possibilidade é que recursos são atribuídos temporariamente a outros agendadores quando o Agendador de proprietário não está usando, por meio de todas as suas raízes de processador virtual nesse thread de hardware que está sendo desativado.

O nível de assinatura de um thread de hardware é indicado pelo número de segmentos assinados e ativado as raízes de processador virtual associados a esse thread de hardware. Do ponto de vista de um agendador específico, o nível de assinatura externa de um thread de hardware é a parte da assinatura colaborar com outros agendadores. Que recursos estejam ocupados externamente de notificações são enviadas para um agendador quando o nível de assinatura externa para um thread de hardware cai para zero de um valor positivo anterior.

As notificações por esse método só são enviadas a agendadores que têm uma política em que o valor para o `MinConcurrency` chave de política é igual ao valor para o `MaxConcurrency` chave de política. Para obter mais informações sobre políticas de Agendador, consulte [SchedulerPolicy](schedulerpolicy-class.md).

Um agendador que qualificam-se para notificações obtém um conjunto de notificações inicias quando ela é criada, informando-o se os recursos que ele recebeu são externamente ocupado ou ocioso.

##  <a name="removevirtualprocessors"></a>  Método ischeduler:: Removevirtualprocessors

Inicia a remoção de raízes de processador virtual que foram alocados anteriormente a este agendador.

```
virtual void RemoveVirtualProcessors(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```

### <a name="parameters"></a>Parâmetros

*ppVirtualProcessorRoots*<br/>
Uma matriz de `IVirtualProcessorRoot` interfaces que representa as raízes de processador virtual a ser removido.

*count*<br/>
O número de `IVirtualProcessorRoot` interfaces na matriz.

### <a name="remarks"></a>Comentários

O Gerenciador de recursos invoca o `RemoveVirtualProcessors` método entrem novamente um conjunto de raízes de processador virtual de um agendador. O Agendador é esperado para invocar o [remover](iexecutionresource-structure.md#remove) método em cada interface quando ele é feito com as raízes de processador virtual. Não use uma `IVirtualProcessorRoot` interface depois que você invocou o `Remove` método nele.

O parâmetro `ppVirtualProcessorRoots` aponta para uma matriz de interfaces. Entre o conjunto de raízes de processador virtual a ser removido, as raízes nunca foram ativadas pode ser retornada imediatamente usando o `Remove` método. As raízes que foram ativadas e são ambos a execução do trabalho, ou foram desativadas e estão aguardando o trabalho chegar, devem ser retornadas de forma assíncrona. O Agendador deve fazer cada tentativa de remover a raiz do processador virtual assim que possível. Atrasando a remoção de raízes de processador virtual pode resultar em excesso de assinatura não intencional dentro do Agendador.

##  <a name="statistics"></a>  Método ischeduler:: statistics

Fornece informações relacionadas às taxas de chegada e a conclusão da tarefa e a alteração no tamanho da fila para um agendador.

```
virtual void Statistics(
    _Out_ unsigned int* pTaskCompletionRate,
    _Out_ unsigned int* pTaskArrivalRate,
    _Out_ unsigned int* pNumberOfTasksEnqueued) = 0;
```

### <a name="parameters"></a>Parâmetros

*pTaskCompletionRate*<br/>
O número de tarefas que foram concluídas desde a última chamada para esse método pelo Agendador.

*pTaskArrivalRate*<br/>
O número de tarefas que chegaram no Agendador desde a última chamada para esse método.

*pNumberOfTasksEnqueued*<br/>
O número total de tarefas em todas as filas do Agendador.

### <a name="remarks"></a>Comentários

Esse método é invocado pelo Gerenciador de recursos para coletar estatísticas para um agendador. As estatísticas coletadas aqui serão usadas para orientar os algoritmos de comentário dinâmico para determinar quando é apropriado atribuir mais recursos para o Agendador e quando a tirar recursos. Os valores fornecidos pelo Agendador podem ser otimista e não necessariamente precisam refletir a contagem atual com precisão.

Você deve implementar esse método se você quiser que o Gerenciador de recursos para usar comentários sobre coisas como a chegada de tarefa para determinar como equilibrar recursos entre seu Agendador e outros agendadores registrados com o Gerenciador de recursos. Se você optar por não coletar estatísticas, você pode definir a chave de política `DynamicProgressFeedback` ao valor `DynamicProgressFeedbackDisabled` na política do seu Agendador e o recurso Manager não invocar esse método em seu Agendador.

Na ausência de informações estatísticas, o Gerenciador de recursos usará níveis de assinatura do thread de hardware para tomar decisões de migração e alocação de recursos. Para obter mais informações sobre os níveis de assinatura, consulte [iexecutionresource:: Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[PolicyElementKey](concurrency-namespace-enums.md)<br/>
[Classe SchedulerPolicy](schedulerpolicy-class.md)<br/>
[Estrutura IExecutionContext](iexecutioncontext-structure.md)<br/>
[Estrutura IThreadProxy](ithreadproxy-structure.md)<br/>
[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)<br/>
[Estrutura IResourceManager](iresourcemanager-structure.md)
