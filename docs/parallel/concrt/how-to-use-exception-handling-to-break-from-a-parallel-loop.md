---
title: Como usar tratamento de exceções para parar um loop paralelo
ms.date: 11/04/2016
helpviewer_keywords:
- search algorithm, writing [Concurrency Runtime]
- writing a search algorithm [Concurrency Runtime]
ms.assetid: 16d7278c-2d10-4014-9f58-f1899e719ff9
ms.openlocfilehash: a5576e8f2416804cac89f5ec34005f4e08b99c47
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142107"
---
# <a name="how-to-use-exception-handling-to-break-from-a-parallel-loop"></a>Como usar tratamento de exceções para parar um loop paralelo

Este tópico mostra como escrever um algoritmo de pesquisa para uma estrutura de árvore básica.

O tópico [cancelamento](cancellation-in-the-ppl.md) explica a função de cancelamento na biblioteca de padrões paralelos. O uso da manipulação de exceção é uma maneira menos eficiente de cancelar o trabalho paralelo do que o uso dos métodos [Concurrency:: task_group:: Cancel](reference/task-group-class.md#cancel) e [concurrency:: structured_task_group:: Cancel](reference/structured-task-group-class.md#cancel) . No entanto, um cenário em que o uso do tratamento de exceção para cancelar o trabalho é apropriado é quando você chama uma biblioteca de terceiros que usa tarefas ou algoritmos paralelos, mas não fornece um objeto `task_group` ou `structured_task_group` a ser cancelado.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra um tipo de `tree` básico que contém um elemento de dados e uma lista de nós filho. A seção a seguir mostra o corpo do método `for_all`, que executa recursivamente uma função de trabalho em cada nó filho.

[!code-cpp[concrt-task-tree-search#2](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_1.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra o método `for_all`. Ele usa o algoritmo [Concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) para executar uma função de trabalho em cada nó da árvore em paralelo.

[!code-cpp[concrt-task-tree-search#1](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_2.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a função `search_for_value`, que procura um valor no objeto `tree` fornecido. Essa função passa para o método de `for_all` uma função de trabalho que gera quando encontra um nó de árvore que contém o valor fornecido.

Suponha que a classe `tree` seja fornecida por uma biblioteca de terceiros e que você não possa modificá-la. Nesse caso, o uso de manipulação de exceção é apropriado porque o método `for_all` não fornece um objeto `task_group` ou `structured_task_group` ao chamador. Portanto, a função de trabalho não pode cancelar diretamente seu grupo de tarefas pai.

Quando a função de trabalho que você fornece a um grupo de tarefas gera uma exceção, o tempo de execução interrompe todas as tarefas que estão no grupo de tarefas (incluindo qualquer grupo de tarefas filho) e descarta todas as tarefas que ainda não foram iniciadas. A função `search_for_value` usa um bloco de `catch` -`try`para capturar a exceção e imprimir o resultado no console.

[!code-cpp[concrt-task-tree-search#3](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_3.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir cria um objeto `tree` e o pesquisa para vários valores em paralelo. A função `build_tree` é mostrada mais adiante neste tópico.

[!code-cpp[concrt-task-tree-search#4](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_4.cpp)]

Este exemplo usa o algoritmo [Concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) para pesquisar valores em paralelo. Para obter mais informações sobre esse algoritmo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo completo a seguir usa a manipulação de exceção para pesquisar valores em uma estrutura de árvore básica.

[!code-cpp[concrt-task-tree-search#5](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_5.cpp)]

Este exemplo produz a seguinte saída de exemplo.

```Output
Found a node with value 32614.
Found a node with value 86131.
Did not find node with value 17522.
```

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `task-tree-search.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Task-Tree-Search. cpp**

## <a name="see-also"></a>Consulte também

[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)<br/>
[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Classe task_group](reference/task-group-class.md)<br/>
[Classe structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md)<br/>
[Função parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each)
