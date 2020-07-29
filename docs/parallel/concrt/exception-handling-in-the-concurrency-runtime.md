---
title: Tratamento de exceções no runtime de simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- lightweight tasks, exception handling [Concurrency Runtime]
- exception handling [Concurrency Runtime]
- structured task groups, exception handling [Concurrency Runtime]
- agents, exception handling [Concurrency Runtime]
- task groups, exception handling [Concurrency Runtime]
ms.assetid: 4d1494fb-3089-4f4b-8cfb-712aa67d7a7a
ms.openlocfilehash: f85bf5c96ef31944e84473f1fedb077123801153
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230396"
---
# <a name="exception-handling-in-the-concurrency-runtime"></a>Tratamento de exceções no runtime de simultaneidade

O Tempo de Execução de Simultaneidade usa a manipulação de exceções do C++ para comunicar muitos tipos de erros. Esses erros incluem uso inválido do tempo de execução, erros de tempo de execução como falha ao adquirir um recurso e erros que ocorrem em funções de trabalho que você fornece a tarefas e grupos de tarefas. Quando uma tarefa ou grupo de tarefas gera uma exceção, o tempo de execução mantém essa exceção e a empacota para o contexto que aguarda a conclusão da tarefa ou do grupo de tarefas. Para componentes como tarefas leves e agentes, o tempo de execução não gerencia exceções para você. Nesses casos, você deve implementar seu próprio mecanismo de tratamento de exceção. Este tópico descreve como o tempo de execução manipula exceções que são geradas por tarefas, grupos de tarefas, tarefas leves e agentes assíncronos e como responder a exceções em seus aplicativos.

## <a name="key-points"></a>Pontos Principais

- Quando uma tarefa ou grupo de tarefas gera uma exceção, o tempo de execução mantém essa exceção e a empacota para o contexto que aguarda a conclusão da tarefa ou do grupo de tarefas.

- Quando possível, coloque cada chamada para [Concurrency:: Task:: Get](reference/task-class.md#get) e [Concurrency:: Task:: Espere](reference/task-class.md#wait) com um **`try`** / **`catch`** bloco para tratar erros dos quais você pode se recuperar. O tempo de execução encerra o aplicativo se uma tarefa gera uma exceção e essa exceção não é detectada pela tarefa, uma de suas continuações ou o aplicativo principal.

- Uma continuação baseada em tarefa sempre é executada; Não importa se a tarefa Antecedent foi concluída com êxito, lançou uma exceção ou foi cancelada. Uma continuação baseada em valor não será executada se a tarefa Antecedent for lançada ou cancelada.

- Como as continuaçãos baseadas em tarefas sempre são executadas, considere a possibilidade de adicionar uma continuação baseada em tarefas ao final da cadeia de continuação. Isso pode ajudar a garantir que seu código Observe todas as exceções.

- O tempo de execução gera [Concurrency:: task_canceled](../../parallel/concrt/reference/task-canceled-class.md) quando você chama [Concurrency:: Task:: Get](reference/task-class.md#get) e essa tarefa é cancelada.

- O tempo de execução não gerencia exceções para tarefas leves e agentes.

## <a name="in-this-document"></a><a name="top"></a>Neste documento

- [Tarefas e Continuações](#tasks)

- [Grupos de Tarefas e Algoritmos Paralelos](#task_groups)

- [Exceções Geradas pelo Tempo de Execução](#runtime)

- [Várias Exceções](#multiple)

- [Cancelamento](#cancellation)

- [Tarefas leves](#lwts)

- [Agentes assíncronos](#agents)

## <a name="tasks-and-continuations"></a><a name="tasks"></a>Tarefas e continuações

Esta seção descreve como o tempo de execução manipula exceções que são geradas por objetos [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) e suas respectivas continuações. Para obter mais informações sobre o modelo de tarefa e continuação, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md).

Quando você lança uma exceção no corpo de uma função de trabalho que você passa para um `task` objeto, o tempo de execução armazena essa exceção e a empacota para o contexto que chama [Concurrency:: tarefa:: Get](reference/task-class.md#get) ou [Concurrency:: Task:: Wait](reference/task-class.md#wait). O [paralelismo de tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md) de documento descreve as continuações baseadas em tarefa versus valor, mas, para resumir, uma continuação baseada em valor usa um parâmetro do tipo `T` e uma continuação baseada em tarefa usa um parâmetro do tipo `task<T>` . Se uma tarefa lançada tiver uma ou mais continuaçãos baseadas em valor, essas continuaçãos não serão agendadas para execução. O exemplo a seguir ilustra esse comportamento:

[!code-cpp[concrt-eh-task#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_1.cpp)]

Uma continuação baseada em tarefas permite que você manipule qualquer exceção gerada pela tarefa Antecedent. Uma continuação baseada em tarefa sempre é executada; Não importa se a tarefa foi concluída com êxito, lançou uma exceção ou foi cancelada. Quando uma tarefa gera uma exceção, suas continuaçãos baseadas em tarefas são agendadas para execução. O exemplo a seguir mostra uma tarefa que sempre é lançada. A tarefa tem duas continuaçãos; uma é baseada em valor e a outra é baseada em tarefas. A exceção baseada em tarefa sempre é executada e, portanto, pode capturar a exceção que é gerada pela tarefa Antecedent. Quando o exemplo aguarda a conclusão de ambas as continuaçãos, a exceção é lançada novamente porque a exceção da tarefa é sempre gerada quando `task::get` ou `task::wait` é chamada.

[!code-cpp[concrt-eh-continuations#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_2.cpp)]

Recomendamos que você use as continuaçãos baseadas em tarefas para detectar exceções que você pode manipular. Como as continuaçãos baseadas em tarefas sempre são executadas, considere a possibilidade de adicionar uma continuação baseada em tarefas ao final da cadeia de continuação. Isso pode ajudar a garantir que seu código Observe todas as exceções. O exemplo a seguir mostra uma cadeia de continuação básica baseada em valor. A terceira tarefa na cadeia é lançada e, portanto, qualquer continuação baseada em valor que a siga não será executada. No entanto, a continuação final é baseada em tarefas e, portanto, sempre é executada. Essa continuação final manipula a exceção que é lançada pela terceira tarefa.

É recomendável que você capture as exceções mais específicas que você pode. Você pode omitir essa continuação baseada em tarefa final se não tiver exceções específicas a serem detectadas. Qualquer exceção permanecerá sem tratamento e poderá encerrar o aplicativo.

[!code-cpp[concrt-eh-task-chain#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_3.cpp)]

> [!TIP]
> Você pode usar o método [Concurrency:: task_completion_event:: set_exception](../../parallel/concrt/reference/task-completion-event-class.md) para associar uma exceção a um evento de conclusão de tarefa. O [paralelismo de tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md) de documento descreve a classe [concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md) mais detalhadamente.

[Concurrency:: task_canceled](../../parallel/concrt/reference/task-canceled-class.md) é um tipo de exceção de tempo de execução importante relacionado a `task` . O tempo de execução gera `task_canceled` quando você chama `task::get` e a tarefa é cancelada. (Por outro lado, `task::wait` retorna [task_status:: cancelado](reference/concurrency-namespace-enums.md#task_group_status) e não gera.) Você pode capturar e tratar essa exceção de uma continuação baseada em tarefa ou ao chamar `task::get` . Para obter mais informações sobre o cancelamento de tarefa, consulte [cancelamento na ppl](cancellation-in-the-ppl.md).

> [!CAUTION]
> Nunca jogue `task_canceled` do seu código. Chame [Concurrency:: cancel_current_task](reference/concurrency-namespace-functions.md#cancel_current_task) em vez disso.

O tempo de execução encerra o aplicativo se uma tarefa gera uma exceção e essa exceção não é detectada pela tarefa, uma de suas continuações ou o aplicativo principal. Se o aplicativo falhar, você poderá configurar o Visual Studio para interromper quando as exceções do C++ forem geradas. Depois de diagnosticar o local da exceção sem tratamento, use uma continuação baseada em tarefa para tratá-lo.

As exceções de seção [geradas pelo tempo de execução](#runtime) neste documento descrevem como trabalhar com exceções de tempo de execução com mais detalhes.

[[Superior](#top)]

## <a name="task-groups-and-parallel-algorithms"></a><a name="task_groups"></a>Grupos de tarefas e algoritmos paralelos

Esta seção descreve como o tempo de execução manipula exceções que são geradas por grupos de tarefas. Esta seção também se aplica a algoritmos paralelos, como [simultaneidade::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for), porque esses algoritmos se baseiam em grupos de tarefas.

> [!CAUTION]
> Certifique-se de entender os efeitos que as exceções têm em tarefas dependentes. Para obter as práticas recomendadas sobre como usar a manipulação de exceções com tarefas ou algoritmos paralelos, consulte a seção [compreender como o cancelamento e o tratamento de exceções afetam a destruição de objetos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md#object-destruction) nas práticas recomendadas no tópico da biblioteca de padrões paralelos.

Para obter mais informações sobre grupos de tarefas, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md). Para obter mais informações sobre algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

Quando você lança uma exceção no corpo de uma função de trabalho que passa para um objeto [Concurrency:: task_group](reference/task-group-class.md) ou [concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) , o tempo de execução armazena essa exceção e a empacota para o contexto que chama [Concurrency:: task_group:: espere](reference/task-group-class.md#wait), [Concurrency:: structured_task_group:: espera](reference/structured-task-group-class.md#wait), [Concurrency:: task_group:: run_and_wait](reference/task-group-class.md#run_and_wait)ou [Concurrency:: structured_task_group:: run_and_wait](reference/structured-task-group-class.md#run_and_wait). O tempo de execução também interrompe todas as tarefas ativas que estão no grupo de tarefas (incluindo aquelas em grupos de tarefas filho) e descarta todas as tarefas que ainda não foram iniciadas.

O exemplo a seguir mostra a estrutura básica de uma função de trabalho que gera uma exceção. O exemplo usa um `task_group` objeto para imprimir os valores de dois `point` objetos em paralelo. A `print_point` função de trabalho imprime os valores de um `point` objeto para o console do. A função trabalho gera uma exceção se o valor de entrada é `NULL` . O tempo de execução armazena essa exceção e a empacota para o contexto que chama `task_group::wait` .

[!code-cpp[concrt-eh-task-group#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_4.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
X = 15, Y = 30Caught exception: point is NULL.
```

Para obter um exemplo completo que usa a manipulação de exceção em um grupo de tarefas, consulte [como usar a manipulação de exceção para interromper a partir de um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md).

[[Superior](#top)]

## <a name="exceptions-thrown-by-the-runtime"></a><a name="runtime"></a>Exceções geradas pelo tempo de execução

Uma exceção pode resultar de uma chamada para o tempo de execução. A maioria dos tipos de exceção, exceto para [Concurrency:: task_canceled](../../parallel/concrt/reference/task-canceled-class.md) e [concurrency:: operation_timed_out](../../parallel/concrt/reference/operation-timed-out-class.md), indicam um erro de programação. Esses erros normalmente são irrecuperáveis e, portanto, não devem ser capturados nem manipulados pelo código do aplicativo. Sugerimos que você só pegue ou manipule erros irrecuperáveis no código do aplicativo quando precisar diagnosticar erros de programação. No entanto, entender os tipos de exceção que são definidos pelo tempo de execução pode ajudá-lo a diagnosticar erros de programação.

O mecanismo de tratamento de exceção é o mesmo para exceções que são geradas pelo tempo de execução como exceções que são geradas por funções de trabalho. Por exemplo, a função [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) `operation_timed_out` é lançada quando não recebe uma mensagem no período de tempo especificado. Se `receive` o lançar uma exceção em uma função de trabalho que você passa para um grupo de tarefas, o tempo de execução armazena essa exceção e a empacota para o contexto que chama `task_group::wait` , `structured_task_group::wait` , `task_group::run_and_wait` ou `structured_task_group::run_and_wait` .

O exemplo a seguir usa o algoritmo [Concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) para executar duas tarefas em paralelo. A primeira tarefa aguarda cinco segundos e, em seguida, envia uma mensagem para um buffer de mensagens. A segunda tarefa usa a `receive` função para aguardar três segundos para receber uma mensagem do mesmo buffer de mensagem. A `receive` função gera `operation_timed_out` se ela não recebe a mensagem no período de tempo.

[!code-cpp[concrt-eh-time-out#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_5.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
The operation timed out.
```

Para evitar a finalização anormal do seu aplicativo, certifique-se de que seu código manipule exceções ao chamar o tempo de execução. Além disso, manipule exceções quando você chama o código externo que usa o Tempo de Execução de Simultaneidade, por exemplo, uma biblioteca de terceiros.

[[Superior](#top)]

## <a name="multiple-exceptions"></a><a name="multiple"></a>Várias exceções

Se uma tarefa ou algoritmo paralelo receber várias exceções, o tempo de execução realizará marshaling apenas de uma dessas exceções para o contexto de chamada. O tempo de execução não garante qual exceção ela empacota.

O exemplo a seguir usa o `parallel_for` algoritmo para imprimir números no console. Ele lançará uma exceção se o valor de entrada for menor que um valor mínimo ou maior que um valor máximo. Neste exemplo, várias funções de trabalho podem gerar uma exceção.

[!code-cpp[concrt-eh-multiple#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_6.cpp)]

Veja a seguir uma saída de exemplo para este exemplo.

```Output
8293104567Caught exception: -5: the value is less than the minimum.
```

[[Superior](#top)]

## <a name="cancellation"></a><a name="cancellation"></a>Cancelamento

Nem todas as exceções indicam um erro. Por exemplo, um algoritmo de pesquisa pode usar manipulação de exceção para interromper sua tarefa associada quando encontrar o resultado. Para obter mais informações sobre como usar mecanismos de cancelamento em seu código, consulte [cancelamento na ppl](../../parallel/concrt/cancellation-in-the-ppl.md).

[[Superior](#top)]

## <a name="lightweight-tasks"></a><a name="lwts"></a>Tarefas leves

Uma tarefa leve é uma tarefa que você agenda diretamente de um objeto [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) . As tarefas leves trazem menos sobrecarga do que as tarefas comuns. No entanto, o tempo de execução não captura exceções que são geradas por tarefas leves. Em vez disso, a exceção é capturada pelo manipulador de exceção sem tratamento, que por padrão encerra o processo. Portanto, use um mecanismo de tratamento de erros apropriado em seu aplicativo. Para obter mais informações sobre tarefas leves, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

[[Superior](#top)]

## <a name="asynchronous-agents"></a><a name="agents"></a>Agentes assíncronos

Como as tarefas leves, o tempo de execução não gerencia exceções geradas por agentes assíncronos.

O exemplo a seguir mostra uma maneira de tratar exceções em uma classe derivada de [Concurrency:: Agent](../../parallel/concrt/reference/agent-class.md). Este exemplo define a `points_agent` classe. O `points_agent::run` método lê `point` objetos do buffer de mensagens e os imprime no console do. O `run` método gera uma exceção se receber um `NULL` ponteiro.

O `run` método envolve todo o trabalho em um **`try`** - **`catch`** bloco. O **`catch`** bloco armazena a exceção em um buffer de mensagens. O aplicativo verifica se o agente encontrou um erro ao ler a partir desse buffer após a conclusão do agente.

[!code-cpp[concrt-eh-agents#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_7.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
X: 10 Y: 20
X: 20 Y: 30
error occurred in agent: point must not be NULL
the status of the agent is: done
```

Como o **`try`** - **`catch`** bloco existe fora do **`while`** loop, o agente termina o processamento quando encontra o primeiro erro. Se o **`try`** - **`catch`** bloco estava dentro do **`while`** loop, o agente continuaria depois de ocorrer um erro.

Este exemplo armazena as exceções em um buffer de mensagens para que outro componente possa monitorar os erros do agente durante a execução. Este exemplo usa um objeto [Concurrency:: single_assignment](../../parallel/concrt/reference/single-assignment-class.md) para armazenar o erro. No caso em que um agente manipula várias exceções, a `single_assignment` classe armazena apenas a primeira mensagem que é passada para ela. Para armazenar apenas a última exceção, use a classe [Concurrency:: overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) . Para armazenar todas as exceções, use a classe [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) . Para obter mais informações sobre esses blocos de mensagens, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

Para obter mais informações sobre agentes assíncronos, consulte [agentes assíncronos](../../parallel/concrt/asynchronous-agents.md).

[[Superior](#top)]

## <a name="summary"></a><a name="summary"></a> Resumo

[[Superior](#top)]

## <a name="see-also"></a>Confira também

[Runtime de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)<br/>
[Paralelismo de Tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)
