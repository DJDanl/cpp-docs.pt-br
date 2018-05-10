---
title: 'Como: usar parallel_invoke para executar operações em paralelo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- parallel_invoke function, example
- calling multiple functions in parallel [Concurrency Runtime]
ms.assetid: a6aea69b-d647-4b7e-bf3b-e6a6a9880072
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 07c7a5248d5a132ae7b0542bfcedddee0c081753
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="how-to-use-parallelinvoke-to-execute-parallel-operations"></a>Como usar parallel_invoke para executar operações em paralelo
Este exemplo mostra como usar o [concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo para melhorar o desempenho de um programa que executa várias operações em uma fonte de dados compartilhada. Como nenhuma operação modificar a fonte, eles podem ser executados em paralelo de uma maneira simples.  

  
## <a name="example"></a>Exemplo  
 Considere o seguinte exemplo de código que cria uma variável de tipo `MyDataType`, chama uma função para inicializar essa variável e, em seguida, executa várias operações longas nesses dados.  
  
 [!code-cpp[concrt-parallel-word-mining#1](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-execute-parallel-operations_1.cpp)]  
  
 Se o `lengthy_operation1`, `lengthy_operation2`, e `lengthy_operation3` funções não modifiquem o `MyDataType` variável, essas funções podem ser executadas em paralelo sem modificações adicionais.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir modifica o exemplo anterior para executar em paralelo. O `parallel_invoke` algoritmo executa cada tarefa em paralelo e retorna depois que todas as tarefas são concluídas.  
  
 [!code-cpp[concrt-parallel-word-mining#2](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-execute-parallel-operations_2.cpp)]  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir baixa *Ilíada o* por Homer de gutenberg.org e executa várias operações nesse arquivo. O exemplo primeiro executa essas operações em série e, em seguida, executa as mesmas operações em paralelo.  
  
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
  
 Este exemplo usa o `parallel_invoke` algoritmo para chamar várias funções que atuam na mesma fonte de dados. Você pode usar o `parallel_invoke` algoritmo chamar qualquer conjunto de funções em paralelo, não apenas aqueles que atuam sobre os mesmos dados.  
  
 Porque o `parallel_invoke` algoritmo chama cada função de trabalho em paralelo, o desempenho é limitado pela função que usa o tempo mais longo para terminar (ou seja, se o tempo de execução processa cada função em um processador separado). Se este exemplo executa mais tarefas em paralelo que o número de processadores disponíveis, várias tarefas podem executar em cada processador. Nesse caso, o desempenho é limitado pelo grupo de tarefas que demora mais para concluir.  
  
 Como este exemplo executa três tarefas em paralelo, você não deve esperar um desempenho dimensionar em computadores com processadores mais de três. Para melhorar o desempenho mais, você pode dividir as tarefas de execução mais longa em tarefas menores e executar as tarefas em paralelo.  
  
 Você pode usar o `parallel_invoke` algoritmo em vez do [concurrency::task_group](reference/task-group-class.md) e [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) classes se não precisar de suporte para cancelamento. Para obter um exemplo que compara o uso do `parallel_invoke` algoritmo em vez de grupos de tarefas, consulte [como: usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md).  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-word-mining.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc /MD//D_AFXDLL tempo paralelo word mining.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)   
 [Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)


