---
title: Agentes Assíncronos
ms.date: 11/19/2018
helpviewer_keywords:
- asynchronous agents
- agents [Concurrency Runtime]
ms.assetid: 6cf6ccc6-87f1-4e14-af15-ea8ba58fef1a
ms.openlocfilehash: a99400e4df49e36e1cddda7068f315485b976cde
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52176530"
---
# <a name="asynchronous-agents"></a>Agentes Assíncronos

Uma *agentes assíncronos* (ou simplesmente *agente*) é um componente de aplicativo que funciona de forma assíncrona com outros agentes para resolver tarefas de computação maiores. Considere um agente como uma tarefa que tem um ciclo de vida definido. Por exemplo, um agente pode ler dados de um dispositivo de entrada/saída (por exemplo, o teclado, um arquivo no disco ou uma conexão de rede) e outro agente podem executar uma ação em que os dados assim que estiverem disponíveis. O primeiro agente usa a passagem de mensagem para informar o agente de segundo há mais dados disponíveis. O Agendador de tarefas de tempo de execução de simultaneidade fornece um mecanismo eficiente para habilitar os agentes bloquear e produzir cooperativamente sem a necessidade de preempção menos eficiente.

A biblioteca de agentes define o [concurrency::agent](../../parallel/concrt/reference/agent-class.md) classe para representar um agente assíncrono. `agent` é uma classe abstrata que declara o método virtual [concurrency::agent::run](reference/agent-class.md#run). O `run` método executa a tarefa que é executada pelo agente. Porque `run` é abstrata, você deve implementar esse método em todas as classes que derivam de `agent`.

## <a name="agent-life-cycle"></a>Ciclo de vida do agente

Agentes têm um ciclo de vida definido. O [concurrency::agent_status](reference/concurrency-namespace-enums.md#agent_status) enumeração define os diversos estados de um agente. A ilustração a seguir é um diagrama de estado que mostra como agentes de andamento de um estado para outro. Nesta ilustração, linhas sólidas representam métodos que você chamar de seu aplicativo. as linhas pontilhadas representam os métodos que são chamados de tempo de execução.

![Diagrama de estado do agente](../../parallel/concrt/media/agentstate.png "diagrama de estado do agente")

A tabela a seguir descreve cada estado no `agent_status` enumeração.

|Estado do agente|Descrição|
|-----------------|-----------------|
|`agent_created`|O agente não foi agendado para execução.|
|`agent_runnable`|O tempo de execução está agendando o agente para execução.|
|`agent_started`|O agente foi iniciado e está em execução.|
|`agent_done`|O agente foi concluído.|
|`agent_canceled`|O agente foi cancelado antes de ele inseriu o `started` estado.|

`agent_created` é o estado inicial de um agente `agent_runnable` e `agent_started` são os estados de Active Directory, e `agent_done` e `agent_canceled` são os estados de terminal.

Use o [concurrency::agent::status](reference/agent-class.md#status) método para recuperar o estado atual de um `agent` objeto. Embora o `status` método é protegido contra simultaneidade, o estado do agente pode alterar o tempo de `status` retorno do método. Por exemplo, um agente pode ser na `agent_started` estado quando você chama o `status` método, mas é movido para o `agent_done` estado logo após o `status` retorno do método.

## <a name="methods-and-features"></a>Métodos e recursos

A tabela a seguir mostra alguns dos métodos importantes que pertencem ao `agent` classe. Para obter mais informações sobre todos os `agent` métodos de classe, consulte [classe agente](../../parallel/concrt/reference/agent-class.md).

|Método|Descrição|
|------------|-----------------|
|[start](reference/agent-class.md#start)|Agendas de `agent` objeto para a execução e o define como o `agent_runnable` estado.|
|[run](reference/agent-class.md#run)|Executa a tarefa a ser executada pelo `agent` objeto.|
|[feito](reference/agent-class.md#done)|Move um agente para o `agent_done` estado.|
|[cancel](../../parallel/concrt/cancellation-in-the-ppl.md#cancel)|Se o agente não foi iniciado, esse método cancela a execução do agente e o define como o `agent_canceled` estado.|
|[status](reference/agent-class.md#status)|Recupera o estado atual do `agent` objeto.|
|[wait](reference/agent-class.md#wait)|Aguarda o `agent` objeto insira a `agent_done` ou `agent_canceled` estado.|
|[wait_for_all](reference/agent-class.md#wait_for_all)|Aguarda todos os fornecidos `agent` objetos para inserir as `agent_done` ou `agent_canceled` estado.|
|[wait_for_one](reference/agent-class.md#wait_for_one)|Aguarda até que pelo menos um dos fornecidos `agent` objetos para inserir as `agent_done` ou `agent_canceled` estado.|

Depois de criar um objeto de agente, chame o [concurrency::agent::start](reference/agent-class.md#start) método agendá-lo para execução. A tempo de execução chama o `run` método depois que ele agenda o agente e o define como o `agent_runnable` estado.

O tempo de execução não gerencia exceções que são geradas por agentes assíncronos. Para obter mais informações sobre o tratamento de exceção e agentes, consulte [tratamento de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

## <a name="example"></a>Exemplo

Para obter um exemplo que mostra como criar um aplicativo básico com base em agente, consulte [instruções passo a passo: Criando um aplicativo baseado em agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md).

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)

