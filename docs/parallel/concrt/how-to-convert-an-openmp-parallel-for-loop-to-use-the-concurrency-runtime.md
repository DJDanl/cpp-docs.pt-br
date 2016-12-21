---
title: "Como converter um loop OpenMP paralelo para loop para usar o tempo de execu&#231;&#227;o de simultaneidade | Microsoft Docs"
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
  - "Convertendo de OpenMP no tempo de execução simultaneidade, loops for paralelos"
  - "Convertendo de OpenMP no tempo de execução de simultaneidade, loop paralelo"
  - "paralelo para loops, convertendo de OpenMP no tempo de execução de simultaneidade"
  - "loops paralelos, convertendo de OpenMP no tempo de execução de simultaneidade"
ms.assetid: d8a7b656-f86c-456e-9c5d-a7d52f94646e
caps.latest.revision: 13
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como converter um loop OpenMP paralelo para loop para usar o tempo de execu&#231;&#227;o de simultaneidade
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este exemplo demonstra como converter um loop básico que usa o OpenMP [paralela](../../parallel/openmp/reference/parallel.md) e políticas de [para](../Topic/for%20\(OpenMP\).md) para usar o algoritmo de [concurrency::parallel\_for](../Topic/parallel_for%20Function.md) de tempo de execução de simultaneidade.  
  
## Exemplo  
 Este exemplo usa OpenMP e o tempo de execução de simultaneidade para calcular a contagem de números à esquerda em uma matriz de valores aleatórios.  
  
 [!code-cpp[concrt-openmp#1](../../parallel/concrt/codesnippet/CPP/how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime_1.cpp)]  
  
 O exemplo produz a seguinte saída.  
  
  **Usando OpenMP…**  
**encontradas 107254 números à esquerda.**  
**Usando o tempo de execução de simultaneidade…**  
**encontradas 107254 números à esquerda.** O algoritmo de `parallel_for` e o OpenMP 3,0 permite o tipo de índice ser um tipo integral um tipo integral assinado ou não assinado.  O algoritmo de `parallel_for` também garante que o intervalo especificado não excederá um tipo assinado.  As versões 2,0 e 2,5 OpenMP permitem tipos integrais assinados de índice.  OpenMP também não valida o intervalo de índice.  
  
 A versão deste exemplo que usa o tempo de execução de simultaneidade também usa um objeto de [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) no lugar da política de [atomic](../../parallel/openmp/reference/atomic.md) para incrementar o valor do contador sem exigir a sincronização.  
  
 Para obter mais informações sobre como `parallel_for` e outros algoritmos paralelos, consulte [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md).  Para obter mais informações sobre a classe `combinable`, consulte [Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md).  
  
## Exemplo  
 Este exemplo altera anterior para atuar em um objeto de [std::array](../../standard-library/array-class-stl.md) em vez de uma matriz nativo.  Como as versões 2,0 e 2,5 OpenMP permitem o índice integral assinado tipo somente em uma compilação de `parallel``for` , você não pode usar iteradores em paralelo para acessar os elementos de um contêiner de \(STL\) da biblioteca do modelo padrão de.  A biblioteca \(PPL\) de padrões de paralelo fornece o algoritmo de [concurrency::parallel\_for\_each](../Topic/parallel_for_each%20Function.md) , que executa tarefas, em paralelo, em um contêiner iterativo como os que são fornecidos por STL.  Usa a mesma lógica de particionamento que o algoritmo de `parallel_for` usa.  O algoritmo de `parallel_for_each` se assemelha ao algoritmo STL [std::for\_each](../Topic/for_each.md) , exceto que o algoritmo de `parallel_for_each` executa as tarefas simultaneamente.  
  
 [!code-cpp[concrt-openmp#10](../../parallel/concrt/codesnippet/CPP/how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime_2.cpp)]  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `concrt-omp-count-primes.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc \/openmp concrt\-omp\-count\-primes.cpp**  
  
## Consulte também  
 [Migrando de OpenMP no Tempo de Execução de Simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)   
 [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)   
 [Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)