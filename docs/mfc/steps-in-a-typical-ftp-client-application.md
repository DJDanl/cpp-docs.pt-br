---
title: As etapas em um aplicativo cliente FTP típico | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Internet client applications [MFC], FTP table
- FTP (File Transfer Protocol)
- WinInet classes [MFC], FTP
- FTP (File Transfer Protocol) [MFC], client applications
- Internet applications [MFC], FTP client applications
ms.assetid: 70bed7b5-6040-40d1-bc77-702e63a698f2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 98f5a21bd5fa20a40123ce442959125ea62c60d3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="steps-in-a-typical-ftp-client-application"></a>Etapas em um aplicativo cliente FTP típico
Cria um aplicativo de cliente FTP típico um [CInternetSession](../mfc/reference/cinternetsession-class.md) e um [CFtpConnection](../mfc/reference/cftpconnection-class.md) objeto. Observe que essas classes WinInet MFC, na verdade, não controlam as configurações de tipo de proxy; IIS faz.  
  
 Além disso, consulte estes artigos da Base de dados de Conhecimento:  
  
-   COMO: FTP com Proxy baseado em CERN usando a API do WinInet (ID do artigo: Q166961)  
  
-   EXEMPLO: FTP com senha com base em CERN protegido Proxy (ID do artigo: Q216214)  
  
-   Gerenciador de falha para mostrar os serviços de Proxy instalado de serviços da Internet (ID do artigo: Q216802)  
  
 A tabela a seguir mostra as etapas que você pode executar em um aplicativo de cliente FTP típico.  
  
|Sua meta|Ações executadas|Efeitos|  
|---------------|----------------------|-------------|  
|Inicia uma sessão FTP.|Criar um [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Inicializa WinInet e se conecta ao servidor.|  
|Conecte a um servidor FTP.|Use [CInternetSession::GetFtpConnection](../mfc/reference/cinternetsession-class.md#getftpconnection).|Retorna um [CFtpConnection](../mfc/reference/cftpconnection-class.md) objeto.|  
|Altere para um novo diretório FTP no servidor.|Use [CFtpConnection::SetCurrentDirectory](../mfc/reference/cftpconnection-class.md#setcurrentdirectory).|Altera o diretório que você está conectado atualmente no servidor.|  
|Localize o primeiro arquivo no diretório de FTP.|Use [CFtpFileFind::FindFile](../mfc/reference/cftpfilefind-class.md#findfile).|Localiza o primeiro arquivo. Se nenhum arquivo for encontrado, retorna falso.|  
|Localize o próximo arquivo no diretório de FTP.|Use [CFtpFileFind::FindNextFile](../mfc/reference/cftpfilefind-class.md#findnextfile).|Localiza o próximo arquivo. Se o arquivo não for encontrado, retorna falso.|  
|Abra o arquivo encontrado por **FindFile** ou `FindNextFile` para leitura ou gravação.|Use [CFtpConnection::OpenFile](../mfc/reference/cftpconnection-class.md#openfile), usando o nome de arquivo retornado por [FindFile](../mfc/reference/cftpfilefind-class.md#findfile) ou [FindNextFile](../mfc/reference/cftpfilefind-class.md#findnextfile).|Abre o arquivo no servidor para leitura ou gravação. Retorna um [CInternetFile](../mfc/reference/cinternetfile-class.md) objeto.|  
|Ler ou gravar no arquivo.|Use [CInternetFile::Read](../mfc/reference/cinternetfile-class.md#read) ou [CInternetFile::Write](../mfc/reference/cinternetfile-class.md#write).|Lê ou grava o número especificado de bytes, usando um buffer que você fornecer.|  
|Trate exceções.|Use o [CInternetException](../mfc/reference/cinternetexception-class.md) classe.|Trata todos os tipos de exceção de Internet comuns.|  
|Encerre a sessão FTP.|Descarte o [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Limpa automaticamente os identificadores de arquivos abertos e conexões.|  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)   
 [Pré-requisitos para Classes de cliente da Internet](../mfc/prerequisites-for-internet-client-classes.md)   
 [Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)
