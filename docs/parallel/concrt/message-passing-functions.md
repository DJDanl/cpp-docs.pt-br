---
title: Funções de transmissão de mensagem
ms.date: 11/04/2016
helpviewer_keywords:
- message passing functions
ms.assetid: 42477c9e-a8a6-4dc4-a98e-93c6dc8c4dd0
ms.openlocfilehash: e258a73723e78090f61230555748e109c28cf01c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50476018"
---
# <a name="message-passing-functions"></a>Funções de transmissão de mensagem

A biblioteca de agentes assíncronos fornece várias funções que permitem que você passar mensagens entre componentes.

Essas funções de transmissão de mensagens são usadas com os vários tipos de bloco de mensagens. Para obter mais informações sobre os tipos de bloco de mensagens que são definidos pelo tempo de execução de simultaneidade, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

##  <a name="top"></a> Seções

Este tópico descreve as funções de transmissão de mensagens a seguir:

- [Send e asend](#send)

- [receber e try_receive](#receive)

- [Exemplos](#examples)

##  <a name="send"></a> Send e asend

O [Concurrency:: Send](reference/concurrency-namespace-functions.md#send) função envia uma mensagem para o destino especificado forma síncrona e o [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend) função envia uma mensagem para o destino especificado de forma assíncrona. Tanto a `send` e `asend` funções Aguarde até que o destino indica que eventualmente irá aceitar ou recusar a mensagem.

O `send` função aguarda até que o destino aceita ou rejeita a mensagem antes de retornar. O `send` retornos de função **verdadeira** se a mensagem foi entregue e **falso** caso contrário. Porque o `send` função funciona de forma síncrona, o `send` função aguarda o destino receber a mensagem antes de retornar.

Por outro lado, o `asend` função não espera até que o destino aceitar ou recusar a mensagem antes de retornar. Em vez disso, o `asend` retornos de função **verdadeiro** se o destino aceita a mensagem e, eventualmente, colocá-lo. Caso contrário, `asend` retorna **falso** para indicar que o destino recusou a mensagem ou adiada a decisão sobre se deve pegar a mensagem.

[[Superior](#top)]

##  <a name="receive"></a> receber e try_receive

O [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) e [concurrency::try_receive](reference/concurrency-namespace-functions.md#try_receive) funções leem dados de uma origem específica. O `receive` função aguarda os dados fiquem disponíveis, enquanto o `try_receive` função retorna imediatamente.

Use o `receive` funcionar quando você deve ter os dados para continuar. Use o `try_receive` funcionar se você não deve bloquear o contexto atual ou você não precisa ter os dados para continuar.

[[Superior](#top)]

##  <a name="examples"></a> Exemplos

Para obter exemplos que usam o `send` e `asend`, e `receive` funções, consulte os seguintes tópicos:

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

