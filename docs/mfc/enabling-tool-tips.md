---
title: Habilitando dicas de ferramenta | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- initializing tool tips [MFC]
- enabling tool tips [MFC]
- tool tips [MFC], initializing
- tool tips [MFC], enabling
ms.assetid: 06b7c889-7722-4ce6-8b88-9efa50fe6369
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0555af785d75c9247eb365a03a51161441a4722a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="enabling-tool-tips"></a>Habilitando dicas de ferramenta
Você pode habilitar o suporte de dica de ferramenta para os controles filho de uma janela (como os controles em uma caixa de diálogo ou o modo de exibição de formulário).  
  
### <a name="to-enable-tool-tips-for-the-child-controls-of-a-window"></a>Para ativar dicas de ferramenta para os controles filho de uma janela  
  
1.  Chamar `EnableToolTips` para a janela para o qual você deseja fornecer dicas de ferramenta.  
  
2.  Forneça uma cadeia de caracteres para cada controle no seu [notificação TTN_NEEDTEXT](../mfc/handling-ttn-needtext-notification-for-tool-tips.md) manipulador. O manipulador é no mapa de mensagem da janela que contém os controles filho (por exemplo, a classe de exibição de formulário). Esse manipulador deverá chamar uma função que identifica o controle e define **pszText** para especificar o texto usado pelo controle de dica de ferramenta.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de ferramenta no Windows não derivadas de CFrameWnd](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md)

