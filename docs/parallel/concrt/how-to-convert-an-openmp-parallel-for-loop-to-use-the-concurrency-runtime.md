---
title: Como converter um loop OpenMP paralelo para loop para usar o runtime de simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- converting from OpenMP to the Concurrency Runtime, parallel for loops
- converting from OpenMP to the Concurrency Runtime, parallel loops
- parallel for loops, converting from OpenMP to the Concurrency Runtime
- parallel loops, converting from OpenMP to the Concurrency Runtime
ms.assetid: d8a7b656-f86c-456e-9c5d-a7d52f94646e
ms.openlocfilehash: 4f523f9f6de7f1ffb4c3b578b60de587239dffb6
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91507872"
---
# <a name="how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime"></a>Como converter um loop OpenMP paralelo para loop para usar o runtime de simultaneidade

Este exemplo demonstra como converter um loop básico que usa [as diretivas de](../openmp/reference/openmp-directives.md#for-openmp) OpenMP e [Parallel](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel) para usar o algoritmo de [arallel_for de simultaneidade de tempo de execução de simultaneidade::p](reference/concurrency-namespace-functions.md#parallel_for) .

## <a name="example---prime-count"></a>Exemplo – contagem de instruções

Este exemplo usa OpenMP e o Tempo de Execução de Simultaneidade para calcular a contagem de números primos em uma matriz de valores aleatórios.

[!code-cpp[concrt-openmp#1](../../parallel/concrt/codesnippet/cpp/how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Using OpenMP...
found 107254 prime numbers.
Using the Concurrency Runtime...
found 107254 prime numbers.
```

O `parallel_for` algoritmo e o OpenMP 3,0 permitem que o tipo de índice seja um tipo integral assinado ou um tipo integral não assinado. O `parallel_for` algoritmo também garante que o intervalo especificado não exceda um tipo assinado. As versões de OpenMP 2,0 e 2,5 permitem apenas tipos de índice integral assinados. O OpenMP também não valida o intervalo de índice.

A versão deste exemplo que usa o Tempo de Execução de Simultaneidade também usa um objeto [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) no lugar da diretiva [atômica](../openmp/reference/openmp-directives.md#atomic) para incrementar o valor do contador sem a necessidade de sincronização.

Para obter mais informações sobre o `parallel_for` e outros algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md). Para obter mais informações sobre a `combinable` classe, consulte [contêineres e objetos paralelos](../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="example---use-stdarray"></a>Exemplo – usar a matriz std:: array

Este exemplo modifica o anterior para agir em um objeto [std:: array](../../standard-library/array-class-stl.md) em vez de em uma matriz nativa. Como as versões de OpenMP 2,0 e 2,5 permitem apenas tipos de índice integrais assinados em uma `parallel_for` construção, você não pode usar iteradores para acessar os elementos de um contêiner de biblioteca padrão C++ em paralelo. A PPL (biblioteca de padrões paralelos) fornece o algoritmo [Concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) , que executa tarefas, em paralelo, em um contêiner iterativo, como os fornecidos pela biblioteca padrão C++. Ele usa a mesma lógica de particionamento que o `parallel_for` algoritmo usa. O `parallel_for_each` algoritmo é semelhante ao algoritmo [std:: For_each](../../standard-library/algorithm-functions.md#for_each) da biblioteca padrão C++, exceto pelo fato de que o `parallel_for_each` algoritmo executa as tarefas simultaneamente.

[!code-cpp[concrt-openmp#10](../../parallel/concrt/codesnippet/cpp/how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime_2.cpp)]

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `concrt-omp-count-primes.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc/OpenMP ConcRT-OMP-Count-Primes. cpp**

## <a name="see-also"></a>Consulte também

[Migrando de OpenMP no Runtime de Simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Contêineres e objetos paralelos](../../parallel/concrt/parallel-containers-and-objects.md)
