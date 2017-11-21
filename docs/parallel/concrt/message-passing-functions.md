---
title: "Funções de transmissão de mensagens | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: message passing functions
ms.assetid: 42477c9e-a8a6-4dc4-a98e-93c6dc8c4dd0
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 4139068c8871fe69f43168fe925011a48411a74b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="message-passing-functions"></a>Funções de transmissão de mensagem
A biblioteca de agentes assíncrona fornece várias funções que permitem que você passar mensagens entre componentes.  
  
 Essas funções de transmissão de mensagens são usadas com os vários tipos de bloco de mensagens. Para obter mais informações sobre os tipos de bloco de mensagens que são definidos pelo tempo de execução de simultaneidade, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).  
  
##  <a name="top"></a>Seções  
 Este tópico descreve as funções de transmissão de mensagens a seguir:  
  
-   [envio e asend](#send)  
  
-   [receber e try_receive](#receive)  
  
-   [Exemplos](#examples)  
  
##  <a name="send"></a>envio e asend  

 O [concurrency::send](reference/concurrency-namespace-functions.md#send) função envia uma mensagem para o destino especificado modo síncrono e o [concurrency::asend](reference/concurrency-namespace-functions.md#asend) função envia uma mensagem para o destino especificado assincronamente. Tanto o `send` e `asend` funções Aguarde até que o destino indica que ele eventualmente aceitar ou recusar a mensagem.  
  
 O `send` função aguarda até que o destino aceita ou recusa a mensagem antes de retornar. O `send` função retorna `true` se a mensagem foi entregue e `false` caso contrário. Porque o `send` função funciona de forma síncrona, o `send` função aguarda até que o destino receber a mensagem antes de retornar.  
  
 Por outro lado, o `asend` função não espera que o destino aceitar ou recusar a mensagem antes de retornar. Em vez disso, o `asend` função retorna `true` se o destino aceita a mensagem e, eventualmente, levará. Caso contrário, `asend` retorna `false` para indicar que o destino recusou a mensagem ou adiada a decisão sobre se deve colocar a mensagem.  
  
 [[Superior](#top)]  
  
##  <a name="receive"></a>receber e try_receive  

 O [concurrency::receive](reference/concurrency-namespace-functions.md#receive) e [concurrency::try_receive](reference/concurrency-namespace-functions.md#try_receive) funções leem dados de uma origem específica. O `receive` função aguarda os dados fiquem disponíveis, enquanto o `try_receive` função retorna imediatamente.  
  
 Use o `receive` funcionar quando você deve ter os dados para continuar. Use o `try_receive` funcionar se você não deve bloquear o contexto atual ou você não precisa ter dados para continuar.  
  
 [[Superior](#top)]  
  
##  <a name="examples"></a> Exemplos  
 Para obter exemplos que usam o `send` e `asend`, e `receive` funções, consulte os seguintes tópicos:  
  
-   [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
  
-   [Como implementar vários padrões de produtor-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md)  
  
-   [Como fornecer funções de trabalho para as classes call e transformer](../../parallel/concrt/how-to-provide-work-functions-to-the-call-and-transformer-classes.md)  
  
-   [Como usar transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)  
  
-   [Como selecionar entre tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md)  
  
-   [Como enviar uma mensagem a um intervalo regular](../../parallel/concrt/how-to-send-a-message-at-a-regular-interval.md)  
  
-   [Como usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)  
  
 [[Superior](#top)]  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Função Send](reference/concurrency-namespace-functions.md#send)   
 [Função asend](reference/concurrency-namespace-functions.md#asend)   
 [Função Receive](reference/concurrency-namespace-functions.md#receive)   
 [Função try_receive](reference/concurrency-namespace-functions.md#try_receive)


