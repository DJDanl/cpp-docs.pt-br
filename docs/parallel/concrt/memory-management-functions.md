---
title: Funções de gerenciamento da memória
ms.date: 11/04/2016
helpviewer_keywords:
- memory management functions [Concurrency Runtime]
ms.assetid: d303dd2a-dfa4-4d90-a508-f6aa290bb9ea
ms.openlocfilehash: aa1951211283ddf7e4823a920d5cdf19bd6d977d
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141835"
---
# <a name="memory-management-functions"></a>Funções de gerenciamento da memória

Este documento descreve as funções de gerenciamento de memória que o Tempo de Execução de Simultaneidade fornece para ajudá-lo a alocar e liberar memória de maneira simultânea.

> [!TIP]
> O Tempo de Execução de Simultaneidade fornece um agendador padrão e, portanto, não é necessário criar um em seu aplicativo. Como o Agendador de Tarefas ajuda você a ajustar o desempenho de seus aplicativos, recomendamos que você comece com a [ppl (biblioteca de padrões paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou a [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você for novo no tempo de execução de simultaneidade.

O Tempo de Execução de Simultaneidade fornece duas funções de gerenciamento de memória que são otimizadas para alocar e liberar blocos de memória de maneira simultânea. A função [Concurrency:: Alloc](reference/concurrency-namespace-functions.md#alloc) aloca um bloco de memória usando o tamanho especificado. A função [Concurrency:: Free](reference/concurrency-namespace-functions.md#free) libera a memória que foi alocada por `Alloc`.

> [!NOTE]
> As funções `Alloc` e `Free` dependem umas das outras. Use a função `Free` apenas para liberar memória que você aloca usando a função `Alloc`. Além disso, quando você usa a função `Alloc` para alocar memória, use apenas a função `Free` para liberar essa memória.

Use as funções `Alloc` e `Free` ao alocar e liberar um conjunto fixo de tamanhos de alocação de diferentes threads ou tarefas. O Tempo de Execução de Simultaneidade armazena em cache a memória que ele aloca a partir do heap de tempo de execução C. O Tempo de Execução de Simultaneidade mantém um cache de memória separado para cada thread em execução; Portanto, o tempo de execução gerencia a memória sem o uso de bloqueios ou barreiras de memória. Um aplicativo se beneficia mais das funções `Alloc` e `Free` quando o cache de memória é acessado com mais frequência. Por exemplo, um thread que geralmente chama `Alloc` e `Free` beneficia mais do que um thread que chama principalmente `Alloc` ou `Free`.

> [!NOTE]
> Quando você usa essas funções de gerenciamento de memória e seu aplicativo usa muita memória, o aplicativo pode inserir uma condição de memória insuficiente antes do esperado. Como os blocos de memória armazenados em cache por um thread não estão disponíveis para nenhum outro thread, se um thread mantiver muita memória, essa memória não estará disponível.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Para obter um exemplo que usa as funções `Alloc` e `Free` para melhorar o desempenho da memória, consulte [como: usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md).

## <a name="see-also"></a>Consulte também

[Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Como usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md)
