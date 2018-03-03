---
title: "Paralelo ferramentas de diagnóstico (tempo de execução de simultaneidade) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Parallel Diagnostic Tools [Concurrency Runtime]
ms.assetid: b1a3f1d2-f5df-4f29-852e-906b3d8341fc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1a7c6aa769faaacd128bb51a422227230fa4a851
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="parallel-diagnostic-tools-concurrency-runtime"></a>Ferramentas de diagnóstico em paralelo (Tempo de Execução de Simultaneidade)
[!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)]fornece amplo suporte para depuração e criação de perfil de aplicativos multithread.  
  
## <a name="debugging"></a>Depuração  
 O depurador do Visual Studio inclui a **pilhas paralelas** janela, **tarefas paralelas** janela, e **inspeção paralela** janela. Para obter mais informações, consulte [passo a passo: depurando um aplicativo paralelo](/visualstudio/debugger/walkthrough-debugging-a-parallel-application) e [como: usar a janela Inspeção paralela](/visualstudio/debugger/how-to-use-the-parallel-watch-window).  
  
## <a name="profiling"></a>Criação de perfil  
 As ferramentas de criação de perfil fornecem três modos de exibição de dados que exibem informações gráficas e tabulares numéricas sobre como um aplicativo multithread interage com ele mesmo e com outros programas. Os modos de exibição permitem identificar rapidamente as áreas de interesse e navegar de pontos no gráfico exibe chamar pilhas, chamar o código-fonte e sites. Para obter mais informações, consulte [Visualizador de simultaneidade](/visualstudio/profiling/concurrency-visualizer).  
  
## <a name="event-tracing"></a>Rastreamento de eventos  
 O tempo de execução de simultaneidade usa [de rastreamento de eventos do Windows](http://msdn.microsoft.com/library/windows/desktop/bb968803) (ETW) para notificar as ferramentas de instrumentação, como criadores de perfil, quando vários eventos ocorrem. Esses eventos incluem quando um agendador está ativado ou desativado, quando um contexto começa, termina, bloquear, desbloqueia ou gera e quando um algoritmo paralelo começa ou termina.  
  
 Ferramentas como o [Visualizador de simultaneidade](/visualstudio/profiling/concurrency-visualizer) utilizar esta funcionalidade; portanto, você normalmente não precisa trabalhar diretamente com esses eventos. No entanto, esses eventos são úteis quando você estiver desenvolvendo um criador de perfil personalizado ou quando você usar ferramentas de rastreamento de eventos, como [Xperf](http://go.microsoft.com/fwlink/p/?linkid=160628).  
  
 O tempo de execução de simultaneidade gera estes eventos somente quando o rastreamento está habilitado. Chamar o [concurrency::EnableTracing](reference/concurrency-namespace-functions.md#enabletracing) função para habilitar o rastreamento de eventos e o [concurrency::DisableTracing](reference/concurrency-namespace-functions.md#disabletracing) função para desabilitar o rastreamento.  
  
 A tabela a seguir descreve os eventos que o tempo de execução aumenta quando o evento de rastreamento está habilitado:  
  
|evento|Descrição|Valor|  
|-----------|-----------------|-----------|  

|[Concurrency::ConcRT_ProviderGuid](reference/concurrency-namespace-constants1.md#concrt_providerguid)| O identificador do provedor de ETW para o tempo de execução de simultaneidade. |`f7b697a3-4db5-4d3b-be71-c4d284e6592f`|  
|[Concurrency::ContextEventGuid](reference/concurrency-namespace-constants1.md#contexteventguid)| Eventos relacionados para contextos de marca. |`5727a00f-50be-4519-8256-f7699871fecb`|  
|[Concurrency::PPLParallelForEventGuid](reference/concurrency-namespace-constants1.md#pplparallelforeventguid)| Marca de entrada e saída em chamadas para o [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo. |`31c8da6b-6165-4042-8b92-949e315f4d84`|  
|[Concurrency::PPLParallelForeachEventGuid](reference/concurrency-namespace-constants1.md#pplparallelforeacheventguid)| Marca de entrada e saída em chamadas para o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo. |`5cb7d785-9d66-465d-bae1-4611061b5434`|  
|[Concurrency::PPLParallelInvokeEventGuid](reference/concurrency-namespace-constants1.md#pplparallelinvokeeventguid)| Marca de entrada e saída em chamadas para o [concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo. |`d1b5b133-ec3d-49f4-98a3-464d1a9e4682`|  
|[Concurrency::SchedulerEventGuid](reference/concurrency-namespace-constants1.md#schedulereventguid)| Marca eventos relacionados para o [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md). |`e2091f8a-1e0a-4731-84a2-0dd57c8a5261`|  
|[Concurrency::VirtualProcessorEventGuid](reference/concurrency-namespace-constants1.md#virtualprocessoreventguid)| Marca eventos relacionados para processadores virtuais. |`2f27805f-1676-4ecc-96fa-7eb09d44302f`|  
  
 O tempo de execução de simultaneidade define, mas não no momento aumenta, os eventos a seguir. O tempo de execução reserva esses eventos para uso futuro:  
  
-   [Concurrency::ConcRTEventGuid](reference/concurrency-namespace-constants1.md#concrteventguid)  
  
-   [Concurrency::ScheduleGroupEventGuid](reference/concurrency-namespace-constants1.md#schedulereventguid)  
  
-   [Concurrency::ChoreEventGuid](reference/concurrency-namespace-constants1.md#choreeventguid)  
  
-   [Concurrency::LockEventGuid](reference/concurrency-namespace-constants1.md#lockeventguid)  
  
-   [Concurrency::ResourceManagerEventGuid](reference/concurrency-namespace-constants1.md#resourcemanagereventguid)  
  
 O [concurrency::ConcRT_EventType](reference/concurrency-namespace-enums.md#concrt_eventtype) enumeração Especifica as possíveis operações que controla um evento. Por exemplo, na entrada do `parallel_for` algoritmo, o tempo de execução gera o `PPLParallelForEventGuid` eventos e fornece `CONCRT_EVENT_START` como a operação. Antes do `parallel_for` algoritmo retorna, o tempo de execução gera novamente o `PPLParallelForEventGuid` eventos e fornece `CONCRT_EVENT_END` como a operação.  
  
 O exemplo a seguir ilustra como habilitar o rastreamento para uma chamada para `parallel_for`. O tempo de execução não rastrear a primeira chamada para `parallel_for` porque o rastreamento não está habilitado. A chamada para `EnableTracing` permite que o tempo de execução rastrear a segunda chamada para `parallel_for`.  
  
 [!code-cpp[concrt-etw#1](../../parallel/concrt/codesnippet/cpp/parallel-diagnostic-tools-concurrency-runtime_1.cpp)]  
  
 O tempo de execução rastreia o número de vezes que você chamar `EnableTracing` e `DisableTracing`. Portanto, se você chamar `EnableTracing` várias vezes, você deve chamar `DisableTracing` o mesmo número de vezes para desabilitar o rastreamento.  
  
## <a name="see-also"></a>Consulte também  
 [Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)

