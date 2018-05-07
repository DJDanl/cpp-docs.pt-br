---
title: Windows Sockets em MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- WINSOCK.DLL
- sockets [MFC], programming models
- MFC, Windows Sockets
- Windows Sockets [MFC], MFC support
- Windows Sockets [MFC], programming models
- WSOCK32.DLL
- sockets [MFC], MFC
ms.assetid: 1f3c476a-9c68-49fe-9a25-d22971a334d0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 84fc25ab6515b22fa647b3cc32833c791b59f2b8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="windows-sockets-in-mfc"></a>Windows Sockets em MFC
> [!NOTE]
>  MFC dá suporte ao Windows Sockets 1, mas não oferece suporte a [Windows Sockets 2](http://msdn.microsoft.com/library/windows/desktop/ms740673). Windows Sockets 2 primeiro fornecido com o Windows 98 e é a versão incluída no Windows 2000.  
  
 MFC fornece dois modelos para escrever programas de comunicações de rede com o Windows Sockets, incorporados em duas classes MFC. Este artigo descreve esses modelos e outros detalhes sobre o MFC soquetes de suporte. Um soquete"" é um ponto de extremidade de comunicação: um objeto por meio do qual seu aplicativo se comunica com outros aplicativos do Windows Sockets por uma rede.  
  
 Para obter informações sobre o Windows Sockets, incluindo uma explicação sobre o conceito de soquete, consulte [Windows Sockets: plano de fundo](../mfc/windows-sockets-background.md).  
  
##  <a name="_core_sockets_programming_models"></a> Modelos de programação de soquetes  
 O Windows Sockets do MFC dois modelos de programação há suporte para as classes a seguir:  
  
-   `CAsyncSocket`  
  
     Essa classe encapsula a API do Windows Sockets. [CAsyncSocket](../mfc/reference/casyncsocket-class.md) é para os programadores que sabe a programação de rede e a flexibilidade de programação diretamente para a API de soquetes mas também evitar a conveniência de funções de retorno de chamada para notificação de eventos de rede. Diferente de empacotamento soquetes na forma orientada a objeto para uso em C++, a abstração adicional somente que essa classe fornece está convertendo determinadas mensagens do Windows relacionados de soquete em retornos de chamada. Para obter mais informações, consulte [Windows Sockets: notificações de soquete](../mfc/windows-sockets-socket-notifications.md).  
  
-   `CSocket`  
  
     Essa classe derivada de `CAsyncSocket`, fornece uma abstração de nível superior para trabalhar com sockets por meio de um MFC [CArchive](../mfc/reference/carchive-class.md) objeto. Usando um soquete com um arquivo morto bastante semelhante usando o protocolo de serialização de arquivo do MFC. Isso torna mais fácil de usar do que o `CAsyncSocket` modelo. [CSocket](../mfc/reference/csocket-class.md) herda muitas funções de membro de `CAsyncSocket` que encapsulam a APIs do Windows Sockets; você terá que usar algumas dessas funções e entender a programação geral de soquetes. Mas `CSocket` gerencia vários aspectos da comunicação que você precisa fazer por conta própria usando o bruto API ou classe `CAsyncSocket`. Mais importante, `CSocket` fornece bloqueio (com processamento em segundo plano das mensagens do Windows), que é essencial para a operação síncrona de `CArchive`.  
  
 Criando e usando `CSocket` e `CAsyncSocket` objetos é descrito na [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md) e [Windows Sockets: usando classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md).  
  
##  <a name="_core_mfc_socket_samples_and_windows_sockets_dlls"></a> DLLs de Windows Sockets  
 Os sistemas operacionais Microsoft Windows fornecem as bibliotecas de vínculo dinâmico (DLL) do Windows Sockets. Visual C++ fornece os arquivos de cabeçalho apropriado e bibliotecas e a especificação de Windows Sockets.  
  
 Para obter mais informações sobre o Windows Sockets, consulte:  
  
-   [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
-   [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
-   [Windows Sockets: sequência de operações](../mfc/windows-sockets-sequence-of-operations.md)  
  
-   [Windows Sockets: exemplo de soquetes que usam arquivos mortos](../mfc/windows-sockets-example-of-sockets-using-archives.md)  
  
-   [Windows Sockets: como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md)  
  
-   [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
-   [Windows Sockets: derivando de classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)  
  
-   [Windows Sockets: notificações de soquete](../mfc/windows-sockets-socket-notifications.md)  
  
-   [Windows Sockets: bloqueando](../mfc/windows-sockets-blocking.md)  
  
-   [Windows Sockets: ordenação de byte](../mfc/windows-sockets-byte-ordering.md)  
  
-   [Windows Sockets: convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md)  
  
-   [Windows Sockets: portas e endereços de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets](../mfc/windows-sockets.md)

