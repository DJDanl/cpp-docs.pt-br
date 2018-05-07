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
ms.openlocfilehash: 598583360eca2a65a5352fc9d284d8d359ac021c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="enabling-tool-tips"></a>Habilitando dicas de ferramenta
Você pode habilitar o suporte de dica de ferramenta para os controles filho de uma janela (como os controles em uma caixa de diálogo ou o modo de exibição de formulário).  
  
### <a name="to-enable-tool-tips-for-the-child-controls-of-a-window"></a>Para ativar dicas de ferramenta para os controles filho de uma janela  
  
1.  Chamar `EnableToolTips` para a janela para o qual você deseja fornecer dicas de ferramenta.  
  
2.  Forneça uma cadeia de caracteres para cada controle no seu [notificação TTN_NEEDTEXT](../mfc/handling-ttn-needtext-notification-for-tool-tips.md) manipulador. O manipulador é no mapa de mensagem da janela que contém os controles filho (por exemplo, a classe de exibição de formulário). Esse manipulador deverá chamar uma função que identifica o controle e define **pszText** para especificar o texto usado pelo controle de dica de ferramenta.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de ferramenta no Windows não derivadas de CFrameWnd](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md)

