---
title: "Windows Sockets: derivando de classes de soquete | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes derivadas, a partir de classes de soquete"
  - "soquetes [C++], derivando de classes de soquete"
  - "Windows Sockets [C++], derivando de classes de soquete"
ms.assetid: 3a26e67a-e323-433b-9b05-eca018799801
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Sockets: derivando de classes de soquete
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve algumas das funcionalidades que você pode obter com sua própria classe de uma das classes de soquete.  
  
 Você pode derivar suas próprias classes de soquete de [CAsyncSocket](../Topic/CAsyncSocket%20Class.md) ou de [CSocket](../mfc/reference/csocket-class.md) para adicionar sua própria funcionalidade.  Em particular, essas classes fornecem várias funções de membro virtuais que você pode substituir.  Essas funções incluem [OnReceive](../Topic/CAsyncSocket::OnReceive.md), [OnSend](../Topic/CAsyncSocket::OnSend.md), [OnAccept](../Topic/CAsyncSocket::OnAccept.md), [OnConnect](../Topic/CAsyncSocket::OnConnect.md), e [OnClose](../Topic/CAsyncSocket::OnClose.md).  Você pode substituir as funções em sua classe derivada de soquete para aproveitar as notificações que fornecem quando eventos de rede ocorrem.  A estrutura chama essas funções de retorno de chamada de notificação para notificá\-lo de eventos importantes de soquete, como o recebimento de dados que você pode começar a ler.  Para obter mais informações sobre as funções de notificação, consulte [Soquetes do windows: Notificações de soquete](../Topic/Windows%20Sockets:%20Socket%20Notifications.md).  
  
 Além disso, a classe `CSocket` fornece a função de membro de um [OnMessagePending](../Topic/CSocket::OnMessagePending.md) \(overridable avançada\).  O MFC chamará essa função quando o soquete bombear mensagens baseados no Windows.  Você pode substituir `OnMessagePending` para procurar mensagens específicos do windows e para reagir a elas.  
  
 A versão padrão de `OnMessagePending` fornecidas na classe que `CSocket` examina a fila de mensagem para mensagens de `WM_PAINT` ao esperar uma chamada de bloqueio para concluir.  Despacha mensagens de pintura para melhorar a qualidade da exibição.  Com exceção de fazer algo útil, isso ilustra uma maneira que você pode substituir a função você mesmo.  Como outro exemplo, considere o uso `OnMessagePending` para a tarefa a seguir.  Suponha que o exibir uma caixa de diálogo modeless ao esperar uma transação de rede para concluir.  A caixa de diálogo contém um botão cancelar que o usuário possa usar para cancelar as transações de bloqueio que demora muito.  A substituição de `OnMessagePending` pode bombear mensagens relacionadas a essa caixa de diálogo modeless.  
  
 Na substituição de `OnMessagePending` , retornar **Verdadeiro** ou o retorno de uma chamada à versão da classe base de `OnMessagePending`.  Chame a versão da classe base se executa o trabalho ainda que você deseja fazer.  
  
 Para obter mais informações, consulte:  
  
-   [Soquetes do windows: Usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
-   [Soquetes do windows: Usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
-   [Soquetes do windows: Bloqueio](../Topic/Windows%20Sockets:%20Blocking.md)  
  
-   [Soquetes do windows: A ordenação de bytes](../mfc/windows-sockets-byte-ordering.md)  
  
-   [Soquetes do windows: Convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md)  
  
## Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)