---
title: 'Como: Gerenciar uma instância do Agendador'
ms.date: 11/04/2016
helpviewer_keywords:
- managing a scheduler instance [Concurrency Runtime]
- scheduler instances, managing [Concurrency Runtime]
ms.assetid: 2cc804f0-5ff3-498b-97f1-a9f67a005448
ms.openlocfilehash: d8e79f7c132abd8e43f661f4dc7c7bb758cb2a6d
ms.sourcegitcommit: c85c8a1226d8fbbaa29f4691ed719f8e6cc6575c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/24/2019
ms.locfileid: "54893984"
---
# <a name="how-to-manage-a-scheduler-instance"></a>Como: Gerenciar uma instância do Agendador

Instâncias de Agendador permitem que você associar políticas de agendamento específicas com vários tipos de cargas de trabalho. Este tópico contém dois exemplos básicos que mostram como criar e gerenciar uma instância do Agendador.

Os exemplos criam agendadores que usam as políticas de agendador padrão. Para um exemplo que cria um agendador que usa uma política personalizada, consulte [como: Especificar políticas de Agendador específicas](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md).

### <a name="to-manage-a-scheduler-instance-in-your-application"></a>Para gerenciar uma instância do agendador no aplicativo

1. Criar uma [concurrency::SchedulerPolicy](../../parallel/concrt/reference/schedulerpolicy-class.md) valores de objeto que contém a política para o Agendador a ser usado.

1. Chame o [concurrency::CurrentScheduler::Create](reference/currentscheduler-class.md#create) método ou o [concurrency::Scheduler::Create](reference/scheduler-class.md#create) método para criar uma instância do Agendador.

   Se você usar o `Scheduler::Create` método, a chamada a [concurrency::Scheduler::Attach](reference/scheduler-class.md#attach) método quando você precisa associar o Agendador com o contexto atual.

1. Chame o [CreateEvent](/windows/desktop/api/synchapi/nf-synchapi-createeventa) função para criar um identificador para um objeto de evento de redefinição automática não sinalizado.

1. Passar o identificador para o objeto de evento que você acabou de criar para o [concurrency::CurrentScheduler::RegisterShutdownEvent](reference/currentscheduler-class.md#registershutdownevent) método ou o [concurrency::Scheduler::RegisterShutdownEvent](reference/scheduler-class.md#registershutdownevent) método. Isso registra o evento a ser definido quando o Agendador é destruído.

1. Execute as tarefas que você deseja que o Agendador atual para agendar.

1. Chame o [concurrency::CurrentScheduler::Detach](reference/currentscheduler-class.md#detach) método para desanexar o Agendador atual e restaurar o Agendador anterior que o atual.

   Se você usar o `Scheduler::Create` método, a chamada a [concurrency::Scheduler::Release](reference/scheduler-class.md#release) método para diminuir a contagem de referência do `Scheduler` objeto.

1. Passar o identificador para o evento para o [WaitForSingleObject](/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject) função esperar o Agendador desligar.

1. Chame o [CloseHandle](/windows/desktop/api/handleapi/nf-handleapi-closehandle) função para fechar o identificador para o objeto de evento.

## <a name="example"></a>Exemplo

O código a seguir mostra duas maneiras para gerenciar uma instância do Agendador. Primeiro, cada exemplo utiliza o agendador padrão para executar uma tarefa que imprime o identificador exclusivo do Agendador atual. Cada exemplo, em seguida, usa uma instância do Agendador para executar a mesma tarefa novamente. Por fim, cada exemplo restaura o agendador padrão que o atual e executa a tarefa mais uma vez.

O primeiro exemplo usa o [concurrency::CurrentScheduler](../../parallel/concrt/reference/currentscheduler-class.md) classe para criar uma instância do Agendador e associá-la com o contexto atual. O segundo exemplo usa o [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) classe para executar a mesma tarefa. Normalmente, o `CurrentScheduler` classe é usada para trabalhar com o Agendador atual. O segundo exemplo usa o `Scheduler` de classe, é útil quando você deseja controlar quando o Agendador está associado com o contexto atual ou quando você deseja associar a agendadores específicos a tarefas específicas.

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

[Instâncias de agendador](../../parallel/concrt/scheduler-instances.md)<br/>
[Como: Especificar políticas específicas do agendador](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md)

