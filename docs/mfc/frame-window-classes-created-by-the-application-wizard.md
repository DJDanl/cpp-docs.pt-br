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
ms.openlocfilehash: 00254bdf49015f26ac257789a15afd1e7f5cc31f
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621701"
---
# <a name="frame-window-classes-created-by-the-application-wizard"></a>Classes de janela com moldura criadas pelo Assistente de Aplicativo

Quando você cria um novo projeto MFC na caixa de diálogo **novo projeto** , além de classes de aplicativo, documento e exibição, o assistente de aplicativo cria uma classe de janela de quadro derivada para a janela principal do quadro do aplicativo. A classe é chamada `CMainFrame` por padrão e os arquivos que a contêm são nomeados MainFrm. H e MAINFRM. CPP.

Se seu aplicativo for SDI, sua `CMainFrame` classe será derivada da classe [CFrameWnd](reference/cframewnd-class.md).

Se seu aplicativo for MDI, `CMainFrame` será derivado da classe [CMDIFrameWnd](reference/cmdiframewnd-class.md). Nesse caso, `CMainFrame` implementa o quadro principal, que contém as barras de menu, barra de ferramentas e status. O assistente de aplicativo não deriva uma nova classe de janela de quadro de documento para você. Em vez disso, ele usa a implementação padrão na [classe CMDIChildWnd](reference/cmdichildwnd-class.md). A estrutura MFC cria uma janela filho para conter cada exibição (que pode ser do tipo `CScrollView` , `CEditView` , `CTreeView` , `CListView` e assim por diante) que o aplicativo requer. Se você precisar personalizar a janela do quadro do documento, poderá criar uma nova classe de janela de quadro de documento (consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md)).

Se você optar por oferecer suporte a uma barra de ferramentas, a classe também terá variáveis de membro do tipo [CToolBar](reference/ctoolbar-class.md) e [CStatusBar](reference/cstatusbar-class.md) e uma `OnCreate` função de manipulador de mensagens para inicializar as duas [barras de controle](control-bars.md).

Essas classes de janela de quadro funcionam como criadas, mas para aprimorar sua funcionalidade, você deve adicionar variáveis de membro e funções de membro. Talvez você também queira fazer com que as classes de janela manipulem outras mensagens do Windows. Para obter mais informações, consulte [alterando os estilos de uma janela criada pelo MFC](changing-the-styles-of-a-window-created-by-mfc.md).

## <a name="see-also"></a>Consulte também

[Classes de janela de quadro](frame-window-classes.md)<br/>
[Programa MFC ou arquivos de cabeçalho e origem de controle](../build/reference/mfc-program-or-control-source-and-header-files.md)
