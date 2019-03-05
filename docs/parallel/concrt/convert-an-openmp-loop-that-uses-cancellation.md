---
title: 'Como: Converter um Loop OpenMP que usa cancelamento para usar o tempo de execução de simultaneidade'
ms.date: 11/04/2016
helpviewer_keywords:
- converting from OpenMP to the Concurrency Runtime, cancellation
- cancellation, converting from OpenMP to the Concurrency Runtime
ms.assetid: 4b0b3c33-bfa9-4e96-ae08-aef245a39cbb
ms.openlocfilehash: 618e93c18173bfe3e5f5b5f3058a8bb3d61e98ec
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57300668"
---
# <a name="how-to-convert-an-openmp-loop-that-uses-cancellation-to-use-the-concurrency-runtime"></a>Como: Converter um Loop OpenMP que usa cancelamento para usar o tempo de execução de simultaneidade

Alguns loops paralelos não exigem que todas as iterações ser executado. Por exemplo, um algoritmo que procura um valor pode terminar depois que o valor for encontrado. OpenMP não fornece um mecanismo para interromper um loop paralelo. No entanto, você pode usar um valor booliano, ou o sinalizador, para habilitar uma iteração do loop para indicar que a solução foi encontrada. O tempo de execução de simultaneidade fornece a funcionalidade que permite que uma tarefa cancelar a outras tarefas que ainda não iniciaram.

Este exemplo demonstra como converter um OpenMP [paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../../parallel/openmp/reference/for-openmp.md) loop que não requer para todas as iterações executar para usar o mecanismo de cancelamento de tempo de execução de simultaneidade.

## <a name="example"></a>Exemplo

Este exemplo usa o OpenMP e o tempo de execução de simultaneidade para implementar uma versão paralela do [std::any_of](../../standard-library/algorithm-functions.md#any_of) algoritmo. A versão OpenMP Este exemplo usa um sinalizador para coordenar entre todas as iterações do loop paralelo que a condição for atendida. A versão que usa o tempo de execução de simultaneidade usa o [concurrency::structured_task_group::cancel](reference/structured-task-group-class.md#cancel) método para parar a operação geral, quando a condição for atendida.

[!code-cpp[concrt-openmp#2](../../parallel/concrt/codesnippet/cpp/convert-an-openmp-loop-that-uses-cancellation_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Using OpenMP...
9114046 is in the array.
Using the Concurrency Runtime...
9114046 is in the array.
```

A versão que usa OpenMP, todas as iterações do loop executar, até mesmo quando o sinalizador está definido. Além disso, se uma tarefa tem todas as tarefas filho, o sinalizador também precisaria estar disponível para essas tarefas filho para se comunicar o cancelamento. O tempo de execução de simultaneidade, quando um grupo de tarefas for cancelado, o tempo de execução cancela toda a árvore de trabalho, incluindo tarefas filho. O [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo usa tarefas para executar o trabalho. Portanto, quando uma iteração do loop cancela a tarefa de raiz, toda a árvore de computação também é cancelada. Quando uma árvore de trabalho é cancelada, o tempo de execução não iniciar novas tarefas. No entanto, o tempo de execução permite que as tarefas que já tem começado a concluir. Portanto, no caso do `parallel_for_each` algoritmo, iterações do loop do Active Directory podem limpar seus recursos.

As duas versões desse exemplo, se a matriz contiver mais de uma cópia do valor a ser pesquisado, várias iterações do loop podem cada definido simultaneamente o resultado e cancelar a operação geral. Você pode usar um primitivo de sincronização, como uma seção crítica, se o seu problema exige que apenas uma tarefa executa o trabalho quando uma condição for atendida.

Você também pode usar o tratamento de exceções para cancelar as tarefas que usam o PPL. Para obter mais informações sobre cancelamento, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).

Para obter mais informações sobre `parallel_for_each` e outros algoritmos em paralelo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `concrt-omp-parallel-any-of.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc /openmp concrt-omp-parallel-any-of.cpp**

## <a name="see-also"></a>Consulte também

[Migrando do OpenMP para o tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)
