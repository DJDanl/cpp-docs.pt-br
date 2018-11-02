---
title: Etapas em um aplicativo cliente FTP típico
ms.date: 11/04/2016
helpviewer_keywords:
- Internet client applications [MFC], FTP table
- FTP (File Transfer Protocol)
- WinInet classes [MFC], FTP
- FTP (File Transfer Protocol) [MFC], client applications
- Internet applications [MFC], FTP client applications
ms.assetid: 70bed7b5-6040-40d1-bc77-702e63a698f2
ms.openlocfilehash: ef772438558e5d587962242fdd7f1230cc2b2f25
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50560180"
---
# <a name="steps-in-a-typical-ftp-client-application"></a>Etapas em um aplicativo cliente FTP típico

Um aplicativo de cliente FTP típico cria um [CInternetSession](../mfc/reference/cinternetsession-class.md) e uma [CFtpConnection](../mfc/reference/cftpconnection-class.md) objeto. Observe que essas classes WinInet do MFC, na verdade, não controlam as configurações de tipo de proxy; IIS faz.

A tabela a seguir mostra as etapas que você pode executar em um aplicativo de cliente FTP típico.

|Sua meta|Ações que você executar|Efeitos|
|---------------|----------------------|-------------|
|Iniciar uma sessão FTP.|Criar uma [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Inicializa o WinInet e se conecta ao servidor.|
|Conecte-se a um servidor FTP.|Use [CInternetSession::GetFtpConnection](../mfc/reference/cinternetsession-class.md#getftpconnection).|Retorna um [CFtpConnection](../mfc/reference/cftpconnection-class.md) objeto.|
|Altere para um novo diretório FTP no servidor.|Use [CFtpConnection::SetCurrentDirectory](../mfc/reference/cftpconnection-class.md#setcurrentdirectory).|Altera o diretório que você está conectado atualmente no servidor.|
|Localize o primeiro arquivo no diretório de FTP.|Use [CFtpFileFind::FindFile](../mfc/reference/cftpfilefind-class.md#findfile).|Localiza o primeiro arquivo. Se nenhum arquivo for encontrado, retornará FALSE.|
|Localize o próximo arquivo no diretório de FTP.|Use [CFtpFileFind::FindNextFile](../mfc/reference/cftpfilefind-class.md#findnextfile).|Localiza o próximo arquivo. Se o arquivo não for encontrado, retornará FALSE.|
|Abra o arquivo encontrado pelo `FindFile` ou `FindNextFile` para leitura ou gravação.|Use [CFtpConnection::OpenFile](../mfc/reference/cftpconnection-class.md#openfile), usando o nome do arquivo retornadas por [FindFile](../mfc/reference/cftpfilefind-class.md#findfile) ou [FindNextFile](../mfc/reference/cftpfilefind-class.md#findnextfile).|Abre o arquivo no servidor para leitura ou gravação. Retorna um [CInternetFile](../mfc/reference/cinternetfile-class.md) objeto.|
|Ler ou gravar no arquivo.|Use [CInternetFile::Read](../mfc/reference/cinternetfile-class.md#read) ou [CInternetFile::Write](../mfc/reference/cinternetfile-class.md#write).|Lê ou grava o número especificado de bytes, usando um buffer que você fornecer.|
|Trate exceções.|Use o [CInternetException](../mfc/reference/cinternetexception-class.md) classe.|Lida com todos os tipos de exceção comuns da Internet.|
|Encerre a sessão FTP.|Descartar os [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Limpa automaticamente identificadores de arquivos abertos e conexões.|

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Pré-requisitos para classes cliente da Internet](../mfc/prerequisites-for-internet-client-classes.md)<br/>
[Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)
