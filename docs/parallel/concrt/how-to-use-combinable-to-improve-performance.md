---
title: "Como usar combin&#225;vel para melhorar o desempenho | Microsoft Docs"
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
  - "classe podem ser combinada, por exemplo:"
  - "melhorando o desempenho paralelo com combinable [Tempo de Execução de Simultaneidade]"
ms.assetid: fa730580-1c94-4b2d-8aec-57c91dc0497e
caps.latest.revision: 17
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar combin&#225;vel para melhorar o desempenho
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este exemplo mostra como usar a classe de [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) para calcular a soma dos números em um objeto de [std::array](../../standard-library/array-class-stl.md) que são principais.  A classe de `combinable` melhora o desempenho com a eliminação do estado compartilhado.  
  
> [!TIP]
>  Em alguns casos, o mapa parallel \([concurrency::parallel\_transform](../Topic/parallel_transform%20Function.md)\) e reduce \(\)[simultaneidade:: parallel\_reduce](../Topic/parallel_reduce%20Function.md)pode fornecer melhorias de desempenho sobre `combinable`.  Para obter um exemplo que usa o mapa e reduzir as operações para produzir os mesmos resultados que esse exemplo, consulte [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md).  
  
## Exemplo  
 O exemplo a seguir usa a função de [std::accumulate](../Topic/accumulate.md) para calcular a soma dos elementos em uma matriz que são principais.  Neste exemplo, `a` é um objeto de `array` e a função de `is_prime` determina se o valor de entrada for o principal.  
  
 [!code-cpp[concrt-parallel-sum-of-primes#1](../../parallel/concrt/codesnippet/CPP/how-to-use-combinable-to-improve-performance_1.cpp)]  
  
## Exemplo  
 O exemplo a seguir mostra uma maneira de naïve de parallelize o exemplo anterior.  Este exemplo usa o algoritmo de [concurrency::parallel\_for\_each](../Topic/parallel_for_each%20Function.md) para processar em paralelo a matriz e um objeto de [concurrency::critical\_section](../../parallel/concrt/reference/critical-section-class.md) para sincronizar o acesso à variável de `prime_sum` .  Este exemplo não dimensiona porque cada thread deve aguardar o recurso compartilhado para se torne disponível.  
  
 [!code-cpp[concrt-parallel-sum-of-primes#2](../../parallel/concrt/codesnippet/CPP/how-to-use-combinable-to-improve-performance_2.cpp)]  
  
## Exemplo  
 O exemplo a seguir usa um objeto de `combinable` para melhorar o desempenho do exemplo anterior.  Este exemplo elimina a necessidade de objetos de sincronização; dimensões como o objeto de `combinable` permite que cada thread independente para executar a tarefa.  
  
 Um objeto de `combinable` é geralmente usado em duas etapas.  Primeiro, gerar uma série de computações refinados executando o trabalho em paralelo.  Em seguida, combina \(ou\) reduza as computações em um resultado final.  Este exemplo usa o método de [concurrency::combinable::local](../Topic/combinable::local%20Method.md) para obter uma referência à soma local.  Usa o método de [concurrency::combinable::combine](../Topic/combinable::combine%20Method.md) e um objeto de [std::plus](../../standard-library/plus-struct.md) para combinar as computações locais no resultado final.  
  
 [!code-cpp[concrt-parallel-sum-of-primes#3](../../parallel/concrt/codesnippet/CPP/how-to-use-combinable-to-improve-performance_3.cpp)]  
  
## Exemplo  
 O exemplo completo calcula a soma de números à esquerda em série ou em paralelo.  O exemplo grava no console o tempo necessário para executar computações ambas.  
  
 [!code-cpp[concrt-parallel-sum-of-primes#4](../../parallel/concrt/codesnippet/CPP/how-to-use-combinable-to-improve-performance_4.cpp)]  
  
 A seguinte saída de exemplo é para um computador que tem quatro processadores.  
  
  **1709600813**  
**tempo seriais: 6178 ms**  
**1709600813**  
**tempo paralelos: 1638 ms**   
## Compilando o código  
 Para compilar o código, copie\-a e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado`parallel-sum-of-primes.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc parallel\-sum\-of\-primes.cpp**  
  
## Programação robusta  
 Para obter um exemplo que usa o mapa e reduzir as operações para produzir os mesmos resultados, consulte [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md).  
  
## Consulte também  
 [Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)   
 [Classe combinable](../../parallel/concrt/reference/combinable-class.md)   
 [Classe critical\_section](../../parallel/concrt/reference/critical-section-class.md)