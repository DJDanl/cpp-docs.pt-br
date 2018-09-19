---
title: Pré-requisitos para Classes cliente da Internet | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Internet files [MFC], writing to
- Internet [MFC], connections
- FTP (File Transfer Protocol), MFC classes
- Gopher prerequisites [MFC]
- files [MFC], writing to
- classes [MFC], connections
- HTTP [MFC], prerequisites for Internet clients
- connections [MFC], classes for
- Internet client class prerequisites [MFC]
- files [MFC], reading
- URLs [MFC], Internet client applications
- prerequisites, Internet client classes [MFC]
- Gopher client applications [MFC]
ms.assetid: c51d1dfe-260c-4228-8100-e4efd90e9599
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e374305586db3c69a19194e866d5a03d3de91f4e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46402649"
---
# <a name="prerequisites-for-internet-client-classes"></a>Pré-requisitos para classes clientes de Internet

Algumas ações realizadas por um cliente da Internet (ler um arquivo, por exemplo) tem ações de pré-requisito (no caso, estabelecendo uma conexão de Internet). As tabelas a seguir listam os pré-requisitos para algumas ações do cliente.

### <a name="general-internet-url-ftp-gopher-or-http"></a>URL da Internet geral (FTP, Gopher ou HTTP)

|Ação|Pré-requisito|
|------------|------------------|
|Estabelece uma conexão.|Criar uma [CInternetSession](../mfc/reference/cinternetsession-class.md) para estabelecer a base de um aplicativo de cliente da Internet.|
|Abra uma URL.|Estabelece uma conexão. Chame [CInternetSession::OpenURL](../mfc/reference/cinternetsession-class.md#openurl). O `OpenURL` função retorna um objeto de recurso de somente leitura.|
|Dados de leitura de URL.|Abra a URL. Chame [CInternetFile::Read](../mfc/reference/cinternetfile-class.md#read).|
|Defina uma opção de Internet.|Estabelece uma conexão. Chame [CInternetSession::SetOption](../mfc/reference/cinternetsession-class.md#setoption).|
|Defina uma função a ser chamado com informações de status.|Estabelece uma conexão. Chame [CInternetSession::EnableStatusCallback](../mfc/reference/cinternetsession-class.md#enablestatuscallback). Substituir [CInternetSession::OnStatusCallback](../mfc/reference/cinternetsession-class.md#onstatuscallback) para lidar com chamadas.|

### <a name="ftp"></a>FTP

|Ação|Pré-requisito|
|------------|------------------|
|Estabelece uma conexão de FTP.|Criar uma [CInternetSession](../mfc/reference/cinternetsession-class.md) como base para esse aplicativo de cliente da Internet. Chame [CInternetSession::GetFtpConnection](../mfc/reference/cinternetsession-class.md#getftpconnection) para criar um [CFtpConnection](../mfc/reference/cftpconnection-class.md) objeto.|
|Localize o recurso primeiro.|Estabelece uma conexão de FTP. Criar uma [CFtpFileFind](../mfc/reference/cftpfilefind-class.md) objeto. Chame [CFtpFileFind::FindFile](../mfc/reference/cftpfilefind-class.md#findfile).|
|Enumere todos os recursos disponíveis.|Localize o primeiro arquivo. Chame [CFtpFileFind::FindNextFile](../mfc/reference/cftpfilefind-class.md#findnextfile) até ele retornar FALSE.|
|Abra um arquivo FTP.|Estabelece uma conexão de FTP. Chame [CFtpConnection::OpenFile](../mfc/reference/cftpconnection-class.md#openfile) para criar e abrir um [CInternetFile](../mfc/reference/cinternetfile-class.md) objeto.|
|Ler um arquivo do FTP.|Abra um arquivo FTP com acesso de leitura. Chame [CInternetFile::Read](../mfc/reference/cinternetfile-class.md#read).|
|Gravar em um arquivo FTP.|Abra um arquivo FTP com acesso de gravação. Chame [CInternetFile::Write](../mfc/reference/cinternetfile-class.md#write).|
|Altere o diretório do cliente no servidor.|Estabelece uma conexão de FTP. Chame [CFtpConnection::SetCurrentDirectory](../mfc/reference/cftpconnection-class.md#setcurrentdirectory).|
|Recupere a pasta do cliente atual no servidor.|Estabelece uma conexão de FTP. Chame [CFtpConnection::GetCurrentDirectory](../mfc/reference/cftpconnection-class.md#getcurrentdirectory).|

### <a name="http"></a>HTTP

|Ação|Pré-requisito|
|------------|------------------|
|Estabelece uma conexão HTTP.|Criar uma [CInternetSession](../mfc/reference/cinternetsession-class.md) como base para esse aplicativo de cliente da Internet. Chame [CInternetSession::GetHttpConnection](../mfc/reference/cinternetsession-class.md#gethttpconnection) para criar um [CHttpConnection](../mfc/reference/chttpconnection-class.md) objeto.|
|Abra um arquivo HTTP.|Estabelece uma conexão HTTP. Chame [CHttpConnection::OpenRequest](../mfc/reference/chttpconnection-class.md#openrequest) para criar um [CHttpFile](../mfc/reference/chttpfile-class.md) objeto. Chame [CHttpFile::AddRequestHeaders](../mfc/reference/chttpfile-class.md#addrequestheaders). Chame [CHttpFile::SendRequest](../mfc/reference/chttpfile-class.md#sendrequest).|
|Ler um arquivo do HTTP.|Abra um arquivo HTTP. Chame [CInternetFile::Read](../mfc/reference/cinternetfile-class.md#read).|
|Obtenha informações sobre uma solicitação HTTP.|Estabelece uma conexão HTTP. Chame [CHttpConnection::OpenRequest](../mfc/reference/chttpconnection-class.md#openrequest) para criar um [CHttpFile](../mfc/reference/chttpfile-class.md) objeto. Chame [CHttpFile::QueryInfo](../mfc/reference/chttpfile-class.md#queryinfo).|

### <a name="gopher"></a>Gopher

|Ação|Pré-requisito|
|------------|------------------|
|Estabelece uma conexão de gopher.|Criar uma [CInternetSession](../mfc/reference/cinternetsession-class.md) como base para esse aplicativo de cliente da Internet. Chame [CInternetSession::GetGopherConnection](../mfc/reference/cinternetsession-class.md#getgopherconnection) para criar um [CGopherConnection](../mfc/reference/cgopherconnection-class.md).|
|Localize o primeiro arquivo no diretório atual.|Estabelece uma conexão de gopher. Criar uma [CGopherFileFind](../mfc/reference/cgopherfilefind-class.md) objeto. Chame [CGopherConnection::CreateLocator](../mfc/reference/cgopherconnection-class.md#createlocator) para criar um [CGopherLocator](../mfc/reference/cgopherlocator-class.md) objeto. Passe o localizador para [CGopherFileFind::FindFile](../mfc/reference/cgopherfilefind-class.md#findfile). Chame [CGopherFileFind::GetLocator](../mfc/reference/cgopherfilefind-class.md#getlocator) para obter o localizador de um arquivo, se você precisar de mais tarde.|
|Enumere todos os arquivos disponíveis.|Localize o primeiro arquivo. Chame [CGopherFileFind::FindNextFile](../mfc/reference/cgopherfilefind-class.md#findnextfile) até ele retornar FALSE.|
|Abra um arquivo de gopher.|Estabelece uma conexão de gopher. Criar um localizador de gopher com [CGopherConnection::CreateLocator](../mfc/reference/cgopherconnection-class.md#createlocator) ou localize um localizador com [CGopherFileFind::GetLocator](../mfc/reference/cgopherfilefind-class.md#getlocator). Chame [CGopherConnection::OpenFile](../mfc/reference/cgopherconnection-class.md#openfile).|
|Ler um arquivo de gopher.|Abra um arquivo de gopher. Use [CGopherFile](../mfc/reference/cgopherfile-class.md).|

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Classes MFC para criar aplicativos clientes de Internet](../mfc/mfc-classes-for-creating-internet-client-applications.md)<br/>
[Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)
