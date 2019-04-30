---
title: 'Como: Executar o mapa e reduzir as operações em paralelo'
ms.date: 11/04/2016
helpviewer_keywords:
- parallel_transform function, example
- parallel map and reduce, example
- parallel_reduce function, example
ms.assetid: 9d19fac0-4ab6-4380-a375-3b18eeb87720
ms.openlocfilehash: ba3ffb5cdae7dcc6f108f005fab33f9a1fee6a6f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62412703"
---
# <a name="how-to-perform-map-and-reduce-operations-in-parallel"></a>Como: Executar o mapa e reduzir as operações em paralelo

Este exemplo mostra como usar o [concurrency::parallel_transform](reference/concurrency-namespace-functions.md#parallel_transform) e [concurrency::parallel_reduce](reference/concurrency-namespace-functions.md#parallel_reduce) algoritmos e o [concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md)classe para contar as ocorrências de palavras nos arquivos.

Um *mapa* operação se aplica a uma função a cada valor em uma sequência. Um *reduzir* operação combina os elementos de uma sequência em um valor. Você pode usar a biblioteca padrão C++ [std::transform](../../standard-library/algorithm-functions.md#transform) e [std::accumulate](../../standard-library/numeric-functions.md#accumulate) funções para executar o mapa e reduzir as operações. No entanto, para melhorar o desempenho para muitos problemas, você pode usar o `parallel_transform` algoritmo para realizar a operação de mapa em paralelo e o `parallel_reduce` algoritmo para realizar a operação de redução em paralelo. Em alguns casos, você pode usar `concurrent_unordered_map` para executar o mapa e redução em uma única operação.

## <a name="example"></a>Exemplo

O exemplo a seguir conta as ocorrências de palavras nos arquivos. Ele usa [std:: Vector](../../standard-library/vector-class.md) para representar o conteúdo de dois arquivos. A operação de mapa calcula as ocorrências de cada palavra em cada vetor. A operação reduce acumula as contagens de palavras entre os dois vetores.

[!code-cpp[concrt-parallel-map-reduce#1](../../parallel/concrt/codesnippet/cpp/how-to-perform-map-and-reduce-operations-in-parallel_1.cpp)]

## <a name="compiling-the-code"></a>Compilando o código

Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-map-reduce.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc parallel-map-reduce.cpp**

## <a name="robust-programming"></a>Programação robusta

Neste exemplo, você pode usar o `concurrent_unordered_map` classe — que é definido em concurrent_unordered_map.h—to executar o mapa e reduzir em uma única operação.

[!code-cpp[concrt-parallel-map-reduce#2](../../parallel/concrt/codesnippet/cpp/how-to-perform-map-and-reduce-operations-in-parallel_2.cpp)]

Normalmente, você paralelizar apenas externo ou o loop interno. Se você tiver relativamente poucos arquivos e cada arquivo contém várias palavras, paralelizar o loop interno. Paralelizar o loop externo, se você tiver relativamente muitos arquivos e cada arquivo contém algumas palavras.

## <a name="see-also"></a>Consulte também

[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Função parallel_transform](reference/concurrency-namespace-functions.md#parallel_transform)<br/>
[Função parallel_reduce](reference/concurrency-namespace-functions.md#parallel_reduce)<br/>
[Classe concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md)
