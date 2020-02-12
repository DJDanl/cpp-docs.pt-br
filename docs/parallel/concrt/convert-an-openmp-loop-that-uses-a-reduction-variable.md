---
title: Como converter um loop OpenMP que usa uma variável de redução para usar o runtime de simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- converting from OpenMP to the Concurrency Runtime, reduction variables
- reduction variables, converting from OpenMP to the Concurrency Runtime
ms.assetid: 96623f36-5e57-4d3f-8c13-669e6cd535b1
ms.openlocfilehash: ee0a600f4234c3ebf4681ad92b5e3623be5665c3
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141270"
---
# <a name="how-to-convert-an-openmp-loop-that-uses-a-reduction-variable-to-use-the-concurrency-runtime"></a>Como converter um loop OpenMP que usa uma variável de redução para usar o runtime de simultaneidade

Este exemplo demonstra como converter um loop de OpenMP [paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md#parallel)[para](../../parallel/openmp/reference/for-openmp.md) que usa a cláusula de [redução](../../parallel/openmp/reference/reduction.md) para usar o tempo de execução de simultaneidade.

A cláusula de `reduction` de OpenMP permite especificar uma ou mais variáveis de thread privado que estão sujeitas a uma operação de redução no final da região paralela. O OpenMP predefine um conjunto de operadores de redução. Cada variável de redução deve ser um escalar (por exemplo, `int`, `long`e `float`). O OpenMP também define várias restrições sobre como as variáveis de redução são usadas em uma região paralela.

A PPL (biblioteca de padrões paralelos) fornece a classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) , que fornece armazenamento reutilizável e local de thread que permite executar cálculos refinados e, em seguida, mesclar esses cálculos em um resultado final. A classe `combinable` é um modelo que atua em tipos escalares e complexos. Para usar a classe `combinable`, execute subcoleções no corpo de uma construção paralela e, em seguida, chame o método [Concurrency:: Combined:: Combine](reference/combinable-class.md#combine) ou [Concurrency:: combinável:: combine_each](reference/combinable-class.md#combine_each) para produzir o resultado final. Os métodos `combine` e `combine_each` usam uma *função combinar* que especifica como combinar cada par de elementos. Portanto, a classe `combinable` não está restrita a um conjunto fixo de operadores de redução.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Este exemplo usa OpenMP e Tempo de Execução de Simultaneidade para calcular a soma dos primeiros 35 números de Fibonacci.

[!code-cpp[concrt-openmp#7](../../parallel/concrt/codesnippet/cpp/convert-an-openmp-loop-that-uses-a-reduction-variable_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Using OpenMP...
The sum of the first 35 Fibonacci numbers is 14930351.
Using the Concurrency Runtime...
The sum of the first 35 Fibonacci numbers is 14930351.
```

Para obter mais informações sobre a classe `combinable`, consulte [contêineres e objetos paralelos](../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `concrt-omp-fibonacci-reduction.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc/OpenMP ConcRT-OMP-Fibonacci-reduction. cpp**

## <a name="see-also"></a>Consulte também

[Migrando do OpenMP para o runtime de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)<br/>
[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)
