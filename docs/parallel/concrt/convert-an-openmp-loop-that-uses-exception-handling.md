---
title: 'Como: Converter um Loop OpenMP que usa o tratamento de exceções para usar o tempo de execução de simultaneidade'
ms.date: 11/04/2016
helpviewer_keywords:
- exception handling, converting from OpenMP to the Concurrency Runtime
- converting from OpenMP to the Concurrency Runtime, exception handling
ms.assetid: 03c28196-21ba-439e-8641-afab1c283e1a
ms.openlocfilehash: 118cf3e485fa78ae3eaa5efe34708924b89d6588
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62296378"
---
# <a name="how-to-convert-an-openmp-loop-that-uses-exception-handling-to-use-the-concurrency-runtime"></a>Como: Converter um Loop OpenMP que usa o tratamento de exceções para usar o tempo de execução de simultaneidade

Este exemplo demonstra como converter um OpenMP [paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../../parallel/openmp/reference/for-openmp.md) loop que executa o tratamento de exceções para usar o mecanismo de tratamento de exceções de tempo de execução de simultaneidade.

Em OpenMP, uma exceção é acionada em uma região parallel deve ser capturada e tratada na mesma região pelo mesmo thread. Uma exceção que ignora a região paralela é capturada pelo manipulador de exceção sem tratamento, o que encerra o processo por padrão.

Em que o tempo de execução de simultaneidade, ao lançar uma exceção no corpo de uma função de trabalho que você passa para um grupo de tarefas, como um [Concurrency:: task_group](reference/task-group-class.md) ou [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) objeto, ou para um algoritmo paralelo, como [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for), o tempo de execução armazena essa exceção e realizar o marshaling para o contexto que aguarda até o grupo de tarefas ou o algoritmo para concluir. Para grupos de tarefas, o contexto de espera é o contexto que chama [concurrency::task_group::wait](reference/task-group-class.md#wait), [concurrency::structured_task_group::wait](reference/structured-task-group-class.md#wait), [concurrency::task_group::run_and _wait](reference/task-group-class.md#run_and_wait), ou [concurrency::structured_task_group::run_and_wait](reference/structured-task-group-class.md#run_and_wait). Para um algoritmo paralelo, o contexto de espera é o contexto que chamou esse algoritmo. Além disso, o tempo de execução interrompe todas as tarefas ativas que estão no grupo de tarefas, inclusive aqueles em grupos de tarefas filho, e descarta quaisquer tarefas que ainda não iniciaram.

## <a name="example"></a>Exemplo

Este exemplo demonstra como manipular exceções em um OpenMP `parallel` região e, em uma chamada para `parallel_for`. O `do_work` função realiza uma solicitação de alocação de memória que não for bem-sucedida e, portanto, gera uma exceção do tipo [std:: bad_alloc](../../standard-library/bad-alloc-class.md). Na versão que usa o OpenMP, o thread que gerou a exceção deve também capturá-la. Em outras palavras, cada iteração de um loop paralelo do OpenMP deve tratar a exceção. Na versão que usa o tempo de execução de simultaneidade, o thread principal captura uma exceção que é gerada por outro thread.

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

Na versão desse exemplo que usa o OpenMP, a exceção ocorre em e é tratada por cada iteração do loop. Na versão que usa o tempo de execução de simultaneidade, o tempo de execução armazena a exceção, interrompe todas as tarefas ativas, descarta todas as tarefas que ainda não foram iniciados e realiza marshaling de exceção para o contexto que chama `parallel_for`.

Se você precisar que a versão que usa OpenMP termina depois que a exceção ocorre, você pode usar um sinalizador booliano para sinalizar para outras iterações do loop que ocorreu o erro. Como no exemplo no tópico [como: Converter um OpenMP Loop que cancelamento usa para usar o tempo de execução de simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that-uses-cancellation.md), iterações do loop subsequentes não faria nada se o sinalizador está definido. Por outro lado, se você precisar que o loop que usa o tempo de execução de simultaneidade continua depois que a exceção ocorre, tratar a exceção no próprio corpo do loop paralelo.

Não de outros componentes do tempo de execução de simultaneidade, como agentes assíncronos e tarefas leves, transporte de exceções. Em vez disso, as exceções sem tratamento são capturadas pelo manipulador de exceção sem tratamento, o que encerra o processo por padrão. Para obter mais informações sobre o tratamento de exceção, consulte [tratamento de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

Para obter mais informações sobre `parallel_for` e outros algoritmos em paralelo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `concrt-omp-exceptions.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc /openmp concrt-omp-exceptions.cpp**

## <a name="see-also"></a>Consulte também

[Migrando do OpenMP para o tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)<br/>
[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)
