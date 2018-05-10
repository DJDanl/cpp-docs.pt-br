---
title: Multithread com C++ e MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC [C++], multithreading
- threading [C++], MFC
- worker threads [C++]
- synchronization classes [C++]
- synchronization [C++], multithreading
- threading [MFC], about threading
- CWinThread class, purpose of
- multithreading [C++], MFC
- threading [MFC]
- user interface threads [C++]
ms.assetid: 979605f8-3988-44b5-ac9c-b8cce7fcce14
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 778602a0e9236ad8cc788d8a2306e8f2d143ec49
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="multithreading-with-c-and-mfc"></a>Multithread com C++ e MFC
A biblioteca Microsoft Foundation Class (MFC) fornece suporte para aplicativos multithread. Este tópico descreve os processos e threads e a abordagem do MFC para multithreading.  
  
 Um processo é uma instância de um aplicativo em execução. Por exemplo, quando você clicar duas vezes no ícone do bloco de notas, iniciar um processo que executa o bloco de notas.  
  
 Um thread é um caminho de execução dentro de um processo. Quando você inicia o bloco de notas, o sistema operacional cria um processo e começa a execução do thread principal do processo. Quando esse thread termina, portanto não o processo. Esse thread principal é fornecida para o sistema operacional pelo código de inicialização na forma de um endereço da função. Normalmente, é o endereço do **principal** ou `WinMain` função que é fornecida.  
  
 Você pode criar threads adicionais em seu aplicativo, se você quiser. Você talvez queira fazer isso para lidar com tarefas de manutenção ou em segundo plano quando você não deseja que o usuário de espera para que elas sejam concluídas. Todos os threads em aplicativos MFC são representados por [CWinThread](../mfc/reference/cwinthread-class.md) objetos. Na maioria das situações, você ainda precisa criar explicitamente esses objetos. em vez disso, chame a função auxiliar do framework [AfxBeginThread](../mfc/reference/application-information-and-management.md#afxbeginthread), que cria o `CWinThread` objeto para você.  
  
 MFC distingue os dois tipos de threads: threads de interface do usuário e os threads de trabalho. Threads de interface do usuário são usadas para manipular a entrada do usuário e responder a eventos e as mensagens geradas pelo usuário. Threads de trabalho são usados para executar tarefas, como o recálculo, que não exigem entrada do usuário. A API do Win32 não faz distinção entre tipos de threads; ele só precisa saber o endereço inicial do segmento para poder começar a executar o thread. MFC manipula threads de interface do usuário especialmente fornecendo um bombeamento de mensagens de eventos na interface do usuário. `CWinApp` é um exemplo de um objeto de thread de interface do usuário, porque deriva de `CWinThread` e trata os eventos e as mensagens geradas pelo usuário.  
  
 Atenção especial deve ser fornecida para situações em que mais de um thread pode exigir o acesso ao mesmo objeto. [Multithreading: Dicas de programação](../parallel/multithreading-programming-tips.md) descreve técnicas que você pode usar para resolver problemas que podem surgir nessas situações. [Multithreading: Como usar as Classes de sincronização](../parallel/multithreading-how-to-use-the-synchronization-classes.md) descreve como usar as classes que estão disponíveis para sincronizar o acesso de vários threads a um único objeto.  
  
 Criação e depuração de programação multithread inerentemente são uma tarefa complexa e difícil, porque você deve garantir que objetos não são acessados por mais de um segmento por vez. Os tópicos de multithreading ensina as Noções básicas de programação multithread, apenas como usar MFC em seu programa multi-threaded. Os exemplos MFC multithread incluídos no Visual C++ ilustram alguns adicionando funcionalidade multithread e APIs do Win32 não circundado por MFC; No entanto, eles só devem ser um ponto de partida.  
  
 Para obter mais informações sobre como o sistema operacional trata processos e threads, consulte [processos e Threads](http://msdn.microsoft.com/library/windows/desktop/ms684841) no [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)].  
  
 Para obter mais informações sobre o suporte a multithreading MFC, consulte os tópicos a seguir:  
  
-   [Multithreading: criando threads da interface do usuário](../parallel/multithreading-creating-user-interface-threads.md)  
  
-   [Multithreading: criando threads de trabalho](../parallel/multithreading-creating-worker-threads.md)  
  
-   [Multithreading: como usar as classes de sincronização](../parallel/multithreading-how-to-use-the-synchronization-classes.md)  
  
-   [Multithreading: encerrando threads](../parallel/multithreading-terminating-threads.md)  
  
-   [Multithreading: dicas de programação](../parallel/multithreading-programming-tips.md)  
  
-   [Multithreading: quando usar as classes de sincronização](../parallel/multithreading-when-to-use-the-synchronization-classes.md)  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de multithreading para código anterior (Visual C++)](../parallel/multithreading-support-for-older-code-visual-cpp.md)