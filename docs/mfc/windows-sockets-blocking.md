---
title: 'Windows Sockets: bloqueando'
ms.date: 11/04/2016
helpviewer_keywords:
- sockets [MFC], blocking mode
- Windows Sockets [MFC], Windows platforms
- Windows Sockets [MFC], blocking mode
- sockets [MFC], behavior on different Windows platforms
- blocking mode sockets
ms.assetid: 10aca9b1-bfba-41a8-9c55-ea8082181e63
ms.openlocfilehash: 87d4f0eb57f9e26dbf73da06b5d7ca6d61d6c174
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359989"
---
# <a name="windows-sockets-blocking"></a>Windows Sockets: bloqueando

Este artigo e dois artigos complementares explicam vários problemas na programação do Windows Sockets. Este artigo abrange o bloqueio. Os outros problemas estão cobertos nos artigos: [Soquetes do Windows: Byte Ordering](../mfc/windows-sockets-byte-ordering.md) e [Soquetes do Windows: Convertendo Cordas](../mfc/windows-sockets-converting-strings.md).

Se você usar ou derivar da classe [CAsyncSocket,](../mfc/reference/casyncsocket-class.md)você precisará gerenciar esses problemas você mesmo. Se você usar ou derivar da classe [CSocket,](../mfc/reference/csocket-class.md)o MFC os gerenciará para você.

## <a name="blocking"></a>Bloqueio

Um soquete pode estar no "modo de bloqueio" ou "modo de não bloqueio". As funções dos soquetes no modo de bloqueio (ou síncrono) não retornam até que possam completar sua ação. Isso é chamado de bloqueio porque o soquete cuja função foi chamada não pode fazer nada — está bloqueado — até que a chamada retorne. Uma chamada `Receive` para a função de membro, por exemplo, pode levar um tempo arbitrariamente longo para ser `CSocket`concluída enquanto aguarda o envio do aplicativo (isto é, se você estiver usando , ou usando `CAsyncSocket` com bloqueio). Se `CAsyncSocket` um objeto estiver no modo de não bloqueio (operando assíncronamente), a chamada retorna imediatamente e o código de erro atual, recuperável com a função de membro [GetLastError,](../mfc/reference/casyncsocket-class.md#getlasterror) é **WSAEWOULDBLOCK**, indicando que a chamada teria bloqueado se não tivesse retornado imediatamente por causa do modo. (`CSocket` nunca retorna **WSAEWOULDBLOCK**. A classe gerencia o bloqueio para você.)

O comportamento dos soquetes é diferente em sistemas operacionais de 32 bits e 64 bits (como windows 95 ou Windows 98) do que em sistemas operacionais de 16 bits (como o Windows 3.1). Ao contrário dos sistemas operacionais de 16 bits, os sistemas operacionais de 32 bits e 64 bits usam multitarefa preventiva e fornecem multithreading. Sob os sistemas operacionais de 32 bits e 64 bits, você pode colocar seus soquetes em roscas separadas do trabalhador. Um soquete em um segmento pode bloquear sem interferir com outras atividades em sua aplicação e sem gastar tempo computacional no bloqueio. Para obter informações sobre programação multithreaded, consulte o artigo [Multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).

> [!NOTE]
> Em aplicativos multithreaded, você pode usar `CSocket` a natureza de bloqueio de simplificar o design do seu programa sem afetar a capacidade de resposta da interface do usuário. Ao manipular as interações do `CSocket` usuário no segmento principal e processar em segmentos alternativos, você pode separar essas operações lógicas. Em um aplicativo que não é multithreaded, essas duas atividades devem ser combinadas e tratadas como um único segmento, o que geralmente significa usar `CAsyncSocket` para que você possa lidar com solicitações de comunicação sob demanda, ou sobrepor `CSocket::OnMessagePending` para lidar com ações do usuário durante atividades síncronas longas.

O resto desta discussão é para programadores que visam sistemas operacionais de 16 bits:

Normalmente, se `CAsyncSocket`você estiver usando, você deve evitar usar operações de bloqueio e operar assíncronamente. Em operações assíncronas, a partir do ponto em que você `Receive`recebe um código de `OnReceive` erro **WSAEWOULDBLOCK** após a chamada, por exemplo, você espera até que sua função de membro seja chamada para notificá-lo que você pode ler novamente. As chamadas assíncronas são feitas chamando de volta a função de notificação de retorno de chamada apropriada do seu soquete, como [onReceive](../mfc/reference/casyncsocket-class.md#onreceive).

No Windows, o bloqueio de chamadas é considerado má prática. Por padrão, [o CAsyncSocket](../mfc/reference/casyncsocket-class.md) suporta chamadas assíncronas e você deve gerenciar o bloqueio sozinho usando notificações de retorno de chamada. Classe [CSocket](../mfc/reference/csocket-class.md), por outro lado, é síncrono. Ele bombeia mensagens do Windows e gerencia o bloqueio para você.

Para obter mais informações sobre o bloqueio, consulte a especificação do Soquetes do Windows. Para obter mais informações sobre as funções "On", consulte [Soquetes do Windows: Notificações do soquete](../mfc/windows-sockets-socket-notifications.md) e [soquetes do Windows: Derivados das classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md).

Para obter mais informações, consulte:

- [Windows Sockets: usando classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)

- [Windows Sockets: plano de fundo](../mfc/windows-sockets-background.md)

- [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Confira também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)<br/>
[CasyncSocket::OnSend](../mfc/reference/casyncsocket-class.md#onsend)
