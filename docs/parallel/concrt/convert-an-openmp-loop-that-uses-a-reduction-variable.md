---
title: "Como: converter um Loop OpenMP que usa uma variável de redução para usar o tempo de execução de simultaneidade | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- converting from OpenMP to the Concurrency Runtime, reduction variables
- reduction variables, converting from OpenMP to the Concurrency Runtime
ms.assetid: 96623f36-5e57-4d3f-8c13-669e6cd535b1
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f218bbc47fa33e6cc9546d032311417d9e10d554
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-convert-an-openmp-loop-that-uses-a-reduction-variable-to-use-the-concurrency-runtime"></a>Como converter um loop OpenMP que usa uma variável de redução para usar o tempo de execução de simultaneidade
Este exemplo demonstra como converter um OpenMP [paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../../parallel/openmp/reference/for-openmp.md) loop que usa o [redução](../../parallel/openmp/reference/reduction.md) cláusula para usar o tempo de execução de simultaneidade.  
  
 O OpenMP `reduction` cláusula permite que você especifique uma ou mais variáveis particulares de thread que estão sujeitas a uma operação de redução no final da região de dados paralelo. OpenMP predefine um conjunto de operadores de redução. Cada variável de reduction deve ser um valor escalar (por exemplo, `int`, `long`, e `float`). OpenMP define também várias restrições sobre como variáveis de redução são usadas em uma região parallel.  
  
 A biblioteca de padrões paralelos (PPL) fornece o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe, que fornece armazenamento reutilizável e local de thread, que permite executar computações refinadas e, em seguida, mesclar os cálculos em um final resultado. O `combinable` classe é um modelo que funciona em tipos escalares e complexos. Para usar o `combinable` classe, executar cálculos sub no corpo de uma construção paralela e, em seguida, chamar o [concurrency::combinable::combine](reference/combinable-class.md#combine) ou [concurrency::combinable::combine_each](reference/combinable-class.md#combine_each) método para produzir o resultado final. O `combine` e `combine_each` métodos cada levar uma *combinar função* que especifica como combinar cada par de elementos. Portanto, o `combinable` classe não é restrita a um conjunto fixo de operadores de redução.  
  
## <a name="example"></a>Exemplo  
 Este exemplo usa OpenMP e o tempo de execução de simultaneidade para calcular a soma dos números Fibonacci primeiro 35.  
  
 [!code-cpp[concrt-openmp#7](../../parallel/concrt/codesnippet/cpp/convert-an-openmp-loop-that-uses-a-reduction-variable_1.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
Using OpenMP...  
The sum of the first 35 Fibonacci numbers is 14930351.  
Using the Concurrency Runtime...  
The sum of the first 35 Fibonacci numbers is 14930351.  
```  
  
 Para obter mais informações sobre o `combinable` de classe, consulte [objetos e contêineres paralelos](../../parallel/concrt/parallel-containers-and-objects.md).  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `concrt-omp-fibonacci-reduction.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc /openmp concrt-omp-fibonacci-reduction.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Migrando de OpenMP no tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)   
 [Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)

