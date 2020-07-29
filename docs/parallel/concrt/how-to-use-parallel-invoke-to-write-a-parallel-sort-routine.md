---
title: Como usar parallel_invoke para escrever uma rotina de classificação em paralelo
ms.date: 11/04/2016
helpviewer_keywords:
- task_handle class, example
- task_group class, example
- make_task function, example
- structured_task_group class, example
- improving parallel performance with task groups [Concurrency Runtime]
ms.assetid: 53979a2a-525d-4437-8952-f1ff85b37673
ms.openlocfilehash: 9d84cdbecb7cc6d39cb30077780c558db85888c0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222713"
---
# <a name="how-to-use-parallel_invoke-to-write-a-parallel-sort-routine"></a>Como usar parallel_invoke para escrever uma rotina de classificação em paralelo

Este documento descreve como usar o algoritmo [parallel_invoke](../../parallel/concrt/parallel-algorithms.md#parallel_invoke) para melhorar o desempenho do algoritmo de classificação bitônico. O algoritmo de classificação bitônico divide recursivamente a sequência de entrada em partições pequenas classificadas. O algoritmo de classificação bitônico pode ser executado em paralelo porque cada operação de partição é independente de todas as outras operações.

Embora a classificação de bitônico seja um exemplo de uma *rede de classificação* que classifica todas as combinações de sequências de entrada, este exemplo classifica as sequências cujos comprimentos são uma potência de dois.

> [!NOTE]
> Este exemplo usa uma rotina de classificação paralela para ilustração. Você também pode usar os algoritmos de classificação internos que a PPL fornece: [simultaneidade::p arallel_sort](reference/concurrency-namespace-functions.md#parallel_sort), [concurrency::p arallel_buffered_sort](reference/concurrency-namespace-functions.md#parallel_buffered_sort)e [Concurrency::p arallel_radixsort](reference/concurrency-namespace-functions.md#parallel_radixsort). Para obter mais informações, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="sections"></a><a name="top"></a>As

Este documento descreve as seguintes tarefas:

- [Realizando Classificação Bitonic em Série](#serial)

- [Usando parallel_invoke para Realizar Classificação Bitonic em Paralelo](#parallel)

## <a name="performing-bitonic-sort-serially"></a><a name="serial"></a>Executando o bitônico classificar em série

O exemplo a seguir mostra a versão serial do algoritmo de classificação bitônico. A `bitonic_sort` função divide a sequência em duas partições, classifica essas partições em direções opostas e, em seguida, mescla os resultados. Essa função chama-se duas vezes recursivamente para classificar cada partição.

[!code-cpp[concrt-parallel-bitonic-sort#1](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_1.cpp)]

[[Superior](#top)]

## <a name="using-parallel_invoke-to-perform-bitonic-sort-in-parallel"></a><a name="parallel"></a>Usando parallel_invoke para executar a classificação bitônico em paralelo

Esta seção descreve como usar o `parallel_invoke` algoritmo para executar o algoritmo de classificação bitônico em paralelo.

### <a name="to-perform-the-bitonic-sort-algorithm-in-parallel"></a>Para realizar o algoritmo de classificação bitonic em paralelo

1. Adicione uma `#include` diretiva para o arquivo de cabeçalho ppl. h.

[!code-cpp[concrt-parallel-bitonic-sort#10](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_2.cpp)]

1. Adicione uma **`using`** diretiva para o `concurrency` namespace.

[!code-cpp[concrt-parallel-bitonic-sort#11](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_3.cpp)]

1. Crie uma nova função, chamada `parallel_bitonic_mege` , que usa o `parallel_invoke` algoritmo para mesclar as sequências em paralelo se houver quantidade suficiente de trabalho a fazer. Caso contrário, chame `bitonic_merge` para mesclar as sequências em série.

[!code-cpp[concrt-parallel-bitonic-sort#2](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_4.cpp)]

1. Execute um processo que se assemelha a um na etapa anterior, mas para a `bitonic_sort` função.

[!code-cpp[concrt-parallel-bitonic-sort#3](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_5.cpp)]

1. Crie uma versão sobrecarregada da `parallel_bitonic_sort` função que classifica a matriz em ordem crescente.

[!code-cpp[concrt-parallel-bitonic-sort#4](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_6.cpp)]

O `parallel_invoke` algoritmo reduz a sobrecarga executando a última série de tarefas no contexto de chamada. Por exemplo, na `parallel_bitonic_sort` função, a primeira tarefa é executada em um contexto separado e a segunda tarefa é executada no contexto de chamada.

[!code-cpp[concrt-parallel-bitonic-sort#5](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_7.cpp)]

O exemplo completo a seguir executa as versões serial e paralela do algoritmo de classificação bitônico. O exemplo também imprime no console o tempo necessário para executar cada computação.

[!code-cpp[concrt-parallel-bitonic-sort#8](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_8.cpp)]

A saída de exemplo a seguir é para um computador com quatro processadores.

```Output
serial time: 4353
parallel time: 1248
```

[[Superior](#top)]

### <a name="compiling-the-code"></a>Compilando o código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `parallel-bitonic-sort.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc Parallel-bitonic-Sort. cpp**

## <a name="robust-programming"></a>Programação robusta

Este exemplo usa o `parallel_invoke` algoritmo em vez da classe [Concurrency:: task_group](reference/task-group-class.md) porque o tempo de vida de cada grupo de tarefas não se estende além de uma função. Recomendamos que você use `parallel_invoke` quando puder porque ela tem menos sobrecarga de execução que `task group` objetos e, portanto, permite escrever um código de melhor desempenho.

As versões paralelas de alguns algoritmos têm melhor desempenho somente quando há um trabalho suficiente para fazer. Por exemplo, a `parallel_bitonic_merge` função chama a versão serial, `bitonic_merge` , se houver 500 ou menos elementos na sequência. Você também pode planejar sua estratégia de classificação geral com base na quantidade de trabalho. Por exemplo, pode ser mais eficiente usar a versão serial do algoritmo de classificação rápida se a matriz contiver menos de 500 itens, conforme mostrado no exemplo a seguir:

[!code-cpp[concrt-parallel-bitonic-sort#9](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_9.cpp)]

Assim como ocorre com qualquer algoritmo paralelo, é recomendável que você perfile e ajuste seu código conforme apropriado.

## <a name="see-also"></a>Confira também

[Paralelismo de Tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)
