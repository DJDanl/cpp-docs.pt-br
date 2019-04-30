---
title: 'Como: Criar uma tarefa que termine após um atraso'
ms.date: 11/04/2016
helpviewer_keywords:
- task_completion_event class, example
- create a task that completes after a delay, example [C++]
ms.assetid: 3fc0a194-3fdb-4eba-8b8a-b890981a985d
ms.openlocfilehash: 3292043d7900d5dc2bfba0afa5fdc237853a5be0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62413899"
---
# <a name="how-to-create-a-task-that-completes-after-a-delay"></a>Como: Criar uma tarefa que termine após um atraso

Este exemplo mostra como usar o [Concurrency:: Task](../../parallel/concrt/reference/task-class.md), [Concurrency:: cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md), [cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md), [ Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md), [concurrency::timer](../../parallel/concrt/reference/timer-class.md), e [concurrency::call](../../parallel/concrt/reference/call-class.md) classes para criar uma tarefa que termine após um atraso. Você pode usar esse método para compilar os loop que ocasionalmente sondar dados, introduzem tempos limite, atrasar a manipulação de entrada do usuário por um período pré-determinado e assim por diante.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra as funções `complete_after` e `cancel_after_timeout`. O `complete_after` função cria um `task` objeto que é concluída após o atraso especificado. Ele usa um `timer` objeto e uma `call` objeto para definir um `task_completion_event` objeto após o atraso especificado. Usando o `task_completion_event` classe, você pode definir uma tarefa que termine após um thread ou outra tarefa sinaliza que um valor está disponível. Quando o evento é definido, tarefas de ouvinte completam e suas continuações são agendadas para execução.

> [!TIP]
>  Para obter mais informações sobre o `timer` e `call` classes, que são parte da biblioteca de agentes assíncronos, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

O `cancel_after_timeout` função se baseia o `complete_after` função para cancelar uma tarefa se essa tarefa não for concluída antes do tempo limite determinado. O `cancel_after_timeout` função cria duas tarefas. A primeira tarefa indica êxito e que termine após a conclusão da tarefa fornecida; a segunda tarefa indica falha e é concluída após o tempo limite especificado. O `cancel_after_timeout` função cria uma tarefa de continuação que é executado quando a tarefa de êxito ou falha é concluída. Se a tarefa falha for concluída primeiro, a continuação cancela a origem do token para cancelar a tarefa geral.

[!code-cpp[concrt-task-delay#1](../../parallel/concrt/codesnippet/cpp/how-to-create-a-task-that-completes-after-a-delay_1.cpp)]

## <a name="example"></a>Exemplo

O exemplo a seguir calcula a contagem de números primos no intervalo [0, 100000] várias vezes. A operação falhará se ela não for concluída em um limite de tempo determinado. O `count_primes` função demonstra como usar o `cancel_after_timeout` função. Ele conta o número de números primos em determinado intervalo e falhará se a tarefa não for concluída no tempo fornecido. O `wmain` chamadas de função a `count_primes` função várias vezes. Cada vez, ele reduz pela metade o tempo limite. O programa seja concluído depois que a operação não for concluída no limite de tempo atual.

[!code-cpp[concrt-task-delay#2](../../parallel/concrt/codesnippet/cpp/how-to-create-a-task-that-completes-after-a-delay_2.cpp)]

Quando você usa essa técnica para cancelar as tarefas após um atraso, as tarefas não iniciadas não serão iniciado depois que a tarefa geral será cancelada. No entanto, é importante para as tarefas de longa execução responder ao cancelamento de maneira oportuna. Para obter mais informações sobre o cancelamento de tarefa, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).

## <a name="example"></a>Exemplo

Aqui está o código completo para este exemplo:

[!code-cpp[concrt-task-delay#3](../../parallel/concrt/codesnippet/cpp/how-to-create-a-task-that-completes-after-a-delay_3.cpp)]

## <a name="compiling-the-code"></a>Compilando o código

Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `task-delay.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc task-delay.cpp**

## <a name="see-also"></a>Consulte também

[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Classe task (Tempo de Execução de Simultaneidade)](../../parallel/concrt/reference/task-class.md)<br/>
[Classe cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md)<br/>
[Classe cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md)<br/>
[Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)<br/>
[Classe timer](../../parallel/concrt/reference/timer-class.md)<br/>
[Classe call](../../parallel/concrt/reference/call-class.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)
