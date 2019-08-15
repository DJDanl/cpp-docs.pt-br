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
ms.openlocfilehash: 44a4838a1cd863bd484701966a156be9f61f8988
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69510619"
---
# <a name="windows-sockets-in-mfc"></a>Windows Sockets em MFC

> [!NOTE]
>  O MFC dá suporte ao Windows Sockets 1, mas não dá suporte ao [Windows Sockets 2](/windows/win32/WinSock/windows-sockets-start-page-2). O Windows Sockets 2 foi fornecido pela primeira vez com o Windows 98 e é a versão incluída no Windows 2000.

O MFC fornece dois modelos para escrever programas de comunicação de rede com o Windows Sockets, incorporados em duas classes MFC. Este artigo descreve esses modelos e mais detalhes sobre o suporte a soquetes MFC. Um "soquete" é um ponto de extremidade de comunicação: um objeto pelo qual seu aplicativo se comunica com outros aplicativos do Windows Sockets em uma rede.

Para obter informações sobre o Windows Sockets, incluindo uma explicação do conceito de [soquete, consulte Windows Sockets: Plano](../mfc/windows-sockets-background.md)de fundo.

##  <a name="_core_sockets_programming_models"></a>Modelos de programação de soquetes

Os dois modelos de programação do Windows Sockets do MFC têm suporte nas seguintes classes:

- `CAsyncSocket`

   Essa classe encapsula a API do Windows Sockets. [CAsyncSocket](../mfc/reference/casyncsocket-class.md) é para programadores que conhecem a programação de rede e desejam a flexibilidade de programação diretamente para a API de soquetes, mas também querem a conveniência das funções de retorno de chamada para notificação de eventos de rede. Além dos soquetes de empacotamento na forma orientada a C++objeto para uso no, a única abstração adicional que essa classe fornece é converter determinadas mensagens do Windows relacionadas ao soquete em retornos de chamada. Para obter mais informações, [consulte Windows Sockets: Notificações](../mfc/windows-sockets-socket-notifications.md)de soquete.

- `CSocket`

   Essa classe, derivada de `CAsyncSocket`, fornece uma abstração de nível superior para trabalhar com soquetes por meio de um objeto MFC [CArchive](../mfc/reference/carchive-class.md) . O uso de um soquete com um arquivo se assemelha muito ao uso do protocolo de serialização de arquivos do MFC. Isso torna mais fácil usar do que o `CAsyncSocket` modelo. O [CSocket](../mfc/reference/csocket-class.md) herda muitas funções de `CAsyncSocket` membro do que encapsulam as APIs do Windows Sockets; você precisará usar algumas dessas funções e entender a programação de soquetes em geral. Mas `CSocket` gerencia muitos aspectos da comunicação que você teria que fazer por conta própria usando a API ou a classe `CAsyncSocket`bruta. O mais importante `CSocket` é que o fornece bloqueio (com processamento em segundo plano de mensagens do Windows), que é `CArchive`essencial para a operação síncrona do.

A criação e `CSocket` o `CAsyncSocket` uso de objetos e [são descritos em Windows Sockets: Usando soquetes com](../mfc/windows-sockets-using-sockets-with-archives.md) arquivos [e Windows Sockets: Usando a classe](../mfc/windows-sockets-using-class-casyncsocket.md)CAsyncSocket.

##  <a name="_core_mfc_socket_samples_and_windows_sockets_dlls"></a>DLLs do Windows Sockets

Os sistemas operacionais Microsoft Windows fornecem as bibliotecas de vínculo dinâmico (DLL) do Windows Sockets. O C++ Visual fornece os arquivos de cabeçalho e as bibliotecas apropriados e a especificação do Windows Sockets.

Para obter mais informações sobre o Windows Sockets, consulte:

- [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

- [Windows Sockets: usar soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)

- [Windows Sockets: sequência de operações](../mfc/windows-sockets-sequence-of-operations.md)

- [Windows Sockets: exemplo de soquetes que usam arquivos mortos](../mfc/windows-sockets-example-of-sockets-using-archives.md)

- [Windows Sockets: como soquetes com arquivos mortos funcionam](../mfc/windows-sockets-how-sockets-with-archives-work.md)

- [Windows Sockets: usar a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: derivar de classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)

- [Windows Sockets: notificações de soquetes](../mfc/windows-sockets-socket-notifications.md)

- [Windows Sockets: bloquear](../mfc/windows-sockets-blocking.md)

- [Windows Sockets: ordenação da regra](../mfc/windows-sockets-byte-ordering.md)

- [Windows Sockets: converter cadeias de caracteres](../mfc/windows-sockets-converting-strings.md)

- [Windows Sockets: portas e endereços de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets](../mfc/windows-sockets.md)
