---
title: 'Como: criar uma tarefa que seja concluída após um atraso'
description: Crie uma tarefa que seja concluída após um atraso usando a biblioteca ConcRT da PPL.
ms.date: 10/19/2020
helpviewer_keywords:
- task_completion_event class, example
- create a task that completes after a delay, example [C++]
ms.assetid: 3fc0a194-3fdb-4eba-8b8a-b890981a985d
ms.openlocfilehash: 694b6190a7ec60043a5674e920dc54e6e7bf0eb6
ms.sourcegitcommit: 19016630f9d35f365e9ba249e0f3617515d7ca33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/20/2020
ms.locfileid: "92274564"
---
# <a name="how-to-create-a-task-that-completes-after-a-delay"></a>Como: criar uma tarefa que seja concluída após um atraso

Este exemplo mostra como usar as classes,,,, [`concurrency::task`](../../parallel/concrt/reference/task-class.md) [`concurrency::cancellation_token_source`](../../parallel/concrt/reference/cancellation-token-source-class.md) [`concurrency::cancellation_token`](../../parallel/concrt/reference/cancellation-token-class.md) [`concurrency::task_completion_event`](../../parallel/concrt/reference/task-completion-event-class.md) [`concurrency::timer`](../../parallel/concrt/reference/timer-class.md) e [`concurrency::call`](../../parallel/concrt/reference/call-class.md) para criar uma tarefa que é concluída após um atraso. Você pode usar esse método para criar loops que ocasionalmente sondam dados. Você também pode introduzir tempos limite, atrasar a manipulação de entrada do usuário para um tempo predeterminado e assim por diante.

## <a name="example-complete_after-and-cancel_after_timeout-functions"></a>Exemplo: funções complete_after e cancel_after_timeout

O exemplo a seguir mostra as funções `complete_after` e `cancel_after_timeout`. A `complete_after` função cria um `task` objeto que é concluído após o atraso especificado. Ele usa um objeto `timer` e um `call` objeto para definir um `task_completion_event` objeto após o atraso especificado. Usando a `task_completion_event` classe, você pode definir uma tarefa que é concluída depois que um thread ou outra tarefa sinaliza que um valor está disponível. Quando o evento é definido, as tarefas do ouvinte são concluídas e suas continuaçãos são agendadas para execução.

> [!TIP]
> Para obter mais informações sobre `timer` as `call` classes e, que fazem parte da biblioteca de agentes assíncronos, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

A `cancel_after_timeout` função se baseia na `complete_after` função para cancelar uma tarefa se essa tarefa não for concluída antes de um tempo limite determinado. A `cancel_after_timeout` função cria duas tarefas. A primeira tarefa indica êxito e é concluída após a conclusão da tarefa fornecida. A segunda tarefa indica falha e é concluída após o tempo limite especificado. A `cancel_after_timeout` função cria uma tarefa de continuação que é executada quando a tarefa de êxito ou falha é concluída. Se a tarefa de falha for concluída primeiro, a continuação cancelará a origem do token para cancelar a tarefa geral.

[!code-cpp[concrt-task-delay#1](../../parallel/concrt/codesnippet/cpp/how-to-create-a-task-that-completes-after-a-delay_1.cpp)]

## <a name="example-compute-count-of-prime-numbers"></a>Exemplo: contagem de computação de números primos

O exemplo a seguir computa a contagem de números primos no intervalo [0, 100000] várias vezes. A operação falhará se não for concluída em um determinado limite de tempo. A `count_primes` função demonstra como usar a `cancel_after_timeout` função. Ele conta o número de primos no intervalo especificado e falhará se a tarefa não for concluída no tempo fornecido. A `wmain` função chama a `count_primes` função várias vezes. A cada hora, ela reduz o limite de tempo. O programa é concluído depois que a operação não é concluída no limite de tempo atual.

[!code-cpp[concrt-task-delay#2](../../parallel/concrt/codesnippet/cpp/how-to-create-a-task-that-completes-after-a-delay_2.cpp)]

Quando você usar essa técnica para cancelar tarefas após um atraso, as tarefas não iniciadas não serão iniciadas depois que a tarefa geral for cancelada. No entanto, é importante que todas as tarefas de execução demorada respondam rapidamente ao cancelamento. Para obter mais informações sobre o cancelamento de tarefa, consulte [cancelamento na ppl](cancellation-in-the-ppl.md).

## <a name="complete-code-example"></a>Exemplo de código completo

Este é o código completo deste exemplo:

[!code-cpp[concrt-task-delay#3](../../parallel/concrt/codesnippet/cpp/how-to-create-a-task-that-completes-after-a-delay_3.cpp)]

## <a name="compiling-the-code"></a>Compilando o código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `task-delay.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

**cl.exe/EHsc Task-delay. cpp**

## <a name="see-also"></a>Confira também

[Paralelismo de Tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Classe Task (Tempo de Execução de Simultaneidade)](../../parallel/concrt/reference/task-class.md)<br/>
[Classe cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md)<br/>
[Classe cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md)<br/>
[Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)<br/>
[Classe Timer](../../parallel/concrt/reference/timer-class.md)<br/>
[Classe Call](../../parallel/concrt/reference/call-class.md)<br/>
[Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)
