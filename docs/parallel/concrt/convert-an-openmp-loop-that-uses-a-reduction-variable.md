---
title: Como converter um loop OpenMP que usa uma variável de redução para usar o runtime de simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- converting from OpenMP to the Concurrency Runtime, reduction variables
- reduction variables, converting from OpenMP to the Concurrency Runtime
ms.assetid: 96623f36-5e57-4d3f-8c13-669e6cd535b1
ms.openlocfilehash: 06418bc1a331a5c77653087434a5cc621f92e7d7
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91498555"
---
# <a name="how-to-convert-an-openmp-loop-that-uses-a-reduction-variable-to-use-the-concurrency-runtime"></a>Como converter um loop OpenMP que usa uma variável de redução para usar o runtime de simultaneidade

Este exemplo demonstra como converter um loop de OpenMP [paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../openmp/reference/openmp-directives.md#for-openmp) que usa a cláusula de [redução](../openmp/reference/openmp-clauses.md#reduction) para usar o tempo de execução de simultaneidade.

A `reduction` cláusula OpenMP permite especificar uma ou mais variáveis de thread privado que estão sujeitas a uma operação de redução no final da região paralela. O OpenMP predefine um conjunto de operadores de redução. Cada variável de redução deve ser uma escala (por exemplo,, **`int`** **`long`** e **`float`** ). O OpenMP também define várias restrições sobre como as variáveis de redução são usadas em uma região paralela.

A PPL (biblioteca de padrões paralelos) fornece a classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) , que fornece armazenamento reutilizável e local de thread que permite executar cálculos refinados e, em seguida, mesclar esses cálculos em um resultado final. A `combinable` classe é um modelo que atua em tipos escalares e complexos. Para usar a `combinable` classe, execute subcoleções no corpo de uma construção paralela e, em seguida, chame o método [Concurrency:: Combining:: Combine](reference/combinable-class.md#combine) ou [Concurrency:: combinável:: combine_each](reference/combinable-class.md#combine_each) para produzir o resultado final. Os `combine` `combine_each` métodos e têm uma *função combinar* que especifica como combinar cada par de elementos. Portanto, a `combinable` classe não está restrita a um conjunto fixo de operadores de redução.

## <a name="example"></a>Exemplo

Este exemplo usa OpenMP e Tempo de Execução de Simultaneidade para calcular a soma dos primeiros 35 números de Fibonacci.

[!code-cpp[concrt-openmp#7](../../parallel/concrt/codesnippet/cpp/convert-an-openmp-loop-that-uses-a-reduction-variable_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Using OpenMP...
The sum of the first 35 Fibonacci numbers is 14930351.
Using the Concurrency Runtime...
The sum of the first 35 Fibonacci numbers is 14930351.
```

Para obter mais informações sobre a `combinable` classe, consulte [contêineres e objetos paralelos](../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `concrt-omp-fibonacci-reduction.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc/OpenMP ConcRT-OMP-Fibonacci-reduction. cpp**

## <a name="see-also"></a>Consulte também

[Migrando de OpenMP no Runtime de Simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)<br/>
[Contêineres e objetos paralelos](../../parallel/concrt/parallel-containers-and-objects.md)
