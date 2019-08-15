---
title: Ferramentas de diagnóstico em paralelo (Tempo de Execução de Simultaneidade)
ms.date: 11/04/2016
helpviewer_keywords:
- Parallel Diagnostic Tools [Concurrency Runtime]
ms.assetid: b1a3f1d2-f5df-4f29-852e-906b3d8341fc
ms.openlocfilehash: 34b2421dfc53deeb35dcc659a8d555983e583737
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69510502"
---
# <a name="parallel-diagnostic-tools-concurrency-runtime"></a>Ferramentas de diagnóstico em paralelo (Tempo de Execução de Simultaneidade)

O Visual Studio fornece amplo suporte para depuração e criação de perfil de aplicativos multi-threaded.

## <a name="debugging"></a>Depuração

O depurador do Visual Studio inclui a janela de **pilhas paralelas** , a janela de **tarefas paralelas** e a janela de **inspeção paralela** . Para obter mais informações, confira [Passo a passo: Depurando um](/visualstudio/debugger/walkthrough-debugging-a-parallel-application) aplicativo [paralelo e como: Use a janela](/visualstudio/debugger/how-to-use-the-parallel-watch-window)de inspeção paralela.

## <a name="profiling"></a>Criação de perfil

As ferramentas de criação de perfil fornecem três exibições de dados que exibem informações gráficas, tabulares e numéricas sobre como um aplicativo multi-threaded interage com ele mesmo e com outros programas. As exibições permitem que você identifique rapidamente áreas de preocupação e navegue de pontos em exibições gráficas para chamadas de pilha, sites de chamada e código-fonte. Para saber mais, confira [Visualização Simultânea](/visualstudio/profiling/concurrency-visualizer).

## <a name="event-tracing"></a>Rastreamento de eventos

O Tempo de Execução de Simultaneidade usa o ETW ( [rastreamento de eventos para Windows](/windows/win32/ETW/event-tracing-portal) ) para notificar ferramentas de instrumentação, como os profileres, quando ocorrem vários eventos. Esses eventos incluem quando um Agendador é ativado ou desativado, quando um contexto começa, termina, bloqueia, desbloqueia ou produz e quando um algoritmo paralelo começa ou termina.

Ferramentas como o [Concurrency Visualizer](/visualstudio/profiling/concurrency-visualizer) utilizam essa funcionalidade; Portanto, normalmente você não precisa trabalhar com esses eventos diretamente. No entanto, esses eventos são úteis quando você está desenvolvendo um criador de perfil personalizado ou quando você usa ferramentas de rastreamento de eventos, como [Xperf](https://go.microsoft.com/fwlink/p/?linkid=160628).

O Tempo de Execução de Simultaneidade gera esses eventos somente quando o rastreamento está habilitado. Chame a função [Concurrency:: EnableTracing](reference/concurrency-namespace-functions.md#enabletracing) para habilitar o rastreamento de eventos e a função [Concurrency::D isabletracing](reference/concurrency-namespace-functions.md#disabletracing) para desabilitar o rastreamento.

A tabela a seguir descreve os eventos que o tempo de execução gera quando o rastreamento de eventos está habilitado:

|evento|Descrição|Valor|
|-----------|-----------------|-----------|
|[concurrency::ConcRT_ProviderGuid](reference/concurrency-namespace-constants1.md#concrt_providerguid)|O identificador do provedor de ETW para o Tempo de Execução de Simultaneidade.|`f7b697a3-4db5-4d3b-be71-c4d284e6592f`|
|[concurrency::ContextEventGuid](reference/concurrency-namespace-constants1.md#contexteventguid)|Marca os eventos relacionados aos contextos.|`5727a00f-50be-4519-8256-f7699871fecb`|
|[concurrency::PPLParallelForEventGuid](reference/concurrency-namespace-constants1.md#pplparallelforeventguid)|Marca a entrada e saída para chamadas para o algoritmo [Concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) .|`31c8da6b-6165-4042-8b92-949e315f4d84`|
|[concurrency::PPLParallelForeachEventGuid](reference/concurrency-namespace-constants1.md#pplparallelforeacheventguid)|Marca a entrada e saída para chamadas para o algoritmo [Concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) .|`5cb7d785-9d66-465d-bae1-4611061b5434`|
|[concurrency::PPLParallelInvokeEventGuid](reference/concurrency-namespace-constants1.md#pplparallelinvokeeventguid)|Marca a entrada e saída para chamadas para o algoritmo [Concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) .|`d1b5b133-ec3d-49f4-98a3-464d1a9e4682`|
|[concurrency::SchedulerEventGuid](reference/concurrency-namespace-constants1.md#schedulereventguid)|Marca os eventos relacionados ao [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).|`e2091f8a-1e0a-4731-84a2-0dd57c8a5261`|
|[concurrency::VirtualProcessorEventGuid](reference/concurrency-namespace-constants1.md#virtualprocessoreventguid)|Marca os eventos relacionados aos processadores virtuais.|`2f27805f-1676-4ecc-96fa-7eb09d44302f`|

O Tempo de Execução de Simultaneidade define, mas não gera, no momento, os eventos a seguir. O tempo de execução reserva esses eventos para uso futuro:

- [simultaneidade:: ConcRTEventGuid](reference/concurrency-namespace-constants1.md#concrteventguid)

- [concurrency::ScheduleGroupEventGuid](reference/concurrency-namespace-constants1.md#schedulereventguid)

- [concurrency::ChoreEventGuid](reference/concurrency-namespace-constants1.md#choreeventguid)

- [concurrency::LockEventGuid](reference/concurrency-namespace-constants1.md#lockeventguid)

- [concurrency::ResourceManagerEventGuid](reference/concurrency-namespace-constants1.md#resourcemanagereventguid)

A enumeração [Concurrency:: ConcRT_EventType](reference/concurrency-namespace-enums.md#concrt_eventtype) especifica as possíveis operações que um evento rastreia. Por exemplo, na entrada do `parallel_for` algoritmo, o tempo de execução gera o `PPLParallelForEventGuid` evento e fornece `CONCRT_EVENT_START` como a operação. Antes de `parallel_for` o algoritmo retornar, o tempo de execução `PPLParallelForEventGuid` gera novamente o `CONCRT_EVENT_END` evento e fornece como a operação.

O exemplo a seguir ilustra como habilitar o rastreamento para uma chamada `parallel_for`para. O tempo de execução não rastreia a primeira chamada `parallel_for` para porque o rastreamento não está habilitado. A chamada para `EnableTracing` permite que o tempo de execução rastreie a segunda `parallel_for`chamada para.

[!code-cpp[concrt-etw#1](../../parallel/concrt/codesnippet/cpp/parallel-diagnostic-tools-concurrency-runtime_1.cpp)]

O tempo de execução acompanha o número de vezes que `EnableTracing` você `DisableTracing`chama e. Portanto, se você chamar `EnableTracing` várias vezes, deverá chamar `DisableTracing` o mesmo número de vezes para desabilitar o rastreamento.

## <a name="see-also"></a>Consulte também

[Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)
