---
title: Como usar parallel_invoke para executar operações em paralelo
ms.date: 11/04/2016
helpviewer_keywords:
- parallel_invoke function, example
- calling multiple functions in parallel [Concurrency Runtime]
ms.assetid: a6aea69b-d647-4b7e-bf3b-e6a6a9880072
ms.openlocfilehash: 62781b2915704c4104bd7e8a13e48e43d81955c6
ms.sourcegitcommit: 43cee7a0d41a062661229043c2f7cbc6ace17fa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/13/2020
ms.locfileid: "92008336"
---
# <a name="how-to-use-parallel_invoke-to-execute-parallel-operations"></a>Como usar parallel_invoke para executar operações em paralelo

Este exemplo mostra como usar o algoritmo [Concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) para melhorar o desempenho de um programa que executa várias operações em uma fonte de dados compartilhada. Como nenhuma operação modifica a origem, elas podem ser executadas em paralelo de maneira simples.

## <a name="example-create-initialize-and-perform-operations-on-a-variable"></a>Exemplo: criar, inicializar e executar operações em uma variável

Considere o exemplo de código a seguir que cria uma variável do tipo `MyDataType` , chama uma função para inicializar essa variável e, em seguida, executa várias operações demoradas nesses dados.

[!code-cpp[concrt-parallel-word-mining#1](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-execute-parallel-operations_1.cpp)]

Se as `lengthy_operation1` `lengthy_operation2` funções, e `lengthy_operation3` não modificarem a `MyDataType` variável, essas funções poderão ser executadas em paralelo sem modificações adicionais.

## <a name="example-run-previous-example-in-parallel"></a>Exemplo: executar o exemplo anterior em paralelo

O exemplo a seguir modifica o exemplo anterior para execução em paralelo. O `parallel_invoke` algoritmo executa cada tarefa em paralelo e retorna depois que todas as tarefas são concluídas.

[!code-cpp[concrt-parallel-word-mining#2](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-execute-parallel-operations_2.cpp)]

## <a name="example-perform-multiple-operations-on-a-downloaded-file"></a>Exemplo: executar várias operações em um arquivo baixado

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

Este exemplo usa o `parallel_invoke` algoritmo para chamar várias funções que agem na mesma fonte de dados. Você pode usar o `parallel_invoke` algoritmo para chamar qualquer conjunto de funções em paralelo, não apenas aquelas que atuam nos mesmos dados.

Como o `parallel_invoke` algoritmo chama cada função de trabalho em paralelo, seu desempenho é limitado pela função que leva o tempo mais longo para ser concluído (ou seja, se o tempo de execução processa cada função em um processador separado). Se este exemplo executar mais tarefas em paralelo do que o número de processadores disponíveis, várias tarefas poderão ser executadas em cada processador. Nesse caso, o desempenho é limitado pelo grupo de tarefas que leva o tempo mais longo para ser concluído.

Como este exemplo executa três tarefas em paralelo, você não deve esperar que o desempenho seja dimensionado em computadores com mais de três processadores. Para melhorar o desempenho, você pode dividir as tarefas de execução mais longa em tarefas menores e executar essas tarefas em paralelo.

Você pode usar o `parallel_invoke` algoritmo em vez das classes [Concurrency:: task_group](reference/task-group-class.md) e [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) se não precisar de suporte para cancelamento. Para obter um exemplo que compara o uso do `parallel_invoke` algoritmo em relação aos grupos de tarefas, consulte [como: usar Parallel_invoke para gravar uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md).

## <a name="compiling-the-code"></a>Compilando o código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `parallel-word-mining.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc/MD/DUNICODE/D_AFXDLL Parallel-Word-Mining. cpp**

## <a name="see-also"></a>Veja também

[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)
