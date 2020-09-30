---
title: Como converter um loop OpenMP que usa cancelamento para usar o runtime de simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- converting from OpenMP to the Concurrency Runtime, cancellation
- cancellation, converting from OpenMP to the Concurrency Runtime
ms.assetid: 4b0b3c33-bfa9-4e96-ae08-aef245a39cbb
ms.openlocfilehash: adde6decc086b883c50e52d12e388197e185fb39
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91505938"
---
# <a name="how-to-convert-an-openmp-loop-that-uses-cancellation-to-use-the-concurrency-runtime"></a>Como converter um loop OpenMP que usa cancelamento para usar o runtime de simultaneidade

Alguns loops paralelos não exigem que todas as iterações sejam executadas. Por exemplo, um algoritmo que pesquisa um valor pode terminar depois que o valor é encontrado. O OpenMP não fornece um mecanismo para interromper um loop paralelo. No entanto, você pode usar um valor booliano, ou sinalizador, para habilitar uma iteração do loop para indicar que a solução foi encontrada. O Tempo de Execução de Simultaneidade fornece funcionalidade que permite que uma tarefa cancele outras tarefas que ainda não foram iniciadas.

Este exemplo demonstra como converter um loop[de OpenMP de](../openmp/reference/openmp-directives.md#for-openmp) uso [paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)que não requer que todas as iterações sejam executadas para usar o mecanismo de cancelamento de tempo de execução de simultaneidade.

## <a name="example"></a>Exemplo

Este exemplo usa o OpenMP e o Tempo de Execução de Simultaneidade para implementar uma versão paralela do algoritmo [std:: any_of](../../standard-library/algorithm-functions.md#any_of) . A versão de OpenMP deste exemplo usa um sinalizador para coordenar entre todas as iterações de loop paralelo que a condição foi atendida. A versão que usa o Tempo de Execução de Simultaneidade usa o método [Concurrency:: structured_task_group:: Cancel](reference/structured-task-group-class.md#cancel) para interromper a operação geral quando a condição é atendida.

[!code-cpp[concrt-openmp#2](../../parallel/concrt/codesnippet/cpp/convert-an-openmp-loop-that-uses-cancellation_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Using OpenMP...
9114046 is in the array.
Using the Concurrency Runtime...
9114046 is in the array.
```

Na versão do que usa OpenMP, todas as iterações do loop são executadas, mesmo quando o sinalizador é definido. Além disso, se uma tarefa tiver quaisquer tarefas filho, o sinalizador também precisaria estar disponível para essas tarefas filho para comunicar o cancelamento. No Tempo de Execução de Simultaneidade, quando um grupo de tarefas é cancelado, o tempo de execução cancela toda a árvore de trabalho, incluindo tarefas filhas. O algoritmo [Concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) usa tarefas para executar o trabalho. Portanto, quando uma iteração do loop cancela a tarefa raiz, toda a árvore de computação também é cancelada. Quando uma árvore de trabalho é cancelada, o tempo de execução não inicia novas tarefas. No entanto, o tempo de execução permite que as tarefas já tenham começado a ser concluídas. Portanto, no caso do `parallel_for_each` algoritmo, as iterações de loop ativo podem limpar seus recursos.

Em ambas as versões deste exemplo, se a matriz contiver mais de uma cópia do valor a ser pesquisado, várias iterações de loop poderão definir simultaneamente o resultado e cancelar a operação geral. Você pode usar um primitivo de sincronização, como uma seção crítica, se o problema exigir que apenas uma tarefa funcione quando uma condição for atendida.

Você também pode usar a manipulação de exceções para cancelar tarefas que usam a PPL. Para obter mais informações sobre cancelamento, consulte [cancelamento na ppl](cancellation-in-the-ppl.md).

Para obter mais informações sobre o `parallel_for_each` e outros algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `concrt-omp-parallel-any-of.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc/OpenMP ConcRT-OMP-Parallel-any-of. cpp**

## <a name="see-also"></a>Consulte também

[Migrando de OpenMP no Runtime de Simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)
