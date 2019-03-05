---
title: 'Passo a passo: Criando um agente de fluxo de dados'
ms.date: 11/19/2018
helpviewer_keywords:
- creating dataflow agents [Concurrency Runtime]
- dataflow agents, creating [Concurrency Runtime]
ms.assetid: 9db5ce3f-c51b-4de1-b79b-9ac2a0cbd130
ms.openlocfilehash: bba72404b1c39ef1835b0c96883154b385181b6a
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57266751"
---
# <a name="walkthrough-creating-a-dataflow-agent"></a>Passo a passo: Criando um agente de fluxo de dados

Este documento demonstra como criar aplicativos baseados em agente que se baseiam no fluxo de dados, em vez de fluxo de controle.

*Fluxo de controle* refere-se a ordem de execução de operações em um programa. Fluxo de controle é controlado por meio de estruturas de controle, como instruções condicionais, loops e assim por diante. Como alternativa, *fluxo de dados* refere-se a um modelo de programação em que computações são feitas somente quando todos os dados necessários está disponível. O modelo de programação de fluxo de dados está relacionado ao conceito de passagem, de mensagens em que componentes independentes de um programa se comunicam uns com os outros enviando mensagens.

Agentes assíncronos dão suporte a fluxo de controle e modelos de programação de fluxo de dados. Embora o modelo de fluxo de controle é apropriado em muitos casos, o modelo de fluxo de dados é apropriado em outros, por exemplo, quando um agente recebe os dados e executa uma ação com base na carga desses dados.

## <a name="prerequisites"></a>Pré-requisitos

Leia os documentos a seguir antes de começar este passo a passo:

- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Como: Usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)

##  <a name="top"></a> Seções

Este passo a passo contém as seguintes seções:

- [Criando um agente de fluxo de controle básico](#control-flow)

- [Criando um agente de fluxo de dados básico](#dataflow)

- [Criando um agente de log de mensagem](#logging)

##  <a name="control-flow"></a> Criando um agente de fluxo de controle básico

Considere o seguinte exemplo define o `control_flow_agent` classe. O `control_flow_agent` classe age em três buffers de mensagem: um buffer de entrada e dois buffers de saída. O `run` método lerá o buffer de mensagem de origem em um loop e usa uma instrução condicional para direcionar o fluxo de execução do programa. O agente incrementa um contador para diferente de zero, os valores negativos e incrementa o contador de outra para valores positivos diferente de zero. Depois que o agente recebe o valor de Sentinela de zero, ele envia os valores dos contadores para os buffers de mensagem de saída. O `negatives` e `positives` métodos permitem que o aplicativo leia as contagens de valores positivos e negativos do agente.

[!code-cpp[concrt-dataflow-agent#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_1.cpp)]

Embora este exemplo faz uso básico do fluxo de controle em um agente, ele demonstra a natureza serial de programação baseado em fluxo de controle. Cada mensagem deve ser processada em sequência, mesmo que várias mensagens podem estar disponíveis no buffer de mensagem de entrada. O modelo de fluxo de dados permite que ambas as ramificações da instrução condicional ser avaliada simultaneamente. O modelo de fluxo de dados também permite que você crie redes mais complexas de mensagens que atuam em dados assim que estiverem disponíveis.

[[Top](#top)]

##  <a name="dataflow"></a> Criando um agente de fluxo de dados básico

Esta seção mostra como converter o `control_flow_agent` classe usar o modelo de fluxo de dados para executar a mesma tarefa.

O agente de fluxo de dados funciona com a criação de uma rede de buffers de mensagens, cada um deles serve a uma finalidade específica. Determinados blocos de mensagens usam uma função de filtro para aceitar ou rejeitar uma mensagem com base em sua carga. Uma função de filtro garante que um bloco de mensagem receba apenas determinados valores.

#### <a name="to-convert-the-control-flow-agent-to-a-dataflow-agent"></a>Para converter o agente do fluxo de controle em um agente do fluxo de dados

1. Copiar o corpo do `control_flow_agent` classe para outra classe, por exemplo, `dataflow_agent`. Como alternativa, você pode renomear o `control_flow_agent` classe.

1. Remova o corpo do loop que chama `receive` do `run` método.

[!code-cpp[concrt-dataflow-agent#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_2.cpp)]

1. No `run` método, após a inicialização das variáveis `negative_count` e `positive_count`, adicione um `countdown_event` objeto que controla a contagem de operações do Active Directory.

[!code-cpp[concrt-dataflow-agent#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_3.cpp)]

   O `countdown_event` classe é mostrado mais adiante neste tópico.

1. Crie a mensagem de objetos de buffer que participarão na rede de fluxo de dados.

[!code-cpp[concrt-dataflow-agent#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_4.cpp)]

1. Conecte-se os buffers de mensagem para formar uma rede.

[!code-cpp[concrt-dataflow-agent#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_5.cpp)]

1. Aguarde até que o `event` e `countdown event` objetos a ser definido. Esses eventos sinalizam que o agente recebeu o valor de sentinela e que concluiu todas as operações.

[!code-cpp[concrt-dataflow-agent#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_6.cpp)]

O diagrama a seguir mostra a rede de fluxo de dados completo para o `dataflow_agent` classe:

![A rede de fluxo de dados](../../parallel/concrt/media/concrt_dataflow.png "a rede de fluxo de dados")

A tabela a seguir descreve os membros da rede.

|Membro|Descrição|
|------------|-----------------|
|`increment_active`|Um [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) objeto que incrementa o contador de eventos ativos e passa o valor de entrada para o restante da rede.|
|`negatives`, `positives`|[Concurrency::Call](../../parallel/concrt/reference/call-class.md) objetos que incrementam a contagem de números e diminui o contador de eventos ativos. Os objetos usam um filtro para aceitar os números negativos ou números positivos.|
|`sentinel`|Um [concurrency::call](../../parallel/concrt/reference/call-class.md) objeto que aceita apenas o valor de sentinela do zero e diminui o contador de eventos ativos.|
|`connector`|Um [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) objeto que se conecta o buffer de mensagem de origem à rede interna.|

Porque o `run` método é chamado em um thread separado, outros threads podem enviar mensagens para a rede antes da rede é totalmente conectada. O `_source` membro de dados é um `unbounded_buffer` objeto que armazena em buffer todas as entradas que é enviada do aplicativo para o agente. Para certificar-se de que a rede processa mensagens de entrada todos, o agente pela primeira vez vincula os nós internos da rede e, em seguida, vincula o início dessa rede, `connector`, para o `_source` membro de dados. Isso garante que as mensagens não serão processadas como a rede está sendo formada.

Porque a rede neste exemplo é baseada em fluxo de dados, em vez de no fluxo de controle, a rede deve se comunicar com o agente que terminou de processar cada valor de entrada e que o nó de sentinela tenha recebido o seu valor. Este exemplo usa uma `countdown_event` objeto para sinalizar que todos os valores de entrada foram processados e um [concurrency::event](../../parallel/concrt/reference/event-class.md) objeto para indicar que o nó de sentinela tenha recebido o seu valor. O `countdown_event` classe usa um `event` objeto para sinalizar quando um valor de contador chega a zero. O cabeçalho da rede de fluxo de dados incrementa o contador de cada vez que ele recebe um valor. Cada nó terminal de diminui a rede o contador Após processar o valor de entrada. Depois que o agente forma a rede de fluxo de dados, ele aguarda o nó de sentinela definir a `event` objeto e para o `countdown_event` objeto para sinalizar que o seu contador chegou a zero.

A exemplo a seguir mostra a `control_flow_agent`, `dataflow_agent`, e `countdown_event` classes. O `wmain` função cria um `control_flow_agent` e uma `dataflow_agent` objeto e usa o `send_values` função para enviar uma série de valores aleatórios para os agentes.

[!code-cpp[concrt-dataflow-agent#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_7.cpp)]

Este exemplo produz a saída de exemplo a seguir:

```Output
Control-flow agent:
There are 500523 negative numbers.
There are 499477 positive numbers.
Dataflow agent:
There are 500523 negative numbers.
There are 499477 positive numbers.
```

### <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `dataflow-agent.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**fluxo de dados de /EHsc cl.exe-agent.cpp**

[[Top](#top)]

##  <a name="logging"></a> Criando um agente de log de mensagem

A exemplo a seguir mostra a `log_agent` classe, que é semelhante a `dataflow_agent` classe. O `log_agent` classe implementa um agente de log assíncrono que grava no log mensagens para um arquivo e para o console. O `log_agent` classe permite que o aplicativo categorizar as mensagens como informativo, aviso ou erro. Ele também permite que o aplicativo especificar se cada categoria de log é gravada em um arquivo, o console ou ambos. Este exemplo grava todas as mensagens de log para um arquivo e somente mensagens de erro no console.

[!code-cpp[concrt-log-filter#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_8.cpp)]

Este exemplo grava a saída a seguir no console.

```Output
error: This is a sample error message.
```

Este exemplo também produz o arquivo de log. txt, que contém o texto a seguir.

```Output
info: ===Logging started.===
warning: This is a sample warning message.
error: This is a sample error message.
info: ===Logging finished.===
```

### <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `log-filter.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc log-filter.cpp**

[[Top](#top)]

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)
