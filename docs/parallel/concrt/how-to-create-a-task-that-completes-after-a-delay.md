---
title: 'Como: criar uma tarefa que seja concluída após um atraso | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- task_completion_event class, example
- create a task that completes after a delay, example [C++]
ms.assetid: 3fc0a194-3fdb-4eba-8b8a-b890981a985d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fca1ba3874f02b44f96fd795b531536a23c8d462
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33688405"
---
# <a name="how-to-create-a-task-that-completes-after-a-delay"></a>Como criar uma tarefa que seja concluída após um atraso
Este exemplo mostra como usar o [Concurrency:: Task](../../parallel/concrt/reference/task-class.md), [Concurrency:: cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md), [Concurrency](../../parallel/concrt/reference/cancellation-token-class.md), [ Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md), [concurrency::timer](../../parallel/concrt/reference/timer-class.md), e [concurrency::call](../../parallel/concrt/reference/call-class.md) classes para criar uma tarefa que seja concluída após um atraso. Você pode usar esse método para criar loops ocasionalmente sondam dados, introduzem tempos limite, atrasar a manipulação de entrada do usuário por um tempo predeterminado, e assim por diante.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra as funções `complete_after` e `cancel_after_timeout`. O `complete_after` função cria uma `task` objeto que seja concluída após o atraso especificado. Ele usa um `timer` objeto e um `call` objeto para definir um `task_completion_event` objeto após o atraso especificado. Usando o `task_completion_event` classe, você pode definir uma tarefa que seja concluída após um thread ou outra tarefa sinaliza que um valor está disponível. Quando o evento é definido, conclua as tarefas de ouvinte e seus continuações estão agendadas para execução.  
  
> [!TIP]
>  Para obter mais informações sobre o `timer` e `call` classes, que são parte da biblioteca de agentes assíncronos, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).  
  
 O `cancel_after_timeout` função se baseia o `complete_after` função para cancelar uma tarefa se essa tarefa não for concluída antes de um tempo limite determinado. O `cancel_after_timeout` função cria duas tarefas. A primeira tarefa indica êxito e completa após a conclusão da tarefa fornecida; a segunda tarefa indica falha e seja concluída após o tempo limite especificado. O `cancel_after_timeout` função cria uma tarefa de continuação que é executado quando concluir a tarefa de êxito ou falha. Se a tarefa falha for concluída primeiro, a continuação cancela a origem do token para cancelar a tarefa.  
  
 [!code-cpp[concrt-task-delay#1](../../parallel/concrt/codesnippet/cpp/how-to-create-a-task-that-completes-after-a-delay_1.cpp)]  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir calcula a contagem de números primos no intervalo [0, 100000] várias vezes. A operação falhará se ela não for concluída em um limite de tempo determinado. O `count_primes` função demonstra como usar o `cancel_after_timeout` função. Ele conta o número de números primos em determinado intervalo e falhará se a tarefa não for concluída no tempo fornecido. O `wmain` chamadas de função de `count_primes` função várias vezes. Cada vez, ele metades do tempo limite. O programa for concluído depois que a operação não é concluída no limite de tempo atual.  
  
 [!code-cpp[concrt-task-delay#2](../../parallel/concrt/codesnippet/cpp/how-to-create-a-task-that-completes-after-a-delay_2.cpp)]  
  
 Quando você usa essa técnica para cancelar tarefas após um atraso, quaisquer tarefas não serão iniciado depois que a tarefa foi cancelada. No entanto, é importante para as tarefas de longa execução responder ao cancelamento de maneira oportuna. Para obter mais informações sobre o cancelamento da tarefa, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).  
  
## <a name="example"></a>Exemplo  
 Aqui está o código completo para este exemplo:  
  
 [!code-cpp[concrt-task-delay#3](../../parallel/concrt/codesnippet/cpp/how-to-create-a-task-that-completes-after-a-delay_3.cpp)]  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `task-delay.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **tarefa de /EHsc cl.exe-delay.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [tarefa de classe (tempo de execução de simultaneidade)](../../parallel/concrt/reference/task-class.md)   
 [Classe cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md)   
 [Classe cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md)   
 [Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)   
 [Classe Timer](../../parallel/concrt/reference/timer-class.md)   
 [Classe da chamada](../../parallel/concrt/reference/call-class.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Cancelamento no PPL](cancellation-in-the-ppl.md)

