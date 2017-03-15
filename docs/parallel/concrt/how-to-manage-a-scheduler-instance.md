---
title: "Como gerenciar uma inst&#226;ncia de agendador | Microsoft Docs"
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
  - "gerenciando uma instância de agendador [Tempo de Execução de Simultaneidade]"
  - "instâncias de Agendador, gerenciando [tempo de execução de simultaneidade]"
ms.assetid: 2cc804f0-5ff3-498b-97f1-a9f67a005448
caps.latest.revision: 15
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como gerenciar uma inst&#226;ncia de agendador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As instâncias do agendador permitem associar políticas específicas de programação com os vários tipos de cargas de trabalho.  Este tópico contém dois exemplos básicos que mostram como criar e gerenciar uma instância do agendador.  
  
 Os exemplos a seguir cria os agendadores que usam as políticas padrão do agendador.  Para obter um exemplo que cria um agendador que usa uma política personalizado, consulte [Como especificar políticas de agendador específicas](../Topic/How%20to:%20Specify%20Specific%20Scheduler%20Policies.md).  
  
### Para gerenciar uma instância do agendador no aplicativo  
  
1.  Crie um objeto de [concurrency::SchedulerPolicy](../../parallel/concrt/reference/schedulerpolicy-class.md) que contém os valores de política para que o agendador usa.  
  
2.  Chame o método de [concurrency::CurrentScheduler::Create](../Topic/CurrentScheduler::Create%20Method.md) ou o método de [concurrency::Scheduler::Create](../Topic/Scheduler::Create%20Method.md) para criar uma instância do agendador.  
  
     Se você usar o método de `Scheduler::Create` , chame o método de [concurrency::Scheduler::Attach](../Topic/Scheduler::Attach%20Method.md) quando você precisa associar o agendador com o contexto atual.  
  
3.  Chame a função de [CreateEvent](http://msdn.microsoft.com/library/windows/desktop/ms682396) para criar um identificador em um objeto não sinalizado, redefinido automática do evento.  
  
4.  Passar o identificador do objeto de evento que você acabou de criar a [concurrency::CurrentScheduler::RegisterShutdownEvent](../Topic/CurrentScheduler::RegisterShutdownEvent%20Method.md) o método ou o método de [concurrency::Scheduler::RegisterShutdownEvent](../Topic/Scheduler::RegisterShutdownEvent%20Method.md) .  Isso registra o evento a ser definido quando o agendador é destruído.  
  
5.  Executar as tarefas que você deseja que o agendador atual para agendar.  
  
6.  Chame o método de [concurrency::CurrentScheduler::Detach](../Topic/CurrentScheduler::Detach%20Method.md) para desanexar o agendador atual e restaurar o agendador anterior como atual.  
  
     Se você usar o método de `Scheduler::Create` , chame o método de [concurrency::Scheduler::Release](../Topic/Scheduler::Release%20Method.md) para diminui a contagem de referência do objeto de `Scheduler` .  
  
7.  Passar o identificador do evento à função de [WaitForSingleObject](http://msdn.microsoft.com/library/windows/desktop/ms687032) a esperar para que o agendador para fechar.  
  
8.  Chame a função de [CloseHandle](http://msdn.microsoft.com/library/windows/desktop/ms724211) para fechar o identificador do objeto de evento.  
  
## Exemplo  
 O código a seguir mostra dois modos de gerenciar uma instância do agendador.  Cada exemplo usa basicamente o agendador padrão para executar uma tarefa que imprime em expansão o identificador exclusivo do agendador atual.  Cada exemplo usa uma instância do agendador para executar novamente a mesma tarefa.  Finalmente, cada exemplo restaura o agendador como padrão atual e executa a tarefa mais uma vez.  
  
 O primeiro exemplo usa a classe de [concurrency::CurrentScheduler](../Topic/CurrentScheduler%20Class.md) para criar uma instância do agendador e para associá\-la ao contexto atual.  O segundo exemplo usa a classe de [concurrency::Scheduler](../../parallel/concrt/reference/scheduler-class.md) para executar a mesma tarefa.  Normalmente, a classe de `CurrentScheduler` é usada para trabalhar com o agendador atual.  O segundo exemplo, usando a classe de `Scheduler` , é útil quando você deseja controlar quando o agendador está associado ao contexto atual ou quando você quiser associar agendadores específicos com as tarefas específicas.  
  
 [!code-cpp[concrt-scheduler-instance#1](../../parallel/concrt/codesnippet/CPP/how-to-manage-a-scheduler-instance_1.cpp)]  
  
 O exemplo produz a seguinte saída.  
  
  **Usando a classe de CurrentScheduler…**  
**ID do agendador atual: 0**  
**Criando e anexando o agendador…**  
**ID do agendador atual: 1**  
**Desanexando o agendador…**  
**ID do agendador atual: 0**  
**Usando a classe do agendador…**  
**ID do agendador atual: 0**  
**Criando o agendador…**  
**Anexando o agendador…**  
**ID do agendador atual: 2**  
**Desanexando o agendador…**  
**ID do agendador atual: 0**   
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `scheduler-instance.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc scheduler\-instance.cpp**  
  
## Consulte também  
 [Instâncias de agendador](../../parallel/concrt/scheduler-instances.md)   
 [Como especificar políticas de agendador específicas](../Topic/How%20to:%20Specify%20Specific%20Scheduler%20Policies.md)