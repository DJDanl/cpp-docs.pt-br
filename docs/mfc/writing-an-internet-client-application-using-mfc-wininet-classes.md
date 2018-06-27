---
title: Escrevendo um aplicativo de cliente da Internet usando Classes WinInet MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Internet client applications [MFC]
- WinInet classes [MFC], programming
- Internet client applications [MFC], writing
- Internet applications [MFC], WinInet
- Internet applications [MFC], client applications
- MFC, Internet applications
ms.assetid: a2c4a40c-a94e-4b3e-9dbf-f8a8dc8e5428
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 00ace36eef483d8385d718e14e1fc4c5f4e9ea1e
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36956460"
---
# <a name="writing-an-internet-client-application-using-mfc-wininet-classes"></a>Escrevendo um aplicativo cliente da Internet usando classes WinInet MFC
A base de cada aplicativo de cliente da Internet é a sessão de Internet. MFC implementa sessões de Internet como objetos da classe [CInternetSession](../mfc/reference/cinternetsession-class.md). O uso dessa classe, você pode criar uma sessão de Internet ou de várias sessões simultâneas.  
  
 Para se comunicar com um servidor, é necessário um [CInternetConnection](../mfc/reference/cinternetconnection-class.md) objeto, bem como a `CInternetSession`. Você pode criar um `CInternetConnection` usando [CInternetSession::GetFtpConnection](../mfc/reference/cinternetsession-class.md#getftpconnection), [CInternetSession::GetHttpConnection](../mfc/reference/cinternetsession-class.md#gethttpconnection), ou [CInternetSession::GetGopherConnection](../mfc/reference/cinternetsession-class.md#getgopherconnection). Cada uma dessas chamadas é específica para o tipo de protocolo. Essas chamadas não abrir um arquivo no servidor para leitura ou gravação. Se você pretende ler ou gravar dados, você deve abrir o arquivo como uma etapa separada.  
  
 Para a maioria das sessões de Internet, o `CInternetSession` objeto funciona em conjunto com um [CInternetFile](../mfc/reference/cinternetfile-class.md) objeto:  
  
-   Em uma sessão de Internet, você deve criar uma instância de [CInternetSession](../mfc/reference/cinternetsession-class.md).  
  
-   Se a sessão da Internet lê ou grava dados, você deve criar uma instância de `CInternetFile` (ou suas subclasses [CHttpFile](../mfc/reference/chttpfile-class.md) ou [CGopherFile](../mfc/reference/cgopherfile-class.md)). A maneira mais fácil a leitura de dados é chamar [CInternetSession::OpenURL](../mfc/reference/cinternetsession-class.md#openurl). Esta função analisa um localizador de recursos Universal (URL) fornecidos por você, abre uma conexão para o servidor especificado pela URL e retorna somente leitura `CInternetFile` objeto. `CInternetSession::OpenURL` não é específico para o tipo de um protocolo — a mesma chamada funciona para qualquer URL gopher, HTTP ou FTP. `CInternetSession::OpenURL` até mesmo funciona com arquivos locais (retornando um `CStdioFile` em vez de um `CInternetFile`).  
  
-   Se sua Internet sessão não ler ou gravar dados, mas executa outras tarefas, como excluir um arquivo em um diretório de FTP, você não precisará criar uma instância do `CInternetFile`.  
  
 Há duas maneiras de criar um `CInternetFile` objeto:  
  
-   Se você usar `CInternetSession::OpenURL` para estabelecer a conexão de servidor, a chamada para `OpenURL` retorna um `CStdioFile`.  
  
-   Se usar `CInternetSession::GetFtpConnection`, `GetGopherConnection`, ou `GetHttpConnection` para estabelecer a conexão de servidor, você deve chamar `CFtpConnection::OpenFile`, `CGopherConnection::OpenFile`, ou `CHttpConnection::OpenRequest`, respectivamente, para retornar um `CInternetFile`, `CGopherFile`, ou `CHttpFile`, respectivamente.  
  
 As etapas na implementação de um aplicativo cliente da Internet variam dependendo se você criar um cliente de Internet genérico com base em `OpenURL` ou um cliente de protocolo específico usando um do `GetConnection` funções.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Como escrever um aplicativo cliente da Internet que funciona de forma genérica com HTTP, FTP e gopher](../mfc/steps-in-a-typical-internet-client-application.md)  
  
-   [Como escrever um aplicativo de cliente FTP que abre um arquivo](../mfc/steps-in-a-typical-ftp-client-application.md)  
  
-   [Como escrever um aplicativo de cliente FTP que executa uma operação de diretório, como excluir um arquivo, mas não abre um arquivo](../mfc/steps-in-a-typical-ftp-client-application-to-delete-a-file.md)  
  
-   [Como escrever um aplicativo de cliente gopher](../mfc/steps-in-a-typical-gopher-client-application.md)  
  
-   [Como escrever um aplicativo de cliente HTTP](../mfc/steps-in-a-typical-http-client-application.md)  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)   
 [Classes MFC para criar aplicativos cliente da Internet](../mfc/mfc-classes-for-creating-internet-client-applications.md)   
 [Pré-requisitos para classes cliente da Internet](../mfc/prerequisites-for-internet-client-classes.md)
