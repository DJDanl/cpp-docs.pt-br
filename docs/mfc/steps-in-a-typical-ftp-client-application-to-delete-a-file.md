---
title: As etapas em um aplicativo cliente FTP típico para excluir um arquivo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Internet client applications [MFC], FTP delete
- WinInet classes [MFC], FTP
- FTP (File Transfer Protocol) [MFC], client applications
- Internet applications [MFC], FTP client applications
ms.assetid: 2c347a96-c0a4-4827-98fe-668406e552bc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eb595dfdc1a73ecd068e251cec5df99d4daaab30
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33380559"
---
# <a name="steps-in-a-typical-ftp-client-application-to-delete-a-file"></a>Etapas em um aplicativo cliente FTP típico para excluir um arquivo
A tabela a seguir mostra as etapas que você pode executar em um aplicativo cliente FTP típico que exclui um arquivo.  
  
|Sua meta|Ações executadas|Efeitos|  
|---------------|----------------------|-------------|  
|Inicia uma sessão FTP.|Criar um [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Inicializa WinInet e se conecta ao servidor.|  
|Conecte a um servidor FTP.|Use [CInternetSession::GetFtpConnection](../mfc/reference/cinternetsession-class.md#getftpconnection).|Retorna um [CFtpConnection](../mfc/reference/cftpconnection-class.md) objeto.|  
|Verifique se que você está no diretório correto no servidor FTP.|Use [CFtpConnection::GetCurrentDirectory](../mfc/reference/cftpconnection-class.md#getcurrentdirectory) ou [CFtpConnection::GetCurrentDirectoryAsURL](../mfc/reference/cftpconnection-class.md#getcurrentdirectoryasurl).|Retorna o nome ou URL do diretório que você está conectado atualmente no servidor, dependendo da função de membro selecionado.|  
|Altere para um novo diretório FTP no servidor.|Use [CFtpConnection::SetCurrentDirectory](../mfc/reference/cftpconnection-class.md#setcurrentdirectory).|Altera o diretório que você está conectado atualmente no servidor.|  
|Localize o primeiro arquivo no diretório de FTP.|Use [CFtpFileFind::FindFile](../mfc/reference/cftpfilefind-class.md#findfile).|Localiza o primeiro arquivo. Se nenhum arquivo for encontrado, retorna falso.|  
|Localize o próximo arquivo no diretório de FTP.|Use [CFtpFileFind::FindNextFile](../mfc/reference/cftpfilefind-class.md#findnextfile).|Localiza o próximo arquivo. Se o arquivo não for encontrado, retorna falso.|  
|Exclua o arquivo encontrado por **FindFile** ou `FindNextFile`.|Use [CFtpConnection::Remove](../mfc/reference/cftpconnection-class.md#remove), usando o nome de arquivo retornado por **FindFile** ou `FindNextFile`.|Exclui o arquivo no servidor para leitura ou gravação.|  
|Trate exceções.|Use o [CInternetException](../mfc/reference/cinternetexception-class.md) classe.|Trata todos os tipos de exceção de Internet comuns.|  
|Encerre a sessão FTP.|Descarte o [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Limpa automaticamente os identificadores de arquivos abertos e conexões.|  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)   
 [Pré-requisitos para Classes de cliente da Internet](../mfc/prerequisites-for-internet-client-classes.md)   
 [Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)
