---
title: Classes da barra de controle
ms.date: 11/04/2016
helpviewer_keywords:
- control bars [MFC], classes
ms.assetid: 11009103-cad8-4309-85ce-3d2e858e1818
ms.openlocfilehash: a050c5d2f7396324c2c380a03fc28e01ab992208
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440957"
---
# <a name="control-bar-classes"></a>Classes da barra de controle

As barras de controle são anexadas a uma janela do quadro. Eles contêm botões, painéis de status ou um modelo de caixa de diálogo. Barras de controle flutuantes livres, também chamadas de paletas de ferramentas, são implementadas anexando-as a um objeto [CMiniFrameWnd](../mfc/reference/cminiframewnd-class.md) .

## <a name="framework-control-bars"></a>Barras de controle de estrutura

Essas barras de controle são parte integrante da estrutura do MFC. Elas são mais fáceis de usar e mais poderosas do que as barras de controle do Windows porque estão integradas com a estrutura. A maioria dos aplicativos MFC usa essas barras de controle em vez das barras de controle do Windows.

[CControlBar](../mfc/reference/ccontrolbar-class.md)<br/>
A classe base para barras de controle do MFC listadas nesta seção. Uma barra de controle é uma janela alinhada à borda de uma janela do quadro. A barra de controle contém controles filho baseados em `HWND`ou controles não baseados em um `HWND`, como botões da barra de ferramentas.

[CDialogBar](../mfc/reference/cdialogbar-class.md)<br/>
Uma barra de controle baseada em um modelo de caixa de diálogo.

[CReBar](../mfc/reference/crebar-class.md)<br/>
Dá suporte a uma barra de ferramentas que pode conter janelas filho adicionais na forma de controles.

[CToolBar](../mfc/reference/ctoolbar-class.md)<br/>
As janelas de controle da barra de ferramentas que contêm botões de comando de bitmap não são baseadas em um `HWND`. A maioria dos aplicativos MFC usa essa classe em vez de `CToolBarCtrl`.

[CStatusBar](../mfc/reference/cstatusbar-class.md)<br/>
A classe base para janelas de controle de barra de status. A maioria dos aplicativos MFC usa essa classe em vez de `CStatusBarCtrl`.

## <a name="windows-control-bars"></a>Barras de controle do Windows

Essas barras de controle são invólucros finos para os controles correspondentes do Windows. Como eles não são integrados à estrutura, eles são mais difíceis de usar do que as barras de controle anteriormente listadas. A maioria dos aplicativos MFC usa as barras de controle anteriormente listadas.

[CRebarCtrl](../mfc/reference/crebarctrl-class.md)<br/>
Implementa o controle interno do objeto `CRebar`.

[CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)<br/>
Uma janela horizontal, geralmente dividida em painéis, em que um aplicativo pode exibir informações de status.

[CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)<br/>
Fornece a funcionalidade do controle comum da barra de ferramentas do Windows.

## <a name="related-classes"></a>Classes relacionadas

[CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md)<br/>
Uma pequena janela pop-up que exibe uma única linha de texto que descreve a finalidade de uma ferramenta em um aplicativo.

[CDockState](../mfc/reference/cdockstate-class.md)<br/>
Lida com o armazenamento persistente de dados de estado de encaixe para barras de controle.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
