---
title: 'Como: Converter um Loop OpenMP que usa uma variável de redução para usar o tempo de execução de simultaneidade'
ms.date: 11/04/2016
helpviewer_keywords:
- converting from OpenMP to the Concurrency Runtime, reduction variables
- reduction variables, converting from OpenMP to the Concurrency Runtime
ms.assetid: 96623f36-5e57-4d3f-8c13-669e6cd535b1
ms.openlocfilehash: d75e115bdb1d13c9e8f45ed67d0f3993eac1b387
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62413951"
---
# <a name="how-to-convert-an-openmp-loop-that-uses-a-reduction-variable-to-use-the-concurrency-runtime"></a>Como: Converter um Loop OpenMP que usa uma variável de redução para usar o tempo de execução de simultaneidade

Este exemplo demonstra como converter um OpenMP [paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../../parallel/openmp/reference/for-openmp.md) loop que usa o [redução](../../parallel/openmp/reference/reduction.md) cláusula para usar o tempo de execução de simultaneidade.

O OpenMP `reduction` cláusula permite que você especifique uma ou mais variáveis de thread privados estão sujeitas a uma operação de redução no final da região paralela. OpenMP predefine um conjunto de operadores de redução. Cada variável de redução deve ser um escalar (por exemplo, `int`, `long`, e `float`). O OpenMP também define várias restrições sobre como as variáveis de redução são usadas em uma região paralela.

A biblioteca de padrões paralelos (PPL) fornece o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe, que fornece armazenamento reutilizável, locais de thread que lhe permite realizar cálculos refinados e, em seguida, mesclar esses cálculos em um final resultado. O `combinable` classe é um modelo que age em tipos complexos e escalares. Para usar o `combinable` classe, executar cálculos subpropriedades no corpo de uma construção paralela e, em seguida, chamar o [concurrency::combinable::combine](reference/combinable-class.md#combine) ou [concurrency::combinable::combine_each](reference/combinable-class.md#combine_each) método para produzir o resultado final. O `combine` e `combine_each` cada métodos usam um *combinar a função* que especifica como combinar cada par de elementos. Portanto, o `combinable` classe não está restrito a um conjunto fixo de operadores de redução.

## <a name="example"></a>Exemplo

Este exemplo usa o OpenMP e o tempo de execução de simultaneidade para calcular a soma dos números de Fibonacci 35 pela primeira vez.

[!code-cpp[concrt-openmp#7](../../parallel/concrt/codesnippet/cpp/convert-an-openmp-loop-that-uses-a-reduction-variable_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Using OpenMP...
The sum of the first 35 Fibonacci numbers is 14930351.
Using the Concurrency Runtime...
The sum of the first 35 Fibonacci numbers is 14930351.
```

Para obter mais informações sobre o `combinable` classe, consulte [paralela contêineres e objetos](../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `concrt-omp-fibonacci-reduction.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc /openmp concrt-omp-fibonacci-reduction.cpp**

## <a name="see-also"></a>Consulte também

[Migrando do OpenMP para o tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)<br/>
[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)
