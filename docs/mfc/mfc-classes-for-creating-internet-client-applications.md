---
title: "Classes MFC para criar aplicativos clientes de Internet | Microsoft Docs"
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
  - "classes [C++], MFC"
  - "aplicativos da Internet, MFC"
  - "aplicativos cliente da Internet, MFC"
  - "MFC, Classes WinInet"
  - "Classes WinInet, Classes "
ms.assetid: 67d34117-9839-4f4b-8bb8-0e4a9471c606
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes MFC para criar aplicativos clientes de Internet
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC O fornece as seguintes classes e as funções globais para gravar aplicativos cliente da Internet.  O recuo indica que uma classe é derivada da classe unindented acima delas.  `CGopherFile` e `CHttpFile` derivam\-se de `CInternetFile`, por exemplo.  Essas classes e funções globais são declaradas em AFXINET.H, exceto `CFileFind`, que é declarado em. AFX.H.  
  
## Classes  
  
-   [CInternetSession](../Topic/CInternetSession%20Class.md)  
  
-   [CInternetConnection](../Topic/CInternetConnection%20Class.md)  
  
    -   [CFtpConnection](../mfc/reference/cftpconnection-class.md)  
  
    -   [CGopherConnection](../mfc/reference/cgopherconnection-class.md)  
  
    -   [CHttpConnection](../mfc/reference/chttpconnection-class.md)  
  
-   [CInternetFile](../mfc/reference/cinternetfile-class.md)  
  
    -   [CGopherFile](../mfc/reference/cgopherfile-class.md)  
  
    -   [CHttpFile](../Topic/CHttpFile%20Class.md)  
  
-   [CFileFind](../mfc/reference/cfilefind-class.md)  
  
    -   [CFtpFileFind](../Topic/CFtpFileFind%20Class.md)  
  
    -   [CGopherFileFind](../mfc/reference/cgopherfilefind-class.md)  
  
-   [CGopherLocator](../Topic/CGopherLocator%20Class.md)  
  
-   [CInternetException](../mfc/reference/cinternetexception-class.md)  
  
## Funções globais  
  
-   [AfxParseURL](../Topic/AfxParseURL.md)  
  
-   [AfxGetInternetHandleType](../Topic/AfxGetInternetHandleType.md)  
  
-   [AfxThrowInternetException](../Topic/AfxThrowInternetException.md)  
  
## Consulte também  
 [Extensões da Internet Win32 \(WinInet\)](../mfc/win32-internet-extensions-wininet.md)   
 [Pré\-requisitos para classes clientes de Internet](../Topic/Prerequisites%20for%20Internet%20Client%20Classes.md)   
 [Escrevendo um aplicativo cliente da Internet usando classes WinInet MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)