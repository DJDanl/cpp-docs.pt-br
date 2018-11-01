---
title: Classes de janela com moldura
ms.date: 11/04/2016
helpviewer_keywords:
- frame window classes [MFC], about frame window classes
- frame window classes [MFC]
- windows [MFC], MDI
- document frame windows [MFC], classes
- single document interface (SDI), frame windows
- window classes [MFC], frame
- MFC, frame windows
- MDI [MFC], frame windows
- classes [MFC], window
ms.assetid: c27e43a7-8ad0-4759-b1b7-43f4725f4132
ms.openlocfilehash: ffeb3339eedb9db7108a26ad4a5840e3921df5fb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50668943"
---
# <a name="frame-window-classes"></a>Classes de janela com moldura

Cada aplicativo tem uma "janela de quadro principal", uma janela da área de trabalho que geralmente tem o nome do aplicativo na sua legenda. Cada documento normalmente tem uma "janela de quadro do documento". Uma janela de quadro do documento contém pelo menos uma exibição, que apresenta os dados do documento.

## <a name="frame-windows-in-sdi-and-mdi-applications"></a>Windows de quadro SDI e MDI aplicativos

Para um aplicativo SDI, há uma janela de quadro derivada da classe [CFrameWnd](../mfc/reference/cframewnd-class.md). Essa janela é a janela do quadro principal e a janela de quadro do documento. Para um aplicativo MDI, a janela do quadro principal é derivada da classe [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md), e as janelas de quadro do documento, que são janelas filho MDI, são derivadas da classe [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md).

## <a name="use-the-frame-window-class-or-derive-from-it"></a>Use a classe de janela com moldura ou derivar dele

Essas classes fornecem a maioria das funcionalidades de janela com moldura que você precisa para seus aplicativos. Em circunstâncias normais, o comportamento padrão e a aparência que eles fornecem atenderá às suas necessidades. Se você precisar da funcionalidade adicional, derivam dessas classes.

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Classes de janela com moldura criadas pelo Assistente de aplicativo](../mfc/frame-window-classes-created-by-the-application-wizard.md)

- [Estilos de janela com moldura](../mfc/frame-window-styles-cpp.md)

- [Alternando os estilos de uma janela criada por MFC](../mfc/changing-the-styles-of-a-window-created-by-mfc.md)

## <a name="see-also"></a>Consulte também

[Janelas com moldura](../mfc/frame-windows.md)

