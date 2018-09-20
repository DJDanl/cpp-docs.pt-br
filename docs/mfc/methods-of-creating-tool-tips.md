---
title: Métodos de criação de dicas de ferramenta | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CToolTipCtrl class [MFC], creating tool tips
- tool tips [MFC], tool tip controls
- tool tips [MFC], creating
ms.assetid: b015e9f4-ddfb-49a4-a5a6-fa2d45e4d328
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 16b96228bd2f101e30605e555dbbc75b0dff78c3
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46374007"
---
# <a name="methods-of-creating-tool-tips"></a>Métodos de criação de dicas de ferramenta

O MFC fornece três classes para criar e gerenciar a ferramenta de controle da Dica: [CWnd](../mfc/reference/cwnd-class.md), [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md), [CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md) e [CMFCToolTipCtrl](../mfc/reference/cmfctooltipctrl-class.md). As funções de membro de dica de ferramenta nessas classes encapsulam a API de controle comum do Windows. Classe `CToolBarCtrl` e a classe `CToolTipCtrl` são derivadas da classe `CWnd`.

`CWnd` fornece quatro funções de membro para criar e gerenciar as dicas de ferramenta: [EnableToolTips](../mfc/reference/cwnd-class.md#enabletooltips), [CancelToolTips](../mfc/reference/cwnd-class.md#canceltooltips), [FilterToolTipMessage](../mfc/reference/cwnd-class.md#filtertooltipmessage), e [OnToolHitTest ](../mfc/reference/cwnd-class.md#ontoolhittest). Consulte essas funções de membro individual para obter mais informações sobre como eles implementam dicas de ferramenta.

Se você criar usando uma barra de ferramentas `CToolBarCtrl`, você pode implementar dicas de ferramenta para aquela barra de ferramentas diretamente usando as seguintes funções de membro: [GetToolTips](../mfc/reference/ctoolbarctrl-class.md#gettooltips) e [SetToolTips](../mfc/reference/ctoolbarctrl-class.md#settooltips). Consulte essas funções de membro individual e [manipulando notificações da dica de ferramenta](../mfc/handling-tool-tip-notifications.md) para obter mais informações sobre como eles implementam dicas de ferramenta.

O `CToolTipCtrl` classe fornece a funcionalidade do controle de dica de ferramenta comuns do Windows. Um controle de dica de ferramenta única pode fornecer informações para mais de uma ferramenta. Uma ferramenta é qualquer janela, como uma janela filho, controle ou uma área retangular definida pelo aplicativo dentro de uma área da janela cliente. O [CMFCToolTipCtrl](../mfc/reference/cmfctooltipctrl-class.md) classe deriva de `CToolTipCtrl` e fornece a funcionalidade e os estilos visuais adicionais.

## <a name="see-also"></a>Consulte também

[Usando CToolTipCtrl](../mfc/using-ctooltipctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

