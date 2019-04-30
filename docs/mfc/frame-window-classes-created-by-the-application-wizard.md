---
title: Classes de janela com moldura criadas pelo Assistente de Aplicativo
ms.date: 11/04/2016
f1_keywords:
- CMainFrame
helpviewer_keywords:
- application wizards [MFC], frame window classes created by
- window classes [MFC]
- classes [MFC], frame-window
- CMDIFrameWnd class [MFC], frame windows
- window classes [MFC], frame
- CFrameWnd class [MFC], frame windows
- CMDIChildWnd class [MFC], frame windows
- frame window classes [MFC], created by application wizards
- CMainFrame class [MFC]
ms.assetid: 9947df73-4470-49a0-ac61-7b6ee401a74e
ms.openlocfilehash: 46da8fc0cb98406bdf97285d7c6f824afd61c4bb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62392811"
---
# <a name="frame-window-classes-created-by-the-application-wizard"></a>Classes de janela com moldura criadas pelo Assistente de Aplicativo

Quando você criar um novo MFC de projeto das **novo projeto** caixa de diálogo, além de aplicativos, documentos e classes de exibição, o Assistente de aplicativo cria uma classe derivada da janela do quadro de janela de quadro principal do seu aplicativo. A classe é chamada `CMainFrame` por padrão e os arquivos que contêm a ele são nomeados MAINFRM. H e MAINFRM. CPP.

Se seu aplicativo SDI, sua `CMainFrame` classe é derivada da classe [CFrameWnd](../mfc/reference/cframewnd-class.md).

Se seu aplicativo MDI, `CMainFrame` é derivado da classe [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md). Nesse caso, `CMainFrame` implementa o quadro principal, que mantém as barras de menu, barra de ferramentas e status. O Assistente de aplicativo não derivar uma nova classe de janela com moldura de documento para você. Em vez disso, ele usa a implementação padrão na [classe CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md). A estrutura MFC cria uma janela filho para conter cada modo de exibição (que pode ser do tipo `CScrollView`, `CEditView`, `CTreeView`, `CListView`e assim por diante) que o aplicativo requer. Se você precisar personalizar a janela de quadro do documento, você pode criar uma nova classe de janela com moldura de documento (consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md)).

Se você optar por dar suporte a uma barra de ferramentas, a classe também tem variáveis de membro do tipo [CToolBar](../mfc/reference/ctoolbar-class.md) e [CStatusBar](../mfc/reference/cstatusbar-class.md) e um `OnCreate` função de manipulador de mensagens para inicializar os dois [ barras de controle](../mfc/control-bars.md).

Essas classes de janela com moldura funcionam conforme criados, mas para aprimorar sua funcionalidade, você deve adicionar variáveis de membro e funções de membro. Você talvez queira ter suas classes de janela a lidar com outras mensagens do Windows. Para obter mais informações, consulte [alternando os estilos de uma janela criada por MFC](../mfc/changing-the-styles-of-a-window-created-by-mfc.md).

## <a name="see-also"></a>Consulte também

[Classes de janela com moldura](../mfc/frame-window-classes.md)<br/>
[Programa MFC ou origem de controle e arquivos de cabeçalho](../build/reference/mfc-program-or-control-source-and-header-files.md)

