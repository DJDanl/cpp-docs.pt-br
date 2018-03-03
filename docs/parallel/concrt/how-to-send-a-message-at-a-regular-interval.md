---
title: 'Como: enviar uma mensagem em um intervalo Regular | Microsoft Docs'
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
- timer class, example
- sending messages at regular intervals [Concurrency Runtime]
ms.assetid: 4b60ea6c-97c8-4d69-9f7b-ad79f3548026
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f12d9f8af028d1e2e1fc149eeb77181c2f6b1730
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-send-a-message-at-a-regular-interval"></a>Como enviar uma mensagem em um intervalo regular
Este exemplo mostra como usar a simultaneidade::[classe timer](../../parallel/concrt/reference/timer-class.md) para enviar uma mensagem em intervalos regulares.  
  
## <a name="example"></a>Exemplo  

 O exemplo a seguir usa uma `timer` objeto para relatar o progresso durante uma operação demorada. Este exemplo vincula o `timer` o objeto para um [concurrency::call](../../parallel/concrt/reference/call-class.md) objeto. O `call` objeto imprime um indicador de progresso para o console em intervalos regulares. O [concurrency::timer::start](reference/timer-class.md#start) método executa o timer em um contexto separado. O `perform_lengthy_operation` chamadas de função de [concurrency::wait](reference/concurrency-namespace-functions.md#wait) função no contexto do principal para simular uma operação demorada.  

  
 [!code-cpp[concrt-report-progress#1](../../parallel/concrt/codesnippet/cpp/how-to-send-a-message-at-a-regular-interval_1.cpp)]  
  
 Este exemplo produz a saída de exemplo a seguir:  
  
```Output  
Performing a lengthy operation..........done.  
```  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `report-progress.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **relatório de /EHsc cl.exe-progress.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)
