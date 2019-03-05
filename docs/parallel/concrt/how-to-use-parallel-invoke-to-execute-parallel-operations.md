---
title: 'Como: Usar parallel_invoke para executar operações em paralelo'
ms.date: 11/04/2016
helpviewer_keywords:
- parallel_invoke function, example
- calling multiple functions in parallel [Concurrency Runtime]
ms.assetid: a6aea69b-d647-4b7e-bf3b-e6a6a9880072
ms.openlocfilehash: d618b5f202c6aaf454a60f4f37211d9000600562
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57293518"
---
# <a name="how-to-use-parallelinvoke-to-execute-parallel-operations"></a>Como: Usar parallel_invoke para executar operações em paralelo

Este exemplo mostra como usar o [Concurrency:: parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo para melhorar o desempenho de um programa que executa várias operações em uma fonte de dados compartilhada. Como nenhuma operação de modificar o código-fonte, podem ser executadas em paralelo de uma maneira simples.

## <a name="example"></a>Exemplo

Considere o seguinte exemplo de código que cria uma variável do tipo `MyDataType`, chama uma função para inicializar essa variável e, em seguida, executa várias operações demoradas nesses dados.

[!code-cpp[concrt-parallel-word-mining#1](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-execute-parallel-operations_1.cpp)]

Se o `lengthy_operation1`, `lengthy_operation2`, e `lengthy_operation3` funções não modificam o `MyDataType` variável, essas funções podem ser executadas em paralelo sem modificações adicionais.

## <a name="example"></a>Exemplo

O exemplo a seguir modifica o exemplo anterior para executar em paralelo. O `parallel_invoke` algoritmo executa cada tarefa em paralelo e retorna depois que todas as tarefas são concluídas.

[!code-cpp[concrt-parallel-word-mining#2](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-execute-parallel-operations_2.cpp)]

## <a name="example"></a>Exemplo

O exemplo a seguir baixa *a Ilíada* por Homero de gutenberg.org e executa várias operações nesse arquivo. O exemplo primeiro executa essas operações em série e, em seguida, executa as mesmas operações em paralelo.

[!code-cpp[concrt-parallel-word-mining#3](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-execute-parallel-operations_3.cpp)]

Este exemplo produz a saída de exemplo a seguir.

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

Este exemplo usa o `parallel_invoke` algoritmo para chamar várias funções que atuam na mesma fonte de dados. Você pode usar o `parallel_invoke` algoritmo para chamar qualquer conjunto de funções em paralelo, não apenas aquelas que atuam nos mesmos dados.

Porque o `parallel_invoke` algoritmo chama cada função de trabalho em paralelo, seu desempenho é limitado pela função que leva mais tempo para concluir (ou seja, se o tempo de execução processa cada função em um processador separado). Se este exemplo executa mais tarefas em paralelo que o número de processadores disponíveis, várias tarefas podem executar em cada processador. Nesse caso, o desempenho é limitado pelo grupo de tarefas que leva mais tempo para concluir.

Como este exemplo realiza três tarefas em paralelo, você não deve esperar desempenho dimensionar em computadores com processadores mais de três. Para melhorar o desempenho mais, você pode dividir as tarefas de execução mais longa em tarefas menores e executar essas tarefas em paralelo.

Você pode usar o `parallel_invoke` algoritmo em vez do [Concurrency:: task_group](reference/task-group-class.md) e [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) classes se você não precisar de suporte para cancelamento. Para obter um exemplo que compara o uso do `parallel_invoke` algoritmo em comparação com grupos de tarefas, consulte [como: Usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md).

## <a name="compiling-the-code"></a>Compilando o código

Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-word-mining.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc /MD/DUNICODE /D_AFXDLL paralelo word mining.cpp**

## <a name="see-also"></a>Consulte também

[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)
