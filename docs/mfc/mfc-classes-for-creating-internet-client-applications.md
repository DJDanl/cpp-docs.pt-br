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
ms.openlocfilehash: 578fd5b72e6c04610aa862f1a6631895a32a9bfe
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358216"
---
# <a name="mfc-classes-for-creating-internet-client-applications"></a>Classes MFC para criar aplicativos clientes de Internet

O MFC fornece as seguintes classes e funções globais para escrever aplicativos clientes da Internet. O recuo indica que uma classe é derivada da classe não recuada acima dela. `CGopherFile`e `CHttpFile` derivam de `CInternetFile`, por exemplo. Essas classes e funções globais são declaradas no AFXINET. H, `CFileFind`exceto , que é declarado em AFX. H.

## <a name="classes"></a>Classes

- [Cinternetsession](../mfc/reference/cinternetsession-class.md)

- [Cinternetconnection](../mfc/reference/cinternetconnection-class.md)

  - [Cftpconnection](../mfc/reference/cftpconnection-class.md)

  - [Cgopherconnection](../mfc/reference/cgopherconnection-class.md)

  - [Conexão Chttp](../mfc/reference/chttpconnection-class.md)

- [Cinternetfile](../mfc/reference/cinternetfile-class.md)

  - [Cgopherfile](../mfc/reference/cgopherfile-class.md)

  - [Chttpfile](../mfc/reference/chttpfile-class.md)

- [Cfilefind](../mfc/reference/cfilefind-class.md)

  - [Cftpfilefind](../mfc/reference/cftpfilefind-class.md)

  - [Cgopherfilefind](../mfc/reference/cgopherfilefind-class.md)

- [Cgopherlocator](../mfc/reference/cgopherlocator-class.md)

- [Cinternetexception](../mfc/reference/cinternetexception-class.md)

## <a name="global-functions"></a>Funções Globais

- [AfxParseURL](reference/internet-url-parsing-globals.md#afxparseurl)

- [AfxGetInternetHandleType](reference/internet-url-parsing-globals.md#afxgetinternethandletype)

- [AfxThrowInternetException](reference/internet-url-parsing-globals.md#afxthrowinternetexception)

## <a name="see-also"></a>Confira também

[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Pré-requisitos para classes clientes de Internet](../mfc/prerequisites-for-internet-client-classes.md)<br/>
[Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)
