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
ms.openlocfilehash: 7b41f034e08570e418bf24d9d720795eafc37932
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50610568"
---
# <a name="windows-sockets-blocking"></a>Windows Sockets: bloqueando

Este artigo e dois artigos complementares explicam vários problemas na programação do Windows Sockets. Este artigo aborda o bloqueio. Os outros problemas são abordados nos artigos: [Windows Sockets: ordenação de bytes](../mfc/windows-sockets-byte-ordering.md) e [Windows Sockets: Convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md).

Se você usar ou derivar da classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md), você precisará gerenciar esses problemas por conta própria. Se você usar ou derivar da classe [CSocket](../mfc/reference/csocket-class.md), gerencia MFC-los para você.

## <a name="blocking"></a>Bloqueando

Um soquete pode estar em "modo de bloqueio" ou "modo sem bloqueio". As funções do sockets em modo de bloqueio (ou síncrono) não retornam até que eles podem concluir sua ação. Isso é chamado de bloqueio porque o soquete cuja função foi chamada não pode fazer qualquer coisa — é bloqueado — até que a chamada retorne. Uma chamada para o `Receive` função de membro, por exemplo, pode levar um tempo longo arbitrariamente para ser concluído, ele aguarda o aplicativo de envio enviar (Isso é se você estiver usando `CSocket`, ou usando `CAsyncSocket` com o bloqueio). Se um `CAsyncSocket` objeto está no modo sem bloqueio (operação assíncrona), a chamada retorna imediatamente e o código de erro atual, possam ser recuperado com o [GetLastError](../mfc/reference/casyncsocket-class.md#getlasterror) é a função de membro, **WSAEWOULDBLOCK**, indicando que a chamada seria ter bloqueado tinha não retornar imediatamente devido ao modo. (`CSocket` nunca retorna **WSAEWOULDBLOCK**. A classe gerencia o bloqueio para você.)

O comportamento de soquetes é diferente em 32 bits e 64-bit operating systems (por exemplo, Windows 95 ou Windows 98) que em sistemas operacionais de 16 bits (por exemplo, o Windows 3.1). Ao contrário de sistemas operacionais de 16 bits, os sistemas operacionais de 32 bits e 64 bits usar multitarefa preemptiva e fornecer multithreading. Nos sistemas de operacionais de 32 bits e 64 bits, você pode colocar seu soquetes em threads de trabalho separados. Um soquete em um thread pode bloquear sem interferir com outras atividades em seu aplicativo e sem gastar tempo de computação em que o bloqueio. Para obter informações sobre a programação multi-threaded, consulte o artigo [Multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).

> [!NOTE]
>  Em aplicativos multi-threaded, você pode usar a natureza de bloqueio de `CSocket` para simplificar o design do seu programa sem afetar a capacidade de resposta da interface do usuário. Ao manipular interações do usuário no thread principal e `CSocket` processamento nos threads alternativos, você pode separar essas operações lógicas. Em um aplicativo que não é multithreaded, essas duas atividades devem ser combinadas e tratadas como um único thread, que normalmente significa usando `CAsyncSocket` você pode lidar com solicitações de comunicações sob demanda ou substituindo `CSocket::OnMessagePending` para lidar com ações do usuário durante a atividade síncrona longa.

O restante desta discussão é para programadores de sistemas operacionais de 16 bits de destino:

Normalmente, se você estiver usando `CAsyncSocket`, você deve evitar o uso de operações de bloqueio e operar de forma assíncrona em vez disso. Em operações assíncronas, do ponto em que você receber um **WSAEWOULDBLOCK** código de erro depois de chamar `Receive`, por exemplo, aguardar sua `OnReceive` função membro é chamada para notificá-lo de que você pode ler novamente. Chamadas assíncronas são feitas por retornar a chamada função de notificação de retorno de chamada apropriados do seu soquete, tais como [OnReceive](../mfc/reference/casyncsocket-class.md#onreceive).

Sob Windows, chamadas de bloqueio são consideradas uma prática inadequada. Por padrão, [CAsyncSocket](../mfc/reference/casyncsocket-class.md) dá suporte a chamadas e você deve gerenciar o bloqueio por conta própria usando notificações de retorno de chamada. Classe [CSocket](../mfc/reference/csocket-class.md), por outro lado, é síncrona. Ele bombeia mensagens do Windows e gerencia o bloqueio para você.

Para obter mais informações sobre o bloqueio, consulte a especificação de soquetes do Windows. Para obter mais informações sobre "funções de On", consulte [Windows Sockets: notificações de soquete](../mfc/windows-sockets-socket-notifications.md) e [Windows Sockets: derivando de Classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md).

Para obter mais informações, consulte:

- [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)

- [Windows Sockets: tela de fundo](../mfc/windows-sockets-background.md)

- [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)<br/>
[CAsyncSocket::OnSend](../mfc/reference/casyncsocket-class.md#onsend)

