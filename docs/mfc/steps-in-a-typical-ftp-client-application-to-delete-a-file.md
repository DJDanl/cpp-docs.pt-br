---
title: Etapas em um aplicativo cliente FTP típico para excluir um arquivo
ms.date: 11/04/2016
helpviewer_keywords:
- Internet client applications [MFC], FTP delete
- WinInet classes [MFC], FTP
- FTP (File Transfer Protocol) [MFC], client applications
- Internet applications [MFC], FTP client applications
ms.assetid: 2c347a96-c0a4-4827-98fe-668406e552bc
ms.openlocfilehash: 5cd005908656f09028f95be38ee78c7887c2f223
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50612440"
---
# <a name="steps-in-a-typical-ftp-client-application-to-delete-a-file"></a>Etapas em um aplicativo cliente FTP típico para excluir um arquivo

A tabela a seguir mostra as etapas que você pode executar em um aplicativo cliente FTP típico que exclui um arquivo.

|Sua meta|Ações que você executar|Efeitos|
|---------------|----------------------|-------------|
|Iniciar uma sessão FTP.|Criar uma [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Inicializa o WinInet e se conecta ao servidor.|
|Conecte-se a um servidor FTP.|Use [CInternetSession::GetFtpConnection](../mfc/reference/cinternetsession-class.md#getftpconnection).|Retorna um [CFtpConnection](../mfc/reference/cftpconnection-class.md) objeto.|
|Verifique se que você está no diretório correto no servidor FTP.|Use [CFtpConnection::GetCurrentDirectory](../mfc/reference/cftpconnection-class.md#getcurrentdirectory) ou [CFtpConnection::GetCurrentDirectoryAsURL](../mfc/reference/cftpconnection-class.md#getcurrentdirectoryasurl).|Retorna o nome ou URL do diretório que você está conectado atualmente no servidor, dependendo da função de membro selecionado.|
|Altere para um novo diretório FTP no servidor.|Use [CFtpConnection::SetCurrentDirectory](../mfc/reference/cftpconnection-class.md#setcurrentdirectory).|Altera o diretório que você está conectado atualmente no servidor.|
|Localize o primeiro arquivo no diretório de FTP.|Use [CFtpFileFind::FindFile](../mfc/reference/cftpfilefind-class.md#findfile).|Localiza o primeiro arquivo. Se nenhum arquivo for encontrado, retornará FALSE.|
|Localize o próximo arquivo no diretório de FTP.|Use [CFtpFileFind::FindNextFile](../mfc/reference/cftpfilefind-class.md#findnextfile).|Localiza o próximo arquivo. Se o arquivo não for encontrado, retornará FALSE.|
|Exclua o arquivo encontrado pelo `FindFile` ou `FindNextFile`.|Use [CFtpConnection::Remove](../mfc/reference/cftpconnection-class.md#remove), usando o nome do arquivo retornadas por `FindFile` ou `FindNextFile`.|Exclui o arquivo no servidor para leitura ou gravação.|
|Trate exceções.|Use o [CInternetException](../mfc/reference/cinternetexception-class.md) classe.|Lida com todos os tipos de exceção comuns da Internet.|
|Encerre a sessão FTP.|Descartar os [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Limpa automaticamente identificadores de arquivos abertos e conexões.|

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Pré-requisitos para classes cliente da Internet](../mfc/prerequisites-for-internet-client-classes.md)<br/>
[Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)
