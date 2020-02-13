---
title: Como enviar uma mensagem em um intervalo regular
ms.date: 11/04/2016
helpviewer_keywords:
- timer class, example
- sending messages at regular intervals [Concurrency Runtime]
ms.assetid: 4b60ea6c-97c8-4d69-9f7b-ad79f3548026
ms.openlocfilehash: c51a5cab6fcae5eb45b9d9b54c0dad8e8ec393b2
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142459"
---
# <a name="how-to-send-a-message-at-a-regular-interval"></a>Como enviar uma mensagem em um intervalo regular

Este exemplo mostra como usar a classe Concurrency::[timer](../../parallel/concrt/reference/timer-class.md) para enviar uma mensagem em um intervalo regular.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir usa um objeto `timer` para relatar o andamento durante uma operação demorada. Este exemplo vincula o objeto `timer` a um objeto [Concurrency:: Call](../../parallel/concrt/reference/call-class.md) . O objeto `call` imprime um indicador de progresso no console em um intervalo regular. O método [Concurrency:: timer:: Start](reference/timer-class.md#start) executa o temporizador em um contexto separado. A função `perform_lengthy_operation` chama a função [Concurrency:: Wait](reference/concurrency-namespace-functions.md#wait) no contexto principal para simular uma operação demorada.

[!code-cpp[concrt-report-progress#1](../../parallel/concrt/codesnippet/cpp/how-to-send-a-message-at-a-regular-interval_1.cpp)]

Este exemplo produz a seguinte saída de exemplo:

```Output
Performing a lengthy operation..........done.
```

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `report-progress.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Report-Progress. cpp**

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)
