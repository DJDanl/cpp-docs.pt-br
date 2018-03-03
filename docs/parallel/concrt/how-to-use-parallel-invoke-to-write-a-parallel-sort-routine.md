---
title: "Como: usar parallel_invoke para escrever uma rotina de classificação paralela | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- task_handle class, example
- task_group class, example
- make_task function, example
- structured_task_group class, example
- improving parallel performance with task groups [Concurrency Runtime]
ms.assetid: 53979a2a-525d-4437-8952-f1ff85b37673
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ff14294236efc26b83d31ad185dc1cfd6329dbe9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-use-parallelinvoke-to-write-a-parallel-sort-routine"></a>Como usar parallel_invoke para escrever uma rotina de classificação em paralelo
Este documento descreve como usar o [parallel_invoke](../../parallel/concrt/parallel-algorithms.md#parallel_invoke) algoritmo para melhorar o desempenho do algoritmo de classificação bitonic. O algoritmo de classificação bitonic forma recursiva divide a sequência de entrada em menores classificadas partições. O algoritmo de classificação bitonic pode ser executados em paralelo porque cada operação de partição é independente de todas as outras operações.  
  
 Embora a classificação de bitonic é um exemplo de um *classificação rede* que classifica todas as combinações de sequências de entrada, este exemplo classifica sequências cujos tamanhos são uma potência de dois.  
  
> [!NOTE]
>  Este exemplo usa uma rotina de classificação paralelo para fins ilustrativos. Você também pode usar os algoritmos de classificação internos que fornece a PPL: [concurrency::parallel_sort](reference/concurrency-namespace-functions.md#parallel_sort), [concurrency::parallel_buffered_sort](reference/concurrency-namespace-functions.md#parallel_buffered_sort), e [concurrency::parallel_ radixsort](reference/concurrency-namespace-functions.md#parallel_radixsort). Para obter mais informações, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  
  
##  <a name="top"></a>Seções  
 Este documento descreve as seguintes tarefas:  
  
- [Execução de classificação Bitonic em série](#serial)  
  
- [Usar parallel_invoke para executar a classificação de Bitonic em paralelo](#parallel)  
  
##  <a name="serial"></a>Execução de classificação Bitonic em série  
 O exemplo a seguir mostra a versão serial do algoritmo de classificação bitonic. O `bitonic_sort` função divide a sequência em duas partições, classifica essas partições em direções opostas e, em seguida, mescla os resultados. Esta função chama a mesmo recursivamente duas vezes para classificar cada partição.  
  
 [!code-cpp[concrt-parallel-bitonic-sort#1](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_1.cpp)]  
  
 [[Superior](#top)]  
  
##  <a name="parallel"></a>Usar parallel_invoke para executar a classificação de Bitonic em paralelo  
 Esta seção descreve como usar o `parallel_invoke` algoritmo para realizar o algoritmo de classificação bitonic em paralelo.  
  
### <a name="procedures"></a>Procedimentos  
  
##### <a name="to-perform-the-bitonic-sort-algorithm-in-parallel"></a>Para realizar o algoritmo de classificação bitonic em paralelo  
  
1.  Adicionar um `#include` diretiva para o ppl.h do arquivo de cabeçalho.  
  
 [!code-cpp[concrt-parallel-bitonic-sort#10](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_2.cpp)]  
  
2.  Adicionar um `using` diretiva para o `concurrency` namespace.  
  
 [!code-cpp[concrt-parallel-bitonic-sort#11](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_3.cpp)]  
  
3.  Criar uma nova função chamada `parallel_bitonic_mege`, que usa o `parallel_invoke` algoritmo para mesclar as sequências em paralelo, se há uma quantidade suficiente de trabalho a fazer. Caso contrário, chame `bitonic_merge` para mesclar as sequências em série.  
  
 [!code-cpp[concrt-parallel-bitonic-sort#2](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_4.cpp)]  
  
4.  Executar um processo semelhante na etapa anterior, mas para o `bitonic_sort` função.  
  
 [!code-cpp[concrt-parallel-bitonic-sort#3](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_5.cpp)]  
  
5.  Criar uma versão sobrecarregada do `parallel_bitonic_sort` função que classifica a matriz em ordem crescente.  
  
 [!code-cpp[concrt-parallel-bitonic-sort#4](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_6.cpp)]  
  
 O `parallel_invoke` algoritmo reduz a sobrecarga, executando a última da série de tarefas no contexto do chamador. Por exemplo, o `parallel_bitonic_sort` função, a primeira tarefa é executado em um contexto separado, e a segunda tarefa é executada no contexto do chamador.  
  
 [!code-cpp[concrt-parallel-bitonic-sort#5](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_7.cpp)]  
  
 O exemplo completo a seguir executa as versões do algoritmo de classificação bitonic paralelas e o número de série. O exemplo também imprime no console o tempo necessário para executar cada cálculo.  
  
 [!code-cpp[concrt-parallel-bitonic-sort#8](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_8.cpp)]  
  
 A seguinte saída de exemplo é para um computador com quatro processadores.  
  
```Output  
serial time: 4353  
parallel time: 1248  
```  
  
 [[Superior](#top)]  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-bitonic-sort.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc paralelo-bitonic-sort.cpp**  
  
## <a name="robust-programming"></a>Programação robusta  
 Este exemplo usa o `parallel_invoke` algoritmo em vez do [concurrency::task_group](reference/task-group-class.md) classe porque o tempo de vida de cada grupo de tarefas não se estende além de uma função. Recomendamos que você use `parallel_invoke` quando é possível porque ela tem menos sobrecarga que a execução `task group` objetos e, portanto, permite que você escreva código melhor desempenho.  
  
 As versões paralelas de alguns algoritmos executam melhor apenas quando há trabalho suficiente para fazer. Por exemplo, o `parallel_bitonic_merge` função chama a versão serial, `bitonic_merge`, se houver elementos 500 ou menos na sequência. Você também pode planejar sua estratégia geral de classificação com base na quantidade de trabalho. Por exemplo, talvez seja mais eficiente usar a versão serial do algoritmo de classificação rápida se a matriz contém menos de 500 itens, como mostrado no exemplo a seguir:  
  
 [!code-cpp[concrt-parallel-bitonic-sort#9](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine_9.cpp)]  
  
 Assim como acontece com qualquer algoritmo em paralelo, é recomendável que você criar o perfil e ajustar seu código conforme apropriado.  
  
## <a name="see-also"></a>Consulte também  
 [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)

