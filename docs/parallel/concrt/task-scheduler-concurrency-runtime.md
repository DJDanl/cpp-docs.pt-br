---
title: "(Tempo de execução de simultaneidade) do Agendador de tarefas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "42"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cf8577b9fcb5ac734ee9eb935688002dbfe162da
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="task-scheduler-concurrency-runtime"></a>Agendador de tarefas (Tempo de Execução de Simultaneidade)
Os tópicos desta parte da documentação descrevem os recursos importantes do Agendador de tarefas de tempo de execução de simultaneidade. O Agendador de tarefas é útil quando você deseja ajustar o desempenho do seu código existente que usa o tempo de execução de simultaneidade.  
  
> [!IMPORTANT]
>  O Agendador de tarefas não está disponível em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo. Para obter mais informações, consulte [Criando operações assíncronas em C++ para aplicativos da Windows Store](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).  
>   
>  No Visual Studio 2015 e posteriores, o [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) classe e tipos relacionados no ppltasks usam ThreadPool Windows como seu Agendador. Este tópico não se aplica a tipos que são definidos em ppltasks. Algoritmos paralelos, como parallel_for continuam a usar o tempo de execução de simultaneidade como o agendador padrão.  
  
> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão e, portanto, não é necessário criá-lo em seu aplicativo. Como o Agendador de tarefas Ajuda a ajustar o desempenho de seus aplicativos, é recomendável que você inicie com o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você estiver novo no tempo de execução de simultaneidade.  
  
 O Agendador de tarefas agenda e coordena as tarefas em tempo de execução. Um *tarefa* é uma unidade de trabalho que executa um trabalho específico. Normalmente, uma tarefa pode executar em paralelo com outras tarefas. O trabalho é executado por agentes assíncronos, os algoritmos paralelos e itens do grupo de tarefas são exemplos de tarefas.  
  
 O Agendador de tarefas gerencia os detalhes relacionados à eficiência agendamento de tarefas em computadores que têm vários recursos de computação. O Agendador de tarefas também usa os recursos mais recentes do sistema operacional subjacente. Portanto, os aplicativos que usam o tempo de execução de simultaneidade automaticamente dimensionar e melhorar no hardware que tem recursos expandidos.  
  
 [Comparando com outros modelos de simultaneidade](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md) descreve as diferenças entre os mecanismos de agendamento preventivos e cooperativos. O Agendador de tarefas usa cooperativo de agendamento e um algoritmo de roubo de trabalho junto com o Agendador preemptivo do sistema operacional para obter o máximo uso dos recursos de processamento.  
  
 O tempo de execução de simultaneidade fornece um agendador padrão para que você não precisa gerenciar detalhes de infraestrutura. Portanto, você normalmente não usa o Agendador de tarefas diretamente. No entanto, para atender as necessidades de qualidade do seu aplicativo, você pode usar o Agendador de tarefas para fornecer seus próprio agendamento agendadores de política ou associar tarefas específicas. Por exemplo, suponha que você tem um paralelo classificação rotina não ultrapassará quatro processadores. Você pode usar *políticas de Agendador* para criar um agendador que gera mais do que quatro tarefas simultâneas. Executar a rotina de classificação neste Agendador permite que outros agendadores ativos usar quaisquer recursos de processamento restantes.  
  
## <a name="related-topics"></a>Tópicos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Instâncias de agendador](../../parallel/concrt/scheduler-instances.md)|Descreve instâncias de agendador e como usar o `concurrency::Scheduler` e `concurrency::CurrentScheduler` classes para gerenciá-los. Use instâncias de Agendador quando você deseja associar políticas de agendamento explícitas com tipos específicos de cargas de trabalho.|  
|[Políticas de agendador](../../parallel/concrt/scheduler-policies.md)|Descreve a função de políticas de Agendador. Use políticas de Agendador quando você deseja controlar a estratégia que o Agendador usa quando ele gerencia as tarefas.|  
|[Grupos Agendados](../../parallel/concrt/schedule-groups.md)|Descreve a função de grupos de agendamento. Use grupos de agendamento de quando você exigir um alto grau de localidade entre tarefas, por exemplo, quando um grupo de tarefas relacionadas se beneficiar de execução no mesmo nó do processador.|  
|[Tarefas leves](../../parallel/concrt/lightweight-tasks.md)|Descreve a função de tarefas leves. Tarefas leves são úteis quando você adaptar o código existente para usar a funcionalidade de agendamento de tempo de execução de simultaneidade.|  
|[Contextos](../../parallel/concrt/contexts.md)|Descreve a função de contextos, a `concurrency::wait` função e o `concurrency::Context` classe. Use essa funcionalidade quando precisar de controle sobre quando contextos bloquear, desbloqueiam e produzem, ou quando você deseja habilitar o excesso de assinatura em seu aplicativo.|  
|[Funções de gerenciamento da memória](../../parallel/concrt/memory-management-functions.md)|Descreve o `concurrency::Alloc` e `concurrency::Free` funções. Essas funções podem melhorar o desempenho de memória por alocar e liberar memória de forma simultânea.|  
|[Comparando com outros modelos de simultaneidade](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md)|Descreve as diferenças entre os mecanismos de agendamento preventivos e cooperativos.|  
|[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Descreve como usar vários padrões paralelos, por exemplo, os algoritmos paralelos, em seus aplicativos.|  
|[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)|Descreve como usar agentes assíncronos em seus aplicativos.|  
|[Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)|Descreve o tempo de execução de simultaneidade, que simplifica a programação paralela e contém links para tópicos relacionados.|

