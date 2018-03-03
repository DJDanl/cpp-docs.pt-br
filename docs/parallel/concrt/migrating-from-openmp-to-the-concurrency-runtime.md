---
title: "Migrando de OpenMP no tempo de execução de simultaneidade | Microsoft Docs"
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
- Concurrency Runtime, migrating from OpenMP
- OpenMP, migrating to the Concurrency Runtime
ms.assetid: 9bab7bb1-e45d-44b2-8509-3b226be2c93b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 65359e76e036a0d8d33de2de9f6c96c6425d2152
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="migrating-from-openmp-to-the-concurrency-runtime"></a>Migrando de OpenMP no Tempo de Execução de Simultaneidade
O tempo de execução de simultaneidade permite uma variedade de modelos de programação. Esses modelos podem se sobrepor ou complementar os modelos de outras bibliotecas. Os documentos nesta seção comparar [OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp) no tempo de execução de simultaneidade e fornece exemplos sobre como migrar código OpenMP existente para usar o tempo de execução de simultaneidade.  
  
 O modelo de programação OpenMP é definido por um padrão aberto e tem associações bem definidas para as linguagens de programação Fortran e C/C++. Versões de OpenMP 2.0 e 2.5, que são suportados pelo compilador do Visual C++, são apropriadas para os algoritmos paralelos que estão iterativos; ou seja, eles executam a iteração paralela em uma matriz de dados. OpenMP 3.0 oferece suporte a tarefas não iterativo além das tarefas iterativas.  
  
 OpenMP é mais eficiente quando o grau de paralelismo é predeterminado e corresponde os recursos disponíveis no sistema. O modelo de OpenMP é um especialmente adequado para a computação de alto desempenho, em que grandes problemas computacionais são distribuídos entre os recursos de processamento de um computador. Nesse cenário, o ambiente de hardware geralmente é fixo e o desenvolvedor pode esperar acesso exclusivo para todos os recursos de computação quando o algoritmo é executado.  
  
 No entanto, menos restrito ambientes de computação pode não ser uma boa correspondência para OpenMP. Por exemplo, problemas recursiva (como o algoritmo quicksort ou pesquisar uma árvore de dados) são mais difíceis de implementar usando OpenMP 2.0 e 2.5. O tempo de execução de simultaneidade complementa os recursos do OpenMP fornecendo o [biblioteca de agentes assíncrona](../../parallel/concrt/asynchronous-agents-library.md) e [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) (PPL). Paralelismo da tarefa de alta granularidade; oferece suporte a biblioteca de agentes assíncronos PPL dá suporte a mais tarefas paralelas refinadas. O tempo de execução de simultaneidade fornece a infraestrutura necessária para executar operações em paralelo, para que você possa se concentrar na lógica do seu aplicativo. No entanto, como o tempo de execução de simultaneidade permite uma variedade de modelos de programação, seu agendamento de sobrecarga pode ser maior do que outras bibliotecas de simultaneidade, como OpenMP. Portanto, recomendamos que você teste desempenho incrementalmente ao converter seu código OpenMP existente para usar o tempo de execução de simultaneidade.  
  
## <a name="when-to-migrate-from-openmp-to-the-concurrency-runtime"></a>Quando migrar de OpenMP no tempo de execução de simultaneidade  
 Pode ser vantajoso para migrar o código OpenMP existente para usar o tempo de execução de simultaneidade nos seguintes casos.  
  
|Casos|Vantagens do tempo de execução de simultaneidade|  
|-----------|-------------------------------------------|  
|Você precisa de uma estrutura de programação simultânea extensível.|Muitos dos recursos no tempo de execução de simultaneidade podem ser estendidos. Você também pode combinar os recursos existentes para compor novas. Como OpenMP depende de diretivas de compilador, ele não pode ser facilmente estendido.|  
|Seu aplicativo pode se beneficiar do bloqueio cooperativo.|Quando uma tarefa bloqueia porque ele requer um recurso que não está disponível, o tempo de execução de simultaneidade poderá executar outras tarefas enquanto aguarda a primeira tarefa para o recurso.|  
|Seu aplicativo pode se beneficiar do balanceamento de carga dinâmico.|O tempo de execução de simultaneidade usa um algoritmo de programação que ajusta a alocação de recursos de computação, como alterar as cargas de trabalho. OpenMP, quando o Agendador aloca recursos de computação para uma região parallel, essas alocações são corrigidas em todo o cálculo.|  
|Você precisa de suporte à manipulação de exceção.|PPL permite capturar exceções dentro e fora de uma região parallel ou loop. OpenMP, você deve lidar com a exceção de dentro do loop ou região paralela.|  
|Você precisa de um mecanismo de cancelamento.|PPL permite que aplicativos Cancelar tarefas individuais e paralelas árvores de trabalho. OpenMP requer que o aplicativo implementar seu próprio mecanismo de cancelamento.|  
|Você requer código paralelo para terminar em um contexto diferente do qual ele é iniciado.|O tempo de execução de simultaneidade permite iniciar uma tarefa em um contexto e esperar ou cancelar a tarefa em outro contexto. OpenMP, todo o trabalho paralelo deve terminar no contexto do qual ele é iniciado.|  
|Você precisa de suporte aprimorado para depuração.|O Visual Studio fornece o **pilhas paralelas** e **tarefas paralelas** windows para que você pode depurar aplicativos multithread mais facilmente.<br /><br /> Para obter mais informações sobre suporte para o tempo de execução de simultaneidade de depuração, consulte [usando a janela tarefas](/visualstudio/debugger/using-the-tasks-window), [usando a janela pilhas paralelas](/visualstudio/debugger/using-the-parallel-stacks-window), e [passo a passo: depurando um paralelo Aplicativo](/visualstudio/debugger/walkthrough-debugging-a-parallel-application).|  
  
## <a name="when-not-to-migrate-from-openmp-to-the-concurrency-runtime"></a>Quando não migrar de OpenMP no tempo de execução de simultaneidade  
 Os casos a seguir descrevem quando ele não pode ser apropriado migrar o código OpenMP existente para usar o tempo de execução de simultaneidade.  
  
|Casos|Explicação|  
|-----------|-----------------|  
|Seu aplicativo já atende às suas necessidades.|Se você estiver satisfeito com o desempenho do aplicativo e suporte de depuração atual, migração pode não ser apropriada.|  
|O corpo do loop paralelo executar pouco de trabalho.|A sobrecarga de tempo de execução de simultaneidade do Agendador de tarefas não pode superar os benefícios de executar o corpo do loop em paralelo, especialmente quando o corpo do loop for relativamente pequeno.|  
|Seu aplicativo é escrito em C.|Como o tempo de execução de simultaneidade usa muitos recursos do C++, ele pode não ser adequado quando não é possível gravar o código que permite que o aplicativo C totalmente usá-lo.|  
  
## <a name="related-topics"></a>Tópicos relacionados  
 [Como converter um loop OpenMP paralelo para loop para usar o tempo de execução de simultaneidade](../../parallel/concrt/how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime.md)  

 Dado um loop básico que usa o OpenMP [paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel) e [para](../../parallel/openmp/reference/for-openmp.md) diretivas, demonstra como convertê-lo para usar o tempo de execução de simultaneidade [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo.  

  
 [Como converter um loop OpenMP que usa cancelamento para usar o tempo de execução de simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that-uses-cancellation.md)  
 Dado um OpenMP [paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../../parallel/openmp/reference/for-openmp.md) loop que não exige que todas as iterações para executar, demonstra como convertê-lo para usar o mecanismo de cancelamento de tempo de execução de simultaneidade.  
  
 [Como converter um loop OpenMP que usa tratamento de exceções para usar o tempo de execução de simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that uses-exception-handling.md)  
 Dado um OpenMP [paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../../parallel/openmp/reference/for-openmp.md) loop que executa a manipulação de exceção, demonstra como convertê-lo para usar o mecanismo de tratamento de exceções de tempo de execução de simultaneidade.  
  
 [Como converter um loop OpenMP que usa uma variável de redução para usar o tempo de execução de simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that-uses-a-reduction-variable.md)  
 Dado um OpenMP [paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../../parallel/openmp/reference/for-openmp.md) loop que usa o [redução](../../parallel/openmp/reference/reduction.md) cláusula, demonstra como convertê-lo para usar o tempo de execução de simultaneidade.  
  
## <a name="see-also"></a>Consulte também  
 [Tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime.md)   
 [OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp)   
 [Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)   
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)

