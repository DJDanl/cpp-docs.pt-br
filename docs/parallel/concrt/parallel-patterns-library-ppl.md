---
title: "Biblioteca de padr&#245;es paralelos (PPL) | Microsoft Docs"
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
  - "Biblioteca de padrões paralelos (PPL)"
ms.assetid: 40fd86b2-69fa-45e5-93d8-98a75636c242
caps.latest.revision: 27
caps.handback.revision: 27
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Biblioteca de padr&#245;es paralelos (PPL)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A biblioteca de padrões paralelos (PPL) fornece um modelo de programação fundamental que promove a escalabilidade e a facilidade de uso para o desenvolvimento de aplicativos simultâneos. A PPL amplia os componentes de gerenciamento de recursos e agendamento do tempo de execução de simultaneidade. Ele aumenta o nível de abstração entre o código do aplicativo e o mecanismo subjacente de threading, fornecendo algoritmos genéricos e de tipo seguro e contêineres que atuam em dados em paralelo. A PPL permite desenvolver aplicativos que dimensionar fornecendo alternativas para o estado compartilhado.  
  
 A PPL fornece os seguintes recursos:  
  
- *Paralelismo de tarefa*: um mecanismo que funciona sobre o ThreadPool do Windows para executar vários itens de trabalho (tarefas) em paralelo  
  
- *Paralelo algoritmos*: algoritmos genéricos funciona sobre o tempo de execução de simultaneidade para atuar em conjuntos de dados em paralelo  
  
- *Paralelo contêineres e objetos*: tipos de contêiner genérico que fornecem acesso simultâneo seguro aos seus elementos  
  
## <a name="example"></a>Exemplo  
 A PPL fornece um modelo de programação que se parece com o modelo Biblioteca STL (Standard). O exemplo a seguir demonstra vários recursos da PPL. Ele calcula vários números Fibonacci em série e em paralelo. Ambas as computações agir em uma [std::array](../../standard-library/array-class-stl.md) objeto. O exemplo também imprime no console o tempo necessário para executar ambas as computações.  
  
 A versão serial usa STL [std::for_each](../Topic/for_each.md) algoritmo para atravessar a matriz e armazena os resultados em um [std:: Vector](../../standard-library/vector-class.md) objeto. A versão paralela executa a mesma tarefa, mas usa a PPL [concurrency::parallel_for_each](../Topic/parallel_for_each%20Function.md) algoritmo e armazena os resultados em uma [concurrency::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) objeto. O `concurrent_vector` classe permite que cada iteração do loop simultaneamente adicionar elementos sem a necessidade de sincronizar o acesso de gravação ao contêiner.  
  
 Porque `parallel_for_each` Age simultaneamente, a versão paralela deste exemplo deve classificar o `concurrent_vector` objeto para produzir os mesmos resultados que a versão serial.  
  
 Observe que o exemplo usa um método simples para calcular os números Fibonacci; No entanto, esse método ilustra como o tempo de execução de simultaneidade pode melhorar o desempenho de computações longos.  
  
 [!code-cpp[concrt-parallel-fibonacci#1](../../parallel/concrt/codesnippet/CPP/parallel-patterns-library-ppl_1.cpp)]  
  
 A seguinte saída de exemplo é para um computador com quatro processadores.  
  
```Output  
serial time: 9250 ms  
parallel time: 5726 ms  
 
fib(24): 46368  
fib(26): 121393  
fib(41): 165580141  
fib(42): 267914296  
```  
  
 Cada iteração do loop requer uma quantidade diferente de tempo para concluir. O desempenho de `parallel_for_each` é limitada pela operação de conclusão da última. Portanto, você não deve esperar melhorias de desempenho linear entre as versões seriais e paralelas deste exemplo.  
  
## <a name="related-topics"></a>Tópicos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)|Descreve a função de tarefas e grupos de tarefas no PPL.|  
|[Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)|Descreve como usar os algoritmos paralelos, como `parallel_for` e `parallel_for_each`.|  
|[Objetos e contêineres em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)|Descreve os vários contêineres em paralelo e objetos que são fornecidos por PPL.|  
|[Cancelamento](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md#cancellation_in_the_ppl)|Explica como cancelar o trabalho que está sendo executado por um algoritmo paralelo.|  
|[Tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime.md)|Descreve o tempo de execução de simultaneidade, que simplifica a programação paralela e contém links para tópicos relacionados.|

