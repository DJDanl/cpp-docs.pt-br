---
title: Processando mensagens de notificação em controles de lista | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- processing notifications [MFC]
- CListCtrl class [MFC], processing notifications
ms.assetid: 1f0e296e-d2a3-48fc-ae38-51d7fb096f51
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: af648a0bf4ae78c5c5e8bcceeac12c5dbc87307a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33347670"
---
# <a name="processing-notification-messages-in-list-controls"></a>Processando mensagens de notificação em controles de lista
Como os usuários clicam cabeçalhos de coluna, arraste os ícones, editar rótulos e assim por diante, o controle de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)) envia mensagens de notificação para sua janela pai. Se você quiser fazer algo em resposta, lidar com essas mensagens. Por exemplo, quando o usuário clica em um cabeçalho de coluna, você talvez queira classificar os itens com base no conteúdo da coluna clicada, como o Microsoft Outlook.  
  
 Processo **WM_NOTIFY** mensagens do controle da lista na sua classe de exibição ou a caixa de diálogo. Use a janela de propriedades para criar um [OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify) função de manipulador com uma instrução switch com base em qual mensagem de notificação está sendo tratada.  
  
 Para obter uma lista das notificações de um controle de lista pode enviar para sua janela pai, consulte [referência de controle de exibição de lista](http://msdn.microsoft.com/library/windows/desktop/bb774737) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

