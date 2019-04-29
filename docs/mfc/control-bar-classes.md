---
title: Classes da barra de controle
ms.date: 11/04/2016
f1_keywords:
- vc.classes.control
helpviewer_keywords:
- control bars [MFC], classes
ms.assetid: 11009103-cad8-4309-85ce-3d2e858e1818
ms.openlocfilehash: 3426d84eab888a6fe78b663945776fff2fe708dd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62301949"
---
# <a name="control-bar-classes"></a>Classes da barra de controle

Barras de controle são anexadas a uma janela do quadro. Elas contêm botões, painéis de status ou um modelo de caixa de diálogo. Barras de controle de flutuante, também chamadas de paletas de ferramenta, são implementadas, anexando-as para um [CMiniFrameWnd](../mfc/reference/cminiframewnd-class.md) objeto.

## <a name="framework-control-bars"></a>Barras de controle de estrutura

Essas barras de controle são parte integrante da estrutura MFC. Eles são mais fáceis de usar e mais potente do que o Windows barras de controle porque eles são integrados com o framework. A maioria dos aplicativos do MFC usam essas barras de controle, em vez das barras de controle do Windows.

[CControlBar](../mfc/reference/ccontrolbar-class.md)<br/>
A classe base para barras de controle MFC listados nesta seção. Uma barra de controle é uma janela alinhada à borda de uma janela de quadro. A barra de controle contém `HWND`-com base em controles filho ou controles que não se baseia em um `HWND`, como botões da barra de ferramentas.

[CDialogBar](../mfc/reference/cdialogbar-class.md)<br/>
Uma barra de controle que se baseia em um modelo de caixa de diálogo.

[CReBar](../mfc/reference/crebar-class.md)<br/>
Dá suporte a uma barra de ferramentas que pode conter windows filho adicionais na forma de controles.

[CToolBar](../mfc/reference/ctoolbar-class.md)<br/>
Janelas de controle de barra de ferramentas que contém botões de comando de bitmap não com base em um `HWND`. A maioria dos aplicativos MFC usar essa classe em vez de `CToolBarCtrl`.

[CStatusBar](../mfc/reference/cstatusbar-class.md)<br/>
A classe base para o windows de controle de barra de status. A maioria dos aplicativos MFC usar essa classe em vez de `CStatusBarCtrl`.

## <a name="windows-control-bars"></a>Barras de controle do Windows

Essas barras de controle são invólucros finos para os controles do Windows correspondentes. Porque eles não são integrados com o framework, eles são mais difíceis de usar do que as barras de controle listadas anteriormente. A maioria dos aplicativos MFC usar as barras de controle listadas anteriormente.

[CRebarCtrl](../mfc/reference/crebarctrl-class.md)<br/>
Implementa o controle interno do `CRebar` objeto.

[CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)<br/>
Uma janela horizontal, geralmente dividida em painéis, no qual um aplicativo pode exibir informações de status.

[CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)<br/>
Fornece a funcionalidade do controle de comum de barra de ferramentas do Windows.

## <a name="related-classes"></a>Classes relacionadas

[CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md)<br/>
Uma pequena janela pop-up que exibe uma única linha de texto que descreve a finalidade de uma ferramenta em um aplicativo.

[CDockState](../mfc/reference/cdockstate-class.md)<br/>
Lida com armazenamento persistente de dados de estado para barras de controle de encaixe.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
