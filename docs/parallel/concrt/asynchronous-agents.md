---
title: "Agentes ass&#237;ncronos | Microsoft Docs"
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
  - "agentes [Tempo de Execução de Simultaneidade]"
  - "agentes assíncronos"
ms.assetid: 6cf6ccc6-87f1-4e14-af15-ea8ba58fef1a
caps.latest.revision: 15
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Agentes ass&#237;ncronos
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

*Um agente assíncrona* \(ou apenas *o agente*\) é um componente de aplicativo que funciona de forma assíncrona com outros agentes para resolver tarefas de computação maiores.  Pense de um agente como uma tarefa que tem um ciclo de vida ajustado.  Por exemplo, um agente pode ler dados de um dispositivo de entrada\/saída \(como o teclado, um arquivo no disco, ou uma conexão de rede\) e outro agente pode executar a ação nesses dados conforme se torna disponível.  O primeiro agent usa a mensagem que transmite para informar o segundo agente que mais dados estão disponíveis.  O agendador de tarefas de tempo de execução de simultaneidade fornece um mecanismo eficiente para habilitar agentes para bloquear cooperativa e gerar sem exigir menos preempção eficiente.  
  
 A biblioteca dos agentes define a classe de [concurrency::agent](../../parallel/concrt/reference/agent-class.md) para representar um agente assíncrona.  `agent` é uma classe abstrata que declara o método virtual [concurrency::agent::run](../Topic/agent::run%20Method.md).  O método de `run` executa a tarefa que é executada pelo agent.  Como `run` é abstrata, você deve implementar esse método em cada classe derivada de `agent`.  
  
## Ciclo de vida do agent  
 Os agentes têm um ciclo de vida ajustado.  A enumeração de [concurrency::agent\_status](../Topic/agent_status%20Enumeration.md) define vários estados de um agente.  A ilustração a seguir é um diagrama de estado que mostra como os agentes o andamento de um estado para outro.  Nesta ilustração, as linhas sólidas representam os métodos que você chama do seu aplicativo; as linhas pontilhadas representam os métodos que são chamados de tempo de execução.  
  
 ![Diagrama de estado do agente](../../parallel/concrt/media/agentstate.png "AgentState")  
  
 A tabela a seguir descreve cada estado da enumeração de `agent_status` .  
  
|Estado do agent|Descrição|  
|---------------------|---------------|  
|`agent_created`|O agent não foi agendado para execução.|  
|`agent_runnable`|O tempo de execução está programando o agente para a execução.|  
|`agent_started`|O agente foi iniciado e está em execução.|  
|`agent_done`|O agente concluído.|  
|`agent_canceled`|O agente foi cancelado antes que entrou no estado de `started` .|  
  
 `agent_created` é o estado inicial de um agente, `agent_runnable` e `agent_started` são os estados ativas, e `agent_done` e `agent_canceled` são os estados terminais.  
  
 Use o método de [concurrency::agent::status](../Topic/agent::status%20Method.md) para recuperar o estado atual de um objeto de `agent` .  Embora o método de `status` é simultaneidade\- seguro, o estado do agent pode ser alterado antes que o método de `status` retornar.  Por exemplo, um agente pode estar no estado de `agent_started` quando você chama o método de `status` , mas movido para `agent_done` o estado imediatamente depois que o método de `status` retorna.  
  
## Métodos e recursos  
 A tabela a seguir mostra alguns dos métodos importantes que pertencem à classe de `agent` .  Para obter mais informações sobre todos os métodos da classe de `agent` , consulte [Classe agente](../../parallel/concrt/reference/agent-class.md).  
  
|Método|Descrição|  
|------------|---------------|  
|[início](../Topic/agent::start%20Method.md)|Agenda do objeto `agent` para execução e defina\-o com o estado de `agent_runnable` .|  
|[execução](../Topic/agent::run%20Method.md)|Executa a tarefa que deve ser executada pelo objeto de `agent` .|  
|[feita](../Topic/agent::done%20Method.md)|Move um agente com o estado de `agent_done` .|  
|[Cancelar](../Topic/agent::cancel%20Method.md)|Se o agente não tiver sido iniciado, essa execução de cancelamentos do método do agent e conjuntos ao estado de `agent_canceled` .|  
|[status](../Topic/agent::status%20Method.md)|Recupera o estado atual do objeto de `agent` .|  
|[espera](../Topic/agent::wait%20Method.md)|As esperas para `agent` objeto para entrar no estado de `agent_done` ou de `agent_canceled` .|  
|[wait\_for\_all](../Topic/agent::wait_for_all%20Method.md)|As esperas fornecidos para todas objetos de `agent` entrem no estado de `agent_done` ou de `agent_canceled` .|  
|[wait\_for\_one](../Topic/agent::wait_for_one%20Method.md)|Esperas no mínimo uma de objetos fornecidos de `agent` entrem no estado de `agent_done` ou de `agent_canceled` .|  
  
 Depois de criar um objeto do agent, chame o método de [concurrency::agent::start](../Topic/agent::start%20Method.md) para agendar\-lo para execução.  O tempo de execução chama o método de `run` depois de agendamento do distribution agent e o define o estado de `agent_runnable` .  
  
 O tempo de execução não gerencia as exceções emitidas por agentes assíncronas.  Para obter mais informações sobre a manipulação e os agentes de exceção, consulte [Tratamento de Exceção](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md).  
  
## Exemplo  
 Para obter um exemplo que mostra como criar um aplicativo agente\- baseado básico, considere [Instruções passo a passo: criando um aplicativo com base no agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md).  
  
## Consulte também  
 [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)