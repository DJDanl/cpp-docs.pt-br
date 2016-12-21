---
title: "Pol&#237;ticas de agendador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "políticas de agendador"
ms.assetid: 58fb68bd-4a57-40a8-807b-6edb6f083cd9
caps.latest.revision: 12
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Pol&#237;ticas de agendador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento descreve a função de políticas do agendador em tempo de execução de simultaneidade.  *Uma política do agendador* controla a estratégia que o agendador usa a gerenciar tarefas.  Por exemplo, considere um aplicativo que requer algumas tarefas executar em `THREAD_PRIORITY_NORMAL` e outras tarefas executar em `THREAD_PRIORITY_HIGHEST`.  Você pode criar duas instâncias do agendador: um que especifica a política de `ContextPriority` para ser `THREAD_PRIORITY_NORMAL` e outra que especifica a mesma política para ser `THREAD_PRIORITY_HIGHEST`.  
  
 Usando diretivas de agendador, você pode dividir os recursos de processamento disponíveis e atribuir um conjunto fixo de recursos para cada agendador.  Por exemplo, considere um algoritmo paralelo que não dimensões além de quatro processadores.  Você pode criar uma política do agendador que limita suas tarefas simultaneamente não usar mais de quatro processadores.  
  
> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão.  Consequentemente, você não precisa criar um em seu aplicativo.  Como o agendador de tarefas o ajuda a ajustar o desempenho dos aplicativos, recomendamos que você comece com [Biblioteca de padrões paralelos \(PPL\)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você é novato em tempo de execução de simultaneidade.  
  
 Quando você usa [concurrency::CurrentScheduler::Create](../Topic/CurrentScheduler::Create%20Method.md), [concurrency::Scheduler::Create](../Topic/Scheduler::Create%20Method.md), ou o método de [concurrency::Scheduler::SetDefaultSchedulerPolicy](../Topic/Scheduler::SetDefaultSchedulerPolicy%20Method.md) para criar uma instância do agendador, você fornece um objeto de [concurrency::SchedulerPolicy](../../parallel/concrt/reference/schedulerpolicy-class.md) que contém uma coleção de pares de chave\-valor que especificam o comportamento do agendador.  O construtor de `SchedulerPolicy` usa um número variável de argumentos.  O primeiro argumento é o número de elementos da política que você está prestes a especificar.  Os argumentos restantes são pares de chave\-valor para cada elemento da política.  O exemplo a seguir cria um objeto de `SchedulerPolicy` que especifica três elementos da política.  O tempo de execução usa valores padrão para as chaves de política que não são especificadas.  
  
 [!CODE [concrt-scheduler-policy#2](../CodeSnippet/VS_Snippets_ConcRT/concrt-scheduler-policy#2)]  
  
 A enumeração de [concurrency::PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md) define as chaves de política associadas ao agendador de tarefas.  A tabela a seguir descreve as chaves da política e o valor padrão que o tempo de execução usa para cada um deless.  
  
|Chave da política|Descrição|Valor padrão|  
|-----------------------|---------------|------------------|  
|`SchedulerKind`|Um valor de [concurrency::SchedulerType](../Topic/SchedulerType%20Enumeration.md) que especifica o tipo de threads para usar para agendar tarefas.|`ThreadScheduler` \(threads normais de uso\).  Esse é o único valor válido para essa chave.|  
|`MaxConcurrency`|Um valor de `unsigned int` que especifica o número máximo de recursos de simultaneidade que o agendador usa.|[concurrency::MaxExecutionResources](../Topic/MaxExecutionResources%20Constant.md)|  
|`MinConcurrency`|Um valor de `unsigned int` que especifica o número mínimo de recursos de simultaneidade que o agendador usa.|`1`|  
|`TargetOversubscriptionFactor`|Um valor de `unsigned int` que especifica quantos threads a ser atribuído a cada recurso de processamento.|`1`|  
|`LocalContextCacheSize`|Um valor de `unsigned int` que especifica o número máximo de contextos que podem ser armazenados em cachê na fila local de cada processador virtual.|`8`|  
|`ContextStackSize`|Um valor de `unsigned int` que especifica o tamanho da pilha, em quilobytes, separados para cada contexto.|`0` \(use o tamanho padrão da pilha\)|  
|`ContextPriority`|Um valor de `int` que especifica a prioridade de thread de cada contexto.  Pode ser qualquer valor que seja possível passar a [SetThreadPriority](http://msdn.microsoft.com/library/windows/desktop/ms686277) ou a `INHERIT_THREAD_PRIORITY`.|`THREAD_PRIORITY_NORMAL`|  
|`SchedulingProtocol`|Um valor de [concurrency::SchedulingProtocolType](../Topic/SchedulingProtocolType%20Enumeration.md) que especifica o algoritmo de programação para usar.|`EnhanceScheduleGroupLocality`|  
|`DynamicProgressFeedback`|Um valor de [concurrency::DynamicProgressFeedbackType](../Topic/DynamicProgressFeedbackType%20Enumeration.md) que especifica se a sobreamostragem recursos de acordo com as informações estatística\- base de progresso.<br /><br /> **Observação** Não defina essa política a `ProgressFeedbackDisabled` como é reservado para uso de tempo de execução.|`ProgressFeedbackEnabled`|  
  
 Cada agendador usa sua própria política ao agendar tarefas.  As políticas associadas com um agendador não afetam o comportamento de nenhum outro agendador.  Além disso, você não pode alterar a política do agendador depois que você criar o objeto de `Scheduler` .  
  
> [!IMPORTANT]
>  Use apenas políticas do agendador para controlar os atributos para os threads que o tempo de execução cria.  Não altere a afinidade do thread ou a prioridade dos threads criados em tempo de execução porque isso pode provocar comportamento indefinido.  
  
 O tempo de execução cria um agendador padrão para se você não criar explicitamente um.  Se você quiser usar o agendador padrão em seu aplicativo, mas você deseja especificar uma política para que o agendador usa, chame o método de [concurrency::Scheduler::SetDefaultSchedulerPolicy](../Topic/Scheduler::SetDefaultSchedulerPolicy%20Method.md) antes que você agende o trabalho paralelo.  Se você não chama o método de `Scheduler::SetDefaultSchedulerPolicy` , o tempo de execução usa os valores da política padrão da tabela.  
  
 Use [concurrency::CurrentScheduler::GetPolicy](../Topic/CurrentScheduler::GetPolicy%20Method.md) e os métodos de [concurrency::Scheduler::GetPolicy](../Topic/Scheduler::GetPolicy%20Method.md) para recuperar uma cópia de política do agendador.  Os valores de políticas que você recebe métodos podem diferir dos valores de políticas que você especifica quando você cria o agendador.  
  
## Exemplo  
 Para revisar os exemplos que usam políticas específicas do agendador para controlar o comportamento de agendador, consulte [Como especificar políticas de agendador específicas](../Topic/How%20to:%20Specify%20Specific%20Scheduler%20Policies.md) e [Como cria agentes que usam políticas de agendador específicas](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md).  
  
## Consulte também  
 [Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Como especificar políticas de agendador específicas](../Topic/How%20to:%20Specify%20Specific%20Scheduler%20Policies.md)   
 [Como cria agentes que usam políticas de agendador específicas](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md)