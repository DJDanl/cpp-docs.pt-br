---
title: "Migrando de OpenMP no Tempo de Execu&#231;&#227;o de Simultaneidade | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Tempo de Execução de Simultaneidade, migrando de OpenMP"
  - "OpenMP, migrando para o Tempo de Execução de Simultaneidade"
ms.assetid: 9bab7bb1-e45d-44b2-8509-3b226be2c93b
caps.latest.revision: 12
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Migrando de OpenMP no Tempo de Execu&#231;&#227;o de Simultaneidade
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O tempo de execução de simultaneidade habilita uma variedade de modelos de programação.  Esses modelos podem sobrepor ou complementar os modelos de outras bibliotecas.  Os documentos nesta seção se comparam [OpenMP](../../parallel/openmp/openmp-in-visual-cpp.md) ao tempo de execução de simultaneidade e fornecem exemplos sobre como migrar o código existente OpenMP para usar o tempo de execução de simultaneidade.  
  
 O modelo de programação OpenMP é definido por um padrão aberto e tem associações bem definidos para o Fortran e as linguagens de programação C\/C\+\+.  As versões 2,0 e 2,5 OpenMP, que têm suporte pelo compilador do Visual C\+\+, são apropriados para os algoritmos que são iterativos paralelos; isto é, a execução paralela iteração sobre uma matriz de dados.  OpenMP 3,0 da suporte a tarefas não iterativas além de tarefas iterativas.  
  
 OpenMP é mais eficiente quando o grau de paralelismo é índice e corresponde aos recursos disponíveis no sistema.  O modelo OpenMP é uma boa correspondência especialmente para o capacidade de alto desempenho, onde os problemas computacionais muito grandes são distribuídos por meio dos recursos de processamento de um computador.  Neste cenário, o ambiente de hardware geralmente é fixo e o desenvolvedor pode esperar razoavelmente ter acesso exclusivo a todos os recursos de computação quando o algoritmo é executado.  
  
 No entanto, menos ambientes restritos de computação não pode ser uma boa correspondência de OpenMP.  Por exemplo, os problemas recursivas \(como o algoritmo de quicksort ou a pesquisa de uma árvore de dados\) são mais difíceis de implementar com OpenMP 2.0 e 2,5.  O tempo de execução de simultaneidade complementa os recursos OpenMP fornecendo [Biblioteca assíncrona de agentes](../../parallel/concrt/asynchronous-agents-library.md) e [A paralela da biblioteca](../../parallel/concrt/parallel-patterns-library-ppl.md) \(PPL\).  A biblioteca assíncrona de agentes da suporte ao paralelismo de alta granularidade da tarefa; o da suporte a uma PPL tarefas paralelas mais refinados.  O tempo de execução de simultaneidade fornece a infraestrutura necessária para executar operações em paralelo de forma que você possa se concentrar a lógica do aplicativo.  Entretanto, como o tempo de execução de simultaneidade habilita uma variedade de modelos de programação, a sobrecarga de programação pode ser maior que outras bibliotecas de simultaneidade como OpenMP.  Consequentemente, recomendamos que você teste o desempenho incremental quando você converte seu código existente OpenMP para usar o tempo de execução de simultaneidade.  
  
## Quando migrar OpenMP ao tempo de execução de simultaneidade  
 Pode ser vantajoso migrar o código existente OpenMP para usar o tempo de execução de simultaneidade nos seguintes casos.  
  
|Casos|Vantagens de tempo de execução de simultaneidade|  
|-----------|------------------------------------------------------|  
|Você precisar de uma estrutura extensível de programação simultâneo.|Muitos dos recursos em tempo de execução de simultaneidade podem ser estendidos.  Você também pode combinar recursos existentes para compor novos.  Como OpenMP confia em políticas do compilador, não pode ser facilmente estendido.|  
|Seu aplicativo pode se beneficiar de bloqueio cooperativo.|Quando os blocos de uma tarefa pois o exige um recurso que não ainda está disponível, o tempo de execução de simultaneidade podem executar outras tarefas quando a primeira tarefa estiver aguardando o recurso.|  
|Seu aplicativo pode se beneficiar de balanceamento de carga dinâmico.|O tempo de execução de simultaneidade usa um algoritmo de programação que ajuste a alocação de recursos de computação porque as cargas de trabalho são alterados.  Em OpenMP, quando o agendador atribui recursos de computação a uma região paralela, as atribuições de recursos estão corrigidas durante a computação.|  
|Você precisa do suporte de manipulação de exceção.|O PPL permite capturar exceções dentro e fora de uma região paralela ou dá\-las loop.  Em OpenMP, você deve controlar a exceção na região paralela ou dá\-la loop.|  
|Você precisar de um mecanismo de cancelamento.|O PPL permite que aplicativos cancelar tarefas individuais e árvores paralelas de trabalho.  OpenMP requer o aplicativo implementa seu próprio mecanismo de cancelamento.|  
|Você precisa do código paralelo para ser concluída em um contexto diferente da parte.|O tempo de execução de simultaneidade permite iniciar uma tarefa em um contexto, e espera\-o em em ou cancelá\-lo essa tarefa em outro contexto.  Em OpenMP, todo o trabalho paralelo deve concluir no contexto no qual parte.|  
|Você precisa do suporte avançado de depuração.|Visual Studio fornece as janelas de **Pilhas Paralelas** e de **Tarefas Paralelas** de forma que você possa mais facilmente depurar aplicativos multi\-threaded.<br /><br /> Para obter mais informações sobre o suporte à depuração do tempo de execução de simultaneidade, consulte [Usando a janela Tarefas](../Topic/Using%20the%20Tasks%20Window.md), [Usando a janela Pilhas Paralelas](../Topic/Using%20the%20Parallel%20Stacks%20Window.md), e [Instruções passo a passo: depurando um aplicativo paralelo](../Topic/Walkthrough:%20Debugging%20a%20Parallel%20Application.md).|  
  
## Quando não migrar OpenMP ao tempo de execução de simultaneidade  
 Os seguintes casos descrevem quando talvez não seja apropriado migrar o código existente OpenMP para usar o tempo de execução de simultaneidade.  
  
|Casos|Explicação|  
|-----------|----------------|  
|Seu aplicativo já atende aos requisitos.|Se estiver satisfeito com o desempenho do aplicativo e o suporte à depuração atuais, a migração pode não ser apropriado.|  
|Os corpos de loop paralelos e executam trabalho.|A sobrecarga o agendador de tarefas de tempo de execução de simultaneidade não pode ultrapassar os benefícios da execução do corpo de loop em paralelo, especialmente quando o corpo de loop for relativamente pequeno.|  
|O aplicativo é gravado em C.|Como o tempo de execução de simultaneidade usa muitos recursos do C\+\+, talvez não seja apropriado quando não pode escrever o código que permite que o aplicativo C o usar completamente.|  
  
## Tópicos relacionados  
 [Como converter um loop OpenMP paralelo para loop para usar o tempo de execução de simultaneidade](../../parallel/concrt/how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime.md)  
 Dado um loop básico que usa o OpenMP [paralela](../../parallel/openmp/reference/parallel.md) e políticas de [para](../Topic/for%20\(OpenMP\).md) , demonstra como convertê\-lo para usar o algoritmo de [concurrency::parallel\_for](../Topic/parallel_for%20Function.md) de tempo de execução de simultaneidade.  
  
 [Como converter um loop OpenMP que usa cancelamento para usar o tempo de execução de simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that-uses-cancellation.md)  
 Dado um loop OpenMP [paralela](../../parallel/openmp/reference/parallel.md)[para](../Topic/for%20\(OpenMP\).md) que não requer todas as iterações executar, demonstra como convertê\-lo para usar o cancelamento do mecanismo de tempo de execução de simultaneidade.  
  
 [Como converter um loop OpenMP que usa tratamento de exceções para usar o tempo de execução de simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that uses-exception-handling.md)  
 Dado um loop OpenMP [paralela](../../parallel/openmp/reference/parallel.md)[para](../Topic/for%20\(OpenMP\).md) que executa a manipulação de exceções, demonstra como convertida para usar o mecanismo de manipulação de exceção em tempo de execução de simultaneidade.  
  
 [Como converter um loop OpenMP que usa uma variável de redução para usar o tempo de execução de simultaneidade](../Topic/How%20to:%20Convert%20an%20OpenMP%20Loop%20that%20Uses%20a%20Reduction%20Variable%20to%20Use%20the%20Concurrency%20Runtime.md)  
 Dado um loop OpenMP [paralela](../../parallel/openmp/reference/parallel.md)[para](../Topic/for%20\(OpenMP\).md) que usa a cláusula de [redução](../../parallel/openmp/reference/reduction.md) , demonstra como convertida para usar o tempo de execução de simultaneidade.  
  
## Consulte também  
 [Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)   
 [OpenMP](../../parallel/openmp/openmp-in-visual-cpp.md)   
 [Biblioteca de padrões paralelos \(PPL\)](../../parallel/concrt/parallel-patterns-library-ppl.md)   
 [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)