---
title: 'Como: Usar Combinável para melhorar o desempenho'
ms.date: 11/04/2016
helpviewer_keywords:
- combinable class, example
- improving parallel performance with combinable [Concurrency Runtime]
ms.assetid: fa730580-1c94-4b2d-8aec-57c91dc0497e
ms.openlocfilehash: c8f4c40be84b2204e5b5632fe6d3d5a5d22b8719
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410000"
---
# <a name="how-to-use-combinable-to-improve-performance"></a>Como: Usar Combinável para melhorar o desempenho

Este exemplo mostra como usar o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe para calcular a soma dos números em uma [std:: array](../../standard-library/array-class-stl.md) objeto são primo. O `combinable` classe melhora o desempenho, eliminando o estado compartilhado.

> [!TIP]
>  Em alguns casos, mapa em paralelo ([concurrency::parallel_transform](reference/concurrency-namespace-functions.md#parallel_transform)) e reduzir ([concurrency:: parallel_reduce](reference/concurrency-namespace-functions.md#parallel_reduce)) pode oferecer melhorias de desempenho em relação `combinable`. Para obter um exemplo que usa mapear e reduzir as operações para produzir os mesmos resultados que neste exemplo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="example"></a>Exemplo

O exemplo a seguir usa o [std::accumulate](../../standard-library/numeric-functions.md#accumulate) função para calcular a soma dos elementos em uma matriz que são primo. Neste exemplo, `a` é um `array` objeto e o `is_prime` função determina se o seu valor de entrada é primo.

[!code-cpp[concrt-parallel-sum-of-primes#1](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-improve-performance_1.cpp)]

## <a name="example"></a>Exemplo

O exemplo a seguir mostra uma maneira ingênua de paralelizar o exemplo anterior. Este exemplo usa o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo para processar a matriz em paralelo e uma [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md) objeto para sincronizar o acesso para o `prime_sum` variável . Este exemplo ajusta a escala porque cada thread deve aguardar que o recurso compartilhado se torne disponível.

[!code-cpp[concrt-parallel-sum-of-primes#2](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-improve-performance_2.cpp)]

## <a name="example"></a>Exemplo

O exemplo a seguir usa um `combinable` objeto para melhorar o desempenho do exemplo anterior. Este exemplo elimina a necessidade para objetos de sincronização. ele é dimensionado porque o `combinable` objeto permite que cada thread realizar sua tarefa de forma independente.

Um `combinable` objeto normalmente é usado em duas etapas. Primeiro, produza uma série de cálculos refinados executando o trabalho em paralelo. Em seguida, combinar (ou reduzir) os cálculos em um resultado final. Este exemplo usa o [concurrency::combinable::local](reference/combinable-class.md#local) método para obter uma referência à soma local. Ele usa o [concurrency::combinable::combine](reference/combinable-class.md#combine) método e uma [std::plus](../../standard-library/plus-struct.md) objeto para combinar os cálculos de locais para o resultado final.

[!code-cpp[concrt-parallel-sum-of-primes#3](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-improve-performance_3.cpp)]

## <a name="example"></a>Exemplo

O exemplo completo a seguir calcula a soma de números primos para ambas as em série e em paralelo. O exemplo imprime no console a hora em que é necessária executar ambos os cálculos.

[!code-cpp[concrt-parallel-sum-of-primes#4](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-improve-performance_4.cpp)]

A saída de exemplo a seguir é para um computador com quatro processadores.

```Output
1709600813
serial time: 6178 ms

1709600813
parallel time: 1638 ms
```

## <a name="compiling-the-code"></a>Compilando o código

Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-sum-of-primes.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc parallel-sum-of-primes.cpp**

## <a name="robust-programming"></a>Programação robusta

Para obter um exemplo que usa mapear e reduzir as operações para produzir os mesmos resultados, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="see-also"></a>Consulte também

[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)<br/>
[Classe combinable](../../parallel/concrt/reference/combinable-class.md)<br/>
[Classe critical_section](../../parallel/concrt/reference/critical-section-class.md)
