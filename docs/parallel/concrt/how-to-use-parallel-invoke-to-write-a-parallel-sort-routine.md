---
title: 'Como: Usar parallel_invoke para escrever uma rotina de classificação paralela'
ms.date: 11/04/2016
helpviewer_keywords:
- task_handle class, example
- task_group class, example
- make_task function, example
- structured_task_group class, example
- improving parallel performance with task groups [Concurrency Runtime]
ms.assetid: 53979a2a-525d-4437-8952-f1ff85b37673
ms.openlocfilehash: 329cf275f283ba7b57276d06e909905c9a900697
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57284171"
---
# <a name="how-to-use-parallelinvoke-to-write-a-parallel-sort-routine"></a>Como: Usar parallel_invoke para escrever uma rotina de classificação paralela

Este documento descreve como usar o [parallel_invoke](../../parallel/concrt/parallel-algorithms.md#parallel_invoke) algoritmo para melhorar o desempenho do algoritmo de classificação bitonic. Recursivamente o algoritmo de classificação bitonic divide a sequência de entrada em partições menores de classificados. O algoritmo de classificação bitonic pode executar em paralelo, porque cada operação de partição é independente de todas as outras operações.

Embora a classificação bitonic é um exemplo de uma *classificação rede* que classifica todas as combinações de sequências de entrada, este exemplo classifica sequências cujos comprimentos são uma potência de dois.

> [!NOTE]
>  Este exemplo usa uma rotina de classificação paralela para fins ilustrativos. Você também pode usar os algoritmos de classificação internos que fornece a PPL: [concurrency::parallel_sort](reference/concurrency-namespace-functions.md#parallel_sort), [concurrency::parallel_buffered_sort](reference/concurrency-namespace-functions.md#parallel_buffered_sort), e [concurrency::parallel_ radixsort](reference/concurrency-namespace-functions.md#parallel_radixsort). Para obter mais informações, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

##  <a name="top"></a> Seções

Este documento descreve as seguintes tarefas:

- [Realizando classificação Bitonic em série](#serial)

- [Usando parallel_invoke para realizar classificação Bitonic em paralelo](#parallel)

##  <a name="serial"></a> Realizando classificação Bitonic em série

O exemplo a seguir mostra a versão serial do algoritmo de classificação bitonic. O `bitonic_sort` função divide a sequência em duas partições, classifica essas partições em direções opostas e, em seguida, mescla os resultados. Essa função chama a mesmo recursivamente duas vezes para classificar cada partição.

[!code-cpp[concrt-parallel-bitonic-sort#1](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_1.cpp)]

[[Top](#top)]

##  <a name="parallel"></a> Usando parallel_invoke para realizar classificação Bitonic em paralelo

Esta seção descreve como usar o `parallel_invoke` algoritmo para realizar o algoritmo de classificação bitonic em paralelo.

### <a name="procedures"></a>Procedimentos

##### <a name="to-perform-the-bitonic-sort-algorithm-in-parallel"></a>Para realizar o algoritmo de classificação bitonic em paralelo

1. Adicionar um `#include` diretiva para o ppl.h do arquivo de cabeçalho.

[!code-cpp[concrt-parallel-bitonic-sort#10](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_2.cpp)]

1. Adicionar um `using` diretiva para o `concurrency` namespace.

[!code-cpp[concrt-parallel-bitonic-sort#11](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_3.cpp)]

1. Criar uma nova função chamada `parallel_bitonic_mege`, que usa o `parallel_invoke` algoritmo para mesclar as sequências em paralelo, se houver uma quantidade suficiente de trabalho a fazer. Caso contrário, chame `bitonic_merge` para mesclar as sequências em série.

[!code-cpp[concrt-parallel-bitonic-sort#2](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_4.cpp)]

1. Executar um processo semelhante na etapa anterior, mas para o `bitonic_sort` função.

[!code-cpp[concrt-parallel-bitonic-sort#3](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_5.cpp)]

1. Criar uma versão sobrecarregada do `parallel_bitonic_sort` função que classifica a matriz em ordem crescente.

[!code-cpp[concrt-parallel-bitonic-sort#4](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_6.cpp)]

O `parallel_invoke` algoritmo reduz a sobrecarga, executando o último da série de tarefas no contexto de chamada. Por exemplo, no `parallel_bitonic_sort` função, a primeira tarefa é executado em um contexto separado e a segunda tarefa é executada no contexto de chamada.

[!code-cpp[concrt-parallel-bitonic-sort#5](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_7.cpp)]

O exemplo completo a seguir executa o número de série e as versões paralelas do algoritmo de classificação bitonic. O exemplo também imprime no console o tempo necessário para executar cada cálculo.

[!code-cpp[concrt-parallel-bitonic-sort#8](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_8.cpp)]

A saída de exemplo a seguir é para um computador com quatro processadores.

```Output
serial time: 4353
parallel time: 1248
```

[[Top](#top)]

## <a name="compiling-the-code"></a>Compilando o código

Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-bitonic-sort.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc parallel-bitonic-sort.cpp**

## <a name="robust-programming"></a>Programação robusta

Este exemplo usa o `parallel_invoke` algoritmo em vez do [Concurrency:: task_group](reference/task-group-class.md) porque o tempo de vida de cada grupo de tarefas não se estende além de uma função de classe. É recomendável que você use `parallel_invoke` quando é possível porque ela tem menos sobrecarga da execução `task group` objetos e, portanto, permite que você escreva código de melhor desempenho.

As versões paralelas dos alguns algoritmos executam melhor apenas quando há trabalho suficiente para fazer. Por exemplo, o `parallel_bitonic_merge` função chama a versão serial, `bitonic_merge`, se houver 500 ou menos elementos na sequência. Você também pode planejar sua estratégia geral de classificação com base na quantidade de trabalho. Por exemplo, talvez seja mais eficiente usar a versão serial do algoritmo de classificação rápida de se a matriz contiver menos de 500 itens, conforme mostrado no exemplo a seguir:

[!code-cpp[concrt-parallel-bitonic-sort#9](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_9.cpp)]

Assim como acontece com qualquer algoritmo paralelo, recomendamos que você criar o perfil e ajustar seu código conforme apropriado.

## <a name="see-also"></a>Consulte também

[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)
