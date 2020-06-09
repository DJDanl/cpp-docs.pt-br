---
title: Métodos de criação de dicas de ferramenta
ms.date: 11/04/2016
helpviewer_keywords:
- CToolTipCtrl class [MFC], creating tool tips
- tool tips [MFC], tool tip controls
- tool tips [MFC], creating
ms.assetid: b015e9f4-ddfb-49a4-a5a6-fa2d45e4d328
ms.openlocfilehash: 26f31705068df009e906d50451efa9ea6572d7e6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625450"
---
# <a name="methods-of-creating-tool-tips"></a>Métodos de criação de dicas de ferramenta

O MFC fornece três classes para criar e gerenciar o controle de dica de ferramenta: [CWnd](reference/cwnd-class.md), [CToolBarCtrl](reference/ctoolbarctrl-class.md), [CToolTipCtrl](reference/ctooltipctrl-class.md) e [CMFCToolTipCtrl](reference/cmfctooltipctrl-class.md). As funções de membro da dica de ferramenta nessas classes encapsulam a API de controle comum do Windows. Classe `CToolBarCtrl` e classe `CToolTipCtrl` são derivadas da classe `CWnd` .

`CWnd`fornece quatro funções de membro para criar e gerenciar dicas de ferramenta: [EnableToolTips](reference/cwnd-class.md#enabletooltips), [CancelToolTips](reference/cwnd-class.md#canceltooltips), [FilterToolTipMessage](reference/cwnd-class.md#filtertooltipmessage)e [OnToolHitTest](reference/cwnd-class.md#ontoolhittest). Consulte essas funções de membro individuais para obter mais informações sobre como elas implementam dicas de ferramenta.

Se você criar uma barra de ferramentas usando `CToolBarCtrl` o, poderá implementar dicas de ferramenta para essa barra de ferramentas diretamente usando as seguintes funções de membro: [GetToolTips](reference/ctoolbarctrl-class.md#gettooltips) e [SetToolTips](reference/ctoolbarctrl-class.md#settooltips). Consulte estas funções membro individuais e [manipulando notificações da dica de ferramenta](handling-tool-tip-notifications.md) para obter mais informações sobre como elas implementam dicas de ferramenta.

A `CToolTipCtrl` classe fornece a funcionalidade do controle de dica de ferramenta comum do Windows. Um único controle de dica de ferramenta pode fornecer informações para mais de uma ferramenta. Uma ferramenta é uma janela, como uma janela ou controle filho, ou uma área retangular definida pelo aplicativo dentro de uma área do cliente da janela. A classe [CMFCToolTipCtrl](reference/cmfctooltipctrl-class.md) deriva de `CToolTipCtrl` e fornece mais estilos visuais e funcionalidades.

## <a name="see-also"></a>Consulte também

[Usando CToolTipCtrl](using-ctooltipctrl.md)<br/>
[Controles](controls-mfc.md)
