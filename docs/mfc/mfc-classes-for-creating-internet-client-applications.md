---
title: Classes MFC para criar aplicativos clientes de Internet
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, WinInet classes
- WinInet classes [MFC], classes
- classes [MFC], MFC
- Internet client applications [MFC], MFC
- Internet applications [MFC], MFC
ms.assetid: 67d34117-9839-4f4b-8bb8-0e4a9471c606
ms.openlocfilehash: d65a2e8b373f26fe928e4c3e7c0193aec4edf2d6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618042"
---
# <a name="mfc-classes-for-creating-internet-client-applications"></a>Classes MFC para criar aplicativos clientes de Internet

O MFC fornece as seguintes classes e funções globais para escrever aplicativos de cliente de Internet. O recuo indica que uma classe é derivada da classe sem recuo acima dela. `CGopherFile`e `CHttpFile` derive de `CInternetFile` , por exemplo. Essas classes e funções globais são declaradas em AFXINET. H, exceto `CFileFind` , que é declarado em AFX. T.

## <a name="classes"></a>Classes

- [CInternetSession](reference/cinternetsession-class.md)

- [CInternetConnection](reference/cinternetconnection-class.md)

  - [CFtpConnection](reference/cftpconnection-class.md)

  - [CGopherConnection](reference/cgopherconnection-class.md)

  - [CHttpConnection](reference/chttpconnection-class.md)

- [CInternetFile](reference/cinternetfile-class.md)

  - [CGopherFile](reference/cgopherfile-class.md)

  - [CHttpFile](reference/chttpfile-class.md)

- [CFileFind](reference/cfilefind-class.md)

  - [CFtpFileFind](reference/cftpfilefind-class.md)

  - [CGopherFileFind](reference/cgopherfilefind-class.md)

- [CGopherLocator](reference/cgopherlocator-class.md)

- [CInternetException](reference/cinternetexception-class.md)

## <a name="global-functions"></a>Funções globais

- [AfxParseURL](reference/internet-url-parsing-globals.md#afxparseurl)

- [AfxGetInternetHandleType](reference/internet-url-parsing-globals.md#afxgetinternethandletype)

- [AfxThrowInternetException](reference/internet-url-parsing-globals.md#afxthrowinternetexception)

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](win32-internet-extensions-wininet.md)<br/>
[Pré-requisitos para classes clientes de Internet](prerequisites-for-internet-client-classes.md)<br/>
[Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](writing-an-internet-client-application-using-mfc-wininet-classes.md)
