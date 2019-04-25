---
title: 'Como: Enviar uma mensagem em um intervalo Regular'
ms.date: 11/04/2016
helpviewer_keywords:
- timer class, example
- sending messages at regular intervals [Concurrency Runtime]
ms.assetid: 4b60ea6c-97c8-4d69-9f7b-ad79f3548026
ms.openlocfilehash: 0bf5f93e2a570761874232a88a23289e59e58d94
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62321956"
---
# <a name="how-to-send-a-message-at-a-regular-interval"></a>Como: Enviar uma mensagem em um intervalo Regular

Este exemplo mostra como usar a simultaneidade::[classe timer](../../parallel/concrt/reference/timer-class.md) para enviar uma mensagem em intervalos regulares.

## <a name="example"></a>Exemplo

O exemplo a seguir usa um `timer` objeto relatar o progresso durante uma operação demorada. Este exemplo vincula a `timer` do objeto para um [concurrency::call](../../parallel/concrt/reference/call-class.md) objeto. O `call` objeto imprime um indicador de progresso para o console em intervalos regulares. O [concurrency::timer::start](reference/timer-class.md#start) método é executado o temporizador em um contexto separado. O `perform_lengthy_operation` chamadas de função do [concurrency::wait](reference/concurrency-namespace-functions.md#wait) função no contexto do principal para simular uma operação demorada.

[!code-cpp[concrt-report-progress#1](../../parallel/concrt/codesnippet/cpp/how-to-send-a-message-at-a-regular-interval_1.cpp)]

Este exemplo produz a saída de exemplo a seguir:

```Output
Performing a lengthy operation..........done.
```

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `report-progress.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**relatório de /EHsc cl.exe-progress.cpp**

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)
