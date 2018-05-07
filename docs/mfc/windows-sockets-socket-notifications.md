---
title: 'Windows Sockets: Notificações de soquete | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Windows Sockets [MFC], notifications
- notifications [MFC], socket
- sockets [MFC], notifications
ms.assetid: 87d5bf70-6e77-49a9-9a64-aaadee2ad018
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b51bf2b562f0d4eff5b9cfef557e62f996d53470
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="windows-sockets-socket-notifications"></a>Windows Sockets: notificações de soquete
Este artigo descreve as funções de notificação em classes de soquete. Essas funções de membro são funções de retorno de chamada que o framework chama para notificar o objeto de soquete de eventos importantes. As funções de notificação são:  
  
-   [OnReceive](../mfc/reference/casyncsocket-class.md#onreceive): notifica esse soquete que há dados no buffer para recuperar chamando [Receive](../mfc/reference/casyncsocket-class.md#receive).  
  
-   [OnSend](../mfc/reference/casyncsocket-class.md#onsend): notifica esse soquete que agora ela pode enviar dados por meio da chamada [enviar](../mfc/reference/casyncsocket-class.md#send).  
  
-   [OnAccept](../mfc/reference/casyncsocket-class.md#onaccept): notifica esse soquete de escuta que ele possa aceitar solicitações de conexão pendentes chamando [aceitar](../mfc/reference/casyncsocket-class.md#accept).  
  
-   [OnConnect](../mfc/reference/casyncsocket-class.md#onconnect): notifica esse soquete de conexão que concluir sua tentativa de conexão: talvez com êxito ou talvez em erro.  
  
-   [OnClose](../mfc/reference/casyncsocket-class.md#onclose): notifica esse soquete que fechou o soquete está conectado ao.  
  
    > [!NOTE]
    >  É uma função de notificação adicional [OnOutOfBandData](../mfc/reference/casyncsocket-class.md#onoutofbanddata). Essa notificação informa o soquete de recebimento que o envio de soquete tem dados de "fora de banda" para enviar. Dados fora de banda são um canal de logicamente independente associado a cada par de soquetes de fluxo conectado. O canal de fora de banda é normalmente usado para enviar dados de "urgentes". MFC dá suporte a dados fora de banda. Trabalhando com a classe de usuários avançados [CAsyncSocket](../mfc/reference/casyncsocket-class.md) talvez seja necessário usar o canal de fora da banda, mas os usuários da classe [CSocket](../mfc/reference/csocket-class.md) são desaconselhável usá-lo. A maneira mais fácil é criar um soquete de segundo para passar esses dados. Para obter mais informações sobre dados fora de banda, consulte a especificação de Windows Sockets, disponível no SDK do Windows.  
  
 Se você derivar da classe `CAsyncSocket`, você deve substituir as funções de notificação para os eventos de interesse para seu aplicativo de rede. Se você derivar uma classe da classe `CSocket`, é de sua escolha se deseja substituir as funções de notificação de interesse. Você também pode usar `CSocket` em si, caso em que a notificação de funções padrão ao fazer nada.  
  
 Essas funções são funções de retorno de chamada substituível. `CAsyncSocket` e `CSocket` converter mensagens para notificações, mas você deve implementar a notificação de funcionamento responder se desejar usá-los. As funções de notificação são chamadas quando que o soquete é notificado de um evento de interesse, como a presença de dados a serem lidos.  
  
 MFC chama as funções de notificação para que você possa personalizar o comportamento do soquete no momento que é notificado. Por exemplo, você pode chamar **Receive** de seu `OnReceive` função de notificação, ou seja, no sendo notificado que não há dados a serem lidos, chamar **Receive** para lê-lo. Essa abordagem não é necessária, mas esse é um cenário válido. Como alternativa, você pode usar a função de notificação para acompanhar o andamento, imprimir **rastreamento** mensagens e assim por diante.  
  
 Você pode tirar proveito dessas notificações, substituindo as funções de notificação em uma classe derivada e fornecendo uma implementação.  
  
 Durante uma operação como receber ou enviar dados, um `CSocket` objeto se torna síncrono. Durante o estado síncrono, as notificações destinam-se para outros soquetes são enfileiradas enquanto aguarda o soquete atual para a notificação que ele deseja. (Por exemplo, durante um **Receive** chamada, o soquete quer uma notificação para leitura.) Depois que o soquete concluirá a operação síncrona e torna-se assíncrona novamente, outros soquetes possam começar a receber as notificações na fila.  
  
> [!NOTE]
>  Em `CSocket`, o `OnConnect` nunca é chamada de função de notificação. Para conexões, você deve chamar **conectar**, que será retornado quando a conexão for concluída (com êxito ou erro). Como são tratadas os notificações de conexão são um detalhe de implementação do MFC.  
  
 Para obter detalhes sobre cada função de notificação, consulte a função na classe `CAsyncSocket` no *referência MFC*. Para informações sobre exemplos MFC e código-fonte, consulte [amostras MFC](../visual-cpp-samples.md).  
  
 Para obter mais informações, consulte:  
  
-   [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
-   [Windows Sockets: derivando de classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)  
  
-   [Windows Sockets: como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md)  
  
-   [Windows Sockets: bloqueando](../mfc/windows-sockets-blocking.md)  
  
-   [Windows Sockets: ordenação de byte](../mfc/windows-sockets-byte-ordering.md)  
  
-   [Windows Sockets: convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)

