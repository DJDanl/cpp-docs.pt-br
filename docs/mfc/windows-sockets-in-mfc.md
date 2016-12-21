---
title: "Windows Sockets em MFC | Microsoft Docs"
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
  - "MFC [C++], Windows Sockets"
  - "soquetes [C++], MFC"
  - "soquetes [C++], modelos de programação"
  - "Windows Sockets [C++], Suporte MFC"
  - "Windows Sockets [C++], modelos de programação"
  - "WINSOCK.DLL"
  - "WSOCK32.DLL"
ms.assetid: 1f3c476a-9c68-49fe-9a25-d22971a334d0
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Sockets em MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Soquetes 1 do windows da suporte MFC mas não dão suporte a [2 Soquetes do windows](http://msdn.microsoft.com/library/windows/desktop/ms740673).  Soquetes 2 do windows enviados primeiro com o Windows 98 e é a versão do incluída com o Windows 2000.  
  
 MFC O fornece dois modelos para escrever programas de comunicações de rede com soquetes do windows, personificados em duas classes MFC.  Este artigo descreve esses modelos e suporte adicional de soquetes MFC de detalhes.  Um soquete “” é um ponto de extremidade de comunicação: um objeto através do seu aplicativo se comunica com outros aplicativos de soquetes do windows por uma rede.  
  
 Para obter informações sobre os soquetes do windows, incluindo uma explicação do conceito de soquete, consulte [Soquetes do windows: Plano de fundo](../mfc/windows-sockets-background.md).  
  
##  <a name="_core_sockets_programming_models"></a> Soquetes de programação modelos  
 Os dois soquetes do windows MFC de programação modelos são suportados pela classes a seguir:  
  
-   `CAsyncSocket`  
  
     Essa classe encapsula soquetes apis do windows.  [CAsyncSocket](../Topic/CAsyncSocket%20Class.md) é para programadores que conhecem a programação de rede e querem a flexibilidade de programação diretamente aos soquetes API mas deseja conveniência de funções de retorno de chamada para a notificação de eventos de rede.  Diferente de soquetes no formato orientado a objeto para uso em C\+\+, a única abstração adicional que esta classe fornece estiver convertendo algumas mensagens soquete\- relacionados do windows em retornos de chamada.  Para obter mais informações, consulte [Soquetes do windows: Notificações de soquete](../Topic/Windows%20Sockets:%20Socket%20Notifications.md).  
  
-   `CSocket`  
  
     Essa classe derivada, fontes de `CAsyncSocket`, uma abstração de alto nível para trabalhar com soquetes por meio de um objeto MFC [CArchive](../mfc/reference/carchive-class.md) .  Usar um soquete com um arquivo morto se assemelha muito usando o protocolo de serialização do arquivo MFC.  Isso torna mais fácil o uso do modelo de `CAsyncSocket` .  [CSocket](../mfc/reference/csocket-class.md) herda as muitas funções de membro de `CAsyncSocket` que encapsulam APIs de soquetes do windows; você terá que usar algumas dessas funções e entender os soquetes de programação geral.  Mas `CSocket` gerencia muitos aspectos da comunicação que você teria que se tornar usando a API bruto ou classificar `CAsyncSocket`.  Ainda mais importante, `CSocket` fornece o bloqueio \(com o processamento em segundo plano de mensagens do windows\), que é essencial para a operação síncrona de `CArchive`.  
  
 Criar e usar `CSocket` e objetos de `CAsyncSocket` são descritas em [Soquetes do windows: Usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md) e em [Soquetes do windows: Usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md).  
  
##  <a name="_core_mfc_socket_samples_and_windows_sockets_dlls"></a> DLL de soquetes do windows  
 Os sistemas operacionais Microsoft Windows \(DLL\) fornecem as bibliotecas de vínculo dinâmico\) nativa de soquetes do windows.  Visual C\+\+ fornece os arquivos de cabeçalho e bibliotecas apropriadas e a especificação de soquetes do windows.  
  
> [!NOTE]
>  No Windows NT e o Windows 2000, o suporte de soquetes do windows para aplicativos de 16 bits é baseado em WINSOCK.DLL.  Para aplicativos de 32 bits, o suporte está em WSOCK32.DLL.  As APIs fornecidas são idênticos exceto que as versões de 32 bits com parâmetros alargadas a 32 bits.  No Win32, a segurança de thread é fornecida.  
  
 Para obter mais informações sobre os soquetes do windows, consulte:  
  
-   [Soquetes do windows: Soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Soquetes do windows: Soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
-   [Soquetes do windows: Usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
-   [Soquetes do windows: Sequência de operações](../Topic/Windows%20Sockets:%20Sequence%20of%20Operations.md)  
  
-   [Soquetes do windows: Exemplo de soquetes usando arquivos mortos](../mfc/windows-sockets-example-of-sockets-using-archives.md)  
  
-   [Soquetes do windows: Como os soquetes com arquivos mortos funcionam](../mfc/windows-sockets-how-sockets-with-archives-work.md)  
  
-   [Soquetes do windows: Usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
-   [Soquetes do windows: Derivação das classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)  
  
-   [Soquetes do windows: Notificações de soquete](../Topic/Windows%20Sockets:%20Socket%20Notifications.md)  
  
-   [Soquetes do windows: Bloqueio](../Topic/Windows%20Sockets:%20Blocking.md)  
  
-   [Soquetes do windows: A ordenação de bytes](../mfc/windows-sockets-byte-ordering.md)  
  
-   [Soquetes do windows: Convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md)  
  
-   [Soquetes do windows: Portas e endereço de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md)  
  
## Consulte também  
 [Windows Sockets](../mfc/windows-sockets.md)