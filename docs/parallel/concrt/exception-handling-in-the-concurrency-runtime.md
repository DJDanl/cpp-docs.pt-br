---
title: "Tratamento de exceção no tempo de execução de simultaneidade | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- lightweight tasks, exception handling [Concurrency Runtime]
- exception handling [Concurrency Runtime]
- structured task groups, exception handling [Concurrency Runtime]
- agents, exception handling [Concurrency Runtime]
- task groups, exception handling [Concurrency Runtime]
ms.assetid: 4d1494fb-3089-4f4b-8cfb-712aa67d7a7a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 72cde17c0bcb6a3582305167e6358f761c16f248
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exception-handling-in-the-concurrency-runtime"></a>Tratamento de exceções no tempo de execução de simultaneidade
O tempo de execução de simultaneidade usa C++ tratamento de exceções para comunicar-se a vários tipos de erros. Esses erros incluem o uso inválido do tempo de execução, erros de tempo de execução, como Falha ao adquirir um recurso e erros que ocorrem nas funções de trabalho que você fornecer para grupos de tarefas e tarefas. Quando uma tarefa ou um grupo de tarefas gerará uma exceção, o tempo de execução contém essa exceção e empacota o contexto que aguarda a tarefa ou o grupo de tarefas para concluir. Para componentes, como tarefas leves e agentes, o tempo de execução não gerencia exceções para você. Nesses casos, você deve implementar seu próprio mecanismo de tratamento de exceção. Este tópico descreve como o tempo de execução trata exceções lançadas por tarefas, grupos de tarefas, tarefas leves e agentes assíncronos e como responder a exceções em seus aplicativos.  
  
## <a name="key-points"></a>Pontos-chave  
  
-   Quando uma tarefa ou um grupo de tarefas gerará uma exceção, o tempo de execução contém essa exceção e empacota o contexto que aguarda a tarefa ou o grupo de tarefas para concluir.  
  
-   Quando possível, coloque todas as chamadas para [concurrency::task::get](reference/task-class.md#get) e [concurrency::task::wait](reference/task-class.md#wait) com um `try` / `catch` bloco para manipular erros que podem ser recuperados De. O tempo de execução encerra o aplicativo se uma tarefa gera uma exceção e exceções não capturadas pela tarefa, um dos seus continuações ou o aplicativo principal.  
  
-   Uma continuação de tarefas sempre é executado; não importa se a tarefa antecedente concluída com êxito, lançou uma exceção ou foi cancelada. Uma continuação de acordo com o valor não será executado se a tarefa antecedente gera ou cancela.  
  
-   Como sempre executar continuações baseado em tarefa, considere se deseja adicionar uma continuação de tarefas com base no final de sua cadeia de continuação. Isso pode ajudar a garantir que seu código observa todas as exceções.  
  
-   O tempo de execução gera [concurrency::task_canceled](../../parallel/concrt/reference/task-canceled-class.md) quando você chama [concurrency::task::get](reference/task-class.md#get) e essa tarefa é cancelada.  

  
-   O tempo de execução não gerencia exceções para tarefas leves e agentes.  
  
##  <a name="top"></a>Neste documento  
  
- [Tarefas e continuações](#tasks)  
  
- [Grupos de tarefas e os algoritmos paralelos](#task_groups)  
  
- [Exceções geradas pelo tempo de execução](#runtime)  
  
- [Várias exceções](#multiple)  
  
- [Cancelamento](#cancellation)  
  
- [Tarefas leves](#lwts)  
  
- [Agentes assíncronos](#agents)  
  
##  <a name="tasks"></a>Tarefas e continuações  
 Esta seção descreve como o tempo de execução trata exceções geradas por [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) objetos e seus continuações. Para obter mais informações sobre o modelo de tarefa e continuação, consulte [paralelismo de tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
 Quando você gera uma exceção no corpo de uma função de trabalho que você passa para um `task` do objeto, o tempo de execução armazena essa exceção e empacota o contexto que chama [concurrency::task::get](reference/task-class.md#get) ou [concurrency:: Task:: wait](reference/task-class.md#wait). O documento [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md) descreve baseado em tarefa versus continuações baseada em valor, mas ao resumir, uma continuação de acordo com o valor usa um parâmetro de tipo `T` e uma continuação de tarefas usa um parâmetro de tipo `task<T>`. Se uma tarefa que gera continuações baseada em valor de um ou mais desses continuações não são agendadas para execução. O exemplo a seguir ilustra esse comportamento:  

  
 [!code-cpp[concrt-eh-task#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_1.cpp)]  
  
 Uma continuação de tarefas permite tratar qualquer exceção que é gerada pela tarefa antecedente. Uma continuação de tarefas sempre é executado; não importa se a tarefa foi concluída com êxito, lançou uma exceção ou foi cancelada. Quando uma tarefa gera uma exceção, seus continuações baseado em tarefas estão agendadas para execução. O exemplo a seguir mostra uma tarefa que sempre gera. A tarefa tem duas continuações; uma é baseada em valor e a outra é baseado em tarefa. A exceção baseado em tarefas sempre é executado e, portanto, pode capturar a exceção que é gerada pela tarefa antecedente. Quando o exemplo espera para ambas as continuações concluir, a exceção é gerada novamente porque a exceção de tarefas sempre é gerada quando `task::get` ou `task::wait` é chamado.  
  
 [!code-cpp[concrt-eh-continuations#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_2.cpp)]  
  
 É recomendável que você use continuações baseado em tarefas para capturar exceções que você pode manipular. Como sempre executar continuações baseado em tarefa, considere se deseja adicionar uma continuação de tarefas com base no final de sua cadeia de continuação. Isso pode ajudar a garantir que seu código observa todas as exceções. O exemplo a seguir mostra uma cadeia de continuação básica baseada em valor. A terceira tarefa na cadeia lança e, portanto, qualquer continuações de acordo com o valor que se seguem não são executadas. No entanto, a continuação do final é baseado em tarefas e, portanto, sempre é executado. Este final continuação manipula a exceção que é gerada pela tarefa de terceiro.  
  
 É recomendável que você capture as exceções mais específicas que você pode. Se você não tem exceções específicas para capturar, você pode omitir essa continuação de baseado em tarefa final. Qualquer exceção permanece não manipulada e pode encerrar o aplicativo.  
  
 [!code-cpp[concrt-eh-task-chain#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_3.cpp)]  
  
> [!TIP]
>  Você pode usar o [concurrency::task_completion_event::set_exception](../../parallel/concrt/reference/task-completion-event-class.md) método associar uma exceção a um evento de conclusão de tarefas. O documento [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md) descreve o [Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md) classe mais detalhadamente.  
  

 [Concurrency::task_canceled](../../parallel/concrt/reference/task-canceled-class.md) é um tipo de exceção importante de tempo de execução que está relacionado ao `task`. O tempo de execução gera `task_canceled` quando você chama `task::get` e essa tarefa é cancelada. (Por outro lado, `task::wait` retorna [task_status::canceled](reference/concurrency-namespace-enums.md#task_group_status) e não gerará.) Você pode capturar e tratar essa exceção de uma continuação de tarefas, ou quando você chamar `task::get`. Para obter mais informações sobre o cancelamento da tarefa, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).  

  
> [!CAUTION]
>  Nunca lançam `task_canceled` do seu código. Chamar [concurrency::cancel_current_task](reference/concurrency-namespace-functions.md#cancel_current_task) em vez disso.  
  
 O tempo de execução encerra o aplicativo se uma tarefa gera uma exceção e exceções não capturadas pela tarefa, um dos seus continuações ou o aplicativo principal. Se o aplicativo falhar, você pode configurar o Visual Studio para interromper quando exceções C++ são geradas. Após diagnosticar o local da exceção sem tratamento, use uma continuação de tarefas para tratá-la.  
  
 A seção [exceções geradas pelo tempo de execução](#runtime) este documento descreve como trabalhar com exceções de tempo de execução mais detalhadamente.  
  
 [[Superior](#top)]  
  
##  <a name="task_groups"></a>Grupos de tarefas e os algoritmos paralelos  

 Esta seção descreve como o tempo de execução trata exceções geradas por grupos de tarefas. Esta seção também se aplica a algoritmos paralelos, como [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for), porque esses algoritmos de compilação em grupos de tarefas.  
  
> [!CAUTION]
>  Certifique-se de que entendeu os efeitos de exceções em tarefas dependentes. Para obter as práticas recomendadas sobre como usar tratamento de exceções com tarefas ou algoritmos paralelos, consulte o [compreender como cancelamento e destruição de tratamento afetam o objeto de exceção](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md#object-destruction) seção práticas recomendadas em paralela Tópico da biblioteca de padrões.  
  
 Para obter mais informações sobre grupos de tarefas, consulte [paralelismo de tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md). Para obter mais informações sobre os algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  

 Quando você gera uma exceção no corpo de uma função de trabalho que você passa para um [concurrency::task_group](reference/task-group-class.md) ou [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) do objeto, o tempo de execução armazena essa exceção e dispõe de o contexto que chama [concurrency::task_group::wait](reference/task-group-class.md#wait), [concurrency::structured_task_group::wait](reference/structured-task-group-class.md#wait), [concurrency::task_group::run_and_wait](reference/task-group-class.md#run_and_wait), ou [concurrency::structured_task_group::run_and_wait](reference/structured-task-group-class.md#run_and_wait). O tempo de execução também interrompe todas as tarefas ativas que estão no grupo de tarefas (inclusive os grupos de tarefas filho) e descarta quaisquer tarefas que ainda não foram iniciados.  

  
 O exemplo a seguir mostra a estrutura básica de uma função de trabalho que gera uma exceção. O exemplo usa um `task_group` objeto para imprimir os valores de dois `point` objetos em paralelo. O `print_point` função de trabalho imprime os valores de uma `point` objeto para o console. A função de trabalho gerará uma exceção se o valor de entrada é `NULL`. O tempo de execução armazena essa exceção e empacota o contexto que chama `task_group::wait`.  
  
 [!code-cpp[concrt-eh-task-group#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_4.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
X = 15, Y = 30Caught exception: point is NULL.  
```  
  
 Para obter um exemplo completo que usa um grupo de tarefas de manipulação de exceção, consulte [como: usar tratamento de exceção para parar um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md).  
  
 [[Superior](#top)]  
  
##  <a name="runtime"></a>Exceções geradas pelo tempo de execução  
 Uma exceção pode resultar de uma chamada para o tempo de execução. A maioria dos tipos de exceção, exceto para [concurrency::task_canceled](../../parallel/concrt/reference/task-canceled-class.md) e [concurrency::operation_timed_out](../../parallel/concrt/reference/operation-timed-out-class.md), indicar um erro de programação. Esses erros são geralmente irrecuperáveis e, portanto, devem não ser detectados ou tratados pelo código do aplicativo. Sugerimos que você somente catch ou manipular erros irrecuperáveis no código do aplicativo quando você precisa diagnosticar erros de programação. No entanto, entender os tipos de exceção que são definidos pelo tempo de execução pode ajudar a diagnosticar erros de programação.  
  
 A mecanismo de tratamento de exceção é o mesmo para exceções geradas pelo tempo de execução como exceções geradas pelas funções de trabalho. Por exemplo, o [concurrency::receive](reference/concurrency-namespace-functions.md#receive) função lança `operation_timed_out` quando ele não receber uma mensagem no período de tempo especificado. Se `receive` lança uma exceção em uma função de trabalho que você passa para um grupo de tarefas, o tempo de execução armazena essa exceção e empacota o contexto que chama `task_group::wait`, `structured_task_group::wait`, `task_group::run_and_wait`, ou `structured_task_group::run_and_wait`.  
  
 O exemplo a seguir usa o [concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo para executar duas tarefas em paralelo. A primeira tarefa espera cinco segundos e, em seguida, envia uma mensagem para um buffer de mensagem. A segunda tarefa usa a `receive` função aguardar três segundos para receber uma mensagem do mesmo buffer de mensagem. O `receive` função lança `operation_timed_out` se não receber a mensagem no período de tempo.  
  
 [!code-cpp[concrt-eh-time-out#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_5.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
The operation timed out.  
```  
  
 Para impedir o encerramento anormal do seu aplicativo, certifique-se de que seu código manipula exceções quando ela chama o tempo de execução. Quando você chama código externo que usa o tempo de execução de simultaneidade, por exemplo, uma biblioteca de terceiros também trata de exceções.  
  
 [[Superior](#top)]  
  
##  <a name="multiple"></a>Várias exceções  
 Se um algoritmo em paralelo ou tarefa recebe várias exceções, o tempo de execução realiza marshaling de apenas uma das exceções para o contexto de chamada. O tempo de execução não garante que ele realiza marshaling de exceção.  
  
 O exemplo a seguir usa o `parallel_for` algoritmo para imprimir os números no console. Gera uma exceção se o valor de entrada é menor que um valor mínimo ou maior que um valor máximo. Neste exemplo, várias funções de trabalho pode gerar uma exceção.  
  
 [!code-cpp[concrt-eh-multiple#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_6.cpp)]  
  
 O exemplo a seguir mostra a saída de exemplo para este exemplo.  
  
```Output  
8293104567Caught exception: -5: the value is less than the minimum.  
```  
  
 [[Superior](#top)]  
  
##  <a name="cancellation"></a>Cancelamento  
 Nem todas as exceções indicam um erro. Por exemplo, um algoritmo de pesquisa pode usar tratamento de exceções para interromper a tarefa associada ao encontrar o resultado. Para obter mais informações sobre como usar mecanismos de cancelamento em seu código, consulte [cancelamento no PPL](../../parallel/concrt/cancellation-in-the-ppl.md).  
  
 [[Superior](#top)]  
  
##  <a name="lwts"></a>Tarefas leves  
 Uma tarefa simples é uma tarefa que você agendar diretamente de um [concurrency::Scheduler](../../parallel/concrt/reference/scheduler-class.md) objeto. Tarefas leves carregam menos sobrecarga do que as tarefas comuns. No entanto, o tempo de execução não capturar exceções geradas por tarefas leves. Em vez disso, a exceção é capturada pelo manipulador de exceção sem tratamento, o que, por padrão, encerra o processo. Portanto, use um mecanismo de tratamento de erros apropriado em seu aplicativo. Para obter mais informações sobre tarefas leves, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
 [[Superior](#top)]  
  
##  <a name="agents"></a>Agentes assíncronos  
 Assim como tarefas simples, o tempo de execução não gerencia as exceções geradas por agentes assíncronos.  
  
 O exemplo a seguir mostra uma maneira de lidar com exceções em uma classe que deriva de [concurrency::agent](../../parallel/concrt/reference/agent-class.md). Este exemplo define o `points_agent` classe. O `points_agent::run` método leituras `point` objetos do buffer de mensagem e imprime no console. O `run` método lançará uma exceção se receber uma `NULL` ponteiro.  
  
 O `run` método envolve todo o trabalho em uma `try` - `catch` bloco. O `catch` bloco armazena a exceção em um buffer de mensagem. O aplicativo verifica se o agente encontrou um erro lendo desse buffer após o agente.  
  
 [!code-cpp[concrt-eh-agents#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_7.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
X: 10 Y: 20  
X: 20 Y: 30  
error occurred in agent: point must not be NULL  
the status of the agent is: done  
```  
  
 Porque o `try` - `catch` bloco existe fora o `while` loop, o agente termina de processar quando encontra o primeiro erro. Se o `try` - `catch` bloco estava dentro de `while` loop, o agente continuará após a ocorrência de um erro.  
  
 Este exemplo armazena exceções em um buffer de mensagem para que o outro componente pode monitorar o agente para erros conforme ele é executado. Este exemplo usa um [concurrency::single_assignment](../../parallel/concrt/reference/single-assignment-class.md) objeto para armazenar o erro. No caso em que um agente controla várias exceções, a `single_assignment` classe armazena apenas a primeira mensagem que é passada a ele. Para armazenar apenas a última exceção, use o [concurrency::overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) classe. Para armazenar todas as exceções, use o [concurrency::unbounded_buffer](reference/unbounded-buffer-class.md) classe. Para obter mais informações sobre esses blocos de mensagens, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).  
  
 Para obter mais informações sobre agentes assíncronos, consulte [agentes assíncronos](../../parallel/concrt/asynchronous-agents.md).  
  
 [[Superior](#top)]  
  
##  <a name="summary"></a> Resumo  
 [[Superior](#top)]  
  
## <a name="see-also"></a>Consulte também  
 [Tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime.md)   
 [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)   
 [Cancelamento no PPL](cancellation-in-the-ppl.md)   
 [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

