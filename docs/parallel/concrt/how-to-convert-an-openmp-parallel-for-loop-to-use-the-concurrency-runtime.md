---
title: "Como: converter um loop OpenMP paralelo para Loop para usar o tempo de execução de simultaneidade | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- converting from OpenMP to the Concurrency Runtime, parallel for loops
- converting from OpenMP to the Concurrency Runtime, parallel loops
- parallel for loops, converting from OpenMP to the Concurrency Runtime
- parallel loops, converting from OpenMP to the Concurrency Runtime
ms.assetid: d8a7b656-f86c-456e-9c5d-a7d52f94646e
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a27e07884b4ada54f694136ea2fbca474c9d214d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime"></a>Como converter um loop OpenMP paralelo para loop para usar o tempo de execução de simultaneidade

Este exemplo demonstra como converter um loop básico que usa o OpenMP [paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel) e [para](../../parallel/openmp/reference/for-openmp.md) diretivas para usar o tempo de execução de simultaneidade [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo.  
  
## <a name="example"></a>Exemplo  
 Este exemplo usa OpenMP e o tempo de execução de simultaneidade para calcular a contagem de números primos em uma matriz de valores aleatórios.  
  
 [!code-cpp[concrt-openmp#1](../../parallel/concrt/codesnippet/cpp/how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime_1.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
Using OpenMP...  
found 107254 prime numbers.  
Using the Concurrency Runtime...  
found 107254 prime numbers.  
```  
  
 O `parallel_for` algoritmo e OpenMP 3.0 permitem para o tipo de índice para ser um tipo inteiro assinado ou um tipo inteiro sem sinal. O `parallel_for` algoritmo também garante que o intervalo especificado não estourar um tipo assinado. Versões de OpenMP 2.0 e 2.5 permite que somente os tipos de índice inteiro assinado. OpenMP também não valida o intervalo de índice.  
  
 A versão deste exemplo que usa o tempo de execução de simultaneidade também usa um [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) do objeto em vez do [atômico](../../parallel/openmp/reference/atomic.md) diretiva para incrementar o valor do contador sem a necessidade de sincronização.  
  
 Para obter mais informações sobre `parallel_for` e outros algoritmos de paralelo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md). Para obter mais informações sobre o `combinable` de classe, consulte [objetos e contêineres paralelos](../../parallel/concrt/parallel-containers-and-objects.md).  
  
## <a name="example"></a>Exemplo  

 Este exemplo modifica o um anterior para agir em um [std:: array](../../standard-library/array-class-stl.md) do objeto, em vez de em uma matriz nativa. Porque versões OpenMP 2.0 e 2.5 permitem para tipos integrais índice somente em um `parallel_for` construção, você não pode usar iteradores para acessar os elementos de um contêiner de biblioteca padrão C++ em paralelo. A biblioteca de padrões paralelos (PPL) fornece o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo, que executa tarefas, em paralelo, em um contêiner iterativo, como as fornecidas pela biblioteca C++ padrão. Ele usa a mesma lógica de particionamento que o `parallel_for` usa o algoritmo. O `parallel_for_each` algoritmo é semelhante a biblioteca padrão C++ [std::for_each](../../standard-library/algorithm-functions.md#for_each) algoritmo, exceto que o `parallel_for_each` algoritmo executa as tarefas simultaneamente.  
  
 [!code-cpp[concrt-openmp#10](../../parallel/concrt/codesnippet/cpp/how-to-convert-an-openmp-parallel-for-loop-to-use-the-concurrency-runtime_2.cpp)]  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `concrt-omp-count-primes.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc /openmp concrt-omp-contagem-primes.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Migrando de OpenMP no tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)   
 [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)   
 [Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)

