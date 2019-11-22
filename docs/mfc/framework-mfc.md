---
title: Framework (MFC)
ms.date: 09/17/2019
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
ms.openlocfilehash: 387f53e3123b6863fcf218da39c7c5e356eb8219
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74303411"
---
# <a name="framework-mfc"></a>Framework (MFC)

Seu trabalho com a estrutura de biblioteca do Microsoft Foundation Class (MFC) baseia-se amplamente em algumas classes principais e em C++ várias ferramentas visuais. Algumas classes encapsulam uma grande parte da API (interface de programação de aplicativo) do Win32. Outras classes encapsulam conceitos de aplicativos, como documentos, exibições e o próprio aplicativo. Ainda outros encapsulam recursos OLE e a funcionalidade de acesso a dados ODBC e DAO.  (O DAO tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto.)

Por exemplo, o conceito Win32's da janela é encapsulado pela classe MFC `CWnd`. Ou seja, uma C++ classe chamada `CWnd` encapsula ou "encapsula" o identificador de `HWND` que representa uma janela do Windows. Da mesma forma, a classe `CDialog` encapsula as caixas de diálogo do Win32.

Encapsulamento significa que a C++ classe `CWnd`, por exemplo, contém uma variável de membro do tipo `HWND`, e as funções de membro da classe encapsulam chamadas para funções do Win32 que usam um `HWND` como um parâmetro. As funções de membro de classe normalmente têm o mesmo nome que a função do Win32 que encapsulam.

## <a name="in-this-section"></a>Nesta seção

[SDI e MDI](../mfc/sdi-and-mdi.md)

[Documentos, exibições e o Framework](../mfc/documents-views-and-the-framework.md)

[Assistentes e editores de recursos](../mfc/wizards-and-the-resource-editors.md)

## <a name="in-related-sections"></a>Em seções relacionadas

[Compilando no Framework](../mfc/building-on-the-framework.md)

[Como o Framework chama o código](../mfc/how-the-framework-calls-your-code.md)

[CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)

[Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)

[Tratamento e mapeamento de mensagem](../mfc/message-handling-and-mapping.md)

[Objetos de janela](../mfc/window-objects.md)

## <a name="see-also"></a>Consulte também

[Usando as classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md)
