---
title: 'Instruções passo a passo: criando um agente de fluxo de dados'
ms.date: 04/25/2019
helpviewer_keywords:
- creating dataflow agents [Concurrency Runtime]
- dataflow agents, creating [Concurrency Runtime]
ms.assetid: 9db5ce3f-c51b-4de1-b79b-9ac2a0cbd130
ms.openlocfilehash: fa19d965a35909dfefc5f586c772bc9b4565e814
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142964"
---
# <a name="walkthrough-creating-a-dataflow-agent"></a>Instruções passo a passo: criando um agente de fluxo de dados

Este documento demonstra como criar aplicativos baseados em agente baseados em Dataflow, em vez de fluxo de controle.

O *fluxo de controle* refere-se à ordem de execução das operações em um programa. O fluxo de controle é regulamentado usando estruturas de controle, como instruções condicionais, loops e assim por diante. Como alternativa, o *fluxo* de dados refere-se a um modelo de programação no qual os cálculos são feitos somente quando todos os dados necessários estão disponíveis. O modelo de programação de fluxo de arquivos está relacionado ao conceito de transmissão de mensagens, no qual os componentes independentes de um programa se comunicam entre si enviando mensagens.

Os agentes assíncronos oferecem suporte aos modelos de programação de fluxo de controle e fluxo de fluxos. Apesar de o modelo de fluxo de controle ser apropriado em muitos casos, o modelo de fluxo de dados é apropriado em outros, por exemplo, quando um agente recebe dados e executa uma ação com base na carga desses dados.

## <a name="prerequisites"></a>{1&gt;{2&gt;Pré-requisitos&lt;2}&lt;1}

Leia os seguintes documentos antes de iniciar este passo a passos:

- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Como usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)

## <a name="top"></a>As

Este passo a passo contém as seguintes seções:

- [Criando um agente de fluxo de controle básico](#control-flow)

- [Criando um agente de fluxo de os básico](#dataflow)

- [Criando um agente de log de mensagens](#logging)

## <a name="control-flow"></a>Criando um agente de fluxo de controle básico

Considere o exemplo a seguir que define a classe `control_flow_agent`. A classe `control_flow_agent` atua em três buffers de mensagens: um buffer de entrada e dois buffers de saída. O método `run` lê a partir do buffer de mensagem de origem em um loop e usa uma instrução condicional para direcionar o fluxo de execução do programa. O agente incrementa um contador para valores não zero, negativos e incrementa outro contador para valores não zero e positivos. Depois que o agente recebe o valor de sentinela de zero, ele envia os valores dos contadores para os buffers de mensagens de saída. Os métodos `negatives` e `positives` permitem que o aplicativo Leia as contagens de valores negativos e positivos do agente.

[!code-cpp[concrt-dataflow-agent#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_1.cpp)]

Embora este exemplo faça uso básico do fluxo de controle em um agente, ele demonstra a natureza serial da programação baseada em fluxo de controle. Cada mensagem deve ser processada sequencialmente, mesmo que várias mensagens possam estar disponíveis no buffer de mensagens de entrada. O modelo de Dataflow permite que ambas as ramificações da instrução condicional sejam avaliadas simultaneamente. O modelo de fluxo de dados também permite que você crie redes de mensagens mais complexas que atuem nos dados conforme estiverem disponíveis.

[[Superior](#top)]

## <a name="dataflow"></a>Criando um agente de fluxo de os básico

Esta seção mostra como converter a classe `control_flow_agent` para usar o modelo de fluxo de os para executar a mesma tarefa.

O agente de fluxo de trabalhos funciona criando uma rede de buffers de mensagens, cada um deles atendendo a uma finalidade específica. Determinados blocos de mensagens usam uma função de filtro para aceitar ou rejeitar uma mensagem com base em sua carga. Uma função de filtro garante que um bloco de mensagem receba apenas determinados valores.

#### <a name="to-convert-the-control-flow-agent-to-a-dataflow-agent"></a>Para converter o agente do fluxo de controle em um agente do fluxo de dados

1. Copie o corpo da classe `control_flow_agent` para outra classe, por exemplo, `dataflow_agent`. Como alternativa, você pode renomear a classe `control_flow_agent`.

1. Remova o corpo do loop que chama `receive` do método `run`.

[!code-cpp[concrt-dataflow-agent#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_2.cpp)]

1. No método `run`, após a inicialização das variáveis `negative_count` e `positive_count`, adicione um objeto `countdown_event` que acompanha a contagem de operações ativas.

[!code-cpp[concrt-dataflow-agent#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_3.cpp)]

   A classe `countdown_event` é mostrada mais adiante neste tópico.

1. Crie os objetos de buffer de mensagem que participarão da rede de fluxo de mensagens.

[!code-cpp[concrt-dataflow-agent#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_4.cpp)]

1. Conecte os buffers de mensagens para formar uma rede.

[!code-cpp[concrt-dataflow-agent#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_5.cpp)]

1. Aguarde até que os objetos `event` e `countdown event` sejam definidos. Esses eventos sinalizam que o agente recebeu o valor de sentinela e que todas as operações foram concluídas.

[!code-cpp[concrt-dataflow-agent#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_6.cpp)]

O diagrama a seguir mostra a rede de Dataflow completa para a classe `dataflow_agent`:

![A rede de Dataflow](../../parallel/concrt/media/concrt_dataflow.png "A rede de Dataflow")

A tabela a seguir descreve os membros da rede.

|{1&gt;Membro&lt;1}|Descrição|
|------------|-----------------|
|`increment_active`|Um objeto [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) que incrementa o contador de eventos ativo e passa o valor de entrada para o restante da rede.|
|`negatives`, `positives`|[Concurrency:: chama](../../parallel/concrt/reference/call-class.md) objetos que incrementam a contagem de números e decrementa o contador de eventos ativo. Os objetos usam um filtro para aceitar números negativos ou números positivos.|
|`sentinel`|Um objeto [Concurrency:: Call](../../parallel/concrt/reference/call-class.md) que aceita apenas o valor de sentinela de zero e decrementa o contador de eventos ativo.|
|`connector`|Um objeto [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) que conecta o buffer de mensagem de origem à rede interna.|

Como o método `run` é chamado em um thread separado, outros threads podem enviar mensagens para a rede antes que a rede esteja totalmente conectada. O membro de dados `_source` é um objeto `unbounded_buffer` que armazena em buffer todas as entradas enviadas do aplicativo para o agente. Para garantir que a rede processe todas as mensagens de entrada, o agente primeiro vincula os nós internos da rede e, em seguida, vincula o início dessa rede, `connector`, ao membro de dados do `_source`. Isso garante que as mensagens não sejam processadas à medida que a rede está sendo formada.

Como a rede neste exemplo é baseada em fluxo de dados, e não no fluxo de controle, a rede deve se comunicar com o agente que concluiu o processamento de cada valor de entrada e que o nó sentinel recebeu seu valor. Este exemplo usa um objeto `countdown_event` para sinalizar que todos os valores de entrada foram processados e um objeto [Concurrency:: Event](../../parallel/concrt/reference/event-class.md) para indicar que o nó sentinel recebeu seu valor. A classe `countdown_event` usa um objeto `event` para sinalizar quando um valor de contador chegar a zero. O cabeçalho da rede de Dataflow incrementa o contador toda vez que recebe um valor. Cada nó de terminal da rede diminui o contador depois de processar o valor de entrada. Depois que o agente forma a rede de Dataflow, ele aguarda que o nó Sentinel defina o objeto `event` e para o objeto `countdown_event` para sinalizar que seu contador atingiu o zero.

O exemplo a seguir mostra as classes `control_flow_agent`, `dataflow_agent`e `countdown_event`. A função `wmain` cria uma `control_flow_agent` e um objeto `dataflow_agent` e usa a função `send_values` para enviar uma série de valores aleatórios para os agentes.

[!code-cpp[concrt-dataflow-agent#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_7.cpp)]

Este exemplo produz a seguinte saída de exemplo:

```Output
Control-flow agent:
There are 500523 negative numbers.
There are 499477 positive numbers.
Dataflow agent:
There are 500523 negative numbers.
There are 499477 positive numbers.
```

### <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `dataflow-agent.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

**CL. exe/EHsc Dataflow-Agent. cpp**

[[Superior](#top)]

## <a name="logging"></a>Criando um agente de log de mensagens

O exemplo a seguir mostra a classe `log_agent`, que se assemelha à classe `dataflow_agent`. A classe `log_agent` implementa um agente de log assíncrono que grava mensagens de log em um arquivo e no console do. A classe `log_agent` permite ao aplicativo categorizar mensagens como informativas, aviso ou erro. Ele também permite que o aplicativo especifique se cada categoria de log é gravada em um arquivo, no console ou em ambos. Este exemplo grava todas as mensagens de log em um arquivo e apenas mensagens de erro no console.

[!code-cpp[concrt-log-filter#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_8.cpp)]

Este exemplo grava a saída a seguir no console.

```Output
error: This is a sample error message.
```

Este exemplo também produz o arquivo log. txt, que contém o texto a seguir.

```Output
info: ===Logging started.===
warning: This is a sample warning message.
error: This is a sample error message.
info: ===Logging finished.===
```

### <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `log-filter.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

**CL. exe/EHsc log-Filter. cpp**

[[Superior](#top)]

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do runtime de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)
