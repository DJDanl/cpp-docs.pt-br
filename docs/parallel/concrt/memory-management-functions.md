---
title: "Funções de gerenciamento de memória | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- memory management functions [Concurrency Runtime]
ms.assetid: d303dd2a-dfa4-4d90-a508-f6aa290bb9ea
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 309080a807a1325bbf921657a152cff60e87cb95
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="memory-management-functions"></a>Funções de gerenciamento da memória
Este documento descreve as funções de gerenciamento de memória que fornece o tempo de execução de simultaneidade para ajudá-lo a alocar e liberar memória, de forma simultânea.  
  
> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão e, portanto, não é necessário criá-lo em seu aplicativo. Como o Agendador de tarefas Ajuda a ajustar o desempenho de seus aplicativos, é recomendável que você inicie com o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você estiver novo no tempo de execução de simultaneidade.  
  
 O tempo de execução de simultaneidade fornece duas funções de gerenciamento de memória que são otimizadas para alocar e liberar blocos de memória de forma simultânea. O [concurrency::Alloc](reference/concurrency-namespace-functions.md#alloc) função aloca um bloco de memória usando o tamanho especificado. O [concurrency::Free](reference/concurrency-namespace-functions.md#free) função libera a memória que foi alocada por `Alloc`.  
  
> [!NOTE]
>  O `Alloc` e `Free` funções dependem uns aos outros. Use o `Free` função apenas para liberar memória alocar usando o `Alloc` função. Além disso, quando você usa o `Alloc` função para alocar a memória, use apenas o `Free` função para liberar memória.  
  
 Use o `Alloc` e `Free` funciona quando você aloca e liberar um conjunto fixo de tamanhos de alocação de tarefas ou segmentos diferentes. O tempo de execução de simultaneidade caches de memória que aloca do heap de tempo de execução C. O tempo de execução de simultaneidade mantém um cache de memória separada para cada thread em execução; Portanto, o tempo de execução gerencia memória sem o uso de bloqueios ou barreiras de memória. Um aplicativo se beneficia mais o `Alloc` e `Free` funções quando o cache de memória é acessado com mais frequência. Por exemplo, um thread que chama frequentemente ambos `Alloc` e `Free` benefícios mais de um thread que chama principalmente `Alloc` ou `Free`.  
  
> [!NOTE]
>  Quando você usar essas funções de gerenciamento de memória e seu usos aplicativo muita memória, o aplicativo pode inserir uma condição de pouca memória antes que o esperado. Como os blocos de memória são armazenados em cache por um thread não estão disponíveis para qualquer outro thread, se um thread tem muita memória, essa memória não está disponível.  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo que usa o `Alloc` e `Free` funções para melhorar o desempenho de memória, consulte [como: usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md).  
  
## <a name="see-also"></a>Consulte também  
 [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Como usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md)

