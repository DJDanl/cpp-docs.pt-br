---
title: "Como: usar contêineres em paralelo para aumentar a eficiência | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- increasing efficiency with parallel containers [Concurrency Runtime]
- concurrent_queue class, examples
- concurrent_vector class, examples
ms.assetid: bd00046d-e9b6-4ae1-b661-3995f671b867
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 64b191b97bcf4b5f1607cde56fac8fefd1505c7c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-use-parallel-containers-to-increase-efficiency"></a>Como usar contêineres em paralelo para aumentar a eficiência
Este tópico mostra como usar contêineres paralelos para armazenar de forma eficiente e acessar dados em paralelo.  
  
 O código de exemplo calcula o conjunto de linha e números de Carmichael em paralelo. Em seguida, para cada número Carmichael, o código calcula os principais fatores desse número.  
  
## <a name="example"></a>Exemplo  
 A exemplo a seguir mostra o `is_prime` função, que determina se um valor de entrada é um número primo, e o `is_carmichael` função, que determina se o valor de entrada é um número Carmichael.  
  
 [!code-cpp[concrt-carmichael-primes#1](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_1.cpp)]  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir usa o `is_prime` e `is_carmichael` funções para calcular os conjuntos de linha e números de Carmichael. O exemplo usa o [concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) e [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmos para calcular cada conjunto em paralelo. Para obter mais informações sobre os algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  
  
 Este exemplo usa um [concurrency::concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md) números de objeto para conter o conjunto de Carmichael porque ele usará mais tarde esse objeto como uma fila de trabalho. Ele usa um [concurrency::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) objeto para conter o conjunto de números primos porque ele mais tarde irá iterar essa definição para localizar os principais fatores.  
  
 [!code-cpp[concrt-carmichael-primes#2](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_2.cpp)]  
  
## <a name="example"></a>Exemplo  
 A exemplo a seguir mostra o `prime_factors_of` função, que usa a divisão de avaliação para localizar todos os principais fatores do valor especificado.  
  
 Essa função usa o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo para iterar pela coleção de números primos. O `concurrent_vector` objeto permite que o loop paralelo adicionar simultaneamente principais fatores para o resultado.  
  
 [!code-cpp[concrt-carmichael-primes#3](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_3.cpp)]  
  
## <a name="example"></a>Exemplo  
 Esse exemplo processa cada elemento na fila de números Carmichael chamando o `prime_factors_of` função para suas principais fatores de computação. Ele usa um grupo de tarefas para executar esse trabalho em paralelo. Para obter mais informações sobre grupos de tarefas, consulte [paralelismo de tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
 Este exemplo imprime os principais fatores para cada número Carmichael se esse número tiver mais de quatro fatores primos.  
  
 [!code-cpp[concrt-carmichael-primes#4](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_4.cpp)]  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra o exemplo completo, que usa contêineres paralelos para calcular os principais fatores dos números Carmichael.  
  
 [!code-cpp[concrt-carmichael-primes#5](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_5.cpp)]  
  
 Este exemplo produz a saída de exemplo a seguir.  
  
```Output  
Prime factors of 9890881 are: 7 11 13 41 241.  
Prime factors of 825265 are: 5 7 17 19 73.  
Prime factors of 1050985 are: 5 13 19 23 37.  
```  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `carmichael-primes.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc carmichael-primes.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Objetos e contêineres paralelos](../../parallel/concrt/parallel-containers-and-objects.md)   
 [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [Classe concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md)   
 [Classe concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md)   
 [Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)   
 [Função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)   
 [Classe task_group](reference/task-group-class.md)
