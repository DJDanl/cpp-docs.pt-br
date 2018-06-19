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
ms.openlocfilehash: c4fe3bb4b576bd1f9160b4a3cdc3142be5cdff05
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33688538"
---
# <a name="walkthrough-adapting-existing-code-to-use-lightweight-tasks"></a>Instruções passo a passo: adaptando um código existente para usar tarefas leves
Este tópico mostra como adaptar o código existente que usa a API do Windows para criar e executar um thread para usar uma tarefa simples.  
  
 Um *tarefa leve* é uma tarefa que você agendar diretamente de um [concurrency::Scheduler](../../parallel/concrt/reference/scheduler-class.md) ou [concurrency::ScheduleGroup](../../parallel/concrt/reference/schedulegroup-class.md) objeto. Tarefas leves são úteis quando você adaptar o código existente para usar a funcionalidade de agendamento de tempo de execução de simultaneidade.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Antes de começar este passo a passo, leia o tópico [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 O exemplo a seguir ilustra o uso típico da API do Windows para criar e executar um thread. Este exemplo usa o [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453) a função para chamar o `MyThreadFunction` em um thread separado.  
  
### <a name="code"></a>Código  
 [!code-cpp[concrt-windows-threads#1](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_1.cpp)]  
  
### <a name="comments"></a>Comentários  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
Parameters = 50, 100  
```  
  
 As etapas a seguir mostram como adaptar o exemplo de código para usar o tempo de execução de simultaneidade para executar a mesma tarefa.  
  
### <a name="to-adapt-the-example-to-use-a-lightweight-task"></a>Para adaptar o exemplo a fim de usar uma tarefa leve  
  
1.  Adicionar um `#include` diretiva para o concrt.h do arquivo de cabeçalho.  
  
 [!code-cpp[concrt-migration-lwt#2](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_2.cpp)]  
  
2.  Adicionar um `using` diretiva para o `concurrency` namespace.  
  
 [!code-cpp[concrt-migration-lwt#3](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_3.cpp)]  
  
3.  Altere a declaração de `MyThreadFunction` para usar o `__cdecl` convenção de chamada e retornar `void`.  
  
 [!code-cpp[concrt-migration-lwt#4](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_4.cpp)]  
  
4.  Modificar o `MyData` estrutura para incluir um [concurrency::event](../../parallel/concrt/reference/event-class.md) objeto que informa ao aplicativo principal que a tarefa é concluída.  
  
 [!code-cpp[concrt-migration-lwt#5](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_5.cpp)]  
  
5.  Substitua a chamada para `CreateThread` com uma chamada para o [concurrency::CurrentScheduler::ScheduleTask](reference/currentscheduler-class.md#scheduletask) método.  

  
 [!code-cpp[concrt-migration-lwt#6](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_6.cpp)]  
  

6.  Substitua a chamada para `WaitForSingleObject` com uma chamada para o [concurrency::event::wait](reference/event-class.md#wait) método Aguarde até que a tarefa seja concluída.  

 [!code-cpp[concrt-migration-lwt#7](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_7.cpp)]  
  
7.  Remova a chamada para `CloseHandle`.  
  
8.  Alterar a assinatura da definição de `MyThreadFunction` para corresponder a etapa 3.  
  
 [!code-cpp[concrt-migration-lwt#8](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_8.cpp)]  
  
9. No final do `MyThreadFunction` funcionar, chame o [concurrency::event::set](reference/event-class.md#set) método para sinalizar para o aplicativo principal que a tarefa é concluída.  
  
 [!code-cpp[concrt-migration-lwt#9](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_9.cpp)]  
  
10. Remover o `return` instrução do `MyThreadFunction`.  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 Concluído o exemplo a seguir mostra o código que usa uma tarefa simples para chamar o `MyThreadFunction` função.  
  
### <a name="code"></a>Código  
 [!code-cpp[concrt-migration-lwt#1](../../parallel/concrt/codesnippet/cpp/walkthrough-adapting-existing-code-to-use-lightweight-tasks_10.cpp)]  
  
### <a name="comments"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Classe Scheduler](../../parallel/concrt/reference/scheduler-class.md)
