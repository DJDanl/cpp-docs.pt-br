---
title: Práticas recomendadas na biblioteca de agentes assíncronos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- best practices, Asynchronous Agents Library
- Asynchronous Agents Library, best practices
- Asynchronous Agents Library, practices to avoid
- practices to avoid, Asynchronous Agents Library
ms.assetid: 85f52354-41eb-4b0d-98c5-f7344ee8a8cf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5e70b4004b24b04470e1fff280869887bbba74cb
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46412737"
---
# <a name="best-practices-in-the-asynchronous-agents-library"></a>Práticas recomendadas na Biblioteca de Agentes Assíncrona

Este documento descreve como fazer uso eficiente do que a biblioteca de agentes assíncronos. A biblioteca de agentes promove um modelo de programação baseado em ator e passando para o fluxo de dados de alta granularidade e pipelining de tarefas de mensagem no processo.

Para obter mais informações sobre a biblioteca de agentes, consulte [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md).

##  <a name="top"></a> Seções

Este documento contém as seguintes seções:

- [Usar agentes para isolar estado](#isolation)

- [Usar um mecanismo de limitação para limitar o número de mensagens em um Pipeline de dados](#throttling)

- [Realizar trabalho granulado em um Pipeline de dados](#fine-grained)

- [Não passar cargas de mensagem grandes por valor](#large-payloads)

- [Usar shared_ptr em uma Data rede quando a propriedade for indefinida](#ownership)

##  <a name="isolation"></a> Usar agentes para isolar estado

A biblioteca de agentes fornece alternativas para estado compartilhado, permitindo que você se conectar componentes isolados por meio de um mecanismo de transmissão de mensagens assíncrono. Agentes assíncronos são mais efetivos quando eles isolar seu estado interno de outros componentes. Ao isolar estado, vários componentes não normalmente funcionam com os dados compartilhados. Isolamento de estado pode habilitar seu aplicativo dimensione porque ele reduz a contenção de memória compartilhada. Estado de isolamento também reduz a chance de condições de corrida e de deadlock porque não tem componentes sincronizar o acesso aos dados compartilhados.

Você normalmente isolar estado em um agente, mantendo os membros de dados do `private` ou `protected` seções da classe agente e por meio de buffers de mensagens para comunicar alterações de estado. A exemplo a seguir mostra a `basic_agent` classe, que deriva [concurrency::agent](../../parallel/concrt/reference/agent-class.md). O `basic_agent` classe usa dois buffers de mensagens para se comunicar com componentes externos. Um buffer de mensagem contém mensagens de entrada; o outro buffer de mensagem contém mensagens de saída.

[!code-cpp[concrt-simple-agent#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-asynchronous-agents-library_1.cpp)]

Para obter exemplos completos sobre como definir e usar agentes, consulte [instruções passo a passo: Criando um aplicativo baseado em agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md) e [passo a passo: Criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md).

[[Superior](#top)]

##  <a name="throttling"></a> Usar um mecanismo de limitação para limitar o número de mensagens em um Pipeline de dados

Muitos tipos de buffer de mensagem, como [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md), pode conter um número ilimitado de mensagens. Quando um produtor de mensagem envia mensagens para um pipeline de dados mais rápido do que o consumidor pode processar essas mensagens, o aplicativo pode entrar em um estado de memória insuficiente ou falta de memória. Você pode usar um mecanismo de limitação, por exemplo, um semáforo, para limitar o número de mensagens que estão ativas simultâneas em um pipeline de dados.

O exemplo básico a seguir demonstra como usar um semáforo para limitar o número de mensagens em um pipeline de dados. Os dados do pipeline usa o [concurrency::wait](reference/concurrency-namespace-functions.md#wait) função para simular uma operação que demora pelo menos 100 milissegundos. Como o remetente produz mensagens mais rápido do que o consumidor pode processar essas mensagens, este exemplo define o `semaphore` classe para permitir que o aplicativo limitar o número de mensagens ativas.

[!code-cpp[concrt-message-throttling#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-asynchronous-agents-library_2.cpp)]

O `semaphore` objeto limita o pipeline para processar no máximo duas mensagens ao mesmo tempo.

O produtor neste exemplo envia mensagens relativamente poucos para o consumidor. Portanto, este exemplo não demonstra uma possível condição de pouca memória ou a falta de memória. No entanto, esse mecanismo é útil quando um pipeline de dados contém um número relativamente alto de mensagens.

Para obter mais informações sobre como criar a classe semaphore que é usada neste exemplo, consulte [como: usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md).

[[Superior](#top)]

##  <a name="fine-grained"></a> Realizar trabalho granulado em um Pipeline de dados

A biblioteca de agentes é mais útil quando o trabalho executado por um pipeline de dados é bastante alta granularidade. Por exemplo, um componente de aplicativo pode ler dados de um arquivo ou uma conexão de rede e ocasionalmente enviar esses dados para outro componente. O protocolo que a biblioteca de agentes usa para se propagar mensagens faz com que o mecanismo de transmissão de mensagens para ter mais sobrecarga do que as construções de tarefas paralelas que são fornecidos pelo [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) (PPL). Portanto, certifique-se de que o trabalho executado por um pipeline de dados é longo o suficiente para essa sobrecarga de deslocamento.

Embora um pipeline de dados é mais eficaz quando suas tarefas são alta granularidade, cada estágio do pipeline de dados pode usar construções PPL, como grupos de tarefas e algoritmos paralelos para realizar mais trabalho Granulado. Para obter um exemplo de uma rede de alta granularidade de dados que usa o paralelismo refinado em cada estágio de processamento, consulte [instruções passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).

[[Superior](#top)]

##  <a name="large-payloads"></a> Não passar cargas de mensagem grandes por valor

Em alguns casos, o tempo de execução cria uma cópia de cada mensagem que ele passa de um buffer de mensagem para outro buffer de mensagem. Por exemplo, o [Concurrency:: overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) classe oferece uma cópia de todas as mensagens que recebe a cada um dos seus destinos. O tempo de execução também cria uma cópia dos dados da mensagem quando você usa funções de transmissão de mensagens, como [Concurrency:: Send](reference/concurrency-namespace-functions.md#send) e [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) para gravar mensagens e ler mensagens de uma mensagem buffer. Embora esse mecanismo ajuda a eliminar o risco de gravar dados compartilhados ao mesmo tempo, isso pode levar a desempenho ruim de memória quando a carga da mensagem é relativamente grande.

Você pode usar ponteiros ou referências para melhorar o desempenho de memória quando você passa mensagens que têm uma grande carga. O exemplo a seguir compara as mensagens grandes passando pelo valor a ser passando ponteiros para o mesmo tipo de mensagem. O exemplo define dois tipos de agente `producer` e `consumer`, que atuam em `message_data` objetos. O exemplo compara a hora em que é necessária para o produtor enviar várias `message_data` objetos ao consumidor para a hora em que é necessário para o agente de produtor para enviar vários ponteiros ao `message_data` objetos para o consumidor.

[!code-cpp[concrt-message-payloads#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-asynchronous-agents-library_3.cpp)]

Este exemplo produz a saída de exemplo a seguir:

```Output
Using message_data...
took 437ms.
Using message_data*...
took 47ms.
```

A versão que usa ponteiros é melhor porque ele elimina a necessidade de tempo de execução criar uma cópia completa de cada `message_data` objeto que ele passa do produtor para o consumidor.

[[Superior](#top)]

##  <a name="ownership"></a> Usar shared_ptr em uma Data rede quando a propriedade for indefinida

Quando você envia mensagens pelo ponteiro por meio de um pipeline de transmissão de mensagens ou rede, você normalmente alocar a memória para cada mensagem na frente da rede e libera essa memória no final da rede. Embora esse mecanismo frequentemente funciona bem, há casos em que é difícil ou não é possível usá-lo. Por exemplo, considere o caso em que a rede de dados contém vários nós de final. Nesse caso, não há nenhum local não criptografado para liberar a memória para as mensagens.

Para resolver esse problema, você pode usar um mecanismo de, por exemplo, [std:: shared_ptr](../../standard-library/shared-ptr-class.md), que permite que um ponteiro pertencer a vários componentes. Quando o último `shared_ptr` objeto que possui um recurso é destruído, o recurso também é liberado.

O exemplo a seguir demonstra como usar `shared_ptr` para compartilhar os valores de ponteiro entre vários buffers de mensagem. O exemplo conecta-se um [Concurrency:: overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) objeto para três [concurrency::call](../../parallel/concrt/reference/call-class.md) objetos. O `overwrite_buffer` classe oferece mensagens para cada um dos seus destinos. Como há vários proprietários dos dados no final da rede de dados, este exemplo usa `shared_ptr` para habilitar cada `call` objeto para compartilhar a propriedade das mensagens.

[!code-cpp[concrt-message-sharing#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-asynchronous-agents-library_4.cpp)]

Este exemplo produz a saída de exemplo a seguir:

```Output
Creating resource 42...
receiver1: received resource 42
Creating resource 64...
receiver2: received resource 42
receiver1: received resource 64
Destroying resource 42...
receiver2: received resource 64
Destroying resource 64...
```

## <a name="see-also"></a>Consulte também

[Práticas recomendadas do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-best-practices.md)<br/>
[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Instruções passo a passo: criando um aplicativo com base no agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)<br/>
[Instruções passo a passo: criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)<br/>
[Instruções passo a passo: criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)<br/>
[Práticas recomendadas na biblioteca de padrões paralelos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md)<br/>
[Práticas recomendadas gerais no tempo de execução de simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)

