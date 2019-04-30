---
title: 'Como: Implementar vários padrões de produtor-consumidor'
ms.date: 11/04/2016
helpviewer_keywords:
- producer-consumer patterns, implementing [Concurrency Runtime]
- implementing producer-consumer patterns [Concurrency Runtime]
ms.assetid: 75f2c7cc-5399-49ea-98eb-847fe6747169
ms.openlocfilehash: 113518e97b6715384b5e7b84b0d0eab63dfcfcc7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62411351"
---
# <a name="how-to-implement-various-producer-consumer-patterns"></a>Como: Implementar vários padrões de produtor-consumidor

Este tópico descreve como implementar o padrão de produtor-consumidor em seu aplicativo. Nesse padrão, o *produtor* envia mensagens a um bloco de mensagens e o *consumidor* lê mensagens nesse bloco.

O tópico demonstra dois cenários. No primeiro cenário, o consumidor deve receber cada mensagem que envia o produtor. No segundo cenário, o consumidor sonda periodicamente para dados e, portanto, não tem que cada mensagem recebida.

Ambos os exemplos neste tópico usam os agentes, blocos de mensagens e funções de transmissão de mensagens para transmitir mensagens do produtor para o consumidor. O agente de produtor usa o [Concurrency:: Send](reference/concurrency-namespace-functions.md#send) função para gravar mensagens em uma [Concurrency:: ITarget](../../parallel/concrt/reference/itarget-class.md) objeto. O agente de consumidor usa a [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) função para ler mensagens de uma [Concurrency:: ISource](../../parallel/concrt/reference/isource-class.md) objeto. Os dois agentes contêm um valor de sentinela para coordenar o final do processamento.

Para obter mais informações sobre agentes assíncronos, consulte [agentes assíncronos](../../parallel/concrt/asynchronous-agents.md). Para obter mais informações sobre funções de transmissão de mensagens e os blocos de mensagem, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md) e [funções de transmissão de mensagens](../../parallel/concrt/message-passing-functions.md).

## <a name="example"></a>Exemplo

Neste exemplo, o agente de produtor envia uma série de números para o agente de consumidor. O consumidor recebe cada um desses números e computa sua média. O aplicativo grava a média para o console.

Este exemplo usa uma [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) objeto para permitir que o produtor para mensagens da fila. O `unbounded_buffer` classe implementa `ITarget` e `ISource` para que o produtor e consumidor podem enviar e receber mensagens e para um buffer compartilhado. O `send` e `receive` funções coordenam a tarefa de propagar os dados de produtor para o consumidor.

[!code-cpp[concrt-producer-consumer-average#1](../../parallel/concrt/codesnippet/cpp/how-to-implement-various-producer-consumer-patterns_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
The average is 50.
```

## <a name="example"></a>Exemplo

Neste exemplo, o agente de produtor envia uma série de cotações de ações para o agente de consumidor. Periodicamente, o agente de consumidor lê a cotação atual e imprime no console.

Este exemplo é semelhante ao anterior, exceto que ele usa um [Concurrency:: overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) objeto para permitir que o produtor compartilhar uma mensagem com o consumidor. Como no exemplo anterior, `overwrite_buffer` classe implementa `ITarget` e `ISource` para que o produtor e consumidor podem atuar em um buffer de mensagens compartilhado.

[!code-cpp[concrt-producer-consumer-quotes#1](../../parallel/concrt/codesnippet/cpp/how-to-implement-various-producer-consumer-patterns_2.cpp)]

Este exemplo produz a saída de exemplo a seguir.

```Output
Current quote is 24.44.
Current quote is 24.44.
Current quote is 24.65.
Current quote is 24.99.
Current quote is 23.76.
Current quote is 22.30.
Current quote is 25.89.
```

Ao contrário de com um `unbounded_buffer` objeto, o `receive` função não remove a mensagem do `overwrite_buffer` objeto. Se o consumidor lê do buffer de mensagem mais de uma vez antes que o produtor substitui essa mensagem, o destinatário obtém a mesma mensagem de cada vez.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `producer-consumer.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc producer-consumer.cpp**

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)
