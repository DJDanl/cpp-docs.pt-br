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
ms.openlocfilehash: eaf28404b06e9b0bf6126d8bbc140bf46cff37da
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69512015"
---
# <a name="multithreading-with-c-and-mfc"></a>Multithread com C++ e MFC

A biblioteca do Microsoft Foundation Class (MFC) fornece suporte para aplicativos multissegmentados. Este tópico descreve processos e threads e a abordagem do MFC para multithreading.

Um processo é uma instância em execução de um aplicativo. Por exemplo, ao clicar duas vezes no ícone do bloco de notas, você inicia um processo que executa o bloco de notas.

Um thread é um caminho de execução dentro de um processo. Quando você inicia o bloco de notas, o sistema operacional cria um processo e começa a executar o thread principal desse processo. Quando esse thread termina, o processo é encerrado. Esse thread principal é fornecido ao sistema operacional pelo código de inicialização na forma de um endereço de função. Normalmente, é o endereço da `main` função ou `WinMain` fornecida.

Você pode criar threads adicionais em seu aplicativo, se desejar. Talvez você queira fazer isso para lidar com tarefas de experiência em segundo plano ou de manutenção quando não quiser que o usuário aguarde a conclusão. Todos os threads em aplicativos MFC são representados por objetos [CWinThread](../mfc/reference/cwinthread-class.md) . Na maioria das situações, você não precisa nem criar explicitamente esses objetos; em vez disso, chame a função auxiliar de estrutura [AfxBeginThread](../mfc/reference/application-information-and-management.md#afxbeginthread), que cria o objeto `CWinThread` para você.

O MFC distingue dois tipos de threads: threads de interface do usuário e threads de trabalho. Os threads de interface do usuário geralmente são usados para manipular a entrada do usuário e responder a eventos e mensagens gerados pelo usuário. Os threads de trabalho são comumente usados para concluir tarefas, como recálculo, que não exigem entrada do usuário. A API do Win32 não faz distinção entre tipos de threads; Ele só precisa saber o endereço inicial do thread para que ele possa começar a executar o thread. O MFC lida com threads de interface do usuário especialmente fornecendo uma bomba de mensagem para eventos na interface do usuário. `CWinApp`é um exemplo de um objeto de thread de interface do usuário, pois ele deriva `CWinThread` de e manipula eventos e mensagens geradas pelo usuário.

Deve-se receber atenção especial para situações em que mais de um thread pode exigir acesso ao mesmo objeto. [Multithreading: As dicas](multithreading-programming-tips.md) de programação descrevem técnicas que você pode usar para resolver problemas que possam surgir nessas situações. [Multithreading: Como usar as classes](multithreading-how-to-use-the-synchronization-classes.md) de sincronização descreve como usar as classes que estão disponíveis para sincronizar o acesso de vários threads a um único objeto.

Escrever e depurar a programação multi-threaded é inerentemente uma tarefa complicada e complicada, pois você deve garantir que os objetos não sejam acessados por mais de um thread por vez. Os tópicos de multithreading não ensinam os conceitos básicos da programação multithread, apenas como usar o MFC em seu programa multithread. Os exemplos de MFC multithread incluídos no Visual C++ ilustram algumas funcionalidades de adição de multithread e APIs do Win32 não englobadas pelo MFC; no entanto, eles se destinam apenas a ser um ponto de partida.

Para obter mais informações sobre como o sistema operacional lida com processos e threads, consulte [processos e threads](/windows/win32/ProcThread/processes-and-threads) no SDK do Windows.

Para obter mais informações sobre o suporte a multithreading do MFC, consulte os seguintes tópicos:

- [Multithreading: criar threads de interface de usuário](multithreading-creating-user-interface-threads.md)

- [Multithreading: criar threads de trabalho](multithreading-creating-worker-threads.md)

- [Multithreading: como usar as classes de sincronização](multithreading-how-to-use-the-synchronization-classes.md)

- [Multithreading: terminar threads](multithreading-terminating-threads.md)

- [Multithreading: dicas de programação](multithreading-programming-tips.md)

- [Multithreading: quando usar as classes de sincronização](multithreading-when-to-use-the-synchronization-classes.md)

## <a name="see-also"></a>Consulte também

[Suporte de multithreading para código anterior (Visual C++)](multithreading-support-for-older-code-visual-cpp.md)
