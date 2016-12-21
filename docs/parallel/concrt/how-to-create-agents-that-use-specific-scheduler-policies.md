---
title: "Como cria agentes que usam pol&#237;ticas de agendador espec&#237;ficas | Microsoft Docs"
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
  - "políticas de Agendador, agentes [tempo de execução de simultaneidade]"
  - "criando agentes que usam políticas específicas [Tempo de Execução de Simultaneidade]"
ms.assetid: 46a3e265-0777-4ec3-a142-967bafc49d67
caps.latest.revision: 14
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como cria agentes que usam pol&#237;ticas de agendador espec&#237;ficas
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um agente é um componente de aplicativo que funciona de forma assíncrona com outros componentes para resolver tarefas de computação maiores.  Um agente normalmente tem um ciclo de vida definir e mantém o estado.  
  
 Cada agente pode ter requisitos de aplicativo exclusivos.  Por exemplo, um agente que permite a interação do usuário \(recuperando a entrada ou saída exibindo\) pode exigir um acesso de prioridade mais alta aos recursos de computação.  As políticas do agendador permitem controlar a estratégia que o agendador usa a gerenciar tarefas.  Este tópico demonstra como criar os agentes que usam políticas específicas do agendador.  
  
 Para obter um exemplo básico que use as políticas personalizadas do agendador junto com blocos assíncronas de mensagem, consulte [Como especificar políticas de agendador específicas](../Topic/How%20to:%20Specify%20Specific%20Scheduler%20Policies.md).  
  
 Este tópico usa a funcionalidade de biblioteca assíncrona de agentes, como agentes, blocos da mensagem e, mensagem\- passar funções, para executar o trabalho.  Para obter mais informações sobre a biblioteca assíncrona de agentes, consulte [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md).  
  
## Exemplo  
 O exemplo a seguir define duas classes que derivam de [concurrency::agent](../../parallel/concrt/reference/agent-class.md): `permutor` e `printer`.  A classe de `permutor` calcula todas as permutações de uma cadeia de caracteres de entrada indicada.  A classe de `printer` imprime mensagens de progresso no console.  A classe de `permutor` executa uma operação computacional\- intensiva, que pode usar todos os recursos de computação disponíveis.  Para ser útil, a classe de `printer` deve imprimir cada mensagem de progresso de maneira oportuna.  
  
 Para fornecer a classe de `printer` acesso restrito aos recursos de computação, esse exemplo usa as etapas que são descritas em [Como gerenciar uma instância de agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md) para criar uma instância do agendador que tem uma política personalizado.  A política personalizado especifica a prioridade de thread para ser a classe prioridade mais alta.  
  
 Para ilustrar os benefícios de usar um agendador que tem uma política personalizado, este exemplo executa a tarefa total duas vezes em.  O primeiro exemplo usa o agendador padrão para agendar as duas tarefas.  O exemplo usa o agendador padrão para agendar o objeto de `permutor` , e um agendador que tem uma política personalizado para agendar o objeto de `printer` .  
  
 [!code-cpp[concrt-permute-strings#1](../../parallel/concrt/codesnippet/CPP/how-to-create-agents-that-use-specific-scheduler-policies_1.cpp)]  
  
 O exemplo produz a seguinte saída.  
  
  **Com o agendador padrão:**  
**Computando todas as permutações de toranja”… “**  
**100% completo…**  
**Com prioridade mais alta de contexto:**  
**Computando todas as permutações de toranja”… “**  
**100% completo…** Embora ambos os conjuntos de tarefas gerenciam o mesmo resultado, a versão que usa uma política personalizado habilita o objeto de `printer` para ser executado em uma prioridade alto de forma que se com comportamento mais respondendo.  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `permute-strings.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc permute\-strings.cpp**  
  
## Consulte também  
 [Políticas de agendador](../../parallel/concrt/scheduler-policies.md)   
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)   
 