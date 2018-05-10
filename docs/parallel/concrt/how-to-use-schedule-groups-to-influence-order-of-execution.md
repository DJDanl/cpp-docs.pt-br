---
title: 'Como: usar grupos de agendas para influenciar a ordem de execução | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- schedule groups, using [Concurrency Runtime]
- using schedule groups [Concurrency Runtime]
ms.assetid: 73124194-fc3a-491e-a23f-fbd7b5a4455c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c41617f562a0abefdecf74d52e7a886ad6326f9e
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="how-to-use-schedule-groups-to-influence-order-of-execution"></a>Como usar grupos de agendas para influenciar a ordem de execução
No tempo de execução de simultaneidade, a ordem na qual as tarefas são agendadas é não determinística. No entanto, você pode usar políticas de agendamento para influenciar a ordem na qual as tarefas executadas. Este tópico mostra como usar grupos de agendas junto com o [concurrency::SchedulingProtocol](reference/concurrency-namespace-enums.md#policyelementkey) políticas de Agendador para influenciar a ordem na qual as tarefas executadas.  

  
 O exemplo executa um conjunto de tarefas duas vezes, cada um com uma política de agendamento diferente. Ambas as políticas limitam o número máximo de recursos de processamento a dois. A primeira execução usa a `EnhanceScheduleGroupLocality` diretiva, que é o padrão e a segunda execução usa a `EnhanceForwardProgress` política. Sob o `EnhanceScheduleGroupLocality` política, o Agendador é executado todas as tarefas em uma agenda grupo até que cada tarefa seja concluída ou gera. Sob o `EnhanceForwardProgress` política, o Agendador move para o próximo grupo de agendamento de forma round robin depois apenas uma tarefa seja concluída ou gera.  
  
 Quando cada grupo de agenda contém tarefas relacionadas, o `EnhanceScheduleGroupLocality` política normalmente resulta em melhor desempenho, porque a localidade do cache é preservada entre tarefas. O `EnhanceForwardProgress` política permite que tarefas Avançar e é útil quando você precisa de agendamento de igualdade entre grupos de agendas.  
  
## <a name="example"></a>Exemplo  
 Este exemplo define o `work_yield_agent` classe que deriva de [concurrency::agent](../../parallel/concrt/reference/agent-class.md). O `work_yield_agent` classe realiza uma unidade de trabalho, gera o contexto atual e, em seguida, executa outra unidade de trabalho. O agente usa o [concurrency::wait](reference/concurrency-namespace-functions.md#wait) função a forma cooperativa produzir o contexto atual para que podem executar outros contextos.  
  
 Este exemplo cria quatro `work_yield_agent` objetos. Para ilustrar como definir políticas de Agendador para afetar a ordem na qual os agentes são executados, o exemplo associa os primeiros dois agentes com o grupo de uma agenda e os outros dois agentes com outro grupo de agendamento. O exemplo usa o [concurrency::CurrentScheduler::CreateScheduleGroup](reference/currentscheduler-class.md#createschedulegroup) método para criar o [concurrency::ScheduleGroup](../../parallel/concrt/reference/schedulegroup-class.md) objetos. O exemplo executa todos os agentes de quatro duas vezes, cada vez com uma política de agendamento diferente.  
  
 [!code-cpp[concrt-scheduling-protocol#1](../../parallel/concrt/codesnippet/cpp/how-to-use-schedule-groups-to-influence-order-of-execution_1.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
Using EnhanceScheduleGroupLocality...  
group 0,
    task 0: first loop...  
group 0,
    task 1: first loop...  
group 0,
    task 0: waiting...  
group 1,
    task 0: first loop...  
group 0,
    task 1: waiting...  
group 1,
    task 1: first loop...  
group 1,
    task 0: waiting...  
group 0,
    task 0: second loop...  
group 1,
    task 1: waiting...  
group 0,
    task 1: second loop...  
group 0,
    task 0: finished...  
group 1,
    task 0: second loop...  
group 0,
    task 1: finished...  
group 1,
    task 1: second loop...  
group 1,
    task 0: finished...  
group 1,
    task 1: finished...  
 
Using EnhanceForwardProgress...  
group 0,
    task 0: first loop...  
group 1,
    task 0: first loop...  
group 0,
    task 0: waiting...  
group 0,
    task 1: first loop...  
group 1,
    task 0: waiting...  
group 1,
    task 1: first loop...  
group 0,
    task 1: waiting...  
group 0,
    task 0: second loop...  
group 1,
    task 1: waiting...  
group 1,
    task 0: second loop...  
group 0,
    task 0: finished...  
group 0,
    task 1: second loop...  
group 1,
    task 0: finished...  
group 1,
    task 1: second loop...  
group 0,
    task 1: finished...  
group 1,
    task 1: finished...  
```  
  
 Ambas as políticas produzem a mesma sequência de eventos. No entanto, a política que usa `EnhanceScheduleGroupLocality` ambos os agentes que são parte do grupo de agendamento primeiro antes de iniciar os agentes que fazem parte do segundo grupo é iniciado. A política que usa `EnhanceForwardProgress` inicia um agente do primeiro grupo e, em seguida, inicia o primeiro agente no grupo de segundo.  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `scheduling-protocol.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **/EHsc cl.exe agendamento-protocol.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Grupos de agendas](../../parallel/concrt/schedule-groups.md)   
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

