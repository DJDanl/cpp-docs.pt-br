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
ms.openlocfilehash: 7e64cc50a121f457b7e32e0ed549db2fa9950843
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619446"
---
# <a name="application-and-thread-support-classes"></a>Classes de aplicativo e suporte de thread

Cada aplicativo tem apenas um objeto de aplicativo; esse objeto coordena outros objetos no programa em execução e é derivado de `CWinApp` .

A biblioteca do MFC (Microsoft Foundation Class) dá suporte a vários threads de execução em um aplicativo. Todos os aplicativos devem ter pelo menos um thread; o thread usado pelo seu `CWinApp` objeto é esse thread principal.

`CWinThread`encapsula uma parte dos recursos de Threading do sistema operacional. Para facilitar o uso de vários threads, o MFC também fornece classes de objeto de sincronização para fornecer uma interface C++ para objetos de sincronização do Win32.

## <a name="application-and-thread-classes"></a>Classes de thread e aplicativo

[CWinApp](reference/cwinapp-class.md)<br/>
Encapsula o código para inicializar, executar e encerrar o aplicativo. Você irá derivar o objeto de aplicativo dessa classe.

[CWinThread](reference/cwinthread-class.md)<br/>
A classe base para todos os threads. Use diretamente ou derive uma classe de `CWinThread` se o thread executar funções de interface do usuário. `CWinApp`é derivado de `CWinThread` .

## <a name="synchronization-object-classes"></a>Classes de objeto de sincronização

[CSyncObject](reference/csyncobject-class.md)<br/>
Classe base das classes de objeto de sincronização.

[CCriticalSection](reference/ccriticalsection-class.md)<br/>
Uma classe de sincronização que permite que apenas um thread em um único processo acesse um objeto.

[CSemaphore](reference/csemaphore-class.md)<br/>
Uma classe de sincronização que permite entre um e um número máximo especificado de acessos simultâneos a um objeto.

[CMutex](reference/cmutex-class.md)<br/>
Uma classe de sincronização que permite que apenas um thread em qualquer número de processos acesse um objeto.

[CEvent](reference/cevent-class.md)<br/>
Uma classe de sincronização que notifica um aplicativo quando um evento ocorreu.

[CSingleLock](reference/csinglelock-class.md)<br/>
Usado em funções de membro de classes thread-safe para bloquear em um objeto de sincronização.

[CMultiLock](reference/cmultilock-class.md)<br/>
Usado em funções de membro de classes thread-safe para bloquear um ou mais objetos de sincronização de uma matriz de objetos de sincronização.

## <a name="related-classes"></a>Classes relacionadas

[CCommandLineInfo](reference/ccommandlineinfo-class.md)<br/>
Analisa a linha de comando com a qual o programa foi iniciado.

[CWaitCursor](reference/cwaitcursor-class.md)<br/>
Coloca um cursor de espera na tela. Usado durante operações demoradas.

[CDockState](reference/cdockstate-class.md)<br/>
Lida com o armazenamento persistente de dados de estado de encaixe para barras de controle.

[CRecentFileList](reference/crecentfilelist-class.md)<br/>
Mantém a lista de arquivos MRU (usados mais recentemente).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
