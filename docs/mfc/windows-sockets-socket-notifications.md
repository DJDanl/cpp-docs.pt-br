---
title: 'Windows Sockets: notificações de soquete'
ms.date: 11/04/2016
helpviewer_keywords:
- Windows Sockets [MFC], notifications
- notifications [MFC], socket
- sockets [MFC], notifications
ms.assetid: 87d5bf70-6e77-49a9-9a64-aaadee2ad018
ms.openlocfilehash: 10dbe6c0e1f486257c50efc4acf917cd9d596630
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80167765"
---
# <a name="windows-sockets-socket-notifications"></a>Windows Sockets: notificações de soquete

Este artigo descreve as funções de notificação nas classes Socket. Essas funções de membro são funções de retorno de chamada que a estrutura chama para notificar o objeto de soquete de eventos importantes. As funções de notificação são:

- [OnReceive](../mfc/reference/casyncsocket-class.md#onreceive): notifica esse soquete de que há dados no buffer para que ele seja recuperado chamando [Receive](../mfc/reference/casyncsocket-class.md#receive).

- [OnSend](../mfc/reference/casyncsocket-class.md#onsend): notifica esse soquete de que agora ele pode enviar dados chamando [Send](../mfc/reference/casyncsocket-class.md#send).

- [OnAccept](../mfc/reference/casyncsocket-class.md#onaccept): notifica esse soquete de escuta de que ele pode aceitar solicitações de conexão pendentes chamando [Accept](../mfc/reference/casyncsocket-class.md#accept).

- [OnConnect](../mfc/reference/casyncsocket-class.md#onconnect): notifica esse soquete de conexão de que sua tentativa de conexão foi concluída: Talvez com êxito ou talvez com erro.

- [Fechamento](../mfc/reference/casyncsocket-class.md#onclose): notifica esse soquete de que o soquete ao qual ele está conectado foi fechado.

    > [!NOTE]
    >  Uma função de notificação adicional é [OnOutOfBandData](../mfc/reference/casyncsocket-class.md#onoutofbanddata). Essa notificação informa ao soquete de recebimento que o soquete de envio tem dados "fora de banda" para enviar. Os dados fora de banda são um canal logicamente independente associado a cada par de soquetes de fluxo conectados. O canal fora de banda normalmente é usado para enviar dados "urgentes". O MFC dá suporte a dados fora de banda. Os usuários avançados que trabalham com a classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md) talvez precisem usar o canal fora de banda, mas os usuários da classe [CSocket](../mfc/reference/csocket-class.md) são desencorajados de usá-lo. A maneira mais fácil é criar um segundo soquete para passar esses dados. Para obter mais informações sobre dados fora de banda, consulte a especificação do Windows Sockets, disponível na SDK do Windows.

Se você derivar da classe `CAsyncSocket`, deverá substituir as funções de notificação para os eventos de rede de interesse de seu aplicativo. Se você derivar uma classe da classe `CSocket`, será sua escolha se deseja substituir as funções de notificação de interesse. Você também pode usar `CSocket` si mesmo, caso em que as funções de notificação assumem o padrão de não fazer nada.

Essas funções são funções de retorno de chamada substituíveis. `CAsyncSocket` e `CSocket` converter mensagens em notificações, mas você deve implementar como as funções de notificação respondem se quiser usá-las. As funções de notificação são chamadas no momento em que seu soquete é notificado de um evento de interesse, como a presença de dados a serem lidos.

O MFC chama as funções de notificação para permitir que você personalize o comportamento do soquete no momento em que é notificado. Por exemplo, você pode chamar `Receive` de sua função de notificação de `OnReceive`, ou seja, para ser notificado de que há dados a serem lidos, você chama `Receive` para lê-lo. Essa abordagem não é necessária, mas é um cenário válido. Como alternativa, você pode usar sua função de notificação para acompanhar o progresso, imprimir mensagens de **rastreamento** e assim por diante.

Você pode aproveitar essas notificações substituindo as funções de notificação em uma classe de soquete derivada e fornecendo uma implementação.

Durante uma operação como receber ou enviar dados, um objeto `CSocket` se torna síncrono. Durante o estado síncrono, todas as notificações destinadas a outros soquetes são enfileiradas enquanto o soquete atual aguarda a notificação que deseja. (Por exemplo, durante uma chamada de `Receive`, o soquete quer uma notificação para ler.) Depois que o soquete concluir sua operação síncrona e se tornar assíncrono novamente, outros soquetes poderão começar a receber as notificações em fila.

> [!NOTE]
> No `CSocket`, a função de notificação `OnConnect` nunca é chamada. Para conexões, você chama `Connect`, que retornará quando a conexão for concluída (com êxito ou com erro). Como as notificações de conexão são tratadas é um detalhe de implementação do MFC.

Para obter detalhes sobre cada função de notificação, consulte a função em classe `CAsyncSocket` na *referência do MFC*. Para obter o código-fonte e informações sobre exemplos de MFC, consulte [exemplos de MFC](../overview/visual-cpp-samples.md#mfc-samples).

Para obter mais informações, consulte:

- [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: derivando de classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)

- [Windows Sockets: como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md)

- [Windows Sockets: bloqueando](../mfc/windows-sockets-blocking.md)

- [Windows Sockets: ordenação de byte](../mfc/windows-sockets-byte-ordering.md)

- [Windows Sockets: convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md)

## <a name="see-also"></a>Confira também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)
