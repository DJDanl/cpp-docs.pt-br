---
title: 'Windows Sockets: Notificações de soquete'
ms.date: 11/04/2016
helpviewer_keywords:
- Windows Sockets [MFC], notifications
- notifications [MFC], socket
- sockets [MFC], notifications
ms.assetid: 87d5bf70-6e77-49a9-9a64-aaadee2ad018
ms.openlocfilehash: c08305b8aeeca00eaf41e4f1c24b51a46a8c4254
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57289904"
---
# <a name="windows-sockets-socket-notifications"></a>Windows Sockets: Notificações de soquete

Este artigo descreve as funções de notificação nas classes de soquete. Essas funções de membro são funções de retorno de chamada que o framework chama para notificar o objeto de soquete de eventos importantes. As funções de notificação são:

- [OnReceive](../mfc/reference/casyncsocket-class.md#onreceive): Notifica o soquete que há dados no buffer para que ele recupere chamando [Receive](../mfc/reference/casyncsocket-class.md#receive).

- [OnSend](../mfc/reference/casyncsocket-class.md#onsend): Notifica o soquete que agora ele pode enviar dados por meio da chamada [enviar](../mfc/reference/casyncsocket-class.md#send).

- [OnAccept](../mfc/reference/casyncsocket-class.md#onaccept): Notifica este soquete de escuta que ele pode aceitar solicitações de conexão pendentes chamando [Accept](../mfc/reference/casyncsocket-class.md#accept).

- [OnConnect](../mfc/reference/casyncsocket-class.md#onconnect): Notifica o soquete de conexão concluir sua tentativa de conexão: talvez com êxito ou talvez em erro.

- [OnClose](../mfc/reference/casyncsocket-class.md#onclose): Notifica o soquete que fechou o soquete que ele está conectado a.

    > [!NOTE]
    >  É uma função de notificação adicional [OnOutOfBandData](../mfc/reference/casyncsocket-class.md#onoutofbanddata). Essa notificação informa o soquete de recebimento que o envio de soquete tem dados de "out-of-band" para enviar. Dados fora de banda são um canal de logicamente independente associado com cada par de soquetes de fluxo conectado. O canal de out-of-band normalmente é usado para enviar dados "urgentes". MFC dá suporte a dados fora de banda. Trabalhando com a classe de usuários avançados [CAsyncSocket](../mfc/reference/casyncsocket-class.md) talvez seja necessário usar o canal de out-of-band, mas os usuários da classe [CSocket](../mfc/reference/csocket-class.md) desaconselhável de usá-lo. A maneira mais fácil é criar um soquete de segundo para passar esses dados. Para obter mais informações sobre dados out-of-band, consulte a especificação de soquetes do Windows, disponível no SDK do Windows.

Se você derivar da classe `CAsyncSocket`, você deve substituir as funções de notificação para os eventos de interesse para seu aplicativo de rede. Se você derivar uma classe da classe `CSocket`, é sua escolha se deseja substituir as funções de notificação de interesse. Você também pode usar `CSocket` em si, caso em que a notificação de funções padrão para fazer nada.

Essas funções são funções de retorno de chamada substituível. `CAsyncSocket` e `CSocket` converter mensagens para enviar notificações, mas você deve implementar a notificação de funcionamento responder se você quiser usá-los. As funções de notificação são chamadas no momento em que o soquete é notificado de um evento de interesse, como a presença de dados a serem lidos.

MFC chama as funções de notificação para permitir que você personalize o comportamento do seu soquete no momento em que ele é notificado. Por exemplo, você pode chamar `Receive` de seu `OnReceive` função de notificação, ou seja, em sendo notificado de que há dados a serem lidos, se você chamar `Receive` para lê-lo. Essa abordagem não é necessária, mas ele é um cenário válido. Como alternativa, você pode usar a função de notificação para acompanhar o andamento, imprima **rastreamento** mensagens e assim por diante.

Você pode tirar proveito dessas notificações, substituindo as funções de notificação em uma classe derivada de soquete e fornecendo uma implementação.

Durante uma operação, como recebimento ou envio de dados, um `CSocket` objeto se torna síncrono. Durante o estado síncrono, todas as notificações para outros soquetes são enfileiradas enquanto o soquete atual aguarda a notificação de que ele deseja. (Por exemplo, durante um `Receive` chamada, o soquete quer uma notificação para leitura.) Depois que o soquete conclui sua operação síncrona e se torna assíncrono novamente, outros soquetes podem começar a receber as notificações na fila.

> [!NOTE]
>  Na `CSocket`, o `OnConnect` nunca é chamada de função de notificação. Para conexões, você deve chamar `Connect`, que retornará quando a conexão for concluída (com êxito ou erro). Como as notificações de conexão são tratadas é um detalhe de implementação do MFC.

Para obter detalhes sobre cada função de notificação, consulte a função na classe `CAsyncSocket` no *referência da MFC*. Para o código-fonte e informações sobre exemplos de MFC, consulte [exemplos de MFC](../visual-cpp-samples.md).

Para obter mais informações, consulte:

- [Windows Sockets: Usando classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: Derivando de Classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)

- [Windows Sockets: Como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md)

- [Windows Sockets: Bloqueando](../mfc/windows-sockets-blocking.md)

- [Windows Sockets: A ordem de bytes](../mfc/windows-sockets-byte-ordering.md)

- [Windows Sockets: Convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)
