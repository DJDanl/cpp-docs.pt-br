---
title: Como gravar um loop parallel_for_each
ms.date: 11/04/2016
helpviewer_keywords:
- writing a parallel_for_each loop [Concurrency Runtime]
- parallel_for_each function, example
ms.assetid: fa9c0ba6-ace0-4f88-8681-c7c1f52aff20
ms.openlocfilehash: 10c281b7db92e2706b20a1c7377fcdb9d924152d
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141883"
---
# <a name="how-to-write-a-parallel_for_each-loop"></a>Como gravar um loop parallel_for_each

Este exemplo mostra como usar o algoritmo [Concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) para calcular a contagem de números primos em um objeto [std:: array](../../standard-library/array-class-stl.md) em paralelo.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir computa a contagem de números primos em uma matriz duas vezes. O exemplo primeiro usa o algoritmo [std:: for_each](../../standard-library/algorithm-functions.md#for_each) para calcular a contagem em série. Em seguida, o exemplo usa o algoritmo `parallel_for_each` para executar a mesma tarefa em paralelo. O exemplo também imprime no console o tempo necessário para executar os dois cálculos.

[!code-cpp[concrt-parallel-count-primes#1](../../parallel/concrt/codesnippet/cpp/how-to-write-a-parallel-for-each-loop_1.cpp)]

A saída de exemplo a seguir é para um computador com quatro processadores.

```Output
serial version:
found 17984 prime numbers
took 6115 ms

parallel version:
found 17984 prime numbers
took 1653 ms
```

## <a name="compiling-the-code"></a>Compilando o Código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `parallel-count-primes.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Parallel-Count-Primes. cpp**

## <a name="robust-programming"></a>Programação Robusta

A expressão lambda que o exemplo passa para o algoritmo `parallel_for_each` usa a função `InterlockedIncrement` para habilitar iterações paralelas do loop para incrementar o contador simultaneamente. Se você usar funções como `InterlockedIncrement` para sincronizar o acesso a recursos compartilhados, poderá apresentar gargalos de desempenho em seu código. Você pode usar um mecanismo de sincronização sem bloqueio, por exemplo, a classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) , para eliminar o acesso simultâneo a recursos compartilhados. Para obter um exemplo que usa a classe `combinable` dessa maneira, consulte [como: usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md).

## <a name="see-also"></a>Consulte também

[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Função parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each)
