---
title: "Classe structured_task_group | Microsoft Docs"
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
  - "ppl/concurrency::structured_task_group"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe structured_task_group"
ms.assetid: 742afa8c-c7b6-482c-b0ba-04c809927b22
caps.latest.revision: 21
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe structured_task_group
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe representa uma coleção de `structured_task_group` altamente estruturados de trabalho paralelo.  Você pode enfileirar de tarefas paralelas individuais em `structured_task_group` usando objetos de `task_handle` , e espera\-os para ser concluído, ou cancelá\-lo o grupo de trabalho antes que seja executada, que anulará todas as tarefas que não começa a execução.  
  
## Sintaxe  
  
```  
class structured_task_group;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor structured\_task\_group::structured\_task\_group](../Topic/structured_task_group::structured_task_group%20Constructor.md)|Sobrecarregado.  Cria um novo objeto de `structured_task_group` .|  
|[Destruidor structured\_task\_group::~structured\_task\_group](../Topic/structured_task_group::~structured_task_group%20Destructor.md)|Destrói um objeto de `structured_task_group` .  Você deve chamar `wait` ou o método de `run_and_wait` do objeto antes de destruidor que é executada, a menos que o destruidor esteja em execução no resultado da pilha que desenrola devido a uma exceção.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método structured\_task\_group::cancel](../Topic/structured_task_group::cancel%20Method.md)|Faz uma melhor tentativa de busca de cancelar a subárvore de trabalho enraizada neste grupo de trabalho.  Cada tarefa agendada no grupo de trabalho será cancelado transitiva se possível.|  
|[Método structured\_task\_group::is\_canceling](../Topic/structured_task_group::is_canceling%20Method.md)|Informa o chamador se o grupo de trabalho é atualmente no meio do cancelamento.  Isso não indica necessariamente que o método de `cancel` esteve chamado no objeto de `structured_task_group` \(embora essa qualifica realmente esse método para retornar `true`\).  Pode ter os casos que o objeto de `structured_task_group` é executar embutido e um grupo de trabalho para cima na árvore de trabalho foi cancelado mais.  Em casos como esses quando o tempo de execução pode determinar antecipadamente que o cancelamento correrá por esse objeto de `structured_task_group` , `true` será retornado também.|  
|[Método structured\_task\_group::run](../Topic/structured_task_group::run%20Method.md)|Sobrecarregado.  Agenda uma tarefa no objeto de `structured_task_group` .  O chamador gerencia o tempo de vida do objeto de `task_handle` passado para o parâmetro de `_Task_handle` .  A versão que usa o parâmetro `_Placement` faz a tarefa ser removido para executar no local especificado pelo parâmetro.|  
|[Método structured\_task\_group::run\_and\_wait](../Topic/structured_task_group::run_and_wait%20Method.md)|Sobrecarregado.  Agenda uma tarefa ser embutidos executado no contexto da chamada de com a ajuda do objeto de `structured_task_group` para suporte completo de cancelamento.  Se um objeto de `task_handle` é passado como um parâmetro a `run_and_wait`, o chamador é responsável por gerenciar o tempo de vida do objeto de `task_handle` .  A função em espera até que todo o trabalho no objeto de `structured_task_group` seja concluída ou cancele.|  
|[Método structured\_task\_group::wait](../Topic/structured_task_group::wait%20Method.md)|Espera até que todo o trabalho em `structured_task_group` seja concluída ou será cancelado.|  
  
## Comentários  
 Há várias restrições severas colocadas no uso de um objeto de `structured_task_group` para obter o desempenho:  
  
-   Um único objeto de `structured_task_group` não pode ser usado por vários threads.  Todas as operações em um objeto de `structured_task_group` devem ser executadas pelo thread que criou o objeto.  As duas exceções a essa regra são as funções de membro `cancel` e `is_canceling`.  O objeto não pode estar na lista de captura de uma expressão de lambda e ser usado em uma tarefa, a menos que a tarefa esteja usando uma das operações de cancelamento.  
  
-   Todas as tarefas agendadas para um objeto de `structured_task_group` são agendadas com o uso dos objetos de `task_handle` de que você precisa explicitamente gerenciar o tempo de vida.  
  
-   Vários grupos só podem ser usados na ordem absolutamente aninhado.  Se dois objetos de `structured_task_group` são declaradas, segundo que está sendo declarado \(interno\) deve destruct antes que qualquer método exceto `cancel` ou `is_canceling` ser chamado primeiro \(externa\).  Esta condição se aplica nos exemplos somente de declarar mais objetos de `structured_task_group` na mesma ou escopos funcional aninhados além de exemplos de uma tarefa que é enfileirada a `structured_task_group` pelos métodos de `run` ou de `run_and_wait` .  
  
-   Ao contrário da classe de `task_group` geral, todos os estados da classe de `structured_task_group` são finais.  Depois que você usarem as tarefas ao grupo e os espera para ser concluída, você não pode usar o mesmo grupo novamente.  
  
 Para obter mais informações, consulte [Paralelismo da tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
## Hierarquia de Herança  
 `structured_task_group`  
  
## Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe task\_group](../Topic/task_group%20Class.md)   
 [Classe task\_handle](../../../parallel/concrt/reference/task-handle-class.md)