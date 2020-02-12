---
title: Funções de transmissão de mensagem
ms.date: 11/04/2016
helpviewer_keywords:
- message passing functions
ms.assetid: 42477c9e-a8a6-4dc4-a98e-93c6dc8c4dd0
ms.openlocfilehash: 4e1052a59f355c4ad5a7c6b57724268c24a209b4
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77143292"
---
# <a name="message-passing-functions"></a>Funções de transmissão de mensagem

A biblioteca de agentes assíncronos fornece várias funções que permitem passar mensagens entre componentes.

Essas funções de passagem de mensagens são usadas com vários tipos de bloco de mensagens. Para obter mais informações sobre os tipos de bloco de mensagens que são definidos pelo Tempo de Execução de Simultaneidade, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="top"></a>As

Este tópico descreve as seguintes funções de passagem de mensagens:

- [Enviar e asend](#send)

- [receber e try_receive](#receive)

- [Exemplos](#examples)

## <a name="send"></a>Enviar e asend

A função [Concurrency:: send](reference/concurrency-namespace-functions.md#send) envia uma mensagem para o destino especificado de forma síncrona e a função [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend) envia uma mensagem para o destino especificado de maneira assíncrona. As funções `send` e `asend` esperam até que o destino indique que, eventualmente, aceitará ou recusará a mensagem.

A função `send` aguarda até que o destino aceite ou recuse a mensagem antes de retornar. A função `send` retornará **true** se a mensagem tiver sido entregue e **false** caso contrário. Como a função `send` funciona de forma síncrona, a função `send` aguarda o destino receber a mensagem antes de retornar.

Por outro lado, a função `asend` não aguarda o destino aceitar ou recusar a mensagem antes de retornar. Em vez disso, a função `asend` retornará **true** se o destino aceitar a mensagem e, eventualmente, a levará. Caso contrário, `asend` retorna **false** para indicar que o destino recusou a mensagem ou adiava a decisão sobre se deve pegar a mensagem.

[[Superior](#top)]

## <a name="receive"></a>receber e try_receive

As funções [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) e [concurrency:: try_receive](reference/concurrency-namespace-functions.md#try_receive) lêem dados de uma determinada fonte. A função `receive` aguarda que os dados fiquem disponíveis, enquanto a função `try_receive` retorna imediatamente.

Use a função `receive` quando for necessário que os dados continuem. Use a função `try_receive` se você não precisar bloquear o contexto atual ou não precisar que os dados continuem.

[[Superior](#top)]

## <a name="examples"></a> Exemplos

Para obter exemplos que usam as funções `send` e `asend`e `receive`, consulte os seguintes tópicos:

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Como implementar vários padrões de produtor-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md)

- [Como fornecer funções de trabalho para as classes call e transformer](../../parallel/concrt/how-to-provide-work-functions-to-the-call-and-transformer-classes.md)

- [Como usar transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)

- [Como selecionar entre tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md)

- [Como enviar uma mensagem a um intervalo regular](../../parallel/concrt/how-to-send-a-message-at-a-regular-interval.md)

- [Como usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)

[[Superior](#top)]

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Função Send](reference/concurrency-namespace-functions.md#send)<br/>
[Função asend](reference/concurrency-namespace-functions.md#asend)<br/>
[Função Receive](reference/concurrency-namespace-functions.md#receive)<br/>
[Função try_receive](reference/concurrency-namespace-functions.md#try_receive)
