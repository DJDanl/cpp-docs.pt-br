---
title: 'Passo a passo: Criando um agente de fluxo de dados | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- creating dataflow agents [Concurrency Runtime]
- dataflow agents, creating [Concurrency Runtime]
ms.assetid: 9db5ce3f-c51b-4de1-b79b-9ac2a0cbd130
caps.latest.revision: "16"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5f92dc200f29f5fd20c8dd1cc27508b9c7cdf4ce
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-creating-a-dataflow-agent"></a>Instruções passo a passo: criando um agente de fluxo de dados
Este documento demonstra como criar aplicativos baseados em agente que se baseiam no fluxo de dados, em vez de fluxo de controle.  
  
 *Fluxo de controle* refere-se a ordem de execução de operações em um programa. Fluxo de controle é controlado usando estruturas de controle, como instruções condicionais, loops e assim por diante. Como alternativa, *fluxo de dados* refere-se a um modelo de programação em que os cálculos são feitos somente quando está disponível a todos os dados necessários. O modelo de programação de fluxo de dados está relacionado ao conceito de passagem, de mensagens no qual componentes independentes de um programa se comunicar uns com os outros enviando mensagens.  
  
 Agentes assíncronos oferecem suporte a modelos de programação de fluxo de dados e o fluxo de controle. Embora o modelo de fluxo de controle é apropriado em muitos casos, o modelo de fluxo de dados é apropriado em outras, por exemplo, quando um agente recebe dados e executa uma ação com base na carga de dados.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Leia os documentos a seguir antes de iniciar esta explicação passo a passo:  
  
- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)  
  
- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
  
- [Como usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)  
  
##  <a name="top"></a>Seções  
 Este passo a passo contém as seguintes seções:  
  
- [Criando um agente básica do fluxo de controle](#control-flow)  
  
- [Criando um agente de fluxo de dados básicos](#dataflow)  
  
- [Criando um agente de log de mensagens](#logging)  
  
##  <a name="control-flow"></a>Criando um agente básica do fluxo de controle  
 Considere o seguinte exemplo define o `control_flow_agent` classe. O `control_flow_agent` classe atua em três buffers de mensagem: um buffer de entrada e dois buffers de saída. O `run` método lerá o buffer de mensagem de origem em um loop e usa uma instrução condicional para direcionar o fluxo de execução do programa. O agente incrementa um contador para diferente de zero, os valores negativos e incrementa o contador de outro para valores positivos diferente de zero. Depois que o agente recebe o valor de Sentinela de zero, ele envia os valores dos contadores aos buffers de mensagem de saída. O `negatives` e `positives` métodos permitem que o aplicativo leia as contagens de valores negativos e positivos do agente.  
  
 [!code-cpp[concrt-dataflow-agent#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_1.cpp)]  
  
 Embora este exemplo faz uso básico do fluxo de controle em um agente, ele demonstra a natureza serial de programação baseado em fluxo de controle. Cada mensagem deve ser processada em sequência, mesmo que várias mensagens podem estar disponíveis no buffer de mensagem de entrada. O modelo de fluxo de dados permite que ambas as ramificações da instrução condicional para avaliar simultaneamente. O modelo de fluxo de dados também permite que você crie redes mensagens mais complexas que atuam em dados assim que possível.  
  
 [[Superior](#top)]  
  
##  <a name="dataflow"></a>Criando um agente de fluxo de dados básicos  
 Esta seção mostra como converter o `control_flow_agent` classe para usar o modelo de fluxo de dados para executar a mesma tarefa.  
  
 O agente de fluxo de dados funciona com a criação de uma rede de buffers de mensagens, cada uma delas atende à finalidade específica. Certos blocos de mensagens de usam uma função de filtro para aceitar ou rejeitar uma mensagem com base em sua carga. Uma função de filtro garante que um bloco de mensagem recebe somente determinados valores.  
  
#### <a name="to-convert-the-control-flow-agent-to-a-dataflow-agent"></a>Para converter o agente do fluxo de controle em um agente do fluxo de dados  
  
1.  Copiar o corpo do `control_flow_agent` classe para outra classe, por exemplo, `dataflow_agent`. Como alternativa, você pode renomear o `control_flow_agent` classe.  
  
2.  Remover o corpo do loop que chama `receive` do `run` método.  
  
 [!code-cpp[concrt-dataflow-agent#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_2.cpp)]  
  
3.  No `run` método após a inicialização das variáveis `negative_count` e `positive_count`, adicione um `countdown_event` objeto que controla a contagem de operações ativas.  
  
 [!code-cpp[concrt-dataflow-agent#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_3.cpp)]  
  
     O `countdown_event` é mostrada neste tópico.  
  
4.  Crie a mensagem de objetos de buffer que participarão na rede de fluxo de dados.  
  
 [!code-cpp[concrt-dataflow-agent#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_4.cpp)]  
  
5.  Conecte-se os buffers de mensagem para formar uma rede.  
  
 [!code-cpp[concrt-dataflow-agent#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_5.cpp)]  
  
6.  Aguarde até que o `event` e `countdown event` objetos a ser definido. Esses eventos sinalizam que que o agente recebeu o valor de sentinela e que todas as operações de terminar.  
  
 [!code-cpp[concrt-dataflow-agent#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-dataflow-agent_6.cpp)]  
  
 O diagrama a seguir mostra a rede de fluxo de dados completo para o `dataflow_agent` classe:  
  
 ![A rede de fluxo de dados](../../parallel/concrt/media/concrt_dataflow.png "concrt_dataflow")  
  
 A tabela a seguir descreve os membros da rede.  
  
|Membro|Descrição|  
|------------|-----------------|  
|`increment_active`|Um [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) objeto que incrementa o contador de eventos ativos e passa o valor de entrada para o restante da rede.|  
|`negatives`, `positives`|[Concurrency::Call](../../parallel/concrt/reference/call-class.md) objetos que incrementa a contagem de números e diminui o contador de eventos ativos. Os objetos usam um filtro para aceitar números negativos ou números positivos.|  
|`sentinel`|Um [concurrency::call](../../parallel/concrt/reference/call-class.md) objeto que aceita apenas o valor de sentinela do zero e diminui o contador de eventos ativos.|  
|`connector`|Um [concurrency::unbounded_buffer](reference/unbounded-buffer-class.md) objeto que conecta o buffer de mensagem de origem para a rede interna.|  
  
 Porque o `run` método for chamado em um thread separado, outros threads podem enviar mensagens para a rede antes da rede é totalmente conectada. O `_source` membro de dados é um `unbounded_buffer` objeto que armazena em buffer todas as entradas que é enviada do aplicativo para o agente. Para certificar-se de que a rede processa mensagens de entrada de todos os, o agente primeiro vincula os nós internos da rede e, em seguida, vincula o início da rede, `connector`, para o `_source` membro de dados. Isso garante que as mensagens não são processadas como a rede está sendo formada.  
  
 Como a rede neste exemplo é baseada no fluxo de dados, em vez de no fluxo de controle, a rede deve se comunicar com o agente que terminou de processar cada valor de entrada e que o nó de sentinela recebeu seu valor. Este exemplo usa um `countdown_event` objeto para indicar que todos os valores de entrada foram processados e um [concurrency::event](../../parallel/concrt/reference/event-class.md) objeto para indicar que o nó de sentinela recebeu seu valor. O `countdown_event` classe usa um `event` objeto para sinalizar quando um valor de contador chega a zero. O início da rede de fluxo de dados incrementa o contador de cada vez que ele recebe um valor. Cada nó terminal de diminui a rede contador Após processar o valor de entrada. Depois que o agente de forma a rede de fluxo de dados, ele aguarda o nó de sentinela definir o `event` objeto e para o `countdown_event` objeto para sinalizar que seu contador chegou a zero.  
  
 A exemplo a seguir mostra o `control_flow_agent`, `dataflow_agent`, e `countdown_event` classes. O `wmain` função cria uma `control_flow_agent` e um `dataflow_agent` objeto e usa o `send_values` função para enviar uma série de valores aleatórios para os agentes.  
  
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
  
 [[Superior](#top)]  
  
##  <a name="logging"></a>Criando um agente de log de mensagens  
 A exemplo a seguir mostra o `log_agent` classe, que é semelhante a `dataflow_agent` classe. O `log_agent` classe implementa um agente de log assíncrono que grava log de mensagens para um arquivo e o console. O `log_agent` classe permite que o aplicativo categorizar as mensagens como informação, aviso ou erro. Ele também permite que o aplicativo especificar se cada categoria de log é gravada em um arquivo, o console ou ambos. Este exemplo grava todas as mensagens de log para um arquivo e somente mensagens de erro no console.  
  
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
  
 [[Superior](#top)]  
  
## <a name="see-also"></a>Consulte também  
 [Instruções passo a passo do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)

