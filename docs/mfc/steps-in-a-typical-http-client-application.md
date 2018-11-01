---
title: Etapas em um aplicativo cliente HTTP típico
ms.date: 11/04/2016
helpviewer_keywords:
- HTTP client applications [MFC]
- client applications [MFC], HTTP
- Internet applications [MFC], HTTP client applications
- applications [MFC], HTTP client
- Internet client applications [MFC], HTTP table
- WinInet classes [MFC], HTTP
ms.assetid: f86552e8-8acd-4b23-bdc5-0c3a247ebd74
ms.openlocfilehash: a73d220f4ab7f58960ccfe4b09f98f0cd0956406
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50630783"
---
# <a name="steps-in-a-typical-http-client-application"></a>Etapas em um aplicativo cliente HTTP típico

A tabela a seguir mostra as etapas que você pode executar em um aplicativo de cliente HTTP típico:

|Sua meta|Ações que você executar|Efeitos|
|---------------|----------------------|-------------|
|Iniciar uma sessão HTTP.|Criar uma [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Inicializa o WinInet e se conecta ao servidor.|
|Conecte-se a um servidor HTTP.|Use [CInternetSession::GetHttpConnection](../mfc/reference/cinternetsession-class.md#gethttpconnection).|Retorna um [CHttpConnection](../mfc/reference/chttpconnection-class.md) objeto.|
|Abra uma solicitação HTTP.|Use [CHttpConnection::OpenRequest](../mfc/reference/chttpconnection-class.md#openrequest).|Retorna um [CHttpFile](../mfc/reference/chttpfile-class.md) objeto.|
|Envie uma solicitação HTTP.|Use [CHttpFile::AddRequestHeaders](../mfc/reference/chttpfile-class.md#addrequestheaders) e [CHttpFile::SendRequest](../mfc/reference/chttpfile-class.md#sendrequest).|Localiza o arquivo. Se o arquivo não for encontrado, retornará FALSE.|
|Ler o arquivo.|Use [CHttpFile](../mfc/reference/chttpfile-class.md).|Lê o número especificado de bytes usando um buffer que você fornecer.|
|Trate exceções.|Use o [CInternetException](../mfc/reference/cinternetexception-class.md) classe.|Lida com todos os tipos de exceção comuns da Internet.|
|Encerre a sessão HTTP.|Descartar os [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Limpa automaticamente identificadores de arquivos abertos e conexões.|

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Pré-requisitos para classes cliente da Internet](../mfc/prerequisites-for-internet-client-classes.md)<br/>
[Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)
