---
title: Como converter um loop OpenMP que usa tratamento de exceções para usar o runtime de simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- exception handling, converting from OpenMP to the Concurrency Runtime
- converting from OpenMP to the Concurrency Runtime, exception handling
ms.assetid: 03c28196-21ba-439e-8641-afab1c283e1a
ms.openlocfilehash: ca2ee42d48d8fe9f66025b8f0d5eeb493fc91d10
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91498457"
---
# <a name="how-to-convert-an-openmp-loop-that-uses-exception-handling-to-use-the-concurrency-runtime"></a>Como converter um loop OpenMP que usa tratamento de exceções para usar o runtime de simultaneidade

Este exemplo demonstra como converter um loop de OpenMP [paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../openmp/reference/openmp-directives.md#for-openmp) o que executa a manipulação de exceção para usar o tempo de execução de simultaneidade mecanismo de manipulação de exceção.

No OpenMP, uma exceção que é lançada em uma região paralela deve ser detectada e manipulada na mesma região pelo mesmo thread. Uma exceção que escapa a região paralela é detectada pelo manipulador de exceção sem tratamento, que encerra o processo por padrão.

Na Tempo de Execução de Simultaneidade, quando você lança uma exceção no corpo de uma função de trabalho que passa para um grupo de tarefas, como um objeto [Concurrency:: task_group](reference/task-group-class.md) ou [concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) , ou para um algoritmo paralelo como [simultaneidade::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for), o tempo de execução armazena essa exceção e a empacota para o contexto que aguarda que o grupo de tarefas ou o algoritmo seja concluído. Para grupos de tarefas, o contexto de espera é o contexto que chama [simultaneidade:: task_group:: Wait](reference/task-group-class.md#wait), [simultaneidade:: structured_task_group:: Wait](reference/structured-task-group-class.md#wait), [Concurrency:: task_group:: run_and_wait](reference/task-group-class.md#run_and_wait)ou [Concurrency:: structured_task_group:: run_and_wait](reference/structured-task-group-class.md#run_and_wait). Para um algoritmo paralelo, o contexto de espera é o contexto que chamou esse algoritmo. O tempo de execução também interrompe todas as tarefas ativas que estão no grupo de tarefas, incluindo aquelas em grupos de tarefas filho, e descarta todas as tarefas que ainda não foram iniciadas.

## <a name="example"></a>Exemplo

Este exemplo demonstra como tratar exceções em uma região de OpenMP `parallel` e em uma chamada para `parallel_for` . A `do_work` função executa uma solicitação de alocação de memória que não tem sucesso e, portanto, gera uma exceção do tipo [std:: bad_alloc](../../standard-library/bad-alloc-class.md). Na versão que usa OpenMP, o thread que lança a exceção também deve capturá-la. Em outras palavras, cada iteração de um loop de OpenMP deve tratar a exceção. Na versão que usa o Tempo de Execução de Simultaneidade, o thread principal captura uma exceção que é gerada por outro thread.

[!code-cpp[concrt-openmp#3](../../parallel/concrt/codesnippet/cpp/convert-an-openmp-loop-that-uses-exception-handling_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Using OpenMP...
An error of type 'class std::bad_alloc' occurred.
An error of type 'class std::bad_alloc' occurred.
An error of type 'class std::bad_alloc' occurred.
An error of type 'class std::bad_alloc' occurred.
An error of type 'class std::bad_alloc' occurred.
An error of type 'class std::bad_alloc' occurred.
An error of type 'class std::bad_alloc' occurred.
An error of type 'class std::bad_alloc' occurred.
An error of type 'class std::bad_alloc' occurred.
An error of type 'class std::bad_alloc' occurred.
Using the Concurrency Runtime...
An error of type 'class std::bad_alloc' occurred.
```

Na versão deste exemplo que usa OpenMP, a exceção ocorre em e é manipulada por cada iteração de loop. Na versão que usa o Tempo de Execução de Simultaneidade, o tempo de execução armazena a exceção, interrompe todas as tarefas ativas, descarta todas as tarefas que ainda não foram iniciadas e realiza marshaling da exceção para o contexto que chama `parallel_for` .

Se você precisar que a versão que usa o encerramento de OpenMP após a exceção ocorra, você poderá usar um sinalizador booliano para sinalizar para outras iterações de loop que o erro ocorreu. Como no exemplo no tópico [como converter um loop de OpenMP que usa o cancelamento para usar o tempo de execução de simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that-uses-cancellation.md), as iterações de loop subsequentes não farão nada se o sinalizador estiver definido. Por outro lado, se você precisar que o loop que usa o Tempo de Execução de Simultaneidade continue após a exceção ocorrer, manipule a exceção no próprio corpo do loop paralelo.

Outros componentes do Tempo de Execução de Simultaneidade, como agentes assíncronos e tarefas leves, não transportam exceções. Em vez disso, as exceções sem tratamento são detectadas pelo manipulador de exceção sem tratamento, que encerra o processo por padrão. Para obter mais informações sobre manipulação de exceção, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

Para obter mais informações sobre o `parallel_for` e outros algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `concrt-omp-exceptions.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc/OpenMP ConcRT-OMP-Exceptions. cpp**

## <a name="see-also"></a>Consulte também

[Migrando de OpenMP no Runtime de Simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)<br/>
[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)
