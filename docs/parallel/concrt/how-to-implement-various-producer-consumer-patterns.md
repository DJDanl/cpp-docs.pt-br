---
title: "Como implementar v&#225;rios padr&#245;es de produtor-consumidor | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "padrões de produtor-consumidor, Implementando [tempo de execução de simultaneidade]"
  - "implementando padrões de produtor-consumidor [Tempo de Execução de Simultaneidade]"
ms.assetid: 75f2c7cc-5399-49ea-98eb-847fe6747169
caps.latest.revision: 17
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como implementar v&#225;rios padr&#245;es de produtor-consumidor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico descreve como implementar o padrão de produtor\- consumidor em seu aplicativo.  Neste padrão, *o produtor* envia mensagens a um bloco de mensagem, e *o consumidor* lê mensagens desse bloco.  
  
 O tópico a seguir demonstra dois cenários.  No primeiro caso, o consumidor deve receber cada mensagem que o produtor envia.  No segundo cenário, o consumidor sonda periodicamente para dados e, consequentemente não precisa receber cada mensagem.  
  
 Ambos os exemplos deste tópico usam agentes, blocos da mensagem e, mensagem\- passar funções para transmitir mensagens do produtor ao consumidor.  O agente do produtor usa a função de [concurrency::send](../Topic/send%20Function.md) para gravar mensagens a um objeto de [concurrency::ITarget](../../parallel/concrt/reference/itarget-class.md) .  O agente do consumidor usa a função de [concurrency::receive](../Topic/receive%20Function.md) para ler mensagens de um objeto de [concurrency::ISource](../../parallel/concrt/reference/isource-class.md) .  Ambos os agentes mantém um valor de sentinela para coordenar a fim de processamento.  
  
 Para obter mais informações sobre os agentes assíncronas, consulte [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md).  Para obter mais informações sobre os blocos da mensagem e funções mensagem\- decorrer, consulte [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md) e [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md).  
  
## Exemplo  
 Neste exemplo, o agente do produtor envia uma série de números para o agente do consumidor.  O consumidor recebe cada um desses números e calcula a média.  O aplicativo grava a média para o console.  
  
 Este exemplo usa um objeto de [concurrency::unbounded\_buffer](../Topic/unbounded_buffer%20Class.md) para habilitar o produtor para enfileirar mensagens.  A classe de `unbounded_buffer` implementa `ITarget` e `ISource` de forma que o produtor e o consumidor pode enviar e receber mensagens para e de um buffer compartilhado.  As funções de `send` e de `receive` coordenam a tarefa de propagar os dados do produtor ao consumidor.  
  
 [!code-cpp[concrt-producer-consumer-average#1](../../parallel/concrt/codesnippet/CPP/how-to-implement-various-producer-consumer-patterns_1.cpp)]  
  
 O exemplo produz a seguinte saída.  
  
  **A média é 50.**   
## Exemplo  
 Neste exemplo, o agente do produtor envia uma série de preços de títulos para o agente do consumidor.  O agente do consumidor lê periodicamente as aspas atuais e imprime\-as ao console.  
  
 Este exemplo é semelhante ao anterior, exceto que usa um objeto de [concurrency::overwrite\_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) para habilitar o produtor para compartilhar uma mensagem com o consumidor.  Como no exemplo anterior, a classe de `overwrite_buffer` implementa `ITarget` e `ISource` de forma que o produtor e o consumidor pode atuar em um buffer de mensagem compartilhado.  
  
 [!code-cpp[concrt-producer-consumer-quotes#1](../../parallel/concrt/codesnippet/CPP/how-to-implement-various-producer-consumer-patterns_2.cpp)]  
  
 Esse exemplo gera a seguinte saída de amostra.  
  
  **As aspas atual é 24,44.**  
**As aspas atual é 24,44.**  
**As aspas atual é 24,65.**  
**As aspas atual é 24,99.**  
**As aspas atual é 23,76.**  
**As aspas atual é 22,30.**  
**As aspas atual é 25,89.** Ao contrário do com um objeto de `unbounded_buffer` , a função de `receive` não remove a mensagem do objeto de `overwrite_buffer` .  Se o consumidor lido do buffer de mensagem mais de uma vez antes do produtor substitui a mensagem, o destinatário obtém a mesma mensagem sempre.  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `producer-consumer.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc producer\-consumer.cpp**  
  
## Consulte também  
 [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)