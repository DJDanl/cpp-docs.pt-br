---
title: Agentes assíncronos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- asynchronous agents
- agents [Concurrency Runtime]
ms.assetid: 6cf6ccc6-87f1-4e14-af15-ea8ba58fef1a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8649ebe0451e4352b27989563a1a0918afcb5a01
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="asynchronous-agents"></a>Agentes Assíncronos
Um *agente assíncrona* (ou apenas *agente*) é um componente de aplicativo que funciona com outros agentes para resolver as tarefas de computação maior de forma assíncrona. Considere um agente como uma tarefa que tem um ciclo de vida definido. Por exemplo, um agente pode ler dados de um dispositivo de entrada/saída (como o teclado, um arquivo em disco ou uma conexão de rede) e outro agente podem executar uma ação em dados assim que possível. O primeiro agente usa a passagem de mensagem para informar o segundo agente que há mais dados disponíveis. O Agendador de tarefas de tempo de execução de simultaneidade fornece um mecanismo eficiente para habilitar os agentes bloquear e geram trabalhem de forma sem a necessidade de preempção menos eficiente.  
  

 A biblioteca de agentes define o [concurrency::agent](../../parallel/concrt/reference/agent-class.md) classe para representar um agente assíncrono. `agent` é uma classe abstrata que declara o método virtual [concurrency::agent::run](reference/agent-class.md#run). O `run` método executa a tarefa que é executada pelo agente. Porque `run` é abstrato, você deve implementar esse método em todas as classes que derivam de `agent`.  
  
## <a name="agent-life-cycle"></a>Ciclo de vida do agente  
 Agentes têm um ciclo de vida definido. O [concurrency::agent_status](reference/concurrency-namespace-enums.md#agent_status) enumeração define os vários estados de um agente. A ilustração a seguir é um diagrama de estado que mostra como os agentes de andamento de um estado para outro. Nesta ilustração, linhas sólidas representam métodos que você chamar do seu aplicativo. linhas pontilhadas representam os métodos que são chamados de tempo de execução.  
  
 ![Diagrama de estado do agente](../../parallel/concrt/media/agentstate.png "agentstate")  
  
 A tabela a seguir descreve cada estado de `agent_status` enumeração.  
  
|Estado do agente|Descrição|  
|-----------------|-----------------|  
|`agent_created`|O agente não foi agendado para execução.|  
|`agent_runnable`|O tempo de execução é agendar o agente para execução.|  
|`agent_started`|O agente foi iniciado e está em execução.|  
|`agent_done`|O agente foi concluído.|  
|`agent_canceled`|O agente foi cancelado antes de ele inseriu o `started` estado.|  
  
 `agent_created` é o estado inicial de um agente, `agent_runnable` e `agent_started` são os estados ativos, e `agent_done` e `agent_canceled` são os estados de terminal.  
  
 Use o [concurrency::agent::status](reference/agent-class.md#status) método para recuperar o estado atual de um `agent` objeto. Embora o `status` método é seguro de simultaneidade, o estado do agente pode alterar o tempo de `status` método retorna. Por exemplo, um agente pode ser no `agent_started` estado quando você chama o `status` método, mas é movido para o `agent_done` estado logo após o `status` método retorna.  

  
## <a name="methods-and-features"></a>Métodos e recursos  
 A tabela a seguir mostra alguns dos métodos importantes que pertencem ao `agent` classe. Para obter mais informações sobre todos os `agent` métodos de classe, consulte [classe agente](../../parallel/concrt/reference/agent-class.md).  
  
|Método|Descrição|  
|------------|-----------------|  
|[start](reference/agent-class.md#start)|Agendas de `agent` objeto para execução e o define como o `agent_runnable` estado.|  
|[run](reference/agent-class.md#run)|Executa a tarefa a ser executada pelo `agent` objeto.|  
|[Feito](reference/agent-class.md#done)|Move um agente para o `agent_done` estado.|  
|[cancel](../../parallel/concrt/cancellation-in-the-ppl.md#cancel)|Se o agente não foi iniciado, esse método cancela a execução do agente e o define como o `agent_canceled` estado.|  
|[status](reference/agent-class.md#status)|Recupera o estado atual do `agent` objeto.|  
|[wait](reference/agent-class.md#wait)|Aguarda o `agent` objeto para inserir o `agent_done` ou `agent_canceled` estado.|  
|[wait_for_all](reference/agent-class.md#wait_for_all)|Aguarda até que todos os fornecidos `agent` objetos para inserir o `agent_done` ou `agent_canceled` estado.|  
|[wait_for_one](reference/agent-class.md#wait_for_one)|Aguarda até que pelo menos um dos fornecidos `agent` objetos para inserir o `agent_done` ou `agent_canceled` estado.|  
  
 Depois de criar um objeto de agente, chame o [concurrency::agent::start](reference/agent-class.md#start) método agendá-lo para execução. O tempo de execução chama o `run` método depois que ele agenda o agente e o define como o `agent_runnable` estado.  
  
 O tempo de execução não gerencia exceções geradas por agentes assíncronos. Para obter mais informações sobre o tratamento de exceção e agentes, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo que mostra como criar um aplicativo básico com base em agente, consulte [passo a passo: Criando um aplicativo com base em agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md).  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)

