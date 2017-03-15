---
title: "Windows Sockets: convertendo cadeias de caracteres | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "soquetes [C++], problemas de conversão de cadeias de caracteres multibyte"
  - "conversão de cadeia de caracteres, cadeias de caracteres multibyte"
  - "Windows Sockets [C++], conversão de cadeias de caracteres multibyte"
ms.assetid: 9df522b5-6b23-41e0-bb96-e4e623baf141
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Sockets: convertendo cadeias de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo e dois artigos complementares explicam vários problemas na programação de soquetes do windows.  Este artigo abrange converter cadeias de caracteres.  Outros problemas são abordados em [Soquetes do windows: Bloqueio](../Topic/Windows%20Sockets:%20Blocking.md) e em [Soquetes do windows: A ordenação de bytes](../mfc/windows-sockets-byte-ordering.md).  
  
 Se você usar ou se deriva da classe [CAsyncSocket](../Topic/CAsyncSocket%20Class.md), você precisará gerenciar esses problemas você mesmo.  Se você usar ou se deriva da classe [CSocket](../mfc/reference/csocket-class.md), o MFC gerenciá\-los para você.  
  
## Convertendo cadeias de caracteres  
 Se você se comunica entre os aplicativos que usam as cadeias de caracteres armazenadas em formatos diferentes ampla de caracteres, como Unicode ou conjuntos de caracteres multibyte \(MBCS\), ou entre um desses e um aplicativo usando cadeias de caracteres ANSI, você deve gerenciar as conversões você mesmo sob `CAsyncSocket`.  O objeto de `CArchive` usado com um objeto de `CSocket` gerencia essa conversão para você por meio dos recursos da classe [CString](../atl-mfc-shared/reference/cstringt-class.md).  Para obter mais informações, consulte a especificação de soquetes do windows, localizada em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações, consulte:  
  
-   [Soquetes do windows: Usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
-   [Soquetes do windows: Usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
-   [Soquetes do windows: Plano de fundo](../mfc/windows-sockets-background.md)  
  
-   [Soquetes do windows: Soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Soquetes do windows: Soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
## Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)