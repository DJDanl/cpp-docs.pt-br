---
title: Manipulando o controle de dica de ferramenta | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CToolTipCtrl class [MFC], manipulating tool tip attributes
- tool tips [MFC], attributes
ms.assetid: 3600afe5-712a-4b56-8456-96e85fe879af
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 76976c0907d645ad945700c4d396217880712f11
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="manipulating-the-tool-tip-control"></a>Manipulando o controle da dica de ferramenta
Classe `CToolTipCtrl` fornece um grupo de membros que controlam os vários atributos de funções de `CToolTipCtrl` objeto e a janela de dica de ferramenta.  
  
 O inicial, o pop-up e reshow durações para as janelas de dica de ferramenta podem ser definidas e recuperadas com chamadas para [GetDelayTime](../mfc/reference/ctooltipctrl-class.md#getdelaytime) e [SetDelayTime](../mfc/reference/ctooltipctrl-class.md#setdelaytime).  
  
 Altere a aparência das janelas de dica de ferramenta com as seguintes funções:  
  
-   [GetMargin](../mfc/reference/ctooltipctrl-class.md#getmargin) e [SetMargin](../mfc/reference/ctooltipctrl-class.md#setmargin) recupera e define a largura entre a borda de dica de ferramenta e a ferramenta de texto de dica.  
  
-   [GetMaxTipWidth](../mfc/reference/ctooltipctrl-class.md#getmaxtipwidth) e [SetMaxTipWidth](../mfc/reference/ctooltipctrl-class.md#setmaxtipwidth) recupera e define a largura máxima da ferramenta de janela de dica.  
  
-   [GetTipBkColor](../mfc/reference/ctooltipctrl-class.md#gettipbkcolor) e [SetTipBkColor](../mfc/reference/ctooltipctrl-class.md#settipbkcolor) recupera e define a cor de plano de fundo da ferramenta de janela de dica.  
  
-   [GetTipTextColor](../mfc/reference/ctooltipctrl-class.md#gettiptextcolor) e [SetTipTextColor](../mfc/reference/ctooltipctrl-class.md#settiptextcolor) recupera e define a cor do texto da ferramenta de janela de dica.  
  
 Para que o controle de dica de ferramenta a ser notificado das mensagens importantes, como **WM_LBUTTONXXX** mensagens, você deve retransmitir as mensagens para o controle de dica de ferramenta. O melhor método para essa retransmissão é fazer uma chamada para [CToolTipCtrl::RelayEvent](../mfc/reference/ctooltipctrl-class.md#relayevent), além de `PreTranslateMessage` função da janela do proprietário. O exemplo a seguir ilustra um método possíveis (supondo que o controle de dica de ferramenta é chamado `m_ToolTip`):  
  
 [!code-cpp[NVC_MFCControlLadenDialog#41](../mfc/codesnippet/cpp/manipulating-the-tool-tip-control_1.cpp)]  
  
 Para remover imediatamente uma janela de dica de ferramenta, chame o [Pop](../mfc/reference/ctooltipctrl-class.md#pop) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CToolTipCtrl](../mfc/using-ctooltipctrl.md)   
 [Controles](../mfc/controls-mfc.md)

