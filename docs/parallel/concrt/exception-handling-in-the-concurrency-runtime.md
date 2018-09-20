---
title: Tratamento de exceções em tempo de execução de simultaneidade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- lightweight tasks, exception handling [Concurrency Runtime]
- exception handling [Concurrency Runtime]
- structured task groups, exception handling [Concurrency Runtime]
- agents, exception handling [Concurrency Runtime]
- task groups, exception handling [Concurrency Runtime]
ms.assetid: 4d1494fb-3089-4f4b-8cfb-712aa67d7a7a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9490fcbd765f277030c235a09d5b6d86d6522676
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46405197"
---
# <a name="exception-handling-in-the-concurrency-runtime"></a>Tratamento de exceções no tempo de execução de simultaneidade

O tempo de execução de simultaneidade usa para comunicar-se a vários tipos de erros de tratamento de exceções de C++. Esses erros incluem o uso inválido do tempo de execução, erros de tempo de execução, como Falha ao adquirir um recurso e erros que ocorrem em funções de trabalho que você fornece para tarefas e grupos de tarefas. Quando uma tarefa ou um grupo de tarefas gera uma exceção, o tempo de execução mantém essa exceção e realizar o marshaling para o contexto que aguarda a tarefa ou o grupo de tarefas para concluir. Para componentes, como tarefas leves e agentes, o tempo de execução não gerencia exceções para você. Nesses casos, você deve implementar seu próprio mecanismo de tratamento de exceção. Este tópico descreve como o tempo de execução trata exceções que são geradas por tarefas, grupos de tarefas, tarefas leves e agentes assíncronos e como responder a exceções em seus aplicativos.

## <a name="key-points"></a>Pontos-chave

- Quando uma tarefa ou um grupo de tarefas gera uma exceção, o tempo de execução mantém essa exceção e realizar o marshaling para o contexto que aguarda a tarefa ou o grupo de tarefas para concluir.

- Quando possível, coloque todas as chamadas para [concurrency::task::get](reference/task-class.md#get) e [concurrency::task::wait](reference/task-class.md#wait) com um `try` / `catch` bloco para manipular erros que podem ser recuperados De. O tempo de execução encerra o aplicativo se uma tarefa gera uma exceção, e essa exceção não é capturada pela tarefa, uma das suas continuações, ou o aplicativo principal.

- Uma continuação baseada em tarefa sempre é executado; não importa se foi concluída com êxito, a tarefa do antecessor gerou uma exceção ou foi cancelada. Uma continuação baseada em valor não será executado se a tarefa antecedente gera ou cancela.

- Porque continuações de tarefa sempre em execução, considere se você deseja adicionar uma continuação baseada em tarefa no final da sua cadeia de continuação. Isso pode ajudar a garantir que seu código Observe todas as exceções.

- O tempo de execução gera [Concurrency:: task_canceled](../../parallel/concrt/reference/task-canceled-class.md) quando você chama [concurrency::task::get](reference/task-class.md#get) e que a tarefa é cancelada.

- O tempo de execução não gerencia exceções para tarefas leves e agentes.

##  <a name="top"></a> Neste documento

- [As tarefas e continuações](#tasks)

- [Grupos de tarefas e algoritmos paralelos](#task_groups)

- [Exceções geradas pelo tempo de execução](#runtime)

- [Várias exceções](#multiple)

- [Cancelamento](#cancellation)

- [Tarefas leves](#lwts)

- [Agentes assíncronos](#agents)

##  <a name="tasks"></a> As tarefas e continuações

Esta seção descreve como o tempo de execução trata exceções que são geradas pelo [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) objetos e suas continuações. Para obter mais informações sobre o modelo de tarefa e continuação, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md).

Quando você lança uma exceção no corpo de uma função de trabalho que você passa para um `task` do objeto, o tempo de execução armazena essa exceção e realizar o marshaling para o contexto que chama [concurrency::task::get](reference/task-class.md#get) ou [concurrency:: Task:: wait](reference/task-class.md#wait). O documento [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md) descreve baseado em tarefa versus continuações com base no valor, mas ao resumir, uma continuação baseada em valor usa um parâmetro do tipo `T` e uma continuação baseada em tarefa leva um parâmetro de tipo `task<T>`. Se uma tarefa que lança tiver continuações com base no valor de um ou mais, as continuações não estão agendadas para execução. O exemplo a seguir ilustra esse comportamento:

[!code-cpp[concrt-eh-task#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_1.cpp)]

Uma continuação baseada em tarefas permite que você lidar com qualquer exceção que é gerada pela tarefa antecedente. Uma continuação baseada em tarefa sempre é executado; não importa se a tarefa foi concluída com êxito, lançou uma exceção ou foi cancelada. Quando uma tarefa gera uma exceção, suas continuações baseado em tarefas estão agendadas para execução. O exemplo a seguir mostra uma tarefa que sempre gera. A tarefa tem duas continuações; uma é baseada em valor e o outro é baseado em tarefa. A exceção baseado em tarefas sempre é executado e, portanto, pode capturar a exceção que é gerada pela tarefa antecedente. Quando o exemplo aguarda para ambas as continuações concluir, a exceção é lançada novamente porque a exceção de tarefa sempre é gerada quando `task::get` ou `task::wait` é chamado.

[!code-cpp[concrt-eh-continuations#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_2.cpp)]

É recomendável que você use continuações baseado em tarefas para capturar exceções que você pode manipular. Porque continuações de tarefa sempre em execução, considere se você deseja adicionar uma continuação baseada em tarefa no final da sua cadeia de continuação. Isso pode ajudar a garantir que seu código Observe todas as exceções. O exemplo a seguir mostra uma cadeia básica de continuação baseada em valor. Lança a terceira tarefa na cadeia e, portanto, não são executadas todas as continuações com base no valor do que o seguem. No entanto, a continuação final é baseado em tarefa e, portanto, sempre é executado. Essa continuação final manipula a exceção que é gerada pela tarefa de terceiro.

É recomendável que você capture as exceções mais específicas que você pode. Se você não tem exceções específicas para capturar, você pode omitir essa continuação final baseado em tarefa. Qualquer exceção permanece sem tratamento e pode encerrar o aplicativo.

[!code-cpp[concrt-eh-task-chain#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_3.cpp)]

> [!TIP]
>  Você pode usar o [concurrency::task_completion_event::set_exception](../../parallel/concrt/reference/task-completion-event-class.md) método a ser associado a um evento de conclusão de tarefas de uma exceção. O documento [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md) descreve a [Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md) classe mais detalhadamente.

[Concurrency:: task_canceled](../../parallel/concrt/reference/task-canceled-class.md) é um tipo de exceção de importantes de tempo de execução que está relacionado ao `task`. O tempo de execução gera `task_canceled` quando você chama `task::get` e que a tarefa é cancelada. (Por outro lado, `task::wait` retorna [task_status::canceled](reference/concurrency-namespace-enums.md#task_group_status) e não gerará.) Você pode capturar e tratar essa exceção de uma continuação baseada em tarefa, ou quando você chama `task::get`. Para obter mais informações sobre o cancelamento de tarefa, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).

> [!CAUTION]
>  Nunca geram `task_canceled` do seu código. Chame [concurrency::cancel_current_task](reference/concurrency-namespace-functions.md#cancel_current_task) em vez disso.

O tempo de execução encerra o aplicativo se uma tarefa gera uma exceção, e essa exceção não é capturada pela tarefa, uma das suas continuações, ou o aplicativo principal. Se seu aplicativo falhar, você pode configurar o Visual Studio para interromper quando exceções de C++ são geradas. Depois que você diagnosticar o local da exceção sem tratamento, use uma continuação baseada em tarefa para tratá-la.

A seção [as exceções geradas pelo tempo de execução](#runtime) este documento descreve como trabalhar com exceções de tempo de execução mais detalhadamente.

[[Superior](#top)]

##  <a name="task_groups"></a> Grupos de tarefas e algoritmos paralelos

Esta seção descreve como o tempo de execução trata exceções que são geradas por grupos de tarefas. Esta seção também se aplica a algoritmos paralelos, como [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for), porque esses algoritmos compilar em grupos de tarefas.

> [!CAUTION]
>  Certifique-se de que você compreenda os efeitos que as exceções têm nas tarefas dependentes. Para obter as práticas recomendadas sobre como usar tratamento de exceções com tarefas ou algoritmos paralelos, consulte o [compreender como cancelamento e destruição de tratamento afetam o objeto de exceção](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md#object-destruction) seção práticas recomendadas de paralelamente Tópico da biblioteca de padrões.

Para obter mais informações sobre grupos de tarefas, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md). Para obter mais informações sobre os algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

Quando você lança uma exceção no corpo de uma função de trabalho que você passa para um [Concurrency:: task_group](reference/task-group-class.md) ou [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) do objeto, o tempo de execução armazena essa exceção e dispõe de o contexto que chama [concurrency::task_group::wait](reference/task-group-class.md#wait), [concurrency::structured_task_group::wait](reference/structured-task-group-class.md#wait), [concurrency::task_group::run_and_wait](reference/task-group-class.md#run_and_wait), ou [concurrency::structured_task_group::run_and_wait](reference/structured-task-group-class.md#run_and_wait). Além disso, o tempo de execução interrompe todas as tarefas ativas que estão no grupo de tarefas (inclusive os grupos de tarefas filho) e descarta quaisquer tarefas que ainda não iniciaram.

O exemplo a seguir mostra a estrutura básica de uma função de trabalho que gera uma exceção. O exemplo usa uma `task_group` objeto para imprimir os valores dos dois `point` objetos em paralelo. O `print_point` função de trabalho imprime os valores de um `point` objeto para o console. A função de trabalho gera uma exceção se o valor de entrada é `NULL`. O tempo de execução armazena essa exceção e realizar o marshaling para o contexto que chama `task_group::wait`.

[!code-cpp[concrt-eh-task-group#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_4.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
X = 15, Y = 30Caught exception: point is NULL.
```

Para obter um exemplo completo que usa o tratamento de exceções em um grupo de tarefas, consulte [como: usar tratamento de exceções para interromper um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md).

[[Superior](#top)]

##  <a name="runtime"></a> Exceções geradas pelo tempo de execução

Uma exceção pode resultar de uma chamada para o tempo de execução. A maioria dos tipos de exceção, exceto para [Concurrency:: task_canceled](../../parallel/concrt/reference/task-canceled-class.md) e [concurrency::operation_timed_out](../../parallel/concrt/reference/operation-timed-out-class.md), indicar um erro de programação. Esses erros são geralmente irrecuperáveis e, portanto, devem não ser detectados ou manipulados pelo código do aplicativo. Sugerimos que você apenas captura ou lidar com erros irrecuperáveis no código do aplicativo quando precisar diagnosticar erros de programação. No entanto, compreender os tipos de exceção que são definidos pelo tempo de execução pode ajudar a diagnosticar erros de programação.

A mecanismo de tratamento de exceção é o mesmo para exceções geradas pelo tempo de execução como exceções geradas pelas funções de trabalho. Por exemplo, o [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) função lança `operation_timed_out` quando ele não recebe uma mensagem no período de tempo especificado. Se `receive` gera uma exceção em uma função de trabalho que você passa para um grupo de tarefas, o tempo de execução armazena essa exceção e realizar o marshaling para o contexto que chama `task_group::wait`, `structured_task_group::wait`, `task_group::run_and_wait`, ou `structured_task_group::run_and_wait`.

O exemplo a seguir usa o [Concurrency:: parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo para executar duas tarefas em paralelo. A primeira tarefa espera cinco segundos e, em seguida, envia uma mensagem para um buffer de mensagem. A segunda tarefa usa o `receive` função aguardar três segundos para receber uma mensagem do mesmo buffer de mensagem. O `receive` função lança `operation_timed_out` se não receber a mensagem no período de tempo.

[!code-cpp[concrt-eh-time-out#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_5.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
The operation timed out.
```

Para impedir o encerramento anormal do seu aplicativo, certifique-se de que seu código trate exceções quando chama o tempo de execução. Também manipula exceções ao chamar em código externo que usa o tempo de execução de simultaneidade, por exemplo, uma biblioteca de terceiros.

[[Superior](#top)]

##  <a name="multiple"></a> Várias exceções

Se um algoritmo paralelo ou tarefa recebe várias exceções, o tempo de execução realiza marshaling de apenas uma dessas exceções para o contexto de chamada. O tempo de execução não garante que ele realiza marshaling de exceção.

O exemplo a seguir usa o `parallel_for` algoritmo para imprimir os números no console. Ele gera uma exceção se o valor de entrada é menor que algum valor mínimo ou maior que algum valor máximo. Neste exemplo, várias funções de trabalho pode lançar uma exceção.

[!code-cpp[concrt-eh-multiple#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_6.cpp)]

O exemplo a seguir mostra a saída de exemplo para este exemplo.

```Output
8293104567Caught exception: -5: the value is less than the minimum.
```

[[Superior](#top)]

##  <a name="cancellation"></a> Cancelamento

Nem todas as exceções indicam um erro. Por exemplo, um algoritmo de pesquisa pode usar o tratamento de exceções para interromper a tarefa associada quando ele encontra o resultado. Para obter mais informações sobre como usar o mecanismo de cancelamento em seu código, consulte [cancelamento no PPL](../../parallel/concrt/cancellation-in-the-ppl.md).

[[Superior](#top)]

##  <a name="lwts"></a> Tarefas leves

Uma tarefa leve é uma tarefa agendada diretamente de um [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) objeto. Tarefas leves carregam menos sobrecarga do que as tarefas comuns. No entanto, o tempo de execução não capturará exceções que são geradas por tarefas leves. Em vez disso, a exceção é capturada pelo manipulador de exceção sem tratamento, que, por padrão, encerra o processo. Portanto, use um mecanismo de tratamento de erros apropriado em seu aplicativo. Para obter mais informações sobre tarefas leves, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

[[Superior](#top)]

##  <a name="agents"></a> Agentes assíncronos

Assim como tarefas leves, o tempo de execução não gerencia as exceções geradas por agentes assíncronos.

O exemplo a seguir mostra uma maneira para tratar exceções em uma classe que deriva de [concurrency::agent](../../parallel/concrt/reference/agent-class.md). Este exemplo define o `points_agent` classe. O `points_agent::run` método leituras `point` objetos do buffer de mensagem e imprime no console. O `run` método gera uma exceção se ela recebe um `NULL` ponteiro.

O `run` método ao redor de todo o trabalho em um `try` - `catch` bloco. O `catch` bloco armazena a exceção em um buffer de mensagem. O aplicativo verifica se o agente encontrou um erro com a leitura desse buffer após a conclusão do agente.

[!code-cpp[concrt-eh-agents#1](../../parallel/concrt/codesnippet/cpp/exception-handling-in-the-concurrency-runtime_7.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
X: 10 Y: 20
X: 20 Y: 30
error occurred in agent: point must not be NULL
the status of the agent is: done
```

Porque o `try` - `catch` bloco existe fora o `while` loop, o agente termina de processar quando encontra o primeiro erro. Se o `try` - `catch` bloco estava dentro de `while` loop, o agente continuará depois de ocorrer um erro.

Este exemplo armazena exceções em um buffer de mensagem para que o outro componente pode monitorar o agente para erros enquanto ele é executado. Este exemplo usa uma [concurrency::single_assignment](../../parallel/concrt/reference/single-assignment-class.md) objeto para armazenar o erro. No caso em que um agente lida com várias exceções, o `single_assignment` classe armazena apenas a primeira mensagem que é passada a ele. Para armazenar apenas a última exceção, use o [Concurrency:: overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) classe. Para armazenar todas as exceções, use o [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) classe. Para obter mais informações sobre esses blocos de mensagem, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

Para obter mais informações sobre agentes assíncronos, consulte [agentes assíncronos](../../parallel/concrt/asynchronous-agents.md).

[[Superior](#top)]

##  <a name="summary"></a> Resumo

[[Superior](#top)]

## <a name="see-also"></a>Consulte também

[Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)<br/>
[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

