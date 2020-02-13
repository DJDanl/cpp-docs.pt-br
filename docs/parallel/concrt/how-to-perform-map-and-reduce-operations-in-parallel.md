---
title: Como realizar operações de mapa e redução em paralelo
ms.date: 11/04/2016
helpviewer_keywords:
- parallel_transform function, example
- parallel map and reduce, example
- parallel_reduce function, example
ms.assetid: 9d19fac0-4ab6-4380-a375-3b18eeb87720
ms.openlocfilehash: 599e46c05a91a1f2ea6e317fe024d3c98a78977f
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141703"
---
# <a name="how-to-perform-map-and-reduce-operations-in-parallel"></a>Como realizar operações de mapa e redução em paralelo

Este exemplo mostra como usar os algoritmos de [simultaneidade::p arallel_transform](reference/concurrency-namespace-functions.md#parallel_transform) e [concurrency::p arallel_reduce](reference/concurrency-namespace-functions.md#parallel_reduce) e a classe [Concurrency:: concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md) para contar as ocorrências de palavras nos arquivos.

Uma operação de *mapa* aplica uma função a cada valor em uma sequência. Uma operação de *redução* combina os elementos de uma sequência em um valor. Você pode usar as C++ funções padrão de biblioteca [std:: Transform](../../standard-library/algorithm-functions.md#transform) e [std:: Accumulate](../../standard-library/numeric-functions.md#accumulate) para executar operações de mapeamento e redução. No entanto, para melhorar o desempenho de muitos problemas, você pode usar o algoritmo de `parallel_transform` para executar a operação de mapeamento em paralelo e o algoritmo de `parallel_reduce` para executar a operação de redução em paralelo. Em alguns casos, você pode usar `concurrent_unordered_map` para executar o mapa e a redução em uma única operação.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir conta as ocorrências de palavras em arquivos. Ele usa [std:: vector](../../standard-library/vector-class.md) para representar o conteúdo de dois arquivos. A operação de mapa computa as ocorrências de cada palavra em cada vetor. A operação de redução acumula as contagens de palavras em ambos os vetores.

[!code-cpp[concrt-parallel-map-reduce#1](../../parallel/concrt/codesnippet/cpp/how-to-perform-map-and-reduce-operations-in-parallel_1.cpp)]

## <a name="compiling-the-code"></a>Compilando o Código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `parallel-map-reduce.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Parallel-MAP-Reduce. cpp**

## <a name="robust-programming"></a>Programação Robusta

Neste exemplo, você pode usar a classe `concurrent_unordered_map`, que é definida em concurrent_unordered_map. h — para executar o mapa e reduzir em uma operação.

[!code-cpp[concrt-parallel-map-reduce#2](../../parallel/concrt/codesnippet/cpp/how-to-perform-map-and-reduce-operations-in-parallel_2.cpp)]

Normalmente, você paraleliza somente o loop externo ou o interno. Paralelizar o loop interno se você tiver relativamente poucos arquivos e cada arquivo contiver muitas palavras. Paralelizar o loop externo se você tiver relativamente muitos arquivos e cada arquivo contiver algumas palavras.

## <a name="see-also"></a>Consulte também

[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Função parallel_transform](reference/concurrency-namespace-functions.md#parallel_transform)<br/>
[Função parallel_reduce](reference/concurrency-namespace-functions.md#parallel_reduce)<br/>
[Classe concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md)
