---
title: Habilitando dicas de ferramenta
ms.date: 11/04/2016
helpviewer_keywords:
- initializing tool tips [MFC]
- enabling tool tips [MFC]
- tool tips [MFC], initializing
- tool tips [MFC], enabling
ms.assetid: 06b7c889-7722-4ce6-8b88-9efa50fe6369
ms.openlocfilehash: 892ed76ef7e021544505600110cd2569d6078312
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57285939"
---
# <a name="enabling-tool-tips"></a>Habilitando dicas de ferramenta

Você pode habilitar o suporte à dica de ferramenta para os controles filho de uma janela (como os controles em uma caixa de diálogo ou modo de exibição de formulário).

### <a name="to-enable-tool-tips-for-the-child-controls-of-a-window"></a>Para habilitar dicas de ferramenta para os controles filho de uma janela

1. Chamar `EnableToolTips` para a janela para o qual você deseja fornecer dicas de ferramenta.

1. Forneça uma cadeia de caracteres para cada controle em seu [notificação TTN_NEEDTEXT](../mfc/handling-ttn-needtext-notification-for-tool-tips.md) manipulador. O manipulador é no mapa de mensagens da janela que contém os controles filho (por exemplo, sua classe de exibição de formulário). Esse manipulador deve chamar uma função que identifica o controle e define **pszText** para especificar o texto usado pelo controle de dica de ferramenta.

## <a name="see-also"></a>Consulte também

[Dicas de ferramenta no Windows não derivadas de CFrameWnd](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md)
