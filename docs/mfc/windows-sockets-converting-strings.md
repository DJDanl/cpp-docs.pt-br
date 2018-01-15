---
title: 'Windows Sockets: Convertendo cadeias de caracteres | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Windows Sockets [MFC], multibyte character string conversion
- sockets [MFC], multibyte character string conversion issues
- string conversion, multibyte character strings
ms.assetid: 9df522b5-6b23-41e0-bb96-e4e623baf141
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f87d200ca6c5b0b1edb003636e5f8c33570da50d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="windows-sockets-converting-strings"></a>Windows Sockets: convertendo cadeias de caracteres
Este artigo e dois artigos complementar explicam vários problemas na programação do Windows Sockets. Este artigo aborda convertendo cadeias de caracteres. Os outros problemas são abordados em [Windows Sockets: bloqueando](../mfc/windows-sockets-blocking.md) e [Windows Sockets: ordenação de bytes](../mfc/windows-sockets-byte-ordering.md).  
  
 Se você usar ou derivar da classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md), você precisará gerenciar esses problemas por conta própria. Se você usar ou derivar da classe [CSocket](../mfc/reference/csocket-class.md), gerencia MFC-los para você.  
  
## <a name="converting-strings"></a>Convertendo cadeias de caracteres  
 Se você se comunica entre aplicativos que usam cadeias de caracteres armazenadas em diferentes formatos de caractere largo, como Unicode ou caracteres multibyte (MBCS) de conjuntos, ou entre um deles e um aplicativo usando cadeias de caracteres ANSI, você deve gerenciar as conversões por conta própria em `CAsyncSocket`. O `CArchive` objeto usado com um `CSocket` objeto gerencia essa conversão para você por meio dos recursos da classe [CString](../atl-mfc-shared/reference/cstringt-class.md). Para obter mais informações, consulte a especificação de Windows Sockets, localizada no SDK do Windows.  
  
 Para obter mais informações, consulte:  
  
-   [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
-   [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
-   [Windows Sockets: tela de fundo](../mfc/windows-sockets-background.md)  
  
-   [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)

