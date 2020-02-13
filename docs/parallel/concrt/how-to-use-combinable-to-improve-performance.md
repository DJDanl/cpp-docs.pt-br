---
title: Como usar combinável para melhorar o desempenho
ms.date: 11/04/2016
helpviewer_keywords:
- combinable class, example
- improving parallel performance with combinable [Concurrency Runtime]
ms.assetid: fa730580-1c94-4b2d-8aec-57c91dc0497e
ms.openlocfilehash: db27a791b2b92102118606712db4cbd2920f9619
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142435"
---
# <a name="how-to-use-combinable-to-improve-performance"></a>Como usar combinável para melhorar o desempenho

Este exemplo mostra como usar a classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) para calcular a soma dos números em um objeto [std:: array](../../standard-library/array-class-stl.md) que é primo. A classe `combinable` melhora o desempenho eliminando o estado compartilhado.

> [!TIP]
> Em alguns casos, o mapa paralelo ([Concurrency::p arallel_transform](reference/concurrency-namespace-functions.md#parallel_transform)) e a redução ([concurrency:: parallel_reduce](reference/concurrency-namespace-functions.md#parallel_reduce)) podem fornecer melhorias de desempenho em `combinable`. Para obter um exemplo que usa operações mapear e reduzir para produzir os mesmos resultados que este exemplo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="example---accumulate"></a>Exemplo – acumular

O exemplo a seguir usa a função [std:: Accumulate](../../standard-library/numeric-functions.md#accumulate) para computar a soma dos elementos em uma matriz que são primos. Neste exemplo, `a` é um objeto `array` e a função `is_prime` determina se seu valor de entrada é primo.

[!code-cpp[concrt-parallel-sum-of-primes#1](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-improve-performance_1.cpp)]

## <a name="example---parallel_for_each"></a>Exemplo – parallel_for_each

O exemplo a seguir mostra uma maneira simples de paralelizar o exemplo anterior. Este exemplo usa o algoritmo [Concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) para processar a matriz em paralelo e um objeto [concurrency:: critical_section](../../parallel/concrt/reference/critical-section-class.md) para sincronizar o acesso à variável `prime_sum`. Este exemplo não é dimensionado porque cada thread deve aguardar até que o recurso compartilhado fique disponível.

[!code-cpp[concrt-parallel-sum-of-primes#2](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-improve-performance_2.cpp)]

## <a name="example---combinable"></a>Exemplo-combinável

O exemplo a seguir usa um objeto `combinable` para melhorar o desempenho do exemplo anterior. Este exemplo elimina a necessidade de objetos de sincronização; Ele é dimensionado porque o objeto `combinable` permite que cada thread execute sua tarefa de forma independente.

Um objeto `combinable` geralmente é usado em duas etapas. Primeiro, produza uma série de computações refinadas executando o trabalho em paralelo. Em seguida, combine (ou reduza) os cálculos em um resultado final. Este exemplo usa o método [Concurrency:: combinable:: local](reference/combinable-class.md#local) para obter uma referência à soma local. Em seguida, ele usa o método [Concurrency:: combinável:: Combine](reference/combinable-class.md#combine) e um objeto [std::p exlu](../../standard-library/plus-struct.md) para combinar os cálculos locais com o resultado final.

[!code-cpp[concrt-parallel-sum-of-primes#3](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-improve-performance_3.cpp)]

## <a name="example---serial-and-parallel"></a>Exemplo – serial e paralelo

O exemplo completo a seguir computa a soma dos números primos em série e em paralelo. O exemplo imprime no console o tempo necessário para executar os dois cálculos.

[!code-cpp[concrt-parallel-sum-of-primes#4](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-improve-performance_4.cpp)]

A saída de exemplo a seguir é para um computador com quatro processadores.

```Output
1709600813
serial time: 6178 ms

1709600813
parallel time: 1638 ms
```

## <a name="compiling-the-code"></a>Compilando o Código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `parallel-sum-of-primes.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Parallel-Sum-of-Primes. cpp**

## <a name="robust-programming"></a>Programação Robusta

Para obter um exemplo que usa operações mapear e reduzir para produzir os mesmos resultados, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="see-also"></a>Consulte também

[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)<br/>
[Classe combinable](../../parallel/concrt/reference/combinable-class.md)<br/>
[Classe critical_section](../../parallel/concrt/reference/critical-section-class.md)
