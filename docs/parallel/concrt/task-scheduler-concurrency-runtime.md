---
title: (Tempo de execução de simultaneidade) do Agendador de tarefas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 56f7f35169b349abb5f7db14b3f3a749ab7dd673
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46419731"
---
# <a name="task-scheduler-concurrency-runtime"></a>Agendador de tarefas (Tempo de Execução de Simultaneidade)

Os tópicos nessa parte da documentação descrevem os recursos importantes do Agendador de tarefas de tempo de execução de simultaneidade. O Agendador de tarefas é útil quando você deseja ajustar o desempenho do seu código existente que usa o tempo de execução de simultaneidade.

> [!IMPORTANT]
>  O Agendador de tarefas não está disponível a partir de um aplicativo da plataforma Universal do Windows (UWP). Para obter mais informações, consulte [criando a operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).
>
>  No Visual Studio 2015 e versões posteriores, o [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) classe e tipos relacionados em ppltasks. h usam o pool de threads do Windows como seu Agendador. Este tópico não se aplica a tipos que são definidos em ppltasks. h. Algoritmos paralelos, como parallel_for continuam a usar o tempo de execução de simultaneidade como o agendador padrão.

> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão e, portanto, não é necessário criá-lo em seu aplicativo. Como o Agendador de tarefas Ajuda você a ajustar o desempenho de seus aplicativos, é recomendável que você comece com o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou o [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você estiver novo no tempo de execução de simultaneidade.

O Agendador de tarefas agenda e coordena tarefas em tempo de execução. Um *tarefa* é uma unidade de trabalho que executa um trabalho específico. Normalmente, uma tarefa pode executar em paralelo com outras tarefas. O trabalho executado por agentes assíncronos de itens do grupo de tarefas e algoritmos paralelos são exemplos de tarefas.

O Agendador de tarefas gerencia os detalhes relacionados à eficiência agendamento de tarefas em computadores que têm vários recursos de computação. O Agendador de tarefas também usa os recursos mais recentes do sistema operacional subjacente. Portanto, os aplicativos que usam o tempo de execução de simultaneidade automaticamente dimensionarem e melhorar o hardware que tem recursos expandidos.

[Comparando com outros modelos de simultaneidade](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md) descreve as diferenças entre os mecanismos de agendamento preemptivas e cooperativas. O Agendador de tarefas usa cooperativo de agendamento e um algoritmo de roubo de trabalho junto com o Agendador preemptive do sistema operacional para alcançar a utilização máxima dos recursos de processamento.

O tempo de execução de simultaneidade fornece um agendador padrão para que você não precise gerenciar detalhes da infraestrutura. Portanto, você normalmente não usar o Agendador de tarefas diretamente. No entanto, para atender as necessidades de qualidade do seu aplicativo, você pode usar o Agendador de tarefas para fornecer seus próprio agendamento agendadores de política ou associar a tarefas específicas. Por exemplo, suponha que você tem um paralelo classificação rotina que não ultrapassará quatro processadores. Você pode usar *políticas de Agendador* para criar um agendador que gera mais do que quatro tarefas simultâneas. Executar a rotina de classificação neste Agendador permite que outros agendadores Active Directory para usar quaisquer recursos restantes do processamento.

## <a name="related-topics"></a>Tópicos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Instâncias de agendador](../../parallel/concrt/scheduler-instances.md)|Descreve as instâncias de agendador e como usar o `concurrency::Scheduler` e `concurrency::CurrentScheduler` classes para gerenciá-los. Quando você deseja associar políticas de agendamento explícitas com tipos específicos de cargas de trabalho, use instâncias de Agendador.|
|[Políticas de agendador](../../parallel/concrt/scheduler-policies.md)|Descreve a função de políticas de Agendador. Use políticas de Agendador quando você deseja controlar a estratégia que o Agendador usa quando ele gerencia as tarefas.|
|[Grupos Agendados](../../parallel/concrt/schedule-groups.md)|Descreve a função de grupos de agendamento. Use grupos de agendamento de quando você exige um alto grau de localidade entre tarefas, por exemplo, quando um grupo de tarefas relacionadas se beneficiar da execução no mesmo nó do processador.|
|[Tarefas leves](../../parallel/concrt/lightweight-tasks.md)|Descreve a função de tarefas leves. Tarefas leves são úteis quando você adaptar o código existente para usar a funcionalidade de agendamento de tempo de execução de simultaneidade.|
|[Contextos](../../parallel/concrt/contexts.md)|Descreve a função dos contextos, o `concurrency::wait` função e o `concurrency::Context` classe. Quando você precisa de controle sobre quando contextos de bloquear, desbloqueiam e produzam, ou quando você deseja habilitar o excesso de assinatura em seu aplicativo, use essa funcionalidade.|
|[Funções de gerenciamento da memória](../../parallel/concrt/memory-management-functions.md)|Descreve o `concurrency::Alloc` e `concurrency::Free` funções. Essas funções podem melhorar o desempenho de memória, alocando e liberando memória de forma simultânea.|
|[Comparando com outros modelos de simultaneidade](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md)|Descreve as diferenças entre os mecanismos de agendamento preemptivas e cooperativas.|
|[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Descreve como usar vários padrões paralelos, por exemplo, algoritmos paralelos, em seus aplicativos.|
|[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)|Descreve como usar agentes assíncronos em seus aplicativos.|
|[Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)|Descreve o tempo de execução de simultaneidade, que simplifica a programação paralela e contém links para tópicos relacionados.|

