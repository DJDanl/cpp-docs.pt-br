---
title: "Classe Scheduler | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "concrt/concurrency::Scheduler"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de agendador"
ms.assetid: 34cf7961-048d-4852-8a5c-a32f823e3506
caps.latest.revision: 19
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe Scheduler
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Representa uma abstração para um agendador de tempo de execução de simultaneidade.  
  
## Sintaxe  
  
```  
class Scheduler;  
```  
  
## Membros  
  
### Construtores Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor Scheduler::Scheduler](../Topic/Scheduler::Scheduler%20Constructor.md)|Um objeto da classe de `Scheduler` pode criado somente por meio de métodos de fábrica, ou implicitamente.|  
|[Destruidor Scheduler::~Scheduler](../Topic/Scheduler::~Scheduler%20Destructor.md)|Um objeto da classe de `Scheduler` é destruído implicitamente quando todas as referências externas a ela são eliminados de existir.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método Scheduler::Attach](../Topic/Scheduler::Attach%20Method.md)|Anexa o agendador do contexto de chamada.  Depois que esse método retornar, o contexto de chamada é gerenciado por agendador e o agendador se torna o agendador atual.|  
|[Método Scheduler::Create](../Topic/Scheduler::Create%20Method.md)|Cria um novo agendador cujo comportamento é descrito pelo parâmetro de `_Policy` , coloca uma referência inicial no agendador, e retorna\-lhe um ponteiro.|  
|[Método Scheduler::CreateScheduleGroup](../Topic/Scheduler::CreateScheduleGroup%20Method.md)|Sobrecarregado.  Cria um novo grupo de agenda no agendador.  A versão que usa o parâmetro `_Placement` causa tarefas dentro do grupo da agenda recém\-criada ser removido para executar no local especificado pelo parâmetro.|  
|[Método Scheduler::GetNumberOfVirtualProcessors](../Topic/Scheduler::GetNumberOfVirtualProcessors%20Method.md)|Retorna o número atual de processadores virtuais para o agendador.|  
|[Método Scheduler::GetPolicy](../Topic/Scheduler::GetPolicy%20Method.md)|Retorna uma cópia de política que o agendador esteve criado com.|  
|[Método Scheduler::Id](../Topic/Scheduler::Id%20Method.md)|Retorna um identificador exclusivo do agendador.|  
|[Método Scheduler::IsAvailableLocation](../Topic/Scheduler::IsAvailableLocation%20Method.md)|Determina se um determinado local está disponível no agendador.|  
|[Método Scheduler::Reference](../Topic/Scheduler::Reference%20Method.md)|Incrementa a contagem de referência do agendador.|  
|[Método Scheduler::RegisterShutdownEvent](../Topic/Scheduler::RegisterShutdownEvent%20Method.md)|Faz com que o identificador de eventos do windows passado no parâmetro de `_Event` a ser sinalizado quando o agendador foi desligado e se destruído.  O evento é sinalizado, qualquer trabalho que tivesse sido agendada do agendador está cheio.  Vários eventos de desligamento podem ser registrados com esse método.|  
|[Método Scheduler::Release](../Topic/Scheduler::Release%20Method.md)|Diminui a contagem de referência do agendador.|  
|[Método Scheduler::ResetDefaultSchedulerPolicy](../Topic/Scheduler::ResetDefaultSchedulerPolicy%20Method.md)|Redefine a política padrão do agendador à opção de tempo de execução.  Um agendador padrão é criado na próxima vez, ele usará as configurações de política da opção de tempo de execução.|  
|[Método Scheduler::ScheduleTask](../Topic/Scheduler::ScheduleTask%20Method.md)|Sobrecarregado.  Agenda uma tarefa de peso leve no agendador.  A tarefa de peso leve será colocada em um grupo de agenda determinado em tempo de execução.  A versão que usa o parâmetro `_Placement` faz a tarefa ser removido para executar no local especificado.|  
|[Método Scheduler::SetDefaultSchedulerPolicy](../Topic/Scheduler::SetDefaultSchedulerPolicy%20Method.md)|Permite que uma política definida pelo usuário é usada para criar o agendador padrão.  Esse método pode ser chamado somente quando nenhum agendador padrão existe no processo.  Depois que uma política padrão tiver sido definida, permanece em vigor até a chamada válido a seguir `SetDefaultSchedulerPolicy` o método ou de [ResetDefaultSchedulerPolicy](../Topic/Scheduler::ResetDefaultSchedulerPolicy%20Method.md) .|  
  
## Comentários  
 O agendador de tempo de execução de simultaneidade usa os contextos de execução, que são mapeados para os contextos de execução do sistema operacional, como um thread, para executar o trabalho em fila a ele por seu aplicativo.  A qualquer momento, a simultaneidade em nível de um agendador é igual ao número de processador virtual conceder a ele pelo Gerenciador de Recursos.  Um processador virtual é uma abstração para um recurso de processamento e mapeia para um thread de hardware seguro no sistema subjacente.  Somente um único contexto de agendador pode ser executado em um processador virtual em um determinado momento.  
  
 O tempo de execução de simultaneidade criará um agendador padrão pelo processo para executar o trabalho paralelo.  Além disso você pode criar suas próprias instâncias do agendador e manipulá\-las que usam essa classe.  
  
## Hierarquia de Herança  
 `Scheduler`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Scheduler Class](../../../parallel/concrt/reference/scheduler-class.md)   
 [Enumeração PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md)   
 [Agendador de Tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)