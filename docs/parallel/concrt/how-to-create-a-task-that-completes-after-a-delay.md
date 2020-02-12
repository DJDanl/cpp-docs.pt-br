---
title: Como criar uma tarefa que seja concluída após um atraso
ms.date: 11/04/2016
helpviewer_keywords:
- task_completion_event class, example
- create a task that completes after a delay, example [C++]
ms.assetid: 3fc0a194-3fdb-4eba-8b8a-b890981a985d
ms.openlocfilehash: 76189f45eb486e06b040155f6697bf003659b474
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141752"
---
# <a name="how-to-create-a-task-that-completes-after-a-delay"></a>Como criar uma tarefa que seja concluída após um atraso

Este exemplo mostra como usar as classes [Concurrency:: Task](../../parallel/concrt/reference/task-class.md), [simultane:: cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md), [Concurrency:: cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md), [simultane:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md), [Concurrency:: timer](../../parallel/concrt/reference/timer-class.md)e [Concurrency:: Call](../../parallel/concrt/reference/call-class.md) para criar uma tarefa concluída após um atraso. Você pode usar esse método para criar loops que ocasionalmente pesquisam dados, introduzir tempos limite, atrasar a manipulação de entrada do usuário para um tempo predeterminado e assim por diante.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra as funções `complete_after` e `cancel_after_timeout`. A função `complete_after` cria um objeto `task` que é concluído após o atraso especificado. Ele usa um objeto `timer` e um objeto `call` para definir um objeto `task_completion_event` após o atraso especificado. Usando a classe `task_completion_event`, você pode definir uma tarefa que é concluída depois que um thread ou outra tarefa sinaliza que um valor está disponível. Quando o evento é definido, as tarefas do ouvinte são concluídas e suas continuaçãos são agendadas para execução.

> [!TIP]
> Para obter mais informações sobre as classes `timer` e `call`, que fazem parte da biblioteca de agentes assíncronos, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

A função `cancel_after_timeout` se baseia na função `complete_after` para cancelar uma tarefa se essa tarefa não for concluída antes de um tempo limite determinado. A função `cancel_after_timeout` cria duas tarefas. A primeira tarefa indica êxito e é concluída após a conclusão da tarefa fornecida; a segunda tarefa indica falha e é concluída após o tempo limite especificado. A função `cancel_after_timeout` cria uma tarefa de continuação que é executada quando a tarefa de êxito ou falha é concluída. Se a tarefa de falha for concluída primeiro, a continuação cancelará a origem do token para cancelar a tarefa geral.

[!code-cpp[concrt-task-delay#1](../../parallel/concrt/codesnippet/cpp/how-to-create-a-task-that-completes-after-a-delay_1.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir computa a contagem de números primos no intervalo [0, 100000] várias vezes. A operação falhará se não for concluída em um determinado limite de tempo. A função `count_primes` demonstra como usar a função `cancel_after_timeout`. Ele conta o número de primos no intervalo especificado e falhará se a tarefa não for concluída no tempo fornecido. A função `wmain` chama a função `count_primes` várias vezes. A cada hora, ela reduz o limite de tempo. O programa é concluído depois que a operação não é concluída no limite de tempo atual.

[!code-cpp[concrt-task-delay#2](../../parallel/concrt/codesnippet/cpp/how-to-create-a-task-that-completes-after-a-delay_2.cpp)]

Quando você usar essa técnica para cancelar tarefas após um atraso, as tarefas não iniciadas não serão iniciadas depois que a tarefa geral for cancelada. No entanto, é importante que todas as tarefas demoradas respondam ao cancelamento em tempo hábil. Para obter mais informações sobre o cancelamento de tarefa, consulte [cancelamento na ppl](cancellation-in-the-ppl.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Este é o código completo deste exemplo:

[!code-cpp[concrt-task-delay#3](../../parallel/concrt/codesnippet/cpp/how-to-create-a-task-that-completes-after-a-delay_3.cpp)]

## <a name="compiling-the-code"></a>Compilando o Código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `task-delay.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

**CL. exe/EHsc Task-delay. cpp**

## <a name="see-also"></a>Consulte também

[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Classe task (Runtime de Simultaneidade)](../../parallel/concrt/reference/task-class.md)<br/>
[Classe cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md)<br/>
[Classe cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md)<br/>
[Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)<br/>
[Classe timer](../../parallel/concrt/reference/timer-class.md)<br/>
[Classe call](../../parallel/concrt/reference/call-class.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)
