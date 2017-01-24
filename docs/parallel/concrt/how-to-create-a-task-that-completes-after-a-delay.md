---
title: "Como criar uma tarefa que seja conclu&#237;da ap&#243;s um atraso | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "classe task_completion_event, por exemplo:"
  - "criar uma tarefa concluída após um atraso, exemplo [C++]"
ms.assetid: 3fc0a194-3fdb-4eba-8b8a-b890981a985d
caps.latest.revision: 9
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como criar uma tarefa que seja conclu&#237;da ap&#243;s um atraso
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este exemplo mostra como usar o [Concurrency:: Task](../../parallel/concrt/reference/task-class-concurrency-runtime.md), [concurrency::cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md), [concurrency::cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md), [concurrency::task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md), "concurrency::timer", e [concurrency::call](../../parallel/concrt/reference/call-class.md) classes para criar uma tarefa seja concluída após um atraso. Você pode usar esse método para construir loops que ocasionalmente sondam dados, introduzem tempos limite, atrasar a manipulação de entrada do usuário por um tempo predeterminado e assim por diante.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra as funções `complete_after` e `cancel_after_timeout`. O `complete_after` função cria um `task` objeto seja concluída após o atraso especificado. Ele usa um `timer` objeto e um `call` objeto para definir um `task_completion_event` objeto após o atraso especificado. Usando o `task_completion_event` classe, você pode definir uma tarefa é concluída depois que um segmento ou outra tarefa indica que um valor está disponível. Quando o evento é definido, concluir tarefas de ouvinte e seus continuações estão agendadas para execução.  
  
> [!TIP]
>  Para obter mais informações sobre o `timer` e `call` classes, que são parte da biblioteca de agentes assíncronos, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).  
  
 O `cancel_after_timeout` função se baseia o `complete_after` função para cancelar uma tarefa se essa tarefa não for concluída antes do tempo limite determinado. O `cancel_after_timeout` função cria duas tarefas. A primeira tarefa indica êxito e é concluída depois de concluir a tarefa de fornecido; a segunda tarefa indica falha e seja concluída após o tempo limite especificado. O `cancel_after_timeout` função cria uma tarefa de continuação que é executado quando a tarefa de êxito ou falha é concluída. Se a tarefa falha for concluída primeiro, a continuação cancela a fonte de token para cancelar a tarefa.  
  
 [!code-cpp[concrt-task-delay#1](../../parallel/concrt/codesnippet/CPP/how-to-create-a-task-that-completes-after-a-delay_1.cpp)]  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir calcula a contagem de números primos no intervalo [0, 100000] várias vezes. A operação falhará se ela não for concluída em um limite de tempo determinado. O `count_primes` função demonstra como usar o `cancel_after_timeout` função. Conta o número de primes em determinado intervalo e falhará se a tarefa não for concluída no tempo fornecido. O `wmain` chamadas de função de `count_primes` função várias vezes. Cada vez, ele metades do limite de tempo. O programa termina depois que a operação não concluída no limite de tempo atual.  
  
 [!code-cpp[concrt-task-delay#2](../../parallel/concrt/codesnippet/CPP/how-to-create-a-task-that-completes-after-a-delay_2.cpp)]  
  
 Quando você usa essa técnica para cancelar tarefas após um atraso, quaisquer tarefas não serão iniciado depois que a tarefa foi cancelada. No entanto, é importante para qualquer tarefa de longa execução responder ao cancelamento de maneira oportuna. Neste exemplo, o `count_primes` chamadas de método de [concurrency::is_task_cancellation_requested](../../misc/is-task-cancellation-requested-function.md) e `cancel_current_task` funções para responder ao cancelamento. (Como alternativa, você pode chamar o [concurrency::interruption_point](../Topic/interruption_point%20Function.md) função). Para obter mais informações sobre o cancelamento da tarefa, consulte [cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md).  
  
## <a name="example"></a>Exemplo  
 Aqui está o código completo para este exemplo:  
  
 [!code-cpp[concrt-task-delay#3](../../parallel/concrt/codesnippet/CPP/how-to-create-a-task-that-completes-after-a-delay_3.cpp)]  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Para compilar o código, copiá-lo e colá-lo em um projeto do Visual Studio ou colá-lo em um arquivo chamado `task-delay.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **tarefa de /EHsc cl.exe-delay.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [tarefa de classe (tempo de execução de simultaneidade)](../../parallel/concrt/reference/task-class-concurrency-runtime.md)   
 [Classe cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md)   
 [Classe cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md)   
 [Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)   
 [Função is_task_cancellation_requested](../../misc/is-task-cancellation-requested-function.md)   
 [Função cancel_current_task](../Topic/cancel_current_task%20Function.md)   
 [Função interruption_point](../Topic/interruption_point%20Function.md)   
 [Classe da chamada](../../parallel/concrt/reference/call-class.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md)