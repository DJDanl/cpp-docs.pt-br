---
title: "Escrevendo um aplicativo cliente da Internet usando classes WinInet MFC | Microsoft Docs"
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
  - "aplicativos da Internet, aplicativos cliente"
  - "aplicativos da Internet, WinInet"
  - "aplicativos cliente da Internet"
  - "aplicativos cliente da Internet, gravando"
  - "MFC, aplicativos da Internet"
  - "Classes WinInet, programação"
ms.assetid: a2c4a40c-a94e-4b3e-9dbf-f8a8dc8e5428
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Escrevendo um aplicativo cliente da Internet usando classes WinInet MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A base de cada aplicativo cliente da Internet é a sessão da Internet.  MFC O implementa sessões de Internet como objetos da classe [CInternetSession](../Topic/CInternetSession%20Class.md).  Usando essa classe, você pode criar uma sessão de Internet ou de várias sessões simultâneas.  
  
 Para se comunicar com um servidor, você precisa de um objeto de [CInternetConnection](../Topic/CInternetConnection%20Class.md) bem como `CInternetSession`.  Você pode criar `CInternetConnection` usando [CInternetSession::GetFtpConnection](../Topic/CInternetSession::GetFtpConnection.md), [CInternetSession::GetHttpConnection](../Topic/CInternetSession::GetHttpConnection.md), ou [CInternetSession::GetGopherConnection](../Topic/CInternetSession::GetGopherConnection.md).  Cada uma dessas chamadas é específico ao tipo de protocolo.  Essas chamadas falha ao abrir um arquivo no servidor para ler ou gravar.  Se você pretende ler ou gravar dados, você deve abrir o arquivo como uma etapa separada.  
  
 Para a maioria das sessões da Internet, os trabalhos do objeto de `CInternetSession` em conjunto com um objeto de [CInternetFile](../mfc/reference/cinternetfile-class.md) :  
  
-   Para uma sessão da Internet, você deve criar uma instância de [CInternetSession](../Topic/CInternetSession%20Class.md).  
  
-   Se a sessão de Internet ler ou gravar dados, você deve criar uma instância de `CInternetFile` \(ou seu subclasses, [CHttpFile](../Topic/CHttpFile%20Class.md) ou [CGopherFile](../mfc/reference/cgopherfile-class.md)\).  A maneira mais fácil de ler dados é chamar [CInternetSession::OpenURL](../Topic/CInternetSession::OpenURL.md).  Esta função analisa um localizador \(URL\) do recurso universal\) fornecido por você, abre uma conexão com o servidor especificado pela URL, e retorna um objeto somente leitura de `CInternetFile` .  `CInternetSession::OpenURL` não é específico a um tipo de protocolo — o mesmo trabalho de chamada para nenhum FTP, HTTP, ou a URL de Gopher.  trabalho de`CInternetSession::OpenURL` mesmo com os arquivos locais \(que retornam `CStdioFile` em vez de `CInternetFile`\).  
  
-   Se a sessão da Internet não lê ou não grava os dados, mas executam outras tarefas, como excluir um arquivo em um diretório de FTP, você não pode precisar criar uma instância de `CInternetFile`.  
  
 Há duas maneiras de criar um objeto de `CInternetFile` :  
  
-   Se você usar `CInternetSession::OpenURL` para estabelecer a conexão do servidor, a chamada para `OpenURL` retorna `CStdioFile`.  
  
-   Se o uso **CInternetSession::GetFtpConnection**, `GetGopherConnection`, ou `GetHttpConnection` estabelecer a conexão de servidor, você deve chamar `CFtpConnection::OpenFile`, `CGopherConnection::OpenFile`, ou **CHttpConnection::OpenRequest,** respectivamente, para retornar `CInternetFile`, `CGopherFile`, ou `CHttpFile`, respectivamente.  
  
 As etapas para implementar um aplicativo cliente da Internet variam dependendo se você criar um cliente genérico da Internet com base em **OpenURL** ou um cliente protocolo específico usando uma das funções de **GetConnection** .  
  
## Que você deseja saber mais?  
  
-   [Como posso escrevo um aplicativo cliente de Internet que funcione genèrica pelo FTP, HTTP, e Gopher?](../Topic/Steps%20in%20a%20Typical%20Internet%20Client%20Application.md)  
  
-   [Como posso escrevo um aplicativo cliente de FTP que abre um arquivo?](../mfc/steps-in-a-typical-ftp-client-application.md)  
  
-   [Como posso escrevo um aplicativo cliente de FTP que faz não abrir um arquivo e executo uma operação de diretório, como excluir um arquivo?](../mfc/steps-in-a-typical-ftp-client-application-to-delete-a-file.md)  
  
-   [Como posso escrevo um aplicativo cliente de Gopher?](../mfc/steps-in-a-typical-gopher-client-application.md)  
  
-   [Como posso escrevo um aplicativo cliente HTTP?](../mfc/steps-in-a-typical-http-client-application.md)  
  
## Consulte também  
 [Extensões da Internet Win32 \(WinInet\)](../mfc/win32-internet-extensions-wininet.md)   
 [Classes MFC para criar aplicativos clientes de Internet](../mfc/mfc-classes-for-creating-internet-client-applications.md)   
 [Pré\-requisitos para classes clientes de Internet](../Topic/Prerequisites%20for%20Internet%20Client%20Classes.md)