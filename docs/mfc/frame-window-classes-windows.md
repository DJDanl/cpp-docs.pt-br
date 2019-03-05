---
title: Classes de janela com moldura (Windows)
ms.date: 11/04/2016
f1_keywords:
- vc.classes.frame
helpviewer_keywords:
- frame window classes [MFC], reference
ms.assetid: 6342ec5f-f922-4da8-a78e-2f5f994c7142
ms.openlocfilehash: 3e56bd0f449992118db75a44c39b6e0e15cb0d86
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57270989"
---
# <a name="frame-window-classes-windows"></a>Classes de janela com moldura (Windows)

Janelas de quadro são janelas que um aplicativo ou uma parte de um aplicativo de quadro. Janelas com moldura geralmente contêm outras janelas, como exibições, barras de ferramentas e barras de status. No caso de `CMDIFrameWnd`, eles podem conter `CMDIChildWnd` objetos indiretamente.

[CFrameWnd](../mfc/reference/cframewnd-class.md)<br/>
A classe base para a janela do quadro principal de um aplicativo SDI. Também é a classe base para todas as outras classes de janela de quadro.

[CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md)<br/>
A classe base para a janela do quadro principal de um aplicativo MDI.

[CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md)<br/>
A classe base para janelas de quadro do documento de um aplicativo MDI.

[CMiniFrameWnd](../mfc/reference/cminiframewnd-class.md)<br/>
Uma janela do quadro de metade da altura normalmente Vista em torno de barras de ferramentas flutuantes.

[COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md)<br/>
Fornece a janela do quadro para um modo de exibição quando um documento do servidor está sendo editado no local.

## <a name="related-class"></a>Classe relacionada

Classe `CMenu` fornece uma interface por meio do qual acessar os menus do seu aplicativo. É útil para manipulando menus dinamicamente em tempo de execução; Por exemplo, ao adicionar ou excluir itens de menu de acordo com o contexto. Embora menus são geralmente usadas com janelas de quadro, eles também podem ser usados com caixas de diálogo e outras janelas nonchild.

[CMenu](../mfc/reference/cmenu-class.md)<br/>
Encapsula um `HMENU` identificador para a barra de menus e menus pop-up do aplicativo.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
