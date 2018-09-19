---
title: Como o MFC torna mais fácil criar aplicativos de cliente da Internet | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Internet client applications [MFC], MFC
- Internet applications [MFC], MFC
- MFC, Internet applications
ms.assetid: 94437b3f-f15c-437d-b5fd-264a2efec9ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 26380dc7e01449e4700ddf403c7395714287ed38
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46407160"
---
# <a name="how-mfc-makes-it-easier-to-create-internet-client-applications"></a>Como o MFC facilita a criação de aplicativos clientes da Internet

O Microsoft Foundation Classes encapsulam as funções de extensão de Internet Win32 (WinInet) de uma maneira que fornece um contexto familiar para programadores do MFC. O MFC fornece três classes de arquivo da Internet ([CInternetFile](../mfc/reference/cinternetfile-class.md), [CHttpFile](../mfc/reference/chttpfile-class.md), e [CGopherFile](../mfc/reference/cgopherfile-class.md)) deriva o [CStdioFile](../mfc/reference/cstdiofile-class.md) classe . Não apenas essas classes fazem recuperar e manipular dados de Internet familiares para programadores que já usaram `CStdioFile` para arquivos locais, mas com essas classes pode manipular arquivos locais e arquivos de Internet de maneira transparente e consistente.

As classes WinInet MFC fornecem a mesma funcionalidade que `CStdioFile` para dados que são transferidos pela Internet. Essas classes abstraem os protocolos de Internet para HTTP, FTP e gopher em um aplicativo de alto nível interface de programação, fornecendo um caminho rápido e simples para tornar os aplicativos sensíveis à Internet. Por exemplo, se conectar a um servidor FTP ainda requer várias etapas em um nível baixo, mas como um desenvolvedor MFC, você só precisará fazer uma chamada para `CInternetSession::GetFTPConnection` para criar essa conexão.

Além disso, as classes WinInet MFC fornecem as seguintes vantagens:

- Armazenados em buffer de e/s

- Identificadores de tipo seguro para seus dados

- Parâmetros padrão para muitas funções

- Tratamento de exceção para erros comuns da Internet

- Limpeza automática de identificadores abertos e conexões

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Como o WinInet facilita a criação de aplicativos cliente da Internet](../mfc/how-wininet-makes-it-easier-to-create-internet-client-applications.md)

