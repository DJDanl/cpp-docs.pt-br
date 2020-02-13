---
title: Como gravar um loop parallel_for
ms.date: 11/04/2016
helpviewer_keywords:
- writing a parallel_for loop [Concurrency Runtime]
- parallel_for function, example
ms.assetid: adb4d64e-5514-4b70-8dcb-b9210e6b5a1c
ms.openlocfilehash: 5903114a12de46dc06929c83e9995b39d0136810
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141868"
---
# <a name="how-to-write-a-parallel_for-loop"></a>Como gravar um loop parallel_for

Este exemplo demonstra como usar a [simultaneidade::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) para computar o produto de duas matrizes.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a função `matrix_multiply`, que computa o produto de duas matrizes quadradas.

[!code-cpp[concrt-parallel-matrix-multiply#1](../../parallel/concrt/codesnippet/cpp/how-to-write-a-parallel-for-loop_1.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a função `parallel_matrix_multiply`, que usa o algoritmo `parallel_for` para executar o loop externo em paralelo.

[!code-cpp[concrt-parallel-matrix-multiply#2](../../parallel/concrt/codesnippet/cpp/how-to-write-a-parallel-for-loop_2.cpp)]

Este exemplo paralelize o loop externo somente porque ele executa um trabalho suficiente para se beneficiar da sobrecarga para processamento paralelo. Se você paralelizar o loop interno, não receberá um lucro no desempenho porque a pequena quantidade de trabalho que o loop interno realiza não supera a sobrecarga do processamento paralelo. Portanto, a paralelização do loop externo é apenas a melhor forma de maximizar os benefícios de simultaneidade na maioria dos sistemas.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mais completo compara o desempenho da função `matrix_multiply` versus a função `parallel_matrix_multiply`.

[!code-cpp[concrt-parallel-matrix-multiply#3](../../parallel/concrt/codesnippet/cpp/how-to-write-a-parallel-for-loop_3.cpp)]

A saída de exemplo a seguir é para um computador com quatro processadores.

```Output
serial: 3853
parallel: 1311
```

## <a name="compiling-the-code"></a>Compilando o Código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `parallel-matrix-multiply.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Parallel-Matrix-Multiply. cpp**

## <a name="see-also"></a>Consulte também

[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)
