---
title: "Ferramentas de diagn&#243;stico em paralelo (Tempo de Execu&#231;&#227;o de Simultaneidade) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Parallel Diagnostic Tools [Tempo de Execução de Simultaneidade]"
ms.assetid: b1a3f1d2-f5df-4f29-852e-906b3d8341fc
caps.latest.revision: 15
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ferramentas de diagn&#243;stico em paralelo (Tempo de Execu&#231;&#227;o de Simultaneidade)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

[!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)] fornece amplo suporte à depuração e analisar aplicativos multi\-threaded.  
  
## Depuração  
 O depurador do Visual Studio inclui a janela de **Pilhas Paralelas** , a janela de **Tarefas Paralelas** , e a janela de **Inspeção Paralela** .  Para obter mais informações, consulte [Instruções passo a passo: depurando um aplicativo paralelo](../Topic/Walkthrough:%20Debugging%20a%20Parallel%20Application.md) e [Como usar a janela Inspeção Paralela](../Topic/How%20to:%20Use%20the%20Parallel%20Watch%20Window.md).  
  
## Criação de Perfil  
 As ferramentas de criação de perfil fornece três exibições de dados que exibem informações gráfico, tabulares e numérica sobre como um aplicativo multi\-threaded interage com se e com outros programas.  As exibições permitem que você identifique rapidamente áreas de intervenção, e para navegar em pontos em exibições gráficas para pilhas de chamadas, a sites da chamada, e no código\-fonte.  Para obter mais informações, consulte [Visualizador de Simultaneidade](../Topic/Concurrency%20Visualizer.md).  
  
## Rastreamento de eventos  
 O tempo de execução de simultaneidade usa [Rastreamento de Eventos do Windows](http://msdn.microsoft.com/library/windows/desktop/bb968803) \(ETW\) para notificar ferramentas de gerenciamento, como perfiladores, quando vários eventos ocorrem.  Esses eventos incluem quando um agendador é ativado ou desativado, quando um contexto começa, termina, o bloqueia, desbloquear, ou continua e, quando um algoritmo paralelo inicia ou termina.  
  
 Ferramentas como [Visualizador de Simultaneidade](../Topic/Concurrency%20Visualizer.md) utilizam essa funcionalidade; em virtude disso, você normalmente não precisa trabalhar com esses eventos diretamente.  No entanto, esses eventos são úteis quando você estiver desenvolvendo um evento personalizado ou quando você usa ferramentas de rastreamento de eventos como [Xperf](http://go.microsoft.com/fwlink/?LinkID=160628).  
  
 O tempo de execução de simultaneidade gerencie esses eventos somente quando o rastreamento é habilitado.  Chame a função de [concurrency::EnableTracing](../Topic/EnableTracing%20Function.md) para habilitar o rastreamento de eventos e a função de [concurrency::DisableTracing](../Topic/DisableTracing%20Function.md) para desabilitar o rastreamento.  
  
 A tabela a seguir descreve os eventos que o tempo de execução aumenta quando o rastreamento de eventos é habilitado:  
  
|Evento|Descrição|Valor|  
|------------|---------------|-----------|  
|[concurrency::ConcRT\_ProviderGuid](../Topic/ConcRT_ProviderGuid%20Constant.md)|O identificador do provedor ETW do tempo de execução de simultaneidade.|`f7b697a3-4db5-4d3b-be71-c4d284e6592f`|  
|[concurrency::ContextEventGuid](../Topic/ContextEventGuid%20Constant.md)|Marca os eventos relacionados aos contextos.|`5727a00f-50be-4519-8256-f7699871fecb`|  
|[concurrency::PPLParallelForEventGuid](../Topic/PPLParallelForEventGuid%20Constant.md)|Marca a entrada e a saída com chamadas para o algoritmo de [concurrency::parallel\_for](../Topic/parallel_for%20Function.md) .|`31c8da6b-6165-4042-8b92-949e315f4d84`|  
|[concurrency::PPLParallelForeachEventGuid](../Topic/PPLParallelForeachEventGuid%20Constant.md)|Marca a entrada e a saída com chamadas para o algoritmo de [concurrency::parallel\_for\_each](../Topic/parallel_for_each%20Function.md) .|`5cb7d785-9d66-465d-bae1-4611061b5434`|  
|[concurrency::PPLParallelInvokeEventGuid](../Topic/PPLParallelInvokeEventGuid%20Constant.md)|Marca a entrada e a saída com chamadas para o algoritmo de [concurrency::parallel\_invoke](../Topic/parallel_invoke%20Function.md) .|`d1b5b133-ec3d-49f4-98a3-464d1a9e4682`|  
|[concurrency::SchedulerEventGuid](../Topic/SchedulerEventGuid%20Constant.md)|Marca os eventos relacionados a [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).|`e2091f8a-1e0a-4731-84a2-0dd57c8a5261`|  
|[concurrency::VirtualProcessorEventGuid](../Topic/VirtualProcessorEventGuid%20Constant.md)|Marca os eventos relacionados aos processadores virtuais.|`2f27805f-1676-4ecc-96fa-7eb09d44302f`|  
  
 O tempo de execução de simultaneidade define, mas não aumenta atualmente, os seguintes eventos.  O tempo de execução reserva esses eventos para uso futuro:  
  
-   [concurrency::ConcRTEventGuid](../Topic/ConcRTEventGuid%20Constant.md)  
  
-   [concurrency::ScheduleGroupEventGuid](../Topic/SchedulerEventGuid%20Constant.md)  
  
-   [concurrency::ChoreEventGuid](../Topic/ChoreEventGuid%20Constant.md)  
  
-   [concurrency::LockEventGuid](../Topic/LockEventGuid%20Constant.md)  
  
-   [concurrency::ResourceManagerEventGuid](../Topic/ResourceManagerEventGuid%20Constant.md)  
  
 A enumeração de [concurrency::ConcRT\_EventType](../Topic/ConcRT_EventType%20Enumeration.md) especifica as operações possíveis que um evento rastreia.  Por exemplo, na entrada do algoritmo de `parallel_for` , o tempo de execução gerencie o evento de `PPLParallelForEventGuid` e fornece `CONCRT_EVENT_START` como a operação.  Antes do algoritmo de `parallel_for` retorna, o tempo de execução novamente gerencie o evento de `PPLParallelForEventGuid` e fornece `CONCRT_EVENT_END` como a operação.  
  
 O exemplo a seguir ilustra como habilitar o rastreamento para uma chamada a `parallel_for`.  O tempo de execução não rastreia a primeira chamada a `parallel_for` porque o rastreamento não habilitado.  A chamada para `EnableTracing` permite que o tempo de execução para rastrear o segundo chamada para `parallel_for`.  
  
 [!code-cpp[concrt-etw#1](../../parallel/concrt/codesnippet/CPP/parallel-diagnostic-tools-concurrency-runtime_1.cpp)]  
  
 O tempo de execução controla o número de vezes que você chama `EnableTracing` e `DisableTracing`.  Em virtude disso, se você chamar `EnableTracing` várias vezes, você deve chamar `DisableTracing` o mesmo número de vezes para desabilitar o rastreamento.  
  
## Consulte também  
 [Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)