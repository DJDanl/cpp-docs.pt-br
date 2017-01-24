---
title: "Como usar grupos de agendas para influenciar a ordem de execu&#231;&#227;o | Microsoft Docs"
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
  - "agendar grupos, usando [tempo de execução de simultaneidade]"
  - "usando grupos de agendas [Tempo de Execução de Simultaneidade]"
ms.assetid: 73124194-fc3a-491e-a23f-fbd7b5a4455c
caps.latest.revision: 15
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar grupos de agendas para influenciar a ordem de execu&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Em tempo de execução da simultaneidade, a ordem em que as tarefas são agendadas é não determinístico.  Porém, você pode usar políticas de programação para influenciar a ordem na qual a execução de tarefas.  Este tópico mostra como usar grupos de agenda com a diretiva o agendador de [concurrency::SchedulingProtocol](../Topic/PolicyElementKey%20Enumeration.md) para influenciar a ordem na qual a execução de tarefas.  
  
 O exemplo executa um conjunto de tarefas duas vezes, cada com uma política diferente de programação.  Ambas as políticas limitam o número máximo de recursos de processamento para dois.  A primeira execução usa a política de `EnhanceScheduleGroupLocality` , que é o padrão, e a segunda execução usa a política de `EnhanceForwardProgress` .  Na política de `EnhanceScheduleGroupLocality` , o agendador executa todas as tarefas em um grupo de agenda até que cada tarefa seja concluída ou renda.  Na política de `EnhanceForwardProgress` , o moverá do agendador para o próximo grupo de agenda em uma forma de rodízio depois que apenas uma tarefa é concluída ou está.  
  
 Quando cada grupo de agenda contém tarefas relacionadas, a política de `EnhanceScheduleGroupLocality` normalmente resulta em desempenho aprimorado porque a localidade do cache é preservada entre tarefas.  A política de `EnhanceForwardProgress` habilita tarefas fazer o progresso para a frente e é útil quando você precisar de equidade de programação nos grupos da agenda.  
  
## Exemplo  
 Este exemplo define a classe de `work_yield_agent` , que se deriva de [concurrency::agent](../../parallel/concrt/reference/agent-class.md).  A classe de `work_yield_agent` executa uma unidade de trabalho, produz o contexto atual, e executa outra unidade de trabalho.  O agent usa a função de [concurrency::wait](../Topic/wait%20Function.md) para obter cooperativa o contexto atual de forma que outros contextos possam ser executados.  
  
 Este exemplo cria quatro objetos de `work_yield_agent` .  Para ilustrar como definir políticas do agendador para afetar a ordem na qual a execução de agentes, o exemplo associa os dois primeiros agentes com um grupo de agenda e os dois outros agentes com outro grupo da agenda.  O exemplo usa o método de [concurrency::CurrentScheduler::CreateScheduleGroup](../Topic/CurrentScheduler::CreateScheduleGroup%20Method.md) para criar os objetos de [concurrency::ScheduleGroup](../Topic/ScheduleGroup%20Class.md) .  O exemplo executa todos os quatro agentes duas vezes, cada vez com uma política diferente de programação.  
  
 [!code-cpp[concrt-scheduling-protocol#1](../../parallel/concrt/codesnippet/CPP/how-to-use-schedule-groups-to-influence-order-of-execution_1.cpp)]  
  
 O exemplo produz a seguinte saída.  
  
  **Usando EnhanceScheduleGroupLocality…**  
**grupo 0, tarefa 0: primeiro loop…**  
**grupo 0, tarefa 1: primeiro loop…**  
**grupo 0, tarefa 0: aguardar…**  
**grupo 1, tarefa 0: primeiro loop…**  
**grupo 0, tarefa 1: aguardar…**  
**grupo 1, tarefa 1: primeiro loop…**  
**grupo 1, tarefa 0: aguardar…**  
**grupo 0, tarefa 0: segundo loop…**  
**grupo 1, tarefa 1: aguardar…**  
**grupo 0, tarefa 1: segundo loop…**  
**grupo 0, tarefa 0: concluído…**  
**grupo 1, tarefa 0: segundo loop…**  
**grupo 0, tarefa 1: concluído…**  
**grupo 1, tarefa 1: segundo loop…**  
**grupo 1, tarefa 0: concluído…**  
**grupo 1, tarefa 1: concluído…**  
**Usando EnhanceForwardProgress…**  
**grupo 0, tarefa 0: primeiro loop…**  
**grupo 1, tarefa 0: primeiro loop…**  
**grupo 0, tarefa 0: aguardar…**  
**grupo 0, tarefa 1: primeiro loop…**  
**grupo 1, tarefa 0: aguardar…**  
**grupo 1, tarefa 1: primeiro loop…**  
**grupo 0, tarefa 1: aguardar…**  
**grupo 0, tarefa 0: segundo loop…**  
**grupo 1, tarefa 1: aguardar…**  
**grupo 1, tarefa 0: segundo loop…**  
**grupo 0, tarefa 0: concluído…**  
**grupo 0, tarefa 1: segundo loop…**  
**grupo 1, tarefa 0: concluído…**  
**grupo 1, tarefa 1: segundo loop…**  
**grupo 0, tarefa 1: concluído…**  
**grupo 1, tarefa 1: concluído…** Ambas as políticas para gerenciar a mesma sequência de eventos.  No entanto, a política usando início de `EnhanceScheduleGroupLocality` ambos os agentes que fazem parte do primeiro grupo de agenda antes de iniciar os agentes que fazem parte do segundo grupo.  A política usando início de `EnhanceForwardProgress` um agente do primeiro grupo e depois inicia o primeiro agente no segundo grupo.  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `scheduling-protocol.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc scheduling\-protocol.cpp**  
  
## Consulte também  
 [Grupos de agendas](../../parallel/concrt/schedule-groups.md)   
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)