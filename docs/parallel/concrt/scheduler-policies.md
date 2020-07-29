---
title: Políticas de agendador
ms.date: 11/04/2016
helpviewer_keywords:
- scheduler policies
ms.assetid: 58fb68bd-4a57-40a8-807b-6edb6f083cd9
ms.openlocfilehash: d074646a333090138c916bc4d3b7a2e072731b3d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228408"
---
# <a name="scheduler-policies"></a>Políticas de agendador

Este documento descreve a função de políticas do Agendador no Tempo de Execução de Simultaneidade. Uma *política do Agendador* controla a estratégia que o Agendador usa ao gerenciar tarefas. Por exemplo, considere um aplicativo que requer algumas tarefas para executar em `THREAD_PRIORITY_NORMAL` e outras tarefas para executar em `THREAD_PRIORITY_HIGHEST` .  Você pode criar duas instâncias do Agendador: uma que especifica a `ContextPriority` política a ser `THREAD_PRIORITY_NORMAL` e outra que especifica a mesma política `THREAD_PRIORITY_HIGHEST` .

Usando as políticas do Agendador, você pode dividir os recursos de processamento disponíveis e atribuir um conjunto fixo de recursos a cada Agendador. Por exemplo, considere um algoritmo paralelo que não se expande além de quatro processadores. Você pode criar uma política do Agendador que limita suas tarefas para usar no máximo quatro processadores simultaneamente.

> [!TIP]
> O Tempo de Execução de Simultaneidade fornece um agendador padrão. Portanto, você não precisa criar um em seu aplicativo. Como o Agendador de Tarefas ajuda você a ajustar o desempenho de seus aplicativos, recomendamos que você comece com a [ppl (biblioteca de padrões paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou a [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você for novo no tempo de execução de simultaneidade.

Quando você usa o método [Concurrency:: CurrentScheduler:: Create](reference/currentscheduler-class.md#create), [Concurrency:: Scheduler:: Create](reference/scheduler-class.md#create)ou [Concurrency:: Scheduler:: SetDefaultSchedulerPolicy](reference/scheduler-class.md#setdefaultschedulerpolicy) para criar uma instância do Agendador, você fornece um objeto [Concurrency:: SchedulerPolicy](../../parallel/concrt/reference/schedulerpolicy-class.md) que contém uma coleção de pares de chave-valor que especificam o comportamento do Agendador. O `SchedulerPolicy` construtor usa um número variável de argumentos. O primeiro argumento é o número de elementos de política que você está prestes a especificar. Os argumentos restantes são pares chave-valor para cada elemento de política. O exemplo a seguir cria um `SchedulerPolicy` objeto que especifica três elementos de política. O tempo de execução usa valores padrão para as chaves de política que não são especificadas.

[!code-cpp[concrt-scheduler-policy#2](../../parallel/concrt/codesnippet/cpp/scheduler-policies_1.cpp)]

A enumeração [Concurrency::P olicyelementkey](reference/concurrency-namespace-enums.md#policyelementkey) define as chaves de política associadas ao agendador de tarefas. A tabela a seguir descreve as chaves de política e o valor padrão que o tempo de execução usa para cada um deles.

|Chave de política|Descrição|Valor Padrão|
|----------------|-----------------|-------------------|
|`SchedulerKind`|Um valor [Concurrency:: SchedulerType](reference/concurrency-namespace-enums.md#schedulertype) que especifica o tipo de threads a serem usados para agendar tarefas.|`ThreadScheduler`(use threads normais). Esse é o único valor válido para essa chave.|
|`MaxConcurrency`|Um **`unsigned int`** valor que especifica o número máximo de recursos de simultaneidade que o Agendador usa.|[simultaneidade:: MaxExecutionResources](reference/concurrency-namespace-constants1.md#maxexecutionresources)|
|`MinConcurrency`|Um **`unsigned int`** valor que especifica o número mínimo de recursos de simultaneidade que o Agendador usa.|`1`|
|`TargetOversubscriptionFactor`|Um **`unsigned int`** valor que especifica quantos threads alocar para cada recurso de processamento.|`1`|
|`LocalContextCacheSize`|Um **`unsigned int`** valor que especifica o número máximo de contextos que podem ser armazenados em cache na fila local de cada processador virtual.|`8`|
|`ContextStackSize`|Um **`unsigned int`** valor que especifica o tamanho da pilha, em kilobytes, a ser reservado para cada contexto.|`0`(use o tamanho de pilha padrão)|
|`ContextPriority`|Um **`int`** valor que especifica a prioridade de thread de cada contexto. Pode ser qualquer valor que você possa passar para [SetThreadPriority](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) ou `INHERIT_THREAD_PRIORITY` .|`THREAD_PRIORITY_NORMAL`|

|`SchedulingProtocol`| Um valor [Concurrency:: SchedulingProtocolType](reference/concurrency-namespace-enums.md#schedulingprotocoltype) que especifica o algoritmo de agendamento a ser usado. | `EnhanceScheduleGroupLocality` | |`DynamicProgressFeedback`| Uma [simultaneidade::D valor ynamicprogressfeedbacktype](reference/concurrency-namespace-enums.md#dynamicprogressfeedbacktype) que especifica se os recursos devem ser reequilibrados de acordo com as informações de progresso baseadas em estatísticas.<br /><br /> **Observação** Não defina essa política como `ProgressFeedbackDisabled` porque ela está reservada para uso pelo tempo de execução. |`ProgressFeedbackEnabled`|

Cada Agendador usa sua própria política ao agendar tarefas. As políticas associadas a um Agendador não afetam o comportamento de nenhum outro agendador. Além disso, você não pode alterar a política do Agendador depois de criar o `Scheduler` objeto.

> [!IMPORTANT]
> Use apenas políticas do Agendador para controlar os atributos de threads que o tempo de execução cria. Não altere a afinidade de thread ou a prioridade de threads criados pelo tempo de execução, pois isso pode causar um comportamento indefinido.

O tempo de execução criará um agendador padrão para você se você não criar explicitamente um. Se você quiser usar o agendador padrão em seu aplicativo, mas quiser especificar uma política para o Agendador a ser usado, chame o método [Concurrency:: Scheduler:: SetDefaultSchedulerPolicy](reference/scheduler-class.md#setdefaultschedulerpolicy) antes de agendar o trabalho paralelo. Se você não chamar o `Scheduler::SetDefaultSchedulerPolicy` método, o tempo de execução usará os valores de política padrão da tabela.

Use os métodos [Concurrency:: CurrentScheduler:: GetPolicy](reference/currentscheduler-class.md#getpolicy) e [Concurrency:: Scheduler:: GetPolicy](reference/scheduler-class.md#getpolicy) para recuperar uma cópia da política do Agendador. Os valores de política que você recebe desses métodos podem diferir dos valores de política que você especifica ao criar o Agendador.

## <a name="example"></a>Exemplo

Para examinar exemplos que usam políticas específicas do Agendador para controlar o comportamento do Agendador, consulte [como: especificar políticas específicas do Agendador](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md) e [como criar agentes que usam políticas específicas do Agendador](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md).

## <a name="see-also"></a>Confira também

[Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Como especificar políticas específicas do Agendador](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md)<br/>
[Como criar agentes que usam políticas específicas do Agendador](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md)
