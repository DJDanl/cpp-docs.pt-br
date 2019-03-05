---
title: Escrevendo um aplicativo cliente da Internet usando classes WinInet MFC
ms.date: 11/04/2016
helpviewer_keywords:
- Internet client applications [MFC]
- WinInet classes [MFC], programming
- Internet client applications [MFC], writing
- Internet applications [MFC], WinInet
- Internet applications [MFC], client applications
- MFC, Internet applications
ms.assetid: a2c4a40c-a94e-4b3e-9dbf-f8a8dc8e5428
ms.openlocfilehash: 6e32210217321e4eb59d7d3e666a4f5494eb3642
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57287694"
---
# <a name="writing-an-internet-client-application-using-mfc-wininet-classes"></a>Escrevendo um aplicativo cliente da Internet usando classes WinInet MFC

A base para todos os aplicativos cliente da Internet é a sessão de Internet. MFC implementa sessões da Internet como objetos da classe [CInternetSession](../mfc/reference/cinternetsession-class.md). Usando essa classe, você pode criar uma sessão de Internet ou de várias sessões simultâneas.

Para se comunicar com um servidor, você precisa de uma [CInternetConnection](../mfc/reference/cinternetconnection-class.md) objeto, bem como a `CInternetSession`. Você pode criar uma `CInternetConnection` por meio [CInternetSession::GetFtpConnection](../mfc/reference/cinternetsession-class.md#getftpconnection), [CInternetSession::GetHttpConnection](../mfc/reference/cinternetsession-class.md#gethttpconnection), ou [CInternetSession::GetGopherConnection](../mfc/reference/cinternetsession-class.md#getgopherconnection). Cada uma dessas chamadas é específica para o tipo de protocolo. Essas chamadas não abra um arquivo no servidor para leitura ou gravação. Se você pretende ler ou gravar dados, você deve abrir o arquivo como uma etapa separada.

Para a maioria das sessões de Internet, o `CInternetSession` objeto funciona em conjunto com um [CInternetFile](../mfc/reference/cinternetfile-class.md) objeto:

- Uma sessão de Internet, você deve criar uma instância do [CInternetSession](../mfc/reference/cinternetsession-class.md).

- Se sua sessão de Internet lê ou grava dados, você deve criar uma instância do `CInternetFile` (ou suas subclasses [CHttpFile](../mfc/reference/chttpfile-class.md) ou [CGopherFile](../mfc/reference/cgopherfile-class.md)). A maneira mais fácil de ler os dados é chamar [CInternetSession::OpenURL](../mfc/reference/cinternetsession-class.md#openurl). Essa função analisa um localizador de recurso Universal (URL) fornecido por você, abre uma conexão com o servidor especificado pela URL e retorna somente leitura `CInternetFile` objeto. `CInternetSession::OpenURL` não é específico para o tipo de um protocolo — a mesma chamada funciona para qualquer URL FTP, HTTP ou gopher. `CInternetSession::OpenURL` funciona até mesmo com arquivos locais (retornando um `CStdioFile` em vez de um `CInternetFile`).

- Se sua Internet sessão não ler ou gravar dados, mas executa outras tarefas, como a exclusão de um arquivo em um diretório FTP, você não precisará criar uma instância de `CInternetFile`.

Há duas maneiras de criar um `CInternetFile` objeto:

- Se você usar `CInternetSession::OpenURL` para estabelecer sua conexão de servidor, a chamada para `OpenURL` retorna um `CStdioFile`.

- Se usar `CInternetSession::GetFtpConnection`, `GetGopherConnection`, ou `GetHttpConnection` para estabelecer sua conexão de servidor, você deve chamar `CFtpConnection::OpenFile`, `CGopherConnection::OpenFile`, ou `CHttpConnection::OpenRequest`, respectivamente, para retornar uma `CInternetFile`, `CGopherFile`, ou `CHttpFile`, respectivamente.

As etapas na implementação de um aplicativo de cliente da Internet variam dependendo se você cria um cliente de Internet genérico com base em `OpenURL` ou um cliente específico de protocolo usando uma da `GetConnection` funções.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Como escrever um aplicativo cliente da Internet que funciona de forma genérica com FTP, HTTP e gopher](../mfc/steps-in-a-typical-internet-client-application.md)

- [Como escrever um aplicativo de cliente FTP que abre um arquivo](../mfc/steps-in-a-typical-ftp-client-application.md)

- [Como escrever um aplicativo de cliente FTP que não abre um arquivo, mas executa uma operação de diretório, como a exclusão de um arquivo](../mfc/steps-in-a-typical-ftp-client-application-to-delete-a-file.md)

- [Como escrever um aplicativo cliente gopher](../mfc/steps-in-a-typical-gopher-client-application.md)

- [Como escrever um aplicativo de cliente HTTP](../mfc/steps-in-a-typical-http-client-application.md)

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Classes MFC para criar aplicativos clientes de Internet](../mfc/mfc-classes-for-creating-internet-client-applications.md)<br/>
[Pré-requisitos para classes cliente da Internet](../mfc/prerequisites-for-internet-client-classes.md)
