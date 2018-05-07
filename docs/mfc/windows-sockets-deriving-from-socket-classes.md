---
title: 'Windows Sockets: Derivando de Classes de soquete | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- derived classes [MFC], from socket classes
- Windows Sockets [MFC], deriving from socket classes
- sockets [MFC], deriving from socket classes
ms.assetid: 3a26e67a-e323-433b-9b05-eca018799801
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 64fb9a3ff1c27aade9f74a8ed95a8016829874ab
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="windows-sockets-deriving-from-socket-classes"></a>Windows Sockets: derivando de classes de soquete
Este artigo descreve algumas das funcionalidades que você pode obter derivando sua própria classe de uma das classes de soquete.  
  
 Você pode derivar suas próprias classes de soquete do [CAsyncSocket](../mfc/reference/casyncsocket-class.md) ou [CSocket](../mfc/reference/csocket-class.md) para adicionar sua própria funcionalidade. Em particular, essas classes fornecem um número de funções de membro virtual que você pode substituir. Essas funções incluem [OnReceive](../mfc/reference/casyncsocket-class.md#onreceive), [OnSend](../mfc/reference/casyncsocket-class.md#onsend), [OnAccept](../mfc/reference/casyncsocket-class.md#onaccept), [OnConnect](../mfc/reference/casyncsocket-class.md#onconnect), e [OnClose](../mfc/reference/casyncsocket-class.md#onclose). Você pode substituir as funções em sua classe derivada de soquete para tirar proveito das notificações fornecerem quando ocorrem eventos de rede. O framework chama essas funções de retorno de chamada de notificação para receber notificações de eventos de soquete importantes, como o recebimento de dados que você pode começar a ler. Para obter mais informações sobre funções de notificação, consulte [Windows Sockets: notificações de soquete](../mfc/windows-sockets-socket-notifications.md).  
  
 Além disso, a classe `CSocket` fornece o [OnMessagePending](../mfc/reference/csocket-class.md#onmessagepending) função de membro (um avançado substituível). MFC chama esta função enquanto o soquete é bombeando mensagens de baseado no Windows. Você pode substituir `OnMessagePending` para pesquisar mensagens específicas do Windows e responder a eles.  
  
 A versão padrão do `OnMessagePending` fornecido na classe `CSocket` examina a fila de mensagens para `WM_PAINT` mensagens ao aguardar uma chamada de bloqueio concluir. Ele envia mensagens de pintura para melhorar a qualidade do vídeo. Além de fazer algo útil, isso por conta própria ilustra uma maneira que você pode substituir a função. Como outro exemplo, considere o uso de `OnMessagePending` para a tarefa a seguir. Suponha que você exibir uma caixa de diálogo sem janela restrita ao aguardar uma transação de rede concluir. A caixa de diálogo contém um botão de cancelamento que o usuário pode usar para cancelar transações de bloqueio que levarem muito tempo. O `OnMessagePending` substituição bomba de mensagens relacionadas à caixa de diálogo sem janela restrita.  
  
 No seu `OnMessagePending` substituir, retornar **TRUE** ou o retorno de uma chamada para a versão da classe base do `OnMessagePending`. Chame a versão da classe de base se ela executa o trabalho que deseja continuar.  
  
 Para obter mais informações, consulte:  
  
-   [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
-   [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
-   [Windows Sockets: bloqueando](../mfc/windows-sockets-blocking.md)  
  
-   [Windows Sockets: ordenação de byte](../mfc/windows-sockets-byte-ordering.md)  
  
-   [Windows Sockets: convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)

