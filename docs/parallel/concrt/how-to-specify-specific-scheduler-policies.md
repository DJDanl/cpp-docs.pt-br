---
title: Como especificar políticas de agendador específicas
ms.date: 11/04/2016
helpviewer_keywords:
- specifying scheduler policies [Concurrency Runtime]
- scheduler policies, specifying [Concurrency Runtime]
ms.assetid: 9c5149f9-ac34-4ff3-9e79-0bad103e4e6b
ms.openlocfilehash: bd5edfbdf6b0fda9c7e327dab9538bbf6b5e4b12
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142447"
---
# <a name="how-to-specify-specific-scheduler-policies"></a>Como especificar políticas de agendador específicas

As políticas do Agendador permitem controlar a estratégia que o Agendador usa ao gerenciar tarefas. Este tópico mostra como usar uma política do Agendador para aumentar a prioridade de thread de uma tarefa que imprime um indicador de progresso no console do.

Para obter um exemplo que usa políticas personalizadas do Agendador junto com agentes assíncronos, consulte [como criar agentes que usam políticas específicas do Agendador](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir executa duas tarefas em paralelo. A primeira tarefa computa o número n<sup>ésimo</sup> Fibonacci. A segunda tarefa imprime um indicador de progresso no console.

A primeira tarefa usa a decomposição recursiva para calcular o número Fibonacci. Ou seja, cada tarefa cria recursivamente subtarefas para calcular o resultado geral. Uma tarefa que usa a decomposição recursiva pode usar todos os recursos disponíveis e, portanto, privar outras tarefas. Neste exemplo, a tarefa que imprime o indicador de progresso pode não receber acesso oportuno aos recursos de computação.

Para fornecer a tarefa que imprime uma mensagem de progresso acesso justo aos recursos de computação, este exemplo usa as etapas descritas em [como gerenciar uma instância do Agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md) para criar uma instância do Agendador que tem uma política personalizada. A política personalizada especifica a prioridade de thread para ser a classe de prioridade mais alta.

Este exemplo usa as classes [Concurrency:: Call](../../parallel/concrt/reference/call-class.md) e [Concurrency:: timer](../../parallel/concrt/reference/timer-class.md) para imprimir o indicador de progresso. Essas classes têm versões de seus construtores que usam uma referência a um objeto [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) que os agenda. O exemplo usa o agendador padrão para agendar a tarefa que computa o número Fibonacci e a instância do Agendador para agendar a tarefa que imprime o indicador de progresso.

Para ilustrar os benefícios de usar um Agendador que tenha uma política personalizada, este exemplo executa a tarefa geral duas vezes. O exemplo primeiro usa o agendador padrão para agendar ambas as tarefas. Em seguida, o exemplo usa o agendador padrão para agendar a primeira tarefa e um Agendador que tem uma política personalizada para agendar a segunda tarefa.

[!code-cpp[concrt-scheduler-policy#1](../../parallel/concrt/codesnippet/cpp/how-to-specify-specific-scheduler-policies_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Default scheduler:
...........................................................................done
Scheduler that has a custom policy:
...........................................................................done
```

Embora os dois conjuntos de tarefas produzam o mesmo resultado, a versão que usa uma política personalizada permite que a tarefa que imprime o indicador de progresso seja executada em uma prioridade elevada, para que ele se comporta com mais capacidade de resposta.

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `scheduler-policy.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Scheduler-Policy. cpp**

## <a name="see-also"></a>Consulte também

[Políticas de agendador](../../parallel/concrt/scheduler-policies.md)<br/>
[Como gerenciar instâncias de agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md)<br/>
[Como criar agentes que usam políticas de agendador específicas](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md)
