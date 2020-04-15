---
title: Windows Sockets em MFC
ms.date: 11/04/2016
helpviewer_keywords:
- WINSOCK.DLL
- sockets [MFC], programming models
- MFC, Windows Sockets
- Windows Sockets [MFC], MFC support
- Windows Sockets [MFC], programming models
- WSOCK32.DLL
- sockets [MFC], MFC
ms.assetid: 1f3c476a-9c68-49fe-9a25-d22971a334d0
ms.openlocfilehash: 8e5562b028d3d9b7cba4b47716b63fd1392c514f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371090"
---
# <a name="windows-sockets-in-mfc"></a>Windows Sockets em MFC

> [!NOTE]
> O MFC suporta soquetes do Windows 1, mas não suporta [soquetes do Windows 2](/windows/win32/WinSock/windows-sockets-start-page-2). Windows Sockets 2 primeiro enviado com windows 98 e é a versão incluída com o Windows 2000.

A MFC fornece dois modelos para escrever programas de comunicação de rede com soquetes de windows, incorporados em duas classes de MFC. Este artigo descreve esses modelos e detalha ainda mais o suporte a tomadas MFC. Um "soquete" é um ponto final de comunicação: um objeto através do qual seu aplicativo se comunica com outros aplicativos do Windows Sockets através de uma rede.

Para obter informações sobre soquetes do Windows, incluindo uma explicação do conceito do soquete, consulte [Soquetes do Windows: Fundo](../mfc/windows-sockets-background.md).

## <a name="sockets-programming-models"></a><a name="_core_sockets_programming_models"></a>Modelos de programação de soquetes

Os dois modelos de programação do MFC Windows Sockets são suportados pelas seguintes classes:

- `CAsyncSocket`

   Esta classe encapsula a API do Windows Sockets. [CAsyncSocket](../mfc/reference/casyncsocket-class.md) é para programadores que conhecem programação de rede e querem a flexibilidade da programação diretamente para a API dos soquetes, mas também querem a conveniência das funções de retorno de chamada para notificação de eventos de rede. Além dos soquetes de embalagem em forma orientada a objetos para uso em C++, a única abstração adicional que esta classe fornece é converter certas mensagens do Windows relacionadas ao soquete em retornos de chamada. Para obter mais informações, consulte [Soquetes do Windows: Notificações do soquete](../mfc/windows-sockets-socket-notifications.md).

- `CSocket`

   Esta classe, derivada de `CAsyncSocket`, fornece uma abstração de nível mais alto para trabalhar com soquetes através de um objeto MFC [CArchive.](../mfc/reference/carchive-class.md) Usar um soquete com um arquivo se assemelha muito ao uso do protocolo de serialização de arquivos do MFC. Isso torna mais fácil `CAsyncSocket` de usar do que o modelo. [O CSocket](../mfc/reference/csocket-class.md) herda muitas `CAsyncSocket` funções de membros a partir desse encapsulamento de APIs de soquetes do Windows; você terá que usar algumas dessas funções e entender a programação de soquetes em geral. Mas `CSocket` gerencia muitos aspectos da comunicação que você teria que fazer usando `CAsyncSocket`a API ou classe crua. Mais importante, `CSocket` fornece o bloqueio (com o processamento em segundo plano de `CArchive`mensagens do Windows), o que é essencial para a operação síncrona de .

Criar e `CSocket` `CAsyncSocket` usar e objetos é descrito em [Soquetes do Windows: Usando soquetes com arquivos](../mfc/windows-sockets-using-sockets-with-archives.md) e [soquetes do Windows: Usando classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md).

## <a name="windows-sockets-dlls"></a><a name="_core_mfc_socket_samples_and_windows_sockets_dlls"></a>DLLs de soquetes do Windows

Os sistemas operacionais Microsoft Windows fornecem as bibliotecas de link dinâmico (DLL) do Windows Sockets. O Visual C++ fornece os arquivos e bibliotecas de cabeçalho apropriados e a especificação do Windows Sockets.

Para obter mais informações sobre soquetes do Windows, consulte:

- [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

- [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)

- [Windows Sockets: sequência de operações](../mfc/windows-sockets-sequence-of-operations.md)

- [Windows Sockets: exemplo de soquetes que usam arquivos mortos](../mfc/windows-sockets-example-of-sockets-using-archives.md)

- [Windows Sockets: como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md)

- [Windows Sockets: usando classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: derivando de classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)

- [Windows Sockets: notificações de soquete](../mfc/windows-sockets-socket-notifications.md)

- [Windows Sockets: bloqueando](../mfc/windows-sockets-blocking.md)

- [Windows Sockets: ordenação de bytes](../mfc/windows-sockets-byte-ordering.md)

- [Windows Sockets: convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md)

- [Windows Sockets: portas e endereços de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md)

## <a name="see-also"></a>Confira também

[Soquetes do Windows](../mfc/windows-sockets.md)
