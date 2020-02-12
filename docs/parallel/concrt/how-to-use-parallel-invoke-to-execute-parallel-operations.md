---
title: Como usar parallel_invoke para executar operações em paralelo
ms.date: 11/04/2016
helpviewer_keywords:
- parallel_invoke function, example
- calling multiple functions in parallel [Concurrency Runtime]
ms.assetid: a6aea69b-d647-4b7e-bf3b-e6a6a9880072
ms.openlocfilehash: 199b663331e3322601100206f222e80bbb7c8db0
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142267"
---
# <a name="how-to-use-parallel_invoke-to-execute-parallel-operations"></a>Como usar parallel_invoke para executar operações em paralelo

Este exemplo mostra como usar o algoritmo [Concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) para melhorar o desempenho de um programa que executa várias operações em uma fonte de dados compartilhada. Como nenhuma operação modifica a origem, elas podem ser executadas em paralelo de maneira simples.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Considere o seguinte exemplo de código que cria uma variável do tipo `MyDataType`, chama uma função para inicializar essa variável e, em seguida, executa várias operações demoradas nesses dados.

[!code-cpp[concrt-parallel-word-mining#1](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-execute-parallel-operations_1.cpp)]

Se as funções `lengthy_operation1`, `lengthy_operation2`e `lengthy_operation3` não modificarem a variável `MyDataType`, essas funções poderão ser executadas em paralelo sem modificações adicionais.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir modifica o exemplo anterior para execução em paralelo. O algoritmo `parallel_invoke` executa cada tarefa em paralelo e retorna após a conclusão de todas as tarefas.

[!code-cpp[concrt-parallel-word-mining#2](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-execute-parallel-operations_2.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir baixa *o iLiad* by Homer de Gutenberg.org e executa várias operações nesse arquivo. O exemplo primeiro executa essas operações em série e, em seguida, executa as mesmas operações em paralelo.

[!code-cpp[concrt-parallel-word-mining#3](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-execute-parallel-operations_3.cpp)]

Este exemplo produz a seguinte saída de exemplo.

```Output
Downloading 'The Iliad'...

Running serial version... took 953 ms.
Running parallel version... took 656 ms.

The most common words that have five or more letters are:
    their (953)
    shall (444)
    which (431)
    great (398)
    Hector (349)
    Achilles (309)
    through (301)
    these (268)
    chief (259)
The longest sequence of words that have the same first letter is:
    through the tempest to the tented
The following palindromes appear in the text:
    spots stops
    speed deeps
    keels sleek
```

Este exemplo usa o algoritmo `parallel_invoke` para chamar várias funções que agem na mesma fonte de dados. Você pode usar o algoritmo `parallel_invoke` para chamar qualquer conjunto de funções em paralelo, não apenas aquelas que atuam nos mesmos dados.

Como o algoritmo de `parallel_invoke` chama cada função de trabalho em paralelo, seu desempenho é limitado pela função que leva o tempo mais longo para ser concluído (ou seja, se o tempo de execução processa cada função em um processador separado). Se este exemplo executar mais tarefas em paralelo do que o número de processadores disponíveis, várias tarefas poderão ser executadas em cada processador. Nesse caso, o desempenho é limitado pelo grupo de tarefas que leva o tempo mais longo para ser concluído.

Como este exemplo executa três tarefas em paralelo, você não deve esperar que o desempenho seja dimensionado em computadores com mais de três processadores. Para melhorar o desempenho, você pode dividir as tarefas de execução mais longa em tarefas menores e executar essas tarefas em paralelo.

Você pode usar o algoritmo `parallel_invoke` em vez das classes [Concurrency:: task_group](reference/task-group-class.md) e [concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) se não precisar de suporte para cancelamento. Para obter um exemplo que compara o uso do algoritmo de `parallel_invoke` versus grupos de tarefas, consulte [como usar parallel_invoke para gravar uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md).

## <a name="compiling-the-code"></a>Compilando o Código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `parallel-word-mining.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc/MD/DUNICODE/D_AFXDLL Parallel-Word-Mining. cpp**

## <a name="see-also"></a>Consulte também

[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)
