---
title: "Multithread com C++ e MFC | Microsoft Docs"
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
  - "Classe CWinThread, finalidade de"
  - "MFC [C++], multithreading"
  - "multithreading [C++], MFC"
  - "sincronização [C++], multithreading"
  - "classes de sincronização [C++]"
  - "threading [C++], MFC"
  - "threading [MFC]"
  - "threading [MFC], sobre threading"
  - "threads de interface de usuário [C++]"
  - "threads de trabalho [C++]"
ms.assetid: 979605f8-3988-44b5-ac9c-b8cce7fcce14
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Multithread com C++ e MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca Microsoft Foundation Class \(MFC\) oferece suporte a aplicativos multithreaded.  Este tópico descreve processos e threads e qual é a abordagem do MFC para multithreading.  
  
 Um processo é uma instância em execução de um aplicativo.  Por exemplo, quando você clica duas vezes no ícone do Bloco de notas, você inicia um processo que executa o Bloco de notas.  
  
 Um thread é um caminho de execução em um processo.  Ao iniciar o Bloco de Notas, o sistema operacional cria um processo e começa a executar o segmento principal do processo.  Quando essa thread termina, o processo se encerra.  Esse thread principal é fornecido ao sistema operacional pelo código inicial na forma de um endereço de função.  Geralmente, é o endereço da função **main** ou `WinMain` que é fornecida.  
  
 É possível criar threads adicionais em seu aplicativo, se desejar.  Talvez você queira fazer isso para gerenciar tarefas de plano de fundo ou de manutenção quando não desejar que o usuário espere até que estejam concluídas.  Todos os threads em aplicativos do MFC são representados por objetos [CWinThread](../mfc/reference/cwinthread-class.md).  Na maioria das situações, você não precisa nem criar explicitamente esses objetos. Em vez disso, chame a função auxiliar de estrutura [AfxBeginThread](../Topic/AfxBeginThread.md), que cria o objeto `CWinThread` para você.  
  
 O MFC distingue dois tipos de threads: threads de interface de usuário e threads de trabalho.  Os segmentos de interface do usuário são normalmente usados para manipular a entrada do usuário e responder a eventos e mensagens gerados pelo usuário.  Threads de trabalho são normalmente usadas para concluir as tarefas, como um recálculo, que não requerem a entrada do usuário.  A API do Win32 não faz distinção entre tipos de threads; apenas precisa conhecer o endereço inicial do thread para poder começar a executar o thread.  O MFC manipula os threads da interface do usuário especialmente fornecendo uma bomba de mensagens para eventos na interface do usuário.  `CWinApp` é um exemplo de um objeto de thread de interface do usuário, pois ele é derivado de `CWinThread` e controla eventos e mensagens gerados pelo usuário.  
  
 Deve ser data atenção especial às situações onde mais de um thread poderia exibir acesso ao mesmo objeto.  [Multithreading: Dicas de Programação](../parallel/multithreading-programming-tips.md) descreve técnicas que você pode utilizar para resolver problemas que podem ocorrer nessas situações.  [Multithreading: Como Usar as Classes de Sincronização](../parallel/multithreading-how-to-use-the-synchronization-classes.md) descreve como usar as classes que estão disponíveis para sincronizar acesso de vários threads a um único objeto.  
  
 A gravação e a depuração da programação multithread é inerentemente uma tarefa complicada e difícil, porque você deve garantir que os objetos não sejam acessados por mais de um segmento de cada vez.  Os tópicos de multithreading não ensinam as noções básicas de programação multithreaded, somente a usar o MFC em seu programa multithreaded.  Os exemplos multithreaded do MFC incluídos no Visual C\+\+ ilustram algumas APIs multithreaded de Adição de Funcionalidade e Win32 não englobadas pelo MFC; no entanto, elas se destinam somente a serem um ponto de partida.  
  
 Para obter mais informações sobre como o sistema operacional trata processos e threads, consulte [Processos e Threads](http://msdn.microsoft.com/library/windows/desktop/ms684841) em [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  
  
 Para obter mais informações sobre suporte multithreading MFC, consulte os tópicos a seguir:  
  
-   [Multithreading: Criando Threads da Interface do Usuário](../parallel/multithreading-creating-user-interface-threads.md)  
  
-   [Multithreading: Criando Threads de Trabalho](../parallel/multithreading-creating-worker-threads.md)  
  
-   [Multithreading: Como Usar as Classes de Sincronização](../parallel/multithreading-how-to-use-the-synchronization-classes.md)  
  
-   [Multithreading: Threads de Terminação](../parallel/multithreading-terminating-threads.md)  
  
-   [Multithreading: Dicas de Programação](../parallel/multithreading-programming-tips.md)  
  
-   [Multithreading: Quando Usar as Classes de Sincronização](../parallel/multithreading-when-to-use-the-synchronization-classes.md)  
  
## Consulte também  
 [Suporte multithread para código anterior \(Visual C\+\+\)](../parallel/multithreading-support-for-older-code-visual-cpp.md)