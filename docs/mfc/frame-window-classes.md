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
ms.openlocfilehash: ffa5b966ee042120213896dc7ad9d81c048ef928
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625807"
---
# <a name="frame-window-classes"></a>Classes de janela com moldura

Cada aplicativo tem uma "janela principal do quadro", uma janela da área de trabalho que geralmente tem o nome do aplicativo em sua legenda. Cada documento geralmente tem uma "janela de quadro do documento". Uma janela de quadro de documento contém pelo menos uma exibição, que apresenta os dados do documento.

## <a name="frame-windows-in-sdi-and-mdi-applications"></a>Janelas de quadros em aplicativos SDI e MDI

Para um aplicativo SDI, há uma janela de quadro derivada da classe [CFrameWnd](reference/cframewnd-class.md). Essa janela é a janela do quadro principal e a janela do quadro do documento. Para um aplicativo MDI, a janela principal do quadro é derivada da classe [CMDIFrameWnd](reference/cmdiframewnd-class.md)e as janelas de quadro do documento, que são janelas filhas MDI, são derivadas da classe [CMDIChildWnd](reference/cmdichildwnd-class.md).

## <a name="use-the-frame-window-class-or-derive-from-it"></a>Usar a classe de janela de quadro ou derivá-la

Essas classes fornecem a maior parte da funcionalidade de janela de quadro necessária para seus aplicativos. Em circunstâncias normais, o comportamento padrão e a aparência que eles fornecem atenderão às suas necessidades. Se você precisar de funcionalidade adicional, derive dessas classes.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Classes de janela de quadro criadas pelo assistente de aplicativo](frame-window-classes-created-by-the-application-wizard.md)

- [Estilos de janela de quadro](frame-window-styles-cpp.md)

- [Alternando os estilos de uma janela criada por MFC](changing-the-styles-of-a-window-created-by-mfc.md)

## <a name="see-also"></a>Consulte também

[Janelas com moldura](frame-windows.md)
