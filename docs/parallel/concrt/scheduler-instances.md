---
title: "Inst&#226;ncias de agendador | Microsoft Docs"
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
  - "instâncias de agendador"
ms.assetid: 4819365f-ef99-49cc-963e-50a2a35a8d6b
caps.latest.revision: 7
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Inst&#226;ncias de agendador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento descreve a função de instâncias do agendador em tempo de execução de simultaneidade e como usar as classes de [concurrency::Scheduler](../../parallel/concrt/reference/scheduler-class.md) e de [concurrency::CurrentScheduler](../Topic/CurrentScheduler%20Class.md) para criar e gerenciar instâncias do agendador.  As instâncias do agendador são úteis quando você deseja associar políticas explícitas de programar com tipos específicos de cargas de trabalho.  Por exemplo, você pode criar uma instância do agendador para executar algumas tarefas em uma prioridade alto de thread e para usar o agendador padrão para executar outras tarefas na prioridade normal de thread.  
  
> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão, e em virtude disso não é necessário criar um relatório em seu aplicativo.  Como o agendador de tarefas o ajuda a ajustar o desempenho dos aplicativos, recomendamos que você comece com [Biblioteca de padrões paralelos \(PPL\)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você é novato em tempo de execução de simultaneidade.  
  
##  <a name="top"></a> Seções  
  
-   [O agendador do e as classes de CurrentScheduler](#classes)  
  
-   [Criando uma instância do agendador](#creating)  
  
-   [Gerenciando o tempo de vida de uma instância do agendador](#managing)  
  
-   [Métodos e recursos](#features)  
  
-   [Exemplo](#example)  
  
##  <a name="classes"></a> O agendador do e as classes de CurrentScheduler  
 O agendador de tarefas permite que aplicativos usar uma ou mais *instâncias do agendador* para agendar o trabalho.  A classe de [concurrency::Scheduler](../../parallel/concrt/reference/scheduler-class.md) representa uma instância do agendador e encapsula a funcionalidade que está relacionada a agendar tarefas.  
  
 Um thread que é anexado a um agendador é conhecido como *um contexto de execução*, ou apenas *o contexto*.  Um agendador pode ser ativo no contexto atual a qualquer momento.  O agendador ativa também é conhecido como *o agendador atual*.  O tempo de execução de simultaneidade usa a classe de [concurrency::CurrentScheduler](../Topic/CurrentScheduler%20Class.md) para fornecer acesso ao agendador atual.  O agendador atual para um contexto pode ser diferente do agendador atual para outro contexto.  O tempo de execução não fornece uma representação de nível de processo do agendador atual.  
  
 Normalmente, a classe de `CurrentScheduler` é usada para acessar o agendador atual.  A classe de `Scheduler` é útil quando você precisa gerenciar um agendador que não seja atual.  
  
 As seções a seguir descrevem como criar e gerenciar uma instância do agendador.  Para obter um exemplo completo que mostra essas tarefas, consulte [Como gerenciar uma instância de agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md).  
  
 \[[Superior](#top)\]  
  
##  <a name="creating"></a> Criando uma instância do agendador  
 Essas há três maneiras de criar um objeto de `Scheduler` :  
  
-   Se nenhum agendador existir, o tempo de execução cria um agendador padrão para quando você usa a funcionalidade de tempo de execução, por exemplo, um algoritmo paralelo, para executar o trabalho.  O agendador padrão se tornará o agendador atual para o contexto que inicia o trabalho paralelo.  
  
-   O método de [concurrency::CurrentScheduler::Create](../Topic/CurrentScheduler::Create%20Method.md) cria um objeto de `Scheduler` que usa uma política específica e esse agendador associado ao contexto atual.  
  
-   O método de [concurrency::Scheduler::Create](../Topic/Scheduler::Create%20Method.md) cria um objeto de `Scheduler` que usa uma política específica, mas não o associa ao contexto atual.  
  
 Permitir que o tempo de execução crie um agendador padrão permite que todas as tarefas simultâneas compartilhar o mesmo agendador.  Normalmente, a funcionalidade fornecida por [A paralela da biblioteca](../../parallel/concrt/parallel-patterns-library-ppl.md) \(PPL\) ou por [Biblioteca assíncrona de agentes](../../parallel/concrt/asynchronous-agents-library.md) é usada para executar o trabalho paralelo.  Consequentemente, você não precisa trabalhar diretamente com o agendador para controlar política ou seu tempo de vida.  Quando você usa o PPL ou a biblioteca de agentes, o tempo de execução cria o agendador padrão se não existir e a torna o agendador atual para cada contexto.  Quando você criar um agendador e o define como o agendador atual, os tempo de execução usa esse agendador agendar tarefas.  Criar instâncias adicionais do agendador apenas quando você precisar de uma política específica de programação.  Para obter mais informações sobre as políticas associadas a um agendador, consulte [Políticas de agendador](../../parallel/concrt/scheduler-policies.md).  
  
 \[[Superior](#top)\]  
  
##  <a name="managing"></a> Gerenciando o tempo de vida de uma instância do agendador  
 O tempo de execução usa um mecanismo de referência\- contagem para controlar o tempo de vida de objetos de `Scheduler` .  
  
 Quando você usa o método de `CurrentScheduler::Create` ou o método de `Scheduler::Create` para criar um objeto de `Scheduler` , o tempo de execução define a contagem inicial de referência do agendador a um.  O tempo de execução incrementa a contagem de referência quando você chama o método de [concurrency::Scheduler::Attach](../Topic/Scheduler::Attach%20Method.md) .  O método de `Scheduler::Attach` associa o objeto de `Scheduler` junto com o contexto atual.  Isso torna o agendador atual.  Quando você chama o método de `CurrentScheduler::Create` , o tempo de execução ambos cria um objeto de `Scheduler` e anexe\-o ao contexto atual \(e definirá a contagem de referência a uma\).  Você também pode usar o método de [concurrency::Scheduler::Reference](../Topic/Scheduler::Reference%20Method.md) para incrementar a contagem de referência de um objeto de `Scheduler` .  
  
 O tempo de execução do diminuirá a contagem de referência quando você chama o método de [concurrency::CurrentScheduler::Detach](../Topic/CurrentScheduler::Detach%20Method.md) para desanexar o agendador atual, ou chama o método de [concurrency::Scheduler::Release](../Topic/Scheduler::Release%20Method.md) .  Quando a contagem de referência chegar a zero, o tempo de execução ao concluir agendamento de tarefas do objeto de `Scheduler` depois.  Uma tarefa em execução é permitida incrementar a contagem de referência do agendador atual.  Em virtude disso, se a contagem de referência atingir incrementos de zero e uma tarefa a contagem de referência, o tempo de execução não destrói o objeto de `Scheduler` até que a contagem de referência o escopo novamente zero e todas as tarefas é concluído.  
  
 O tempo de execução mantém uma pilha interna de objetos de `Scheduler` para cada contexto.  Quando você chamar o método de `Scheduler::Attach` ou de `CurrentScheduler::Create` , o tempo de execução que objeto de `Scheduler` na pilha no contexto atual.  Isso torna o agendador atual.  Quando você chama `CurrentScheduler::Detach`, o tempo de execução aparece no agendador atual da pilha para o contexto atual e define anterior como o agendador atual.  
  
 O tempo de execução fornece várias maneiras para gerenciar o ciclo de vida de uma instância do agendador.  A tabela a seguir mostra o método apropriado que se libera ou desanexa o agendador do contexto atual para cada método que cria ou anexa um agendador ao contexto atual.  
  
|Crie ou anexar o método|Liberar ou o método desanexar|  
|-----------------------------|-----------------------------------|  
|`CurrentScheduler::Create`|`CurrentScheduler::Detach`|  
|`Scheduler::Create`|`Scheduler::Release`|  
|`Scheduler::Attach`|`CurrentScheduler::Detach`|  
|`Scheduler::Reference`|`Scheduler::Release`|  
  
 Chamando a versão inadequada ou desanexar o método gerencia o comportamento não especificado em tempo de execução.  
  
 Quando você usar a funcionalidade, por exemplo, o PPL, o que faz com que o tempo de execução crie o agendador padrão para você, não liberam nem desanexar este agendador.  O tempo de execução gerencia o tempo de vida de qualquer agendador que cria.  
  
 Como o tempo de execução não destrói um objeto de `Scheduler` antes que todas as tarefas sejam concluídas, você pode usar o método de [concurrency::Scheduler::RegisterShutdownEvent](../Topic/Scheduler::RegisterShutdownEvent%20Method.md) ou o método de [concurrency::CurrentScheduler::RegisterShutdownEvent](../Topic/CurrentScheduler::RegisterShutdownEvent%20Method.md) para receber uma notificação quando um objeto de `Scheduler` é destruído.  Isso é útil quando você precisa esperar cada tarefa que está agendada por um objeto de `Scheduler` para ser concluída.  
  
 \[[Superior](#top)\]  
  
##  <a name="features"></a> Métodos e recursos  
 Esta seção resume os métodos importantes das classes de `CurrentScheduler` e de `Scheduler` .  
  
 Pense da classe de `CurrentScheduler` como um auxiliar para criar um agendador para uso no contexto atual.  A classe de `Scheduler` permite controlar um agendador que pertence a outro contexto.  
  
 A tabela a seguir mostra os métodos importantes que são definidos pela classe de `CurrentScheduler` .  
  
|Método|Descrição|  
|------------|---------------|  
|[Criar](../Topic/CurrentScheduler::Create%20Method.md)|Cria um objeto de `Scheduler` que usa a política especificada e a associa ao contexto atual.|  
|[Obter...](../Topic/CurrentScheduler::Get%20Method.md)|Recupera um ponteiro para o objeto de `Scheduler` associado ao contexto atual.  Esse método não incrementa a contagem de referência do objeto de `Scheduler` .|  
|[Detach](../Topic/CurrentScheduler::Detach%20Method.md)|Desanexa o agendador atual do contexto atual e define anterior como o agendador atual.|  
|[RegisterShutdownEvent](../Topic/CurrentScheduler::RegisterShutdownEvent%20Method.md)|Registra um evento que define o tempo de execução quando o agendador atual é destruído.|  
|[CreateScheduleGroup](../Topic/CurrentScheduler::CreateScheduleGroup%20Method.md)|Cria um objeto de [concurrency::ScheduleGroup](../Topic/ScheduleGroup%20Class.md) no agendador atual.|  
|[ScheduleTask](../Topic/CurrentScheduler::ScheduleTask%20Method.md)|Adiciona uma tarefa de peso leve à fila de programação do agendador atual.|  
|[GetPolicy](../Topic/CurrentScheduler::GetPolicy%20Method.md)|Recupera uma cópia da política associada ao agendador atual.|  
  
 A tabela a seguir mostra os métodos importantes que são definidos pela classe de `Scheduler` .  
  
|Método|Descrição|  
|------------|---------------|  
|[Criar](../Topic/Scheduler::Create%20Method.md)|Cria um objeto de `Scheduler` que usa a política especificada.|  
|[Anexar](../Topic/Scheduler::Attach%20Method.md)|Associa o objeto de `Scheduler` junto com o contexto atual.|  
|[Referência](../Topic/Scheduler::Reference%20Method.md)|Adiciona a referência do contador do objeto de `Scheduler` .|  
|[Versão](../Topic/Scheduler::Release%20Method.md)|Diminui a referência do contador do objeto de `Scheduler` .|  
|[RegisterShutdownEvent](../Topic/Scheduler::RegisterShutdownEvent%20Method.md)|Registra um evento que o tempo de execução quando define o objeto de `Scheduler` é destruído.|  
|[CreateScheduleGroup](../Topic/Scheduler::CreateScheduleGroup%20Method.md)|Cria um objeto de [concurrency::ScheduleGroup](../Topic/ScheduleGroup%20Class.md) no objeto de `Scheduler` .|  
|[ScheduleTask](../Topic/Scheduler::ScheduleTask%20Method.md)|Agenda uma tarefa de peso leve do objeto de `Scheduler` .|  
|[GetPolicy](../Topic/Scheduler::GetPolicy%20Method.md)|Recupera uma cópia da política associada ao objeto de `Scheduler` .|  
|[SetDefaultSchedulerPolicy](../Topic/Scheduler::SetDefaultSchedulerPolicy%20Method.md)|Define a política para que o tempo de execução ao criar o agendador padrão.|  
|[ResetDefaultSchedulerPolicy](../Topic/Scheduler::ResetDefaultSchedulerPolicy%20Method.md)|Restaura a política padrão para aquela que estava ativo antes da chamada a `SetDefaultSchedulerPolicy`.  Se o agendador padrão é criado quando essa chamada, as configurações padrão da política de tempo de execução usa para criar o agendador.|  
  
 \[[Superior](#top)\]  
  
##  <a name="example"></a> Exemplo  
 Para obter exemplos básicos como criar e gerenciar uma instância do agendador, consulte [Como gerenciar uma instância de agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md).  
  
## Consulte também  
 [Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Como gerenciar uma instância de agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md)   
 [Políticas de agendador](../../parallel/concrt/scheduler-policies.md)   
 [Grupos de agendas](../../parallel/concrt/schedule-groups.md)