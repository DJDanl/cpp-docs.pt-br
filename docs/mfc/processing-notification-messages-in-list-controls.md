---
title: "Processando mensagens de notificação em controles de lista | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- processing notifications [MFC]
- CListCtrl class [MFC], processing notifications
ms.assetid: 1f0e296e-d2a3-48fc-ae38-51d7fb096f51
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 777cc97ca5f0cb0bf16ab051975d65138a791362
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="processing-notification-messages-in-list-controls"></a>Processando mensagens de notificação em controles de lista
Como os usuários clicam cabeçalhos de coluna, arraste os ícones, editar rótulos e assim por diante, o controle de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)) envia mensagens de notificação para sua janela pai. Se você quiser fazer algo em resposta, lidar com essas mensagens. Por exemplo, quando o usuário clica em um cabeçalho de coluna, você talvez queira classificar os itens com base no conteúdo da coluna clicada, como o Microsoft Outlook.  
  
 Processo **WM_NOTIFY** mensagens do controle da lista na sua classe de exibição ou a caixa de diálogo. Use a janela de propriedades para criar um [OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify) função de manipulador com uma instrução switch com base em qual mensagem de notificação está sendo tratada.  
  
 Para obter uma lista das notificações de um controle de lista pode enviar para sua janela pai, consulte [referência de controle de exibição de lista](http://msdn.microsoft.com/library/windows/desktop/bb774737) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

