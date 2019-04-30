---
title: 'Como: Usar contêineres em paralelo para aumentar a eficiência'
ms.date: 11/04/2016
helpviewer_keywords:
- increasing efficiency with parallel containers [Concurrency Runtime]
- concurrent_queue class, examples
- concurrent_vector class, examples
ms.assetid: bd00046d-e9b6-4ae1-b661-3995f671b867
ms.openlocfilehash: 2479915b167ee3dbc2ce43d9c2733efc74818bbe
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394436"
---
# <a name="how-to-use-parallel-containers-to-increase-efficiency"></a>Como: Usar contêineres em paralelo para aumentar a eficiência

Este tópico mostra como usar contêineres em paralelo com eficiência armazenar e acessar dados em paralelo.

O exemplo de código calcula o conjunto de números de Carmichael em paralelo e primo. Em seguida, para cada número Carmichael, o código calcula os fatores primos desse número.

## <a name="example"></a>Exemplo

A exemplo a seguir mostra a `is_prime` função, que determina se um valor de entrada é um número primo, e o `is_carmichael` função, que determina se o valor de entrada é um número Carmichael.

[!code-cpp[concrt-carmichael-primes#1](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_1.cpp)]

## <a name="example"></a>Exemplo

O exemplo a seguir usa o `is_prime` e `is_carmichael` funções para calcular os conjuntos de números de Carmichael e primo. O exemplo usa o [Concurrency:: parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) e [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmos para calcular cada conjunto em paralelo. Para obter mais informações sobre os algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

Este exemplo usa uma [concurrency::concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md) números de objeto para conter o conjunto de Carmichael porque ele usará mais tarde esse objeto como uma fila de trabalho. Ele usa um [concurrency::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) objeto para conter o conjunto de números primos, porque ele mais tarde irá iterar isso definida para encontrar os fatores primos.

[!code-cpp[concrt-carmichael-primes#2](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_2.cpp)]

## <a name="example"></a>Exemplo

A exemplo a seguir mostra o `prime_factors_of` função, que usa a divisão de avaliação para localizar todos os principais fatores do valor fornecido.

Essa função usa o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo para iterar pela coleção de números primos. O `concurrent_vector` objeto permite que o loop paralelo adicionar simultaneamente fatores primos ao resultado.

[!code-cpp[concrt-carmichael-primes#3](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_3.cpp)]

## <a name="example"></a>Exemplo

Este exemplo processa cada elemento na fila de números Carmichael chamando o `prime_factors_of` função para calcular seus fatores primos. Ele usa um grupo de tarefas para realizar esse trabalho em paralelo. Para obter mais informações sobre grupos de tarefas, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md).

Este exemplo imprime os fatores principais para cada número Carmichael se esse número tiver mais de quatro fatores primos.

[!code-cpp[concrt-carmichael-primes#4](../../parallel/concrt/codesnippet/cpp/how-to-use-parallel-containers-to-increase-efficiency_4.cpp)]

## <a name="example"></a>Exemplo

O código a seguir mostra o exemplo completo, que usa contêineres em paralelo para calcular os fatores principais dos números Carmichael.

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

[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)<br/>
[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Classe concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md)<br/>
[Classe concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md)<br/>
[Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)<br/>
[Função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)<br/>
[Classe task_group](reference/task-group-class.md)
