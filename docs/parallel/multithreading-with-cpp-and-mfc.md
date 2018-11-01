---
title: Multithread com C++ e MFC
ms.date: 08/27/2018
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
ms.openlocfilehash: c707c1c117bbc0005b2b3da4ed39f083ae407b27
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50643411"
---
# <a name="multithreading-with-c-and-mfc"></a>Multithread com C++ e MFC

A biblioteca Microsoft Foundation Class (MFC) fornece suporte para aplicativos multithread. Este tópico descreve os processos e threads e a abordagem MFC para multithreading.

Um processo é uma instância de um aplicativo em execução. Por exemplo, quando você clica duas vezes no ícone do bloco de notas, você inicia um processo que executa o bloco de notas.

Um thread é um caminho de execução dentro de um processo. Quando você inicia o bloco de notas, o sistema operacional cria um processo e começa a executar o thread primário desse processo. Quando esse thread é encerrado, portanto, não o processo. Esse thread principal é fornecido para o sistema operacional pelo código de inicialização na forma de um endereço de função. Geralmente, ele é o endereço do `main` ou `WinMain` função que é fornecida.

Você pode criar threads adicionais em seu aplicativo, se você quiser. Você talvez queira fazer isso para lidar com tarefas de manutenção ou em segundo plano quando você não deseja que o usuário a aguardar para que elas sejam concluídas. Todos os threads em aplicativos MFC são representados por [CWinThread](../mfc/reference/cwinthread-class.md) objetos. Na maioria das situações, você ainda precisa criar explicitamente esses objetos. em vez disso, chame a função de auxiliar de estrutura [AfxBeginThread](../mfc/reference/application-information-and-management.md#afxbeginthread), que cria o `CWinThread` objeto para você.

MFC distingue dois tipos de threads: threads de interface do usuário e threads de trabalho. Threads de interface do usuário são usadas para manipular a entrada do usuário e responder a eventos e mensagens gerados pelo usuário. Threads de trabalho são usados para concluir tarefas, como o recálculo, que não exigem a entrada do usuário. A API do Win32 não faz distinção entre tipos de threads; Ele apenas precisa saber o endereço inicial do thread para poder começar a executar o thread. MFC manipula os threads de interface do usuário especialmente fornecendo uma bomba de mensagens para eventos na interface do usuário. `CWinApp` é um exemplo de um objeto de thread de interface do usuário, pois ele é derivado de `CWinThread` e manipula eventos e mensagens gerados pelo usuário.

Deve ser dada atenção especial às situações onde mais de um thread pode exigir acesso ao mesmo objeto. [Multithreading: Dicas de programação](multithreading-programming-tips.md) descreve técnicas que você pode usar para resolver problemas que podem ocorrer nessas situações. [Multithreading: Como usar as Classes de sincronização](multithreading-how-to-use-the-synchronization-classes.md) descreve como usar as classes que estão disponíveis para sincronizar o acesso de vários threads a um único objeto.

Escrever e depurar a programação multi-threaded de é inerentemente uma tarefa complicada e difícil, porque você deve garantir que objetos não são acessados por mais de um thread por vez. Os tópicos de multithreading não ensinam as Noções básicas de programação multithreaded, só como usar MFC em seu programa multithreaded. Os exemplos multithreaded do MFC incluídos no Visual C++ ilustram alguns multithreaded de adição de funcionalidade e as APIs do Win32 não englobadas pelo MFC; No entanto, eles só devem ser um ponto de partida.

Para obter mais informações sobre como o sistema operacional trata processos e threads, consulte [processos e Threads](/windows/desktop/ProcThread/processes-and-threads) no SDK do Windows.

Para obter mais informações sobre suporte multithreading MFC, consulte os tópicos a seguir:

- [Multithreading: criando threads da interface do usuário](multithreading-creating-user-interface-threads.md)

- [Multithreading: criando threads de trabalho](multithreading-creating-worker-threads.md)

- [Multithreading: como usar as classes de sincronização](multithreading-how-to-use-the-synchronization-classes.md)

- [Multithreading: encerrando threads](multithreading-terminating-threads.md)

- [Multithreading: dicas de programação](multithreading-programming-tips.md)

- [Multithreading: quando usar as classes de sincronização](multithreading-when-to-use-the-synchronization-classes.md)

## <a name="see-also"></a>Consulte também

[Suporte de multithreading para código anterior (Visual C++)](multithreading-support-for-older-code-visual-cpp.md)