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
ms.openlocfilehash: 0c4f83ccd9bf431f7eb910f77409199da2b1325f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50476096"
---
# <a name="windows-sockets-in-mfc"></a>Windows Sockets em MFC

> [!NOTE]
>  MFC dá suporte ao Windows Sockets 1, mas não suporta [Windows Sockets 2](/windows/desktop/WinSock/windows-sockets-start-page-2). Windows Sockets 2 primeiro fornecido com o Windows 98 e é a versão incluída com o Windows 2000.

MFC fornece dois modelos para escrever programas de comunicações de rede com o Windows Sockets, incorporadas ao duas classes do MFC. Este artigo descreve esses modelos e outros detalhes sobre o MFC de soquetes suporte. Um soquete de"" é um ponto de extremidade de comunicação: um objeto por meio do qual seu aplicativo se comunica com outros aplicativos do Windows Sockets em uma rede.

Para obter informações sobre o Windows Sockets, incluindo uma explicação sobre o conceito de soquete, consulte [Windows Sockets: tela de fundo](../mfc/windows-sockets-background.md).

##  <a name="_core_sockets_programming_models"></a> Modelos de programação de soquetes

Os soquetes do Windows MFC dois modelos de programação têm suporte para as classes a seguir:

- `CAsyncSocket`

   Essa classe encapsula a API do Windows Sockets. [CAsyncSocket](../mfc/reference/casyncsocket-class.md) é para os programadores que conhecer a programação de rede e querem a flexibilidade da programação diretamente para a API do sockets, mas também querem a conveniência de funções de retorno de chamada de notificação de eventos de rede. Diferente de empacotamento de soquetes em forma orientada a objeto para uso em C++, a essa classe fornece apenas adicional de abstração é converter determinadas mensagens do Windows relacionados ao soquete em retornos de chamada. Para obter mais informações, consulte [Windows Sockets: notificações de soquete](../mfc/windows-sockets-socket-notifications.md).

- `CSocket`

   Essa classe, derivada de `CAsyncSocket`, fornece uma abstração de nível superior para trabalhar com soquetes por meio de um MFC [CArchive](../mfc/reference/carchive-class.md) objeto. Usando um soquete com um arquivo morto bastante semelhante usando o protocolo de serialização de arquivo do MFC. Isso torna mais fácil de usar do que o `CAsyncSocket` modelo. [CSocket](../mfc/reference/csocket-class.md) herda muitas funções de membro de `CAsyncSocket` que encapsulam as APIs do Windows Sockets; você terá que usar algumas dessas funções e entender os soquetes de programação em geral. Mas `CSocket` gerencia muitos aspectos da comunicação que teria de fazer por conta própria usando o brutos API ou classe `CAsyncSocket`. Mais importante, `CSocket` fornece o bloqueio (com processamento em segundo plano de mensagens do Windows), que é essencial para a operação síncrona de `CArchive`.

Criando e usando `CSocket` e `CAsyncSocket` objetos é descrito em [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md) e [Windows Sockets: usando classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md).

##  <a name="_core_mfc_socket_samples_and_windows_sockets_dlls"></a> DLLs de soquetes do Windows

Os sistemas operacionais Microsoft Windows fornece as bibliotecas de vínculo dinâmico (DLL) do Windows Sockets. Visual C++ fornece os arquivos de cabeçalho apropriado e bibliotecas e a especificação de soquetes do Windows.

Para obter mais informações sobre o Windows Sockets, consulte:

- [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

- [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)

- [Windows Sockets: sequência de operações](../mfc/windows-sockets-sequence-of-operations.md)

- [Windows Sockets: exemplo de soquetes que usam arquivos mortos](../mfc/windows-sockets-example-of-sockets-using-archives.md)

- [Windows Sockets: como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md)

- [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: derivando de classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)

- [Windows Sockets: notificações de soquete](../mfc/windows-sockets-socket-notifications.md)

- [Windows Sockets: bloqueando](../mfc/windows-sockets-blocking.md)

- [Windows Sockets: ordenação de byte](../mfc/windows-sockets-byte-ordering.md)

- [Windows Sockets: convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md)

- [Windows Sockets: portas e endereços de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets](../mfc/windows-sockets.md)

