---
title: 'Windows Sockets: Derivando de Classes de soquete'
ms.date: 11/04/2016
helpviewer_keywords:
- derived classes [MFC], from socket classes
- Windows Sockets [MFC], deriving from socket classes
- sockets [MFC], deriving from socket classes
ms.assetid: 3a26e67a-e323-433b-9b05-eca018799801
ms.openlocfilehash: 12ab66cfd9212cd79752e2f6359b857194c6428c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385252"
---
# <a name="windows-sockets-deriving-from-socket-classes"></a>Windows Sockets: Derivando de Classes de soquete

Este artigo descreve algumas das funcionalidades que você pode obter, derivando sua própria classe de uma das classes de soquete.

Você pode derivar suas próprias classes de soquete de uma [CAsyncSocket](../mfc/reference/casyncsocket-class.md) ou [CSocket](../mfc/reference/csocket-class.md) para adicionar sua própria funcionalidade. Em particular, essas classes fornecem um número de funções de membro virtual que pode ser substituído. Essas funções incluem [OnReceive](../mfc/reference/casyncsocket-class.md#onreceive), [OnSend](../mfc/reference/casyncsocket-class.md#onsend), [OnAccept](../mfc/reference/casyncsocket-class.md#onaccept), [OnConnect](../mfc/reference/casyncsocket-class.md#onconnect), e [OnClose](../mfc/reference/casyncsocket-class.md#onclose). Você pode substituir as funções em sua classe derivada de soquete para tirar proveito das notificações que eles fornecem quando ocorrem eventos de rede. O framework chama essas funções de retorno de chamada de notificação para notificá-lo de eventos de soquete importantes, como o recebimento de dados que você pode começar a ler. Para obter mais informações sobre funções de notificação, consulte [Windows Sockets: Notificações de soquete](../mfc/windows-sockets-socket-notifications.md).

Além disso, a classe `CSocket` fornece a [OnMessagePending](../mfc/reference/csocket-class.md#onmessagepending) função de membro (um avançado substituível). MFC chama esta função, enquanto o soquete está bombeando mensagens baseadas em Windows. Você pode substituir `OnMessagePending` para localizar mensagens específicas do Windows e respondê-los.

A versão padrão do `OnMessagePending` fornecidos na classe `CSocket` examina a fila de mensagens para mensagens WM_PAINT enquanto aguarda a conclusão de uma chamada de bloqueio. Ele envia mensagens de pintura para melhorar a qualidade do vídeo. Além de fazer algo útil, isso por conta própria ilustra uma maneira que você pode substituir a função. Como outro exemplo, considere o uso de `OnMessagePending` para a tarefa a seguir. Suponha que você exibir uma caixa de diálogo sem janela restrita ao aguardar pela conclusão de uma transação de rede. A caixa de diálogo contém um botão Cancelar que o usuário pode usar para cancelar transações de bloqueio que demoram muito. Seu `OnMessagePending` substituição bomba de mensagens relacionadas a essa caixa de diálogo sem janela restrita.

No seu `OnMessagePending` substituir, retornar um **verdadeira** ou o retorno de uma chamada para a versão da classe base do `OnMessagePending`. Chame a versão da classe base se ela executa o trabalho que você ainda quer feito.

Para obter mais informações, consulte:

- [Windows Sockets: usar soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)

- [Windows Sockets: usar a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: bloquear](../mfc/windows-sockets-blocking.md)

- [Windows Sockets: ordenação da regra](../mfc/windows-sockets-byte-ordering.md)

- [Windows Sockets: converter cadeias de caracteres](../mfc/windows-sockets-converting-strings.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)
