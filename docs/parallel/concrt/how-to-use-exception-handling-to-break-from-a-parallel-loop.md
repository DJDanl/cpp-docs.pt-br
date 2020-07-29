---
title: Como usar tratamento de exceções para parar um loop paralelo
ms.date: 11/04/2016
helpviewer_keywords:
- search algorithm, writing [Concurrency Runtime]
- writing a search algorithm [Concurrency Runtime]
ms.assetid: 16d7278c-2d10-4014-9f58-f1899e719ff9
ms.openlocfilehash: 9cf42df0926022f93633a6b5b1365ae9fc646a1a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213912"
---
# <a name="how-to-use-exception-handling-to-break-from-a-parallel-loop"></a>Como usar tratamento de exceções para parar um loop paralelo

Este tópico mostra como escrever um algoritmo de pesquisa para uma estrutura de árvore básica.

O tópico [cancelamento](cancellation-in-the-ppl.md) explica a função de cancelamento na biblioteca de padrões paralelos. O uso da manipulação de exceção é uma maneira menos eficiente de cancelar o trabalho paralelo do que o uso dos métodos [Concurrency:: task_group:: Cancel](reference/task-group-class.md#cancel) e [concurrency:: structured_task_group:: Cancel](reference/structured-task-group-class.md#cancel) . No entanto, um cenário em que o uso do tratamento de exceção para cancelar o trabalho é apropriado é quando você chama uma biblioteca de terceiros que usa tarefas ou algoritmos paralelos, mas não fornece um `task_group` `structured_task_group` objeto ou para cancelar.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra um `tree` tipo básico que contém um elemento de dados e uma lista de nós filho. A seção a seguir mostra o corpo do `for_all` método, que executa recursivamente uma função de trabalho em cada nó filho.

[!code-cpp[concrt-task-tree-search#2](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_1.cpp)]

## <a name="example"></a>Exemplo

O exemplo a seguir mostra o `for_all` método. Ele usa o algoritmo [Concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) para executar uma função de trabalho em cada nó da árvore em paralelo.

[!code-cpp[concrt-task-tree-search#1](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_2.cpp)]

## <a name="example"></a>Exemplo

O exemplo a seguir mostra a `search_for_value` função, que procura um valor no objeto fornecido `tree` . Essa função passa para o `for_all` método uma função de trabalho que é lançada quando encontra um nó de árvore que contém o valor fornecido.

Suponha que a `tree` classe seja fornecida por uma biblioteca de terceiros e que você não possa modificá-la. Nesse caso, o uso de manipulação de exceção é apropriado porque o `for_all` método não fornece um `task_group` objeto ou `structured_task_group` para o chamador. Portanto, a função de trabalho não pode cancelar diretamente seu grupo de tarefas pai.

Quando a função de trabalho que você fornece a um grupo de tarefas gera uma exceção, o tempo de execução interrompe todas as tarefas que estão no grupo de tarefas (incluindo qualquer grupo de tarefas filho) e descarta todas as tarefas que ainda não foram iniciadas. A `search_for_value` função usa um **`try`** - **`catch`** bloco para capturar a exceção e imprimir o resultado no console.

[!code-cpp[concrt-task-tree-search#3](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_3.cpp)]

## <a name="example"></a>Exemplo

O exemplo a seguir cria um `tree` objeto e o pesquisa em busca de vários valores em paralelo. A `build_tree` função é mostrada mais adiante neste tópico.

[!code-cpp[concrt-task-tree-search#4](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_4.cpp)]

Este exemplo usa o algoritmo [Concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) para pesquisar valores em paralelo. Para obter mais informações sobre esse algoritmo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="example"></a>Exemplo

O exemplo completo a seguir usa a manipulação de exceção para pesquisar valores em uma estrutura de árvore básica.

[!code-cpp[concrt-task-tree-search#5](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_5.cpp)]

Este exemplo produz a seguinte saída de exemplo.

```Output
Found a node with value 32614.
Found a node with value 86131.
Did not find node with value 17522.
```

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `task-tree-search.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc Task-Tree-Search. cpp**

## <a name="see-also"></a>Confira também

[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)<br/>
[Paralelismo de Tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Classe task_group](reference/task-group-class.md)<br/>
[Classe structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md)<br/>
[Função parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each)
