---
title: "Fun&#231;&#245;es de transmiss&#227;o de mensagem | Microsoft Docs"
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
  - "funções de transmissão de mensagem"
ms.assetid: 42477c9e-a8a6-4dc4-a98e-93c6dc8c4dd0
caps.latest.revision: 23
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es de transmiss&#227;o de mensagem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A biblioteca assíncrona de agentes fornece várias funções que permitem passar mensagens entre os componentes.  
  
 Essas funções mensagem\- passando são usadas com vários tipos retornadas bloco.  Para obter mais informações sobre os tipos retornadas bloco que são definidos no tempo de execução de simultaneidade, consulte [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md).  
  
##  <a name="top"></a> Seções  
 Este tópico descreve as seguintes funções mensagem\- passando:  
  
-   [envio e asend](#send)  
  
-   [recebe e try\_receive](#receive)  
  
-   [Exemplos](#examples)  
  
##  <a name="send"></a> envio e asend  
 A função de [concurrency::send](../Topic/send%20Function.md) envia uma mensagem ao destino especificado de forma síncrona e os envios da função de [concurrency::asend](../Topic/asend%20Function.md) uma mensagem ao destino especificado de maneira assíncrona.  As funções de `send` e de `asend` esperar até que o destino que indica se houver aceitará ou diminuirá a mensagem.  
  
 A função de `send` espera até que o destino aceita ou diminui a mensagem antes de retornar.  A função de `send` retorna `true` se a mensagem foi entregue e `false` de outra forma.  Como a função de `send` funciona de forma síncrona, a função de `send` espera o destino para receber a mensagem antes de retornar.  
  
 Por outro lado, a função de `asend` não aguarda o destino para aceitar ou diminuir a mensagem antes de retornar.  Em vez disso, a função de `asend` retorna `true` se o destino aceita a mensagem e a levará se houver.  Caso contrário, `asend` retorna `false` para indicar que o destino diminuiu a mensagem ou adiou a decisão sobre se assumirá a mensagem.  
  
 \[[Superior](#top)\]  
  
##  <a name="receive"></a> recebe e try\_receive  
 [concurrency::receive](../Topic/receive%20Function.md) e [concurrency::try\_receive](../Topic/try_receive%20Function.md) funções lendo dados de uma origem especificada.  A função de `receive` espera dados fique disponível, enquanto a função de `try_receive` retorna imediatamente.  
  
 Use a função de `receive` quando você deve ter dados para continuar.  Use a função de `try_receive` se você não deve impedir o contexto atual ou você não tem que ter dados para continuar.  
  
 \[[Superior](#top)\]  
  
##  <a name="examples"></a> Exemplos  
 Para obter exemplos que usam `send` e `asend`, e as funções de `receive` , consulte os seguintes tópicos:  
  
-   [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
  
-   [Como implementar vários padrões de produtor\-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md)  
  
-   [Como fornecer funções de trabalho para as classes call e transformer](../../parallel/concrt/how-to-provide-work-functions-to-the-call-and-transformer-classes.md)  
  
-   [Como usar transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)  
  
-   [Como selecionar tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md)  
  
-   [Como enviar uma mensagem em um intervalo regular](../../parallel/concrt/how-to-send-a-message-at-a-regular-interval.md)  
  
-   [Como usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)  
  
 \[[Superior](#top)\]  
  
## Consulte também  
 [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Função send](../Topic/send%20Function.md)   
 [Função asend](../Topic/asend%20Function.md)   
 [Função receive](../Topic/receive%20Function.md)   
 [Função try\_receive](../Topic/try_receive%20Function.md)