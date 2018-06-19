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
ms.openlocfilehash: 26f6e7cbf8c6464afa90c52f9cd91dcdb55de767
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33349526"
---
# <a name="methods-of-creating-tool-tips"></a>Métodos de criação de dicas de ferramenta
MFC fornece três classes para criar e gerenciar a ferramenta de controle da Dica: [CWnd](../mfc/reference/cwnd-class.md), [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md), [CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md) e [CMFCToolTipCtrl](../mfc/reference/cmfctooltipctrl-class.md). As funções de membro de dica de ferramenta nessas classes encapsular a API de controle comum do Windows. Classe `CToolBarCtrl` e classe `CToolTipCtrl` são derivadas da classe `CWnd`.  
  
 `CWnd` fornece quatro funções de membro para criar e gerenciar as dicas de ferramenta: [EnableToolTips](../mfc/reference/cwnd-class.md#enabletooltips), [CancelToolTips](../mfc/reference/cwnd-class.md#canceltooltips), [FilterToolTipMessage](../mfc/reference/cwnd-class.md#filtertooltipmessage), e [OnToolHitTest ](../mfc/reference/cwnd-class.md#ontoolhittest). Consulte essas funções de membro individual para obter mais informações sobre como eles implementem dicas de ferramenta.  
  
 Se você criar uma barra de ferramentas usando `CToolBarCtrl`, você pode implementar dicas de ferramenta para a barra de ferramentas diretamente usando as seguintes funções de membro: [GetToolTips](../mfc/reference/ctoolbarctrl-class.md#gettooltips) e [SetToolTips](../mfc/reference/ctoolbarctrl-class.md#settooltips). Consulte essas funções de membro individual e [tratamento notificações da dica de ferramenta](../mfc/handling-tool-tip-notifications.md) para obter mais informações sobre como eles implementem dicas de ferramenta.  
  
 O `CToolTipCtrl` classe fornece a funcionalidade de controle de dica de ferramenta comuns do Windows. Um controle de dica de ferramenta único pode fornecer informações para mais de uma ferramenta. Uma ferramenta é tanto uma janela, como uma janela filho controle ou uma área retangular definido pelo aplicativo dentro da área cliente da janela. O [CMFCToolTipCtrl](../mfc/reference/cmfctooltipctrl-class.md) classe derivada de `CToolTipCtrl` e fornece funcionalidade e estilos visuais adicionais.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CToolTipCtrl](../mfc/using-ctooltipctrl.md)   
 [Controles](../mfc/controls-mfc.md)

