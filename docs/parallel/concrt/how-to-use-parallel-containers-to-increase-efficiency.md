---
title: Como usar contêineres em paralelo para aumentar a eficiência
ms.date: 11/04/2016
helpviewer_keywords:
- increasing efficiency with parallel containers [Concurrency Runtime]
- concurrent_queue class, examples
- concurrent_vector class, examples
ms.assetid: bd00046d-e9b6-4ae1-b661-3995f671b867
ms.openlocfilehash: cd120d1fbe0f73ed0974efda5a1aa643a1afde9d
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77143007"
---
# <a name="how-to-use-parallel-containers-to-increase-efficiency"></a>Como usar contêineres em paralelo para aumentar a eficiência

Este tópico mostra como usar contêineres paralelos para armazenar e acessar dados em paralelo de forma eficiente.

O código de exemplo computa o conjunto de números primo e Carmichael em paralelo. Em seguida, para cada número de Carmichael, o código computa os fatores primos desse número.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a função `is_prime`, que determina se um valor de entrada é um número primo e a função `is_carmichael`, que determina se o valor de entrada é um número Carmichael.

[!code-cpp[concrt-carmichael-primes#1](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_1.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir usa as funções `is_prime` e `is_carmichael` para computar os conjuntos de números primo e Carmichael. O exemplo usa a [simultaneidade::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) e a [simultaneidade::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmos para computar cada conjunto em paralelo. Para obter mais informações sobre algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

Este exemplo usa um objeto [Concurrency:: concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md) para conter o conjunto de números Carmichael, pois ele usará posteriormente esse objeto como uma fila de trabalho. Ele usa um objeto [Concurrency:: concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) para conter o conjunto de números primos, pois ele iterará mais tarde por meio desse conjunto para localizar os principais fatores.

[!code-cpp[concrt-carmichael-primes#2](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_2.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a função `prime_factors_of`, que usa a divisão de avaliação para localizar todos os fatores primos do valor especificado.

Essa função usa o algoritmo [Concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) para iterar pela coleção de números primos. O objeto `concurrent_vector` permite que o loop paralelo adicione fatores primos ao resultado simultaneamente.

[!code-cpp[concrt-carmichael-primes#3](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_3.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Este exemplo processa cada elemento na fila de números Carmichael chamando a função `prime_factors_of` para calcular seus fatores primos. Ele usa um grupo de tarefas para executar esse trabalho em paralelo. Para obter mais informações sobre grupos de tarefas, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md).

Este exemplo imprime os fatores primos para cada número de Carmichael se esse número tiver mais de quatro fatores primos.

[!code-cpp[concrt-carmichael-primes#4](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_4.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O código a seguir mostra o exemplo completo, que usa contêineres paralelos para computar os principais fatores dos números de Carmichael.

[!code-cpp[concrt-carmichael-primes#5](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_5.cpp)]

Este exemplo produz a seguinte saída de exemplo.

```Output
Prime factors of 9890881 are: 7 11 13 41 241.
Prime factors of 825265 are: 5 7 17 19 73.
Prime factors of 1050985 are: 5 13 19 23 37.
```

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `carmichael-primes.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Carmichael-Primes. cpp**

## <a name="see-also"></a>Consulte também

[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)<br/>
[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Classe concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md)<br/>
[Classe concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md)<br/>
[Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)<br/>
[Função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)<br/>
[Classe task_group](reference/task-group-class.md)
