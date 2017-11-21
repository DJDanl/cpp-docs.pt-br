---
title: "Como: usar tratamento de exceções para quebra de um loop paralelo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- search algorithm, writing [Concurrency Runtime]
- writing a search algorithm [Concurrency Runtime]
ms.assetid: 16d7278c-2d10-4014-9f58-f1899e719ff9
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 1b75c1779ae4f660acb925b07e857c1883f43fe8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-use-exception-handling-to-break-from-a-parallel-loop"></a>Como usar tratamento de exceções para parar um loop paralelo
Este tópico mostra como escrever um algoritmo de pesquisa para uma estrutura de árvore básico.  
  
 O tópico [cancelamento](cancellation-in-the-ppl.md) explica a função de cancelamento na biblioteca padrões paralelos. O uso da manipulação de exceção é uma maneira menos eficiente para cancelar o trabalho paralelo que o uso do [concurrency::task_group::cancel](reference/task-group-class.md#cancel) e [concurrency::structured_task_group::cancel](reference/structured-task-group-class.md#cancel) métodos. No entanto, um cenário em que o uso de manipulação de exceção para cancelar o trabalho é apropriado é quando você chama em uma biblioteca de terceiros que usa algoritmos paralelos ou tarefas, mas não fornece um `task_group` ou `structured_task_group` objeto para cancelar.  

  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra um `tree` tipo que contém um elemento de dados e uma lista de nós filho. A seção a seguir mostra o corpo do `for_all` método, quais recursivamente executa uma função de trabalho em cada nó filho.  
  
 [!code-cpp[concrt-task-tree-search#2](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_1.cpp)]  
  
## <a name="example"></a>Exemplo  
 A exemplo a seguir mostra o `for_all` método. Ele usa o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo para realizar uma função de trabalho em cada nó da árvore em paralelo.  
  
 [!code-cpp[concrt-task-tree-search#1](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_2.cpp)]  
  
## <a name="example"></a>Exemplo  
 A exemplo a seguir mostra o `search_for_value` função, que procura um valor em fornecidos `tree` objeto. Essa função passa para o `for_all` método uma função de trabalho que gera quando encontrar um nó de árvore que contém o valor fornecido.  
  
 Suponha que o `tree` classe é fornecida em uma biblioteca de terceiros e que não é possível modificá-lo. Nesse caso, o uso da manipulação de exceção é apropriado porque a `for_all` método não fornece um `task_group` ou `structured_task_group` objeto ao chamador. Portanto, a função de trabalho não conseguiu cancelar diretamente o respectivo grupo pai de tarefa.  
  
 Quando a função de trabalho que você fornecer a um grupo de tarefas gerará uma exceção, o tempo de execução interrompe todas as tarefas que estão no grupo de tarefas (incluindo quaisquer grupos de tarefas filho) e descarta quaisquer tarefas que ainda não foram iniciados. O `search_for_value` função usa um `try` - `catch` bloco para capturar a exceção e imprimir o resultado para o console.  
  
 [!code-cpp[concrt-task-tree-search#3](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_3.cpp)]  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria um `tree` do objeto e ele procura vários valores em paralelo. O `build_tree` função é mostrada posteriormente neste tópico.  
  
 [!code-cpp[concrt-task-tree-search#4](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_4.cpp)]  
  
 Este exemplo usa o [concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo para procurar valores em paralelo. Para obter mais informações sobre esse algoritmo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir completo usa tratamento de exceção para procurar valores em uma estrutura de árvore básico.  
  
 [!code-cpp[concrt-task-tree-search#5](../../parallel/concrt/codesnippet/cpp/how-to-use-exception-handling-to-break-from-a-parallel-loop_5.cpp)]  
  
 Este exemplo produz a saída de exemplo a seguir.  
  
```Output  
Found a node with value 32614.  
Found a node with value 86131.  
Did not find node with value 17522.  
```  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `task-tree-search.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc tarefa-árvore-search.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Cancelamento no PPL](cancellation-in-the-ppl.md)   
 [Tratamento de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)   
 [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)   
 [Classe task_group](reference/task-group-class.md)   
 [Classe structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md)   
 [Função parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each)


