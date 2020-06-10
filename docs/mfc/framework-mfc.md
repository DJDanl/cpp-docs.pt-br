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
ms.openlocfilehash: b02d5a1862a278f46591895f20f58a97367b5ab2
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618792"
---
# <a name="framework-mfc"></a>Framework (MFC)

Seu trabalho com a estrutura de biblioteca do Microsoft Foundation Class (MFC) é baseado amplamente em algumas classes principais e várias ferramentas de Visual C++. Algumas classes encapsulam uma grande parte da API (interface de programação de aplicativo) do Win32. Outras classes encapsulam conceitos de aplicativos, como documentos, exibições e o próprio aplicativo. Ainda outros encapsulam recursos OLE e a funcionalidade de acesso a dados ODBC e DAO.  (O DAO tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto.)

Por exemplo, o conceito Win32's da janela é encapsulado pela classe do MFC `CWnd` . Ou seja, uma classe C++ chamada `CWnd` encapsula ou "encapsula" o `HWND` identificador que representa uma janela do Windows. Da mesma forma, a classe `CDialog` encapsula as caixas de diálogo do Win32.

O encapsulamento significa que a classe C++ `CWnd` , por exemplo, contém uma variável de membro do tipo `HWND` , e as funções de membro da classe encapsulam chamadas para funções do Win32 que usam um `HWND` como parâmetro. As funções de membro de classe normalmente têm o mesmo nome que a função do Win32 que encapsulam.

## <a name="in-this-section"></a>Nesta seção

[SDI e MDI](sdi-and-mdi.md)

[Documentos, exibições e a estrutura](documents-views-and-the-framework.md)

[Assistentes e editores de recursos](wizards-and-the-resource-editors.md)

## <a name="in-related-sections"></a>Nas seções relacionadas

[Criando na estrutura](building-on-the-framework.md)

[Como o Framework chama o código](how-the-framework-calls-your-code.md)

[CWinApp: a classe do aplicativo](cwinapp-the-application-class.md)

[Modelos de documento e o processo de criação de documento/exibição](document-templates-and-the-document-view-creation-process.md)

[Tratamento e mapeamento de mensagem](message-handling-and-mapping.md)

[Objetos de janela](window-objects.md)

## <a name="see-also"></a>Consulte também

[Usando as classes para escrever aplicativos para Windows](using-the-classes-to-write-applications-for-windows.md)
