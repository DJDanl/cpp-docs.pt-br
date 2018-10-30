---
title: Classes de Internet Win32 | Microsoft Docs
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.win32
dev_langs:
- C++
helpviewer_keywords:
- Internet classes [MFC]
- WinInet classes [MFC], classes
- Win32 [MFC], Internet classes
- Windows API [MFC], Internet classes
ms.assetid: b49601d5-3025-4068-9408-316b54ee4375
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1c59d9d3e2a838c2b3933d49454a494ab6c7a290
ms.sourcegitcommit: a3c9e7888b8f437a170327c4c175733ad9eb0454
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2018
ms.locfileid: "50204425"
---
# <a name="win32-internet-classes"></a>Classes de Internet Win32

MFC encapsula a Internet Win32 (WinInet) e a tecnologia de ActiveX para facilitar a programação da Internet.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

[CInternetSession](../mfc/reference/cinternetsession-class.md)<br/>
Cria e inicializa várias sessões simultâneas da Internet ou uma sessão de Internet e, se necessário, descreve a conexão a um servidor proxy.

[CInternetConnection](../mfc/reference/cinternetconnection-class.md)<br/>
Gerencia sua conexão a um servidor de Internet.

[CInternetFile](../mfc/reference/cinternetfile-class.md)<br/>
Essa classe e suas classes derivadas permitem acesso aos arquivos em sistemas remotos que usam protocolos de Internet.

[CHttpConnection](../mfc/reference/chttpconnection-class.md)<br/>
Gerencia sua conexão a um servidor HTTP.

[CHttpFile](../mfc/reference/chttpfile-class.md)<br/>
Fornece a funcionalidade para localizar e ler arquivos em um servidor HTTP.

[CGopherFile](../mfc/reference/cgopherfile-class.md)<br/>
Fornece a funcionalidade para localizar e ler arquivos em um servidor gopher.

[CFtpConnection](../mfc/reference/cftpconnection-class.md)<br/>
Gerencia sua conexão a um servidor FTP.

[CGopherConnection](../mfc/reference/cgopherconnection-class.md)<br/>
Gerencia sua conexão a um servidor gopher.

[CFileFind](../mfc/reference/cfilefind-class.md)<br/>
Executa o local e pesquisas de arquivos de Internet.

[CFtpFileFind](../mfc/reference/cftpfilefind-class.md)<br/>
Auxílios em pesquisas de arquivos de Internet de servidores FTP.

[CGopherFileFind](../mfc/reference/cgopherfilefind-class.md)<br/>
Auxílios em pesquisas de arquivos de Internet de servidores gopher.

[CGopherLocator](../mfc/reference/cgopherlocator-class.md)<br/>
Obtém um gopher "localizador" de um servidor gopher, determina o tipo de localizador e torna o localizador disponível para `CGopherFileFind`.

[CInternetException](../mfc/reference/cinternetexception-class.md)<br/>
Representa uma condição de exceção relacionada a uma operação de Internet.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

