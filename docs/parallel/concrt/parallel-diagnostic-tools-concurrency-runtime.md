---
title: Ferramentas de diagnóstico (tempo de execução de simultaneidade) em paralelo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Parallel Diagnostic Tools [Concurrency Runtime]
ms.assetid: b1a3f1d2-f5df-4f29-852e-906b3d8341fc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bb41f9630e22d9067743b106aed49ea9c51ee4ae
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42538575"
---
# <a name="parallel-diagnostic-tools-concurrency-runtime"></a>Ferramentas de diagnóstico em paralelo (Tempo de Execução de Simultaneidade)
O Visual Studio fornece amplo suporte para depuração e criação de perfil de aplicativos multi-threaded.  
  
## <a name="debugging"></a>Depuração  
 O depurador do Visual Studio inclui o **pilhas paralelas** janela **tarefas paralelas** janela, e **inspeção paralela** janela. Para obter mais informações, consulte [instruções passo a passo: depurando um aplicativo paralelo](/visualstudio/debugger/walkthrough-debugging-a-parallel-application) e [como: usar a janela Inspeção paralela](/visualstudio/debugger/how-to-use-the-parallel-watch-window).  
  
## <a name="profiling"></a>Criação de perfil  
 As ferramentas de criação de perfil fornecem três modos de exibição de dados que exibem informações gráficas, tabulares e numéricas sobre como um aplicativo multithread interage com ele próprio e com outros programas. Os modos de exibição que você possa identificar rapidamente as áreas de preocupação e navegar de pontos em que o gráfico exibe a pilhas de chamadas, chamam o código-fonte e sites. Para saber mais, confira [Visualização Simultânea](/visualstudio/profiling/concurrency-visualizer).  
  
## <a name="event-tracing"></a>Rastreamento de eventos  
 Usa o tempo de execução de simultaneidade [rastreamento de eventos para Windows](http://msdn.microsoft.com/library/windows/desktop/bb968803) (ETW) para notificar as ferramentas de instrumentação, como os criadores de perfil, quando eventos diversos ocorrem. Esses eventos incluem quando um agendador é ativado ou desativado, quando um contexto de inicia, encerra, bloqueia, desbloqueia ou produz, e quando um algoritmo paralelo começa ou termina.  
  
 Ferramentas como o [simultânea](/visualstudio/profiling/concurrency-visualizer) utilizar esta funcionalidade; portanto, geralmente, você precisa trabalhar diretamente com esses eventos. No entanto, esses eventos são úteis quando você estiver desenvolvendo um criador de perfil personalizado ou quando você usa ferramentas de rastreamento de eventos, como [Xperf](http://go.microsoft.com/fwlink/p/?linkid=160628).  
  
 O tempo de execução de simultaneidade gera esses eventos somente quando o rastreamento está habilitado. Chame o [concurrency::EnableTracing](reference/concurrency-namespace-functions.md#enabletracing) função para habilitar o rastreamento de eventos e o [concurrency::DisableTracing](reference/concurrency-namespace-functions.md#disabletracing) função para desabilitar o rastreamento.  
  
 A tabela a seguir descreve os eventos que o tempo de execução gera quando o rastreamento de eventos está habilitado:  
  
|evento|Descrição|Valor|  
|-----------|-----------------|-----------|  

|[Concurrency::ConcRT_ProviderGuid](reference/concurrency-namespace-constants1.md#concrt_providerguid)| O identificador do provedor ETW para o tempo de execução de simultaneidade. |`f7b697a3-4db5-4d3b-be71-c4d284e6592f`|  
|[Concurrency::ContextEventGuid](reference/concurrency-namespace-constants1.md#contexteventguid)| Eventos que estão relacionados aos contextos de marca. |`5727a00f-50be-4519-8256-f7699871fecb`|  
|[Concurrency::PPLParallelForEventGuid](reference/concurrency-namespace-constants1.md#pplparallelforeventguid)| Marca de entrada e saída em chamadas para o [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo. |`31c8da6b-6165-4042-8b92-949e315f4d84`|  
|[Concurrency::PPLParallelForeachEventGuid](reference/concurrency-namespace-constants1.md#pplparallelforeacheventguid)| Marca de entrada e saída em chamadas para o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo. |`5cb7d785-9d66-465d-bae1-4611061b5434`|  
|[Concurrency::PPLParallelInvokeEventGuid](reference/concurrency-namespace-constants1.md#pplparallelinvokeeventguid)| Marca de entrada e saída em chamadas para o [Concurrency:: parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo. |`d1b5b133-ec3d-49f4-98a3-464d1a9e4682`|  
|[Concurrency::SchedulerEventGuid](reference/concurrency-namespace-constants1.md#schedulereventguid)| Marca os eventos relacionados para o [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md). |`e2091f8a-1e0a-4731-84a2-0dd57c8a5261`|  
|[Concurrency::VirtualProcessorEventGuid](reference/concurrency-namespace-constants1.md#virtualprocessoreventguid)| Marca os eventos relacionados a processadores virtuais. |`2f27805f-1676-4ecc-96fa-7eb09d44302f`|  
  
 O tempo de execução de simultaneidade define, mas não no momento aumenta, os eventos a seguir. O tempo de execução reserva esses eventos para uso futuro:  
  
-   [Concurrency::ConcRTEventGuid](reference/concurrency-namespace-constants1.md#concrteventguid)  
  
-   [Concurrency::ScheduleGroupEventGuid](reference/concurrency-namespace-constants1.md#schedulereventguid)  
  
-   [Concurrency::ChoreEventGuid](reference/concurrency-namespace-constants1.md#choreeventguid)  
  
-   [Concurrency::LockEventGuid](reference/concurrency-namespace-constants1.md#lockeventguid)  
  
-   [Concurrency::ResourceManagerEventGuid](reference/concurrency-namespace-constants1.md#resourcemanagereventguid)  
  
 O [concurrency::ConcRT_EventType](reference/concurrency-namespace-enums.md#concrt_eventtype) enumeração Especifica as possíveis operações que rastreia um evento. Por exemplo, na entrada dos `parallel_for` algoritmo, o tempo de execução gera a `PPLParallelForEventGuid` eventos e fornece `CONCRT_EVENT_START` como a operação. Antes do `parallel_for` retorna de algoritmo, o tempo de execução gerará novamente a `PPLParallelForEventGuid` eventos e fornece `CONCRT_EVENT_END` como a operação.  
  
 O exemplo a seguir ilustra como habilitar o rastreamento para uma chamada para `parallel_for`. O tempo de execução não rastreia a primeira chamada para `parallel_for` porque o rastreamento não está habilitado. A chamada para `EnableTracing` permite que o tempo de execução rastrear a segunda chamada para `parallel_for`.  
  
 [!code-cpp[concrt-etw#1](../../parallel/concrt/codesnippet/cpp/parallel-diagnostic-tools-concurrency-runtime_1.cpp)]  
  
 O tempo de execução rastreia o número de vezes que você chame `EnableTracing` e `DisableTracing`. Portanto, se você chamar `EnableTracing` várias vezes, você deve chamar `DisableTracing` o mesmo número de vezes para desabilitar o rastreamento.  
  
## <a name="see-also"></a>Consulte também  
 [Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)

