---
title: Como cria agentes que usam políticas de agendador específicas
ms.date: 11/04/2016
helpviewer_keywords:
- scheduler policies, agents [Concurrency Runtime]
- creating agents that use specific policies [Concurrency Runtime]
ms.assetid: 46a3e265-0777-4ec3-a142-967bafc49d67
ms.openlocfilehash: ece6b113e3fe10c2c3179517f73137df281acf87
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141734"
---
# <a name="how-to-create-agents-that-use-specific-scheduler-policies"></a>Como cria agentes que usam políticas de agendador específicas

Um agente é um componente de aplicativo que funciona de forma assíncrona com outros componentes para resolver tarefas de computação maiores. Um agente normalmente tem um ciclo de vida definido e mantém o estado.

Cada agente pode ter requisitos de aplicativo exclusivos. Por exemplo, um agente que habilita a interação do usuário (recuperando entrada ou exibindo a saída) pode exigir acesso de prioridade mais alto aos recursos de computação. As políticas do Agendador permitem controlar a estratégia que o Agendador usa ao gerenciar tarefas. Este tópico demonstra como criar agentes que usam políticas específicas do Agendador.

Para obter um exemplo básico que usa políticas personalizadas do Agendador junto com os blocos de mensagens assíncronas, consulte [como especificar políticas específicas do Agendador](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md).

Este tópico usa a funcionalidade da biblioteca de agentes assíncronos, como agentes, blocos de mensagens e funções de passagem de mensagens, para executar o trabalho. Para obter mais informações sobre a biblioteca de agentes assíncronos, consulte [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir define duas classes que derivam de [Concurrency:: Agent](../../parallel/concrt/reference/agent-class.md): `permutor` e `printer`. A classe `permutor` computa todas as permutas de uma determinada cadeia de caracteres de entrada. A classe `printer` imprime as mensagens de progresso no console. A classe `permutor` executa uma operação computacionalmente intensiva, que pode usar todos os recursos de computação disponíveis. Para ser útil, a classe `printer` deve imprimir cada mensagem de progresso em tempo hábil.

Para fornecer à classe `printer` acesso justo aos recursos de computação, este exemplo usa as etapas descritas em [como gerenciar uma instância do Agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md) para criar uma instância do Agendador que tenha uma política personalizada. A política personalizada especifica a prioridade de thread para ser a classe de prioridade mais alta.

Para ilustrar os benefícios de usar um Agendador que tenha uma política personalizada, este exemplo executa a tarefa geral duas vezes. O exemplo primeiro usa o agendador padrão para agendar ambas as tarefas. Em seguida, o exemplo usa o agendador padrão para agendar o objeto de `permutor` e um Agendador que tem uma política personalizada para agendar o objeto de `printer`.

[!code-cpp[concrt-permute-strings#1](../../parallel/concrt/codesnippet/cpp/how-to-create-agents-that-use-specific-scheduler-policies_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
With default scheduler:
Computing all permutations of 'Grapefruit'...
100% complete...

With higher context priority:
Computing all permutations of 'Grapefruit'...
100% complete...
```

Embora os dois conjuntos de tarefas produzam o mesmo resultado, a versão que usa uma política personalizada permite que o objeto `printer` seja executado em uma prioridade elevada para que ele se comporta com mais capacidade de resposta.

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `permute-strings.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc permute-Strings. cpp**

## <a name="see-also"></a>Consulte também

[Políticas de agendador](../../parallel/concrt/scheduler-policies.md)<br/>
[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)
