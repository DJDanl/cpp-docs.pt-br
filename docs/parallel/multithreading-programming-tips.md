---
title: 'Multithreading: Dicas de programação do MFC'
ms.date: 08/27/2018
helpviewer_keywords:
- multithreading [C++], programming tips
- handle maps [C++]
- access control [C++], multithreading
- objects [C++], multiple threads and
- non-MFC threads [C++]
- threading [MFC], programming tips
- critical sections [C++]
- synchronization [C++], multithreading
- programming [C++], multithreaded
- communications [C++], between threads
- threading [C++], best practices
- troubleshooting [C++], multithreading
- Windows handle maps [C++]
ms.assetid: ad14cc70-c91c-4c24-942f-13a75e58bf8a
ms.openlocfilehash: deaf53d7b337fd33214bbcc4567e73bd33345d49
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69511719"
---
# <a name="multithreading-mfc-programming-tips"></a>Multithreading: Dicas de programação do MFC

Os aplicativos multissegmentados exigem um cuidado mais rigoroso do que os aplicativos de thread único para garantir que as operações ocorram na ordem pretendida e que todos os dados acessados por vários threads não estejam corrompidos. Este tópico explica técnicas para evitar possíveis problemas ao programar aplicativos multithread com a biblioteca do Microsoft Foundation Class (MFC).

- [Acessando objetos de vários threads](#_core_accessing_objects_from_multiple_threads)

- [Acessando objetos MFC de threads não MFC](#_core_accessing_mfc_objects_from_non.2d.mfc_threads)

- [Mapas de identificadores do Windows](#_core_windows_handle_maps)

- [Comunicação entre threads](#_core_communicating_between_threads)

##  <a name="_core_accessing_objects_from_multiple_threads"></a>Acessando objetos de vários threads

Os objetos MFC não são thread-safe por si só. Dois threads separados não podem manipular o mesmo objeto, a menos que você use as classes de sincronização do MFC e/ou os objetos de sincronização do Win32 apropriados, como seções críticas. Para obter mais informações sobre seções críticas e outros objetos relacionados, consulte [sincronização](/windows/win32/Sync/synchronization) no SDK do Windows.

A biblioteca de classes usa seções críticas internamente para proteger estruturas de dados globais, como as usadas pela alocação de memória de depuração.

##  <a name="_core_accessing_mfc_objects_from_non.2d.mfc_threads"></a>Acessando objetos MFC de threads não MFC

Se você tiver um aplicativo multithread que cria um thread de uma maneira diferente de usar um objeto [CWinThread](../mfc/reference/cwinthread-class.md) , não será possível acessar outros objetos MFC a partir desse thread. Em outras palavras, se você quiser acessar qualquer objeto MFC a partir de um thread secundário, deverá criar esse thread com um dos métodos descritos em [multithreading: Criando threads](multithreading-creating-user-interface-threads.md) de interface do [usuário ou multithreading: Criando threads](multithreading-creating-worker-threads.md)de trabalho. Esses métodos são os únicos que permitem que a biblioteca de classes inicialize as variáveis internas necessárias para lidar com aplicativos multithread.

##  <a name="_core_windows_handle_maps"></a>Mapas de identificadores do Windows

Como regra geral, um thread pode acessar somente objetos MFC que ele criou. Isso ocorre porque os mapas de identificadores temporários e permanentes do Windows são mantidos no armazenamento local de threads para ajudar a manter a proteção contra o acesso simultâneo de vários threads. Por exemplo, um thread de trabalho não pode executar um cálculo e, em seguida `UpdateAllViews` , chamar a função de membro de um documento para ter as janelas que contêm exibições nos novos dados modificados. Isso não tem nenhum efeito, porque o mapa de `CWnd` objetos para HWNDs é local para o thread primário. Isso significa que um thread pode ter um mapeamento de um identificador do Windows para C++ um objeto, mas outro thread pode mapear esse mesmo identificador para C++ um objeto diferente. As alterações feitas em um thread não seriam refletidas no outro.

Há várias maneiras de resolver esse problema. A primeira é passar identificadores individuais (como um HWND) em vez de C++ objetos para o thread de trabalho. Em seguida, o thread de trabalho adiciona esses objetos ao mapa temporário chamando a `FromHandle` função de membro apropriada. Você também pode adicionar o objeto ao mapa permanente do thread chamando `Attach`, mas isso deve ser feito somente se você tiver certeza de que o objeto existirá mais tempo do que o thread.

Outro método é criar novas mensagens definidas pelo usuário correspondentes às diferentes tarefas que seus threads de trabalho executarão e publicar essas mensagens na janela principal do aplicativo usando `::PostMessage`. Esse método de comunicação é semelhante a dois aplicativos diferentes, com a exceção de que ambos os threads estão sendo executados no mesmo espaço de endereço.

Para obter mais informações sobre mapas de identificadores, consulte a [Nota técnica 3](../mfc/tn003-mapping-of-windows-handles-to-objects.md). Para obter mais informações sobre o armazenamento local de thread, consulte [armazenamento local](/windows/win32/ProcThread/thread-local-storage) de thread e [usando o armazenamento local de thread](/windows/win32/ProcThread/using-thread-local-storage) no SDK do Windows.

##  <a name="_core_communicating_between_threads"></a>Comunicação entre threads

O MFC fornece várias classes que permitem que os threads sincronizem o acesso a objetos para manter a segurança do thread. O uso dessas classes é descrito em [multithreading: Como usar as classes](multithreading-how-to-use-the-synchronization-classes.md) de sincronização e [multithreading: Quando usar as classes](multithreading-when-to-use-the-synchronization-classes.md)de sincronização. Para obter mais informações sobre esses objetos, consulte [sincronização](/windows/win32/Sync/synchronization) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md)
