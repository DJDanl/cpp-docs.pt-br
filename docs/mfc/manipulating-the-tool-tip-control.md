---
title: Manipulando o controle da dica de ferramenta
ms.date: 11/04/2016
helpviewer_keywords:
- CToolTipCtrl class [MFC], manipulating tool tip attributes
- tool tips [MFC], attributes
ms.assetid: 3600afe5-712a-4b56-8456-96e85fe879af
ms.openlocfilehash: 61bc35e8b19ba7645736b939acac6cdaa6cb7316
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622418"
---
# <a name="manipulating-the-tool-tip-control"></a>Manipulando o controle da dica de ferramenta

`CToolTipCtrl`Fornece um grupo de funções de membro que controlam os vários atributos do `CToolTipCtrl` objeto e a janela de dica de ferramenta.

As durações inicial, pop-up e Reexibir para as janelas de dicas de ferramenta podem ser definidas e recuperadas com chamadas para [GetDelayTime](reference/ctooltipctrl-class.md#getdelaytime) e [SetDelayTime](reference/ctooltipctrl-class.md#setdelaytime).

Altere a aparência das janelas de dicas de ferramenta com as seguintes funções:

- [GetMargin](reference/ctooltipctrl-class.md#getmargin) e [SetMargin](reference/ctooltipctrl-class.md#setmargin) recupera e define a largura entre a borda da dica de ferramenta e o texto da dica de ferramenta.

- [GetMaxTipWidth](reference/ctooltipctrl-class.md#getmaxtipwidth) e [SetMaxTipWidth](reference/ctooltipctrl-class.md#setmaxtipwidth) recupera e define a largura máxima da janela de dica de ferramenta.

- [GetTipBkColor](reference/ctooltipctrl-class.md#gettipbkcolor) e [SetTipBkColor](reference/ctooltipctrl-class.md#settipbkcolor) recupera e define a cor do plano de fundo da janela de dica de ferramenta.

- [GetTipTextColor](reference/ctooltipctrl-class.md#gettiptextcolor) e [SetTipTextColor](reference/ctooltipctrl-class.md#settiptextcolor) recupera e define a cor do texto da janela de dica de ferramenta.

Para que o controle de dica de ferramenta seja notificado sobre mensagens importantes, como WM_LBUTTONXXX mensagens, você deve retransmitir as mensagens para o controle de dica de ferramenta. O melhor método para essa retransmissão é fazer uma chamada para [CToolTipCtrl:: RelayEvent](reference/ctooltipctrl-class.md#relayevent), na `PreTranslateMessage` função da janela do proprietário. O exemplo a seguir ilustra um método possível (supondo que o controle de dica de ferramenta seja chamado `m_ToolTip` ):

[!code-cpp[NVC_MFCControlLadenDialog#41](codesnippet/cpp/manipulating-the-tool-tip-control_1.cpp)]

Para remover imediatamente uma janela de dica de ferramenta, chame a função de membro [pop](reference/ctooltipctrl-class.md#pop) .

## <a name="see-also"></a>Consulte também

[Usando CToolTipCtrl](using-ctooltipctrl.md)<br/>
[Controles](controls-mfc.md)
