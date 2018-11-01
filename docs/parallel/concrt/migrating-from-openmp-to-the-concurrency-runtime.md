---
title: Migrando de OpenMP no Tempo de Execução de Simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- Concurrency Runtime, migrating from OpenMP
- OpenMP, migrating to the Concurrency Runtime
ms.assetid: 9bab7bb1-e45d-44b2-8509-3b226be2c93b
ms.openlocfilehash: 4b70aa57a6485fefe0dbb678e72ba127502c89e3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50481920"
---
# <a name="migrating-from-openmp-to-the-concurrency-runtime"></a>Migrando de OpenMP no Tempo de Execução de Simultaneidade

O tempo de execução de simultaneidade permite que uma variedade de modelos de programação. Esses modelos podem se sobrepor ou complementar os modelos de outras bibliotecas. Os documentos desta seção compare [OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp) no tempo de execução de simultaneidade e fornecem exemplos sobre como migrar o código de OpenMP existente para usar o tempo de execução de simultaneidade.

O modelo de programação OpenMP é definido por um padrão aberto e tem associações bem definidas para as linguagens de programação Fortran e C/C++. Versões de OpenMP 2.0 e 2.5, que são suportadas pelo compilador Visual C++, são bem adequadas para algoritmos paralelos são iterativos; ou seja, eles executam a iteração paralela em uma matriz de dados. OpenMP 3.0 oferece suporte a tarefas não iterativo, além das tarefas iterativas.

OpenMP é mais eficiente quando o grau de paralelismo é predeterminado e corresponde os recursos disponíveis no sistema. O modelo de OpenMP é uma correspondência especialmente bons para computação de alto desempenho, em que grandes problemas computacionais são distribuídos entre os recursos de processamento de um computador. Nesse cenário, o ambiente de hardware geralmente é fixo e o desenvolvedor razoável pode esperar ter acesso exclusivo para todos os recursos de computação quando o algoritmo é executado.

No entanto, menos restrito ambientes de computação pode não ser uma boa correspondência para OpenMP. Por exemplo, problemas de recursiva (como o algoritmo quicksort ou pesquisar uma árvore de dados) são mais difíceis de implementar usando OpenMP 2.0 e 2.5. O tempo de execução de simultaneidade complementa os recursos do OpenMP, fornecendo o [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) e o [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) (PPL). A biblioteca de agentes assíncrona suporta paralelismo de tarefas de alta granularidade; o PPL dá suporte a mais tarefas paralelas refinadas. O tempo de execução de simultaneidade fornece a infraestrutura necessária para executar operações em paralelo para que você possa se concentrar na lógica do seu aplicativo. No entanto, como o tempo de execução de simultaneidade permite que uma variedade de modelos de programação, sobrecarga de seu agendamento pode ser maior do que outras bibliotecas de simultaneidade, como OpenMP. Portanto, é recomendável que você teste incrementalmente desempenho quando você converte seu código existente do OpenMP para usar o tempo de execução de simultaneidade.

## <a name="when-to-migrate-from-openmp-to-the-concurrency-runtime"></a>Quando migrar de OpenMP no tempo de execução de simultaneidade

Ele pode ser vantajoso para migrar o código de OpenMP existente para usar o tempo de execução de simultaneidade nos seguintes casos.

|Casos|Vantagens do tempo de execução de simultaneidade|
|-----------|-------------------------------------------|
|Você precisa de uma estrutura extensível da programação simultânea.|Muitos dos recursos no tempo de execução de simultaneidade podem ser estendidos. Você também pode combinar os recursos existentes para redigir novas marcas. Como OpenMP depende de diretivas de compilador, ele não pode ser estendido facilmente.|
|Seu aplicativo pode se beneficiar do bloqueio cooperativo.|Quando uma tarefa for bloqueado porque ele requer um recurso que ainda não está disponível, o tempo de execução de simultaneidade podem executar outras tarefas enquanto a primeira tarefa aguarda o recurso.|
|Seu aplicativo pode se beneficiar do balanceamento de carga dinâmica.|O tempo de execução de simultaneidade usa um algoritmo de agendamento que ajusta a alocação de recursos de computação conforme as cargas de trabalho mudam. OpenMP, quando o Agendador aloca recursos de computação para uma região parallel, essas alocações de recursos são fixas durante o cálculo.|
|Você precisar de suporte de manipulação de exceção.|O PPL permite capturar exceções dentro e fora de um loop ou uma região paralela. O OpenMP, você deve lidar com a exceção dentro do loop ou região paralela.|
|Você precisa de um mecanismo de cancelamento.|O PPL permite que os aplicativos cancelar as tarefas individuais e paralelas árvores de trabalho. OpenMP requer que o aplicativo implementar seu próprio mecanismo de cancelamento.|
|Exigir o código paralelo para terminar em um contexto diferente do qual ele é iniciado.|O tempo de execução de simultaneidade permite que você iniciar uma tarefa em um contexto e, em seguida, aguardar ou cancelar a tarefa em outro contexto. O OpenMP, todo o trabalho paralelo deve terminar no contexto do qual ele é iniciado.|
|Exigir o suporte avançado a depuração.|O Visual Studio fornece o **pilhas paralelas** e **tarefas paralelas** windows para que você pode depurar mais facilmente aplicativos multithread.<br /><br /> Para obter mais informações sobre a depuração de suporte para o tempo de execução de simultaneidade, consulte [usando a janela tarefas](/visualstudio/debugger/using-the-tasks-window), [usando a janela Parallel Stacks](/visualstudio/debugger/using-the-parallel-stacks-window), e [passo a passo: depurando um paralelo Aplicativo](/visualstudio/debugger/walkthrough-debugging-a-parallel-application).|

## <a name="when-not-to-migrate-from-openmp-to-the-concurrency-runtime"></a>Quando não migrar do OpenMP no tempo de execução de simultaneidade

Os casos a seguir descrevem quando pode não ser apropriado migrar o código de OpenMP existente para usar o tempo de execução de simultaneidade.

|Casos|Explicação|
|-----------|-----------------|
|Seu aplicativo já atende às suas necessidades.|Se você estiver satisfeito com o desempenho do aplicativo e o suporte de depuração atual, migração pode não ser apropriada.|
|Seus corpos de loop paralelo executam pouco trabalho.|A sobrecarga do Agendador de tarefas de tempo de execução de simultaneidade não pode superar os benefícios de executar o corpo do loop em paralelo, especialmente quando o corpo do loop é relativamente pequeno.|
|Seu aplicativo é escrito em C.|Como o tempo de execução de simultaneidade usa muitos recursos do C++, ele pode não ser adequado quando você não pode gravar código que permite que o aplicativo C totalmente usá-lo.|

## <a name="related-topics"></a>Tópicos relacionados

[Como converter um loop OpenMP paralelo para loop para usar o tempo de execução de simultaneidade](../../parallel/concrt/how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime.md)

Dado um loop básico que usa o OpenMP [paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel) e [para](../../parallel/openmp/reference/for-openmp.md) diretivas, demonstra como convertê-lo para usar o tempo de execução de simultaneidade [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo.

[Como converter um loop OpenMP que usa cancelamento para usar o tempo de execução de simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that-uses-cancellation.md)<br/>
Dado um OpenMP [paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../../parallel/openmp/reference/for-openmp.md) loop que não exige que todas as iterações para executar, demonstra como convertê-lo para usar o mecanismo de cancelamento de tempo de execução de simultaneidade.

[Como converter um loop OpenMP que usa tratamento de exceções para usar o tempo de execução de simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that uses-exception-handling.md)<br/>
Dado um OpenMP [paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../../parallel/openmp/reference/for-openmp.md) loop que executa o tratamento de exceções, demonstra como convertê-lo para usar o mecanismo de tratamento de exceções de tempo de execução de simultaneidade.

[Como converter um loop OpenMP que usa uma variável de redução para usar o tempo de execução de simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that-uses-a-reduction-variable.md)<br/>
Dado um OpenMP [paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../../parallel/openmp/reference/for-openmp.md) loop que usa o [redução](../../parallel/openmp/reference/reduction.md) cláusula, demonstra como convertê-lo para usar o tempo de execução de simultaneidade.

## <a name="see-also"></a>Consulte também

[Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)<br/>
[OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp)<br/>
[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)<br/>
[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)

