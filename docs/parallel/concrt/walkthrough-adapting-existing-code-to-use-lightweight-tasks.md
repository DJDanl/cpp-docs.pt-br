---
title: 'Instruções passo a passo: adaptando um código existente para usar tarefas leves'
ms.date: 04/25/2019
helpviewer_keywords:
- using lightweight tasks [Concurrency Runtime]
- lightweight tasks, using [Concurrency Runtime]
ms.assetid: 1edfe818-d274-46de-bdd3-e92967c9bbe0
ms.openlocfilehash: e7c6096829a1cd45cfdb849a1899d6b4a2d4cb78
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141989"
---
# <a name="walkthrough-adapting-existing-code-to-use-lightweight-tasks"></a>Instruções passo a passo: adaptando um código existente para usar tarefas leves

Este tópico mostra como adaptar o código existente que usa a API do Windows para criar e executar um thread para usar uma tarefa leve.

Uma *tarefa leve* é uma tarefa que você agenda diretamente de um objeto [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) ou [Concurrency:: Schedule](../../parallel/concrt/reference/schedulegroup-class.md) . Tarefas leves são úteis quando você adapta o código existente para usar a funcionalidade de agendamento do Tempo de Execução de Simultaneidade.

## <a name="prerequisites"></a>{1&gt;{2&gt;Pré-requisitos&lt;2}&lt;1}

Antes de iniciar este passo a passos, leia o tópico [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir ilustra o uso típico da API do Windows para criar e executar um thread. Este exemplo usa a função [CreateThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread) para chamar o `MyThreadFunction` em um thread separado.

### <a name="initial-code"></a>Código inicial

[!code-cpp[concrt-windows-threads#1](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Parameters = 50, 100
```

As etapas a seguir mostram como adaptar o exemplo de código para usar o Tempo de Execução de Simultaneidade para executar a mesma tarefa.

### <a name="to-adapt-the-example-to-use-a-lightweight-task"></a>Para adaptar o exemplo a fim de usar uma tarefa leve

1. Adicione uma diretiva `#include` para o arquivo de cabeçalho ConcRT. h.

[!code-cpp[concrt-migration-lwt#2](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_2.cpp)]

1. Adicione uma diretiva de `using` para o namespace `concurrency`.

[!code-cpp[concrt-migration-lwt#3](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_3.cpp)]

1. Altere a declaração de `MyThreadFunction` para usar a Convenção de chamada `__cdecl` e retornar `void`.

[!code-cpp[concrt-migration-lwt#4](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_4.cpp)]

1. Modifique a estrutura de `MyData` para incluir um objeto [Concurrency:: Event](../../parallel/concrt/reference/event-class.md) que sinaliza para o aplicativo principal que a tarefa concluiu.

[!code-cpp[concrt-migration-lwt#5](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_5.cpp)]

1. Substitua a chamada para `CreateThread` por uma chamada para o método [Concurrency:: CurrentScheduler:: ScheduleTask](reference/currentscheduler-class.md#scheduletask) .

[!code-cpp[concrt-migration-lwt#6](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_6.cpp)]

1. Substitua a chamada para `WaitForSingleObject` por uma chamada para o método [Concurrency:: evento:: Wait](reference/event-class.md#wait) para aguardar a conclusão da tarefa.

[!code-cpp[concrt-migration-lwt#7](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_7.cpp)]

1. Remova a chamada para `CloseHandle`.

1. Altere a assinatura da definição de `MyThreadFunction` para corresponder à etapa 3.

[!code-cpp[concrt-migration-lwt#8](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_8.cpp)]

1. No final da função `MyThreadFunction`, chame o método [Concurrency:: Event:: Set](reference/event-class.md#set) para sinalizar para o aplicativo principal que a tarefa concluiu.

[!code-cpp[concrt-migration-lwt#9](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_9.cpp)]

1. Remova a instrução `return` da `MyThreadFunction`.

### <a name="completed-code"></a>Código concluído

O exemplo a seguir completo mostra o código que usa uma tarefa leve para chamar a função `MyThreadFunction`.

[!code-cpp[concrt-migration-lwt#1](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_10.cpp)]

## <a name="see-also"></a>Consulte também

[Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Classe Scheduler](../../parallel/concrt/reference/scheduler-class.md)
