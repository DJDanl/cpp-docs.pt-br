---
title: 'Windows Sockets: Convertendo cadeias de caracteres'
ms.date: 11/04/2016
helpviewer_keywords:
- Windows Sockets [MFC], multibyte character string conversion
- sockets [MFC], multibyte character string conversion issues
- string conversion, multibyte character strings
ms.assetid: 9df522b5-6b23-41e0-bb96-e4e623baf141
ms.openlocfilehash: eaf278fc2689f0afa9ab6ff30f1294c36de5d7ac
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62217385"
---
# <a name="windows-sockets-converting-strings"></a>Windows Sockets: Convertendo cadeias de caracteres

Este artigo e dois artigos complementares explicam vários problemas na programação do Windows Sockets. Este artigo aborda como converter cadeias de caracteres. Os outros problemas são abordados em [Windows Sockets: Bloqueando](../mfc/windows-sockets-blocking.md) e [Windows Sockets: A ordem de bytes](../mfc/windows-sockets-byte-ordering.md).

Se você usar ou derivar da classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md), você precisará gerenciar esses problemas por conta própria. Se você usar ou derivar da classe [CSocket](../mfc/reference/csocket-class.md), gerencia MFC-los para você.

## <a name="converting-strings"></a>Convertendo cadeias de caracteres

Se você se comunicar entre os aplicativos que usam cadeias de caracteres armazenadas em diferentes formatos de caractere largo, como Unicode ou caracteres multibyte (MBCS) de define, ou entre uma destas opções e um aplicativo usando cadeias de caracteres ANSI, você deve gerenciar as conversões por conta própria em `CAsyncSocket`. O `CArchive` objeto usado com um `CSocket` objeto gerencia essa conversão para você por meio dos recursos da classe [CString](../atl-mfc-shared/reference/cstringt-class.md). Para obter mais informações, consulte a especificação de soquetes do Windows, localizada no SDK do Windows.

Para obter mais informações, consulte:

- [Windows Sockets: usar a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: usar soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)

- [Windows Sockets: tela de fundo](../mfc/windows-sockets-background.md)

- [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)
