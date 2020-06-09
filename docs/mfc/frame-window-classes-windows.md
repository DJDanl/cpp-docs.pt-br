---
title: Classes de janela com moldura (Windows)
ms.date: 11/04/2016
f1_keywords:
- vc.classes.frame
helpviewer_keywords:
- frame window classes [MFC], reference
ms.assetid: 6342ec5f-f922-4da8-a78e-2f5f994c7142
ms.openlocfilehash: 1c0a1e1e93433e0fbe07c11eb350216173e74d84
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625846"
---
# <a name="frame-window-classes-windows"></a>Classes de janela com moldura (Windows)

Janelas de quadros são janelas que estruturam um aplicativo ou uma parte de um aplicativo. Janelas de quadros geralmente contêm outras janelas, como exibições, barras de ferramentas e barras de status. No caso do `CMDIFrameWnd` , eles podem conter `CMDIChildWnd` objetos indiretamente.

[CFrameWnd](reference/cframewnd-class.md)<br/>
A classe base para a janela do quadro principal de um aplicativo SDI. Também a classe base para todas as outras classes de janela do quadro.

[CMDIFrameWnd](reference/cmdiframewnd-class.md)<br/>
A classe base para a janela do quadro principal de um aplicativo MDI.

[CMDIChildWnd](reference/cmdichildwnd-class.md)<br/>
A classe base para as janelas de quadro de documento de um aplicativo MDI.

[CMiniFrameWnd](reference/cminiframewnd-class.md)<br/>
Uma janela de quadro de meia altura normalmente vista em relação a barras de ferramentas flutuantes.

[COleIPFrameWnd](reference/coleipframewnd-class.md)<br/>
Fornece a janela do quadro para uma exibição quando um documento do servidor está sendo editado no local.

## <a name="related-class"></a>Classe relacionada

`CMenu`Fornece uma interface por meio da qual acessar os menus do seu aplicativo. Ele é útil para manipular menus dinamicamente em tempo de execução; por exemplo, ao adicionar ou excluir itens de menu de acordo com o contexto. Embora os menus sejam usados com mais frequência com janelas de quadros, eles também podem ser usados com caixas de diálogo e outras janelas não-filhas.

[CMenu](reference/cmenu-class.md)<br/>
Encapsula um `HMENU` identificador para a barra de menus e os menus pop-up do aplicativo.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
