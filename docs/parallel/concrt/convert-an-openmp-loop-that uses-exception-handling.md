---
title: 'Como: converter um Loop OpenMP que usa o tratamento de exceção para usar o tempo de execução de simultaneidade | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- exception handling, converting from OpenMP to the Concurrency Runtime
- converting from OpenMP to the Concurrency Runtime, exception handling
ms.assetid: 03c28196-21ba-439e-8641-afab1c283e1a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b96273589fb4e7d7e73e7bc72da03a92d5587de8
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="how-to-convert-an-openmp-loop-that-uses-exception-handling-to-use-the-concurrency-runtime"></a>Como converter um loop OpenMP que usa tratamento de exceções para usar o tempo de execução de simultaneidade
Este exemplo demonstra como converter um OpenMP [paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../../parallel/openmp/reference/for-openmp.md) loop que executa o tratamento de exceção para usar o mecanismo de tratamento de exceções de tempo de execução de simultaneidade.  
  
 Em OpenMP, uma exceção que é lançada em uma região parallel deve ser capturada e tratada na mesma região pelo mesmo thread. Uma exceção que ignora a região paralela é capturada pelo manipulador de exceção sem tratamento, que encerra o processo por padrão.  
  

 Em que o tempo de execução de simultaneidade, quando você gera uma exceção no corpo de uma função de trabalho que você passa para um grupo de tarefas, como um [concurrency::task_group](reference/task-group-class.md) ou [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) objeto, ou para um algoritmo em paralelo, como [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for), o tempo de execução armazena essa exceção e empacota o contexto que aguarda até que o grupo de tarefas ou o algoritmo para concluir. Para grupos de tarefas, o contexto de espera é o contexto que chama [concurrency::task_group::wait](reference/task-group-class.md#wait), [concurrency::structured_task_group::wait](reference/structured-task-group-class.md#wait), [concurrency::task_group::run_and _wait](reference/task-group-class.md#run_and_wait), ou [concurrency::structured_task_group::run_and_wait](reference/structured-task-group-class.md#run_and_wait). Para um algoritmo em paralelo, o contexto de espera é o contexto que chamou esse algoritmo. O tempo de execução também interrompe todas as tarefas ativas que estão no grupo de tarefas, inclusive os grupos de tarefas filho, e descarta quaisquer tarefas que ainda não foram iniciados.  


  
## <a name="example"></a>Exemplo  
 Este exemplo demonstra como manipular exceções em um OpenMP `parallel` região e, em uma chamada para `parallel_for`. O `do_work` função faz uma solicitação de alocação de memória que não for bem-sucedida e, portanto, gera uma exceção do tipo [std:: bad_alloc](../../standard-library/bad-alloc-class.md). Na versão que usa OpenMP, o thread que lança a exceção deve também alcançá-la. Em outras palavras, cada iteração de um loop paralelo OpenMP deve lidar com a exceção. Na versão que usa o tempo de execução de simultaneidade, o thread principal captura uma exceção que é lançada por outro thread.  
  
 [!code-cpp[concrt-openmp#3](../../parallel/concrt/codesnippet/cpp/convert-an-openmp-loop-that uses-exception-handling_1.cpp)]  
  
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
  
 A versão deste exemplo que usa OpenMP, a exceção ocorre no e é tratada por cada iteração do loop. Na versão que usa o tempo de execução de simultaneidade, o tempo de execução armazena a exceção, interrompe todas as tarefas ativas, descarta quaisquer tarefas que ainda não foram iniciados e empacota a exceção para o contexto que chama `parallel_for`.  
  
 Se você precisar que a versão que usa OpenMP termina após a exceção ocorrer, você pode usar um sinalizador booliano para sinalizar para outras iterações do loop que ocorreu o erro. Como no exemplo no tópico [como: converter um OpenMP Loop que cancelamento usa para usar o tempo de execução de simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that-uses-cancellation.md), iterações do loop subsequentes não fará nada se o sinalizador é definido. Por outro lado, se você precisar que o loop que usa o tempo de execução de simultaneidade continuará depois que a exceção ocorrer, lidar com a exceção no próprio corpo do loop paralelo.  
  
 Outros componentes do tempo de execução de simultaneidade, como agentes assíncronos e tarefas leves, não transporte exceções. Em vez disso, exceções sem tratamento são capturadas pelo manipulador de exceção sem tratamento, que encerra o processo por padrão. Para obter mais informações sobre o tratamento de exceção, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).  
  
 Para obter mais informações sobre `parallel_for` e outros algoritmos de paralelo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `concrt-omp-exceptions.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc /openmp concrt-omp-exceptions.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Migrando de OpenMP no tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)   
 [Tratamento de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)   
 [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)

