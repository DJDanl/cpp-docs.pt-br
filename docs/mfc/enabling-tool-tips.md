---
title: Habilitando dicas de ferramenta
ms.date: 11/04/2016
helpviewer_keywords:
- initializing tool tips [MFC]
- enabling tool tips [MFC]
- tool tips [MFC], initializing
- tool tips [MFC], enabling
ms.assetid: 06b7c889-7722-4ce6-8b88-9efa50fe6369
ms.openlocfilehash: bdd5c54f9174c42e17db0be7e13ea31acfea2dcf
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615726"
---
# <a name="enabling-tool-tips"></a>Habilitando dicas de ferramenta

Você pode habilitar o suporte à dica de ferramenta para os controles filho de uma janela (como os controles em uma exibição de formulário ou caixa de diálogo).

### <a name="to-enable-tool-tips-for-the-child-controls-of-a-window"></a>Para habilitar dicas de ferramenta para os controles filho de uma janela

1. Chame `EnableToolTips` a janela para a qual você deseja fornecer dicas de ferramenta.

1. Forneça uma cadeia de caracteres para cada controle em seu manipulador de [notificação TTN_NEEDTEXT](handling-ttn-needtext-notification-for-tool-tips.md) . O manipulador está no mapa de mensagens da janela que contém os controles filho (por exemplo, sua classe de exibição de formulário). Esse manipulador deve chamar uma função que identifica o controle e define **pszText** para especificar o texto usado pelo controle de dica de ferramenta.

## <a name="see-also"></a>Consulte também

[Dicas de ferramenta no Windows derivadas de CFrameWnd](tool-tips-in-windows-not-derived-from-cframewnd.md)
