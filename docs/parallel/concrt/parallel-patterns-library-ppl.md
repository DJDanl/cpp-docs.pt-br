---
title: Paralelo a biblioteca de padrões (PPL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Parallel Patterns Library (PPL)
ms.assetid: 40fd86b2-69fa-45e5-93d8-98a75636c242
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7263d764014fa3532c3234bd4c7a0d4f1ff8d3c3
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33691535"
---
# <a name="parallel-patterns-library-ppl"></a>Biblioteca de padrões paralelos (PPL)
A biblioteca de padrões paralelos (PPL) fornece um modelo de programação imperativo que promova a escalabilidade e a facilidade de uso para o desenvolvimento de aplicativos simultâneos. PPL tem como base os componentes de gerenciamento de recursos e agendamento de tempo de execução de simultaneidade. Ele gera o nível de abstração entre o código do aplicativo e o mecanismo subjacente de threading, fornecendo algoritmos genéricos fortemente tipadas e contêineres que atuam em dados em paralelo. PPL permite desenvolver aplicativos que podem ser expandidos fornecendo alternativas para estado compartilhado.  
  
 PPL fornece os seguintes recursos:  
  
- *Paralelismo de tarefa*: um mecanismo que funciona sobre o ThreadPool do Windows para executar vários itens de trabalho (tarefas) em paralelo  
  
- *Paralelo algoritmos*: algoritmos genéricos que funciona sobre o tempo de execução de simultaneidade para atuar em conjuntos de dados em paralelo  
  
- *Paralelo contêineres e objetos*: tipos de contêiner genérico que fornecem acesso simultâneo seguro para seus elementos  
  
## <a name="example"></a>Exemplo  
 PPL fornece um modelo de programação que se parece com a biblioteca padrão C++. O exemplo a seguir demonstra muitos recursos da PPL. Computa vários números de Fibonacci em série e em paralelo. Ambas as computações agir em um [std:: array](../../standard-library/array-class-stl.md) objeto. O exemplo também imprime no console o tempo necessário para executar ambos os cálculos.  
  
 A versão serial usa a biblioteca padrão C++ [std::for_each](../../standard-library/algorithm-functions.md#for_each) algoritmo para atravessar a matriz e armazena os resultados em uma [std:: Vector](../../standard-library/vector-class.md) objeto. A versão paralela executa a mesma tarefa, mas usa PPL [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo e armazena os resultados em uma [concurrency::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) objeto. O `concurrent_vector` classe permite que cada iteração do loop simultaneamente adicionar elementos sem a necessidade de sincronizar o acesso de gravação ao contêiner.  
  
 Porque `parallel_for_each` funciona ao mesmo tempo, a versão paralela deste exemplo deve classificar o `concurrent_vector` objeto para produzir os mesmos resultados que a versão serial.  
  
 Observe que o exemplo usa um método simples para calcular os números Fibonacci; No entanto, esse método ilustra como o tempo de execução de simultaneidade pode melhorar o desempenho de cálculos de tempo.  
  
 [!code-cpp[concrt-parallel-fibonacci#1](../../parallel/concrt/codesnippet/cpp/parallel-patterns-library-ppl_1.cpp)]  
  
 A seguinte saída de exemplo é para um computador com quatro processadores.  
  
```Output  
serial time: 9250 ms  
parallel time: 5726 ms  
 
fib(24): 46368  
fib(26): 121393  
fib(41): 165580141  
fib(42): 267914296  
```  
  
 Cada iteração do loop requer um valor diferente de tempo para concluir. O desempenho de `parallel_for_each` é limitada pela operação de conclusão da última. Portanto, você não deve esperar melhorias de desempenho linear entre as versões paralelas e seriais deste exemplo.  
  
## <a name="related-topics"></a>Tópicos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)|Descreve a função de tarefas e grupos de tarefas no PPL.|  
|[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)|Descreve como usar os algoritmos paralelos, como `parallel_for` e `parallel_for_each`.|  
|[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)|Descreve os vários contêineres paralelos e objetos que são fornecidos pelo PPL.|  
|[Cancelamento no PPL](cancellation-in-the-ppl.md)|Explica como cancelar o trabalho que está sendo executado por um algoritmo em paralelo.|  
|[Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)|Descreve o tempo de execução de simultaneidade, que simplifica a programação paralela e contém links para tópicos relacionados.|

