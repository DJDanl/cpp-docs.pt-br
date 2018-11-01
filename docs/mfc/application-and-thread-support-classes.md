---
title: Classes de aplicativo e suporte de thread
ms.date: 11/04/2016
f1_keywords:
- vc.classes.support
helpviewer_keywords:
- application objects [MFC], thread support classes
- lock classes [MFC]
- thread support classes [MFC]
- threading [MFC]
- synchronization classes [MFC], multithreading
- application support classes [MFC]
ms.assetid: 3c1d14fd-c35c-48f1-86ce-1e0f9a32c36d
ms.openlocfilehash: 5f69ea6a87d0e1ae16a6079a414d623af6dd88fc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50496247"
---
# <a name="application-and-thread-support-classes"></a>Classes de aplicativo e suporte de thread

Cada aplicativo tem apenas um objeto de aplicativo; Esse objeto coordena a outros objetos no programa em execução e é derivado de `CWinApp`.

A biblioteca Microsoft Foundation Class (MFC) oferece suporte a vários threads de execução dentro de um aplicativo. Todos os aplicativos devem ter pelo menos um thread; o thread usado pelo seu `CWinApp` objeto é esse thread principal.

`CWinThread` encapsula uma parte dos recursos de threading do sistema operacional. Para tornar o uso de vários threads, MFC também fornece sincronização de objetos para fornecer uma interface de C++ para objetos de sincronização do Win32.

## <a name="application-and-thread-classes"></a>Classes de aplicativo e Thread

[CWinApp](../mfc/reference/cwinapp-class.md)<br/>
Encapsula o código para inicializar, executar e encerrar o aplicativo. O objeto de aplicativo será derivar dessa classe.

[CWinThread](../mfc/reference/cwinthread-class.md)<br/>
A classe base para todos os threads. Use diretamente, ou derivar uma classe de `CWinThread` se o thread executa funções de interface do usuário. `CWinApp` é derivado de `CWinThread`.

## <a name="synchronization-object-classes"></a>Classes de objeto de sincronização

[CSyncObject](../mfc/reference/csyncobject-class.md)<br/>
Classe base das classes de objeto de sincronização.

[CCriticalSection](../mfc/reference/ccriticalsection-class.md)<br/>
Uma classe de sincronização que permite que apenas um thread em um único processo para acessar um objeto.

[CSemaphore](../mfc/reference/csemaphore-class.md)<br/>
Uma classe de sincronização que permite entre um e um número máximo especificado de acessos simultâneos para um objeto.

[CMutex](../mfc/reference/cmutex-class.md)<br/>
Uma classe de sincronização que permite que apenas um thread em qualquer número de processos para acessar um objeto.

[CEvent](../mfc/reference/cevent-class.md)<br/>
Uma classe de sincronização que notifica um aplicativo quando um evento ocorreu.

[CSingleLock](../mfc/reference/csinglelock-class.md)<br/>
Usado em funções de membro de classes thread-safe para bloquear em um objeto de sincronização.

[CMultiLock](../mfc/reference/cmultilock-class.md)<br/>
Usado em funções de membro de classes thread-safe para bloquear um ou mais objetos de sincronização de uma matriz de objetos de sincronização.

## <a name="related-classes"></a>Classes relacionadas

[CCommandLineInfo](../mfc/reference/ccommandlineinfo-class.md)<br/>
Analisa a linha de comando com a qual o programa foi iniciado.

[CWaitCursor](../mfc/reference/cwaitcursor-class.md)<br/>
Coloca um cursor de espera na tela. Usado durante operações demoradas.

[CDockState](../mfc/reference/cdockstate-class.md)<br/>
Lida com armazenamento persistente de dados de estado para barras de controle de encaixe.

[CRecentFileList](../mfc/reference/crecentfilelist-class.md)<br/>
Mantém a lista de arquivos (MRU) usado com o mais recentemente.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

