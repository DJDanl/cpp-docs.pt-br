---
title: Como o MFC facilita a criar aplicativos cliente da Internet | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Internet client applications [MFC], MFC
- Internet applications [MFC], MFC
- MFC, Internet applications
ms.assetid: 94437b3f-f15c-437d-b5fd-264a2efec9ab
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f6270cdd3e64d24f1c2000acb9e8466f8c85edba
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-mfc-makes-it-easier-to-create-internet-client-applications"></a>Como o MFC facilita a criação de aplicativos clientes da Internet
O Microsoft Foundation Classes encapsular as funções de extensão de Internet Win32 (WinInet) de uma maneira que fornece um contexto familiar para os programadores do MFC. MFC fornece três classes de arquivo de Internet ([CInternetFile](../mfc/reference/cinternetfile-class.md), [CHttpFile](../mfc/reference/chttpfile-class.md), e [CGopherFile](../mfc/reference/cgopherfile-class.md)) derivado de [CStdioFile](../mfc/reference/cstdiofile-class.md) classe . Não só essas classes fazem recuperar e manipular dados de Internet familiar para os programadores que usaram `CStdioFile` para arquivos locais, mas com essas classes você pode manipular arquivos locais e arquivos da Internet de maneira transparente e consistente.  
  
 As classes WinInet MFC fornecem a mesma funcionalidade que `CStdioFile` para dados que são transferidos pela Internet. Essas classes abstraem os protocolos de Internet para HTTP, FTP e gopher em um aplicativo de alto nível interface de programação, fornecendo um caminho rápido e simples para aplicativos sensíveis à Internet. Por exemplo, se conectar a um servidor FTP ainda requer várias etapas em um nível baixo, mas como um desenvolvedor MFC, você só precisa fazer uma chamada para `CInternetSession::GetFTPConnection` para criar essa conexão.  
  
 Além disso, as classes WinInet MFC fornecem as seguintes vantagens:  
  
-   Buffer de e/s  
  
-   Identificadores de tipo seguro para seus dados  
  
-   Parâmetros padrão para muitas funções  
  
-   Manipulação de exceções para erros comuns de Internet  
  
-   Limpeza automática de identificadores abertos e conexões  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)   
 [Como o WinInet facilita a criação de aplicativos cliente da Internet](../mfc/how-wininet-makes-it-easier-to-create-internet-client-applications.md)

