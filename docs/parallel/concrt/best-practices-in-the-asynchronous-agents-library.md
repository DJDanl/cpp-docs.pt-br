---
title: Práticas recomendadas na Biblioteca de Agentes Assíncrona
ms.date: 11/04/2016
helpviewer_keywords:
- best practices, Asynchronous Agents Library
- Asynchronous Agents Library, best practices
- Asynchronous Agents Library, practices to avoid
- practices to avoid, Asynchronous Agents Library
ms.assetid: 85f52354-41eb-4b0d-98c5-f7344ee8a8cf
ms.openlocfilehash: 99780de11d85831a6901f370d2491f15ef88c0b1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231735"
---
# <a name="best-practices-in-the-asynchronous-agents-library"></a>Práticas recomendadas na Biblioteca de Agentes Assíncrona

Este documento descreve como fazer uso efetivo da biblioteca de agentes assíncronos. A biblioteca de agentes promove um modelo de programação baseado em ator e uma mensagem em processo que passa por tarefas de fluxo de mensagens e pipelines de alta granularidade.

Para obter mais informações sobre a biblioteca de agentes, consulte [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md).

## <a name="sections"></a><a name="top"></a>As

Este documento contém as seguintes seções:

- [Usar Agentes para Isolar Estado](#isolation)

- [Usar um Mecanismo de Limitação para Restringir o Número de Mensagens em Pipeline de Dados](#throttling)

- [Não Realizar Trabalho Granulado em um Pipeline de Dados](#fine-grained)

- [Não Passar Cargas de Mensagem Grandes por Valor](#large-payloads)

- [Usar shared_ptr em uma Rede de Dados Quando a Propriedade for Indefinida](#ownership)

## <a name="use-agents-to-isolate-state"></a><a name="isolation"></a>Usar agentes para isolar o estado

A biblioteca de agentes fornece alternativas para o estado compartilhado, permitindo que você conecte componentes isolados por meio de um mecanismo assíncrono de transmissão de mensagens. Os agentes assíncronos são mais eficazes quando isolam seu estado interno de outros componentes. Ao isolar o estado, vários componentes normalmente não agem em dados compartilhados. O isolamento de estado pode permitir que seu aplicativo seja dimensionado, pois reduz a contenção na memória compartilhada. O isolamento de estado também reduz a chance de deadlock e condições de corrida porque os componentes não precisam sincronizar o acesso a dados compartilhados.

Normalmente, você isola o estado em um agente, mantendo os membros de dados nas **`private`** **`protected`** seções ou da classe Agent e usando buffers de mensagens para comunicar alterações de estado. O exemplo a seguir mostra a `basic_agent` classe, que deriva de [Concurrency:: Agent](../../parallel/concrt/reference/agent-class.md). A `basic_agent` classe usa dois buffers de mensagens para se comunicar com componentes externos. Um buffer de mensagens contém mensagens de entrada; o outro buffer de mensagens mantém mensagens de saída.

[!code-cpp[concrt-simple-agent#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-asynchronous-agents-library_1.cpp)]

Para obter exemplos completos sobre como definir e usar agentes, consulte [passo a passos: Criando um aplicativo baseado em agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md) e [passo a passo: Criando um agente de fluxo de](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)aplicativos.

[[Superior](#top)]

## <a name="use-a-throttling-mechanism-to-limit-the-number-of-messages-in-a-data-pipeline"></a><a name="throttling"></a>Usar um mecanismo de limitação para limitar o número de mensagens em um pipeline de dados

Muitos tipos de buffer de mensagens, como [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md), podem conter um número ilimitado de mensagens. Quando um produtor de mensagem envia mensagens a um pipeline de dados mais rápido do que o consumidor pode processar essas mensagens, o aplicativo pode inserir um estado de baixa memória ou de memória insuficiente. Você pode usar um mecanismo de limitação, por exemplo, um semáforo, para limitar o número de mensagens que estão ativas simultaneamente em um pipeline de dados.

O exemplo básico a seguir demonstra como usar um semáforo para limitar o número de mensagens em um pipeline de dados. O pipeline de dados usa a função [Concurrency:: Wait](reference/concurrency-namespace-functions.md#wait) para simular uma operação que leva pelo menos 100 milissegundos. Como o remetente produz mensagens mais rápidas do que o consumidor pode processar essas mensagens, este exemplo define a `semaphore` classe para permitir que o aplicativo limite o número de mensagens ativas.

[!code-cpp[concrt-message-throttling#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-asynchronous-agents-library_2.cpp)]

O `semaphore` objeto limita o pipeline para processar no máximo duas mensagens ao mesmo tempo.

O produtor neste exemplo envia relativamente poucas mensagens para o consumidor. Portanto, este exemplo não demonstra uma condição de pouca memória ou memória insuficiente. No entanto, esse mecanismo é útil quando um pipeline de dados contém um número relativamente alto de mensagens.

Para obter mais informações sobre como criar a classe Semaphore usada neste exemplo, consulte [como: usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md).

[[Superior](#top)]

## <a name="do-not-perform-fine-grained-work-in-a-data-pipeline"></a><a name="fine-grained"></a>Não executar trabalho refinado em um pipeline de dados

A biblioteca de agentes é mais útil quando o trabalho executado por um pipeline de dados é bastante granular. Por exemplo, um componente de aplicativo pode ler dados de um arquivo ou de uma conexão de rede e, ocasionalmente, enviar esses dados para outro componente. O protocolo que a biblioteca de agentes usa para propagar mensagens faz com que o mecanismo de passagem de mensagens tenha mais sobrecarga do que as construções paralelas de tarefa que são fornecidas pela ppl ( [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) ). Portanto, certifique-se de que o trabalho executado por um pipeline de dados seja longo o suficiente para compensar essa sobrecarga.

Embora um pipeline de dados seja mais eficaz quando suas tarefas são de alta granularidade, cada estágio do pipeline de dados pode usar construções PPL, como grupos de tarefas e algoritmos paralelos, para executar um trabalho mais refinado. Para obter um exemplo de uma rede de dados com uma grande granularidade que usa paralelismo refinado em cada estágio de processamento, consulte [passo a passos: criando uma rede de processamento de imagens](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).

[[Superior](#top)]

## <a name="do-not-pass-large-message-payloads-by-value"></a><a name="large-payloads"></a>Não passe cargas de mensagens grandes por valor

Em alguns casos, o tempo de execução cria uma cópia de cada mensagem que passa de um buffer de mensagens para outro buffer de mensagens. Por exemplo, a classe [Concurrency:: overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) oferece uma cópia de cada mensagem que recebe para cada um de seus destinos. O tempo de execução também cria uma cópia dos dados da mensagem quando você usa funções de passagem de mensagens, como [simultaneidade:: send](reference/concurrency-namespace-functions.md#send) e [simultaneidade:: Receive](reference/concurrency-namespace-functions.md#receive) para gravar mensagens e ler mensagens de um buffer de mensagens. Embora esse mecanismo ajude a eliminar o risco de gravar simultaneamente em dados compartilhados, isso pode levar a um desempenho de memória insatisfatório quando a carga da mensagem é relativamente grande.

Você pode usar ponteiros ou referências para melhorar o desempenho da memória ao passar mensagens com uma carga grande. O exemplo a seguir compara a passagem de mensagens grandes por valor para passar ponteiros para o mesmo tipo de mensagem. O exemplo define dois tipos de agente, `producer` e `consumer` isso atua em `message_data` objetos. O exemplo compara o tempo necessário para o produtor enviar vários `message_data` objetos ao consumidor para o tempo necessário para o agente de produtor enviar vários ponteiros para `message_data` os objetos para o consumidor.

[!code-cpp[concrt-message-payloads#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-asynchronous-agents-library_3.cpp)]

Este exemplo produz a seguinte saída de exemplo:

```Output
Using message_data...
took 437ms.
Using message_data*...
took 47ms.
```

A versão que usa ponteiros é melhor porque elimina o requisito para o tempo de execução criar uma cópia completa de cada `message_data` objeto que ele passa do produtor para o consumidor.

[[Superior](#top)]

## <a name="use-shared_ptr-in-a-data-network-when-ownership-is-undefined"></a><a name="ownership"></a>Usar shared_ptr em uma rede de dados quando a propriedade for indefinida

Quando você envia mensagens por ponteiro por meio de um pipeline de transmissão de mensagens ou rede, normalmente aloca a memória para cada mensagem na frente da rede e libera essa memória no final da rede. Embora esse mecanismo frequentemente funcione bem, há casos em que é difícil ou não possível usá-lo. Por exemplo, considere o caso em que a rede de dados contém vários nós finais. Nesse caso, não há nenhum local claro para liberar a memória para as mensagens.

Para resolver esse problema, você pode usar um mecanismo, por exemplo, [std:: shared_ptr](../../standard-library/shared-ptr-class.md), que permite que um ponteiro seja de propriedade de vários componentes. Quando o `shared_ptr` objeto final que possui um recurso é destruído, o recurso também é liberado.

O exemplo a seguir demonstra como usar o `shared_ptr` para compartilhar valores de ponteiro entre vários buffers de mensagens. O exemplo conecta um objeto [Concurrency:: overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) a três objetos [Concurrency:: Call](../../parallel/concrt/reference/call-class.md) . A `overwrite_buffer` classe oferece mensagens para cada um de seus destinos. Como há vários proprietários dos dados no final da rede de dados, este exemplo usa o `shared_ptr` para habilitar cada `call` objeto para compartilhar a propriedade das mensagens.

[!code-cpp[concrt-message-sharing#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-asynchronous-agents-library_4.cpp)]

Este exemplo produz a seguinte saída de exemplo:

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

## <a name="see-also"></a>Confira também

[Práticas recomendadas de Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime-best-practices.md)<br/>
[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Walkthrough: Criando um aplicativo baseado em agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)<br/>
[Walkthrough: Criando um agente de Dataflow](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)<br/>
[Walkthrough: criando uma rede de processamento de imagens](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)<br/>
[Práticas recomendadas na biblioteca de padrões paralelos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md)<br/>
[Práticas recomendadas gerais no Tempo de Execução de Simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)
