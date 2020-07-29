---
title: Funções de transmissão de mensagem
ms.date: 11/04/2016
helpviewer_keywords:
- message passing functions
ms.assetid: 42477c9e-a8a6-4dc4-a98e-93c6dc8c4dd0
ms.openlocfilehash: 3709e7b5280b96b2b77ec850a06ed15d0e42a7e5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87194622"
---
# <a name="message-passing-functions"></a>Funções de transmissão de mensagem

A biblioteca de agentes assíncronos fornece várias funções que permitem passar mensagens entre componentes.

Essas funções de passagem de mensagens são usadas com vários tipos de bloco de mensagens. Para obter mais informações sobre os tipos de bloco de mensagens que são definidos pelo Tempo de Execução de Simultaneidade, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="sections"></a><a name="top"></a>As

Este tópico descreve as seguintes funções de passagem de mensagens:

- [Enviar e asend](#send)

- [receber e try_receive](#receive)

- [Exemplos](#examples)

## <a name="send-and-asend"></a><a name="send"></a>Enviar e asend

A função [Concurrency:: send](reference/concurrency-namespace-functions.md#send) envia uma mensagem para o destino especificado de forma síncrona e a função [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend) envia uma mensagem para o destino especificado de maneira assíncrona. As `send` funções e `asend` esperam até que o destino indique que, eventualmente, aceitará ou recusará a mensagem.

A `send` função aguarda até que o destino aceite ou recuse a mensagem antes de retornar. A `send` função retorna **`true`** se a mensagem foi entregue e **`false`** , caso contrário,. Como a `send` função funciona de forma síncrona, a `send` função aguarda o destino receber a mensagem antes de retornar.

Por outro lado, a `asend` função não aguarda o destino aceitar ou recusar a mensagem antes de retornar. Em vez disso, a `asend` função retorna **`true`** se o destino aceita a mensagem e, eventualmente, a levará. Caso contrário, `asend` retorna **`false`** para indicar que o destino recusou a mensagem ou adie a decisão sobre se deve pegar a mensagem.

[[Superior](#top)]

## <a name="receive-and-try_receive"></a><a name="receive"></a>receber e try_receive

As funções [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) e [concurrency:: try_receive](reference/concurrency-namespace-functions.md#try_receive) lêem dados de uma determinada fonte. A `receive` função espera que os dados fiquem disponíveis, enquanto a `try_receive` função retorna imediatamente.

Use a `receive` função quando for necessário que os dados continuem. Use a `try_receive` função se você não deve bloquear o contexto atual ou não precisa ter os dados para continuar.

[[Superior](#top)]

## <a name="examples"></a><a name="examples"></a> Exemplos

Para obter exemplos que usam `send` as `asend` funções e e `receive` , consulte os seguintes tópicos:

- [Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)

- [Como implementar vários padrões de produtor-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md)

- [Como: fornecer funções de trabalho para as classes Call e transformador](../../parallel/concrt/how-to-provide-work-functions-to-the-call-and-transformer-classes.md)

- [Como: usar o transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)

- [Como: selecionar entre as tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md)

- [Como: Enviar uma mensagem em um intervalo regular](../../parallel/concrt/how-to-send-a-message-at-a-regular-interval.md)

- [Como: usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)

[[Superior](#top)]

## <a name="see-also"></a>Confira também

[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Função send](reference/concurrency-namespace-functions.md#send)<br/>
[Função asend](reference/concurrency-namespace-functions.md#asend)<br/>
[Função receive](reference/concurrency-namespace-functions.md#receive)<br/>
[Função try_receive](reference/concurrency-namespace-functions.md#try_receive)
