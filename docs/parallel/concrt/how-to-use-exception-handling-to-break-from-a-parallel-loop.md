---
title: 'Como: Use o tratamento de exceções para quebra de um loop paralelo'
ms.date: 11/04/2016
helpviewer_keywords:
- search algorithm, writing [Concurrency Runtime]
- writing a search algorithm [Concurrency Runtime]
ms.assetid: 16d7278c-2d10-4014-9f58-f1899e719ff9
ms.openlocfilehash: 19d732d98f24172471d96cd5e2962b2a99ab0203
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57262305"
---
# <a name="how-to-use-exception-handling-to-break-from-a-parallel-loop"></a>Como: Use o tratamento de exceções para quebra de um loop paralelo

Este tópico mostra como escrever um algoritmo de pesquisa para uma estrutura de árvore básico.

O tópico [cancelamento](cancellation-in-the-ppl.md) explica a função de cancelamento na biblioteca padrões paralelos. O uso de manipulação de exceção é uma maneira menos eficiente para cancelar o trabalho paralelo que o uso do [concurrency::task_group::cancel](reference/task-group-class.md#cancel) e [concurrency::structured_task_group::cancel](reference/structured-task-group-class.md#cancel) métodos. No entanto, um cenário em que o uso de tratamento de exceções para cancelar o trabalho é apropriado é quando você chama em uma biblioteca de terceiros que usa tarefas ou algoritmos paralelos, mas não fornece um `task_group` ou `structured_task_group` objeto Cancelar.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra um `tree` tipo que contém um elemento de dados e uma lista de nós filho. A seção a seguir mostra o corpo do `for_all` método, quais recursivamente executa uma função de trabalho em cada nó filho.

[!code-cpp[concrt-task-tree-search#2](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_1.cpp)]

## <a name="example"></a>Exemplo

A exemplo a seguir mostra o `for_all` método. Ele usa o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo para realizar uma função de trabalho em cada nó da árvore em paralelo.

[!code-cpp[concrt-task-tree-search#1](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_2.cpp)]

## <a name="example"></a>Exemplo

A exemplo a seguir mostra a `search_for_value` função, que procura um valor fornecido `tree` objeto. Essa função passa para o `for_all` método uma função de trabalho que gera quando ele encontra um nó de árvore que contém o valor fornecido.

Suponha que o `tree` classe é fornecida por uma biblioteca de terceiros e que não é possível modificá-lo. Nesse caso, o uso de manipulação de exceção é apropriado porque o `for_all` método não fornece uma `task_group` ou `structured_task_group` objeto ao chamador. Portanto, a função de trabalho é não é possível cancelar diretamente de seu grupo de tarefas pai.

Quando a função de trabalho que você fornecer a um grupo de tarefas gera uma exceção, o tempo de execução interrompe todas as tarefas que estão no grupo de tarefas (incluindo quaisquer grupos de tarefas filho) e descarta quaisquer tarefas que ainda não iniciaram. O `search_for_value` função usa um `try` - `catch` bloco para capturar a exceção e imprimir o resultado no console.

[!code-cpp[concrt-task-tree-search#3](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_3.cpp)]

## <a name="example"></a>Exemplo

O exemplo a seguir cria um `tree` do objeto e ele o procura para vários valores em paralelo. O `build_tree` função será mostrada posteriormente neste tópico.

[!code-cpp[concrt-task-tree-search#4](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_4.cpp)]

Este exemplo usa o [Concurrency:: parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo para procurar valores em paralelo. Para obter mais informações sobre esse algoritmo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="example"></a>Exemplo

O seguinte exemplo completo usa o tratamento de exceções para procurar valores em uma estrutura de árvore básico.

[!code-cpp[concrt-task-tree-search#5](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_5.cpp)]

Este exemplo produz a saída de exemplo a seguir.

```Output
Found a node with value 32614.
Found a node with value 86131.
Did not find node with value 17522.
```

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `task-tree-search.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc task-tree-search.cpp**

## <a name="see-also"></a>Consulte também

[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)<br/>
[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Classe task_group](reference/task-group-class.md)<br/>
[Classe structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md)<br/>
[Função parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each)
