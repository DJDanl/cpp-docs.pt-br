---
title: "Como: gerenciar uma instância de Agendador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- managing a scheduler instance [Concurrency Runtime]
- scheduler instances, managing [Concurrency Runtime]
ms.assetid: 2cc804f0-5ff3-498b-97f1-a9f67a005448
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f2e4916e0f563c4034dc27be1e3d911f42a65319
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-manage-a-scheduler-instance"></a>Como gerenciar uma instância de agendador
Instâncias de Agendador permitem associar políticas específicas de programação com vários tipos de cargas de trabalho. Este tópico contém dois exemplos básicos que mostram como criar e gerenciar uma instância de Agendador.  
  
 Os exemplos criam agendadores que usam as políticas de agendador padrão. Para um exemplo que cria um agendador que usa uma política personalizada, consulte [como: especificar políticas de Agendador específicas](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md).  
  
### <a name="to-manage-a-scheduler-instance-in-your-application"></a>Para gerenciar uma instância do agendador no aplicativo  
  
1.  Criar um [concurrency::SchedulerPolicy](../../parallel/concrt/reference/schedulerpolicy-class.md) valores de objeto que contém a política para o Agendador usar.  
  

2.  Chamar o [concurrency::CurrentScheduler::Create](reference/currentscheduler-class.md#create) método ou o [concurrency::Scheduler::Create](reference/scheduler-class.md#create) método para criar uma instância de Agendador.  
  
     Se você usar o `Scheduler::Create` método, chame o [concurrency::Scheduler::Attach](reference/scheduler-class.md#attach) método quando você precisa associar o Agendador do contexto atual.  
  
3.  Chamar o [CreateEvent](http://msdn.microsoft.com/library/windows/desktop/ms682396) função para criar um identificador para um objeto de evento de redefinição automática não sinalizado.  
  
4.  Passar o identificador para o objeto de evento que você criou para o [concurrency::CurrentScheduler::RegisterShutdownEvent](reference/currentscheduler-class.md#registershutdownevent) método ou o [concurrency::Scheduler::RegisterShutdownEvent](reference/scheduler-class.md#registershutdownevent) método. Isso registra o evento a ser definido quando o Agendador é destruído.  
  
5.  Execute as tarefas que você deseja que o Agendador do agendamento.  
  
6.  Chamar o [concurrency::CurrentScheduler::Detach](reference/currentscheduler-class.md#detach) método para desanexar o Agendador atual e restaurar o Agendador anterior que o atual.  
  
     Se você usar o `Scheduler::Create` método, chame o [concurrency::Scheduler::Release](reference/scheduler-class.md#release) método para diminuir a contagem de referência a `Scheduler` objeto.  
  
7.  Passar o identificador para o evento para o [WaitForSingleObject](http://msdn.microsoft.com/library/windows/desktop/ms687032) função aguardar o Agendador desligar.  
  
8.  Chamar o [CloseHandle](http://msdn.microsoft.com/library/windows/desktop/ms724211) função para fechar o identificador para o objeto de evento.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra duas maneiras para gerenciar uma instância do Agendador. Cada exemplo primeiro usa o agendador padrão para executar uma tarefa que imprime o identificador exclusivo do Agendador atual. Cada exemplo, em seguida, usa uma instância de Agendador para executar a mesma tarefa novamente. Por fim, cada exemplo restaura o agendador padrão que o atual e executa a tarefa mais uma vez.  
  
 O primeiro exemplo usa o [concurrency::CurrentScheduler](../../parallel/concrt/reference/currentscheduler-class.md) classe para criar uma instância de agendador e associá-lo com o contexto atual. O segundo exemplo usa o [concurrency::Scheduler](../../parallel/concrt/reference/scheduler-class.md) classe para executar a mesma tarefa. Normalmente, o `CurrentScheduler` classe é usada para trabalhar com o Agendador atual. O segundo exemplo usa o `Scheduler` da classe, é útil quando você deseja controlar quando o Agendador é associado ao contexto atual ou quando você deseja associar a agendadores específicos com tarefas específicas.  
  
 [!code-cpp[concrt-scheduler-instance#1](../../parallel/concrt/codesnippet/cpp/how-to-manage-a-scheduler-instance_1.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
Using CurrentScheduler class...  
 
Current scheduler id: 0  
Creating and attaching scheduler...  
Current scheduler id: 1  
Detaching scheduler...  
Current scheduler id: 0  
 
Using Scheduler class...  
 
Current scheduler id: 0  
Creating scheduler...  
Attaching scheduler...  
Current scheduler id: 2  
Detaching scheduler...  
Current scheduler id: 0  
```  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `scheduler-instance.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc Agendador-instance.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Instâncias de Agendador](../../parallel/concrt/scheduler-instances.md)   
 [Como especificar políticas de agendador específicas](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md)

