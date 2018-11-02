---
title: Framework (MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- encapsulation [MFC], Win32 API
- MFC, application framework
- wrapper classes [MFC], explained
- Win32 [MFC], API encapsulation by MFC
- application framework [MFC], about MFC application framework
- APIs [MFC], encapsulation by MFC Win32
- encapsulation [MFC]
- Windows API [MFC], encapsulation by MFC
- encapsulated Win32 API [MFC]
ms.assetid: 3be0fec8-9843-4119-ae42-ece993ef500b
ms.openlocfilehash: ff29a867a8351a51ad7f09a5ca31d871fc67bab8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50589300"
---
# <a name="framework-mfc"></a>Framework (MFC)

Seu trabalho com a estrutura da biblioteca Microsoft Foundation Class (MFC) baseia-se em grande parte algumas classes principais e várias ferramentas do Visual C++. Algumas classes encapsulam uma grande parte da interface de programação de aplicativo (API) do Win32. Outras classes encapsulam os conceitos de aplicativo, como documentos, exibições e o aplicativo em si. Ainda outros encapsulam recursos OLE e a funcionalidade de acesso a dados ODBC e DAO.

Por exemplo, o conceito do Win32 da janela é encapsulado pela classe do MFC `CWnd`. Ou seja, uma classe C++ chamado `CWnd` encapsula ou "encapsula" o `HWND` identificador que representa uma janela do Windows. Da mesma forma, a classe `CDialog` encapsula as caixas de diálogo do Win32.

Encapsulamento significa que a classe do C++ `CWnd`, por exemplo, contém uma variável de membro do tipo `HWND`, e funções de membro da classe encapsulam chamadas para funções do Win32 que usam um `HWND` como um parâmetro. As funções de membro de classe normalmente tem o mesmo nome que a função Win32 que eles encapsulam.

## <a name="in-this-section"></a>Nesta seção

[SDI e MDI](../mfc/sdi-and-mdi.md)

[Documentos, exibições e o Framework](../mfc/documents-views-and-the-framework.md)

[Assistentes e editores de recursos](../mfc/wizards-and-the-resource-editors.md)

## <a name="in-related-sections"></a>Nas seções relacionadas

[Compilando no Framework](../mfc/building-on-the-framework.md)

[Como o Framework chama o código](../mfc/how-the-framework-calls-your-code.md)

[CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)

[Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)

[Tratamento e mapeamento de mensagem](../mfc/message-handling-and-mapping.md)

[Objetos de janela](../mfc/window-objects.md)

## <a name="see-also"></a>Consulte também

[Usando as classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md)
