---
title: 'Como: Converter um loop OpenMP paralelo para Loop para usar o tempo de execução de simultaneidade'
ms.date: 11/04/2016
helpviewer_keywords:
- converting from OpenMP to the Concurrency Runtime, parallel for loops
- converting from OpenMP to the Concurrency Runtime, parallel loops
- parallel for loops, converting from OpenMP to the Concurrency Runtime
- parallel loops, converting from OpenMP to the Concurrency Runtime
ms.assetid: d8a7b656-f86c-456e-9c5d-a7d52f94646e
ms.openlocfilehash: bc408465f34f0558e9f426ae35b83d4610898414
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57296131"
---
# <a name="how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime"></a>Como: Converter um loop OpenMP paralelo para Loop para usar o tempo de execução de simultaneidade

Este exemplo demonstra como converter um loop básico que usa o OpenMP [paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel) e [para](../../parallel/openmp/reference/for-openmp.md) diretivas para usar o tempo de execução de simultaneidade [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo.

## <a name="example"></a>Exemplo

Este exemplo usa o OpenMP e o tempo de execução de simultaneidade para calcular a contagem de números primos em uma matriz de valores aleatórios.

[!code-cpp[concrt-openmp#1](../../parallel/concrt/codesnippet/cpp/how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Using OpenMP...
found 107254 prime numbers.
Using the Concurrency Runtime...
found 107254 prime numbers.
```

O `parallel_for` OpenMP 3.0 e o algoritmo permitem o tipo de índice a ser um tipo integral com sinal ou um tipo integral sem sinal. O `parallel_for` algoritmo também certifica-se de que o intervalo especificado não estourar um tipo com sinal. Versões do OpenMP 2.0 e 2.5 permite que somente os tipos de índice integral com sinal. O OpenMP também não valida o intervalo de índice.

A versão desse exemplo que usa o tempo de execução de simultaneidade também usa um [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) do objeto em vez da [atômica](../../parallel/openmp/reference/atomic.md) diretiva para incrementar o valor do contador sem a necessidade de sincronização.

Para obter mais informações sobre `parallel_for` e outros algoritmos em paralelo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md). Para obter mais informações sobre o `combinable` classe, consulte [paralela contêineres e objetos](../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="example"></a>Exemplo

Este exemplo modifica o exemplo anterior para agir em um [std:: array](../../standard-library/array-class-stl.md) do objeto, em vez de em uma matriz nativa. Porque o OpenMP versões 2.0 e 2.5 permitem para assinados tipos de índice integrais somente em um `parallel_for` constructo, você não pode usar iteradores para acessar os elementos de um contêiner de biblioteca padrão C++ em paralelo. A biblioteca de padrões paralelos (PPL) fornece o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo, que executa tarefas, em paralelo, em um contêiner iterativo, como as fornecidas pela biblioteca padrão C++. Ele usa a mesma lógica de particionamento que o `parallel_for` usa o algoritmo. O `parallel_for_each` algoritmo se parece com a biblioteca padrão C++ [std::for_each](../../standard-library/algorithm-functions.md#for_each) algoritmo, exceto que o `parallel_for_each` algoritmo executa as tarefas simultaneamente.

[!code-cpp[concrt-openmp#10](../../parallel/concrt/codesnippet/cpp/how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime_2.cpp)]

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `concrt-omp-count-primes.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc /openmp concrt-omp-count-primes.cpp**

## <a name="see-also"></a>Consulte também

[Migrando do OpenMP para o tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)
