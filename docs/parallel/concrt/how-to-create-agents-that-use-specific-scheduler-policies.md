---
title: 'Como: Criar agentes que usam políticas de Agendador específicas'
ms.date: 11/04/2016
helpviewer_keywords:
- scheduler policies, agents [Concurrency Runtime]
- creating agents that use specific policies [Concurrency Runtime]
ms.assetid: 46a3e265-0777-4ec3-a142-967bafc49d67
ms.openlocfilehash: 5aac86801015549b5552b51c06a30f8398346a06
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57257365"
---
# <a name="how-to-create-agents-that-use-specific-scheduler-policies"></a>Como: Criar agentes que usam políticas de Agendador específicas

Um agente é um componente de aplicativo que funciona de forma assíncrona com outros componentes para resolver tarefas de computação maiores. Normalmente, um agente tem um ciclo de vida definido e mantém o estado.

Cada agente pode ter requisitos de aplicativo exclusivo. Por exemplo, um agente que permite a interação do usuário (Recuperando entrada ou exibindo saída) pode exigir acesso de prioridade mais alta para recursos de computação. Políticas de Agendador permitem controlar a estratégia que o Agendador usa quando ele gerencia as tarefas. Este tópico demonstra como criar agentes que usam políticas de Agendador específicas.

Para obter um exemplo básico que usa políticas de Agendador personalizado junto com blocos de mensagens assíncronos, consulte [como: Especificar políticas de Agendador específicas](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md).

Este tópico usa a funcionalidade da biblioteca de agentes assíncronos, como agentes, blocos de mensagens e funções de transmissão de mensagens, para executar o trabalho. Para obter mais informações sobre a biblioteca de agentes assíncronos, consulte [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md).

## <a name="example"></a>Exemplo

O exemplo a seguir define duas classes que derivam de [concurrency::agent](../../parallel/concrt/reference/agent-class.md): `permutor` e `printer`. O `permutor` classe calcula todas as permutações de uma determinada cadeia de caracteres de entrada. O `printer` classe imprime mensagens de andamento para o console. O `permutor` classe executa uma operação de intensa, o que pode usar todos os recursos de computação disponíveis. Para ser útil, a `printer` classe deve ser impressos cada mensagem de progresso de maneira oportuna.

Para fornecer a `printer` acesso razoável de classe para recursos de computação, este exemplo usa as etapas descritas em [como: Gerenciar uma instância do Agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md) para criar uma instância de agendador que tenha uma política personalizada. A política personalizada Especifica a prioridade do thread para ser a classe de prioridade mais alta.

Para ilustrar os benefícios de usar um agendador que tem uma política personalizada, este exemplo executa a tarefa geral duas vezes. Primeiro, o exemplo usa o agendador padrão para agendar as duas tarefas. O exemplo usa o agendador padrão para agendar a `permutor` objeto e um agendador que tem uma política personalizada para agendar o `printer` objeto.

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

Embora os dois conjuntos de tarefas produzem o mesmo resultado, a versão que usa uma política personalizada permite que o `printer` objeto a ser executado em uma prioridade com privilégios elevados, de modo que ele se comporta de maneira mais responsiva.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `permute-strings.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc permute-strings.cpp**

## <a name="see-also"></a>Consulte também

[Políticas de agendador](../../parallel/concrt/scheduler-policies.md)<br/>
[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)
