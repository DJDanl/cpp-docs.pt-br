---
title: "Como: implementar vários padrões de produtor-consumidor | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- producer-consumer patterns, implementing [Concurrency Runtime]
- implementing producer-consumer patterns [Concurrency Runtime]
ms.assetid: 75f2c7cc-5399-49ea-98eb-847fe6747169
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0efafe17cd524c241e709d3c3c59233a130cdf95
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-implement-various-producer-consumer-patterns"></a>Como implementar vários padrões de produtor-consumidor
Este tópico descreve como implementar o padrão de produtor-consumidor em seu aplicativo. Nesse padrão, o *produtor* envia mensagens para um bloco de mensagens e o *consumidor* lê mensagens esse bloco.  
  
 O tópico demonstra dois cenários. O primeiro cenário, o consumidor deve receber cada mensagem que envia o produtor. O segundo cenário, o consumidor sonda periodicamente para dados e, portanto, não tem que cada mensagem.  
  
 Ambos os exemplos neste tópico usam agentes, blocos de mensagens e funções de transmissão de mensagens para transmitir mensagens do produtor para o consumidor. O agente de produtor usa o [concurrency::send](reference/concurrency-namespace-functions.md#send) função para gravar mensagens para um [concurrency::ITarget](../../parallel/concrt/reference/itarget-class.md) objeto. O agente do cliente usa o [concurrency::receive](reference/concurrency-namespace-functions.md#receive) função para ler mensagens de uma [concurrency::ISource](../../parallel/concrt/reference/isource-class.md) objeto. Os dois agentes mantêm um valor de sentinela para coordenar o final do processamento.  
  
 Para obter mais informações sobre agentes assíncronos, consulte [agentes assíncronos](../../parallel/concrt/asynchronous-agents.md). Para obter mais informações sobre funções de transmissão de mensagens e blocos de mensagens, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md) e [funções de transmissão de mensagens](../../parallel/concrt/message-passing-functions.md).  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, o agente de produtor envia uma série de números para o agente do consumidor. O consumidor recebe cada um desses números e computa sua média. O aplicativo grava a média para o console.  
  
 Este exemplo usa um [concurrency::unbounded_buffer](reference/unbounded-buffer-class.md) objeto para permitir que o produtor e mensagens da fila. O `unbounded_buffer` classe implementa `ITarget` e `ISource` para que o produtor e consumidor podem enviar e receber mensagens e para um buffer compartilhado. O `send` e `receive` funções coordenam a tarefa de propagar os dados do produtor para o consumidor.  
  
 [!code-cpp[concrt-producer-consumer-average#1](../../parallel/concrt/codesnippet/cpp/how-to-implement-various-producer-consumer-patterns_1.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
The average is 50.  
```  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, o agente de produtor envia uma série de cotações de ações para o agente do consumidor. Periodicamente, o agente de consumidor lê a cotação atual e imprime no console.  
  
 Este exemplo semelhante ao anterior, exceto que ele usa um [concurrency::overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) objeto para permitir que o produtor compartilhar uma mensagem com o consumidor. Como no exemplo anterior, `overwrite_buffer` classe implementa `ITarget` e `ISource` para que o produtor e consumidor podem agir em um buffer de mensagem compartilhado.  
  
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
  
 Ao contrário de com um `unbounded_buffer` objeto, o `receive` função não remove a mensagem do `overwrite_buffer` objeto. Se o consumidor lê do buffer de mensagem de mais de uma vez antes do produtor substitui essa mensagem, o destinatário obtém a mesma mensagem de cada vez.  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `producer-consumer.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc produtor-consumer.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)
