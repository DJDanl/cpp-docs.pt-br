---
title: Como usar grupos de agendas para influenciar a ordem de execução
ms.date: 11/04/2016
helpviewer_keywords:
- schedule groups, using [Concurrency Runtime]
- using schedule groups [Concurrency Runtime]
ms.assetid: 73124194-fc3a-491e-a23f-fbd7b5a4455c
ms.openlocfilehash: 84829664603999893f32caab39af250059bf9788
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141913"
---
# <a name="how-to-use-schedule-groups-to-influence-order-of-execution"></a>Como usar grupos de agendas para influenciar a ordem de execução

No Tempo de Execução de Simultaneidade, a ordem na qual as tarefas são agendadas é não determinística. No entanto, você pode usar políticas de agendamento para influenciar a ordem em que as tarefas são executadas. Este tópico mostra como usar grupos de agenda junto com a política de Agendador [Concurrency:: SchedulingProtocol](reference/concurrency-namespace-enums.md#policyelementkey) para influenciar a ordem em que as tarefas são executadas.

O exemplo executa um conjunto de tarefas duas vezes, cada uma com uma política de agendamento diferente. Ambas as políticas limitam o número máximo de recursos de processamento a dois. A primeira execução usa a política de `EnhanceScheduleGroupLocality`, que é o padrão, e a segunda execução usa a política de `EnhanceForwardProgress`. Na política de `EnhanceScheduleGroupLocality`, o Agendador executa todas as tarefas em um grupo de agendamento até que cada tarefa seja concluída ou resulte. Na política de `EnhanceForwardProgress`, o Agendador passa para o próximo grupo de agendas de uma maneira Round-Robin depois que apenas uma tarefa é concluída ou produz.

Quando cada grupo de agendas contém tarefas relacionadas, a política de `EnhanceScheduleGroupLocality` normalmente resulta em um desempenho aprimorado porque a localidade do cache é preservada entre as tarefas. A política de `EnhanceForwardProgress` permite que as tarefas façam o progresso e seja útil quando você precisa de atividades de agendamento em grupos de agendamento.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Este exemplo define a classe `work_yield_agent`, que deriva de [Concurrency:: Agent](../../parallel/concrt/reference/agent-class.md). A classe `work_yield_agent` executa uma unidade de trabalho, produz o contexto atual e, em seguida, executa outra unidade de trabalho. O agente usa a função [Concurrency:: Wait](reference/concurrency-namespace-functions.md#wait) para produzir o contexto atual de forma cooperativa para que outros contextos possam ser executados.

Este exemplo cria quatro objetos `work_yield_agent`. Para ilustrar como definir as políticas do Agendador para afetar a ordem em que os agentes são executados, o exemplo associa os dois primeiros agentes com um grupo de agendamento e os outros dois, com outro grupo de agendamento. O exemplo usa o método [Concurrency:: CurrentScheduler:: CreateSchedule](reference/currentscheduler-class.md#createschedulegroup) para criar os objetos [Concurrency:: Schedule](../../parallel/concrt/reference/schedulegroup-class.md) . O exemplo executa todos os quatro agentes duas vezes, cada vez com uma política de agendamento diferente.

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

Ambas as políticas produzem a mesma sequência de eventos. No entanto, a política que usa `EnhanceScheduleGroupLocality` inicia os dois agentes que fazem parte do primeiro grupo de agenda antes de iniciar os agentes que fazem parte do segundo grupo. A política que usa `EnhanceForwardProgress` inicia um agente do primeiro grupo e, em seguida, inicia o primeiro agente no segundo grupo.

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `scheduling-protocol.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Scheduling-Protocol. cpp**

## <a name="see-also"></a>Consulte também

[Grupos Agendados](../../parallel/concrt/schedule-groups.md)<br/>
[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)
