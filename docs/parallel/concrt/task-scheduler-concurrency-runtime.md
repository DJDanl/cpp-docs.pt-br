---
title: Agendador de tarefas (Runtime de Simultaneidade)
ms.date: 11/04/2016
helpviewer_keywords:
- oversubscription [Concurrency Runtime]
- task scheduler [Concurrency Runtime], oversubscription
- schedule groups [Concurrency Runtime]
- task scheduler [Concurrency Runtime], lightweight tasks
- task scheduler [Concurrency Runtime]
- lightweight tasks [Concurrency Runtime]
- task scheduler [Concurrency Runtime], scheduler policies
- task scheduler [Concurrency Runtime], schedule groups
- wait function [Concurrency Runtime]
- task scheduler [Concurrency Runtime], scheduler instances
- scheduler instances [Concurrency Runtime]
- scheduler policies [Concurrency Runtime]
- task scheduler [Concurrency Runtime], wait function
ms.assetid: 9aba278c-e0c9-4ede-b7c6-fedf7a365d90
ms.openlocfilehash: e4a2e66afe656f9588ed3040218d1f70b3684190
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77143303"
---
# <a name="task-scheduler-concurrency-runtime"></a>Agendador de tarefas (Runtime de Simultaneidade)

Os tópicos desta parte da documentação descrevem os recursos importantes do Agendador de Tarefas de Tempo de Execução de Simultaneidade. O Agendador de Tarefas é útil quando você deseja ajustar o desempenho do seu código existente que usa o Tempo de Execução de Simultaneidade.

> [!IMPORTANT]
> O Agendador de Tarefas não está disponível em um aplicativo de Plataforma Universal do Windows (UWP). Para obter mais informações, consulte [criando operações assíncronas no C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).
>
> No Visual Studio 2015 e posterior, a classe [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) e os tipos relacionados em ppltasks. h usam o ThreadPool do Windows como seu Agendador. Este tópico não se aplica mais a tipos que são definidos em ppltasks. h. Os algoritmos paralelos, como parallel_for, continuam a usar o Tempo de Execução de Simultaneidade como o agendador padrão.

> [!TIP]
> O Tempo de Execução de Simultaneidade fornece um agendador padrão e, portanto, não é necessário criar um em seu aplicativo. Como o Agendador de Tarefas ajuda você a ajustar o desempenho de seus aplicativos, recomendamos que você comece com a [ppl (biblioteca de padrões paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou a [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você for novo no tempo de execução de simultaneidade.

O Agendador de Tarefas agenda e coordena tarefas em tempo de execução. Uma *tarefa* é uma unidade de trabalho que executa um trabalho específico. Normalmente, uma tarefa pode ser executada em paralelo com outras tarefas. O trabalho executado por itens de grupo de tarefas, algoritmos paralelos e agentes assíncronos são exemplos de tarefas.

O Agendador de Tarefas gerencia os detalhes relacionados ao agendamento eficiente de tarefas em computadores com vários recursos de computação. O Agendador de Tarefas também usa os recursos mais recentes do sistema operacional subjacente. Portanto, os aplicativos que usam o Tempo de Execução de Simultaneidade são automaticamente dimensionados e aprimorados em hardware com recursos expandidos.

A [comparação com outros modelos de simultaneidade](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md) descreve as diferenças entre os mecanismos de agendamento preventivo e cooperativos. O Agendador de Tarefas usa agendamento cooperativo e um algoritmo de roubo de trabalho junto com o Agendador preventivo do sistema operacional para obter o uso máximo de recursos de processamento.

O Tempo de Execução de Simultaneidade fornece um agendador padrão para que você não precise gerenciar os detalhes da infraestrutura. Portanto, normalmente você não usa o Agendador de Tarefas diretamente. No entanto, para atender às necessidades de qualidade do seu aplicativo, você pode usar o Agendador de Tarefas para fornecer sua própria política de agendamento ou associar agendadores a tarefas específicas. Por exemplo, suponha que você tenha uma rotina de classificação paralela que não dimensione além de quatro processadores. Você pode usar *as políticas do Agendador* para criar um Agendador que não gere mais do que quatro tarefas simultâneas. A execução da rotina de classificação neste Agendador permite que outros agendadores ativos usem os demais recursos de processamento.

## <a name="related-topics"></a>Tópicos Relacionados

|{1&gt;Título&lt;1}|Descrição|
|-----------|-----------------|
|[Instâncias de agendador](../../parallel/concrt/scheduler-instances.md)|Descreve as instâncias do Agendador e como usar as classes `concurrency::Scheduler` e `concurrency::CurrentScheduler` para gerenciá-las. Use instâncias do Agendador quando desejar associar políticas de agendamento explícitas a tipos específicos de cargas de trabalho.|
|[Políticas de agendador](../../parallel/concrt/scheduler-policies.md)|Descreve a função de políticas do Agendador. Use as políticas do Agendador quando desejar controlar a estratégia que o Agendador usa ao gerenciar tarefas.|
|[Grupos Agendados](../../parallel/concrt/schedule-groups.md)|Descreve a função de grupos de agendamento. Use grupos de agendamento quando precisar de um alto grau de localidade entre tarefas, por exemplo, quando um grupo de tarefas relacionadas se beneficiar da execução no mesmo nó do processador.|
|[Tarefas leves](../../parallel/concrt/lightweight-tasks.md)|Descreve a função de tarefas leves. Tarefas leves são úteis quando você adapta o código existente para usar a funcionalidade de agendamento do Tempo de Execução de Simultaneidade.|
|[Contextos](../../parallel/concrt/contexts.md)|Descreve a função de contextos, a função `concurrency::wait` e a classe `concurrency::Context`. Use essa funcionalidade quando precisar de controle quando contextos bloquear, desbloquear e gerar, ou quando você quiser habilitar a assinatura em excesso em seu aplicativo.|
|[Funções de gerenciamento da memória](../../parallel/concrt/memory-management-functions.md)|Descreve as funções `concurrency::Alloc` e `concurrency::Free`. Essas funções podem melhorar o desempenho da memória alocando e liberando memória de maneira simultânea.|
|[Comparando com outros modelos de simultaneidade](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md)|Descreve as diferenças entre mecanismos de agendamento preventivo e cooperativos.|
|[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Descreve como usar vários padrões paralelos, por exemplo, algoritmos paralelos, em seus aplicativos.|
|[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)|Descreve como usar agentes assíncronos em seus aplicativos.|
|[Runtime de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)|Descreve o Tempo de Execução de Simultaneidade, que simplifica a programação paralela e contém links para tópicos relacionados.|
