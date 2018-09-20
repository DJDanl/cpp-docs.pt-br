---
title: 'Como: usar grupos agendados para influenciar a ordem de execução | Microsoft Docs'
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
ms.openlocfilehash: 55417f1d72d6bd3e111a89f4b28f783543101b6e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46415870"
---
# <a name="how-to-use-schedule-groups-to-influence-order-of-execution"></a>Como usar grupos de agendas para influenciar a ordem de execução

No tempo de execução de simultaneidade, a ordem na qual as tarefas são agendadas é não determinística. No entanto, você pode usar políticas de agendamento para influenciar a ordem na qual as tarefas são executadas. Este tópico mostra como usar grupos de agendamento junto com o [concurrency::SchedulingProtocol](reference/concurrency-namespace-enums.md#policyelementkey) política de Agendador para influenciar a ordem na qual as tarefas são executadas.

O exemplo executa um conjunto de tarefas duas vezes, cada um com uma política de agendamento diferente. Ambas as políticas de limitam o número máximo de recursos de processamento para dois. A primeira execução usa o `EnhanceScheduleGroupLocality` diretiva, que é o padrão e a segunda execução usa o `EnhanceForwardProgress` política. Sob o `EnhanceScheduleGroupLocality` política, o Agendador executa todas as tarefas no grupo de uma agenda até que cada tarefa seja concluída ou produz. Sob o `EnhanceForwardProgress` política, o Agendador move para o próximo grupo de agendamento de forma round-robin depois apenas uma tarefa seja concluída ou produz.

Quando cada grupo de agenda contém tarefas relacionadas, o `EnhanceScheduleGroupLocality` política geralmente resulta em melhor desempenho porque a localidade do cache é preservada entre as tarefas. O `EnhanceForwardProgress` política permite que as tarefas acelerar o andamento e é útil quando você precisar de agendamento honestidade entre grupos de agendamento.

## <a name="example"></a>Exemplo

Este exemplo define o `work_yield_agent` classe, que deriva [concurrency::agent](../../parallel/concrt/reference/agent-class.md). O `work_yield_agent` classe executa uma unidade de trabalho, gera o contexto atual e, em seguida, executa outra unidade de trabalho. O agente usa o [concurrency::wait](reference/concurrency-namespace-functions.md#wait) função para produzir cooperativamente o contexto atual para que podem executar a outros contextos.

Este exemplo cria quatro `work_yield_agent` objetos. Para ilustrar como definir políticas de Agendador para afetar a ordem na qual os agentes são executados, o exemplo associa os primeiros dois agentes com o grupo de uma agenda e dois agentes com outro grupo de agendas. O exemplo usa o [concurrency::CurrentScheduler::CreateScheduleGroup](reference/currentscheduler-class.md#createschedulegroup) método para criar a [Concurrency:: schedulegroup](../../parallel/concrt/reference/schedulegroup-class.md) objetos. O exemplo executa todos os agentes de quatro duas vezes, cada vez com uma política de agendamento diferente.

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

Ambas as políticas produzem a mesma sequência de eventos. No entanto, a política que usa `EnhanceScheduleGroupLocality` inicia os dois agentes que fazem parte do primeiro grupo de agendamento antes de iniciar os agentes que fazem parte do segundo grupo. A política que usa `EnhanceForwardProgress` inicia um agente do primeiro grupo e, em seguida, inicia o primeiro agente no segundo grupo.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `scheduling-protocol.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**/EHsc cl.exe agendamento-protocol.cpp**

## <a name="see-also"></a>Consulte também

[Grupos Agendados](../../parallel/concrt/schedule-groups.md)<br/>
[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

