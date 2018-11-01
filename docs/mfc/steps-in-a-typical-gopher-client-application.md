---
title: Etapas em um aplicativo cliente gopher típico
ms.date: 11/04/2016
helpviewer_keywords:
- WinInet classes [MFC], gopher
- Internet applications [MFC], gopher client applications
- Gopher client applications [MFC]
- Internet client applications [MFC], gopher table
ms.assetid: 3e4e1869-5da0-453d-8ba9-b648c894bb90
ms.openlocfilehash: 123b8abd2ca65356c584fa52f9415504bcb701c6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50486418"
---
# <a name="steps-in-a-typical-gopher-client-application"></a>Etapas em um aplicativo cliente gopher típico

A tabela a seguir mostra as etapas que você pode executar em um aplicativo cliente gopher típico.

|Sua meta|Ações que você executar|Efeitos|
|---------------|----------------------|-------------|
|Iniciar uma sessão de gopher.|Criar uma [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Inicializa o WinInet e se conecta ao servidor.|
|Conecte-se a um servidor gopher.|Use [CInternetSession::GetGopherConnection](../mfc/reference/cinternetsession-class.md#getgopherconnection).|Retorna um [CGopherConnection](../mfc/reference/cgopherconnection-class.md) objeto.|
|Encontre o primeiro recurso no gopher.|Use [CGopherFileFind::FindFile](../mfc/reference/cgopherfilefind-class.md#findfile).|Localiza o primeiro arquivo. Se nenhum arquivo for encontrado, retornará FALSE.|
|Localize o recurso de próximo no gopher.|Use [CGopherFileFind::FindNextFile](../mfc/reference/cgopherfilefind-class.md#findnextfile).|Localiza o próximo arquivo. Se o arquivo não for encontrado, retornará FALSE.|
|Abra o arquivo encontrado pelo `FindFile` ou `FindNextFile` para leitura.|Obtenha um localizador de gopher usando [CGopherFileFind::GetLocator](../mfc/reference/cgopherfilefind-class.md#getlocator). Use [CGopherConnection::OpenFile](../mfc/reference/cgopherconnection-class.md#openfile).|Abre o arquivo especificado pelo localizador. `OpenFile` Retorna um [CGopherFile](../mfc/reference/cgopherfile-class.md) objeto.|
|Abra um arquivo usando um localizador de gopher que você fornecer.|Criar um localizador de gopher usando [CGopherConnection::CreateLocator](../mfc/reference/cgopherconnection-class.md#createlocator). Use [CGopherConnection::OpenFile](../mfc/reference/cgopherconnection-class.md#openfile).|Abre o arquivo especificado pelo localizador. `OpenFile` Retorna um [CGopherFile](../mfc/reference/cgopherfile-class.md) objeto.|
|Ler o arquivo.|Use [CGopherFile](../mfc/reference/cgopherfile-class.md).|Lê o número especificado de bytes, usando um buffer que você fornecer.|
|Trate exceções.|Use o [CInternetException](../mfc/reference/cinternetexception-class.md) classe.|Lida com todos os tipos de exceção comuns da Internet.|
|Encerre a sessão de gopher.|Descartar os [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Limpa automaticamente identificadores de arquivos abertos e conexões.|

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Pré-requisitos para classes cliente da Internet](../mfc/prerequisites-for-internet-client-classes.md)<br/>
[Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)
