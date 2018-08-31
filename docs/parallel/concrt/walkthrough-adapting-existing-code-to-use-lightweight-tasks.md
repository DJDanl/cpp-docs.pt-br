---
title: 'Passo a passo: Adaptando um código existente para usar tarefas leves | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- using lightweight tasks [Concurrency Runtime]
- lightweight tasks, using [Concurrency Runtime]
ms.assetid: 1edfe818-d274-46de-bdd3-e92967c9bbe0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b4a48720a55487531e7dcfc2c38c9a0bf54c88a8
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43214325"
---
# <a name="walkthrough-adapting-existing-code-to-use-lightweight-tasks"></a>Instruções passo a passo: adaptando um código existente para usar tarefas leves
Este tópico mostra como adaptar o código existente que usa a API do Windows para criar e executar um thread para usar uma tarefa leve.  
  
 Um *tarefa leve* é uma tarefa agendada diretamente de um [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) ou [Concurrency:: schedulegroup](../../parallel/concrt/reference/schedulegroup-class.md) objeto. Tarefas leves são úteis quando você adaptar o código existente para usar a funcionalidade de agendamento de tempo de execução de simultaneidade.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Antes de começar este passo a passo, leia o tópico [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 O exemplo a seguir ilustra o uso típico da API do Windows para criar e executar um thread. Este exemplo usa o [CreateThread](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) função para chamar o `MyThreadFunction` em um thread separado.  
  
### <a name="code"></a>Código  
 [!code-cpp[concrt-windows-threads#1](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_1.cpp)]  
  
### <a name="comments"></a>Comentários  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
Parameters = 50, 100  
```  
  
 As etapas a seguir mostram como adaptar o exemplo de código para usar o tempo de execução de simultaneidade para executar a mesma tarefa.  
  
### <a name="to-adapt-the-example-to-use-a-lightweight-task"></a>Para adaptar o exemplo a fim de usar uma tarefa leve  
  
1.  Adicionar um `#include` diretiva para o arquivo de cabeçalho concrt. h.  
  
 [!code-cpp[concrt-migration-lwt#2](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_2.cpp)]  
  
2.  Adicionar um `using` diretiva para o `concurrency` namespace.  
  
 [!code-cpp[concrt-migration-lwt#3](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_3.cpp)]  
  
3.  Altere a declaração de `MyThreadFunction` para usar o `__cdecl` convenção de chamada e retornar `void`.  
  
 [!code-cpp[concrt-migration-lwt#4](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_4.cpp)]  
  
4.  Modificar a `MyData` estrutura para incluir uma [concurrency::event](../../parallel/concrt/reference/event-class.md) objeto que sinaliza para o aplicativo principal que a tarefa foi concluída.  
  
 [!code-cpp[concrt-migration-lwt#5](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_5.cpp)]  
  
5.  Substitua a chamada para `CreateThread` com uma chamada para o [concurrency::CurrentScheduler::ScheduleTask](reference/currentscheduler-class.md#scheduletask) método.  

  
 [!code-cpp[concrt-migration-lwt#6](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_6.cpp)]  
  

6.  Substitua a chamada para `WaitForSingleObject` com uma chamada para o [concurrency::event::wait](reference/event-class.md#wait) método para aguardar a conclusão da tarefa.  

 [!code-cpp[concrt-migration-lwt#7](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_7.cpp)]  
  
7.  Remova a chamada para `CloseHandle`.  
  
8.  Alterar a assinatura da definição de `MyThreadFunction` para corresponder a etapa 3.  
  
 [!code-cpp[concrt-migration-lwt#8](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_8.cpp)]  
  
9. No final dos `MyThreadFunction` funcionar, chamar o [concurrency::event::set](reference/event-class.md#set) método para sinalizar para o aplicativo principal que a tarefa foi concluída.  
  
 [!code-cpp[concrt-migration-lwt#9](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_9.cpp)]  
  
10. Remover o `return` instrução from `MyThreadFunction`.  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 Concluído o exemplo a seguir mostra o código que usa uma tarefa leve para chamar o `MyThreadFunction` função.  
  
### <a name="code"></a>Código  
 [!code-cpp[concrt-migration-lwt#1](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_10.cpp)]  
  
### <a name="comments"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Classe Scheduler](../../parallel/concrt/reference/scheduler-class.md)
