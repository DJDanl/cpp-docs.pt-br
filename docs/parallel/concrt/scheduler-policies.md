---
title: Políticas de Agendador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- scheduler policies
ms.assetid: 58fb68bd-4a57-40a8-807b-6edb6f083cd9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7d9c855260df34290d01f1eeeee89e8bfe8988de
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33690401"
---
# <a name="scheduler-policies"></a>Políticas de agendador
Este documento descreve a função de políticas de Agendador no tempo de execução de simultaneidade. Um *política Agendador* controla a estratégia que o Agendador usa quando ele gerencia as tarefas. Por exemplo, considere um aplicativo que exige algumas tarefas para executar em `THREAD_PRIORITY_NORMAL` e outras tarefas para executar em `THREAD_PRIORITY_HIGHEST`.  Você pode criar duas instâncias do Agendador: um que especifica o `ContextPriority` política a ser `THREAD_PRIORITY_NORMAL` e outra que especifica a mesma diretiva para ser `THREAD_PRIORITY_HIGHEST`.  
  
 Usando políticas de Agendador, você pode dividir os recursos de processamento disponíveis e atribuir um conjunto fixo de recursos para cada Agendador. Por exemplo, considere um algoritmo paralelo que não ultrapassará quatro processadores. Você pode criar uma política de agendador que limita suas tarefas para usar não mais do que quatro processadores simultaneamente.  
  
> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão. Portanto, você não precisa criar um em seu aplicativo. Como o Agendador de tarefas Ajuda a ajustar o desempenho de seus aplicativos, é recomendável que você inicie com o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você estiver novo no tempo de execução de simultaneidade.  
  
 Quando você usa o [concurrency::CurrentScheduler::Create](reference/currentscheduler-class.md#create), [concurrency::Scheduler::Create](reference/scheduler-class.md#create), ou [concurrency::Scheduler::SetDefaultSchedulerPolicy](reference/scheduler-class.md#setdefaultschedulerpolicy) método para criar uma instância de Agendador, você fornece um [concurrency::SchedulerPolicy](../../parallel/concrt/reference/schedulerpolicy-class.md) objeto que contém uma coleção de pares chave-valor que especificam o comportamento do Agendador. O `SchedulerPolicy` construtor aceita um número variável de argumentos. O primeiro argumento é o número de elementos de política que você está prestes a especificar. Os argumentos restantes são pares chave-valor para cada elemento de política. O exemplo a seguir cria um `SchedulerPolicy` objeto que especifica três elementos de política. O tempo de execução usa valores padrão para as chaves de política que não são especificadas.  

  
 [!code-cpp[concrt-scheduler-policy#2](../../parallel/concrt/codesnippet/cpp/scheduler-policies_1.cpp)]  
  

 O [concurrency::PolicyElementKey](reference/concurrency-namespace-enums.md#policyelementkey) enumeração define as chaves de política que estão associadas com o Agendador de tarefas. A tabela a seguir descreve as chaves de política e o valor padrão que usa o tempo de execução para cada um deles.  
  
|Chave de política|Descrição|Valor padrão|  
|----------------|-----------------|-------------------|  
|`SchedulerKind`|Um [concurrency::SchedulerType](reference/concurrency-namespace-enums.md#schedulertype) valor que especifica o tipo de threads a ser usado para agendar tarefas.|`ThreadScheduler` (use threads normais). Este é o único valor válido para essa chave.|  
|`MaxConcurrency`|Um `unsigned int` valor que especifica o número máximo de recursos de simultaneidade que usa o Agendador.|[Concurrency::MaxExecutionResources](reference/concurrency-namespace-constants1.md#maxexecutionresources)|  
|`MinConcurrency`|Um `unsigned int` valor que especifica o número mínimo de recursos de simultaneidade que usa o Agendador.|`1`|  
|`TargetOversubscriptionFactor`|Um `unsigned int` valor que especifica quantos threads para alocar a cada recurso de processamento.|`1`|  
|`LocalContextCacheSize`|Um `unsigned int` valor que especifica o número máximo de contextos que podem ser armazenados em cache na fila local de cada processador virtual.|`8`|  
|`ContextStackSize`|Um `unsigned int` valor que especifica o tamanho da pilha, em quilobytes, para reservar para cada contexto.|`0` (use o tamanho da pilha padrão)|  
|`ContextPriority`|Um `int` valor que especifica a prioridade de thread de cada contexto. Isso pode ser qualquer valor que você pode passar para [SetThreadPriority](http://msdn.microsoft.com/library/windows/desktop/ms686277) ou `INHERIT_THREAD_PRIORITY`.|`THREAD_PRIORITY_NORMAL`|  

|`SchedulingProtocol`| Um [concurrency::SchedulingProtocolType](reference/concurrency-namespace-enums.md#schedulingprotocoltype) valor que especifica o algoritmo de programação para usar. |`EnhanceScheduleGroupLocality`|  
|`DynamicProgressFeedback`| Um [concurrency::DynamicProgressFeedbackType](reference/concurrency-namespace-enums.md#dynamicprogressfeedbacktype) valor que especifica se a reequilibrar recursos de acordo com as informações de progresso com base em estatísticas.<br /><br /> **Observação** não definir essa política como `ProgressFeedbackDisabled` porque ele está reservado para uso pelo tempo de execução. |`ProgressFeedbackEnabled`|  

  
 Cada Agendador usa sua própria política quando ele agenda tarefas. As políticas que estão associadas um agendador não afetam o comportamento de qualquer outro Agendador. Além disso, você não pode alterar a política de Agendador depois de criar o `Scheduler` objeto.  
  
> [!IMPORTANT]
>  Use somente as políticas de Agendador para controlar os atributos de threads que cria o tempo de execução. Não altere a afinidade de thread ou a prioridade de threads que são criados pelo tempo de execução porque o que pode causar um comportamento indefinido.  
  
 O tempo de execução cria um agendador padrão para você, se você não criar explicitamente uma. Se você deseja usar o agendador padrão em seu aplicativo, mas você deseja especificar uma política para que o Agendador usar, chame o [concurrency::Scheduler::SetDefaultSchedulerPolicy](reference/scheduler-class.md#setdefaultschedulerpolicy) método antes de você agendar trabalho paralelos. Se você não chama o `Scheduler::SetDefaultSchedulerPolicy` método, a tempo de execução usa a política padrão de valores da tabela.  
  
 Use o [concurrency::CurrentScheduler::GetPolicy](reference/currentscheduler-class.md#getpolicy) e [concurrency::Scheduler::GetPolicy](reference/scheduler-class.md#getpolicy) métodos para recuperar uma cópia da política do Agendador. Os valores de política que você receber esses métodos podem diferir dos valores de política que você especifica ao criar o Agendador.  
  
## <a name="example"></a>Exemplo  
 Para examinar os exemplos que usam políticas de Agendador específicas para controlar o comportamento do Agendador, consulte [como: especificar políticas de Agendador específicas](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md) e [como: criar agentes que usam políticas específicas do Agendador](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md).  
  
## <a name="see-also"></a>Consulte também  
 [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Como: especificar políticas de Agendador específicas](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md)   
 [Como criar agentes que usam políticas de agendador específicas](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md)

