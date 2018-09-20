---
title: Habilitando dicas de ferramenta | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- initializing tool tips [MFC]
- enabling tool tips [MFC]
- tool tips [MFC], initializing
- tool tips [MFC], enabling
ms.assetid: 06b7c889-7722-4ce6-8b88-9efa50fe6369
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 968d31b49c6d2b2fe5a5f69e04f58f17de8df5a2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46440479"
---
# <a name="enabling-tool-tips"></a>Habilitando dicas de ferramenta

Você pode habilitar o suporte à dica de ferramenta para os controles filho de uma janela (como os controles em uma caixa de diálogo ou modo de exibição de formulário).

### <a name="to-enable-tool-tips-for-the-child-controls-of-a-window"></a>Para habilitar dicas de ferramenta para os controles filho de uma janela

1. Chamar `EnableToolTips` para a janela para o qual você deseja fornecer dicas de ferramenta.

1. Forneça uma cadeia de caracteres para cada controle em seu [notificação TTN_NEEDTEXT](../mfc/handling-ttn-needtext-notification-for-tool-tips.md) manipulador. O manipulador é no mapa de mensagens da janela que contém os controles filho (por exemplo, sua classe de exibição de formulário). Esse manipulador deve chamar uma função que identifica o controle e define **pszText** para especificar o texto usado pelo controle de dica de ferramenta.

## <a name="see-also"></a>Consulte também

[Dicas de ferramenta no Windows não derivadas de CFrameWnd](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md)

