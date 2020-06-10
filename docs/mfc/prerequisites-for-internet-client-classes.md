---
title: Pré-requisitos para classes clientes de Internet
ms.date: 11/04/2016
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
ms.openlocfilehash: aaf5756df69728e8ae89fb278bc0671bfc6840b7
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619828"
---
# <a name="prerequisites-for-internet-client-classes"></a>Pré-requisitos para classes clientes de Internet

Algumas ações tomadas por um cliente de Internet (ler um arquivo, por exemplo) têm ações de pré-requisito (nesse caso, estabelecendo uma conexão com a Internet). As tabelas a seguir listam os pré-requisitos para algumas ações do cliente.

### <a name="general-internet-url-ftp-gopher-or-http"></a>URL geral da Internet (FTP, Gopher ou HTTP)

|Ação|Pré-requisito|
|------------|------------------|
|Estabeleça uma conexão.|Crie um [CInternetSession](reference/cinternetsession-class.md) para estabelecer a base de um aplicativo cliente de Internet.|
|Abra uma URL.|Estabeleça uma conexão. Chame [CInternetSession:: OpenURL](reference/cinternetsession-class.md#openurl). A `OpenURL` função retorna um objeto de recurso somente leitura.|
|Ler dados de URL.|Abra a URL. Chame [CInternetFile:: Read](reference/cinternetfile-class.md#read).|
|Definir uma opção da Internet.|Estabeleça uma conexão. Chame [CInternetSession:: SetOption](reference/cinternetsession-class.md#setoption).|
|Defina uma função a ser chamada com informações de status.|Estabeleça uma conexão. Chame [CInternetSession:: EnableStatusCallback](reference/cinternetsession-class.md#enablestatuscallback). Substitua [CInternetSession:: OnStatusCallback](reference/cinternetsession-class.md#onstatuscallback) para tratar chamadas.|

### <a name="ftp"></a>FTP

|Ação|Pré-requisito|
|------------|------------------|
|Estabeleça uma conexão FTP.|Crie um [CInternetSession](reference/cinternetsession-class.md) como a base deste aplicativo cliente de Internet. Chame [CInternetSession:: GetFtpConnection](reference/cinternetsession-class.md#getftpconnection) para criar um objeto [CFtpConnection](reference/cftpconnection-class.md) .|
|Localize o primeiro recurso.|Estabeleça uma conexão FTP. Crie um objeto [CFtpFileFind](reference/cftpfilefind-class.md) . Chame [CFtpFileFind:: FindFile](reference/cftpfilefind-class.md#findfile).|
|Enumere todos os recursos disponíveis.|Localize o primeiro arquivo. Chame [CFtpFileFind:: FindNextFile](reference/cftpfilefind-class.md#findnextfile) até que ele retorne FALSE.|
|Abra um arquivo FTP.|Estabeleça uma conexão FTP. Chame [CFtpConnection:: OpenFile](reference/cftpconnection-class.md#openfile) para criar e abrir um objeto [CInternetFile](reference/cinternetfile-class.md) .|
|Ler um arquivo FTP.|Abra um arquivo FTP com acesso de leitura. Chame [CInternetFile:: Read](reference/cinternetfile-class.md#read).|
|Gravar em um arquivo FTP.|Abra um arquivo FTP com acesso de gravação. Chame [CInternetFile:: Write](reference/cinternetfile-class.md#write).|
|Altere o diretório do cliente no servidor.|Estabeleça uma conexão FTP. Chame [CFtpConnection:: SetCurrentDirectory](reference/cftpconnection-class.md#setcurrentdirectory).|
|Recupere o diretório atual do cliente no servidor.|Estabeleça uma conexão FTP. Chame [CFtpConnection:: GetCurrentDirectory](reference/cftpconnection-class.md#getcurrentdirectory).|

### <a name="http"></a>HTTP

|Ação|Pré-requisito|
|------------|------------------|
|Estabeleça uma conexão HTTP.|Crie um [CInternetSession](reference/cinternetsession-class.md) como a base deste aplicativo cliente de Internet. Chame [CInternetSession:: GetHttpConnection](reference/cinternetsession-class.md#gethttpconnection) para criar um objeto [CHttpConnection](reference/chttpconnection-class.md) .|
|Abra um arquivo HTTP.|Estabeleça uma conexão HTTP. Chame [CHttpConnection:: OpenRequest](reference/chttpconnection-class.md#openrequest) para criar um objeto [CHttpFile](reference/chttpfile-class.md) . Chame [CHttpFile:: AddRequestHeaders](reference/chttpfile-class.md#addrequestheaders). Chame [CHttpFile:: SendRequest](reference/chttpfile-class.md#sendrequest).|
|Ler um arquivo HTTP.|Abra um arquivo HTTP. Chame [CInternetFile:: Read](reference/cinternetfile-class.md#read).|
|Obter informações sobre uma solicitação HTTP.|Estabeleça uma conexão HTTP. Chame [CHttpConnection:: OpenRequest](reference/chttpconnection-class.md#openrequest) para criar um objeto [CHttpFile](reference/chttpfile-class.md) . Chame [CHttpFile:: QueryInfo](reference/chttpfile-class.md#queryinfo).|

### <a name="gopher"></a>Gopher

|Ação|Pré-requisito|
|------------|------------------|
|Estabeleça uma conexão do Gopher.|Crie um [CInternetSession](reference/cinternetsession-class.md) como a base deste aplicativo cliente de Internet. Chame [CInternetSession:: GetGopherConnection](reference/cinternetsession-class.md#getgopherconnection) para criar um [CGopherConnection](reference/cgopherconnection-class.md).|
|Localize o primeiro arquivo no diretório atual.|Estabeleça uma conexão do Gopher. Crie um objeto [CGopherFileFind](reference/cgopherfilefind-class.md) . Chame [CGopherConnection:: CreateLocator](reference/cgopherconnection-class.md#createlocator) para criar um objeto [CGopherLocator](reference/cgopherlocator-class.md) . Passe o localizador para [CGopherFileFind:: FindFile](reference/cgopherfilefind-class.md#findfile). Chame [CGopherFileFind:: GetLocator](reference/cgopherfilefind-class.md#getlocator) para obter o localizador de um arquivo se você precisar dele mais tarde.|
|Enumere todos os arquivos disponíveis.|Localize o primeiro arquivo. Chame [CGopherFileFind:: FindNextFile](reference/cgopherfilefind-class.md#findnextfile) até que ele retorne FALSE.|
|Abra um arquivo gopher.|Estabeleça uma conexão do Gopher. Crie um localizador do Gopher com [CGopherConnection:: CreateLocator](reference/cgopherconnection-class.md#createlocator) ou localize um localizador com [CGopherFileFind:: GetLocator](reference/cgopherfilefind-class.md#getlocator). Chame [CGopherConnection:: OpenFile](reference/cgopherconnection-class.md#openfile).|
|Ler um arquivo gopher.|Abra um arquivo gopher. Use [CGopherFile](reference/cgopherfile-class.md).|

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](win32-internet-extensions-wininet.md)<br/>
[Classes MFC para criar aplicativos clientes de Internet](mfc-classes-for-creating-internet-client-applications.md)<br/>
[Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](writing-an-internet-client-application-using-mfc-wininet-classes.md)
