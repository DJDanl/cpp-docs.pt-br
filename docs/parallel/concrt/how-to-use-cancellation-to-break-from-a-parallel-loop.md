---
title: Como usar cancelamento para parar um loop paralelo
ms.date: 11/04/2016
helpviewer_keywords:
- writing a parallel search algorithm [Concurrency Runtime]
- parallel search algorithm, writing [Concurrency Runtime]
ms.assetid: 421cd2de-f058-465f-b890-dd8fcc0df273
ms.openlocfilehash: 2a19c2874ce331be2d4f5840f61cabf7bca9abf6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50612739"
---
# <a name="how-to-use-cancellation-to-break-from-a-parallel-loop"></a>Como usar cancelamento para parar um loop paralelo

Este exemplo mostra como usar cancelamento para implementar um algoritmo de pesquisa paralela básica.

## <a name="example"></a>Exemplo

O exemplo a seguir usa cancelamento para procurar um elemento em uma matriz. O `parallel_find_any` função usa o [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo e o [concurrency::run_with_cancellation_token](reference/concurrency-namespace-functions.md#run_with_cancellation_token) função Pesquisar a posição que contém o valor especificado. Quando o loop paralelo localiza o valor, ele chama o [concurrency::cancellation_token_source::cancel](reference/cancellation-token-source-class.md#cancel) método Cancelar trabalho futuro.

[!code-cpp[concrt-parallel-array-search#1](../../parallel/concrt/codesnippet/cpp/how-to-use-cancellation-to-break-from-a-parallel-loop_1.cpp)]

O [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo atua simultaneamente. Portanto, ele não executa as operações em uma ordem predeterminada. Se a matriz contiver várias instâncias do valor, o resultado pode ser qualquer uma das suas posições.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-array-search.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc paralelo-array-search.cpp**

## <a name="see-also"></a>Consulte também

[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)<br/>
[Classe cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md)
