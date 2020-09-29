---
title: Como implementar vários padrões de produtor-consumidor
ms.date: 11/04/2016
helpviewer_keywords:
- producer-consumer patterns, implementing [Concurrency Runtime]
- implementing producer-consumer patterns [Concurrency Runtime]
ms.assetid: 75f2c7cc-5399-49ea-98eb-847fe6747169
ms.openlocfilehash: 70813adf6715a2bcaf4af7370ce43d99c44263bd
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91413769"
---
# <a name="how-to-implement-various-producer-consumer-patterns"></a>Como implementar vários padrões de produtor-consumidor

Este tópico descreve como implementar o padrão produtor-consumidor em seu aplicativo. Nesse padrão, o *produtor* envia mensagens a um bloco de mensagens e o *consumidor* lê mensagens nesse bloco.

O tópico demonstra dois cenários. No primeiro cenário, o consumidor deve receber cada mensagem que o produtor envia. No segundo cenário, o consumidor sonda periodicamente os dados e, portanto, não precisa receber cada mensagem.

Os dois exemplos neste tópico usam agentes, blocos de mensagens e funções de passagem de mensagens para transmitir mensagens do produtor para o consumidor. O agente de produtor usa a função [Concurrency:: send](reference/concurrency-namespace-functions.md#send) para gravar mensagens em um objeto [Concurrency:: ITarget](../../parallel/concrt/reference/itarget-class.md) . O agente do consumidor usa a função [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) para ler mensagens de um objeto [Concurrency:: as](../../parallel/concrt/reference/isource-class.md) . Ambos os agentes mantêm um valor de sentinela para coordenar o fim do processamento.

Para obter mais informações sobre agentes assíncronos, consulte [agentes assíncronos](../../parallel/concrt/asynchronous-agents.md). Para obter mais informações sobre blocos de mensagens e funções de passagem de mensagens, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md) e [funções de passagem de mensagens](../../parallel/concrt/message-passing-functions.md).

## <a name="example-send-series-of-numbers-to-consumer-agent"></a>Exemplo: Enviar uma série de números para o agente do consumidor

Neste exemplo, o agente de produtor envia uma série de números para o agente do consumidor. O consumidor recebe cada um desses números e calcula sua média. O aplicativo grava a média no console.

Este exemplo usa um objeto [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) para habilitar o produtor para enfileirar mensagens. A `unbounded_buffer` classe implementa `ITarget` e `ISource` , para que o produtor e o consumidor possam enviar e receber mensagens de e para um buffer compartilhado. As `send` `receive` funções e coordenam a tarefa de propagar os dados do produtor para o consumidor.

[!code-cpp[concrt-producer-consumer-average#1](../../parallel/concrt/codesnippet/cpp/how-to-implement-various-producer-consumer-patterns_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
The average is 50.
```

## <a name="example-send-series-of-stock-quotes-to-consumer-agent"></a>Exemplo: Enviar uma série de Cotações de ações para o agente do consumidor

Neste exemplo, o agente de produtor envia uma série de Cotações de ações para o agente do consumidor. Periodicamente, o agente do consumidor lê a cotação atual e a imprime no console.

Este exemplo é semelhante ao anterior, exceto pelo fato de que ele usa um objeto [Concurrency:: overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) para permitir que o produtor Compartilhe uma mensagem com o consumidor. Como no exemplo anterior, a `overwrite_buffer` classe implementa `ITarget` e `ISource` , para que o produtor e o consumidor possam agir em um buffer de mensagens compartilhado.

[!code-cpp[concrt-producer-consumer-quotes#1](../../parallel/concrt/codesnippet/cpp/how-to-implement-various-producer-consumer-patterns_2.cpp)]

Este exemplo produz a seguinte saída de exemplo.

```Output
Current quote is 24.44.
Current quote is 24.44.
Current quote is 24.65.
Current quote is 24.99.
Current quote is 23.76.
Current quote is 22.30.
Current quote is 25.89.
```

Ao contrário de um `unbounded_buffer` objeto, a `receive` função não remove a mensagem do `overwrite_buffer` objeto. Se o consumidor lê o buffer de mensagens mais de uma vez antes de o produtor substituir essa mensagem, o receptor Obtém a mesma mensagem a cada vez.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `producer-consumer.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

**cl.exe/EHsc Producer-Consumer. cpp**

## <a name="see-also"></a>Confira também

[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)<br/>
[Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de passagem de mensagens](../../parallel/concrt/message-passing-functions.md)
