---
title: Migrando de OpenMP no Runtime de Simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- Concurrency Runtime, migrating from OpenMP
- OpenMP, migrating to the Concurrency Runtime
ms.assetid: 9bab7bb1-e45d-44b2-8509-3b226be2c93b
ms.openlocfilehash: 081d0ae8b312d827a0af98dd45c62f7563e81677
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91507761"
---
# <a name="migrating-from-openmp-to-the-concurrency-runtime"></a>Migrando de OpenMP no Runtime de Simultaneidade

O Tempo de Execução de Simultaneidade permite uma variedade de modelos de programação. Esses modelos podem sobrepor ou complementar os modelos de outras bibliotecas. Os documentos nesta seção comparam [OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp) com o tempo de execução de simultaneidade e fornecem exemplos de como migrar o código de OpenMP existente para usar o tempo de execução de simultaneidade.

O modelo de programação de OpenMP é definido por um padrão aberto e tem associações bem definidas para as linguagens de programação Fortran e C/C++. As versões de OpenMP 2,0 e 2,5, que têm suporte do compilador do Microsoft C++, são adequadas para algoritmos paralelos que são iterativos; ou seja, eles executam iteração paralela em uma matriz de dados. O OpenMP 3,0 dá suporte a tarefas não iterativas além das tarefas iterativas.

O OpenMP é mais eficiente quando o grau de paralelismo é predeterminado e corresponde aos recursos disponíveis no sistema. O modelo de OpenMP é uma correspondência especialmente boa para computação de alto desempenho, em que problemas computacionais muito grandes são distribuídos entre os recursos de processamento de um computador. Nesse cenário, o ambiente de hardware geralmente é corrigido e o desenvolvedor pode esperar ter acesso exclusivo a todos os recursos de computação quando o algoritmo é executado.

No entanto, ambientes de computação menos restritos podem não ser uma boa correspondência para OpenMP. Por exemplo, problemas recursivos (como o algoritmo quicksort ou a pesquisa de uma árvore de dados) são mais difíceis de implementar usando OpenMP 2,0 e 2,5. O Tempo de Execução de Simultaneidade complementa os recursos de OpenMP fornecendo a biblioteca de [agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) e a PPL ( [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) ). A biblioteca de agentes assíncronos dá suporte ao paralelismo de tarefas de alta granularidade; a PPL dá suporte a tarefas paralelas mais refinadas. O Tempo de Execução de Simultaneidade fornece a infraestrutura necessária para executar operações em paralelo para que você possa se concentrar na lógica do seu aplicativo. No entanto, como o Tempo de Execução de Simultaneidade permite uma variedade de modelos de programação, sua sobrecarga de agendamento pode ser maior do que outras bibliotecas de simultaneidade, como OpenMP. Portanto, recomendamos que você teste o desempenho incrementalmente ao converter seu código de OpenMP existente para usar o Tempo de Execução de Simultaneidade.

## <a name="when-to-migrate-from-openmp-to-the-concurrency-runtime"></a>Quando migrar de OpenMP para o Tempo de Execução de Simultaneidade

Pode ser vantajoso migrar o código de OpenMP existente para usar o Tempo de Execução de Simultaneidade nos casos a seguir.

|Casos|Vantagens do Tempo de Execução de Simultaneidade|
|-----------|-------------------------------------------|
|Você precisa de uma estrutura de programação simultânea extensível.|Muitos dos recursos do Tempo de Execução de Simultaneidade podem ser estendidos. Você também pode combinar recursos existentes para compor novos. Como o OpenMP se baseia em diretivas de compilador, ele não pode ser facilmente estendido.|
|Seu aplicativo se beneficiaria do bloqueio cooperativo.|Quando uma tarefa é bloqueada porque requer um recurso que ainda não está disponível, o Tempo de Execução de Simultaneidade pode executar outras tarefas enquanto a primeira tarefa aguarda o recurso.|
|Seu aplicativo se beneficiaria do balanceamento de carga dinâmico.|O Tempo de Execução de Simultaneidade usa um algoritmo de agendamento que ajusta a alocação de recursos de computação à medida que as cargas de trabalho mudam. No OpenMP, quando o Agendador aloca recursos de computação para uma região paralela, essas alocações de recursos são corrigidas em todo o cálculo.|
|Você precisa de suporte para tratamento de exceções.|A PPL permite que você capture exceções dentro e fora de uma região paralela ou loop. No OpenMP, você deve tratar a exceção dentro da região paralela ou loop.|
|Você precisa de um mecanismo de cancelamento.|A PPL permite que os aplicativos cancelem as tarefas individuais e as árvores paralelas de trabalho. O OpenMP requer que o aplicativo implemente seu próprio mecanismo de cancelamento.|
|Você precisa que o código paralelo seja concluído em um contexto diferente do qual ele é iniciado.|O Tempo de Execução de Simultaneidade permite que você inicie uma tarefa em um contexto e aguarde ou cancele essa tarefa em outro contexto. No OpenMP, todo trabalho paralelo deve ser concluído no contexto do qual ele é iniciado.|
|Você precisa de suporte à depuração avançada.|O Visual Studio fornece as janelas de **pilhas paralelas** e de **tarefas paralelas** para que você possa depurar aplicativos multithread mais facilmente.<br /><br /> Para obter mais informações sobre o suporte à depuração para o Tempo de Execução de Simultaneidade, consulte [usando a janela tarefas](/visualstudio/debugger/using-the-tasks-window), [usando a janela pilhas paralelas](/visualstudio/debugger/using-the-parallel-stacks-window)e [passo a passos: Depurando um aplicativo paralelo](/visualstudio/debugger/walkthrough-debugging-a-parallel-application).|

## <a name="when-not-to-migrate-from-openmp-to-the-concurrency-runtime"></a>Quando não migrar de OpenMP para o Tempo de Execução de Simultaneidade

Os casos a seguir descrevem quando talvez não seja apropriado migrar o código de OpenMP existente para usar o Tempo de Execução de Simultaneidade.

|Casos|Explicação|
|-----------|-----------------|
|Seu aplicativo já atende aos seus requisitos.|Se você estiver satisfeito com o desempenho do aplicativo e com o suporte à depuração atual, a migração poderá não ser apropriada.|
|Seus corpos de loop paralelos executam pouco trabalho.|A sobrecarga do Agendador de tarefas Tempo de Execução de Simultaneidade pode não superar os benefícios de executar o corpo do loop em paralelo, especialmente quando o corpo do loop é relativamente pequeno.|
|Seu aplicativo é escrito em C.|Como o Tempo de Execução de Simultaneidade usa muitos recursos do C++, ele pode não ser adequado quando você não pode escrever código que permita que o aplicativo C o use totalmente.|

## <a name="related-topics"></a>Tópicos relacionados

[Como converter um loop de OpenMP paralelo para usar o Tempo de Execução de Simultaneidade](../../parallel/concrt/how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime.md)

Dado um loop básico que usa [as diretivas de](../openmp/reference/openmp-directives.md#for-openmp) OpenMP e [Parallel](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel) , demonstra como convertê-lo para usar o algoritmo de arallel_for de simultaneidade de tempo de execução de simultaneidade [::p](reference/concurrency-namespace-functions.md#parallel_for) .

[Como converter um loop de OpenMP que usa o cancelamento para usar o Tempo de Execução de Simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that-uses-cancellation.md)<br/>
Dado um loop de OpenMP [paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[for](../openmp/reference/openmp-directives.md#for-openmp) que não requer a execução de todas as iterações, demonstra como convertê-lo para usar o tempo de execução de simultaneidade mecanismo de cancelamento.

[Como converter um loop de OpenMP que usa o tratamento de exceções para usar o Tempo de Execução de Simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that-uses-exception-handling.md)<br/>
Dado um loop [parallel](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[de OpenMP de](../openmp/reference/openmp-directives.md#for-openmp) uso paralelo que executa a manipulação de exceção, demonstra como convertê-lo para usar o tempo de execução de simultaneidade mecanismo de manipulação de exceção.

[Como converter um loop de OpenMP que usa uma variável de redução para usar o Tempo de Execução de Simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that-uses-a-reduction-variable.md)<br/>
Dado um loop de OpenMP [paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../openmp/reference/openmp-directives.md#for-openmp) que usa a cláusula de [redução](../openmp/reference/openmp-clauses.md#reduction) , demonstra como convertê-lo para usar o tempo de execução de simultaneidade.

## <a name="see-also"></a>Consulte também

[Runtime de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)<br/>
[OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp)<br/>
[Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)<br/>
[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)
