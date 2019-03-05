---
title: 'Como: Especificar políticas de Agendador específicas'
ms.date: 11/04/2016
helpviewer_keywords:
- specifying scheduler policies [Concurrency Runtime]
- scheduler policies, specifying [Concurrency Runtime]
ms.assetid: 9c5149f9-ac34-4ff3-9e79-0bad103e4e6b
ms.openlocfilehash: 3c03ef6661ebefe0bfe9fab62938ce9987a4bca1
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57277853"
---
# <a name="how-to-specify-specific-scheduler-policies"></a>Como: Especificar políticas de Agendador específicas

Políticas de Agendador permitem controlar a estratégia que o Agendador usa quando ele gerencia as tarefas. Este tópico mostra como usar uma política de Agendador para aumentar a prioridade de thread de uma tarefa que imprime um indicador de progresso para o console.

Para obter um exemplo que usa políticas de Agendador personalizado juntamente com agentes assíncronos, consulte [como: Criar agentes que usam políticas de Agendador específicas](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md).

## <a name="example"></a>Exemplo

O exemplo a seguir executa duas tarefas em paralelo. A primeira tarefa computa a n<sup>ésimo</sup> número Fibonacci. A segunda tarefa imprime um indicador de progresso para o console.

A primeira tarefa usa a decomposição recursiva para calcular o número de Fibonacci. Ou seja, cada tarefa recursivamente cria subtarefas para calcular o resultado geral. Uma tarefa que usa a decomposição recursiva pode usar todos os recursos disponíveis e, assim, enfraquecer outras tarefas. Neste exemplo, a tarefa que imprime o indicador de progresso pode não receber acesso oportuno a recursos de computação.

Para fornecer a tarefa que imprime um acesso razoável de mensagem de progresso para recursos de computação, este exemplo usa as etapas descritas em [como: Gerenciar uma instância do Agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md) para criar uma instância de agendador que tenha uma política personalizada. A política personalizada Especifica a prioridade do thread para ser a classe de prioridade mais alta.

Este exemplo usa o [concurrency::call](../../parallel/concrt/reference/call-class.md) e [concurrency::timer](../../parallel/concrt/reference/timer-class.md) classes para imprimir o indicador de progresso. Essas classes têm versões dos seus construtores que usam uma referência a um [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) objeto que agenda-los. O exemplo usa o agendador padrão para agendar a tarefa que computa o número de Fibonacci e a instância de Agendador para agendar a tarefa que imprime o indicador de progresso.

Para ilustrar os benefícios de usar um agendador que tem uma política personalizada, este exemplo executa a tarefa geral duas vezes. Primeiro, o exemplo usa o agendador padrão para agendar as duas tarefas. O exemplo, em seguida, usa o Agendador para agendar a primeira tarefa padrão e um agendador que tem uma política personalizada para agendar a tarefa de segundo.

[!code-cpp[concrt-scheduler-policy#1](../../parallel/concrt/codesnippet/cpp/how-to-specify-specific-scheduler-policies_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Default scheduler:
...........................................................................done
Scheduler that has a custom policy:
...........................................................................done
```

Embora os dois conjuntos de tarefas produzem o mesmo resultado, a versão que usa uma política personalizada permite que a tarefa que imprime o indicador de progresso para ser executado em uma prioridade com privilégios elevados, de modo que ele se comporta de maneira mais responsiva.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `scheduler-policy.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc scheduler-policy.cpp**

## <a name="see-also"></a>Consulte também

[Políticas de agendador](../../parallel/concrt/scheduler-policies.md)<br/>
[Como: Gerenciar uma instância de agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md)<br/>
[Como: Criar agentes que usam políticas específicas do agendador](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md)
