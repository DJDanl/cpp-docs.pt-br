---
title: Como usar cancelamento para parar um loop paralelo
ms.date: 11/04/2016
helpviewer_keywords:
- writing a parallel search algorithm [Concurrency Runtime]
- parallel search algorithm, writing [Concurrency Runtime]
ms.assetid: 421cd2de-f058-465f-b890-dd8fcc0df273
ms.openlocfilehash: 21907de6c5625f7774ae788cef0449ac49107e40
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142142"
---
# <a name="how-to-use-cancellation-to-break-from-a-parallel-loop"></a>Como usar cancelamento para parar um loop paralelo

Este exemplo mostra como usar o cancelamento para implementar um algoritmo de pesquisa paralela básico.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir usa o cancelamento para pesquisar um elemento em uma matriz. A função `parallel_find_any` usa o algoritmo [Concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) e a função [concurrency:: run_with_cancellation_token](reference/concurrency-namespace-functions.md#run_with_cancellation_token) para pesquisar a posição que contém o valor especificado. Quando o loop paralelo encontra o valor, ele chama o método [Concurrency:: cancellation_token_source:: Cancel](reference/cancellation-token-source-class.md#cancel) para cancelar o trabalho futuro.

[!code-cpp[concrt-parallel-array-search#1](../../parallel/concrt/codesnippet/cpp/how-to-use-cancellation-to-break-from-a-parallel-loop_1.cpp)]

O algoritmo [Concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) atua simultaneamente. Portanto, ele não executa as operações em uma ordem predeterminada. Se a matriz contiver várias instâncias do valor, o resultado poderá ser qualquer uma de suas posições.

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `parallel-array-search.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Parallel-array-Search. cpp**

## <a name="see-also"></a>Consulte também

[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)<br/>
[Classe cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md)
