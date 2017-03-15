---
title: "Como enviar uma mensagem em um intervalo regular | Microsoft Docs"
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
  - "classe Timer, por exemplo:"
  - "enviando mensagens a intervalos regulares [Tempo de Execução de Simultaneidade]"
ms.assetid: 4b60ea6c-97c8-4d69-9f7b-ad79f3548026
caps.latest.revision: 19
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como enviar uma mensagem em um intervalo regular
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este exemplo mostra como usar a simultaneidade::[classe timer](../../parallel/concrt/reference/timer-class.md) para enviar uma mensagem em intervalos regulares.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir usa uma `timer` objeto para relatar o progresso durante uma operação demorada. Este exemplo vincula o `timer` do objeto para um [concurrency::call](../../parallel/concrt/reference/call-class.md) objeto. O `call` objeto imprime um indicador de progresso para o console em intervalos regulares. O [concurrency::timer::start](../Topic/timer::start%20Method.md) método executa o timer em um contexto separado. O `perform_lengthy_operation` chamadas de função do [concurrency::wait](../Topic/wait%20Function.md) função no contexto do principal para simular uma operação demorada.  
  
 [!CODE [concrt-report-progress#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-report-progress#1)]  
  
 Este exemplo produz a seguinte saída de exemplo:  
  
```Output  
Performing a lengthy operation..........done.  
```  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `report-progress.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **relatório de /EHsc cl.exe-progress.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagens](../../parallel/concrt/message-passing-functions.md)
