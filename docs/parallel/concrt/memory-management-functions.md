---
title: Funções de gerenciamento da memória
ms.date: 11/04/2016
helpviewer_keywords:
- memory management functions [Concurrency Runtime]
ms.assetid: d303dd2a-dfa4-4d90-a508-f6aa290bb9ea
ms.openlocfilehash: d8dfc8bbb200258818c38e931e978cc3be292525
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50454074"
---
# <a name="memory-management-functions"></a>Funções de gerenciamento da memória

Este documento descreve as funções de gerenciamento de memória que o tempo de execução de simultaneidade oferece para ajudá-lo a alocar e liberar memória, de forma simultânea.

> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão e, portanto, não é necessário criá-lo em seu aplicativo. Como o Agendador de tarefas Ajuda você a ajustar o desempenho de seus aplicativos, é recomendável que você comece com o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou o [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você estiver novo no tempo de execução de simultaneidade.

O tempo de execução de simultaneidade fornece duas funções de gerenciamento de memória que são otimizadas para alocar e liberar os blocos de memória de forma simultânea. O [concurrency::Alloc](reference/concurrency-namespace-functions.md#alloc) função aloca um bloco de memória usando o tamanho especificado. O [concurrency::Free](reference/concurrency-namespace-functions.md#free) função libera a memória alocada por `Alloc`.

> [!NOTE]
>  O `Alloc` e `Free` funções dependem uns aos outros. Use o `Free` função apenas para liberar a memória alocada usando o `Alloc` função. Além disso, quando você usa o `Alloc` função para alocar memória, use apenas o `Free` função para liberar memória.

Use o `Alloc` e `Free` funciona quando você alocar e liberar um conjunto fixo de tamanhos de alocação de tarefas ou threads diferentes. O tempo de execução de simultaneidade caches de memória que aloca do heap do tempo de execução C. O tempo de execução de simultaneidade mantém um cache de memória separados para cada thread em execução; Portanto, o tempo de execução gerencia a memória sem o uso de bloqueios ou as barreiras de memória. Um aplicativo se beneficia ainda mais a `Alloc` e `Free` funções quando o cache de memória é acessado com mais frequência. Por exemplo, um thread que chama frequentemente `Alloc` e `Free` benefícios mais do que um thread que chama principalmente `Alloc` ou `Free`.

> [!NOTE]
>  Quando você usar essas funções de gerenciamento de memória e seu usos de aplicativo muita memória, o aplicativo pode inserir uma condição de pouca memória antes que você espera. Como os blocos de memória são armazenados em cache por um thread não estão disponíveis para outros threads, se um thread mantiver muita memória, que a memória não está disponível.

## <a name="example"></a>Exemplo

Para obter um exemplo que usa o `Alloc` e `Free` funções para melhorar o desempenho de memória, consulte [como: usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md).

## <a name="see-also"></a>Consulte também

[Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Como usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md)

